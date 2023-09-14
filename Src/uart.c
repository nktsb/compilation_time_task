#include "uart.h"
#include "stm32f1xx.h"

void uartInit(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
	GPIOA->CRL &= ~(GPIO_CRL_MODE2 | GPIO_CRL_CNF2);
	GPIOA->CRL |= (GPIO_CRL_MODE2_1 | GPIO_CRL_CNF2_1);
	GPIOA->CRL &= ~(GPIO_CRL_MODE3 | GPIO_CRL_CNF3);
	GPIOA->CRL |= GPIO_CRL_CNF3_0;

	USART2->BRR = 0xD05;
	USART2->CR1 |= USART_CR1_TE | USART_CR1_UE;

}

void uartSendBuff(uint8_t *buff, uint8_t size)
{
	for(uint8_t i = 0; i < size; i++)
	{
		USART2->DR = buff[i];
		while(!(USART2->SR & USART_SR_TC));
	}
}
