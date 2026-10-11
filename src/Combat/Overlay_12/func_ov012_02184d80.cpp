#include <globaldefs.h>
#include <std_library_functions.h>
extern unsigned char data_0211e33c[0x30000] __attribute__((aligned(4)));
#include "Filesystem/FileIO.h"

struct ForbiddenWordFile;
struct ForbiddenWordPattern;
extern "C" int func_ov012_0218558c(ForbiddenWordFile*, ForbiddenWordPattern*);

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
struct MessageSyntax {
    char container_[0x18];
    ForbiddenWordFile file_;
    void* secondFile_;
    unsigned short secondFileSize_;
    char pad2a[4];
    unsigned char closeBraceId_, caretId_, hyphenId_, dotId_, dollarId_;
    unsigned char slashId_, atId_, ampersandId_, commaId_, controlCId_, apostropheId_;
    unsigned char pad39[3];
    inline ForbiddenWordFile* GetFile() { return &file_; }
};
struct NameSpan {
    short begin_;
    short length_;
    unsigned char adjacent_;
    unsigned char active_;
};
struct MessageCheckWork {
    unsigned int fileSize_;
    char exactName_[64];
    char exactCharacter_[12];
    char character_[12];
};
extern const char* data_020f285c;
extern char data_ov012_0218b220[];
extern "C" void __clear(void*, unsigned int);
extern "C" void _Z20ToUpperCopy_021855f0PvPcS0_(void*, char*, char*);
extern "C" int _Z27FindEntryIndexByKey020424e4ii(int, int);
extern "C" CharacterInfo* _Z23GetBoundedEntry020425b4ii(int, int);
extern "C" int func_020426bc(const char*, unsigned char*, int);
extern "C" int _Z24AnyMatchInRange_02185634PvS_iii(void*, void*, int, int, int);
extern "C" int func_ov012_02185684(void*, unsigned char*, unsigned char*, int, int);

static inline ForbiddenWordPattern* GetFilePatterns(const ForbiddenWordFile* file) { return file->patterns_; }
static inline int GetFileCount(const ForbiddenWordFile* file) { return file->header_.count_; }

static inline unsigned int PatternOffset(unsigned int base, unsigned int count, unsigned int size, unsigned int alignment) {
    unsigned int stride = AlignUp(size, alignment);
    unsigned int amount = count * stride;
    return base + amount;
}

