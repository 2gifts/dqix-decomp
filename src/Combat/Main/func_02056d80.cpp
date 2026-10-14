#include <globaldefs.h>
#include <Memory/SignedAllocator.h>

struct AnimationKeyframe02056d80 {
    int x;
    union {
        float y;
        unsigned int duration;
    };
    float z;
    float w;
};
struct Wrap020578e8 {
    AnimationKeyframe02056d80* keyframe;
};
struct S02055080 {
    unsigned char padding[8];
    SignedAllocatorList translation[3];
    SignedAllocatorList rotation[3];
    SignedAllocatorList scale[3];
    SignedAllocatorList duration;
    SignedAllocatorList extra[3];
    SignedAllocatorList vector;
    SignedAllocatorList nextChannels[4];
    unsigned char padding_0xe0[12];
    SignedAllocatorList firstChannels[4];
    SignedAllocatorList final;
};
struct Counts02056d80 {
    unsigned char padding[16];
    unsigned char channels[4];
};
struct TransformCounts02056d80 {
    unsigned char padding[0x24];
    unsigned char translation[3];
    unsigned char rotation[3];
    unsigned char scale[3];
};
struct DurationCounts02056d80 {
    unsigned char padding[4];
    unsigned char count;
};
struct ExtraCounts02056d80 {
    unsigned char padding[16];
    unsigned char channels[3];
    unsigned char vector;
};
struct Settings02056d80 {
    unsigned char begin;
    unsigned char delay;
    unsigned char repeat;
    unsigned char flags;
};
struct Header02056d80 {
    unsigned char padding[12];
    unsigned short finalCount;
};
struct Animation02056d80 {
    int field_0x0;
    int frame;
    int endFrame;
    unsigned char repeat;
    unsigned char padding_0xd[0x1b];
    void* active;
    int field_0x2c;
    S02055080* resource;
    unsigned char padding_0x34[4];
    unsigned char flags;
    unsigned char padding_0x39[0x13];
    float channelSlopes[4];
    unsigned short channelIndices[4];
    float translationSlopes[3];
    float rotationSlopes[3];
    float scaleSlopes[3];
    unsigned short translationIndices[3];
    unsigned short rotationIndices[3];
    unsigned short scaleIndices[3];
    unsigned char padding_0x9a[2];
    float durationSlope;
    unsigned short durationIndex;
    unsigned char padding_0xa2[2];
    float extraSlopes[3];
    float vectorSlopes[3];
    unsigned short extraIndices[3];
    unsigned short vectorIndex;
    unsigned char padding_0xc4[0x54];
    float channels[4];
    float translation[3];
    float rotation[3];
    float scale[3];
    float duration;
    int finalValue;
    int delay;
    float extra[3];
    float vector[3];
};

int GetField0x4Field0x0Field0x0OrNull_02055168(S02055080*);
void* GetField0x4Field0x4OrNull_020550a8(S02055080*);
void* GetSubField0x8_020550c0(S02055080*);
void* GetSubField0xC_020550d8(S02055080*);
void* GetSubField0x10_020550f0(S02055080*);
void* GetField0x4Field0x0OrNull_02055090(S02055080*);
float ComputeSlope020578e8(Wrap020578e8*, Wrap020578e8*);

