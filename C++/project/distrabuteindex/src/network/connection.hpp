/*
 * @Description: 
 * @Author: ZWW
 * @Date: 2019-02-26 09:16:39
 */

#ifndef _CONNECTION_HPP_
#define _CONNECTION_HPP_

#include "../include/utility.hpp"
#include "callback.hpp"
#include "socket.hpp"
#include "endpoint.hpp"
#include "buffer.hpp"


namespace Distrabute
{
    class Connection : private NoCopy
{
	public:
		Connection(const Socket &socket, Poller *poller);

		Connection(const EndPoint &server, Poller *poller);

		virtual ~Connection();

		bool Success() const;

		Buffer& GetInput();

		Buffer& GetOutput();

		void HandleRead();

		void HandleWrite();

		void OnRead(const ReadCallBack &readcb);

		void OnWrite(const WriteCallBack &writecb);

		bool Close();

		void Send(const char *str);

		void Send(Buffer &buffer);

		void Send(const char *str, uint32_t len);

		void SendOutput();

	protected:
		Socket   socket_;
		bool     connected_;
		Channel *channel_;
		Buffer   input_;
		Buffer   output_;

		ReadCallBack  readcb_;
		WriteCallBack writecb_;
};

} // Distrabute



#endif