// USA: func_ov012_02184d80
extern "C" ARM int func_ov012_02184d80(MessageSyntax* self, char* name, char* out) {
    int last;
    int count;
    unsigned char dollarId;
    unsigned char slashId;
    unsigned char atId;
    unsigned char ampersandId;
    int apostropheId;
    int controlCId;
    int positions;
    NameSpan* first;
    int patternCount;
    int i;
    ForbiddenWordPattern* headerPattern;
    int headerCount;
    unsigned char work_patterns_[5][64];
    unsigned char work_tokens_[128];
    char work_normalized_[512];
    NameSpan work_spans_[30];
    MessageCheckWork work;
    unsigned short secondFileSize = 0;
    work.fileSize_ = 0;
    LoadFileIntoMemory(data_020f285c, data_0211e33c, &work.fileSize_);
    memset(&self->file_, 0, 12);
    unsigned char* buffer = data_0211e33c;
    if (buffer) {
        memcpy(&self->file_, data_0211e33c, 4);
        unsigned int firstOffset = AlignUp(sizeof(ForbiddenWordHeader), 4);
        unsigned char* base = data_0211e33c;
        self->file_.patterns_ = (ForbiddenWordPattern*)(base + firstOffset);
        unsigned int bytes = PatternOffset(0, self->file_.header_.count_, sizeof(ForbiddenWordPattern), 4);
        self->file_.texts_ = (char*)(base + (firstOffset + bytes));
        unsigned int relocated = self->file_.header_.relocated_;
        if (!relocated) {
            const ForbiddenWordFile* file_v = &self->file_;
            headerPattern = GetFilePatterns(file_v);
            if (headerPattern) {
                headerCount = GetFileCount(file_v);
                int (*callback)(ForbiddenWordFile*, ForbiddenWordPattern*);
                if (headerCount && (callback = func_ov012_0218558c) != 0) {
                    for (i = 0; i < headerCount; ++i, ++headerPattern) func_ov012_0218558c(self->GetFile(), headerPattern);
                }
            }
            self->file_.header_.relocated_ = 1;
            ((ForbiddenWordHeader*)data_0211e33c)->relocated_ = 1;
        }
    }
    self->secondFile_ = 0;
    self->secondFileSize_ = 0;
    if (secondFileSize) {
        self->secondFile_ = data_0211e33c + secondFileSize;
        self->secondFileSize_ = secondFileSize;
    }
    __clear(work_spans_, 180);
    __clear(work_normalized_, 512);
    __clear(work_tokens_, 128);
    {
    dollarId = self->dollarId_;
    slashId = self->slashId_;
    atId = self->atId_;
    ampersandId = self->ampersandId_;
    apostropheId = self->apostropheId_;
    controlCId = self->controlCId_;
    out = work_normalized_;
    for (;;) {
        if (!*name) break;
        CharacterInfo* entry;
        int index = _Z27FindEntryIndexByKey020424e4ii((int)name, 1);
        entry = _Z23GetBoundedEntry020425b4ii(index, 1);
        if (!entry) goto fallback_character;
        if (((index >= 8 && index <= 69) || index == 77 || index == 83 ||
                      (index >= 120 && index <= 169) || index == dollarId || index == atId ||
                      index == ampersandId || index == 107 || index == apostropheId)) {
            int advance = entry->length_;
            if (index == 107) entry = _Z23GetBoundedEntry020425b4ii(slashId, 1);
            __clear(work.character_, 12);
            int length = entry->length_;
            char* text = entry->text_;
            if (entry->uppercase_) {
                _Z20ToUpperCopy_021855f0PvPcS0_(self, text, work.character_);
                text = work.character_;
            }
            if (index >= 120 && index <= 169) {
                int c = text[1];
                if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
                    if (c != 's') goto copy_character;
                }
                c = text[2];
                if (c >= 'a' && c <= 'z') c = (char)(c - 32);
                memset(work.character_, 0, 12);
                work.character_[0] = c;
                text = work.character_;
                length = 1;
            }
        copy_character:
            memcpy(out, text, length);
            name += advance;
            out += length;
        } else if (index == controlCId) {
            int length = entry->length_;
            memcpy(out, data_ov012_0218b220, 1);
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
    int gapPosition;
    int spanIndex;
    int wordIndex;
    int tokenIndex;
    unsigned char* p;
    int gapEnd;
    int gapIndex;
    int signedCommaId;
    NameSpan* gapSpan;
    int gapCommaId;
    int commaId;
    int position;
    unsigned char* token;
    NameSpan* span;
    int matchIndex;
    NameSpan* matchSpan;
    ForbiddenWordPattern* pattern;
    short patternIndex;
    int spanCount;
    unsigned int c;
    func_020426bc(work_normalized_, work_tokens_, 1);
    matchIndex = 0;
    span = work_spans_;
    commaId = self->commaId_;
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
    gapSpan = work_spans_;
    gapCommaId = self->commaId_;
    for (gapIndex = 0; gapIndex < spanCount - 1; ++gapIndex, ++gapSpan) {
        gapPosition = gapSpan->begin_ + gapSpan->length_;
        gapEnd = gapSpan[1].begin_;
        gapSpan->adjacent_ = 1;
        p = work_tokens_ + gapPosition;
        while (gapPosition < gapEnd) {
            if (gapCommaId == *p) { gapSpan->adjacent_ = 0; break; }
            ++gapPosition;
            ++p;
        }
    }
    signedCommaId = (signed char)self->commaId_;
    for (tokenIndex = 0; tokenIndex < 128; ++tokenIndex) {
        if (signedCommaId == (signed char)work_tokens_[tokenIndex]) ((char*)work_tokens_)[tokenIndex] = -1;
    }
    patternCount = (short)self->file_.header_.count_;
    for (patternIndex = 0; patternIndex < patternCount; ++patternIndex) {
        pattern = self->file_.patterns_ + patternIndex;
        first = work_spans_;
        __clear(work_patterns_, 320);
        for (wordIndex = 0; wordIndex < pattern->count_; ++wordIndex) {
            func_020426bc(pattern->words_[wordIndex], work_patterns_[wordIndex], 1);
            pattern->words_[wordIndex] = (char*)work_patterns_[wordIndex];
        }
        positions = spanCount - pattern->count_ + 1;
        for (spanIndex = 0; spanIndex < positions; ++spanIndex, ++first) {
            int matched;
            {
                matchSpan = first;
                unsigned char* input = work_tokens_;
                count = pattern->count_;
                last = count - 1;
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
                        if (!_Z24AnyMatchInRange_02185634PvS_iii(self, (void*)text, (int)(input + matchSpan->begin_), length, 1)) { matched = 0; goto match_done; }
                        break;
                    case 3:
                        if (spanLength < length) { matched = 0; goto match_done; }
                        if (!_Z24AnyMatchInRange_02185634PvS_iii(self, (void*)text, (int)(input + matchSpan->begin_), length, 1)) { matched = 0; goto match_done; }
                        break;
                    case 2:
                        if (spanLength < length) { matched = 0; goto match_done; }
                        if (!_Z24AnyMatchInRange_02185634PvS_iii(self, (void*)text, (int)(input + (matchSpan->begin_ + matchSpan->length_ - length)), length, 1)) { matched = 0; goto match_done; }
                        break;
                    case 1:
                        if (spanLength < length) { matched = 0; goto match_done; }
                        if (!_Z24AnyMatchInRange_02185634PvS_iii(self, (void*)text, (int)(input + matchSpan->begin_), length, positions)) { matched = 0; goto match_done; }
                        break;
                    case 4:
                        if (length != spanLength) { matched = 0; goto match_done; }
                        if (!func_ov012_02185684(self, (unsigned char*)text, input + matchSpan->begin_, length, 1)) { matched = 0; goto match_done; }
                        break;
                    case 7:
                        if (spanLength < length) { matched = 0; goto match_done; }
                        if (!func_ov012_02185684(self, (unsigned char*)text, input + matchSpan->begin_, length, 1)) { matched = 0; goto match_done; }
                        break;
                    case 6:
                        if (spanLength < length) { matched = 0; goto match_done; }
                        if (!func_ov012_02185684(self, (unsigned char*)text, input + (matchSpan->begin_ + matchSpan->length_ - length), length, 1)) { matched = 0; goto match_done; }
                        break;
                    case 5:
                        if (spanLength < length) { matched = 0; goto match_done; }
                        if (!func_ov012_02185684(self, (unsigned char*)text, input + matchSpan->begin_, length, positions)) { matched = 0; goto match_done; }
                        break;
                    }
                }
                matched = 1;
            }
match_done:
            if (matched) {
                return 1;
            }
        }
    }
    return 0;
}
