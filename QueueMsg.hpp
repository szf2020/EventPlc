#ifndef __QUEUEMSG_H__
#define __QUEUEMSG_H__
#include "Base.hpp"
#include "Event.hpp"

class Base;
struct QueueMsg
{
    Event event;
    Base* object;
};
#endif // __QUEUEMSG_H__