#include <stdint.h>
#include <xmc4500.h>
#include <core_cm4.h>

/* Variables set in the loeader script for memory layout */
extern uint32_t _sfixed;
extern uint32_t _efixed;
extern uint32_t _etext;
extern uint32_t _srelocate;
extern uint32_t _erelocate;
extern uint32_t _szero;
extern uint32_t _ezero;
extern uint32_t _sstack;
extern uint32_t _estack;

int main(void);

void __libc_init_array(void);

volatile uint32_t tickflag;
volatile uint32_t systick_count;

void SysTick_Handler(void)
{
	tickflag = 1;
	systick_count++;
}

void initSysTick()
{		
	// Use processor clock, enable interrupt request and enable counter
	PPB->SYST_CSR |= 0x7; 
	// Set the reload register (timebase in effect)
	PPB->SYST_RVR = SystemCoreClock/1000-1; //16000000 -1; // generate 1/2 second time base
	PPB->SYST_CVR=5; // Start the counter at a value close to zero
	__enable_irq();
	PORT1->OUT = 1;
}

void Reset_Handler(void)
{
	uint32_t *pSrc, *pDest;

	/* Chip dependent clock and memory setup */
    SystemInit();

	/* Initialize the relocate segment */
	pSrc = &_etext;
	pDest = &_srelocate;

	if (pSrc != pDest) {
		for (; pDest < &_erelocate;) {
			*pDest++ = *pSrc++;
		}
	}

	/* Clear the zero segment */
	for (pDest = &_szero; pDest < &_ezero;) {
		*pDest++ = 0;
	}

	/* Set the vector table base address */
	pSrc = (uint32_t *) & _sfixed;
	SCB->VTOR = ((uint32_t) pSrc & SCB_VTOR_TBLOFF_Msk);
    
	/* Initialize the C library */
	__libc_init_array();

	/* 1 millsecond timer tick */
	initSysTick();

	/* Branch to main function */
	main();

	/* Infinite loop */
	while (1);
}
