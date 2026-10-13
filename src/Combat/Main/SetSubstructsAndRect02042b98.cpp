#include <globaldefs.h>

struct Holder02042c24;
void SetSubstructXY02042c24(struct Holder02042c24* holder, int x, int y);

struct Holder02042c3c;
void SetSubstructSize02042c3c(struct Holder02042c3c* holder, int width, int height);

struct Rect02042c54;
void SetRect02042c54(struct Rect02042c54* rect, int left, int top, int right, int bottom);

#if defined(jpn)
#define func_02042b98 func_02043270
enum { kCenterOffset = 0x860, kHolderOffset = 0x1804, kXOffset = 0x1728, kYOffset = 0x172c, kRectOffset = 0x1718 };
#else
enum { kCenterOffset = 0x990, kHolderOffset = 0x19e0, kXOffset = 0x1858, kYOffset = 0x185c, kRectOffset = 0x1848 };
#endif

// USA: func_02042b98  (semantic: SetSubstructsAndRect02042b98)
extern "C" ARM void func_02042b98(void* self, int arg1, int arg2, int arg3, int arg4) {
    char* p = (char*)self;
    *(int*)(p + kCenterOffset) = arg1 + (arg3 >> 1);
    SetSubstructXY02042c24((struct Holder02042c24*)(p + kHolderOffset), (short)arg1, (short)arg2);
    SetSubstructSize02042c3c((struct Holder02042c3c*)(p + kHolderOffset), (short)arg3, (short)arg4);
    *(int*)(p + kXOffset) = arg1;
    *(int*)(p + kYOffset) = arg2 + 8;
    SetRect02042c54((struct Rect02042c54*)(p + kRectOffset), arg1, arg2 + 8, arg1 + arg3, arg2 + arg4);
}
