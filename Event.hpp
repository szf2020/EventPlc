#ifndef __EVENT_H__
#define __EVENT_H__

enum event_type {
    state_change
};

struct Event
{
    event_type ev;
    bool state;
};
#endif // __EVENT_H__