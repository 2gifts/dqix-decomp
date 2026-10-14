#include <globaldefs.h>
#include <std_library_functions.h>
#include "GameState/GameState.h"
#include "Resource/MessageSystem.h"

#if defined(jpn)

extern "C" void func_02045ca4(void*, const char*, int);
extern "C" void func_0206cb14(void*, int, unsigned short);
extern "C" void func_0205e944(void*, int);
extern "C" void func_02041bbc(State0204166c*);
extern "C" void func_02043270(void*, int, int, int, int);
extern "C" void func_02044d0c(void);
extern "C" void func_02044104(Struct0204394c*);
extern "C" void func_020698d8(void*, int, const char*, char*);
extern "C" void func_02069ecc(MessageSystem0219050c*, const char*, char*);
extern "C" void func_0206c570(void*, const char*);
unsigned char* GetField4Ptr020e1b24(void*);
extern "C" void func_020e1b2c(void*, int);
extern "C" int func_020e1f1c(void*);
extern "C" void func_020e2110(void*);
extern "C" void func_020e23f4(void*);
void InvokeSubHandlerIfPresent(int*);
void SetEntryEnabled020e2cc4(Entry020e2cc4*, int);
void CopyInternalFields0207df50(Foo0207df50*);
extern int data_02108760;

#else

extern "C" void __clear(void* dst, int size);
extern "C" void* memcpy(void* dst, const void* src, unsigned int size);
extern "C" void* memset(void* dst, int value, unsigned int size);
void* Clear12Bytes020e46c4(void*);
void DispatchIfCountPositive020dcf7c(int, void*);
int StringLength(const char*);
extern "C" void func_02044f3c(struct MessageSystem* window, const char* text, int mode);
void DecrementSlotRef0206b198(struct CombatSlots0206b198*, unsigned short);
extern "C" void func_0205e944(void* target, int level);
void Forward020416c0(struct State0204166c*);
extern "C" void func_02042b98(struct MessageSystem* window, int a, int b, int c, int d);
void ResetFoo02042fcc(struct Foo02042fcc*);
void SetRingBufferSlot02045824(struct RingBuffer02045824*, int, int);
extern "C" void func_02044d0c(void);
void PrepareEncodeStreamBuffer0204394c(struct Struct0204394c*);
extern "C" void func_0206831c(struct MessageSystem* window, const char* text, char* destination);
extern "C" void func_02068418(struct MessageSystem* window, const char* source, char* destination, int fontIndex);
extern "C" void func_02068f40(struct MessageSystem* window, const char* source, char* destination, int fontIndex);
extern "C" void func_02069234(struct MessageSystem* window, const char* source, char* destination, int fontIndex);
extern "C" void func_020695f4(struct MessageSystem* window, const char* source, char* destination, int fontIndex);
extern "C" void func_02069fec(struct MessageSystem* window, const char* source, char* destination);
void InitContextString0206a974(struct Ctx0206a974*, const char*, void*);
unsigned char* GetField4Ptr020e1b24(void*);
extern "C" void func_020e1b2c(void*, int);
extern "C" int func_020e1f1c(void*);
extern "C" void func_020e2110(void*);
extern "C" void func_020e23f4(void*);
void InvokeSubHandlerIfPresent(int*);
void SetEntryEnabled020e2cc4(struct Entry020e2cc4*, int);
void CopyInternalFields0207df50(struct Foo0207df50*);

extern int data_02108760;

#endif

