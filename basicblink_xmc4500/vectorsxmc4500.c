/*****************************************************************************/
/* Startup_XMC4500.s: Startup file for XMC4500 device series                 */
/*****************************************************************************/

//#include <uc_id.inc>

/* ===========START : MACRO DEFINITION MACRO DEFINITION ================== */
/*
 * STEP_AB and below have the prefetch bug. A veneer defined below will first
 * be executed which in turn branches to the final exception handler.
 * 
 * In addition to defining the veneers, the vector table must for these buggy
 * devices contain the veneers. 
 */
 
#if (UC_STEP > STEP_AB)
   
#else
   
#endif

extern void _estack();

extern void Reset_Handler(void);
void Default_Handler();

void NMI_Handler()  			__attribute__((weak, alias("Default_Handler")));
void HardFault_Handler()  		__attribute__((weak, alias("Default_Handler")));
void MemManage_Handler()  		__attribute__((weak, alias("Default_Handler")));
void BusFault_Handler()  		__attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler()  		__attribute__((weak, alias("Default_Handler")));
void SVC_Handler()  			__attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler()  		__attribute__((weak, alias("Default_Handler")));
void PendSV_Handler()  			__attribute__((weak, alias("Default_Handler")));
void SysTick_Handler()  		__attribute__((weak, alias("Default_Handler")));

/* ============= END OF EXCEPTION HANDLER DEFINITION ======================== */

/* ============= START OF INTERRUPT HANDLER DEFINITION ====================== */

