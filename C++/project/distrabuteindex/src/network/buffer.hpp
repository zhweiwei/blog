/*
 * @Description: 
 * @Author: ZWW
 * @Date: 2019-02-21 18:58:38
 */


#ifndef __BUFFER_HPP__
#define __BUFFER_HPP__

#include "../include/utility.hpp"

namespace Distrabute{
    class Buffer:private noCopy{
        public:
        Buffer();

        ~Buffer();

        uint32_t size() const;

        bool empty() const;

        char* data() const;

        char* end() const;

        uint32_t space() const;

        void Read(const char* data,uint32_t len);

        void Write(char *data,uint32_t len);

        void AdvanceHead(uint32_t len);

        void AdvanceTail(uint32_t len);

        void Reset();

        void Clear();

        void Adjust();

        void Unget(uint32_t len);

        private:
        char    *data_;
        uint32_t size_;
        uint32_t cap_;
        uint32_t beg_;
        uint32_t end_;
    };
}

#endif