#include <globaldefs.h>
#include <System/Matrix.h>
#include <std_library_functions.h>

struct Entry02156ba0 {
    int start;
    int duration;
    int cubic[3];
    int quadratic[3];
    int linear[3];
    int constant[3];
};
struct Buf02156ba0 {
    Entry02156ba0 entries[16];
    int count;
    int field_384;
    int field_388;
    Vector3fix initial;
    int mode;
};
extern "C" void _Z30ZeroEntryArrayAndTail_02156ba0P11Buf02156ba0(Buf02156ba0*);

static inline int MultiplyFixed(int value, int factor) {
    return FIX32_MULTIPLY(value, factor);
}

// USA: func_ov001_02156c14
extern "C" ARM void func_ov001_02156c14(Buf02156ba0* self, const Vector3fix* points, const int* durations, int count, int mode) {
    _Z30ZeroEntryArrayAndTail_02156ba0P11Buf02156ba0(self);
    if (count > 0) {
        int index;
        Vector3fix positions[18];
        self->count = count;
        self->mode = mode;
        for (index = 0; index < self->count; ++index) memcpy(&positions[index], &points[index], sizeof(Vector3fix));
        memcpy(&positions[self->count], &points[self->count - 1], sizeof(Vector3fix));
        memcpy(&positions[self->count + 1], &points[self->count - 1], sizeof(Vector3fix));
        self->initial.x = points[0].x;
        self->initial.y = points[0].y;
        self->initial.z = points[0].z;
        for (index = 0; index < self->count; ++index) {
            if (index == 0) {
                self->entries[index].start = 0;
                self->entries[index].duration = durations[index];
            } else if (index == self->count - 1) {
                self->entries[index].start = self->entries[index - 1].start + self->entries[index - 1].duration;
                self->entries[index].duration = 0;
            } else {
                self->entries[index].start = self->entries[index - 1].start + self->entries[index - 1].duration;
                self->entries[index].duration = durations[index];
            }
        }
        for (index = 0; index < self->count; ++index) {
            for (int axis = 0; axis < 3; ++axis) {
                int slope;
                int previous;
                int current;
                int next;
                int following;
                if (axis == 0) {
                    current = positions[index].x;
                    next = positions[index + 1].x;
                    following = positions[index + 2].x;
                    if (index > 0) previous = positions[index - 1].x;
                } else if (axis == 1) {
                    current = positions[index].y;
                    next = positions[index + 1].y;
                    following = positions[index + 2].y;
                    if (index > 0) previous = positions[index - 1].y;
                } else {
                    current = positions[index].z;
                    next = positions[index + 1].z;
                    following = positions[index + 2].z;
                    if (index > 0) previous = positions[index - 1].z;
                }
                if (index == 0) slope = next - current;
                else {
                    int previousTerm = MultiplyFixed(current - previous, self->entries[index].duration << 12);
                    int nextTerm = MultiplyFixed(next - current, self->entries[index - 1].duration << 12);
                    slope = fix32_Divide(nextTerm + previousTerm, (self->entries[index - 1].duration + self->entries[index].duration) << 12);
                }
                int nextSlope;
                if (index == self->count - 1) nextSlope = following - next;
                else {
                    int currentTerm = MultiplyFixed(next - current, self->entries[index + 1].duration << 12);
                    int followingTerm = MultiplyFixed(following - next, self->entries[index].duration << 12);
                    nextSlope = fix32_Divide(followingTerm + currentTerm, (self->entries[index].duration + self->entries[index + 1].duration) << 12);
                }
                int twiceNext = MultiplyFixed(next, 0x2000);
                int twiceCurrent = MultiplyFixed(current, 0x2000);
                self->entries[index].cubic[axis] = twiceCurrent - twiceNext + slope + nextSlope;
                int tripleNext = MultiplyFixed(next, 0x3000);
                int tripleCurrent = MultiplyFixed(current, -0x3000);
                int twiceSlope = MultiplyFixed(slope, 0x2000);
                self->entries[index].quadratic[axis] = tripleCurrent + tripleNext - twiceSlope - nextSlope;
                self->entries[index].linear[axis] = slope;
                self->entries[index].constant[axis] = current;
            }
        }
    }
}
