/*
 * @Description: 
 * @Author: ZWW
 * @Date: 2019-02-22 16:36:49
 */

#include <arpa/inet.h>
#include <cassert>

#include "endpoint.hpp"

namespace Distrabute
{
    EndPoint::EndPoint(uint16_t port,uint32_t address):port_(port),address_(address){}

    EndPoint::EndPoint(uint16_t port,const char* str):port_(port){
        assert(inet_pton(AF_INET,str,&address_) == 1)
    }

    EndPoint::~EndPoint(){}

    uint16_t EndPoint::Port()const{
        return port_;
    }

    uint32_t EndPoint::Address()const{
        return address_;
    }

    std::string EndPoint::ToString()const{
        char buf[MaxLen];
        assert(inet_ntop(AF_INET,&address_,buf,MaxLen));
        return std::string(buf)+" port "+std::to_string(port);
    }
} // Distrabute
