/*
 * @Description: 
 * @Author: ZWW
 * @Date: 2019-02-26 08:41:02
 */

#include "../include/utility.hpp"
#include "callback.hpp"

namespace Distrabute
{
    class Poller;

class Channel : private NoCopy
{
	public:
		friend class Connection;

		Channel(int fd, Poller *poller, const ReadCallBack &readcb, const WriteCallBack &writecb);

		~Channel();

		int fd() const;

		uint32_t events() const;

		bool CanRead() const;

		bool CanWrite() const;

		void OnRead(const ReadCallBack &readcb);

		void OnWrite(const WriteCallBack &writecb);

		void EnableRead(bool flag);

		void EnableWrite(bool flag);

		void HandleRead();

		void HandleWrite();

	private:
		int      fd_;
		uint32_t events_;
		Poller  *poller_;

		ReadCallBack  readcb_;
		WriteCallBack writecb_;
};
    
} // Distrabute