#if defined(jpn)
// USA: func_0204500c
extern "C" ARM void func_0204500c(MessageSystem* window, const char* text, int mode) {
    if (text == 0) return;
    for (int i = 0; i < 4; i++) {
        window->b194e[i] = -1;
        window->b1952[i] = 0;
    }
    window->b1956 = 0;
    window->b1957 = 0;
    window->flags17ff.flag4 = 1;
    window->flags17ff.flag3 = 0;
    window->b1958 = 0;
    window->b195b = 0;
    window->w9b0 = 0;
    window->b195a = 12;
    if (window->mode == 3) {
        func_02045ca4(window, text, mode);
    } else {
        unsigned short lineGlyphCount = window->lineGlyphCount;
        unsigned short* lineGlyphSlots = window->lineGlyphSlots;
        for (unsigned short i = 0; i < lineGlyphCount; i++) {
            func_0206cb14(window, 10, lineGlyphSlots[i]);
        }
        memset(window->lineGlyphSlots, 0xff01, sizeof(window->lineGlyphSlots));
        window->b19c4 = 0;
        window->b19c3 = 0;
        window->lineGlyphCount = 0;
        window->h1944 = 0;
        window->b19c2 = 1;
        window->flags17ff.flag5 = 0;
        window->b19b0 = 0;
        window->b19bf = 1;
        window->flags17ff.flag1 = 1;
        window->levels[0] = window->levels[1] = window->levels[2] = window->levels[3] = 0x7f;
        func_0205e944(&data_02108760, 0x7f);
        memset(window->bitmapAllocationBits, 0, sizeof(window->bitmapAllocationBits));
        memset(window->textBuffer, 0, 0x800);
        memset(window->firstLineBuffer, 0, 0x140);
        memset(window->secondLineBuffer, 0, 0x140);
        window->b19bd = 1;
        window->allocatedGlyphCount = 14;
        for (int slot = 14; slot < 0x80; ++slot) {
            func_02041bbc(&window->glyphs[slot]);
            window->glyphReferences[slot] = 0;
        }
        window->b19bb = 1;
        window->w1860 = 0xc;
        window->w1864 = 0x10;
        window->h187c = 0x7fff;
        window->w9a4 = 3;
        func_02043270(window, 2, 0x80, 0xfc, 0x3e);
        window->b19b8 = 0;
        window->b19b1 = 1;
        window->w990 = 0x80;
        window->w1868 = 0;
        window->b912 = 0;
        window->w994 = -1;
        window->w94c[0] = 0;
        window->w94c[1] = 0;
        window->w94c[2] = 0;
        window->w94c[3] = 0;
        window->b19ac = 0;
        window->b19ad = 0;
        window->b1960 = 0;

        for (int i = 0; i < 4; i++) window->w1868 = 0;
        window->field17f2 = 0;
        window->b19c0 = 0;
        window->b195d = 0x1e;
        window->b19c1 = 0;
        window->b19c6 = 0;
        window->b19c7 = 0;
        window->b19c8 = 0;
        window->b19c9 = 0;
        window->h187e = 0;
        window->b19cc = 0;
        window->flags17ff.streamMode = 0;
        window->b19cd = 0;
        if (mode == 1) {
            window->b19cc = 1;
        } else if (mode == 1) {

            window->flags17ff.streamMode = 1;
        }
        if (window->b19cc != 0) {
            window->b19cd = 1;
            window->stream40 = 0;
            func_02044d0c();
        }
        if (window->flags17ff.streamMode != 0) {
            window->stream44 = 0;
            func_02044104((Struct0204394c*)window->encoder);
        }
        func_020698d8(window, window->b195a, text, window->formatBuffer);
        func_02069ecc((MessageSystem0219050c*)window, window->formatBuffer, window->expandedBuffer);
        func_0206c570(window, window->expandedBuffer);
        func_02043270(window, 2, 0x74, 0xfc, 0x4a);
        window->w1858 = 2;
        window->w185c = 0x7e;
        window->w1860 = 0xc;
        window->w1864 = 0x14;
        if (window->frame != 0) {
            unsigned char* frame = GetField4Ptr020e1b24(window->frame);
            if (frame != 0) {
                frame[0x38] = 2;
                frame[0x39] = 0x74;
                frame[0x3a] = 0xfc;
                frame[0x3b] = 0x4a;
                func_020e1b2c(window->frame, -1);
                if (func_020e1f1c(window->frame) != 0) {
                    func_020e2110(window->frame);
                    func_020e23f4(window->frame);
                    InvokeSubHandlerIfPresent((int*)window->frame);
                }
            }
        }
        memset(window->block95c, 0, sizeof(window->block95c));
        memset(window->block97c, 0, sizeof(window->block97c));
        window->w994 = -1;
        window->b19bc = 0;
        window->mode = 5;
        window->b19b2 = 1;
        window->state = 0;
        window->b19ae = 0;
        window->b19af = 0;
        window->b19b5 = 0;
        window->b19c5 = 0;
        window->b19ca = 1;
        window->b19b4 = 0;
        for (int i = 0; i < 2; i++) {
            SetEntryEnabled020e2cc4(&window->entries[i].prefix, 0);
        }
        if (window->encoder != 0) CopyInternalFields0207df50(window->encoder);
    }
}
#else
// USA: func_0204500c
extern "C" ARM void func_0204500c(struct MessageSystem* window, const char* text, int mode, void* context) {
    GameState* gs = GameState::GetInstance();

    short itemId = *reinterpret_cast<short*>(&gs->unk_6fc0[0x7f58 - 0x6fc0]);
    ItemNameText itemName;
    Clear12Bytes020e46c4(&itemName);
    if (itemId > 0) {
        char first[0x80] = {};
        char second[0x80] = {};
        itemName.first = first;
        itemName.second = second;
        DispatchIfCountPositive020dcf7c(itemId, &itemName);
        window->itemName = &itemName;
    }
    window->b19dc = 1;
    if (text == 0) {
        return;
    }

    int len = StringLength(text);
    for (int pos = 0; pos < len;) {
        int n = 0x40;
        char chunk[0x43] = {};
        if (len < pos + 0x40) {
            n = len - pos;
        }
        memcpy(chunk, text + pos, n);
        pos += n;
    }

    for (int i = 0; i < 4; i++) {
        window->b194e[i] = -1;
        window->b1952[i] = 0;
    }
    window->b1956 = 0;
    window->b1957 = 0;
    window->b19d2 = 1;
    window->b19d1 = 0;
    window->b1958 = 0;
    window->b195b = 0;
    window->w9b0 = 0;
    window->b195a = 8;

    if (window->mode == 3) {
        func_02044f3c(window, text, mode);
    } else {
        unsigned short lineGlyphCount = window->lineGlyphCount;
        for (unsigned short i = 0; i < lineGlyphCount; i++) {
            DecrementSlotRef0206b198((struct CombatSlots0206b198*)window, window->lineGlyphSlots[i]);
        }
        memset(window->lineGlyphSlots, 0xff01, sizeof(window->lineGlyphSlots));
        memset(window->slotData, 0, sizeof(window->slotData));
        window->b19c4 = 0;
        window->b19c3 = 0;
        window->lineGlyphCount = 0;
        window->h1944 = 0;
        window->h1946 = 0;
        window->b19c2 = 1;
        window->b19d3 = 0;
        window->b19b0 = 0;
        window->b19bf = 1;
        window->b19cf = 1;
        window->levels[0] = window->levels[1] = window->levels[2] = window->levels[3] = 0x7f;
        func_0205e944(&data_02108760, 0x7f);
        memset(window->bitmapAllocationBits, 0, sizeof(window->bitmapAllocationBits));
        memset(window->textBuffer, 0, 0x960);
        memset(window->firstLineBuffer, 0, 0x280);
        memset(window->secondLineBuffer, 0, 0x280);
        window->b19bd = 1;
        window->allocatedGlyphCount = 0;
        for (int slot = 0; slot < 0x80; ++slot) {
            Forward020416c0(&window->glyphs[slot]);
            window->glyphReferences[slot] = 0;
        }
        window->b19bb = 1;
        window->w1860 = 0xc;
        window->w1864 = 0x10;
        window->h187c = 0x7fff;
        window->w9a4 = 3;
        func_02042b98(window, 2, 0x80, 0xfc, 0x3e);
        ResetFoo02042fcc(&window->foo930);
        window->b19b8 = 0;
        window->b19b1 = 1;
        window->w990 = 0x80;
        window->w1868 = 0;
        window->b912 = 0;
        window->w994 = -1;
        window->w94c[0] = 0;
        window->w94c[1] = 0;
        window->w94c[2] = 0;
        window->w94c[3] = 0;
        window->b19ac = 0;
        window->b19ad = 0;
        window->b1960 = 0;
        SetRingBufferSlot02045824((struct RingBuffer02045824*)window, 0, -1);
        window->b19c0 = 0;
        window->b195d = 0x1e;
        window->b19c1 = 0;
        window->b19c6 = 0;
        window->b19c7 = 0;
        window->b19c8 = 0;
        window->b19c9 = 0;
        window->h187e = 0;
        window->b19cc = 0;
        window->b19ce = 0;
        window->b19cd = 0;
        if (mode == 1) {
            window->b19cc = 1;
        } else if (mode == 1) {

            window->b19ce = 1;
        }
        if (window->b19cc != 0) {
            window->b19cd = 1;
            window->stream40 = 0;
            func_02044d0c();
        }
        if (window->b19ce != 0) {
            window->stream44 = 0;
            PrepareEncodeStreamBuffer0204394c((struct Struct0204394c*)window->encoder);
        }
        char* formatBuffer = window->formatBuffer;
        char* expandedBuffer = window->expandedBuffer;
        func_0206831c(window, text, formatBuffer);
        func_02068418(window, formatBuffer, expandedBuffer, window->b19dc);
        func_02068f40(window, expandedBuffer, formatBuffer, window->b19dc);
        func_02069234(window, formatBuffer, expandedBuffer, window->b19dc);
        func_020695f4(window, expandedBuffer, formatBuffer, window->b19dc);
        func_02069fec(window, formatBuffer, expandedBuffer);
        InitContextString0206a974((struct Ctx0206a974*)window, expandedBuffer, context);
        func_02042b98(window, 2, 0x74, 0xfc, 0x4a);
        window->w1858 = 2;
        window->w185c = 0x7e;
        window->w1860 = 0xc;
        window->w1864 = 0x14;
        if (window->frame != 0) {
            unsigned char* frame = GetField4Ptr020e1b24(window->frame);
            if (frame != 0) {
                frame[0x38] = 2;
                frame[0x39] = 0x74;
                frame[0x3a] = 0xfc;
                frame[0x3b] = 0x4a;
                func_020e1b2c(window->frame, -1);
                if (func_020e1f1c(window->frame) != 0) {
                    func_020e2110(window->frame);
                    func_020e23f4(window->frame);
                    InvokeSubHandlerIfPresent((int*)window->frame);
                }
            }
        }
        memset(window->block95c, 0, sizeof(window->block95c));
        memset(window->block97c, 0, sizeof(window->block97c));
        window->w994 = -1;
        window->b19bc = 0;
        window->mode = 5;
        window->b19b2 = 1;
        window->state = 0;
        window->b19ae = 0;
        window->b19af = 0;
        window->b19b5 = 0;
        window->b19c5 = 0;
        window->b19ca = 1;
        window->b19b4 = 0;
        for (int i = 0; i < 2; i++) {
            SetEntryEnabled020e2cc4(&window->entries[i], 0);
        }
        if (window->encoder != 0) {
            CopyInternalFields0207df50(window->encoder);
        }
    }
    window->cursor30 = -1;
    window->cursor31 = -1;
    if (itemId > 0) {
        *reinterpret_cast<short*>(&gs->unk_6fc0[0x7f58 - 0x6fc0]) = 0;
    }
}

#endif