void SCU_0_IRQ()  		__attribute__((weak, alias("Default_Handler")));
void ERU0_0_IRQ()  		__attribute__((weak, alias("Default_Handler")));
void ERU0_1_IRQ()  		__attribute__((weak, alias("Default_Handler")));
void ERU0_2_IRQ()  		__attribute__((weak, alias("Default_Handler")));
void ERU0_3_IRQ()  		__attribute__((weak, alias("Default_Handler")));
void ERU1_0_IRQ()  		__attribute__((weak, alias("Default_Handler")));
void ERU1_1_IRQ()  		__attribute__((weak, alias("Default_Handler")));
void ERU1_2_IRQ()  		__attribute__((weak, alias("Default_Handler")));
void ERU1_3_IRQ()  		__attribute__((weak, alias("Default_Handler")));
void PMU0_0_IRQ()  		__attribute__((weak, alias("Default_Handler")));
void VADC0_C0_0_IRQ()  	__attribute__((weak, alias("Default_Handler")));
void VADC0_C0_1_IRQ()  	__attribute__((weak, alias("Default_Handler")));
void VADC0_C0_2_IRQ()  	__attribute__((weak, alias("Default_Handler")));
void VADC0_C0_3_IRQ()  	__attribute__((weak, alias("Default_Handler")));
void VADC0_G0_0_IRQ()  	__attribute__((weak, alias("Default_Handler")));
void VADC0_G0_1_IRQ()  	__attribute__((weak, alias("Default_Handler")));
void VADC0_G0_2_IRQ()  	__attribute__((weak, alias("Default_Handler")));
void VADC0_G0_3_IRQ()  	__attribute__((weak, alias("Default_Handler")));
void VADC0_G1_0_IRQ()  	__attribute__((weak, alias("Default_Handler")));
void VADC0_G1_1_IRQ()  	__attribute__((weak, alias("Default_Handler")));
void VADC0_G1_2_IRQ()  	__attribute__((weak, alias("Default_Handler")));
void VADC0_G1_3_IRQ()  	__attribute__((weak, alias("Default_Handler")));
void VADC0_G2_0_IRQ()  	__attribute__((weak, alias("Default_Handler")));
void VADC0_G2_1_IRQ()  	__attribute__((weak, alias("Default_Handler")));
void VADC0_G2_2_IRQ()  	__attribute__((weak, alias("Default_Handler")));
void VADC0_G2_3_IRQ()  	__attribute__((weak, alias("Default_Handler")));
void VADC0_G3_0_IRQ()  	__attribute__((weak, alias("Default_Handler")));
void VADC0_G3_1_IRQ()  	__attribute__((weak, alias("Default_Handler")));
void VADC0_G3_2_IRQ()  	__attribute__((weak, alias("Default_Handler")));
void VADC0_G3_3_IRQ()  	__attribute__((weak, alias("Default_Handler")));
void DSD0_0_IRQ()  		__attribute__((weak, alias("Default_Handler")));
void DSD0_1_IRQ()  __attribute__((weak, alias("Default_Handler")));
void DSD0_2_IRQ()  __attribute__((weak, alias("Default_Handler")));
void DSD0_3_IRQ()  __attribute__((weak, alias("Default_Handler")));
void DSD0_4_IRQ()  __attribute__((weak, alias("Default_Handler")));
void DSD0_5_IRQ()  __attribute__((weak, alias("Default_Handler")));
void DSD0_6_IRQ()  __attribute__((weak, alias("Default_Handler")));
void DSD0_7_IRQ()  __attribute__((weak, alias("Default_Handler")));
void DAC0_0_IRQ()  __attribute__((weak, alias("Default_Handler")));
void DAC0_1_IRQ()  		__attribute__((weak, alias("Default_Handler")));
void CCU40_0_IRQ()  		__attribute__((weak, alias("Default_Handler")));
void CCU40_1_IRQ()  		__attribute__((weak, alias("Default_Handler")));
void CCU40_2_IRQ()  		__attribute__((weak, alias("Default_Handler")));
void CCU40_3_IRQ()  		__attribute__((weak, alias("Default_Handler")));
void CCU41_0_IRQ()  		__attribute__((weak, alias("Default_Handler")));
void CCU41_1_IRQ()  __attribute__((weak, alias("Default_Handler")));
void CCU41_2_IRQ()  __attribute__((weak, alias("Default_Handler")));
void CCU41_3_IRQ()  __attribute__((weak, alias("Default_Handler")));
void CCU42_0_IRQ()  __attribute__((weak, alias("Default_Handler")));
void CCU42_1_IRQ()  __attribute__((weak, alias("Default_Handler")));
void CCU42_2_IRQ()  __attribute__((weak, alias("Default_Handler")));
void CCU42_3_IRQ()  __attribute__((weak, alias("Default_Handler")));
void CCU43_0_IRQ()  __attribute__((weak, alias("Default_Handler")));
void CCU43_1_IRQ()  __attribute__((weak, alias("Default_Handler")));
void CCU43_2_IRQ()  __attribute__((weak, alias("Default_Handler")));
void CCU43_3_IRQ()  __attribute__((weak, alias("Default_Handler")));
void CCU80_0_IRQ()  __attribute__((weak, alias("Default_Handler")));
void CCU80_1_IRQ()  __attribute__((weak, alias("Default_Handler")));
void CCU80_2_IRQ()  __attribute__((weak, alias("Default_Handler")));
void CCU80_3_IRQ()  __attribute__((weak, alias("Default_Handler")));
void CCU81_0_IRQ()  __attribute__((weak, alias("Default_Handler")));
void CCU81_1_IRQ()  __attribute__((weak, alias("Default_Handler")));
void CCU81_2_IRQ()  __attribute__((weak, alias("Default_Handler")));
void CCU81_3_IRQ()  __attribute__((weak, alias("Default_Handler")));
void POSIF0_0_IRQ()  __attribute__((weak, alias("Default_Handler")));
void POSIF0_1_IRQ()  __attribute__((weak, alias("Default_Handler")));
void POSIF1_0_IRQ()  __attribute__((weak, alias("Default_Handler")));
void POSIF1_1_IRQ()  __attribute__((weak, alias("Default_Handler")));
void CAN0_0_IRQ()  __attribute__((weak, alias("Default_Handler")));
void CAN0_1_IRQ()  __attribute__((weak, alias("Default_Handler")));
void CAN0_2_IRQ()  __attribute__((weak, alias("Default_Handler")));
void CAN0_3_IRQ()  __attribute__((weak, alias("Default_Handler")));
void CAN0_4_IRQ()  __attribute__((weak, alias("Default_Handler")));
void CAN0_5_IRQ()  __attribute__((weak, alias("Default_Handler")));
void CAN0_6_IRQ()  __attribute__((weak, alias("Default_Handler")));
void CAN0_7_IRQ()  __attribute__((weak, alias("Default_Handler")));
void USIC0_0_IRQ()  __attribute__((weak, alias("Default_Handler")));
void USIC0_1_IRQ()  __attribute__((weak, alias("Default_Handler")));
void USIC0_2_IRQ()  __attribute__((weak, alias("Default_Handler")));
void USIC0_3_IRQ()  __attribute__((weak, alias("Default_Handler")));
void USIC0_4_IRQ()  __attribute__((weak, alias("Default_Handler")));
void USIC0_5_IRQ()  __attribute__((weak, alias("Default_Handler")));
void USIC1_0_IRQ()  __attribute__((weak, alias("Default_Handler")));
void USIC1_1_IRQ()  __attribute__((weak, alias("Default_Handler")));
void USIC1_2_IRQ()  __attribute__((weak, alias("Default_Handler")));
void USIC1_3_IRQ()  __attribute__((weak, alias("Default_Handler")));
void USIC1_4_IRQ()  __attribute__((weak, alias("Default_Handler")));
void USIC1_5_IRQ()  __attribute__((weak, alias("Default_Handler")));
void USIC2_0_IRQ()  __attribute__((weak, alias("Default_Handler")));
void USIC2_1_IRQ()  __attribute__((weak, alias("Default_Handler")));
void USIC2_2_IRQ()  __attribute__((weak, alias("Default_Handler")));
void USIC2_3_IRQ()  __attribute__((weak, alias("Default_Handler")));
void USIC2_4_IRQ()  __attribute__((weak, alias("Default_Handler")));
void USIC2_5_IRQ()  __attribute__((weak, alias("Default_Handler")));
void LEDTS0_0_IRQ()  __attribute__((weak, alias("Default_Handler")));
void FCE0_0_IRQ()  __attribute__((weak, alias("Default_Handler")));
void GPDMA0_0_IRQ()  __attribute__((weak, alias("Default_Handler")));
void SDMMC0_0_IRQ()  __attribute__((weak, alias("Default_Handler")));
void USB0_0_IRQ()  __attribute__((weak, alias("Default_Handler")));
void ETH0_0_IRQ()  __attribute__((weak, alias("Default_Handler")));
void GPDMA1_0_IRQ()  __attribute__((weak, alias("Default_Handler")));


