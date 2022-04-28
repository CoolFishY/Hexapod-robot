#include"TxBuf.h"

void TXBUF::reset(int mode){
  char *re_buf = ( char *)malloc(60);
  switch(mode){
    case 0:
        *re_buf=0xff;*(re_buf+1)=0x02;*(re_buf+2)=0x00;*(re_buf+3)=0xdc;*(re_buf+4)=0x05;                 //左脚上下复位
        *(re_buf+5)=0xff;*(re_buf+6)=0x02;*(re_buf+7)=0x01;*(re_buf+8)=0xdc;*(re_buf+9)=0x05;
        *(re_buf+10)=0xff;*(re_buf+11)=0x02;*(re_buf+12)=0x02;*(re_buf+13)=0xdc;*(re_buf+14)=0x05;

        *(re_buf+15)=0xff;*(re_buf+16)=0x02;*(re_buf+17)=0x04;*(re_buf+18)=0xdc;*(re_buf+19)=0x05;        //右脚上下复位
        *(re_buf+20)=0xff;*(re_buf+21)=0x02;*(re_buf+22)=0x05;*(re_buf+23)=0xdc;*(re_buf+24)=0x05;
        *(re_buf+25)=0xff;*(re_buf+26)=0x02;*(re_buf+27)=0x06;*(re_buf+28)=0xdc;*(re_buf+29)=0x05;

        *(re_buf+30)=0xff;*(re_buf+31)=0x02;*(re_buf+32)=0x0e;*(re_buf+33)=0xdc;*(re_buf+34)=0x05;        //左脚前后复位
        *(re_buf+35)=0xff;*(re_buf+36)=0x02;*(re_buf+37)=0x0d;*(re_buf+38)=0xdc;*(re_buf+39)=0x05;
        *(re_buf+40)=0xff;*(re_buf+41)=0x02;*(re_buf+42)=0x0c;*(re_buf+43)=0xdc;*(re_buf+44)=0x05;

        *(re_buf+45)=0xff;*(re_buf+46)=0x02;*(re_buf+47)=0x0a;*(re_buf+48)=0xdc;*(re_buf+49)=0x05;        //右脚前后复位
        *(re_buf+50)=0xff;*(re_buf+51)=0x02;*(re_buf+52)=0x09;*(re_buf+53)=0xdc;*(re_buf+54)=0x05;
        *(re_buf+55)=0xff;*(re_buf+56)=0x02;*(re_buf+57)=0x08;*(re_buf+58)=0xdc;*(re_buf+59)=0x05;
        break;
    default:break;
  }
  uart_write_bytes(UART_NUM_0,(char*)re_buf , 60);
}

