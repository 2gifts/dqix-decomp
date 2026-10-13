#include <globaldefs.h>
#include "Resource/GameResources.h"
#include "Resource/Brightness.h"
#include "Grotto/Main/TreasureMapDataStructs.h"
#include "System/Memory.h"
#include "std_library_functions.h"

struct MapList3C40 {
    TreasureMapMetadata maps[99];
    char field_ad4[0x18f4 - 0xad4];
    unsigned char count;
    char field_18f5[5];
    unsigned char sortMode;
    char field_18fb[3];
    unsigned char field_18fe;
};
struct Dialog3C40 { char field_0[0x998]; int active; };
struct Node3C40 { char field_0[0x38]; unsigned short selected; };
struct Obj0205eaa0;
extern MapList3C40* data_ov004_02171010;
extern Obj0205eaa0 data_02108760;
extern unsigned short data_ov004_0216fef8[3];
extern "C" int _Z26GetGlobalField0x1c020421a0v();
extern "C" int _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(Obj0205eaa0*, int, int);
extern "C" void func_ov004_02163478(MapList3C40*);
extern "C" void* func_ov011_021849c8(void*);
extern "C" Node3C40* func_ov023_021f6880(void*, int);
extern "C" short func_ov023_021f6f10(void*);
extern "C" void _Z29DispatchNodeIfState6_021f6680Pvi(void*, int);
extern "C" void _Z26ClearNodeMaskById_021f6600Pvii(void*, int, int);
extern "C" void func_ov004_02164084(void*);

// USA: func_ov004_02163c40
extern "C" ARM int func_ov004_02163c40(void* self) {
    TreasureMapMetadata maps[99];
    unsigned short indices[99];
    unsigned short scores[99];
    DetailedTreasureMapData detail;
    unsigned short modes[3];
    int forward;
    int backward;
    int changed;
    int last;
    int first;
    unsigned short selected;
    int brightness = IsBrightnessTransitionActive(func_ov017_0218b5b0());
    if (brightness && !data_ov004_02171010->field_18fe) return 0;
    if (!data_ov004_02171010->count) return 0;
    if (reinterpret_cast<Dialog3C40*>(_Z26GetGlobalField0x1c020421a0v())->active) return 0;
    if (!data_ov004_02171010->field_18fe) {
        _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 1, 0);
    }
    COPY_ARRAY(modes, data_ov004_0216fef8);
    selected = modes[data_ov004_02171010->sortMode];
    VectorizedInvertedMemcpy(data_ov004_02171010, maps, sizeof(maps));
    for (int i = 0; i < 99; i++) indices[i] = i;
    for (unsigned int i = 0; i < 99; i++) {
        if (static_cast<int>(i) >= data_ov004_02171010->count) {
            scores[i] = 0xffff;
        } else {
            scores[i] = 0;
            detail.Clear();
            ExportDetailedTreasureMapData(&data_ov004_02171010->maps[i], &detail, false, 0);
            if (data_ov004_02171010->sortMode == 0) {
                scores[i] += detail.discoveryState_ * 1000;
                if (detail.mapType_ == 1) scores[i] += detail.regular_.level_ * 10;
                else if (detail.mapType_ == 2) scores[i] += detail.legacy_.level_ * 10;
                scores[i] += detail.mapType_;
            } else if (data_ov004_02171010->sortMode == 1) {
                if (detail.mapType_ == 1) scores[i] += detail.regular_.level_ * 10;
                else if (detail.mapType_ == 2) scores[i] += detail.legacy_.level_ * 10;
                scores[i] += detail.mapType_;
            } else if (data_ov004_02171010->sortMode == 2) {
                scores[i] += (2 - detail.mapType_) * 1000;
                scores[i] += detail.discoveryState_ * 100;
                if (detail.mapType_ == 1) scores[i] += detail.regular_.level_;
                else if (detail.mapType_ == 2) scores[i] += detail.legacy_.level_;
            }
            detail.BlankFunction();
        }
    }
    first = 0;
    last = 98;
    while (last > first) {
        changed = 0;
        for (forward = first; forward < last; forward++) {
            unsigned short nextScore = scores[forward + 1];
            unsigned short score = scores[forward];
            if (score > nextScore) {
                unsigned short index = indices[forward];
                unsigned short nextIndex = indices[forward + 1];
                scores[forward] = nextScore;
                changed = forward;
                indices[forward] = nextIndex;
                scores[forward + 1] = score;
                indices[forward + 1] = index;
            }
        }
        last = changed;
        first++;
        for (backward = last; backward >= first; backward--) {
            unsigned short score = scores[backward];
            unsigned short previousScore = scores[backward - 1];
            if (previousScore > score) {
                unsigned short previousIndex = indices[backward - 1];
                unsigned short index = indices[backward];
                scores[backward - 1] = score;
                changed = backward;
                indices[backward - 1] = index;
                scores[backward] = previousScore;
                indices[backward] = previousIndex;
            }
        }
        first = changed;
    }
    for (int i = 0; i < 99; i++) {
        VectorizedInvertedMemcpy(&maps[indices[i]], &data_ov004_02171010->maps[i], sizeof(TreasureMapMetadata));
    }
    func_ov004_02163478(data_ov004_02171010);
    Node3C40* node = func_ov023_021f6880(func_ov011_021849c8(self), 0x35);
    if (node && func_ov023_021f6f10(node) == 8) node->selected = selected;
    _Z29DispatchNodeIfState6_021f6680Pvi(self, 0x16);
    _Z26ClearNodeMaskById_021f6600Pvii(self, 0x16, 8);
    func_ov004_02164084(self);
    return 0;
}
