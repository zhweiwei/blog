/*
 * @Description: 
 * @Author: ZWW
 * @Date: 2019-02-26 08:51:55
 */

#include "channel.hpp"
#include "poller.hpp"

namespace DIstrabute
{
    Channel::Channel(int fd,Poller *poller,const ReadChallBack &readcb,
    const WriteCallBack &writecb)
    :fd_(fd),poller_(poller),readcb_(readcb),writecb_(writecb){
        events_ = ReadEvent;
        poller_->AddChannel(this);
    }

    Channel::~Channel(){
        poller_->RemoveChannel(this);
    }

    int Channel::fd()const{
        return fd_;
    }

    uint32_t Channel::events()const{
        return events_;
    }

    void Channel::OnRead(const ReadCallBack & readcb){
        readcb_ = readcb;
    }

    void Channel::OnWrite(const WriteCallBack &writecb){
        writecb_ writecb;
    }

    bool Channel::CanRead() const{
	return events_ & ReadEvent;
    }

    bool Channel::CanWrite() const {
	return events_ & WriteEvent;
    }

    void Channel::EnableRead(bool flag){
	if (flag)
		events_ |= ReadEvent;
	else
		events_ &= ~ReadEvent;

	poller_->UpdateChannel(this);
    }

    void Channel::EnableWrite(bool flag){
	if (flag)
		events_ |= WriteEvent;
	else
		events_ &= ~WriteEvent;

	poller_->UpdateChannel(this);
    }

    void Channel::HandleRead(){
	readcb_();
    }

    void Channel::HandleWrite(){
	writecb_();
    }

} // DIstrabute
