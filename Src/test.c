#include "test.h"
#include "stdio.h"
#include "string.h"
#include "uart.h"

void startTest(TimeDate_t *test_data)
{
	uint8_t	test_buff[64] = {0};
	uint8_t test_buff_size = collectTestBuff(test_data, test_buff);
	sendTestBuff(test_buff, test_buff_size);
}

uint8_t collectTestBuff(TimeDate_t *comp_data, uint8_t *res)
{
	char month[4] = {0};
	getMonthName(month, comp_data->Month);

	uint8_t size =
			sprintf((char *)res,
					" Build Date/Time: %s %02d %d %02d:%02d:%02d\n\r",
					month,
					(int)comp_data->Day,
					(int)comp_data->Year,
					(int)comp_data->Hour,
					(int)comp_data->Minute,
					(int)comp_data->Second
			);
	return size;

}

void sendTestBuff(uint8_t *buff, uint8_t size)
{
	uartInit();
	uartSendBuff(buff, size);
}
