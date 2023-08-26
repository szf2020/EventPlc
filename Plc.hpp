#ifndef __PLC_H__
#define __PLC_H__

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"
#include "esp_attr.h"

//namespace plc
//{


/*     struct IsrMsg
    {
        Plc& plc;
        uint8_t object_id;
        void *state;
    }; */



    class Plc
    {
        public:
        void start();
        static int i;
        Plc();
        //void (*cb)(uint8_t object_id,event_type ev, void* value);
        QueueHandle_t gpio_evt_queue;
    };
//}
#endif // __PLC_H__