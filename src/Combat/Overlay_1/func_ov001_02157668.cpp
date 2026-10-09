#include <globaldefs.h>

struct SrcVec02157570 {
    unsigned char pad0[0x38c];
    int x;
    int y;
    int z;
    int minimumDistance;
};
struct DstVec02157570 {
    int x;
    int y;
    int z;
};

extern "C" void _Z20CopyVector3_02157570P14SrcVec02157570P14DstVec02157570(struct SrcVec02157570* src, struct DstVec02157570* dst);

extern "C" int Vector3fix_Distance(struct DstVec02157570* a, struct DstVec02157570* b);
extern "C" int fix32_Divide(int num, int denom);
extern "C" int func_ov001_021573c0(void* path);
extern "C" void func_ov001_02156c14(void* path, void* points, int* paces, int count, int speed);

struct DualPath02157668 {
    struct DstVec02157570 pointsA[16];
    struct DstVec02157570 pointsB[16];
    int count;
    int duration;
    struct SrcVec02157570 pathA;
    struct SrcVec02157570 pathB;
};

// USA: func_ov001_02157668
extern "C" ARM int func_ov001_02157668(struct DualPath02157668* self) {
    int pace[16];
    int dist[16];
    struct DstVec02157570 prevA;
    struct DstVec02157570 nextA;
    struct DstVec02157570 prevB;
    struct DstVec02157570 nextB;
    int i;
    int total;

    if (self->count <= 0) {
        return 1;
    }

    total = 0;
    for (i = 0; i < self->count - 1; i++) {
        dist[i] = Vector3fix_Distance(&self->pointsA[i], &self->pointsA[i + 1]);
        total += dist[i];
    }
    for (i = 0; i < self->count - 1; i++) {
        pace[i] = self->duration / (self->count - 1);
    }
    func_ov001_02156c14(&self->pathA, self->pointsA, pace, self->count, 0);

    total = 0;
    while (1) {
        _Z20CopyVector3_02157570P14SrcVec02157570P14DstVec02157570(&self->pathA, &prevA);
        if (func_ov001_021573c0(&self->pathA) != 0) {
            break;
        }
        _Z20CopyVector3_02157570P14SrcVec02157570P14DstVec02157570(&self->pathA, &nextA);
        total += Vector3fix_Distance(&prevA, &nextA);
    }
    func_ov001_02156c14(&self->pathA, self->pointsA, pace, self->count, fix32_Divide(total, self->duration << 12));

    total = 0;
    for (i = 0; i < self->count - 1; i++) {
        dist[i] = Vector3fix_Distance(&self->pointsB[i], &self->pointsB[i + 1]);
        total += dist[i];
    }
    for (i = 0; i < self->count - 1; i++) {
        pace[i] = self->duration / (self->count - 1);
    }
    func_ov001_02156c14(&self->pathB, self->pointsB, pace, self->count, 0);

    total = 0;
    while (1) {
        _Z20CopyVector3_02157570P14SrcVec02157570P14DstVec02157570(&self->pathB, &prevB);
        if (func_ov001_021573c0(&self->pathB) != 0) {
            break;
        }
        _Z20CopyVector3_02157570P14SrcVec02157570P14DstVec02157570(&self->pathB, &nextB);
        total += Vector3fix_Distance(&prevB, &nextB);
    }
    func_ov001_02156c14(&self->pathB, self->pointsB, pace, self->count, fix32_Divide(total, self->duration << 12));

    return 0;
}
