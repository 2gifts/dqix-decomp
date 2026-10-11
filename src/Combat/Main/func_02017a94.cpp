#include <globaldefs.h>
#include <World/Zone3D.h>
#include <GameState/GameState.h>

extern "C" void* func_0205ec34(void);
void* GetField0x3f8Address(GameState* battleStruct);
int GetBitmapPixel(unsigned char* base, int row, int col);
void* GetPointerFromArray0x3c(unsigned char* obj, unsigned int index);
extern "C" int _Z35LookupAndForEachNodeIfMatch02064b24PvitS_(void* a, int mode, unsigned short id, void* c);

struct Obj0201b600;
struct Elem0201b600;
struct FeatureElem02017a94;
extern "C" struct FeatureElem02017a94* _Z14FindElemByKeysP11Obj0201b600is(
    struct Obj0201b600* obj, int key1, unsigned short key2);

struct FeatureElem02017a94 {
    unsigned short key;
    unsigned short flags;
    unsigned char pad[0x2b];
};

struct FeatureNode02017a94 {
    unsigned char pad00[0x2d];
    unsigned char id2d;
    unsigned short field2e;
    unsigned char pad30[0x70 - 0x30];
    struct FeatureNode02017a94* next;
};

struct AppendContext02017a94 {
    unsigned char pad00[0x0c];
    unsigned int zoneId;
    unsigned char pad10[0x30 - 0x10];
    unsigned int field30;
};

// USA: func_02017a94
extern "C" ARM void func_02017a94(Zone3D* zone) {
    GameState* gs = GameState::GetInstance();
    if (gs == NULL) {
        return;
    }
    if (GetField0x3f8Address(gs) == NULL) {
        return;
    }
    unsigned char* bmp = (unsigned char*)func_0205ec34();
    int row;
    int colLow;
    int colHigh;
    if (bmp != NULL && *(unsigned char*)((char*)zone + 0x281d) != 0) {
        for (row = 0; row < 2; row++) {
            for (colLow = 0; colLow < 0x7f; colLow++) {
                if (GetBitmapPixel(bmp, (unsigned char)row, (short)colLow)) {
                    struct FeatureElem02017a94* e =
                        _Z14FindElemByKeysP11Obj0201b600is((struct Obj0201b600*)zone, row, colLow);
                    if (e != NULL) {
                        e->flags &= ~4;
                    }
                }
            }
            for (colHigh = 0x80; colHigh < 0xff; colHigh++) {
                if (GetBitmapPixel(bmp, (unsigned char)row, (short)colHigh)) {
                    struct FeatureElem02017a94* e =
                        _Z14FindElemByKeysP11Obj0201b600is((struct Obj0201b600*)zone, row, colHigh - 0x80);
                    struct FeatureNode02017a94* n;
                    if (e != NULL) {
                        e->flags |= 4;
                        if ((e->flags & 8) != 0) {
                            unsigned int cur;
                            unsigned short mask;
                            e->flags |= 1;
                            n = (struct FeatureNode02017a94*)
                                GetPointerFromArray0x3c((unsigned char*)zone->substruct_6c_, 2);
                            while (n != NULL) {
                                if (n->id2d == e->key) {
                                    cur = n->field2e;
                                    mask = (unsigned short)(((cur << 16) >> 20) | 1);
                                    n->field2e = (cur & 0xffff000f) | ((unsigned int)(mask << 20) >> 16);
                                    break;
                                }
                                n = n->next;
                            }
                        }
                    }
                }
            }
        }
        struct AppendContext02017a94 ctx;
        ctx.zoneId = zone->currentZoneID_;
        _Z35LookupAndForEachNodeIfMatch02064b24PvitS_(bmp, 3, 0x6c, &ctx);
        _Z35LookupAndForEachNodeIfMatch02064b24PvitS_(bmp, 0x14, 0x6c, &ctx);
        zone->unk_276c[0x281d - 0x276c] = 0;
    }
}
