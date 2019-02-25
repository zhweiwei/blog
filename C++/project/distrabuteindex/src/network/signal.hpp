/*
 * @Description: 
 * @Author: ZWW
 * @Date: 2019-02-23 10:15:06
 */


#ifndef __SIGNAL_HPP__
#define __SIGNAL_HPP_

#include <csignal>
#include <functional>
#include <unordered_map>

namespace Distrabute
{
    class Signal{
        public:
            static void Register(int sig,const std::function<void()> &handler){
                handlers_[sig] = handler;
                signal(sig,sigal_handler);
            }

            static void sigal_handler(int sig){
                handler_[sig]();
            }

        private:
        static std::unordered_map<int,std::function<void()>> handlers_;
    }
} // Distrabute


#endif