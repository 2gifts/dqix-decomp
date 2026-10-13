// JPN: func_ov009_02189af0
#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

struct Struct_0205bef8;
extern "C" void _Z12Init0205bef8P15Struct_0205bef8(struct Struct_0205bef8* s);
struct Struct_0205ba68;
extern "C" void _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii(struct Struct_0205ba68* s, int columns, int rows, int mode);
struct Node0205bacc;
extern "C" void _Z29SetField0AndPropagate0205baccP12Node0205bacci(struct Node0205bacc* s, int val);
struct SelfBB04;
extern "C" void func_0205bb04(struct SelfBB04* self, int value);

// USA: func_ov009_02188c2c  (semantic: DispatchTypeAndInitPair_02188c2c)
extern "C" ARM void func_ov009_02188c2c(CharacterCreationUI* editor) {
    int columns, rows, count, pageCount, selected;
    signed char id = editor->state;

    switch (id) {
    case 1:
        columns = 1;
        rows = 2;
        count = rows;
        pageCount = columns;
        selected = editor->sex;
        break;
    case 2: {
        unsigned char sel = editor->sex;
        columns = 5;
        rows = 1;
        count = columns;
        pageCount = rows;
        selected = editor->bodyType[sel];
        break;
    }
    case 3: {
        unsigned char sel = editor->sex;
        columns = 5;
        rows = 2;
        selected = editor->hairStyle[sel];
        count = 0xa;
        pageCount = 1;
        break;
    }
    case 4: {
        unsigned char sel = editor->sex;
        columns = 5;
        rows = 2;
        selected = editor->hairColor[sel];
        count = 0xa;
        pageCount = 1;
        break;
    }
    case 5: {
        unsigned char sel = editor->sex;
        columns = 5;
        rows = 2;
        selected = editor->faceStyle[sel];
        count = 0xa;
        pageCount = 1;
        break;
    }
    case 6: {
        unsigned char sel = editor->sex;
        columns = 4;
        rows = 2;
        selected = editor->eyeColor[sel];
        count = 8;
        pageCount = 1;
        break;
    }
    case 7: {
        unsigned char sel = editor->sex;
        columns = 4;
        rows = 2;
        selected = editor->skinColor[sel];
        count = 8;
        pageCount = 1;
        break;
    }
    case 8:
        columns = 0xb;
        rows = 6;
        count = 0x42;
        pageCount = 1;
#if defined(jpn)
        selected = editor->keyboardChoice;
#else
        selected = 0;
#endif
        break;
    default:
        break;
    }

    CreationNavigation* navigation = &editor->navigation;
    _Z12Init0205bef8P15Struct_0205bef8((struct Struct_0205bef8*)navigation);
    _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii((struct Struct_0205ba68*)navigation, columns, rows, 1);
    _Z29SetField0AndPropagate0205baccP12Node0205bacci((struct Node0205bacc*)navigation, count);
    navigation->field4 = pageCount;
    func_0205bb04((struct SelfBB04*)navigation, selected);
    navigation->flags3d = 0;
}
