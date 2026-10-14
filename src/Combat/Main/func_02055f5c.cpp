#include <globaldefs.h>
#include "Memory/SignedAllocator.h"

#include "World/Object3D.h"

struct Particle02055f5c;
struct Spawner02055f5c;
struct Struct02058c88;

extern "C" int rand(void);
extern "C" Particle02055f5c* func_02055ed0(Spawner02055f5c*);
extern "C" void func_02058d40(Particle02055f5c*, void*, Object3D*, int);
extern "C" void* __clear(void*, unsigned);
extern "C" void func_020ca528(const void*, Matrix3x3*);
extern "C" void func_02059720(Particle02055f5c*);

struct S02055080 {
    unsigned char padding_0x0[0x11c];
    SignedAllocatorList keyframes;
};
void* GetField0x4Field0x0OrNull_02055090(S02055080*);
void* GetSubField0x8_020550c0(S02055080*);
void InitStruct02058c88(Struct02058c88*);

#define ToBamAngle(degF) ((int)(4096.0f * (3.14159274f * ((degF) / 180.0f))))

struct PosData0x9c {
    int unused0;
    float x, y, z;
    float x2, y2, z2;
};

struct KeyframeElement02055f5c {
    PosData0x9c* data;
};

struct ParticleSpawnConfig02055f5c {
    char padding0[5];
    unsigned char countVariationPercent;
};

struct CountHolder0xc {
    char pad[0xc];
    unsigned short count;
};

struct Particle02055f5c {
    char pad00[0x10];
    Vector3fix position;
    char pad1c[0x2c - 0x1c];
    unsigned char active2c;
    unsigned char flag2d;
    unsigned char flag2e;
    char pad2f;
    char pad30[0x6c - 0x30];
    float velX, velY, velZ;
    float speed78;
};

struct Spawner02055f5c {
    char pad00[0x4];
    int field4;
    char pad08[0x2c - 0x8];
    Object3D* field2c;
    S02055080* ptr30;
    char pad34[0x3a - 0x34];
    unsigned char field3a;
    unsigned char field3b;
    unsigned short field3c;
    char pad3e[0x40 - 0x3e];
    Vector3fix scale;
    char pad4c[0x70 - 0x4c];
    float field70, field74, field78, field7c, field80, field84;
    char pad88[0xa8 - 0x88];
    float fieldA8;
    char padAC[0xb0 - 0xac];
    float fieldB0, fieldB4, fieldB8;
    char padBC[0xe8 - 0xbc];
    unsigned int fieldE8[9];
    int field10c, field110, field114;
    float field118, field11c, field120;
    char pad124[4];
    float field128, field12c, field130;
    float field134, field138, field13c;
    float field140, field144, field148;
    float field14c;
    int field150;
    char pad154[0x15c - 0x154];
    float field15c;
    float field160;
    float field164, field168, field16c;
};

