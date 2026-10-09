#include <globaldefs.h>

struct B6_021e1c20 {
    unsigned char b[6];
};

struct Ent021e1c20 {
    unsigned char id;
    unsigned char val;
    char pad[2];
    int moved;
    unsigned char* obj;
};

extern "C" void func_ov000_0216f82c(B6_021e1c20* out, const int* cell);
int GetSubstructByte0x1c(unsigned char*);
int GetSubstructByte0x1e(unsigned char*);
void SetSubstructByte0x1e(unsigned char*, unsigned char);

// USA: func_ov025_021e1c20
extern "C" ARM void func_ov025_021e1c20(int cell, unsigned char* map, unsigned char* dist, int level, Ent021e1c20* ents, int n, unsigned char* self) {
    unsigned char cands[8];
    int cur = cell;
    B6_021e1c20 tmp;
    B6_021e1c20 nb;
    int i;
    int k;
    int j;
    int pos;
    unsigned char b;
    int cnt;
    unsigned int c;
    cnt = 0;
    func_ov000_0216f82c(&tmp, &cur);
    nb = tmp;
    for (i = 0; i < 6; i++) {
        b = nb.b[i];
        if (b != 0xff && dist[b] == level - 1) {
            cands[cnt] = b;
            cnt++;
        }
    }
    for (k = 0; k < cnt; k++) {
        c = cands[k];
        if (c < 0x51) {
            map[c] = 0xff;
        }
        for (j = 0; j < n; j++) {
            if (*self != ents[j].id) {
                pos = GetSubstructByte0x1e(ents[j].obj);
                if (pos >= 0x51) {
                    pos = GetSubstructByte0x1c(ents[j].obj);
                }
                if (pos == c) {
                    ents[j].moved = 1;
                    SetSubstructByte0x1e(ents[j].obj, 0xff);
                }
            }
        }
    }
}
