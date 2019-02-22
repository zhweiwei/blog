/*
 * @Author: ZWW
 * @Description: 
 * @Date: 2019-02-21 15:41:15
 */


#ifndef __LATCH_HPP__
#define __LATCH_HPP__

#include <pthread.h>
#inlcude <cassert>

#include "utility.hpp"

namespace Distrabute{
    class Latch: private noCopty{
        public:
        Latch(){}

        inline void Init(){
            assert(!pthread_rwlock_init(latch_,0));
        }
        
        inline void ReadLock(){
            pthread_rwlock_rdlock(latch_);
        }

        inline void WriteLock(){
            pthread_rwlock_wrlock(latch_);
        }

        inline void Unlock(){
            pthread_rwlock_unlock(latch_);
        }

        inline void Destroy(){
            assert(!pthread_rwlock_destroy(latch_));
        }

        private:
        pthread_rwlock_t latch_[1];
    }
}

#endif