void TXBUF::forward(int mode){
  char *fw_buf = ( char *)malloc(15);
  switch(mode){
    case 0:
      *fw_buf=0xff;*(fw_buf+1)=0x02;*(fw_buf+2)=0x00;*(fw_buf+3)=0xc4;*(fw_buf+4)=0x09;                   //左三角抬起
      *(fw_buf+5)=0xff;*(fw_buf+6)=0x02;*(fw_buf+7)=0x05;*(fw_buf+8)=0xf4;*(fw_buf+9)=0x01;
      *(fw_buf+10)=0xff;*(fw_buf+11)=0x02;*(fw_buf+12)=0x02;*(fw_buf+13)=0xc4;*(fw_buf+14)=0x09;break;
      break;
    case 1:
      *fw_buf=0xff;*(fw_buf+1)=0x02;*(fw_buf+2)=0x0e;*(fw_buf+3)=0x29;*(fw_buf+4)=0x07;                   //左三角前进
      *(fw_buf+5)=0xff;*(fw_buf+6)=0x02;*(fw_buf+7)=0x09;*(fw_buf+8)=0x8e;*(fw_buf+9)=0x04;
      *(fw_buf+10)=0xff;*(fw_buf+11)=0x02;*(fw_buf+12)=0x0c;*(fw_buf+13)=0x29;*(fw_buf+14)=0x07;break;
      break;
    case 2:
      *fw_buf=0xff;*(fw_buf+1)=0x02;*(fw_buf+2)=0x00;*(fw_buf+3)=0xdc;*(fw_buf+4)=0x05;                   //左三角上下复位
      *(fw_buf+5)=0xff;*(fw_buf+6)=0x02;*(fw_buf+7)=0x05;*(fw_buf+8)=0xdc;*(fw_buf+9)=0x05;
      *(fw_buf+10)=0xff;*(fw_buf+11)=0x02;*(fw_buf+12)=0x02;*(fw_buf+13)=0xdc;*(fw_buf+14)=0x05;
      break;
    case 3:
      *fw_buf=0xff;*(fw_buf+1)=0x02;*(fw_buf+2)=0x04;*(fw_buf+3)=0xf4;*(fw_buf+4)=0x01;                   //右三角抬起
      *(fw_buf+5)=0xff;*(fw_buf+6)=0x02;*(fw_buf+7)=0x01;*(fw_buf+8)=0xc4;*(fw_buf+9)=0x09;
      *(fw_buf+10)=0xff;*(fw_buf+11)=0x02;*(fw_buf+12)=0x06;*(fw_buf+13)=0xf4;*(fw_buf+14)=0x01;
      break;
    case 4:
      *fw_buf=0xff;*(fw_buf+1)=0x02;*(fw_buf+2)=0x0e;*(fw_buf+3)=0xdc;*(fw_buf+4)=0x05;                   //左三角前后复位
      *(fw_buf+5)=0xff;*(fw_buf+6)=0x02;*(fw_buf+7)=0x09;*(fw_buf+8)=0xdc;*(fw_buf+9)=0x05;
      *(fw_buf+10)=0xff;*(fw_buf+11)=0x02;*(fw_buf+12)=0x0c;*(fw_buf+13)=0xdc;*(fw_buf+14)=0x05;
      break;
    case 5:
      *fw_buf=0xff;*(fw_buf+1)=0x02;*(fw_buf+2)=0x0a;*(fw_buf+3)=0x8e;*(fw_buf+4)=0x04;                   //右三角前进
      *(fw_buf+5)=0xff;*(fw_buf+6)=0x02;*(fw_buf+7)=0x0d;*(fw_buf+8)=0x29;*(fw_buf+9)=0x07;
      *(fw_buf+10)=0xff;*(fw_buf+11)=0x02;*(fw_buf+12)=0x08;*(fw_buf+13)=0x8e;*(fw_buf+14)=0x04;
      break;
    case 6:
      *fw_buf=0xff;*(fw_buf+1)=0x02;*(fw_buf+2)=0x04;*(fw_buf+3)=0xdc;*(fw_buf+4)=0x05;                   //右三角上下复位
      *(fw_buf+5)=0xff;*(fw_buf+6)=0x02;*(fw_buf+7)=0x01;*(fw_buf+8)=0xdc;*(fw_buf+9)=0x05;
      *(fw_buf+10)=0xff;*(fw_buf+11)=0x02;*(fw_buf+12)=0x06;*(fw_buf+13)=0xdc;*(fw_buf+14)=0x05;
      break;
    case 7:
      *fw_buf=0xff;*(fw_buf+1)=0x02;*(fw_buf+2)=0x00;*(fw_buf+3)=0xc4;*(fw_buf+4)=0x09;                   //左三角抬起
      *(fw_buf+5)=0xff;*(fw_buf+6)=0x02;*(fw_buf+7)=0x05;*(fw_buf+8)=0xf4;*(fw_buf+9)=0x01;
      *(fw_buf+10)=0xff;*(fw_buf+11)=0x02;*(fw_buf+12)=0x02;*(fw_buf+13)=0xc4;*(fw_buf+14)=0x09;
      break;
    case 8:
      *fw_buf=0xff;*(fw_buf+1)=0x02;*(fw_buf+2)=0x0a;*(fw_buf+3)=0xdc;*(fw_buf+4)=0x05;                   //右三角前后复位
      *(fw_buf+5)=0xff;*(fw_buf+6)=0x02;*(fw_buf+7)=0x0d;*(fw_buf+8)=0xdc;*(fw_buf+9)=0x05;
      *(fw_buf+10)=0xff;*(fw_buf+11)=0x02;*(fw_buf+12)=0x08;*(fw_buf+13)=0xdc;*(fw_buf+14)=0x05;
      break;
    case 9:
      *fw_buf=0xff;*(fw_buf+1)=0x02;*(fw_buf+2)=0x00;*(fw_buf+3)=0xdc;*(fw_buf+4)=0x05;                   //左三角上下复位
      *(fw_buf+5)=0xff;*(fw_buf+6)=0x02;*(fw_buf+7)=0x05;*(fw_buf+8)=0xdc;*(fw_buf+9)=0x05;
      *(fw_buf+10)=0xff;*(fw_buf+11)=0x02;*(fw_buf+12)=0x02;*(fw_buf+13)=0xdc;*(fw_buf+14)=0x05;
      break;
    default:break;
  }
   uart_write_bytes(UART_NUM_0,(char*)fw_buf , 15);
}

