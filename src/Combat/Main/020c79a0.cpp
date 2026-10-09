#include <globaldefs.h>
#include <System/Interrupts.h>
#include <System/ProcessorContext.h>

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020c79a0
void SwitchContextUninterrupted()
{
	int savedInterruptState = DisableIRQInterrupts();
	SwitchContext();
	SetIRQInterruptState(savedInterruptState);
}
