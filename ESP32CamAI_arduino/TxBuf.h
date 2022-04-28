#ifndef _TXBUF_H_
#define _TXBUF_H_

#include<Arduino.h>
#include "driver/uart.h"
#define BUF_SIZE (1024)
#define UART_MAX_NUM_RX_BYTES (1024)
static QueueHandle_t s_uart0Queue;
//申请5字节内存

class TXBUF{
  public:
      uint8_t UART_Init();
      void forward(int mode); 
      void backward(int mode);
      void left(int mode);
      void right(int mode);
      void reset(int mode);
  private:
        ;
};
#endif
