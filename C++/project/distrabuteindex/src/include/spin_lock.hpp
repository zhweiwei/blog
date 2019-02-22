/*
*用设置自旋锁
*
*/

#ifndef __SPIN_LOCK_HPP__
#define __SPIN_LOCK_HPP__

#include <pthread.h>
#include <cassert>

#include "utility.hpp"

namespace Distrabute{
    class SpinLock:private noCopy{
        public:
        SpinLock(){
            assert(!pthread_spin_init(lock_,0));
        }

        inline void Lock(){
            pthread_spin_lock(lock_);
        }

        inline bool TryLock(){
        return !pthread_spin_trylock(lock_);
        }

        inline void Unlock(){
            pthread_spin_unlock(lock_);
        }

        ~SpinLock(){
            assert(!pthread_spin_destroy(lock_));
        }

        private:
        pthread_spinlock_t lock_[1];
    };
}

#endif