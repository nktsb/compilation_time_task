#ifndef __TIME_H_
#define __TIME_H_

#include "stdint.h"
#include "compilation_time.h"

void startTest(TimeDate_t *test_data);
uint8_t collectTestBuff(TimeDate_t *comp_data, uint8_t *res);
void sendTestBuff(uint8_t *buff, uint8_t size);

#endif //__TIME_H_
