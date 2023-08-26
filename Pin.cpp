#include "Pin.hpp"
#include "Plc.hpp"
#include "driver/gpio.h"
extern void gpio_isr_handler(Pin*);
//namespace plc
//{
    Pin::Pin(gpio_num_t gpio_num, Plc& plc) : Base(plc) 
    {
        m_pin=gpio_num;
        gpio_reset_pin(m_pin);      
    }
    
    void Pin::start()
    {
        setInterruptType(GPIO_INTR_ANYEDGE);
        gpio_intr_enable(m_pin);
        gpio_isr_handler_add(m_pin,(gpio_isr_t)gpio_isr_handler,(void*)this);
    }
    
    void Pin::setDirection(gpio_mode_t mode)
    {
        gpio_set_direction(m_pin,mode);
    }
    
    void Pin::setPullUpMode(gpio_pull_mode_t pull)
    {
        gpio_set_pull_mode(m_pin,pull);
    }
    
    void Pin::setInterruptType(gpio_int_type_t intr_type)
    {
        gpio_set_intr_type(m_pin,intr_type);
    }
    void Pin::setLevel(bool level)
    {
        gpio_set_level(m_pin,level);
    }
    bool Pin::getLevel()
    {
        return gpio_get_level(m_pin);
    }
//}