void TXBUF::backward(int mode){
  char *bw_buf = ( char *)malloc(15);
  switch(mode){
    case 0:
      *bw_buf=0xff;*(bw_buf+1)=0x02;*(bw_buf+2)=0x00;*(bw_buf+3)=0xc4;*(bw_buf+4)=0x09;                   //左三角抬起
      *(bw_buf+5)=0xff;*(bw_buf+6)=0x02;*(bw_buf+7)=0x05;*(bw_buf+8)=0xf4;*(bw_buf+9)=0x01;
      *(bw_buf+10)=0xff;*(bw_buf+11)=0x02;*(bw_buf+12)=0x02;*(bw_buf+13)=0xc4;*(bw_buf+14)=0x09;
      break;
    case 1:
      *bw_buf=0xff;*(bw_buf+1)=0x02;*(bw_buf+2)=0x0e;*(bw_buf+3)=0x8e;*(bw_buf+4)=0x04;                   //左三角后退
      *(bw_buf+5)=0xff;*(bw_buf+6)=0x02;*(bw_buf+7)=0x09;*(bw_buf+8)=0x29;*(bw_buf+9)=0x07;
      *(bw_buf+10)=0xff;*(bw_buf+11)=0x02;*(bw_buf+12)=0x0c;*(bw_buf+13)=0x8e;*(bw_buf+14)=0x04;
      break;
    case 2:
      *bw_buf=0xff;*(bw_buf+1)=0x02;*(bw_buf+2)=0x00;*(bw_buf+3)=0xdc;*(bw_buf+4)=0x05;                   //左三角上下复位
      *(bw_buf+5)=0xff;*(bw_buf+6)=0x02;*(bw_buf+7)=0x05;*(bw_buf+8)=0xdc;*(bw_buf+9)=0x05;
      *(bw_buf+10)=0xff;*(bw_buf+11)=0x02;*(bw_buf+12)=0x02;*(bw_buf+13)=0xdc;*(bw_buf+14)=0x05;
      break;
    case 3:
      *bw_buf=0xff;*(bw_buf+1)=0x02;*(bw_buf+2)=0x04;*(bw_buf+3)=0xf4;*(bw_buf+4)=0x01;                   //右三角抬起
      *(bw_buf+5)=0xff;*(bw_buf+6)=0x02;*(bw_buf+7)=0x01;*(bw_buf+8)=0xc4;*(bw_buf+9)=0x09;
      *(bw_buf+10)=0xff;*(bw_buf+11)=0x02;*(bw_buf+12)=0x06;*(bw_buf+13)=0xf4;*(bw_buf+14)=0x01;
      break;
    case 4:
      *bw_buf=0xff;*(bw_buf+1)=0x02;*(bw_buf+2)=0x0e;*(bw_buf+3)=0xdc;*(bw_buf+4)=0x05;                   //左三角前后复位
      *(bw_buf+5)=0xff;*(bw_buf+6)=0x02;*(bw_buf+7)=0x09;*(bw_buf+8)=0xdc;*(bw_buf+9)=0x05;
      *(bw_buf+10)=0xff;*(bw_buf+11)=0x02;*(bw_buf+12)=0x0c;*(bw_buf+13)=0xdc;*(bw_buf+14)=0x05;
      break;
    case 5:
      *bw_buf=0xff;*(bw_buf+1)=0x02;*(bw_buf+2)=0x0a;*(bw_buf+3)=0x29;*(bw_buf+4)=0x07;                   //右三角后退
      *(bw_buf+5)=0xff;*(bw_buf+6)=0x02;*(bw_buf+7)=0x0d;*(bw_buf+8)=0x8e;*(bw_buf+9)=0x04;
      *(bw_buf+10)=0xff;*(bw_buf+11)=0x02;*(bw_buf+12)=0x08;*(bw_buf+13)=0x29;*(bw_buf+14)=0x07;
      break;
    case 6:
      *bw_buf=0xff;*(bw_buf+1)=0x02;*(bw_buf+2)=0x04;*(bw_buf+3)=0xdc;*(bw_buf+4)=0x05;                   //右三角上下复位
      *(bw_buf+5)=0xff;*(bw_buf+6)=0x02;*(bw_buf+7)=0x01;*(bw_buf+8)=0xdc;*(bw_buf+9)=0x05;
      *(bw_buf+10)=0xff;*(bw_buf+11)=0x02;*(bw_buf+12)=0x06;*(bw_buf+13)=0xdc;*(bw_buf+14)=0x05;
      break;
    case 7:
      *bw_buf=0xff;*(bw_buf+1)=0x02;*(bw_buf+2)=0x00;*(bw_buf+3)=0xc4;*(bw_buf+4)=0x09;                   //左三角抬起
      *(bw_buf+5)=0xff;*(bw_buf+6)=0x02;*(bw_buf+7)=0x05;*(bw_buf+8)=0xf4;*(bw_buf+9)=0x01;
      *(bw_buf+10)=0xff;*(bw_buf+11)=0x02;*(bw_buf+12)=0x02;*(bw_buf+13)=0xc4;*(bw_buf+14)=0x09;
      break;
    case 8:
      *bw_buf=0xff;*(bw_buf+1)=0x02;*(bw_buf+2)=0x0a;*(bw_buf+3)=0xdc;*(bw_buf+4)=0x05;                   //右三角前后复位
      *(bw_buf+5)=0xff;*(bw_buf+6)=0x02;*(bw_buf+7)=0x0d;*(bw_buf+8)=0xdc;*(bw_buf+9)=0x05;
      *(bw_buf+10)=0xff;*(bw_buf+11)=0x02;*(bw_buf+12)=0x08;*(bw_buf+13)=0xdc;*(bw_buf+14)=0x05;
      break;
    case 9:
      *bw_buf=0xff;*(bw_buf+1)=0x02;*(bw_buf+2)=0x00;*(bw_buf+3)=0xdc;*(bw_buf+4)=0x05;                   //左三角上下复位
      *(bw_buf+5)=0xff;*(bw_buf+6)=0x02;*(bw_buf+7)=0x05;*(bw_buf+8)=0xdc;*(bw_buf+9)=0x05;
      *(bw_buf+10)=0xff;*(bw_buf+11)=0x02;*(bw_buf+12)=0x02;*(bw_buf+13)=0xdc;*(bw_buf+14)=0x05;
      break;
    default:break;
  }
   uart_write_bytes(UART_NUM_0,(char*)bw_buf , 15);
}

