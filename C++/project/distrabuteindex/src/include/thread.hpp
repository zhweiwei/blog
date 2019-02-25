/*
* 线程控制
*
*/


#ifndef  __THREAD_HPP__
#define  __THREAD_HPP__

#include <thread>
#include "utility.hpp"

namespace Distrabute{
    class Thread:private noCopy{
        public:
        Thread(const Func &func):func_(func){}

        inline void Start(){
            std::thread tmp(func_);
            thread_.swap(tmp);
        }

        inline void Stop(){
            thread_.join();
        }
        
        private:
        Func func_;
        std::thread thread_;
    };
}

#endif