// JPN: main:020cf468
struct RatioConfig { short numeratorA, numeratorB, divisorA, divisorB; };
struct RatioState { unsigned pad[7]; int numeratorA,divisorA,resultA,numeratorB,divisorB,resultB; unsigned short enabled; };
extern RatioState data_021117b0;
int DisableIRQInterrupts();
void SetIRQInterruptState(int);
#pragma optimize_for_size off
extern "C" void func_020cd99c(RatioConfig* config) {
 if(!config) { data_021117b0.enabled=0; return; }
 int irq=DisableIRQInterrupts();
 int divisor=config->divisorA;
 if(divisor) {
  *(volatile unsigned short*)0x04000280=0;
  *(volatile unsigned*)0x04000290=0x10000000;
  *(volatile unsigned long long*)0x04000298=(unsigned)divisor;
  data_021117b0.numeratorA=config->numeratorA;
  data_021117b0.divisorA=config->divisorA;
  while(*(volatile unsigned short*)0x04000280&0x8000) {}
  data_021117b0.resultA=*(volatile int*)0x040002a0;
 } else { data_021117b0.numeratorA=0;data_021117b0.divisorA=0;data_021117b0.resultA=0; }
 divisor=config->divisorB;
 if(divisor) {
  *(volatile unsigned short*)0x04000280=0;
  *(volatile unsigned*)0x04000290=0x10000000;
  *(volatile unsigned long long*)0x04000298=(unsigned)divisor;
  data_021117b0.numeratorB=config->numeratorB;
  data_021117b0.divisorB=config->divisorB;
  while(*(volatile unsigned short*)0x04000280&0x8000) {}
  data_021117b0.resultB=*(volatile int*)0x040002a0;
 } else { data_021117b0.numeratorB=0;data_021117b0.divisorB=0;data_021117b0.resultB=0; }
 SetIRQInterruptState(irq);
 data_021117b0.enabled=1;
}

#pragma optimize_for_size reset
