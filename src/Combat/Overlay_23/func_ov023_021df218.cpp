#include <globaldefs.h>

// USA: func_ov023_021df218

struct StructAcAe021db45c;

extern "C" void func_0204c684(void* buf);
extern "C" int _Z33InitBufferFromDataField4_021ddc34Pvssss(void* obj, short a, short b, short c, short d);
extern "C" void* memcpy(void* dst, const void* src, unsigned int length);
extern "C" void* func_0205ec34();
int TestBitInByteArray(int flags, unsigned char* flags2, int id);
extern "C" int _Z28MatchesAnyTableEntry020dd19cji(unsigned int a, int b);
extern "C" void _Z21SetByteField_021e29b8Pvih(void* a, int b, unsigned char v);
extern "C" void* func_ov023_021e2550(void* obj, int unused, int index);
extern "C" void _Z28UpdateEntryAndReset_021db45cPvP18StructAcAe021db45ciPsS2_(void* obj, struct StructAcAe021db45c* p1, int p2, short* p3, short* p4);
extern "C" void func_ov023_021e257c(void* obj);
extern "C" void* _Z29CreateAndSetFields8A_021db544PvS_ii(void* a, void* b, int c, int d);
extern "C" void* func_ov023_021db4e4(void* obj, int key);
extern "C" int func_ov023_021ddc98(void* buf, int val, unsigned short len, int flag);
extern "C" unsigned short* func_ov023_021db2b8(signed char screen, int bg1);
extern "C" void _Z25CleanInvalidateCacheRangePKvj(void* p, unsigned size);
extern "C" void _Z25ComputeShortPair_021e2bdcPviPsS0_(void* a, int unused, short* out1, short* out2);

struct Data021df218 {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    void* f20;
};

extern "C" Data021df218 data_ov023_021ff9e0;
extern "C" const unsigned char data_ov023_021fd626[];
extern "C" const short data_ov023_021fd64c[];
extern "C" const short data_ov023_021fd634[];

struct NodeFlags021df218 {
    unsigned int f0 : 7;
    unsigned int sel : 4;
    unsigned int f1 : 21;
    unsigned int flags : 12;
    unsigned int f2 : 20;
};

struct Layout021df218 {
    int unk_0;
    void* canvas_;
    char pad8[0x12 - 8];
    short unk_12;
};

struct Entry021df218 {
    char pad[0x16];
    unsigned char flags;
};

struct Obj021df218 {
    char pad0[0x4c];
    int* node;
    char pad50[0xcc - 0x50];
    Layout021df218 list;
    char padE0[0x75c - 0xe0];
    int pos;
};

extern "C" ARM void func_ov023_021df218(Obj021df218* self)
{
    char buf[0xe0];
    unsigned char flags[14];
    short y;
    short x;
    unsigned short t;
    short p1;
    short p0;
    int len;
    int mask;
    short a0;
    unsigned short* base;

    func_0204c684(buf);
    if (!_Z33InitBufferFromDataField4_021ddc34Pvssss(buf, 0, 0, 7, 0x10))
        return;

    mask = 0;
    {
        unsigned char i;
        unsigned char j;
        int cur;
        unsigned int one = 1;
        struct NodeFlags021df218* nf = (struct NodeFlags021df218*)self->node[0];

        if (nf != NULL)
        {
            Entry021df218* e = (Entry021df218*)func_ov023_021db4e4(&self->list, 0x1b);
            if (e)
                e->flags |= 1;

            memcpy(flags, data_ov023_021fd626, 0xd);

            {
                void* f = func_0205ec34();
                for (j = 7; j < 0xd; j++)
                {
                    if (TestBitInByteArray((int)f, (unsigned char*)f + 0x8c, 0x113f + j))
                        flags[j] = 1;
                }
            }

            i = 1;
            j = 0;
            for (; i < 0xd; j++, i++)
            {
                if (flags[i] != 0)
                {
                    cur = 0xe;
                    if (nf->sel != 0)
                    {
                        if (_Z28MatchesAnyTableEntry020dd19cji(i, nf->sel & 0xff) != 0)
                            cur = 0xf;
                    }
                    else
                    {
                        if (nf->flags & ((unsigned short)(one << j)))
                            cur = 0xf;
                    }
                    if (cur == 0xe)
                        mask |= 1 << j;
                    {
                        short v = data_ov023_021fd64c[j];
                        _Z21SetByteField_021e29b8Pvih(&self->list, v, 3);
                        func_ov023_021e2550(&self->list, v, i);
                    }
                }
            }

            _Z28UpdateEntryAndReset_021db45cPvP18StructAcAe021db45ciPsS2_(&self->list, (struct StructAcAe021db45c*)buf, 0x1b, &x, &y);
            if (data_ov023_021ff9e0.f4 != 0)
            {
                self->list.canvas_ = buf;
                self->list.unk_12 = 1;
                func_ov023_021e257c(&self->list);
            }
            _Z29CreateAndSetFields8A_021db544PvS_ii(&self->list, (void*)0x1b, x, y);
            e = (Entry021df218*)func_ov023_021db4e4(&self->list, 0x1b);
            if (e)
                e->flags &= ~1;
        }
    }

    len = func_ov023_021ddc98(buf, self->pos, (unsigned short)data_ov023_021ff9e0.f10, 0);

    if (&self->list != (Layout021df218*)0)
    {
        base = func_ov023_021db2b8(*(signed char*)((char*)data_ov023_021ff9e0.f20 + 0x77c), 0);
        if (base != NULL)
        {
            int b;
            int ii;
            int a;
            int jj;
            int k;
            for (k = 0; k < 0xc; k++)
            {
                if (mask & (1 << k))
                {
                    int off;

                    p0 = 0;
                    p1 = 0;
                    _Z25ComputeShortPair_021e2bdcPviPsS0_(&self->list, data_ov023_021fd634[k], &p0, &p1);
                    a0 = p0 >> 3;
                    b = p1 >> 3;
                    p0 = (short)a0;
                    p1 = (short)b;

                    for (ii = 0; ii < 2; ii++)
                    {
                        unsigned short* row = (unsigned short*)((char *)base + (b << 6));
                        a = a0;
                        for (jj = 0; jj < 2; jj++)
                        {
                            off = a << 1;
                            t = (short)(*(unsigned short*)((char*)row + off) & 0xfff);
                            t |= 0x1000;
                            _Z25CleanInvalidateCacheRangePKvj(&t, 2);
                            *(unsigned short*)((char*)row + off) = t;
                            a = a + 1;
                        }
                        b = b + 1;
                    }
                }
            }
        }
    }

    self->pos = self->pos + len;
}