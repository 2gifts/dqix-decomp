#include <globaldefs.h>
#include <std_library_functions.h>

#if defined(jpn)
typedef unsigned short MessageCharacter;
#else
typedef char MessageCharacter;
#endif

#if defined(jpn)
enum { SourceField = 0x14, DestinationField = 0x1c, CursorField = 0x20,
       NextField = 0x24, SourceLengthField = 0x34, StateField = 0x38,
       LengthField = 0x3c, State2Field = 0x40, State3Field = 0x44 };
#else
enum { SourceField = 0x48, DestinationField = 0x50, CursorField = 0x54,
       NextField = 0x58, SourceLengthField = 0x68, StateField = 0x6c,
       LengthField = 0x70, State2Field = 0x74, State3Field = 0x78 };
#endif

struct Object02043124;
void ReinitController02043204(char*);
extern "C" void func_02043124(Object02043124*);

#if defined(jpn)
extern "C" int func_02069430(void*, unsigned short);
extern "C" int func_02069408(void*, unsigned short);
extern "C" unsigned short* func_0206c730(void*, unsigned short, unsigned short*);
extern "C" void func_0206c794(void*);
#else
struct Entry0204254c {
    int key;
    signed char width;
    signed char size : 6;
    signed char flags : 2;
    char unknown6[2];
};
int IsHighByteFF0206ac6c(void*, void*);
int Func0206abf8(void*, void*);
bool IsCommandInRange02067a9c(void*, void*);
Entry0204254c* FindEntryByKey0204254c(int, int);
extern "C" char* func_0206ac94(void*, unsigned short, char*);
extern "C" void func_0206ad74(void*);
#endif

// USA: func_0206aa28
extern "C" ARM void func_0206aa28(char* context) {
#if !defined(jpn)
    *(int*)(context + 0x7c) = 0;
#endif
    (*(int*)(context + StateField)) = 0;
    (*(int*)(context + LengthField)) = 0;
    (*(int*)(context + State2Field)) = 0;
    (*(int*)(context + State3Field)) = 0;
    MessageCharacter* cursor = *(MessageCharacter**)(context + CursorField);
    MessageCharacter* output = *(MessageCharacter**)(context + DestinationField);
    bool seenGlyph = false;
#if defined(jpn)
    while (cursor != 0) {
        *output = *cursor;
        ++output;
        (*(int*)(context + LengthField))++;
        if (*(unsigned int*)(context + SourceLengthField) < (unsigned int)(cursor - *(MessageCharacter**)(context + SourceField))) {
            *(int*)(context + 0x868) = 0;
            break;
        }
        if (func_02069430(context, *cursor)) {
            if (*cursor == 0xff1a || *cursor == 0xff1b) seenGlyph = 1;
            if (func_02069408(context, *cursor)) {
                if (!seenGlyph) {
                    (*(int*)(context + LengthField))--;
                    *(MessageCharacter**)(context + CursorField) = ++cursor;
                    --output;
                    continue;
                }
                *(MessageCharacter**)(context + NextField) = cursor;
                break;
            }
            unsigned short command = *cursor;
            if ((command & 0xffe0) == 0xffe0) {
                command = (unsigned short)(command ^ 0xffe0) + 0xffd0;
                cursor = func_0206c730(context, command, *(MessageCharacter**)(context + SourceField));
                if (!cursor) {
                    unsigned char saved = *(unsigned char*)(context + 0x17fd);
                    ReinitController02043204(context);
                    func_02043124((Object02043124*)(context));
                    context[0x17fd] = saved;
                    break;
                }
            }
        } else {
            seenGlyph = 1;
        }
        ++cursor;
    }
    func_0206c794(context);
#else
    for (;;) {
        if (!*cursor) break;
        int commandBytes = 0;
        if (IsHighByteFF0206ac6c(context, cursor)) {
            int words = Func0206abf8(context, cursor) + 1;
            commandBytes = words * 2;
            memcpy(output, cursor, commandBytes);
            output += words * 2;
            (*(int*)(context + LengthField)) += words * 2;
        }
        if (*(unsigned int*)(context + SourceLengthField) < (unsigned int)(cursor - *(MessageCharacter**)(context + SourceField))) {
            *(int*)(context + 0x998) = 0;
            break;
        }
        if (IsHighByteFF0206ac6c(context, cursor)) {
            if (IsCommandInRange02067a9c(context, cursor)) {
                if (seenGlyph) {
                    *(MessageCharacter**)(context + NextField) = cursor;
                    break;
                }
                unsigned char saved = *(unsigned char*)(context + 0x19cc);
                ReinitController02043204(context);
                func_02043124((Object02043124*)(context));
                context[0x19cc] = saved;
                break;
            }
            unsigned short command;
            memcpy(&command, cursor, 2);
            cursor += commandBytes;
            if ((command & 0xffe0) == 0xffe0) {
                command = (unsigned short)(command ^ 0xffe0) + 0xffd0;
                cursor = func_0206ac94(context, command, *(MessageCharacter**)(context + SourceField));
                if (!cursor) {
                    unsigned char saved = *(unsigned char*)(context + 0x19cc);
                    ReinitController02043204(context);
                    func_02043124((Object02043124*)(context));
                    context[0x19cc] = saved;
                    break;
                }
            }
        } else {
            seenGlyph = 1;
            int size = 1;
            Entry0204254c* entry = FindEntryByKey0204254c((int)(cursor), (unsigned char)(context[0x19dc]));
            if (entry) size = entry->size;
            memcpy(output, cursor, size);
            output += size;
            (*(int*)(context + LengthField))++;
            cursor += size;
        }
    }
    func_0206ad74(context);
#endif
}
