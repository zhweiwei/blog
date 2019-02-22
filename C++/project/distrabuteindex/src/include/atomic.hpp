/*
 * @Author: ZWW
 * @Description: 
 * @Date: 2019-02-21 14:08:38
 */

#ifndef __ATOMIC_HPP__
#define __ATOMIC_HPP__

#include <cstdint>

namespace Distrabute{
    template<typename T>
    class Atomic
{
	public:
		Atomic() { }

		Atomic(T val):val_(val) { }

		inline T get() {
			return __sync_val_compare_and_swap(&val_, 0, 0);
		}

		inline T operator++() {
			return __sync_add_and_fetch(&val_, 1);
		}

		inline T operator--() {
			return __sync_sub_and_fetch(&val_, 1);
		}

		inline T operator++(int) {
			return __sync_fetch_and_add(&val_, 1);
		}

		inline T operator--(int) {
			return __sync_fetch_and_sub(&val_, 1);
		}

		inline Atomic& operator=(T new_val) {
			__sync_val_compare_and_swap(&val_, val_, new_val);
			return *this;
		}

	private:
		volatile T val_;
};

typedef Atomic<uint8_t>  atomic_8_t;
typedef Atomic<uint16_t> atomic_16_t;
typedef Atomic<uint32_t> atomic_32_t;

}

#endif