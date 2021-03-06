#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"

int main(int argc, char *argv[])
{
	GPIO_InitTypeDef GPIO_InitStructure;
	u32 delay;

	/* GPIOC Periph clock enable */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);

	/* Configure PC12 to mode: slow rise-time, pushpull output */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_8;//GPIO No. 12
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;;//slow rise time
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;// push-pull output
	GPIO_Init(GPIOC,&GPIO_InitStructure);//GPIOC init

	while(1)
	{
		/* make some float calculations */
		float x = 42,y = 23,z = 7;
		int i = 0;
		for (i = 0;i<6;i++)
		{
			z = (x*y)/z;
		};
		GPIO_WriteBit(GPIOC,GPIO_Pin_8,Bit_SET);
		/* GPIO PC12 set, pin=high,LED_E off */
		GPIOC->BSRR = GPIO_BSRR_BS9;
		/* GPIO_WriteBit(GPIOC,GPIO_Pin_9,Bit_SET); */

		/*delay ->> compiler optimizer settings must be "-O0" */
		delay = 500000;
		while(delay)
		{
			delay--;
		}
		delay = 500000;
		while(delay)
			delay--;

		/* GPIO PC12 reset pin=low, LED_E on */
		GPIOC->BRR= 1<<9;
		GPIOC->BRR= 1<<8;
		delay = 500000;
		while(delay)
			delay--;
		delay = 500000;
		while(delay)
			delay--;


		/* delay --> blah */
		
			
	}
}