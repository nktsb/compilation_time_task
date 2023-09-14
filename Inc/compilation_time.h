#ifndef __COMPILATION_TIME_
#define __COMPILATION_TIME_

#include <stdint.h>
#include <stdlib.h>
#include "stm32f10x_type.h"

typedef struct
{
	u8 Second;
	u8 Minute;
	u8 Hour;
	s8 Zone;
	u8 Day;
	u8 WeekDay;
	u8 Month;
	u16 Year;
} TimeDate_t;

void getMonthName(char* data, uint8_t mon_num);
void getCompilationTimeAndDate(TimeDate_t *comp_data);

#endif //__COMPILATION_TIME_
