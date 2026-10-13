#include <globaldefs.h>
#include "std_library_functions.h"

struct FontIndexFile
{
    struct Glyph
    {
        const char* tag;
        int8_t width;
        int8_t tagLength : 6;
        int8_t isVowel : 1;
        int8_t unk_5_bit_7 : 1;
        char unk_6[2];
    };
};

enum ControlWord
{
    ControlWord_LineBreak = 0xff18,
    ControlWord_Unknown_ff19 = 0xff19,
};

class TextManager
{
public:
    char unk_0[0x70];
    unsigned int unknown_70_;
};

extern "C" int func_02001aec(const void* lhs, const void* rhs, unsigned int length);
extern "C" int _Z27FindEntryIndexByKey020424e4ii(const char* tag, int fontType);

char* FindUnescapedAngleBracket(char*);
extern "C" FontIndexFile::Glyph* _Z23GetBoundedEntry020425b4ii(int glyph, int fontType);
extern "C" int _Z22LookupKeyValue020425e4iii(int leftGlyph, int rightGlyph, int fontType);
extern "C" int _Z24GetWordFromTable02042648i(int fontType);
extern "C" int _Z16Dispatch02044420PvS_(void*, void*);
extern "C" bool _Z20IsHighByteFF02044494PvS_(void*, void*);
int StringLength(const char*);
extern "C" bool _Z26StringStartsWithCI020d85dcPKcS0_(const char* str, const char* initial);

struct Struct_020e7e04
{
    char unk_0[2];
    unsigned short newlineWord;
    char unk_4[0x20];
    short array_24[2];
} extern const data_020e7e04;

extern char data_020f08dc[];
extern char data_020f0979[];
extern char data_020f097c[];
extern char data_020f0981[];
extern char data_020f0988[];
extern char data_020f098c[];
extern char data_020f0990[];
extern char data_020f0992[];

struct NewlineCalculationTagProcessor
{
    char* tag;
    int (*proc)(char* input, int* pX, int fontIndex, int margin);
};

extern const NewlineCalculationTagProcessor data_020e7ec4[];

