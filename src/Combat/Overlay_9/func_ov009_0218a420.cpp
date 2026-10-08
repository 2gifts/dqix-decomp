#include <globaldefs.h>

struct ForbiddenWordPattern {
    const char* words_[5];
    signed char lengths_[5];
    unsigned char types_[5];
    unsigned char count_;
    char unk_1f;
};

struct ForbiddenWordFile {
    unsigned int header_;
    ForbiddenWordPattern* patterns_;
    char* texts_;
};

// USA: func_ov009_0218a420
extern "C" ARM int func_ov009_0218a420(ForbiddenWordFile* file, ForbiddenWordPattern* pattern)
{
    for (int i = 0; i < pattern->count_; i++)
    {
        bool none = true;
        int offset = pattern->words_[i] - (const char*)0;
        if (offset != -1 && file->texts_ != 0)
            none = false;
        pattern->words_[i] = none ? 0 : file->texts_ + offset;
    }
    return 1;
}
