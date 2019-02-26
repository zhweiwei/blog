/*
 * @Description: 
 * @Author: ZWW
 * @Date: 2019-02-22 18:28:23
 */

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <cstring>
#include <cassert>
#include <cerrno>

#include "socket.hpp"

namespace Distrabute
{
    Socket::Socket():fd_(-1){}

    Socket::Socket(int fd):fd_(fd){}

    Socket::~Socket(){}

    int Socket::fd()const{
        return fd_;
    }

    bool Socket::Create()
{
	fd_ = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	return fd_ != -1;
}

    bool Socket::Valid()const{
        return fd_ != -1;
    }

    bool Socket::Connect(const EndPoint &end_point)
{
	struct sockaddr_in server;
	memset(&server, 0, sizeof(server));
	server.sin_family      = AF_INET;
	server.sin_port        = htons(end_point.Port());
	server.sin_addr.s_addr = end_point.Address();
	return !connect(fd_, (const struct sockaddr *)&server, sizeof(server));
}

bool Socket::Close()
{
	bool flag = true;
	if (fd_ != -1) {
		flag = !close(fd_);
		fd_ = -1;
	}
	return flag;
}

int Socket::Accept()
{
	struct sockaddr_in client;
	memset(&client, 0, sizeof(client));
	socklen_t len = sizeof(client);
	int fd = accept(fd_, (struct sockaddr *)&client, &len);
	return fd;
}

bool Socket::Bind(uint16_t port)
{
	struct sockaddr_in server;
	memset(&server, 0, sizeof(server));
	server.sin_family      = AF_INET;
	server.sin_port        = htons(port);
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	return !bind(fd_, (const struct sockaddr *)&server, sizeof(server));
}

bool Socket::Listen()
{
	return !listen(fd_, 32);
}

bool Socket::SetOption(int value, bool flag)
{
	return !setsockopt(fd_, SOL_SOCKET, value, &flag, sizeof(flag));
}

bool Socket::GetOption(int value, int *ret)
{
	socklen_t len = sizeof(*ret);
	return !getsockopt(fd_, SOL_SOCKET, value, ret, &len);
}

bool Socket::SetResuseAddress()
{
	int flag = 1;
	return !setsockopt(fd_, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(flag));
}

int Socket::Accept()
{
	struct sockaddr_in client;
	memset(&client, 0, sizeof(client));
	socklen_t len = sizeof(client);
	int fd = accept(fd_, (struct sockaddr *)&client, &len);
	return fd;
}

bool Socket::GetPeerName(EndPoint *endpoint)
{
	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	socklen_t len = sizeof(addr);
	if (!getsockname(fd_, (struct sockaddr *)&addr, &len)) {
		*endpoint = EndPoint(ntohs(addr.sin_port), addr.sin_addr.s_addr);
		return true;
	}
	return false;
}

bool Socket::GetSockName(EndPoint *endpoint)
{
	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	socklen_t len = sizeof(addr);
	if (!getpeername(fd_, (struct sockaddr *)&addr, &len)) {
		*endpoint = EndPoint(ntohs(addr.sin_port), addr.sin_addr.s_addr);
		return true;
	}
	return false;
}

bool Socket::AddFlag(int flag)
{
	int value = fcntl(fd_, F_GETFL, 0);
	assert(value != -1);
	return !fcntl(fd_, F_SETFL, value | flag);
}

bool Socket::SetNonBlock()
{
	int value = fcntl(fd_, F_GETFL, 0);
	assert(value != -1);
	return !fcntl(fd_, F_SETFL, value | O_NONBLOCK);
}

uint32_t Socket::Write(const char *data, uint32_t len, bool *blocked)
{
	uint32_t written = 0;
	for (; written < len;) {
		ssize_t r = write(fd_, data + written, len - written);
		if (r > 0) {
			written += r;
			continue;
		} else if (r == -1) {
			if (errno == EINTR)
				continue;
			if (errno == EAGAIN || errno == EWOULDBLOCK) {
				*blocked = true;
				break;
			}
		}
		printf("write error, %s :(\n", strerror(errno));
		break;
	}
	return written;
}

uint32_t Socket::Read(char *data, uint32_t len, bool *blocked)
{
	uint32_t has_read = 0;
	ssize_t r;
	for (; has_read < len && (r = read(fd_, data + has_read, len - has_read));) {
		if (r == -1) {
			if (errno == EINTR)
				continue;
			if (errno == EAGAIN || errno == EWOULDBLOCK)
				*blocked = true;
			else
				printf("read error, %s :(\n", strerror(errno));
			break;
		}
		has_read += r;
	}
	return has_read;
}

} // Distrabute
