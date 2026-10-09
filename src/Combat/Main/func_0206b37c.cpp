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

extern "C" int _Z24GetWordFromTable02042648i(int);
extern "C" bool _Z20IsHighByteFF02044494PvS_(void*, void*);
extern "C" int _Z16Dispatch02044420PvS_(void*, void*);
extern "C" int _Z22LookupKeyValue020425e4iii(int, int, int);
extern "C" Entry0204254c* _Z22FindEntryByKey0204254cii(int, int);
extern "C" int _Z27FindEntryIndexByKey020424e4ii(int, int);
extern "C" int _Z25IsHalfwordInRange02067ad8iPv(int, void*);

// USA: func_0206b37c
extern "C" ARM int func_0206b37c(TextContext* context, char* text) {
    if (!text) return 0;
    unsigned char defaultWidth = _Z24GetWordFromTable02042648i(context->fontTable);
    int current = 0xff;
    unsigned char previous = current;
    int payloadWords;
    int step;
    int width = 0;
    unsigned short command;
    short argument;
    while (!_Z25IsHalfwordInRange02067ad8iPv((int)context, text)) {
        memcpy(&command, text, 2);
        if (_Z20IsHighByteFF02044494PvS_(context, &command)) {
            payloadWords = _Z16Dispatch02044420PvS_(context, &command);
            switch (command) {
            case 0xff19:
                previous = 0xff;
                width += _Z22LookupKeyValue020425e4iii(previous, current, context->fontTable);
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
            Entry0204254c* entry = _Z22FindEntryByKey0204254cii((int)text, context->fontTable);
            if (entry) {
                current = (unsigned char)_Z27FindEntryIndexByKey020424e4ii((int)text, context->fontTable);
                width += _Z22LookupKeyValue020425e4iii(previous, current, context->fontTable);
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
