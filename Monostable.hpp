#ifndef __MONOSTABLE_H__
#define __MONOSTABLE_H__

#include "Plc.hpp"
class Monostable 
{
    public:
        Monostable(Plc& plc) : m_plc(plc) {};
        void start();
        bool retriggerable;
        uint32_t period;
        Plc& m_plc;
};
#endif // __MONOSTABLE_H__