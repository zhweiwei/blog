/*
 * @Description: 
 * @Author: ZWW
 * @Date: 2019-02-22 17:58:43
 */

#ifndef _CALLBACK_HPP_
#define _CALLBACK_HPP_

#include <functional>

namespace Distrabute
{
    class Connection;

    typedef std::function<void()> ReadCallBack;
    typedef std::function<void()> WriteCallBack;

    typedef std::function<void (Connection*)> ConnectCallBack;
} // Distrabute


#endif