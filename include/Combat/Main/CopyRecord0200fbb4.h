#pragma once

// Layout is defined locally by func_0200fbb4; field meanings remain unknown.
struct CopyRecord0200fbb4;

extern "C" CopyRecord0200fbb4* func_0200fbb4(
    CopyRecord0200fbb4* dst, const CopyRecord0200fbb4* src);

// Preserve the committed symbol spellings despite their historical one-input names.
// Both wrappers copy src into the record at obj + 0x3f8 and return that destination.
extern "C" void* _Z37CallFunc0200fbb4AtField0x3f8_0200fba4Pv(
    void* obj, const void* src);
extern "C" void* _Z28CallFunc0200fbb4AtField0x3f8Pv(
    void* obj, const void* src);
