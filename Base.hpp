#ifndef __BASE_H__
#define __BASE_H__
#include "Plc.hpp"
#include "QueueMsg.hpp"
class Base
{
    public:
        void (*callback)(const Event &event); 
        Plc& m_plc;
        Base(Plc& plc) : m_plc(plc) {};
};
#endif // __BASE_H__