/*
*用于线程互斥
*
*/

#ifndef __MUTEX_HPP__
#define __MUTEX_HPP__

#include <pthread.h>
#include <cassert>

#include "utility.hpp"

namespace Distrabute{
    class Cond;

    class Mutex:private noCopy{
        friend class Cond;

        public:
        Mutex(){
            assert(!pthread_mutex_init(mutex_,0));
        }

        inline void Lock(){
            pthread_mutex_lock(mutex_);
        }

        inline void Unlock(){
            pthread_mutex_unlock(mutex_);
        }

        ~Mutex(){
            assert(!pthread_mutex_destroy(mutex_));
        }

        private:
        pthread_mutex_t mutex_[1];
    };
}

#endif