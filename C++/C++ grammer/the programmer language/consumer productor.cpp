#include <mutex>
#include <chrono>
#include <queue>
#include <condition_variable>

using namespace std;


class message{

}

queue<message> mqueue;
condition_variable mcond;
mutex mmutex;

void consumer(){
    while(true){
        unique_lock<mutex>  lck{mmutex};

        while(mcond.wait(lck)) ;

        auto m = mqueue.front();
        mqueue.pop();
        lck.unlock();
    }
}


void productor(){
    while(true){
        message m;

        unique_lock<mutex> lck(mmutex);
        mqueue.push(m);
        mcond.notify_one();
    }
}