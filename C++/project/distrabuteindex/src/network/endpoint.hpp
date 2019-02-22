/*
 * @Description: 
 * @Author: ZWW
 * @Date: 2019-02-22 16:23:29
 */


#ifndef _ENDPOINT_HPP_
#define _ENDPOINT_HPP_

#include <string>
namespace Distrabute
{
 class EndPoint
{
	public:
		static const uint32_t MaxLen = 16;

		EndPoint(uint16_t port, uint32_t address);

		EndPoint(uint16_t port, const char *str);

		~EndPoint();

		uint16_t Port() const;

		uint32_t Address() const;

		std::string ToString() const;

	private:
		uint16_t port_;
		uint32_t address_;
};   
} // Distrabute

#endif
