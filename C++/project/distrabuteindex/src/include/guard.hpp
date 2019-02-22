/*
*
*用于管理mutex
*/

#ifndef __GUARD_HPP__
#define __GUARD_HPP__

#include "utility.hpp"
#include "mutex.hpp"

namespace Distrabute{
    class Guard:private noCopy{
        public:
            Guard(Mutex &mutex):mutex_(mutex){
                mutex_.Lock();
            }

            ~Guard(){
                mutex_.Unlock();
            }

        private:
        Mutex &mutex_;
    };
}


#endif