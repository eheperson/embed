#ifndef __TIMERDRIVER_H_
#define __TIMERDRIVER_H_
#include "memoryMap.h"

void  systickOne(void);

void  systickIDot5sec(void);

int countFlag(void);

void systickMsDelay(std::uint32_t delay);

void tim2OneHz(void);

void tim2Timeout(void);

void tim3OneHz(void);

void tim3Timeout(void);

void tim4OneHz(void);

void tim4Timeout(void);

void tim5OneHz(void);

void tim5Timeout(void);
#endif

