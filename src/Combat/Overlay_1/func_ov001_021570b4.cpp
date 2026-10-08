#include <globaldefs.h>

#include <System/Matrix.h>

struct CubicPathSegment {
    int startTime;
    int duration;
    fix32_t cubic[3];
    fix32_t quadratic[3];
    fix32_t linear[3];
    fix32_t constant[3];
};

struct DistanceSteppedCubicPathState {
    CubicPathSegment segments[16];
    int segmentCount;
    int currentSegment;
    fix32_t elapsedTime;
    fix32_t position[3];
    fix32_t minimumDistance;
};

static inline fix32_t MultiplyRounded(fix32_t lhs, fix32_t rhs) {
    return FIX32_MULTIPLY(lhs, rhs);
}

// USA: func_ov001_021570b4
extern "C" ARM int func_ov001_021570b4(void *receiver) {
    DistanceSteppedCubicPathState *path = static_cast<DistanceSteppedCubicPathState *>(receiver);
    if (path->segmentCount <= 1) {
        return 1;
    }
    if (path->minimumDistance <= 0) {
        return 1;
    }

    Vector3fix previous;
    Vector3fix next;
    do {
        path->elapsedTime += 0x199;
        if (path->elapsedTime >=
            (path->segments[path->currentSegment].startTime + path->segments[path->currentSegment].duration) << 12)
        {
            ++path->currentSegment;
            if (path->currentSegment >= path->segmentCount) {
                for (int axis = 0; axis < 3; ++axis) {
                    path->position[axis] = path->segments[path->segmentCount - 1].constant[axis];
                }
                path->currentSegment = path->segmentCount - 1;
                path->elapsedTime =
                    (path->segments[path->currentSegment].startTime + path->segments[path->currentSegment].duration + 100)
                    << 12;
                return 1;
            }
        }

        fix32_t progress = fix32_Divide(path->elapsedTime - (path->segments[path->currentSegment].startTime << 12),
                                        path->segments[path->currentSegment].duration << 12);
        fix32_t squared  = MultiplyRounded(progress, progress);
        fix32_t cubed    = MultiplyRounded(squared, progress);
        previous.x       = path->position[0];
        next.x           = MultiplyRounded(path->segments[path->currentSegment].cubic[0], cubed) +
                 MultiplyRounded(path->segments[path->currentSegment].quadratic[0], squared) +
                 MultiplyRounded(path->segments[path->currentSegment].linear[0], progress) +
                 path->segments[path->currentSegment].constant[0];
        previous.y = path->position[1];
        next.y     = MultiplyRounded(path->segments[path->currentSegment].cubic[1], cubed) +
                 MultiplyRounded(path->segments[path->currentSegment].quadratic[1], squared) +
                 MultiplyRounded(path->segments[path->currentSegment].linear[1], progress) +
                 path->segments[path->currentSegment].constant[1];
        previous.z = path->position[2];
        next.z     = MultiplyRounded(path->segments[path->currentSegment].cubic[2], cubed) +
                 MultiplyRounded(path->segments[path->currentSegment].quadratic[2], squared) +
                 MultiplyRounded(path->segments[path->currentSegment].linear[2], progress) +
                 path->segments[path->currentSegment].constant[2];
    } while (Vector3fix_Distance(&previous, &next) < path->minimumDistance);
    path->position[0] = next.x;
    path->position[1] = next.y;
    path->position[2] = next.z;
    return 0;
}