void TXBUF::left(int mode){
  char *lt_buf = ( char *)malloc(15);
  switch(mode){
    case 0:
      *lt_buf=0xff;*(lt_buf+1)=0x02;*(lt_buf+2)=0x04;*(lt_buf+3)=0xf4;*(lt_buf+4)=0x01;                   //右三角抬起
      *(lt_buf+5)=0xff;*(lt_buf+6)=0x02;*(lt_buf+7)=0x01;*(lt_buf+8)=0xc4;*(lt_buf+9)=0x09;
      *(lt_buf+10)=0xff;*(lt_buf+11)=0x02;*(lt_buf+12)=0x06;*(lt_buf+13)=0xf4;*(lt_buf+14)=0x01;
      break;
    case 1:
      *lt_buf=0xff;*(lt_buf+1)=0x02;*(lt_buf+2)=0x0a;*(lt_buf+3)=0x8e;*(lt_buf+4)=0x04;                   //右三角旋转
      *(lt_buf+5)=0xff;*(lt_buf+6)=0x02;*(lt_buf+7)=0x0d;*(lt_buf+8)=0x8e;*(lt_buf+9)=0x04;
      *(lt_buf+10)=0xff;*(lt_buf+11)=0x02;*(lt_buf+12)=0x08;*(lt_buf+13)=0x8e;*(lt_buf+14)=0x04;
      break;
    case 2:
      *lt_buf=0xff;*(lt_buf+1)=0x02;*(lt_buf+2)=0x04;*(lt_buf+3)=0xdc;*(lt_buf+4)=0x05;                   //右三角上下复位
      *(lt_buf+5)=0xff;*(lt_buf+6)=0x02;*(lt_buf+7)=0x01;*(lt_buf+8)=0xdc;*(lt_buf+9)=0x05;
      *(lt_buf+10)=0xff;*(lt_buf+11)=0x02;*(lt_buf+12)=0x06;*(lt_buf+13)=0xdc;*(lt_buf+14)=0x05;
      break;
    case 3:
      *lt_buf=0xff;*(lt_buf+1)=0x02;*(lt_buf+2)=0x00;*(lt_buf+3)=0xc4;*(lt_buf+4)=0x09;                   //左三角抬起
      *(lt_buf+5)=0xff;*(lt_buf+6)=0x02;*(lt_buf+7)=0x05;*(lt_buf+8)=0xf4;*(lt_buf+9)=0x01;
      *(lt_buf+10)=0xff;*(lt_buf+11)=0x02;*(lt_buf+12)=0x02;*(lt_buf+13)=0xc4;*(lt_buf+14)=0x09;
      break;
    case 4:
      *lt_buf=0xff;*(lt_buf+1)=0x02;*(lt_buf+2)=0x0a;*(lt_buf+3)=0xdc;*(lt_buf+4)=0x05;                   //右三角前后复位
      *(lt_buf+5)=0xff;*(lt_buf+6)=0x02;*(lt_buf+7)=0x0d;*(lt_buf+8)=0xdc;*(lt_buf+9)=0x05;
      *(lt_buf+10)=0xff;*(lt_buf+11)=0x02;*(lt_buf+12)=0x08;*(lt_buf+13)=0xdc;*(lt_buf+14)=0x05;
      break;
    case 5:
      *lt_buf=0xff;*(lt_buf+1)=0x02;*(lt_buf+2)=0x00;*(lt_buf+3)=0xdc;*(lt_buf+4)=0x05;                   //左三角上下复位
      *(lt_buf+5)=0xff;*(lt_buf+6)=0x02;*(lt_buf+7)=0x05;*(lt_buf+8)=0xdc;*(lt_buf+9)=0x05;
      *(lt_buf+10)=0xff;*(lt_buf+11)=0x02;*(lt_buf+12)=0x02;*(lt_buf+13)=0xdc;*(lt_buf+14)=0x05;
      break;
    default:break;
  }
  uart_write_bytes(UART_NUM_0,(char*)lt_buf , 15);
}

