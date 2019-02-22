/*
*
*
*/

#ifndef __COND_HPP__
#define __COND_HPP__

#include <sys/time.h>
#include <cerrno>

#include "utility.hpp"
#include "mutex.hpp"

namespace Distrabute{
    class Cond:private noCopy{
        public:
        Cond(){
            assert(!pthread_cond_init(cond_,0));
        }

        inline void Wait(Mutex &mutex){
            pthread_cond_wait(cond_,mutex.mutex_);
        }

        inline void Signal(){
            pthread_cond_signal(cond_);
        }

        inline void BroadCast(){
            pthread_cond_broadcast(cond_);
        }

        inline bool TimedWait(Mutex &mutex,int64_t millisecond){
            struct timeval tv;
            gettimeofday(&tv,0);
            timespec abstime;
            abstime.tv_sec = tv.tv_sec;
            int64_t nsec = int64_t(tv.tv_usec)*1000 + millisecond* 1000000;
            while(nsec >= 1000000000){
                ++abstime.tv_sec;
                nsec -= 1000000000;
            }

            abstime.tv_nsec = nsec;
            return pthread_cond_timedwait(cond_,mutex.mutex_,&abstime) == ETIMEDOUT;
        }

        ~Cond(){
            pthread_cond_destroy(cond_);
        }

        private:
        pthread_cond_t cond_[1];
    };
}
#endif