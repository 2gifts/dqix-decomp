// usa: 020c32f8
// jpn: 020c4dc4
extern "C" long long func_020c30ac(long long);
extern "C" long long func_020c3194(long long);
extern "C" long long func_020c32f8(int angle) {
 if(angle<0) return func_020c32f8(-angle);
 long long scaled=angle; scaled*=0x145f306ddLL; scaled>>=12;
 int quadrant=(int)(scaled>>32);
 long long fraction=scaled & 0xffffffffLL;
 if(quadrant&1) fraction=0x100000000LL-fraction;
 long long result;
 if((quadrant+1)&2) result=func_020c30ac(fraction);
 else result=func_020c3194(fraction);
 if(((quadrant+2) & 7)>3) return -result;
 return result;
}
