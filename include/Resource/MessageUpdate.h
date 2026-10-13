#pragma once

struct MessageSystem;

void Forward020444d4(MessageSystem* window, int ticks);
extern "C" void func_02065990(MessageSystem* window, int ticks);
extern "C" int func_020440cc(MessageSystem* window);
int CheckAndClearFlag020656e4(MessageSystem* window, int unusedDelta);
unsigned short GetIndexedHalfword(MessageSystem* window);
void ProcessPendingFlag02045688(MessageSystem* window);
void InitCombatSlots02043040(MessageSystem* window);
void ResetControllerState020430b0(MessageSystem* window);

#if defined(jpn)
extern "C" int func_02069430(void* unused, unsigned short token);
extern "C" int func_02069444(void* unused, unsigned short token);
#else
bool IsHighByteFF02044494(void* unused, void* token);
int Dispatch02044420(void* unused, void* token);
#endif
