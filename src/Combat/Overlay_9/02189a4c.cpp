#include <globaldefs.h>
#include <std_library_functions.h>
extern unsigned char data_0211e33c[0x30000] __attribute__((aligned(4)));
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"

struct ForbiddenWordFile;
struct ForbiddenWordPattern;
extern "C" int func_ov009_0218a420(ForbiddenWordFile*, ForbiddenWordPattern*);

struct ForbiddenWordPattern {
    char* words_[5];
    signed char lengths_[5];
    unsigned char types_[5];
    unsigned char count_;
    char unk_1f;
};
struct ForbiddenWordHeader {
    unsigned int count_ : 12;
    unsigned int unused_ : 19;
    unsigned int relocated_ : 1;
};
static inline unsigned int AlignUp(unsigned int value, unsigned int alignment) {
    unsigned int mask = alignment - 1;
    return (value + mask) & ~mask;
}
struct ForbiddenWordFile {
    ForbiddenWordHeader header_;
    ForbiddenWordPattern* patterns_;
    char* texts_;
};
struct CharacterInfo {
    char* text_;
    signed char unk_4;
    signed char length_ : 6;
    signed char unused_ : 1;
    signed char uppercase_ : 1;
    char pad6[2];
};
struct Header020e0424 { unsigned int count_ : 12; unsigned int rest_ : 20; };
struct DictionaryPair { int key_; char* text_; };
struct Container020e0310 : Header020e0424 { DictionaryPair* entries_; char* texts_; };
struct Struct020dfc40 : Container020e0310 { short currentIndex_; short mode_; int currentText_; void* allocator_; };
struct NameSyntax {
    Struct020dfc40 container_;
    ForbiddenWordFile file_;
    void* secondFile_;
    unsigned short secondFileSize_;
    char pad2a[4];
    unsigned char closeBraceId_, caretId_, hyphenId_, dotId_, dollarId_;
    unsigned char slashId_, atId_, ampersandId_, commaId_, controlCId_, apostropheId_;
    unsigned char pad35[3];
    inline ForbiddenWordFile* GetFile() { return &file_; }
};
struct CharacterCreation {
    char pad0[0xfc];
    NameSyntax syntax_;
    char pad138[0xd9c - 0x138];
    unsigned int flags_;
    char pada0[3];
    unsigned char sex_;
    char pada4[0xc];
    char** names_;
    char padb4[4];
};
struct NameSpan {
    short begin_;
    short length_;
    unsigned char adjacent_;
    unsigned char active_;
};
extern const char* data_020f285c;
extern const char* data_020f2858;
extern char data_ov009_0218aca0[];
extern "C" void func_ov009_021847ec(NameSyntax*);
extern "C" void _Z19ResetStruct020dfc40P14Struct020dfc40(Struct020dfc40*);
extern "C" int _Z24ApplyNodeUpdater020e038cPvS_i(void*, void*, int);
extern "C" int func_ov009_0218a420(ForbiddenWordFile*, ForbiddenWordPattern*);
extern "C" void __clear(void*, unsigned int);
extern "C" CharacterInfo* _Z22FindEntryByKey0204254cii(int, int);
extern "C" void _Z19ToUpperCopy0218a484iPcS_(int, char*, char*);
extern "C" unsigned int _Z20GetLow12Bits020e0424P14Header020e0424(Header020e0424*);
extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(Container020e0310*, int);
extern "C" int _Z27FindEntryIndexByKey020424e4ii(int, int);
extern "C" CharacterInfo* _Z23GetBoundedEntry020425b4ii(int, int);
extern "C" int func_020426bc(const char*, unsigned char*, int);
extern "C" int _Z17FindMatch0218a4c8iiiii(int, int, int, int, int);
extern "C" int func_ov009_0218a518(NameSyntax*, const unsigned char*, const unsigned char*, int, int);

static inline ForbiddenWordPattern* GetFilePatterns(const ForbiddenWordFile* file) { return file->patterns_; }
static inline int GetFileCount(const ForbiddenWordFile* file) { return file->header_.count_; }

static inline unsigned int PatternOffset(unsigned int base, unsigned int count, unsigned int size, unsigned int alignment) {
    unsigned int stride = AlignUp(size, alignment);
    unsigned int amount = count * stride;
    return base + amount;
}


