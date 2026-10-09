#include <globaldefs.h>
#include <std_library_functions.h>
struct Block0208358c { int field_0x0, field_0x4, field_0x8, field_0xc, field_0x10, field_0x14, field_0x18, field_0x1c; };
struct Record020836e4 { Block0208358c* block; char* text; unsigned int flags:4; unsigned int rest:28; char tail[20]; };
struct Object0208358c { char pad[0x194]; Record020836e4 records[11]; char pad2[0x3fc]; Block0208358c blocks[11]; };
struct StructDE1D4;
extern "C" void _Z18InitStruct020de1d4P11StructDE1D4(StructDE1D4*);
extern "C" void _Z18CopyStruct020836e4P14Record020836e4S0_(Record020836e4*, Record020836e4*);
extern "C" unsigned char* _Z30GetIndexedBlockPointer0208349cPhi(unsigned char*, int);
// USA: func_0208358c
extern "C" ARM void func_0208358c(Object0208358c* obj, Record020836e4* src, int arg) {
    if (!src) return;
    int index = -1;
    switch (src->flags) {
    case 0: index = 8; break;
    case 1: index = 9; break;
    case 4: index = 7; break;
    case 2: index = 0; break;
    case 5: index = 5; break;
    case 3: index = 1; break;
    case 6: index = 6; break;
    case 7: index = 10; break;
    case 11: index = arg; break;
    }
    if (index < 0) return;
    Record020836e4* dst = &obj->records[index];
    Block0208358c* out = dst->block;
    char* text = dst->text;
    Block0208358c* in = src->block;
    out->field_0x0 = in->field_0x0; out->field_0x4 = in->field_0x4; out->field_0x8 = in->field_0x8; out->field_0xc = in->field_0xc;
    out->field_0x10 = in->field_0x10; out->field_0x14 = in->field_0x14; out->field_0x18 = in->field_0x18; out->field_0x1c = in->field_0x1c;
    *text = 0;
    if (src->text) { memset(text, 0, 0x30); sprintf(text, src->text); }
    _Z18InitStruct020de1d4P11StructDE1D4((StructDE1D4*)dst);
    _Z18CopyStruct020836e4P14Record020836e4S0_(dst, src);
    dst->block = &obj->blocks[index];
    dst->text = (char*)_Z30GetIndexedBlockPointer0208349cPhi((unsigned char*)obj, index);
}
