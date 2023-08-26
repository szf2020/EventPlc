#ifndef __PIN_H__
#define __PIN_H__


// https://github.com/cpp-best-practices/cppbestpractices/tree/master

#include "driver/gpio.h"
#include "Base.hpp"
#include "Plc.hpp"
//namespace plc
//{
    class Pin : public Base
    {
    private:
    public:
        gpio_num_t m_pin;
        Pin(gpio_num_t gpio_num, Plc& plc);
        //~Pin();
        void start();
        void setDirection(gpio_mode_t mode);
        void setPullUpMode(gpio_pull_mode_t pull);
        void setInterruptType(gpio_int_type_t intr_type);
        void setLevel(bool level);
        bool getLevel();
    };
    

//}
#endif // __PIN_H__