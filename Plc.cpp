#include "Plc.hpp"
#include "Pin.hpp"
#include "esp_attr.h"
#include "QueueMsg.hpp"
#include "Event.hpp"

    void gpio_isr_handler(Pin* pin)
    {
        static bool preclev[32];
        bool l=gpio_get_level(pin->m_pin);
        esp_rom_printf("p %d l %d pr %d\n",pin->m_pin,l,preclev[pin->m_pin]);
        if(preclev[pin->m_pin]!=l)
        {
            QueueMsg msg;
            msg.event.ev=state_change;
            msg.object=pin;
            msg.event.state=l;
            xQueueSendFromISR(pin->m_plc.gpio_evt_queue,&msg,NULL);
        }
        preclev[pin->m_pin]=l;
    }

//namespace plc
//{
    void Plc::start()
    {
        gpio_install_isr_service(0);
    }
    
    Plc::Plc()
    {
        gpio_evt_queue = xQueueCreate(10, sizeof(QueueMsg));
    }
//}