// USA: func_0206b974
extern "C" ARM void func_0206b974(TextManager* self, bool arg2, char *input, char *output,
    int boxWidth, int margin, bool arg7, unsigned char fontType)
{
    int local_2c;
    char* local_34 = NULL;
    char* local_38 = NULL;
    int local_3c = 0;
    int extraWidthFromSpeaker = 0;

    char* noSpeakerStart = strstr(input, data_020f0979);
    char* altNoSpeakerStart = strstr(input, data_020f097c);

    if (noSpeakerStart != NULL || altNoSpeakerStart != NULL)
        extraWidthFromSpeaker = 2;

    local_2c = margin;
    unsigned char lastGlyphIndex = 0xff;
    bool leftAligned = true;
    bool iVar11 = 0;

    unsigned char defaultSpacing = _Z24GetWordFromTable02042648i(fontType);

    while (true)
    {
        char nextChar = *input;
        if (nextChar == 0)
            break;
        unsigned short control;
        memcpy(&control, input, 2);
        if (_Z20IsHighByteFF02044494PvS_(self, &control) && control != ControlWord_Unknown_ff19)
        {
            int numControlWordBytes = (_Z16Dispatch02044420PvS_(self, &control) + 1) * 2;
            memcpy(output, input, numControlWordBytes);
            input += numControlWordBytes;
            output += numControlWordBytes;
            if (control == ControlWord_LineBreak)
            {
                extraWidthFromSpeaker = 0;
                local_2c = margin;
                local_34 = input;
                local_38 = output;
                local_3c = margin;
                lastGlyphIndex = 0xff;
                iVar11 = 0;
            }
            continue;
        }

        if (nextChar == '\\' && input[1] == 'n')
        {

            extraWidthFromSpeaker = 0;
            local_2c = margin;
            lastGlyphIndex = 0xff;

            memcpy(output, input, 2);
            input += 2;
            output += 2;
            local_34 = input;
            local_38 = output;
            local_3c = local_2c;
            iVar11 = 0;
            continue;
        }

        if (nextChar == '\n')
        {
            extraWidthFromSpeaker = 0;
            local_2c = margin;
            lastGlyphIndex = 0xff;
            memcpy(output, input, 1);
            input += 1;
            output += 1;
            local_34 = input;
            local_38 = output;
            local_3c = local_2c;
            iVar11 = 0;
            continue;
        }

        if (func_02001aec(input, data_020f0981, 6) == 0)
        {
            extraWidthFromSpeaker = 0;
            local_2c = margin;
            lastGlyphIndex = 0xff;
            memcpy(output, input, 6);
            input += 6;
            output += 6;
            local_34 = input;
            local_38 = output;
            local_3c = local_2c;
            iVar11 = 0;
            continue;
        }

        if (func_02001aec(input, data_020f08dc, 2) == 0)
        {
            char* speakerEnd = strstr(input, data_020f0988);
            if (speakerEnd != NULL)
            {
                local_2c = NULL;
                int speakerLength = speakerEnd - input;
                memcpy(output, input, speakerLength + 3);
                input += speakerLength + 3;
                output += speakerLength + 3;
                continue;
            }
        }

        int nextGlyphIndex = _Z27FindEntryIndexByKey020424e4ii(input, fontType);
        if (control == ControlWord_Unknown_ff19)
            nextGlyphIndex = -1;
        if (nextChar == '<' && nextGlyphIndex < 0)
        {
            char* tagEnd = FindUnescapedAngleBracket(input);
            if (tagEnd != NULL)
            {
                char* tagInner = input + 1;
                for (const NewlineCalculationTagProcessor* candidate = data_020e7ec4;
                    candidate->tag != NULL && candidate->proc != NULL; candidate++)
                {
                    if (!_Z26StringStartsWithCI020d85dcPKcS0_(tagInner, candidate->tag))
                        continue;

                    int procRet = candidate->proc(tagInner + StringLength(candidate->tag), &local_2c, fontType, margin);
                    if (procRet != 1)
                    {
                        if (procRet == 2)
                        {
                            leftAligned = true;
                        }
                        break;
                    }
                    else
                    {
                        leftAligned = false;
                        break;
                    }
                }
                int tagInnerLength = (tagEnd - input);
                memcpy(output, input, tagInnerLength + 1);
                input += tagInnerLength + 1;
                output += tagInnerLength + 1;
                continue;
            }
        }

        bool foundDash = false;
        int glyphSpacing = defaultSpacing + 1;
        int ioCopyLength = 1;
        if (control == ControlWord_Unknown_ff19)
        {
            iVar11 = 1;
            ioCopyLength = 2;
        }
        if (nextChar == ' ')
        {
            iVar11 = 0;
        }
        if (func_02001aec(input, data_020f098c, 3) == 0)
        {
            nextGlyphIndex = -1;
            input += 3;
            glyphSpacing = 0;
            ioCopyLength = 0;
            iVar11 = 1;
        }
        if (nextGlyphIndex >= 0)
        {
            FontIndexFile::Glyph* glyph = _Z23GetBoundedEntry020425b4ii(nextGlyphIndex, fontType);
            ioCopyLength = glyph->tagLength;
            unsigned char nextGlyphUC = nextGlyphIndex;
            int kerning = _Z22LookupKeyValue020425e4iii(lastGlyphIndex, nextGlyphUC, fontType);
            lastGlyphIndex = nextGlyphUC;
            glyphSpacing = kerning + glyph->width;

            foundDash = (glyph->tag[0] == '-');
            if (foundDash)
                iVar11 = 0;

            if (local_34 != NULL && local_38 != NULL && leftAligned &&
                (boxWidth + extraWidthFromSpeaker < local_2c + glyphSpacing))
            {
                local_2c -= local_3c;
                local_2c += margin;
                extraWidthFromSpeaker = 0;
                int copyLength = input - local_34;
                int zeroLength = output - local_38;
                output = local_38;
                memset(local_38, 0, zeroLength);
                if (iVar11 != 0)
                {
                    memcpy(output, data_020f0990, 1);
                    output += 1;
                }
                if (arg7)
                {
                    memcpy(output, &data_020e7e04.newlineWord, 2);
                    output += 2;
                }
                else
                {
                    memcpy(output, data_020f0992, 1);
                    output += 1;
                }
                memcpy(output, local_34, copyLength);
                output += copyLength;
                iVar11 = 0;
                if (arg2)
                {
                    self->unknown_70_++;
                }
            }
            glyphSpacing++;
        }
        if (leftAligned)
            local_2c += glyphSpacing;

        memcpy(output, input, ioCopyLength);
        input += ioCopyLength;
        output += ioCopyLength;
        if (nextGlyphIndex < 0 || foundDash)
        {
            local_34 = input;
            local_38 = output;
            local_3c = local_2c;
        }
    }

    *output = *input;
}
