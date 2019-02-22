/*
*   该类用于禁止copy
*
*/

#ifndef __UTILITY_HPP__
#define __UTILITY_HPP__

#include <functional>

namespace Distrabute{
    class noCopy{
        public:
        noCopy() = default;

        private:
        noCopy(const noCopy&) = delete;

        noCopy& operator=(const noCopy&) = delete;
    };


template<typename T>
class noCoptyTemp{
    public:
    noCoptyTemp() = default;

    private:
    noCoptyTemp(const noCoptyTemp&) = delete;
    noCoptyTemp& operator=(const noCoptyTemp&) = delete;
};

typedef std::function<void()> Task;
typedef std::function<void()> Func;
}
#endif