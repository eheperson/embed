#ifndef _UARTDRIVER_H_
#define _UARTDRIVER_H_
/*Procedure:
1. Enable the USART by writing the UE bit in USART_CR1 register to 1.
2. Program the M bit in USART_CR1 to define the word length.
3. Program the number of stop bits in USART_CR2.
4. Select DMA enable (DMAT) in USART_CR3 if Multi buffer Communication is to take
place. Configure the DMA register as explained in multibuffer communication.
5. Select the desired baud rate using the USART_BRR register.
6. Set the TE bit in USART_CR1 to send an idle frame as first transmission.
7. Write the data to send in the USART_DR register (this clears the TXE bit). Repeat this
for each data to be transmitted in case of single buffer.
8. After writing the last data into the USART_DR register, wait until TC=1. This indicates
that the transmission of the last frame is complete. This is required for instance when
the USART is disabled or enters the Halt mode to avoid corrupting the last
transmission.*/

#include "memoryMap.h"
#include <stdio.h>

/************************************** UART simplex Tx - Begin ****************************************/
void uartInitTx(void);
/**/
int uartWriteTx(int ch);
/************************************** UART simplex Tx - End ****************************************/
/**/
/**/
/**/
/************************************** UART simplex Rx - Begin ****************************************/
void uartInitRx(void);
/**/
char uartReadRx(void);
/************************************** UART simplex Rx - End ****************************************/
/**/
/**/
/**/
/************************************** UART duplex Rx-Tx - Begin **************************************/
void uartInitRTx(void);
/**/
char uartReadRTx(void);
/**/
int uartWriteRTx(int ch);
/************************************** UART duplex Rx-Tx - End **************************************/







#endif