/* ================== START OF VECTOR TABLE DEFINITION ====================== */
/* Vector Table - This gets programed into VTOR register by onchip BootROM */
const void * FlashVectors[] __attribute__((section(".vectors"))) ={
	(void *)_estack, 				    /* Top of stack  @0x10010000 */ 
	Reset_Handler, 		 				/* Reset Handler             */
    NMI_Handler,		   				/* NMI Handler                  */
    HardFault_Handler,           		/* Hard Fault Handler           */
    MemManage_Handler,          		/* MPU Fault Handler            */
    BusFault_Handler,           		/* Bus Fault Handler            */
    UsageFault_Handler,          		/* Usage Fault Handler          */
    0,                           /* Reserved                     */
    0,                  /* Reserved                     */
    0,                           /* Reserved                     */
    0,                           /* Reserved                     */
    SVC_Handler,              /* SVCall Handler               */
    DebugMon_Handler,            /* Debug Monitor Handler        */
    0,                           /* Reserved                     */
    PendSV_Handler,						/* PendSV Handler               */
    SysTick_Handler,             /* SysTick Handler              */

    /* Interrupt Handlers for Service Requests (SR) from XMC4500 Peripherals */
    SCU_0_IRQ,            /* Handler name for SR SCU_0     */
    ERU0_0_IRQ,           /* Handler name for SR ERU0_0    */
    ERU0_1_IRQ,           /* Handler name for SR ERU0_1    */
    ERU0_2_IRQ,           /* Handler name for SR ERU0_2    */
    ERU0_3_IRQ,           /* Handler name for SR ERU0_3    */ 
    ERU1_0_IRQ,           /* Handler name for SR ERU1_0    */
    ERU1_1_IRQ,           /* Handler name for SR ERU1_1    */
    ERU1_2_IRQ,           /* Handler name for SR ERU1_2    */
    ERU1_3_IRQ,           /* Handler name for SR ERU1_3    */
    0,                           /* Not Available                 */
    0,                           /* Not Available                 */
    0,                           /* Not Available                 */
    PMU0_0_IRQ,           /* Handler name for SR PMU0_0    */
    0,                           /* Not Available                 */
    VADC0_C0_0_IRQ,       /* Handler name for SR VADC0_C0_0  */
    VADC0_C0_1_IRQ,       /* Handler name for SR VADC0_C0_1  */
    VADC0_C0_2_IRQ,       /* Handler name for SR VADC0_C0_1  */
    VADC0_C0_3_IRQ,       /* Handler name for SR VADC0_C0_3  */
    VADC0_G0_0_IRQ,       /* Handler name for SR VADC0_G0_0  */
    VADC0_G0_1_IRQ,       /* Handler name for SR VADC0_G0_1  */
    VADC0_G0_2_IRQ,       /* Handler name for SR VADC0_G0_2  */
    VADC0_G0_3_IRQ,       /* Handler name for SR VADC0_G0_3  */
    VADC0_G1_0_IRQ,       /* Handler name for SR VADC0_G1_0  */
    VADC0_G1_1_IRQ,   /* Handler, name for SR VADC0_G1_1  */
    VADC0_G1_2_IRQ,   /* Handler, name for SR VADC0_G1_2  */
    VADC0_G1_3_IRQ,   /* Handler, name for SR VADC0_G1_3  */
    VADC0_G2_0_IRQ,   /* Handler, name for SR VADC0_G2_0  */
    VADC0_G2_1_IRQ,   /* Handler, name for SR VADC0_G2_1  */
    VADC0_G2_2_IRQ,   /* Handler, name for SR VADC0_G2_2  */
    VADC0_G2_3_IRQ,   /* Handler, name for SR VADC0_G2_3  */
    VADC0_G3_0_IRQ,   /* Handler, name for SR VADC0_G3_0  */
    VADC0_G3_1_IRQ,   /* Handler, name for SR VADC0_G3_1  */
    VADC0_G3_2_IRQ,   /* Handler, name for SR VADC0_G3_2  */
    VADC0_G3_3_IRQ,   /* Handler, name for SR VADC0_G3_3  */
    DSD0_0_IRQ,       /* Handler, name for SR DSD0_0    */
    DSD0_1_IRQ,       /* Handler, name for SR DSD0_1    */
    DSD0_2_IRQ,       /* Handler, name for SR DSD0_2    */
    DSD0_3_IRQ,       /* Handler, name for SR DSD0_3    */
    DSD0_4_IRQ,       /* Handler, name for SR DSD0_4    */
    DSD0_5_IRQ,       /* Handler, name for SR DSD0_5    */
    DSD0_6_IRQ,       /* Handler, name for SR DSD0_6    */
    DSD0_7_IRQ,       /* Handler, name for SR DSD0_7    */
    DAC0_0_IRQ,       /* Handler name for SR DAC0_0    */
    DAC0_1_IRQ,       /* Handler name for SR DAC0_0    */
    CCU40_0_IRQ,      /* Handler name for SR CCU40_0   */
    CCU40_1_IRQ,      /* Handler name for SR CCU40_1   */
    CCU40_2_IRQ,      /* Handler name for SR CCU40_2   */
    CCU40_3_IRQ,      /* Handler name for SR CCU40_3   */
    CCU41_0_IRQ,      /* Handler name for SR CCU41_0   */
    CCU41_1_IRQ,      /* Handler name for SR CCU41_1   */
    CCU41_2_IRQ,      /* Handler name for SR CCU41_2   */
    CCU41_3_IRQ,      /* Handler name for SR CCU41_3   */
    CCU42_0_IRQ,      /* Handler name for SR CCU42_0   */
    CCU42_1_IRQ,      /* Handler name for SR CCU42_1   */
    CCU42_2_IRQ,      /* Handler name for SR CCU42_2   */
    CCU42_3_IRQ,      /* Handler name for SR CCU42_3   */
    CCU43_0_IRQ,      /* Handler name for SR CCU43_0   */
    CCU43_1_IRQ,      /* Handler name for SR CCU43_1   */
    CCU43_2_IRQ,      /* Handler name for SR CCU43_2   */
    CCU43_3_IRQ,      /* Handler name for SR CCU43_3   */
    CCU80_0_IRQ,      /* Handler name for SR CCU80_0   */
    CCU80_1_IRQ,      /* Handler name for SR CCU80_1   */
    CCU80_2_IRQ,      /* Handler name for SR CCU80_2   */
    CCU80_3_IRQ,      /* Handler name for SR CCU80_3   */
    CCU81_0_IRQ,      /* Handler name for SR CCU81_0   */
    CCU81_1_IRQ,      /* Handler name for SR CCU81_1   */
    CCU81_2_IRQ,      /* Handler name for SR CCU81_2   */
    CCU81_3_IRQ,      /* Handler name for SR CCU81_3   */
    POSIF0_0_IRQ,     /* Handler name for SR POSIF0_0  */
    POSIF0_1_IRQ,     /* Handler name for SR POSIF0_1  */
    POSIF1_0_IRQ,     /* Handler name for SR POSIF1_0  */
    POSIF1_1_IRQ,     /* Handler name for SR POSIF1_1  */
    0,                           /* Not Available                 */
    0,                           /* Not Available                 */
    0,                           /* Not Available                 */
    0,                           /* Not Available                 */
    CAN0_0_IRQ,       /* Handler name for SR CAN0_0    */
    CAN0_1_IRQ,       /* Handler name for SR CAN0_1    */
    CAN0_2_IRQ,       /* Handler name for SR CAN0_2    */
    CAN0_3_IRQ,       /* Handler name for SR CAN0_3    */
    CAN0_4_IRQ,       /* Handler name for SR CAN0_4    */
    CAN0_5_IRQ,       /* Handler name for SR CAN0_5    */
    CAN0_6_IRQ,       /* Handler name for SR CAN0_6    */
    CAN0_7_IRQ,       /* Handler name for SR CAN0_7    */
    USIC0_0_IRQ,      /* Handler name for SR USIC0_0   */
    USIC0_1_IRQ,      /* Handler name for SR USIC0_1   */
    USIC0_2_IRQ,      /* Handler name for SR USIC0_2   */
    USIC0_3_IRQ,      /* Handler name for SR USIC0_3   */
    USIC0_4_IRQ,      /* Handler name for SR USIC0_4   */
    USIC0_5_IRQ,      /* Handler name for SR USIC0_5   */
    USIC1_0_IRQ,      /* Handler name for SR USIC1_0   */
    USIC1_1_IRQ,      /* Handler name for SR USIC1_1   */
    USIC1_2_IRQ,      /* Handler name for SR USIC1_2   */
    USIC1_3_IRQ,      /* Handler name for SR USIC1_3   */
    USIC1_4_IRQ,      /* Handler name for SR USIC1_4   */
    USIC1_5_IRQ,      /* Handler name for SR USIC1_5   */
    USIC2_0_IRQ,      /* Handler name for SR USIC2_0   */
    USIC2_1_IRQ,      /* Handler name for SR USIC2_1   */
    USIC2_2_IRQ,      /* Handler name for SR USIC2_2   */
    USIC2_3_IRQ,      /* Handler name for SR USIC2_3   */
    USIC2_4_IRQ,      /* Handler name for SR USIC2_4   */
    USIC2_5_IRQ,      /* Handler name for SR USIC2_5   */
    LEDTS0_0_IRQ,     /* Handler name for SR LEDTS0_0  */
    0,                           /* Not Available                 */
    FCE0_0_IRQ,       /* Handler name for SR FCE0_0    */
    GPDMA0_0_IRQ,     /* Handler name for SR GPDMA0_0  */
    SDMMC0_0_IRQ,     /* Handler name for SR SDMMC0_0  */
    USB0_0_IRQ,       /* Handler name for SR USB0_0    */
    ETH0_0_IRQ,       /* Handler name for SR ETH0_0    */
    0,                           /* Not Available                 */
    GPDMA1_0_IRQ,     /* Handler name for SR GPDMA1_0  */
    0                           /* Not Available                 */
};
/* ================== END OF VECTOR TABLE DEFINITION ======================= */

void Default_Handler()
{
	while(1);
}


