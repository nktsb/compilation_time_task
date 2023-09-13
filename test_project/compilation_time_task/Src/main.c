#include "main.h"
#include "clk.h"
#include "compilation_time.h"
#include "test.h"
#include "uart.h"

int main(void)
{
	initClk();

	TimeDate_t test_time = {0};
	getCompilationTimeAndDate(&test_time);

	startTest(&test_time);

	while(1);
}