// USA: func_02056d80
extern "C" ARM void func_02056d80(Animation02056d80* self) {
    if (!self->resource || !self->active) return;
    Counts02056d80* counts = (Counts02056d80*)GetField0x4Field0x0Field0x0OrNull_02055168(self->resource);
    Wrap020578e8* previous;
    Wrap020578e8* next;
    previous = (Wrap020578e8*)self->resource->firstChannels[0].ElementAfter(0);
    self->channels[0] = previous->keyframe->y;
    if (counts->channels[0] > 1) {
        self->channelIndices[0] = 1;
        next = (Wrap020578e8*)self->resource->nextChannels[0].GetNthElement(1);
        if (next) self->channelSlopes[0] = ComputeSlope020578e8(previous, next);
    }
    previous = (Wrap020578e8*)self->resource->firstChannels[1].ElementAfter(0);
    self->channels[1] = previous->keyframe->y;
    if (counts->channels[1] > 1) {
        self->channelIndices[1] = 1;
        next = (Wrap020578e8*)self->resource->nextChannels[1].GetNthElement(1);
        if (next) self->channelSlopes[1] = ComputeSlope020578e8(previous, next);
    }
    previous = (Wrap020578e8*)self->resource->firstChannels[2].ElementAfter(0);
    self->channels[2] = previous->keyframe->y;
    if (counts->channels[2] > 1) {
        self->channelIndices[2] = 1;
        next = (Wrap020578e8*)self->resource->nextChannels[2].GetNthElement(1);
        if (next) self->channelSlopes[2] = ComputeSlope020578e8(previous, next);
    }
    previous = (Wrap020578e8*)self->resource->firstChannels[3].ElementAfter(0);
    self->channels[3] = previous->keyframe->y;
    if (counts->channels[3] > 1) {
        self->channelIndices[3] = 1;
        next = (Wrap020578e8*)self->resource->nextChannels[3].GetNthElement(1);
        if (next) self->channelSlopes[3] = ComputeSlope020578e8(previous, next);
    }
    TransformCounts02056d80* transforms = (TransformCounts02056d80*)GetField0x4Field0x4OrNull_020550a8(self->resource);
    for (int i = 0; i < 3; i++) {
        previous = (Wrap020578e8*)self->resource->translation[i].ElementAfter(0);
        self->translation[i] = previous->keyframe->y;
        if (transforms->translation[i] > 1) {
            self->translationIndices[i] = 1;
            next = (Wrap020578e8*)self->resource->translation[i].GetNthElement(self->translationIndices[i]);
            if (next) self->translationSlopes[i] = ComputeSlope020578e8(previous, next);
        }
    }
    for (int i = 0; i < 3; i++) {
        previous = (Wrap020578e8*)self->resource->rotation[i].ElementAfter(0);
        self->rotation[i] = previous->keyframe->y;
        if (transforms->rotation[i] > 1) {
            self->rotationIndices[i] = 1;
            next = (Wrap020578e8*)self->resource->rotation[i].GetNthElement(self->rotationIndices[i]);
            if (next) self->rotationSlopes[i] = ComputeSlope020578e8(previous, next);
        }
    }
    for (int i = 0; i < 3; i++) {
        previous = (Wrap020578e8*)self->resource->scale[i].ElementAfter(0);
        self->scale[i] = previous->keyframe->y;
        if (transforms->scale[i] > 1) {
            self->scaleIndices[i] = 1;
            next = (Wrap020578e8*)self->resource->scale[i].GetNthElement(self->scaleIndices[i]);
            if (next) self->scaleSlopes[i] = ComputeSlope020578e8(previous, next);
        }
    }
    DurationCounts02056d80* duration = (DurationCounts02056d80*)GetSubField0x8_020550c0(self->resource);
    previous = (Wrap020578e8*)self->resource->duration.ElementAfter(0);
    self->duration = (float)previous->keyframe->duration;
    if (duration->count > 1) {
        self->durationIndex = 1;
        next = (Wrap020578e8*)self->resource->duration.GetNthElement(1);
        if (next) self->durationSlope = ComputeSlope020578e8(previous, next);
    }
    ExtraCounts02056d80* extra = (ExtraCounts02056d80*)GetSubField0xC_020550d8(self->resource);
    for (int i = 0; i < 3; i++) {
        previous = (Wrap020578e8*)self->resource->extra[i].ElementAfter(0);
        self->extra[i] = previous->keyframe->y;
        if (extra->channels[i] > 1) {
            self->extraIndices[i] = 1;
            next = (Wrap020578e8*)self->resource->extra[i].GetNthElement(self->extraIndices[i]);
            if (next) self->extraSlopes[i] = ComputeSlope020578e8(previous, next);
        }
    }
    previous = (Wrap020578e8*)self->resource->vector.ElementAfter(0);
    self->vector[0] = previous->keyframe->y;
    self->vector[1] = previous->keyframe->z;
    self->vector[2] = previous->keyframe->w;
    if (extra->vector > 1) {
        self->vectorIndex = 1;
        next = (Wrap020578e8*)self->resource->vector.GetNthElement(1);
        if (next) {
            self->vectorSlopes[0] = (next->keyframe->y - previous->keyframe->y) / (float)(next->keyframe->x - previous->keyframe->x);
            self->vectorSlopes[1] = (next->keyframe->z - previous->keyframe->z) / (float)(next->keyframe->x - previous->keyframe->x);
            self->vectorSlopes[2] = (next->keyframe->w - previous->keyframe->w) / (float)(next->keyframe->x - previous->keyframe->x);
        }
    }
    Settings02056d80* settings = (Settings02056d80*)GetSubField0x10_020550f0(self->resource);
    self->frame = 0;
    self->endFrame = settings->begin + settings->delay;
    self->repeat = settings->repeat;
    self->flags = settings->flags;
    self->delay = settings->delay;
    if (settings->repeat) self->repeat = 1;
    if (((Header02056d80*)GetField0x4Field0x0OrNull_02055090(self->resource))->finalCount == 0) return;
    previous = (Wrap020578e8*)self->resource->final.ElementAfter(0);
    self->finalValue = previous->keyframe->x;
}
