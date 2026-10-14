#include <globaldefs.h>

#include "World/Zone3D.h"
#include "World/ZoneTerrain.h"
#include "World/Bounds3D.h"
#include "Graphics/Vector.h"

extern "C" float _fflt(int v);
extern "C" float _fdiv(float a, float b);
extern "C" int _ffix(float v);

// USA: func_02018fbc
extern "C" ARM int func_02018fbc(Zone3D* ctx, Vector3fix* p) {
    Vector3fix v = *p;
    Bounds3D probe;
    Vector3fix diff;
    Vector3fix up;
    Vector3fix down;
    Vector3fix out;

    probe.maximum = v;
    probe.minimum = v;
    probe.maximum.x += 0x800;
    probe.maximum.y += 0x1000;
    probe.maximum.z += 0x800;
    probe.minimum.x -= 0x800;
    probe.minimum.y -= 0xa000;
    probe.minimum.z -= 0x800;

    int cell;
    if (ctx->isInMainGrottoFloor_23b8_ != 0) {
        cell = (int)(((float)(v.x + 0x4000) / 4096.0f) / 8.0f)
             + ((int)(((float)(v.z + 0x4000) / 4096.0f) / 8.0f) << 4);
    }

    for (int i = 0; i < ctx->unknown_82c_; i++) {
        if (ctx->isInMainGrottoFloor_23b8_ == 0 || cell == i) {
            ZoneTerrainGrid grid;
            ZoneTerrainSample samples[96];
            int n = func_02017d90(ctx, i, &grid, probe, 0);
            if (n > 0) {
                ZoneTerrainSample* sample = samples;
                int scale;
                for (int j = 0; j < n; j++, sample++) {
                    scale = grid.scale << 12;
                    func_02031188(sample, &grid.cells[j][0]);
                    Vector3fixMultiplyScalar(&sample->a, scale, &sample->a);
                    Vector3fixMultiplyScalar(&sample->b, scale, &sample->b);
                    Vector3fixMultiplyScalar(&sample->c, scale, &sample->c);
                }
                Vector3fix_Subtract(&v, &grid.position, &diff);
                up = diff;
                up.y += 0x1000;
                down = diff;
                down.y -= 0xa000;
                if (func_020312bc(samples, n, &up, &down, &out) != -1) {
                    out.y += 0x199;
                    v.y = out.y;
                    diff.y = out.y;
                }
            }
        }
    }
    return v.y;
}
