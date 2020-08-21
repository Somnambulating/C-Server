#ifndef _THREADPOLL_H_
#define _THREADPOLL_H_
#include<vector>
#include<queue>
#include<thread>
#include<iostream>
#include<stdexcept>
#include<condition_variable>
#include<memory>

const int MAX_THREADS = 1000;

template <typename T>
class threadPoll{
public:
    threadPoll(int number = 1);
    ~threadPoll();
    bool append(T *request);

private:
    static void *worker(void *arg);
    void run();

private:
    std::vector<std::thread> work_threads;
    std::queue<T *> tasks_queue;
    std::mutex queue_mutex;
    std::condition_variable condition;
    bool stop;
};

template<typename T>
threadPoll<T>::threadPoll(int number):stop(false){
    if(number <= 0 || number > MAX_THREADS){
        throw std::exception();
    }

    for(int i = 0; i < number; i++){
        std::cout<<"Create the"<<i<<"th thread"<<std::endl;
        work_threads.emplace_back(worker, this);
    }
}

template<typename T>
inline threadPoll<T>::~threadPoll(){
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        stop = true;
    }

    condition.notify_all();
    for(auto &ww: work_threads){
        ww.join();
    }
}

template<typename T>
bool threadPoll<T>::append(T *request){
    queue_mutex.lock();
    tasks_queue.push(request);
    queue_mutex.unlock();
    condition.notify_one();
    return true;
}

template<typename T>
void *threadPoll<T>::worker(void *arg){
    threadPoll *pool = (threadPoll*)arg;
    pool->run();
    return pool;
}

template<typename T>
void threadPoll<T>::run(){
    while(!stop){
        std::unique_lock<std::mutex> lk(this->queue_mutex);
        this->condition.wait(lk, [this]{return !this->tasks_queue.empty();});

        if(this->tasks_queue.empty()){
            continue;
        }
        else{
            T *request = tasks_queue.front();
            tasks_queue.pop();
            if(request){
                request->process();
            }
        }
    }
}

#endif
