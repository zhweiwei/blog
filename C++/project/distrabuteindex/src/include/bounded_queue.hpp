/*
 * @Author: ZWW
 * @Description: 
 * @Date: 2019-02-21 12:38:33
 */


#ifndef __BOUNDED_QUEUE__
#define __BOUNDED_QUEUE__

#include "utility.hpp"
#include "mutex.hpp"
#include "cond.hpp"

namespace Distrabute{
    template<typename T>
    class BoundedQueue:private noCoptyTemp<T>{
        public:
        BoundedQueue(int capacity);

        ~BoundedQueue();

        inline void Push(T &&);

        inline T Pop();

        inline void Clear();

        private:
        bool    clear_;//判断队列是否清除
        int     beg_;
        int     end_;
        int     capacity_;
        T       *queue_;
        Mutex   mutex_;
        Cond    empty_;
        Cond    full_;
    };

    template<typename T>
    BoundedQueue<T>::BoundedQueue(int capacity)
    :clear_(false),beg_(0),end_(0),capacity_(capacity){
        if(capacity_ <= 0)
        capacity_ = 8;

        if(capacity_ > 1024)
        capacity_ = 0124;

        queue_ = new T(capacity_);
    }

    template<typename T>
    BoundedQueue<T>::~BoundedQueue(){
        delete[] queue_;
    }

    template<typename T>
    inline void BoundedQueue<T>::Clear(){
        mutex_.Lock();
        if(clear_){
            mutex_.Unlock();
            return;
        }

        clear_ = true;
        empty_.BroadCast();
        mutex_.Unlock();
    }

    template<typename T>
    inline void BoundedQueue<T>::Push(T &&t){
        mutex_.Lock();
        while(((end_ +1)%capacity_) == beg_)
        full_.Wait(mutex_);
        queue_[end_] = t;
        if(++end_ == capacity_)
        end_ = 0;
        mutex_.Unlock();
        empty_.Signal();
    }

    template<typename T>
    inline T BoundedQueue<T>::Pop(){
        mutex_.Lock();
        while(beg_ == end_ && !clear_)
        empty_.Wait(mutex_);

        if(clear_){
            mutex_.Unlock();
            return T();
        }

        T t = std::move(queue_[beg_]);
        if(++beg_ == capacity_)
        beg_ = 0;
        mutex_.Unlock();
        full_.Signal();
        return t;
    }
}

#endif