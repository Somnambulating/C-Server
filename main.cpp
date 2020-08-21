#include"threadPoll.h"
#include<string>

using namespace std;

class Task{
public:
    void process(){
        cout<<"run......"<<endl;
    }
};

int main(){
    threadPoll<Task> pool(6);
    string str;

    while(1){
        Task *it = new Task();
        pool.append(it);
        delete it;
    }

    return 0;
}
