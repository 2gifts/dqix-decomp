#include <globaldefs.h>
#include "World/Zone3D.h"
#include "World/ZoneTerrain.h"
#include "World/Bounds3D.h"
#include "Graphics/Vector.h"

// USA: func_02019210
extern "C" ARM Vector3fix func_02019210(Zone3D* zone, const Vector3fix* position,
                                       const Vector3fix* offset, int radius) {
    Vector3fix destination;
    Vector3fix_Add(position, offset, &destination);
    Vector3fix_Length(offset);

    Bounds3D probe;
    if (destination.x < position->x) {
        probe.maximum.x = position->x;
        probe.minimum.x = destination.x;
    } else {
        probe.maximum.x = destination.x;
        probe.minimum.x = position->x;
    }
    if (destination.y < position->y) {
        probe.maximum.y = position->y;
        probe.minimum.y = destination.y;
    } else {
        probe.maximum.y = destination.y;
        probe.minimum.y = position->y;
    }
    if (destination.z < position->z) {
        probe.maximum.z = position->z;
        probe.minimum.z = destination.z;
    } else {
        probe.maximum.z = destination.z;
        probe.minimum.z = position->z;
    }

    Vector3fix from = *position;
    Vector3fix to;
    Vector3fix_Add(position, offset, &to);
    if (radius > 0) {
        Vector3fix direction;
        Vector3fix_Normalize(&to, &direction);
        Vector3fix margin;
        Vector3fixMultiplyScalar(&direction, radius, &margin);
        Vector3fix_Add(&to, &margin, &to);
    }

    int cell;
    if (zone->isInMainGrottoFloor_23b8_) {
        cell = (int)(((float)(position->x + 0x4000) / 4096.0f) / 8.0f)
             + ((int)(((float)(position->z + 0x4000) / 4096.0f) / 8.0f) << 4);
    }

    for (int i = 0; i < zone->unknown_82c_; i++) {
        if (!zone->isInMainGrottoFloor_23b8_ || cell == i) {
            ZoneTerrainGrid grid;
            ZoneTerrainSample samples[96];
            int count = func_02017d90(zone, i, &grid, probe, 0);
            if (count > 0) {
                ZoneTerrainSample* sample = samples;
                int scale;
                for (int j = 0; j < count; j++, sample++) {
                    scale = grid.scale << 12;
                    func_02031188(sample, &grid.cells[j][0]);
                    Vector3fixMultiplyScalar(&sample->a, scale, &sample->a);
                    Vector3fixMultiplyScalar(&sample->b, scale, &sample->b);
                    Vector3fixMultiplyScalar(&sample->c, scale, &sample->c);
                }
                Vector3fix localFrom = from;
                Vector3fix localTo = to;
                Vector3fix_Subtract(&from, &grid.position, &localFrom);
                Vector3fix_Subtract(&to, &grid.position, &localTo);
                Vector3fix collision;
                if (func_020319d8(samples, count, &localFrom, &localTo, &collision) >= 0) {
                    if (func_020315b8(samples, count, &collision, radius, &collision, 0) >= 0) {
                        Vector3fix_Add(&collision, &grid.position, &to);
                        destination = to;
                    }
                }
            }
        }
    }
    return destination;
}