// USA: func_02055f5c
extern "C" ARM void func_02055f5c(struct Spawner02055f5c* self, int elapsedFrames, int waveCount) {
    struct CountHolder0xc* keyframeCount = (struct CountHolder0xc*)GetField0x4Field0x0OrNull_02055090(self->ptr30);

    if (keyframeCount->count != 0) {
        if (self->field3c >= keyframeCount->count) return;

        struct SignedAllocatorHeader* keyframe = self->ptr30->keyframes.GetNthElement(self->field3c);

        struct Particle02055f5c* particle = func_02055ed0(self);
        if (particle == 0) return;

        if (self->field2c != 0 && self->scale.x == 0 && self->scale.y == 0 && self->scale.z == 0) {
            self->scale = self->field2c->GetScale();
        }

        InitStruct02058c88((struct Struct02058c88*)particle);

        Vector3fix keyframePosition;
        keyframePosition.x = (int)((((KeyframeElement02055f5c*)keyframe)->data)->x * 4096.0f);
        keyframePosition.y = (int)((((KeyframeElement02055f5c*)keyframe)->data)->y * 4096.0f);
        keyframePosition.z = (int)((((KeyframeElement02055f5c*)keyframe)->data)->z * 4096.0f);
        particle->position = keyframePosition;

        struct PosData0x9c* keyframeData = ((KeyframeElement02055f5c*)keyframe)->data;
        int scaleFactorX = (int)(keyframeData->x2 * 4096.0f);
        int scaleFactorY = (int)(keyframeData->y2 * 4096.0f);
        int scaleFactorZ = (int)(keyframeData->z2 * 4096.0f);

        Vector3fix baseScale = self->scale;
        Vector3fix particleScale;
        int scaled;
        scaled = (int)(((long long)scaleFactorX * baseScale.x + 0x800) >> 12);
        particleScale.x = scaled;
        scaled = (int)(((long long)scaleFactorY * baseScale.y + 0x800) >> 12);
        particleScale.y = scaled;
        scaled = (int)(((long long)scaleFactorZ * baseScale.z + 0x800) >> 12);
        particleScale.z = scaled;
        self->field2c->SetScale(&particleScale);

        func_02058d40(particle, self->ptr30, self->field2c, self->field4);
        particle->active2c = 1;

        self->field3c = self->field3c + 1;
        if (self->field3c >= keyframeCount->count) return;

        struct SignedAllocatorHeader* nextKeyframe = self->ptr30->keyframes.GetNthElement(self->field3c);
        self->field150 = ((KeyframeElement02055f5c*)nextKeyframe)->data->unused0;
        if (self->field150 != 0) return;

        func_02055f5c(self, elapsedFrames, waveCount);
        return;
    }

    ParticleSpawnConfig02055f5c* spawnConfig = (ParticleSpawnConfig02055f5c*)GetSubField0x8_020550c0(self->ptr30);
    int countVariationPercent = spawnConfig->countVariationPercent;
    int sampledCountDelta = rand() % (countVariationPercent * 2);
    float countVariation = (float)(sampledCountDelta - countVariationPercent) / 100.0f;
    int countAdjustment = (int)(self->field14c * countVariation);
    int particlesPerWave = (int)(self->field14c + (float)countAdjustment);

    int particleIndex;
    int waveIndex;
    Particle02055f5c* particle;
    for (waveIndex = 0; waveIndex < waveCount; waveIndex++) {
        particleIndex = 0;

        for (; particleIndex < particlesPerWave; particleIndex++) {
            particle = func_02055ed0(self);
            if (particle == 0) continue;

            InitStruct02058c88((struct Struct02058c88*)particle);

            int radiusRandom = rand() % 90;
            float radiusRatio = (float)(radiusRandom + 10) / 100.0f;
            int heightRandom = rand() % 90;
            float heightRatio = (float)(heightRandom + 10) / 100.0f;
            int angleDeg = rand() % 360;

            Vector3fix posv;
            __clear(&posv, 0xc);
            posv.x = (int)(4096.0f * radiusRatio);
            int angle2 = ToBamAngle((float)angleDeg);

            Matrix4x3 mtxY;
            mtxY = RotationMatrixY(angle2);
            Matrix4x3 mtxYCopy = mtxY;
            Mat4x3_ApplyToVector(&posv, &mtxYCopy, &posv);

            float extentX = self->field118 * self->field128;
            float extentY = self->field11c * self->field12c;
            float extentZ = self->field120 * self->field130;

            float rotatedX = (float)posv.x;
            float normalizedX = rotatedX / 4096.0f;
            float displacementX = normalizedX * extentX;
            float originX = self->field140 + displacementX;
            float movementX = self->field7c * (float)elapsedFrames;
            float waveMovementX = movementX / (float)(waveCount - waveIndex);
            float positionX = originX;
            positionX += waveMovementX;

            float displacementY = heightRatio * extentY;
            float originY = self->field144 + displacementY;
            float movementY = self->field80 * (float)elapsedFrames;
            float waveMovementY = movementY / (float)(waveCount - waveIndex);
            float positionY = originY;
            positionY += waveMovementY;

            float rotatedZ = (float)posv.z;
            float normalizedZ = rotatedZ / 4096.0f;
            float displacementZ = normalizedZ * extentZ;
            float originZ = self->field148 + displacementZ;
            float movementZ = self->field84 * (float)elapsedFrames;
            float waveMovementZ = movementZ / (float)(waveCount - waveIndex);
            float positionZ = originZ;
            positionZ += waveMovementZ;

            float halfExtentY = extentY / 2.0f;
            float centeredY = positionY - halfExtentY;

            Vector3fix position;
            position.x = (int)(4096.0f * positionX) + self->field10c;
            position.y = (int)(4096.0f * centeredY) + self->field110;
            position.z = (int)(4096.0f * positionZ) + self->field114;
            particle->position = position;

            float velXdeg = self->field134 + (self->field70 * (float)elapsedFrames) / (float)(waveCount - waveIndex);
            if (velXdeg < 0.0f) velXdeg = 360.0f + velXdeg;
            float velYdeg = self->field138 + (self->field74 * (float)elapsedFrames) / (float)(waveCount - waveIndex);
            if (velYdeg < 0.0f) velYdeg = 360.0f + velYdeg;
            float velZdeg = self->field13c + (self->field78 * (float)elapsedFrames) / (float)(waveCount - waveIndex);
            if (velZdeg < 0.0f) velZdeg = 360.0f + velZdeg;

            int angleX = ToBamAngle(velXdeg);
            Matrix4x3 rotX;
            rotX = RotationMatrixX(angleX);
            Matrix4x3 accumX = rotX;

            int angleY = ToBamAngle(velYdeg);
            Matrix4x3 rotY;
            rotY = RotationMatrixY(angleY);
            Matrix4x3 accumY = rotY;

            int angleZ = ToBamAngle(velZdeg);
            Matrix4x3 transform;
            transform = RotationMatrixZ(angleZ);
            Matrix4x3 accumT = transform;

            Mat4x3_Multiply(&accumX, &accumY, &accumX);
            Mat4x3_Multiply(&accumX, &accumT, &accumX);

            Vector3fix velVec;
            velVec.x = (int)(4096.0f * (self->field164 + (self->fieldB0 * (float)elapsedFrames) / (float)(waveCount - waveIndex)));
            velVec.y = (int)(4096.0f * (self->field168 + (self->fieldB4 * (float)elapsedFrames) / (float)(waveCount - waveIndex)));
            velVec.z = (int)(4096.0f * (self->field16c + (self->fieldB8 * (float)elapsedFrames) / (float)(waveCount - waveIndex)));

            Mat4x3_ApplyToVector(&velVec, &accumX, &velVec);

            Matrix3x3 orientMtx;
            Mat3x3_WriteIdentity(&orientMtx);
            func_020ca528(self->fieldE8, &orientMtx);
            Mat3x3_ApplyToVector(&velVec, &orientMtx, &velVec);

            Matrix3x3 jitterAccum;
            Mat3x3_WriteIdentity(&jitterAccum);

            int jitterAngle;
            int jitterCount = (int)self->field160;
            if ((float)jitterCount >= 1.0f) {
                int jitterDegreesX = rand() % jitterCount;
                jitterAngle = ToBamAngle((float)jitterDegreesX);
                if (rand() % 2) {
                    jitterAngle -= ToBamAngle((float)jitterCount);
                }
                jitterAngle = fix32ReduceAngle0To2Pi(jitterAngle);
                int jitterCosX = fix32cos(jitterAngle);
                int jitterSinX = fix32sin(jitterAngle);
                Matrix3x3 jitterRotationX;
                Mat3x3_WriteRotationX(&jitterRotationX, jitterSinX, jitterCosX);
                Mat3x3_Multiply(&jitterAccum, &jitterRotationX, &jitterAccum);

                int jitterDegreesY = rand() % jitterCount;
                jitterAngle = ToBamAngle((float)jitterDegreesY);
                if (rand() % 2) {
                    jitterAngle -= ToBamAngle((float)jitterCount);
                }
                jitterAngle = fix32ReduceAngle0To2Pi(jitterAngle);
                int jitterCosY = fix32cos(jitterAngle);
                int jitterSinY = fix32sin(jitterAngle);
                Matrix3x3 jitterRotationY;
                Mat3x3_WriteRotationY(&jitterRotationY, jitterSinY, jitterCosY);
                Mat3x3_Multiply(&jitterAccum, &jitterRotationY, &jitterAccum);

                int jitterDegreesZ = rand() % jitterCount;
                jitterAngle = ToBamAngle((float)jitterDegreesZ);
                if (rand() % 2) {
                    jitterAngle -= ToBamAngle((float)jitterCount);
                }
                jitterAngle = fix32ReduceAngle0To2Pi(jitterAngle);
                int jitterCosZ = fix32cos(jitterAngle);
                int jitterSinZ = fix32sin(jitterAngle);
                Matrix3x3 jitterRotationZ;
                Mat3x3_WriteRotationZ(&jitterRotationZ, jitterSinZ, jitterCosZ);
                Mat3x3_Multiply(&jitterAccum, &jitterRotationZ, &jitterAccum);

                Mat3x3_ApplyToVector(&velVec, &jitterAccum, &velVec);
            }

            float fz = (float)velVec.z / 4096.0f;
            float fy = (float)velVec.y / 4096.0f;
            float fx = (float)velVec.x / 4096.0f;
            particle->velX = fx;
            particle->velY = fy;
            particle->velZ = fz;

            particle->speed78 = self->field15c + (self->fieldA8 * (float)elapsedFrames) / (float)(waveCount - waveIndex);

            if (self->field3a != 0) {
                particle->flag2d = 1;
            } else if (self->field3b != 0) {
                particle->flag2e = 1;
            }

            func_02058d40(particle, self->ptr30, self->field2c, self->field4);
            particle->active2c = 1;

            for (int t = 0; t < waveIndex; t++) {
                func_02059720(particle);
            }
        }
    }
}
