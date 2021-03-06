/*
 * @Description: 
 * @Author: ZWW
 * @Date: 2019-02-21 21:10:14
 */

#ifndef __TIME_HPP__
#define __TIME_HPP__

#include <sys/time.h>
#include <inttypes.h>

namespace Distrabute
{
    class Time{
        public:
        static int64_t NowMicro(){
            struct timeval tv;
            gettimeofday(&tv,0);
            return (int64_t(tv.tv_sec) * 1000000 + tv.tv_usec);
        }
 
         static int64_t Now(){
            return NowMicro()/1000;
#endif