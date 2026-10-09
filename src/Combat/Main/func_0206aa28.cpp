#include <globaldefs.h>
#include <std_library_functions.h>

struct TextContext {
    char pad_0[0x48];
    char* source;
    void* field_4c;
    char* destination;
    char* cursor;
    char* next;
    char pad_5c[0xc];
    unsigned int sourceLength;
    int field_6c;
    int length;
    int field_74;
    int field_78;
    int field_7c;
    char pad_80[0x918];
    int active;
    char pad_99c[0x19cc - 0x99c];
    unsigned char preserved;
    char pad_19cd[0xf];
    unsigned char fontTable;
};

struct Entry0204254c {
    int key;
    signed char width;
    signed char size : 6;
    signed char flags : 2;
    char pad_6[2];
};

extern "C" bool _Z20IsHighByteFF0206ac6cPvS_(void*, void*);
extern "C" int _Z12Func0206abf8PvS_(void*, void*);
extern "C" bool _Z24IsCommandInRange02067a9cPvS_(void*, void*);
extern "C" void _Z24ReinitController02043204Pc(char*);
extern "C" void func_02043124(void*);
extern "C" char* func_0206ac94(void*, unsigned short, char*);
extern "C" Entry0204254c* _Z22FindEntryByKey0204254cii(int, int);
extern "C" void func_0206ad74(void*);

// USA: func_0206aa28
extern "C" ARM void func_0206aa28(TextContext* context) {
    context->field_7c = 0;
    context->field_6c = 0;
    context->length = 0;
    context->field_74 = 0;
    context->field_78 = 0;
    char* cursor = context->cursor;
    char* output = context->destination;
    int seenGlyph = 0;
    for (;;) {
        if (!*cursor) break;
        int commandBytes = 0;
        if (_Z20IsHighByteFF0206ac6cPvS_(context, cursor)) {
            int words = _Z12Func0206abf8PvS_(context, cursor) + 1;
            commandBytes = words * 2;
            memcpy(output, cursor, commandBytes);
            output += words * 2;
            context->length += words * 2;
        }
        if (context->sourceLength < (unsigned int)(cursor - context->source)) {
            context->active = 0;
            break;
        }
        if (_Z20IsHighByteFF0206ac6cPvS_(context, cursor)) {
            if (_Z24IsCommandInRange02067a9cPvS_(context, cursor)) {
                if (seenGlyph) {
                    context->next = cursor;
                    break;
                }
                unsigned char saved = context->preserved;
                _Z24ReinitController02043204Pc((char*)context);
                func_02043124(context);
                context->preserved = saved;
                break;
            }
            unsigned short command;
            memcpy(&command, cursor, 2);
            cursor += commandBytes;
            if ((command & 0xffe0) == 0xffe0) {
                command = (unsigned short)(command ^ 0xffe0) + 0xffd0;
                cursor = func_0206ac94(context, command, context->source);
                if (!cursor) {
                    unsigned char saved = context->preserved;
                    _Z24ReinitController02043204Pc((char*)context);
                    func_02043124(context);
                    context->preserved = saved;
                    break;
                }
            }
        } else {
            seenGlyph = 1;
            int size = 1;
            Entry0204254c* entry = _Z22FindEntryByKey0204254cii((int)cursor, context->fontTable);
            if (entry) size = entry->size;
            memcpy(output, cursor, size);
            output += size;
            context->length++;
            cursor += size;
        }
    }
    func_0206ad74(context);
}