// USA: func_ov009_02189a4c
extern "C" ARM void func_ov009_02189a4c(CharacterCreation* self) {
    int i;
    ForbiddenWordPattern* headerPattern;
    int headerCount;
    NameSpan work_spans_[30];
    char work_normalized_[512];
    unsigned char work_tokens_[128];
    unsigned char work_patterns_[5][64];
    char work_exactName_[64];
    char work_exactCharacter_[12];
    char work_character_[12];
    unsigned int work_fileSize_[2];
    char* name = self->names_[self->sex_];
    if (!*name) return;
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
        func_ov009_021847ec((&self->syntax_));
    work_fileSize_[0] = 0;
    work_fileSize_[1] = 0;
    LoadFileIntoMemory(data_020f285c, data_0211e33c, &work_fileSize_[0]);
    unsigned int aligned = (work_fileSize_[0] + 511) & ~511;
    LoadFileIntoMemory(data_020f2858, data_0211e33c + aligned, &work_fileSize_[1]);
    _Z19ResetStruct020dfc40P14Struct020dfc40(&self->syntax_.container_);
    _Z24ApplyNodeUpdater020e038cPvS_i((&self->syntax_), data_0211e33c + aligned, work_fileSize_[1]);
    memset((&self->syntax_.file_), 0, 12);
    unsigned char* buffer = data_0211e33c;
    if (buffer) {
        memcpy((&self->syntax_.file_), data_0211e33c, 4);
        unsigned int firstOffset = AlignUp(sizeof(ForbiddenWordHeader), 4);
        unsigned char* base = data_0211e33c;
        self->syntax_.file_.patterns_ = (ForbiddenWordPattern*)(base + firstOffset);
        unsigned int bytes = PatternOffset(0, self->syntax_.file_.header_.count_, sizeof(ForbiddenWordPattern), 4);
        self->syntax_.file_.texts_ = (char*)(base + (firstOffset + bytes));
        unsigned int relocated = (&self->syntax_.file_)->header_.relocated_;
        if (!relocated) {
            const ForbiddenWordFile* file_v = &self->syntax_.file_;
            headerPattern = GetFilePatterns(file_v);
            if (headerPattern) {
                headerCount = GetFileCount(file_v);
                int (*callback)(ForbiddenWordFile*, ForbiddenWordPattern*);
                if (headerCount && (callback = func_ov009_0218a420) != 0) {
                    for (i = 0; i < headerCount; ++i, ++headerPattern) func_ov009_0218a420(self->syntax_.GetFile(), headerPattern);
                }
            }
            (&self->syntax_.file_)->header_.relocated_ = 1;
            ((ForbiddenWordHeader*)data_0211e33c)->relocated_ = 1;
        }
    }
    (&self->syntax_)->secondFile_ = 0;
    (&self->syntax_)->secondFileSize_ = 0;
    if (work_fileSize_[1]) {
        (&self->syntax_)->secondFile_ = data_0211e33c + aligned;
        (&self->syntax_)->secondFileSize_ = work_fileSize_[1];
    }
    int forbidden;
    int exact;
    {
__clear(work_exactName_, 64);
    char* out = work_exactName_;
    char* in = name;
    for (;;) {
        if (!*in) break;
        CharacterInfo* entry = _Z22FindEntryByKey0204254cii((int)in, 1);
        __clear(work_exactCharacter_, 12);
        int length = entry->length_;
        char* text = entry->text_;
        if (entry->uppercase_) {
            _Z19ToUpperCopy0218a484iPcS_((int)(&self->syntax_), text, work_exactCharacter_);
            text = work_exactCharacter_;
        }
        memcpy(out, text, length);
        in += length;
        out += length;
    }
    int length = strlen(work_exactName_);
    int exactIndex;
    int count = _Z20GetLow12Bits020e0424P14Header020e0424(&self->syntax_.container_);
    for (exactIndex = 0; exactIndex < count; ++exactIndex) {
        char* forbidden = (char*)_Z21GetFieldByKey020e0434P17Container020e0310i(&self->syntax_.container_, (short)exactIndex);
        if (forbidden && *forbidden) {
            int forbiddenLength = strlen(forbidden);
            if (forbiddenLength == length && strcmp(forbidden, work_exactName_) == 0) { exact = 1; goto exact_done; }
        }
    }
    exact = 0;

    }
exact_done:
    if (exact) {
        forbidden = 1;
        goto finished;
    }
    int patternCount;
    NameSpan* first;
    int positions;
    __clear(work_spans_, 180);
    __clear(work_normalized_, 512);
    __clear(work_tokens_, 128);
    {
    int controlCId;
    int apostropheId;
    unsigned char ampersandId;
    unsigned char atId;
    unsigned char slashId;
    unsigned char dollarId;
    dollarId = self->syntax_.dollarId_;
    slashId = self->syntax_.slashId_;
    atId = self->syntax_.atId_;
    ampersandId = self->syntax_.ampersandId_;
    apostropheId = self->syntax_.apostropheId_;
    controlCId = self->syntax_.controlCId_;
    char* out = work_normalized_;
    for (;;) {
        if (!*name) break;
        int index = _Z27FindEntryIndexByKey020424e4ii((int)name, 1);
        CharacterInfo* entry = _Z23GetBoundedEntry020425b4ii(index, 1);
        if (!entry) goto fallback_character;
        if (((index >= 8 && index <= 69) || index == 77 || index == 83 ||
                      (index >= 120 && index <= 169) || index == dollarId || index == atId ||
                      index == ampersandId || index == 107 || index == apostropheId)) {
            int advance = entry->length_;
            if (index == 107) entry = _Z23GetBoundedEntry020425b4ii(slashId, 1);
            __clear(work_character_, 12);
            int length = entry->length_;
            char* text = entry->text_;
            if (entry->uppercase_) {
                _Z19ToUpperCopy0218a484iPcS_((int)(&self->syntax_), text, work_character_);
                text = work_character_;
            }
            if (index >= 120 && index <= 169) {
                int c = text[1];
                if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
                    if (c != 's') goto copy_character;
                }
                c = text[2];
                if (c >= 'a' && c <= 'z') c = (char)(c - 32);
                memset(work_character_, 0, 12);
                work_character_[0] = c;
                text = work_character_;
                length = 1;
            }
        copy_character:
            memcpy(out, text, length);
            name += advance;
            out += length;
        } else if (index == controlCId) {
            int length = entry->length_;
            memcpy(out, data_ov009_0218aca0, 1);
            name += length;
            out++;
        } else {
        fallback_character:
            int length = 1;
            if (entry) {
                length = entry->length_;
                *out = ',';
            } else *out = ' ';
            name += length;
            ++out;
        }
    }
    }
    short patternIndex;
    ForbiddenWordPattern* pattern;
    int spanCount;
    NameSpan* matchSpan;
    int matchIndex;
    func_020426bc(work_normalized_, work_tokens_, 1);
    matchIndex = 0;
    unsigned int c;
    NameSpan* span;
    unsigned char* token;
    int position;
    int commaId;
    span = work_spans_;
    commaId = (&self->syntax_)->commaId_;
    token = work_tokens_;
    position = matchIndex;
    spanCount = matchIndex;
    for (;;) {
        c = *token;
        if (span->active_) {
            if (c == 0 || c == 255 || c == commaId) {
                spanCount++;
                span->length_ = position - span->begin_;
                span->adjacent_ = c == 255 ? 1 : 0;
                span->active_ = 0;
                span++;
            }
        } else {
            if (c != 0 && c < 255 && c != commaId) {
                span->begin_ = position;
                span->active_ = 1;
            }
            if (c == commaId && spanCount != 0) (work_spans_ + (spanCount - 1))->adjacent_ = 0;
        }
        if (span->active_ && matchIndex == 18) {
            spanCount++;
            span->length_ = position - span->begin_ + 1;
            span->adjacent_ = 1;
            span++;
        }
        if (!c) break;
        matchIndex++;
        token++;
        position++;
        if (matchIndex == 19) matchIndex = 0;
    }
    int gapCommaId;
    NameSpan* gapSpan = work_spans_;
    gapCommaId = (&self->syntax_)->commaId_;
    for (int i = 0; i < spanCount - 1; ++i, ++gapSpan) {
        unsigned char* p;
        int position = gapSpan->begin_ + gapSpan->length_;
        matchIndex = gapSpan[1].begin_;
        gapSpan->adjacent_ = 1;
        p = work_tokens_ + position;
        while (position < matchIndex) {
            if (gapCommaId == *p) { gapSpan->adjacent_ = 0; break; }
            ++position;
            ++p;
        }
    }
    int signedCommaId = (signed char)(&self->syntax_)->commaId_;
    for (int i = 0; i < 128; ++i) {
        if (signedCommaId == (signed char)work_tokens_[i]) ((char*)work_tokens_)[i] = -1;
    }
    patternCount = (short)self->syntax_.file_.header_.count_;
    for (patternIndex = 0; patternIndex < patternCount; ++patternIndex) {
        pattern = (&self->syntax_.file_)->patterns_ + patternIndex;
        first = work_spans_;
        __clear(work_patterns_, 320);
        for (int j = 0; j < pattern->count_; ++j) {
            func_020426bc(pattern->words_[j], work_patterns_[j], 1);
            pattern->words_[j] = (char*)work_patterns_[j];
        }
        positions = spanCount - pattern->count_ + 1;
        for (int j = 0; j < positions; ++j, ++first) {
            int matched;
            {
                matchSpan = first;
                unsigned char* input = work_tokens_;
int count = pattern->count_;
    int last = count - 1;
    for (matchIndex = 0; matchIndex < count; ++matchIndex, ++matchSpan) {
        if (matchIndex < last && !matchSpan->adjacent_) { matched = 0; goto match_done; }
        int type;
        int length = pattern->lengths_[matchIndex];
        int spanLength = matchSpan->length_;
        int positions = spanLength - length + 1;
        type = pattern->types_[matchIndex];
        int text = (int)pattern->words_[matchIndex];
        switch (type) {
        case 0:
            if (length != spanLength) { matched = 0; goto match_done; }
            if (!_Z17FindMatch0218a4c8iiiii((int)(&self->syntax_), text, (int)(input + matchSpan->begin_), length, 1)) { matched = 0; goto match_done; }
            break;
        case 3:
            if (spanLength < length) { matched = 0; goto match_done; }
            if (!_Z17FindMatch0218a4c8iiiii((int)(&self->syntax_), text, (int)(input + matchSpan->begin_), length, 1)) { matched = 0; goto match_done; }
            break;
        case 2:
            if (spanLength < length) { matched = 0; goto match_done; }
            if (!_Z17FindMatch0218a4c8iiiii((int)(&self->syntax_), text, (int)(input + (matchSpan->begin_ + matchSpan->length_ - length)), length, 1)) { matched = 0; goto match_done; }
            break;
        case 1:
            if (spanLength < length) { matched = 0; goto match_done; }
            if (!_Z17FindMatch0218a4c8iiiii((int)(&self->syntax_), text, (int)(input + matchSpan->begin_), length, positions)) { matched = 0; goto match_done; }
            break;
        case 4:
            if (length != spanLength) { matched = 0; goto match_done; }
            if (!func_ov009_0218a518((&self->syntax_), (unsigned char*)text, input + matchSpan->begin_, length, 1)) { matched = 0; goto match_done; }
            break;
        case 7:
            if (spanLength < length) { matched = 0; goto match_done; }
            if (!func_ov009_0218a518((&self->syntax_), (unsigned char*)text, input + matchSpan->begin_, length, 1)) { matched = 0; goto match_done; }
            break;
        case 6:
            if (spanLength < length) { matched = 0; goto match_done; }
            if (!func_ov009_0218a518((&self->syntax_), (unsigned char*)text, input + (matchSpan->begin_ + matchSpan->length_ - length), length, 1)) { matched = 0; goto match_done; }
            break;
        case 5:
            if (spanLength < length) { matched = 0; goto match_done; }
            if (!func_ov009_0218a518((&self->syntax_), (unsigned char*)text, input + matchSpan->begin_, length, positions)) { matched = 0; goto match_done; }
            break;
        }
    }
    matched = 1;

            }
match_done:
            if (matched) {
                forbidden = 1;
                goto finished;
            }
        }
    }
    forbidden = 0;
finished:
    BackgroundLoader::RemoveLockGlobal();
    if (forbidden) self->flags_ |= 0x400000;
    else self->flags_ |= 0x800;
}
