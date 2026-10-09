#include <globaldefs.h>

struct Obj020196fc;
struct List0201e434;
struct Struct02019f24;
struct FloorMap02019728;

struct AdjacencyBits02019728 {
    unsigned char bits;
};

struct Mat02019728 {
    int m[9];
};

struct Cell02019728 {
    void* node;
    unsigned char info[16];
    Mat02019728 matrix;
    int rotation;
    int x;
    int y;
    int z;
};

struct Tile02019728 {
    unsigned char data[16];
};

extern "C" {
void __clear(void* buf, int size);
int sprintf(char* buf, const char* fmt, ...);
int _ZNK8FloorMap16GetAdjacencyBitsEii(const FloorMap02019728* map, int x, int y);
void Mat3x3_WriteRotationY(Mat02019728* out, int sine, int cosine);
void Mat3x3_WriteIdentity(Mat02019728* out);
}

extern const char data_020ef26f[];
extern const char data_020ef274[];
extern const char data_020ef279[];
extern const char data_020ef27e[];
extern const char data_020ef283[];
extern const char data_020ef288[];
extern const char data_020ef28d[];
extern const char data_020ef292[];
extern const char data_020ef297[];
extern const char data_020ef29c[];
extern const char data_020ef2a1[];
extern const char data_020ef2a6[];
extern const char data_020ef2ab[];
extern const char data_020ef2b0[];
extern const char data_020ef2b5[];

extern "C" void* _Z22GetNodeAtDepth020196fcP11Obj020196fci(Obj020196fc* obj, int count);
extern "C" void* _Z29FindEntryByNameSubstr0201e434P12List0201e434PKc(List0201e434* list, const char* substr);
extern "C" Struct02019f24* _Z18CopyStruct02019f24P14Struct02019f24S0_(Struct02019f24* dst, Struct02019f24* src);
void RotateTileGrid3x3(void* obj, unsigned char* buf, int mode);

static inline AdjacencyBits02019728 GetAdjacency02019728(const FloorMap02019728* map, int x, int y) {
    AdjacencyBits02019728 result;
    result.bits = _ZNK8FloorMap16GetAdjacencyBitsEii(map, x, y);
    return result;
}

// USA: func_02019728
extern "C" ARM int func_02019728(void* obj, int unused, List0201e434* listArg, Tile02019728* grid, FloorMap02019728* mapArg)
{
    char name[8];
    List0201e434* list = listArg ? listArg : (List0201e434*)((char*)obj + 0x6c);
    FloorMap02019728* map = mapArg ? mapArg : (FloorMap02019728*)((char*)obj + 0x1b4 + 0x2400);
    int n;
    int row;

    __clear(name, 8);
    n = 0;

    for (row = 0; row < 16; row++) {
        int col;
        for (col = 0; col < 16; col++) {
            AdjacencyBits02019728 adj;
            Mat02019728 matrix;
            Cell02019728* cell;
            void* entry;
            int rotation;
            int mode;

            adj = GetAdjacency02019728(map, col, row);
            cell = *(Cell02019728**)((char*)obj + 0x420) + row * 16 + col;
            Mat3x3_WriteIdentity(&matrix);

            switch (adj.bits) {
            case 0xff:
                n = 0xc;
                sprintf(name, data_020ef26f);
                break;
            case 0xbb: case 0xee:
                n = 3;
                sprintf(name, data_020ef274);
                break;
            case 0xaf: case 0xbe: case 0xeb: case 0xfa:
                n = 2;
                sprintf(name, data_020ef279);
                break;
            case 0xaa:
                n = 1;
                sprintf(name, data_020ef27e);
                break;
            case 0xab: case 0xae: case 0xba: case 0xea:
                n = 0;
                sprintf(name, data_020ef283);
                break;
            case 0xbf: case 0xef: case 0xfb: case 0xfe:
                n = 0xd;
                sprintf(name, data_020ef288);
                break;
            case 0x0e: case 0x38: case 0x83: case 0xe0:
                n = 0xa;
                sprintf(name, data_020ef28d);
                break;
            case 0x3e: case 0x8f: case 0xe3: case 0xf8:
                n = 9;
                sprintf(name, data_020ef292);
                break;
            case 0x02: case 0x08: case 0x20: case 0x80:
                n = 8;
                sprintf(name, data_020ef297);
                break;
            case 0x00:
                n = 7;
                sprintf(name, data_020ef29c);
                break;
            case 0x22: case 0x88:
                n = 6;
                sprintf(name, data_020ef2a1);
                break;
            case 0x0a: case 0x28: case 0x82: case 0xa0:
                n = 0x11;
                sprintf(name, data_020ef2a6);
                break;
            case 0x3a: case 0x8e: case 0xa3: case 0xe8:
                n = 0x10;
                sprintf(name, data_020ef2ab);
                break;
            case 0x2e: case 0x8b: case 0xb8: case 0xe2:
                n = 0xf;
                sprintf(name, data_020ef2b0);
                break;
            case 0x2a: case 0x8a: case 0xa2: case 0xa8:
                n = 0xe;
                sprintf(name, data_020ef2b5);
                break;
            }

            if (grid == 0) {
                cell->node = _Z22GetNodeAtDepth020196fcP11Obj020196fci((Obj020196fc*)obj, n);
                entry = _Z29FindEntryByNameSubstr0201e434P12List0201e434PKc(list, name);
                if (entry != 0) {
                    _Z18CopyStruct02019f24P14Struct02019f24S0_((Struct02019f24*)cell->info, (Struct02019f24*)entry);
                }
            } else {
                entry = _Z29FindEntryByNameSubstr0201e434P12List0201e434PKc(list, name);
                if (entry != 0 && grid != 0) {
                    _Z18CopyStruct02019f24P14Struct02019f24S0_((Struct02019f24*)(grid + row * 16 + col), (Struct02019f24*)entry);
                }
            }

            rotation = 0;
            mode = 0;
            switch (adj.bits) {
            case 0x02: case 0x82: case 0x83: case 0x88: case 0x8a: case 0x8e:
            case 0x8f: case 0xab: case 0xaf: case 0xe2: case 0xee: case 0xef:
                rotation = 0x3243 >> 1;
                Mat3x3_WriteRotationY(&matrix, 0x1000, 0);
                mode = 1;
                break;
            case 0x08: case 0x0a: case 0x0e: case 0x2a: case 0x3a: case 0x3e:
            case 0x8b: case 0xae: case 0xbe: case 0xbf:
                rotation = 0x3243;
                Mat3x3_WriteRotationY(&matrix, 0, -0x1000);
                mode = 2;
                break;
            case 0x20: case 0x28: case 0x2e: case 0x38: case 0xa8: case 0xba:
            case 0xe8: case 0xf8: case 0xfa: case 0xfe:
                rotation = 0x4b65;
                Mat3x3_WriteRotationY(&matrix, -0x1000, 0);
                mode = 3;
                break;
            case 0xff:
                break;
            default:
                rotation = 0;
                break;
            }

            if (grid == 0) {
                cell->rotation = rotation;
                RotateTileGrid3x3(obj, cell->info + 2, mode);
                cell->x = (int)(4096.0f * (8.0f * (float)col));
                cell->y = 0;
                cell->z = (int)(4096.0f * (8.0f * (float)row));
                cell->matrix = matrix;
            } else {
                RotateTileGrid3x3(obj, (grid + row * 16 + col)->data + 2, mode);
            }
        }
    }
    return 1;
}
