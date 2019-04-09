/*
 * @Description: 
 * @Author: ZWW
 * @Date: 2019-03-01 11:12:17
 */


#include <unistd.h>
#include <vector>

#include "../include/bounded_queue.hpp"
#include "../include/thread_pool.hpp"
#include "time.hpp"
#include "eventbase.hpp"
#include "poller.hpp"
#include "channel.hpp"
#include "socket.hpp"

namespace Distrabute{
    static const int MaxTimeout = 0x7FFFFFFF;

    EventBase::EventBase(int thread_num, int queue_size)
    :running_(true), poller_(new Poller()), next_time_out_(MaxTimeout), seq_(0),
    queue_(new BoundedQueue<Task>(queue_size)), pool_(new ThreadPool<Task>(queue_, thread_num))
    {
        char buf;
        ssize_t r = read(channel_->fd,&buf,sizeof(buf));
        
    }
}