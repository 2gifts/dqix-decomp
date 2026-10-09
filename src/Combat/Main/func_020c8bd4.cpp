#include <globaldefs.h>

extern int data_02111588[3];
extern char data_021115b4;
extern int data_0211158c;
extern int data_02111590;
void EnableSystemControlBit0();
void DisableSystemControlBit0();

// USA: func_020c8bd4
extern "C" ARM void func_020c8bd4()
{
    if (data_02111588[2])
    {
        asm
        {
            mrs r2, cpsr
            mov r0, sp
            ldr r1, =0x9F
            msr cpsr_fsxc, r1
            mov r1, sp
            mov sp, r0
            stmdb sp!, {r1, r2}
            bl EnableSystemControlBit0
            ldr r0, =data_021115b4
            ldr r1, =data_0211158c
            ldr r1, [r1]
            ldr r12, =data_02111590
            ldr r12, [r12]
            ldr lr, =@ret
            bx r12
@ret:
            bl DisableSystemControlBit0
            ldmia sp!, {r1, r2}
            mov sp, r1
            msr cpsr_fsxc, r2
        }
    }
}