void TXBUF::right(int mode){
  char *rt_buf = ( char *)malloc(15);
  switch(mode){
    case 0:
      *rt_buf=0xff;*(rt_buf+1)=0x02;*(rt_buf+2)=0x00;*(rt_buf+3)=0xc4;*(rt_buf+4)=0x09;                   //左三角抬起
      *(rt_buf+5)=0xff;*(rt_buf+6)=0x02;*(rt_buf+7)=0x05;*(rt_buf+8)=0xf4;*(rt_buf+9)=0x01;
      *(rt_buf+10)=0xff;*(rt_buf+11)=0x02;*(rt_buf+12)=0x02;*(rt_buf+13)=0xc4;*(rt_buf+14)=0x09;
      break;
    case 1:
      *rt_buf=0xff;*(rt_buf+1)=0x02;*(rt_buf+2)=0x0e;*(rt_buf+3)=0x29;*(rt_buf+4)=0x07;                   //左三角旋转
      *(rt_buf+5)=0xff;*(rt_buf+6)=0x02;*(rt_buf+7)=0x09;*(rt_buf+8)=0x29;*(rt_buf+9)=0x07;
      *(rt_buf+10)=0xff;*(rt_buf+11)=0x02;*(rt_buf+12)=0x0c;*(rt_buf+13)=0x29;*(rt_buf+14)=0x07;
      break;
    case 2:
      *rt_buf=0xff;*(rt_buf+1)=0x02;*(rt_buf+2)=0x00;*(rt_buf+3)=0xdc;*(rt_buf+4)=0x05;                   //左三角上下复位
      *(rt_buf+5)=0xff;*(rt_buf+6)=0x02;*(rt_buf+7)=0x05;*(rt_buf+8)=0xdc;*(rt_buf+9)=0x05;
      *(rt_buf+10)=0xff;*(rt_buf+11)=0x02;*(rt_buf+12)=0x02;*(rt_buf+13)=0xdc;*(rt_buf+14)=0x05;
      break;
    case 3:
      *rt_buf=0xff;*(rt_buf+1)=0x02;*(rt_buf+2)=0x04;*(rt_buf+3)=0xf4;*(rt_buf+4)=0x01;                   //右三角抬起
      *(rt_buf+5)=0xff;*(rt_buf+6)=0x02;*(rt_buf+7)=0x01;*(rt_buf+8)=0xc4;*(rt_buf+9)=0x09;
      *(rt_buf+10)=0xff;*(rt_buf+11)=0x02;*(rt_buf+12)=0x06;*(rt_buf+13)=0xf4;*(rt_buf+14)=0x01;
      break;
    case 4:
      *rt_buf=0xff;*(rt_buf+1)=0x02;*(rt_buf+2)=0x0e;*(rt_buf+3)=0xdc;*(rt_buf+4)=0x05;                   //左三角前后复位
      *(rt_buf+5)=0xff;*(rt_buf+6)=0x02;*(rt_buf+7)=0x09;*(rt_buf+8)=0xdc;*(rt_buf+9)=0x05;
      *(rt_buf+10)=0xff;*(rt_buf+11)=0x02;*(rt_buf+12)=0x0c;*(rt_buf+13)=0xdc;*(rt_buf+14)=0x05;
      break;
    case 5:
      *rt_buf=0xff;*(rt_buf+1)=0x02;*(rt_buf+2)=0x04;*(rt_buf+3)=0xdc;*(rt_buf+4)=0x05;                   //右三角上下复位
      *(rt_buf+5)=0xff;*(rt_buf+6)=0x02;*(rt_buf+7)=0x01;*(rt_buf+8)=0xdc;*(rt_buf+9)=0x05;
      *(rt_buf+10)=0xff;*(rt_buf+11)=0x02;*(rt_buf+12)=0x06;*(rt_buf+13)=0xdc;*(rt_buf+14)=0x05;
      break;
    default:break;
  }
  uart_write_bytes(UART_NUM_0,(char*)rt_buf , 15);
}
uint8_t TXBUF::UART_Init()
{
    // Configure parameters of an UART driver,
    // communication pins and install the driver
    uart_config_t uart_config = 
    {
        .baud_rate = 9600,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE
    };

    uart_param_config(UART_NUM_0, &uart_config);                                            // 配置串口0参数
    uart_set_pin(UART_NUM_0,UART_PIN_NO_CHANGE,UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);// 配置串口0引脚
    // Install UART driver, and get the queue.
    uart_driver_install(UART_NUM_0, BUF_SIZE * 2, BUF_SIZE * 2, 100, &s_uart0Queue, 0);     // 安装UART驱动程序
}
