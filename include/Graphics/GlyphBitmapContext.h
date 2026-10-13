#pragma once



struct GlyphBitmapContext {
#if defined(jpn)
    int colorSchemeIndex;
    void* buffer;
#else
    void* buffer;
    int colorSchemeIndex;
#endif
};

#if defined(jpn)
extern GlyphBitmapContext data_020fe6fc;
#define glyphBitmapContext data_020fe6fc
#else
extern GlyphBitmapContext data_020fe9a4;
#define glyphBitmapContext data_020fe9a4
#endif
