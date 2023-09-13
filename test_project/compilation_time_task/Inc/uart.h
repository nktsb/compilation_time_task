#ifndef __UART_H_
#define __UART_H_

#include "stdint.h"

void uartInit(void);
void uartSendBuff(uint8_t *buff, uint8_t size);

#endif //__UART_H_
