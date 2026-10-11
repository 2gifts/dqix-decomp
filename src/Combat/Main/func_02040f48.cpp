#include <globaldefs.h>
#include <System/Matrix.h>

extern "C" int _Z8fix32sini(int x);
extern "C" int _Z8fix32cosi(int x);
extern "C" int rand(void);

struct Node020409b0 {
    char pad[0x14];
    void* f14;
    void* f18;
};
extern "C" extern int _Z29DispatchOnActiveChild020409b0P12Node020409b0i(struct Node020409b0* obj, int arg);

struct Table02040f48 {
    Vector3i v[4];
};

extern struct Table02040f48 data_020e7a20;

struct Container02040f48 {
    char pad0[0x1f];
    unsigned char mode;
    char pad20[2];
    short angle;
    int xMax;
    int zMax;
    int xMin;
    int zMin;
};

struct Obj02040f48 {
    char pad0[0xc];
    struct Container02040f48* cont;
};

// USA: func_02040f48
extern "C" ARM void func_02040f48(struct Obj02040f48* self, Vector3i* ref) {
    struct Table02040f48 table = data_020e7a20;
    Vector3i pos = *ref;
    Vector3i cand[4];

    if (self->cont->mode == 8) {
        int sn = _Z8fix32sini(self->cont->angle);
        int cs = _Z8fix32cosi(self->cont->angle);
        if (sn < 0) sn = -sn;
        if (cs < 0) cs = -cs;
        if (self->cont->angle < 0x191e || (self->cont->angle > 0x323d && self->cont->angle < 0x4b5c)) {
            table.v[0].x = sn;
            table.v[0].z = cs;
            table.v[1].x = sn;
            table.v[1].z = cs;
            table.v[2].x = -sn;
            table.v[2].z = -cs;
            table.v[3].x = -sn;
            table.v[3].z = -cs;
        } else {
            table.v[0].x = sn;
            table.v[0].z = -cs;
            table.v[1].x = sn;
            table.v[1].z = -cs;
            table.v[2].x = -sn;
            table.v[2].z = cs;
            table.v[3].x = -sn;
            table.v[3].z = cs;
        }
    }

    int n = 0;
    if (pos.x < self->cont->xMax) {
        cand[n] = table.v[0];
        n++;
    }
    if (pos.z < self->cont->zMax) {
        cand[n] = table.v[1];
        n++;
    }
    if (pos.x > self->cont->xMin) {
        cand[n] = table.v[2];
        n++;
    }
    if (pos.z > self->cont->zMin) {
        cand[n] = table.v[3];
        n++;
    }

    if (pos.x > self->cont->xMax) pos.x = self->cont->xMax;
    if (pos.z > self->cont->zMax) pos.z = self->cont->zMax;
    if (pos.x < self->cont->xMin) pos.x = self->cont->xMin;
    if (pos.z < self->cont->zMin) pos.z = self->cont->zMin;

    int idx = rand() % n;
    Vector3fix_Add((const Vector3fix*)&pos, (const Vector3fix*)&cand[idx], (Vector3fix*)&pos);
    _Z29DispatchOnActiveChild020409b0P12Node020409b0i((struct Node020409b0*)self, (int)&pos);
}
