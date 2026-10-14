#include <globaldefs.h>
#include <std_library_functions.h>

struct TextContext {
    char pad_0[0x19dc];
    unsigned char fontTable;
};

struct Entry0204254c {
    int key;
    signed char width;
    signed char size : 6;
    signed char flags : 2;
    char pad_6[2];
};

int GetWordFromTable02042648(int);
bool IsHighByteFF02044494(void*, void*);
int Dispatch02044420(void*, void*);
int LookupKeyValue020425e4(int, int, int);
Entry0204254c* FindEntryByKey0204254c(int, int);
int FindEntryIndexByKey020424e4(int, int);
int IsHalfwordInRange02067ad8(int, void*);

// USA: func_0206b37c
extern "C" ARM int func_0206b37c(TextContext* context, char* text) {
    if (!text) return 0;
    unsigned char defaultWidth = GetWordFromTable02042648(context->fontTable);
    int current = 0xff;
    unsigned char previous = current;
    int payloadWords;
    int step;
    int width = 0;
    unsigned short command;
    short argument;
    while (!IsHalfwordInRange02067ad8((int)context, text)) {
        memcpy(&command, text, 2);
        if (IsHighByteFF02044494(context, &command)) {
            payloadWords = Dispatch02044420(context, &command);
            switch (command) {
            case 0xff19:
                previous = 0xff;
                width += LookupKeyValue020425e4(previous, current, context->fontTable);
                break;
            case 0xff20:
                previous = 0xff;
                memcpy(&argument, text + 2, 2);
                if (width < argument) width = argument;
                break;
            case 0xff23:
                previous = 0xff;
                memcpy(&argument, text + 2, 2);
                width += argument;
                break;
            }
            text = text + 2 + payloadWords * 2;
        } else {
            step = 1;
            int glyphWidth = defaultWidth;
            Entry0204254c* entry = FindEntryByKey0204254c((int)text, context->fontTable);
            if (entry) {
                current = (unsigned char)FindEntryIndexByKey020424e4((int)text, context->fontTable);
                width += LookupKeyValue020425e4(previous, current, context->fontTable);
                previous = current;
                current = 0xff;
                step = entry->size;
                glyphWidth = entry->width;
            }
            width += glyphWidth + 1;
            text += step;
        }
    }
    return width;
}
