#include "compilation_time.h"
#include "string.h"
#include "stdio.h"

//#define USING_SSCANF

#define MONTH_NUM	12U

static const char month_gloss[MONTH_NUM][3] =
{
	"Jan",
	"Feb",
	"Mar",
	"Apr",
	"May",
	"Jun",
	"Jul",
	"Aug",
	"Sep",
	"Oct",
	"Nov",
	"Dec"
};

#ifdef USING_SSCANF

void getCompilationTimeAndDate(TimeDate_t *comp_data)
{
	const char *date = __DATE__; //	mmm dd yyyy
	const char *time = __TIME__; //	hh:mm:ss

	//	Get Time
	int hour, min, sec = 0;

	sscanf(time, "%d:%d:%d", &hour, &min, &sec);

	comp_data->Hour   = (u8)hour;
	comp_data->Minute = (u8)min;
	comp_data->Second = (u8)sec;

	//	Get Date
	char month[3] = {0};
	int day, year = 0;

	sscanf(date, "%s %d %d", month, &day, &year);

	comp_data->Month = (u8)((strstr((char *)month_gloss, month) - (char *)month_gloss)/3 + 1);
	comp_data->Day   = (u8)day;
	comp_data->Year  = (u16)year;
}

#else //without sscanf

void getCompilationTimeAndDate(TimeDate_t *comp_data)
{
	//	Get date
	const char *date = __DATE__; //	mmm dd yyyy
	const char *time = __TIME__; //	hh:mm:ss

	char buff[4] = {0};

	//	Get Time
	memcpy(buff, &time[0], 2); // hh
	comp_data->Hour = (u8)atoi(buff);

	memcpy(buff, &time[3], 2); // mm
	comp_data->Minute = (u8)atoi(buff);

	memcpy(buff, &time[6], 2); // ss
	comp_data->Second = (u8)atoi(buff);

	//	Get Date
	memcpy(buff, &date[4], 2); // dd
	comp_data->Day = (u8)atoi(buff);

	memcpy(buff, &date[0], 3); // mmm
	comp_data->Month = (u8)((strstr((char *)month_gloss, buff) - (char *)month_gloss)/3 + 1);

	memcpy(buff, &date[7], 4); // yyyy
	comp_data->Year = (u16)atoi(buff);
}

#endif

void getMonthName(char* data, uint8_t mon_num)
{
	memcpy(data, month_gloss[mon_num - 1], 3);
}
