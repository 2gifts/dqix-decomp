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

struct CubicPathState {
    CubicPathSegment segments[16];
    int segmentCount;
    int currentSegment;
    fix32_t elapsedTime;
    fix32_t position[3];
};

static inline fix32_t MultiplyRounded(fix32_t lhs, fix32_t rhs) {
    return FIX32_MULTIPLY(lhs, rhs);
}

// USA: func_ov001_021573c0
extern "C" ARM int func_ov001_021573c0(void *receiver) {
    int axis;
    fix32_t squared;
    fix32_t cubed;
    CubicPathState *path = static_cast<CubicPathState *>(receiver);
    if (path->segmentCount <= 1) {
        return 1;
    }

    path->elapsedTime += 0x1000;
    if (path->elapsedTime >= (path->segments[path->currentSegment].startTime + path->segments[path->currentSegment].duration)
                                 << 12)
    {
        ++path->currentSegment;
        if (path->currentSegment >= path->segmentCount) {
            for (axis = 0; axis < 3; ++axis) {
                path->position[axis] = path->segments[path->segmentCount - 1].constant[axis];
            }
            path->currentSegment = path->segmentCount - 1;
            path->elapsedTime =
                (path->segments[path->currentSegment].startTime + path->segments[path->currentSegment].duration + 100) << 12;
            return 1;
        }
    }

    fix32_t progress = fix32_Divide(path->elapsedTime - (path->segments[path->currentSegment].startTime << 12),
                                    path->segments[path->currentSegment].duration << 12);
    squared          = MultiplyRounded(progress, progress);
    cubed            = MultiplyRounded(squared, progress);
    for (axis = 0; axis < 3; ++axis) {
        path->position[axis] = MultiplyRounded(path->segments[path->currentSegment].cubic[axis], cubed) +
                               MultiplyRounded(path->segments[path->currentSegment].quadratic[axis], squared) +
                               MultiplyRounded(path->segments[path->currentSegment].linear[axis], progress) +
                               path->segments[path->currentSegment].constant[axis];
    }
    return 0;
}
