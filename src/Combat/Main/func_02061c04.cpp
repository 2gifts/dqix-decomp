#define __STDC_UTF_16__ 1
#define __STDC_UTF_32__ 1
#define _GNU_SOURCE 1

extern "C" {
int rand();
void srand(int seed);
int abs(int);
long labs(long);
void* memcpy(void* dst, const void* src, unsigned int length);
void* memmove(void* dst, const void* src, unsigned int length);
void* memset(void* dst, int value, unsigned int length);
unsigned int strlen(const char* str);
char* strcpy(char* dst, const char* src);
char* strncpy(char* dst, const char* src, unsigned int count);
char* strcat(char* dst, const char* src);
int strcmp(const char* lhs, const char* rhs);
int strncmp(const char* lhs, const char* rhs, unsigned int count);
char* strchr(const char* str, int ch);
char* strrchr(const char* str, int ch);
char* strstr(const char* str, const char* substr);
int sprintf(char* buffer, const char* format, ...);
}
#define offsetof(type,member) ((unsigned int)(&((type*)0)->member))
typedef unsigned long long uint64_t;
typedef signed long long int64_t;
typedef unsigned int uint32_t;
typedef signed int int32_t;
typedef unsigned short uint16_t;
typedef signed short int16_t;
typedef unsigned char uint8_t;
typedef char int8_t;
typedef unsigned int uintptr_t;
typedef signed int intptr_t;
typedef unsigned int size_t;
#define INLINE_MEMCPY(to,from,size) { int i; unsigned char* dst; const unsigned char* src; i = (size); src = (const unsigned char*)(from); dst = (unsigned char*)(to); do { i--; *dst = *src; dst++; src++; } while (i != 0); }
#define INLINE_MEMCPY_4(to,from,size) { int i; unsigned int* dst; const unsigned int* src; i = (size); src = (const unsigned int*)(from); dst = (unsigned int*)(to); do { i -= 4; *dst = *src; dst++; src++; } while (i != 0); }
#define COPY_ARRAY(dst,src) INLINE_MEMCPY(dst, src, sizeof(dst))
typedef int32_t fix32_t;
typedef int16_t fix16_t;
#define FIX32_MULTIPLY(a,b) (fix32_t)((((int64_t)(a) * (int64_t)(b)) + (int64_t)0x800) >> (int64_t)12)
#define FIX32_MULTIPLY_SIMPLE(a,b) (fix32_t)(((int64_t)(a) * (int64_t)(b)) >> 12)
#define FIX32_MULTIPLY_v2(a,b) ((((int64_t)(unsigned int)(b) * (int64_t)(a))) >> (int64_t)12)
#define FIX32_MULTIPLY_v3(a,b) ((((int64_t)(b) * (int64_t)(a))) >> (int64_t)12)
#define FIX32_MULTIPLY_v4(a,b) ((((int64_t)(unsigned)(b) * (int64_t)(signed)(a))) >> (int64_t)12)
typedef struct Vector3i
{
    int32_t x;
    int32_t y;
    int32_t z;
} Vector3i;
typedef struct Vector3s
{
    int16_t x;
    int16_t y;
    int16_t z;
} Vector3s;
typedef Vector3i Vector3fix;
typedef Vector3s Vector3fix16;
#define FIX_2PI 0x6488
typedef union Matrix3x3
{
    Vector3fix rows[3];
    fix32_t entries[9];
} Matrix3x3;
typedef union Matrix4x3
{
    Vector3fix rows[4];
    fix32_t entries[12];
    struct {
        Matrix3x3 rotation;
        Vector3fix translation;
    };
} Matrix4x3;
typedef union Vector4fix
{
    fix32_t entries[4];
    Vector3fix xyz;
    struct {
        fix32_t x;
        fix32_t y;
        fix32_t z;
        fix32_t w;
    };
};
typedef union Matrix4x4
{
    fix32_t entries[16];
    Vector4fix rows[4];
} Matrix4x4;
extern "C"
{
    void Mat3x3_WriteIdentity(Matrix3x3* out);
    void Mat3x3_ApplyScale(const Matrix3x3* in, Matrix3x3* out, fix32_t x, fix32_t y, fix32_t z);
    void Mat3x3_WriteRotationX(Matrix3x3* out, fix32_t sine, fix32_t cosine);
    void Mat3x3_WriteRotationY(Matrix3x3* out, fix32_t sine, fix32_t cosine);
    void Mat3x3_WriteRotationZ(Matrix3x3* out, fix32_t sine, fix32_t cosine);
    int Mat3x3_Invert(const Matrix3x3* in, Matrix3x3* out);
    void Mat3x3_Multiply(const Matrix3x3* inA, const Matrix3x3* inB, Matrix3x3* out);
    void Mat3x3_ApplyToVector(const Vector3fix* inVec, const Matrix3x3* inMat, Vector3fix* out);
    void Mat4x3_WriteIdentity(Matrix4x3* out);
    void Mat4x3_ConvertTo4x4(const Matrix4x3* in, Matrix4x4* out);
    void Mat4x3_ApplyTranslation(const Matrix4x3* in, Matrix4x3* out, fix32_t x, fix32_t y, fix32_t z);
    void Mat4x3_ApplyScale(const Matrix4x3* in, Matrix4x3* out, fix32_t x, fix32_t y, fix32_t z);
    void Mat4x3_WriteRotationX(Matrix4x3* out, fix32_t sine, fix32_t cosine);
    void Mat4x3_WriteRotationY(Matrix4x3* out, fix32_t sine, fix32_t cosine);
    void Mat4x3_WriteRotationZ(Matrix4x3* out, fix32_t sine, fix32_t cosine);
    int Mat4x3_Invert(const Matrix4x3* in, Matrix4x3* out);
    void Mat4x3_Multiply(const Matrix4x3* inA, const Matrix4x3* inB, Matrix4x3* out);
    void Mat4x3_ApplyToVector(const Vector3fix* inVec, const Matrix4x3* inMat, Vector3fix* out);
    void Mat4x3_WriteViewMatrix(const Vector3fix* eye, const Vector3fix* up, const Vector3fix* target, Matrix4x3* out);
    void Mat4x4_WriteIdentity(Matrix4x4* out);
    void Mat4x4_ConvertTo4x3(const Matrix4x4* in, Matrix4x3* out);
    void Mat4x4_Multiply(const Matrix4x4* inA, const Matrix4x4* inB, Matrix4x4* out);
    void Mat4x4_MaybeWriteFrustum(fix32_t a, fix32_t b, fix32_t c, fix32_t d, fix32_t e, fix32_t f, Matrix4x4* out);
    void Mat4x4_WriteProjectionUnknown(fix32_t a, fix32_t b, fix32_t c, fix32_t d, fix32_t e, fix32_t f, fix32_t g, Matrix4x4* out);
    fix32_t fix32_Divide(fix32_t num, fix32_t denom);
    fix32_t fix32_Sqrt(fix32_t x);
    int64_t GetHardwareDividerResult();
    fix32_t fix32_GetDivisionResult();
    void fix32_QueueComputeReciprocal(fix32_t x);
    fix32_t fix32_GetSqrtResult();
    void fix32_QueueComputeQuotient(fix32_t num, fix32_t denom);
    int32_t FastIntDivide(int32_t a, int32_t b);
    int32_t FastIntModulus(int32_t a, int32_t b);
    void Vector3fix_Add(const Vector3fix* a, const Vector3fix* b, Vector3fix* out);
    void Vector3fix_Subtract(const Vector3fix* a, const Vector3fix* b, Vector3fix* out);
    fix32_t Vector3fix_InnerProduct(const Vector3fix* a, const Vector3fix* b);
    void Vector3fix_CrossProduct(const Vector3fix* a, const Vector3fix* b, Vector3fix* out);
    fix32_t Vector3fix_Length(const Vector3fix* vec);
    void Vector3fix_Normalize(const Vector3fix* in, Vector3fix* out);
    fix32_t Vector3fix_Distance(const Vector3fix* a, const Vector3fix* b);
    fix32_t fix32_Atan2(fix32_t y, fix32_t x);
    fix32_t fix32_Atan2_Rescaled(fix32_t y, fix32_t x);
}
fix32_t fix32sin(fix32_t x);
fix32_t fix32cos(fix32_t x);
fix32_t fix32SignedAngleDistance(fix32_t a, fix32_t b);
fix32_t fix32abs(fix32_t x);
Matrix4x3 RotationMatrixX(fix32_t angle);
Matrix4x3 RotationMatrixY(fix32_t angle);
Matrix4x3 RotationMatrixZ(fix32_t angle);
void Vector3fixMultiplyScalar(const Vector3fix* in, fix32_t scalar, Vector3fix* out);
void Vector3fixMultiply(const Vector3fix* a, const Vector3fix* b, Vector3fix* out);
void Vector3fixDivideScalar(const Vector3fix* in, fix32_t scalar, Vector3fix* out);
fix32_t fix32ReduceAngle0To2Pi(fix32_t angle);
fix32_t Vector3fixSquaredDistance(const Vector3fix* a, const Vector3fix* b);
fix32_t Vector3fixAngleToPoint(const Vector3fix* source, const Vector3fix* target);

#define ARM _Pragma("thumb off")
#define THUMB _Pragma("thumb on")
#define NULL 0
#define SIGNATURE_NSBMD 0x30444d42
#define SIGNATURE_NSBTX 0x30585442
#define SIGNATURE_NSBCA 0x30414342
#define SIGNATURE_NSBTP 0x30505442
#define SIGNATURE_NSBTA 0x30415442
#define SIGNATURE_NSBMA 0x30414d42
#define SIGNATURE_NSBVA 0x30415642
struct NSBXXContainer
{
    uint32_t signature_;
    uint16_t byteOrderMark_;
    uint16_t version_;
    uint32_t fileSize_;
    uint16_t headerSize_;
    uint16_t numSubfiles_;
};
struct NSBXXNameList
{
    uint8_t unknown_0_;
    uint8_t numEntries_;
    uint16_t totalSize_;
    uint16_t subheaderSize_;
    uint16_t offsetToDataStart_;
    struct SearchTreeEntry
    {
        uint8_t bitIndex_;
        uint8_t children_[2];
        uint8_t resourceIndex_;
    } treeRoot_8_;
    template<class T>
    inline T* GetEntryByIndex(unsigned int n) const volatile
    {
        if (this != 0 && n < numEntries_)
        {
            intptr_t dataStart = (intptr_t)this + offsetToDataStart_;
            uint16_t stride = *(uint16_t*)dataStart;
            return (T*)(dataStart + 4 + stride * n);
        }
        return 0;
    }
    template<class T>
    inline T* GetEntryByIndex_notVolatile(unsigned int n) const
    {
        if (this != 0 && n < numEntries_)
        {
            intptr_t dataStart = (intptr_t)this + offsetToDataStart_;
            uint16_t stride = *(uint16_t*)dataStart;
            return (T*)(dataStart + 4 + stride * n);
        }
        return 0;
    }
    template<class T>
    inline T* GetEntryFromu32Offset(unsigned int n) const
    {
        uint32_t* pOffset = GetEntryByIndex_notVolatile<uint32_t>(n);
        if (pOffset != 0)
            return (T*)((intptr_t)this + *pOffset);
        return 0;
    }
    template<class T>
    inline T* GetEntryFromu32Offset_v2(unsigned int n) const
    {
        if (this != 0)
        {
            uint32_t* pOffset = GetEntryByIndex_notVolatile<uint32_t>(n);
            if (pOffset != 0)
                return (T*)((intptr_t)this + *pOffset);
        }
        return 0;
    }
    inline const char* GetNameByIndexAndOffset(unsigned int n, unsigned int offsetInBuffer) const
    {
        if (this != 0 && n < numEntries_)
        {
            intptr_t dataStart = (intptr_t)this + offsetToDataStart_;
            intptr_t nameStart = dataStart + *(uint16_t*)(dataStart + 2);
            return (const char*)(nameStart + offsetInBuffer);
        }
        return 0;
    }
};
struct NSBXXInnerFileCommon {
    uint32_t signature;
    uint32_t fileSize;
    NSBXXNameList nameList;
};
struct NSBXXBoneMatrix
{
    uint16_t flags_;
    fix16_t m_11;
    struct Translation
    {
        fix32_t x;
        fix32_t y;
        fix32_t z;
    };
    struct PivotMatrixData
    {
        fix16_t a;
        fix16_t b;
    };
    struct RotationMatrixData
    {
        fix16_t entries[8];
    };
    struct Scaling
    {
        fix32_t x;
        fix32_t y;
        fix32_t z;
        fix32_t x_v2;
        fix32_t y_v2;
        fix32_t z_v2;
    };
};
struct NSBXXAnimationSignature
{
    uint8_t signatureInitial_;
    uint8_t signatureNull_;
    uint16_t signatureEnd_;
};
struct NSBXXAnimationJAC
{
    NSBXXAnimationSignature signature_;
    uint16_t numFrames_;
    uint16_t numTracks_;
    uint32_t unk_8;
    uint32_t pivotDataOffset_;
    uint32_t basisMatricesOffset_;
    uint16_t trackOffsets_[1];
    struct Track
    {
        uint32_t flagsAndTargetBoneMatrix_;
        struct ChannelNonConst
        {
            uint32_t metadata_;
            uint32_t samplesOffset_;
        };
    };
    struct ScaleSample16
    {
        fix16_t primary_;
        fix16_t secondary_;
    };
    struct ScaleSample32
    {
        fix32_t primary_;
        fix32_t secondary_;
    };
    struct PivotMatrix
    {
        int16_t flags;
        fix16_t a;
        fix16_t b;
    };
    struct BasisMatrix
    {
        int16_t data[5];
    };
    inline PivotMatrix* GetPivotMatrices() const
    {
        return (PivotMatrix*)((intptr_t)this + this->pivotDataOffset_);
    }
    inline BasisMatrix* GetBasisMatrices() const
    {
        return (BasisMatrix*)((intptr_t)this + this->basisMatricesOffset_);
    }
};
struct NSBXXAnimationMAM
{
    NSBXXAnimationSignature signature_;
    uint16_t unk_4;
    uint16_t unk_6;
    NSBXXNameList tracks_;
    struct Track
    {
        uint32_t diffuse_;
        uint32_t ambient_;
        uint32_t reflection_;
        uint32_t emission_;
        uint32_t alpha_;
    };
};
struct NSBXXAnimationMAT
{
    NSBXXAnimationSignature signature_;
    uint16_t unk_4;
    uint16_t unk_6;
    NSBXXNameList tracks_;
    struct Track
    {
        uint32_t unk_0;
        uint32_t unk_4;
        uint32_t unk_8;
        uint32_t unk_c;
        uint32_t unk_10;
        uint32_t unk_14;
        uint32_t unk_18;
        uint32_t unk_1c;
        uint32_t unk_20;
        uint32_t unk_24;
    };
};
struct NSBXXAnimationMPT
{
    NSBXXAnimationSignature signature_;
    uint16_t numFrames_;
    uint8_t numTextureNames_;
    uint8_t numPaletteNames_;
    uint16_t textureNamesOffset_;
    uint16_t paletteNamesOffset_;
    NSBXXNameList tracks_;
    struct Track
    {
        uint16_t numKeyframes_;
        uint16_t unk_2;
        int16_t maybeSpeed_4_;
        uint16_t keyframeArrayOffset_;
        struct Keyframe
        {
            uint16_t frameTime_;
            uint8_t textureIdx_;
            uint8_t paletteIdx_;
        };
    };
};
struct NSBXXAnimationVAV
{
    char unk_0[6];
    unsigned short numConditions_;
    char unk_8[4];
    uint32_t bitfield_[1];
};
struct ModelBoundingBox
{
    int16_t xMin_;
    int16_t yMin_;
    int16_t zMin_;
    int16_t xSize_;
    int16_t ySize_;
    int16_t zSize_;
};
struct NSBXXMaterial
{
    uint16_t unk_0;
    uint16_t size_;
    uint32_t paramDIF_AMB_;
    uint32_t paramSPE_EMI_;
    uint32_t paramPOLYGON_ATTR_;
    uint32_t maskPOLYGON_ATTR_;
    uint32_t paramTEXIMAGE_PARAMS_;
    uint32_t unk_18;
    uint16_t texturePaletteVRAMOffset_;
    uint16_t flags_;
    uint16_t width_;
    uint16_t height_;
    fix32_t xScale_;
    fix32_t yScale_;
    struct ExtensionData_Bit1
    {
        fix32_t scaleX_;
        fix32_t scaleY_;
    };
    struct ExtensionData_Bit2
    {
        fix16_t sine_;
        fix16_t cosine_;
    };
    struct ExtensionData_Bit3
    {
        uint32_t translateX_;
        uint32_t translateY_;
    };
    struct ExtensionData_Bit13
    {
        Matrix4x4 matrix_;
    };
};
struct NSBXXModelMaterialData
{
    uint16_t texturePairingsOffset_;
    uint16_t palettePairingsOffset_;
    NSBXXNameList materialOffsetList_;
    inline struct NSBXXMaterial* GetMaterialByIndex(unsigned int n) const
    {
        if (this != 0)
        {
            uint32_t* materialOffset = materialOffsetList_.GetEntryByIndex<uint32_t>(n);
            if (materialOffset != 0)
            {
                return (NSBXXMaterial*)((intptr_t)this + *materialOffset);
            }
        }
        return 0;
    }
};
struct NSBXXMaterialPairing
{
    uint16_t offsetToIndexArray_;
    uint8_t arraySize_;
    uint8_t flags_;
};
struct NSBXXMesh
{
    uint16_t unk_0;
    uint16_t size_;
    uint32_t unk_4;
    uint32_t gpuCommandsOffset_;
    uint32_t gpuCommandsLength_;
    inline const uint32_t* GetGPUCommands() const
    {
        return (uint32_t*)((intptr_t)this + gpuCommandsOffset_);
    }
};
struct NSBXXInvBindMatrix
{
    Matrix4x3 mat4x3;
    Matrix3x3 mat3x3;
};
struct NSBXXInternalModel
{
    uint32_t filesize_;
    uint32_t renderCommandsOffset_;
    uint32_t materialsOffset_;
    uint32_t meshesOffset_;
    uint32_t inverseBindsOffset_;
    uint8_t unk_14;
    uint8_t boneScalingMode_;
    uint8_t materialCallbackType_;
    uint8_t numBoneMatrices_;
    uint8_t numMaterials_;
    uint8_t numMeshes_;
    uint8_t unk_1a[2];
    fix32_t upScale_;
    fix32_t downScale_;
    uint16_t numVertices_;
    uint16_t numPolygons_;
    uint16_t numTriangles_;
    uint16_t numQuads_;
    ModelBoundingBox bounds_;
    int32_t maybeScale_;
    char unk_3c[4];
    NSBXXNameList boneList_;
    inline NSBXXModelMaterialData* GetMaterialData() const
    {
        if (this != 0 && materialsOffset_ != 0)
            return (NSBXXModelMaterialData*)((intptr_t)this + materialsOffset_);
        else
            return 0;
    }
    inline NSBXXNameList* GetMeshList() const
    {
        if (this != 0 && meshesOffset_ != 0)
            return (NSBXXNameList*)((intptr_t)this + meshesOffset_);
        return 0;
    }
    inline NSBXXMesh* GetMesh(unsigned int n) const
    {
        NSBXXNameList* meshList;
        if (this != 0 && meshesOffset_ != 0)
            meshList = (NSBXXNameList*)((intptr_t)this + meshesOffset_);
        else
            meshList = 0;
        if (meshList != 0)
        {
            return meshList->GetEntryFromu32Offset<NSBXXMesh>(n);
        }
        return 0;
    }
};
struct NSBXXMdl
{
    uint32_t signature_;
    uint32_t unknown_4;
    NSBXXNameList nameList_;
    NSBXXInternalModel* GetInternalModelByIndex(unsigned int n) const
    {
        NSBXXInternalModel* internalModel;
        if (this != 0)
        {
            uint32_t* pModelOffset = nameList_.GetEntryByIndex<uint32_t>(n);
            if (pModelOffset != 0)
            {
                internalModel = (NSBXXInternalModel*)((intptr_t)this + *pModelOffset);
                return internalModel;
            }
        }
        return 0;
    }
};
struct NSBXXTex
{
    uint32_t signature;
    uint32_t maybeTotalSize_4_;
    uint32_t block1VRAMLoadOffset_;
    uint16_t block1NumEightBytes_;
    uint16_t textureListOffset_;
    uint16_t maybeBlock1Flags_10_;
    char padding_12[2];
    uint32_t block1Offset_;
    uint32_t block2Or3VRAMLoadOffset_;
    uint16_t block2NumEightBytes_;
    uint16_t unk_1e;
    uint16_t maybeBlock23Flags_20_;
    char padding_22[2];
    uint32_t block2Offset_;
    uint32_t block3Offset_;
    uint32_t block4VRAMLoadOffset_;
    uint16_t block4NumEightBytes_;
    uint16_t maybeBlock4Flags_32_;
    uint16_t paletteListOffset_;
    uint16_t unk_36;
    uint32_t block4Offset_;
    NSBXXNameList textureList_;
    inline NSBXXNameList* GetPaletteList() const
    {
        if (this != 0 && paletteListOffset_ != 0)
            return (NSBXXNameList*)((intptr_t)this + paletteListOffset_);
        else
            return 0;
    }
};
struct NSBXXTexTexture
{
    uint32_t paramTEXIMAGE_PARAMS_;
    uint32_t unk_4;
};
struct NSBXXTexPalette
{
    uint16_t offsetWithinBlock4_;
    uint16_t unk_2;
};
extern "C"
{
int NSBXX_Tex_GetBlock1Length(NSBXXTex* tex);
int NSBXX_Tex_GetBlock2Length(NSBXXTex* tex);
void NSBXX_Tex_WriteImageVRAMOffsets(NSBXXTex* tex, int block1, int block2_3);
void NSBXX_Tex_LoadImageToVRAM(NSBXXTex* tex, bool needsMapping);
int NSBXX_Tex_GetBlock4Length(NSBXXTex* tex);
void NSBXX_Tex_WritePaletteVRAMOffset(NSBXXTex* tex, int offset);
void NSBXX_Tex_LoadPaletteToVRAM(NSBXXTex* tex, bool needsMapping);
bool NSBXX_AttachTextureImageToModel(NSBXXInternalModel* model, NSBXXTex* tex0);
void NSBXX_DetachTextureImageFromModel(NSBXXInternalModel* model);
bool NSBXX_AttachTexturePaletteToModel(NSBXXInternalModel* model, NSBXXTex* tex0);
void NSBXX_DetachTexturePaletteFromModel(NSBXXInternalModel* model);
int NSBXX_LinkTEX0ToMDL0(NSBXXMdl* mdl0, NSBXXTex* tex0);
void NSBXX_UnlinkTEX0FromMDL0(NSBXXMdl* mdl0);
void NSBXX_Model_DrawShadow(NSBXXInternalModel* model, unsigned int arg_2, unsigned int arg_3, unsigned int arg_4);
struct AnimationData* NSBXX_Model_AllocateAnimationData(class AllocatorUnion* alloc, const void* rawAnim, NSBXXInternalModel* model);
void NSBXX_Model_SetAllMaterialFlags(NSBXXInternalModel* model, int value, unsigned int mask);
void NSBXX_Model_SetMaterialAlpha(NSBXXInternalModel* model, unsigned int materialIndex, int alpha);
int NSBXX_Model_GetMaterialPolygonID(NSBXXInternalModel* model, unsigned int materialIndex);
void NSBXX_Model_SetDiffuseReflectionColor(NSBXXInternalModel* model, int rgb);
void NSBXX_Model_SetAlpha(NSBXXInternalModel* model, int alpha);
void* NSBXXNameList_Search(NSBXXNameList* nameList, const char* name);
int NSBXXNameList_SearchIndex(NSBXXNameList* nameList, const char* name);
void* NSBXX_GetFirstSubfile(NSBXXContainer* nsbxx);
NSBXXTex* NSBXX_GetTEXFile(NSBXXContainer* nsbxx);
void* NSBXX_GetObjectFromFirstSubfile(NSBXXContainer* nsbxx, unsigned int idx);
const char* NSBXX_PatternAnimation_GetTextureName(NSBXXAnimationMPT* anim, unsigned int idx);
const char* NSBXX_PatternAnimation_GetPaletteName(NSBXXAnimationMPT* anim, unsigned int idx);
NSBXXAnimationMPT::Track::Keyframe* NSBXX_PatternAnimation_GetKeyframe(NSBXXAnimationMPT*, uint16_t track, uint16_t frameTime);
NSBXXAnimationMPT::Track* NSBXX_PatternAnimation_GetTrack(NSBXXAnimationMPT*, unsigned int track);
}
struct RenderCommandHandler;
typedef void (*RenderCommandHook)(RenderCommandHandler*);
struct BoneMatrixRenderData
{
    union Scale
    {
        struct {
            fix32_t x; fix32_t y; fix32_t z;
        };
        fix32_t array[3];
    };
    unsigned int flags_;
    Scale scale_v0_;
    Scale scale_v1_;
    Scale scale_v2_;
    Matrix3x3 rotationMatrix_;
    Vector3fix translate_;
};
struct MaterialRenderData
{
    unsigned int flags_;
    unsigned int paramDIF_AMB_;
    unsigned int paramSPE_EMI_;
    unsigned int paramPOLYGON_ATTR_;
    unsigned int paramTEXIMAGE_PARAMS_;
    unsigned int texturePaletteBase_;
    fix32_t extensionScaleX_;
    fix32_t extensionScaleY_;
    fix16_t rotationSine_;
    fix16_t rotationCosine_;
    fix32_t translateX_;
    fix32_t translateY_;
    unsigned short materialWidth_;
    unsigned short materialHeight_;
    fix32_t materialxScale_;
    fix32_t materialyScale_;
};
struct AnimationData;
struct ModelRenderContext
{
    unsigned int flags_;
    NSBXXInternalModel* internalModel_;
    AnimationData* materialAnimations_;
    bool (*pfnProcessMaterialAnimations_)(MaterialRenderData*, AnimationData*, unsigned int);
    AnimationData* jointAnimations_;
    bool (*pfnProcessJointAnimations_)(BoneMatrixRenderData*, AnimationData*, unsigned int);
    AnimationData* visibilityAnimations_;
    bool (*pfnProcessVisibilityAnimations_)(int*, AnimationData*, unsigned int);
    void (*renderCommandHook_)(RenderCommandHandler*);
    unsigned char renderCommandHookCommandID_;
    unsigned char renderCommandHookStage_;
    char padding_26[2];
    void (*preRenderCallback_)(RenderCommandHandler*);
    char unk_2c[4];
    uint8_t* renderCommandList_;
    BoneMatrixRenderData* boneMatrixRenderDataArray_;
    MaterialRenderData* materialRenderDataArray_;
    unsigned int animatedMaterials_[2];
    unsigned int animatedBoneMatrices_[2];
    unsigned int animatedVisibilityConditions_[2];
};
struct RenderCommandHandler
{
    uint8_t* instructionPointer_;
    ModelRenderContext* modelContext_;
    unsigned int flags_;
    RenderCommandHook hooks_[32];
    unsigned char hookStages_[32];
    unsigned char command2Arg1_;
    unsigned char boundMaterial_;
    unsigned char currentBoneMatrix_;
    char padding_af;
    MaterialRenderData* pMaterialRenderData_;
    BoneMatrixRenderData* pBoneMatrixRenderData_;
    int* pCommand2Word_;
    unsigned int materialBitfield_[2];
    unsigned int boneMatrixBitfield_[2];
    unsigned int invBindBitfield_[2];
    NSBXXNameList* boneList_;
    NSBXXModelMaterialData* modelMaterials_;
    NSBXXNameList* meshList_;
    fix32_t upScale_;
    fix32_t downScale_;
    void (*boneMatrixRenderDataScalePopulateProc_)(BoneMatrixRenderData*, NSBXXBoneMatrix::Scaling* boneMatrixScaleData, uint8_t* ip, int boneMatrixFlags);
    void (*boneMatrixRenderDataSubmitProc_)(BoneMatrixRenderData*);
    void (*textureMatrixCreateProc_)(MaterialRenderData*);
    MaterialRenderData scratchMaterialRenderData_;
    BoneMatrixRenderData scratchBoneMatrixRenderData_;
    int scratchCommand2Word_;
};
#define RCH_FLAG_0 0
#define RCH_FLAG_1 1
#define RCH_FLAG_2 2
#define RCH_FLAG_3 3
#define RCH_FLAG_4 4
#define RCH_FLAG_5 5
#define RCH_FLAG_6 6
#define RCH_FLAG_7 7
#define RCH_FLAG_8 8
#define RCH_FLAG_9 9
#define RCH_FLAG_10 10
void RenderModelFromRenderData(ModelRenderContext* renderData);
void RenderMeshWithMaterial(NSBXXInternalModel* model, unsigned int materialIdx, unsigned int meshIdx, int bindMaterial);
struct AnimationData
{
    typedef void (*Callback)(void*, AnimationData*, int);
    fix32_t time_;
    fix32_t weight_;
    void* pRawData_;
    void (*callback_)(void* renderData, AnimationData* animData, int arg);
    AnimationData* pNext_;
    NSBXXTex* pTex0_;
    unsigned char unk_18;
    unsigned char numEntries_;
    unsigned short entries_[64];
};
void InitializeModelAnimation(AnimationData* anim, void* pRawData, NSBXXInternalModel* model, NSBXXTex* tex);
void PopulateModelRenderContext(ModelRenderContext* context, NSBXXInternalModel* model);
void AddAnimationsToModelRenderContext(ModelRenderContext* context, AnimationData* anim);
void RemoveAnimationFromModelRenderContext(ModelRenderContext* context, AnimationData* anim);
void SetModelRenderContextRenderCommandHook(ModelRenderContext* context, RenderCommandHook hook, int unknown, int commandID, int stage);
bool ProcessMaterialAnimationsOnBoundMaterial(MaterialRenderData* material, AnimationData* anim, unsigned int matIdx);
bool ProcessJointAnimationsOnBoneMatrix(BoneMatrixRenderData* bone, AnimationData* anim, unsigned int boneIdx);
bool ProcessVisibilityAnimations(int* output, AnimationData* anim, unsigned int boneIdx);
#define ALLOCATOR_SIGNATURE_HPXE 0x45585048
#define ALLOCATOR_SIGNATURE_HMRF 0x46524d48
#define ALLOCATOR_SIGNATURE_HTNU 0x554e5448

struct SignedAllocatorHeader;

class SignedAllocatorList
{
public:
    SignedAllocatorHeader* pFirst;
    SignedAllocatorHeader* pLast;
    unsigned short numElements;
    unsigned short signatureLength;

    void Initialize(unsigned short signatureLength);
    void DoInitialInsertion(SignedAllocatorHeader* what);

    void InsertAtEnd(SignedAllocatorHeader* what);
    void InsertAtStart(SignedAllocatorHeader* what);
    void InsertBefore(SignedAllocatorHeader* where, SignedAllocatorHeader* what);
    void Remove(SignedAllocatorHeader* what);

    SignedAllocatorHeader* ElementAfter(SignedAllocatorHeader* what);
    SignedAllocatorHeader* ElementBefore(SignedAllocatorHeader* what);

    SignedAllocatorHeader* GetNthElement(unsigned int n);
};

struct SignedAllocatorHeader
{
    unsigned int signature;
    SignedAllocatorHeader* pPrevAllocator;
    SignedAllocatorHeader* pNextAllocator;
    SignedAllocatorList children;
    void* allocBegin;
    void* allocEnd;
    int clearFlags;
};

class HMRFAllocator
{
public:
    struct SavedState
    {
        int id;
        unsigned int startAddress;
        unsigned int endAddress;
        SavedState* pPrev;
    };

    struct Block
    {
        unsigned int startAddress;
        unsigned int endAddress;

        void* AllocateForward(unsigned int len, unsigned int alignment);
        void* AllocateBackward(unsigned int len, unsigned int alignment);
    };
public:
    SignedAllocatorHeader header;
    Block block;
    SavedState* newestState;

    static HMRFAllocator* CreateInRegion(void* start, void* end, unsigned short clearFlags);

    void FreeFront();
    void FreeBack();

    static HMRFAllocator* CreateAtLocation(void* where, unsigned int size, unsigned short clearFlags);
    void RemoveFromTree();

    void* Allocate(unsigned int len, int alignAndDirection);
    void Free(int flags);

    unsigned int GetMaxPossibleAllocation(int alignAndDir);

    bool SaveCurrentState(int id);
    bool RestoreState(int id);
};

class HPXEAllocator
{
public:
    struct Block
    {
        unsigned short signature;
        unsigned short coalescenceData;
        unsigned int size;
        Block* pPrev;
        Block* pNext;
    };

    struct BlockList
    {
        Block* pFirst;
        Block* pLast;

        Block* RemoveAndGetPrevious(Block* block);
        Block* InsertAfter(Block* newBlock, Block* previous);
    };

    struct MemoryRangeDescription
    {
        unsigned int beginAddr;
        unsigned int endAddr;

        void PopulateFromBlock(Block* block);
        Block* CreateBlock(unsigned short signature);
    };

    struct BlockManager
    {
        BlockList freeBlocks;
        BlockList usedBlocks;
        unsigned short unknown_34;
        unsigned short blockSelectFlags;

        void* AllocateFromFreeBlock(Block* freeNode, unsigned int effStart, unsigned int length, unsigned short reversed);
        bool FreeMemoryRange(const MemoryRangeDescription& range);
    };

public:
    SignedAllocatorHeader header;
    BlockManager blocks;

private:
    static HPXEAllocator* CreateInRegion(void* start, void* end, unsigned short clearFlags);

    void* AllocateFromFront(unsigned int len, unsigned int align);
    void* AllocateFromEnd(unsigned int len, unsigned int align);

public:
    static HPXEAllocator* CreateAtLocation(void* where, unsigned int size, unsigned short clearFlags);
    void RemoveFromTree();

    void* Allocate(unsigned int len, int alignAndDir);
    void Free(void* data);

    unsigned int GetMaxPossibleAllocation(int alignAndDir);
};

namespace AllocatorTree
{
    SignedAllocatorHeader* GetParent(SignedAllocatorList* searchTree, SignedAllocatorHeader* alloc);

    SignedAllocatorList* GetListContainingAllocator(SignedAllocatorHeader* allocator);

    void InsertNewAndPopulateHeader(SignedAllocatorHeader* allocator, unsigned int sig,
        void* allocBegin, void* allocEnd, unsigned short clearFlags);
    void Remove(SignedAllocatorHeader* alloc);

}
class UnusedSignedAllocator
{
public:
    struct Block
    {
        Block* pNext;
    };

    SignedAllocatorHeader header;
    Block* pFirstAvailableBlock;
    unsigned int blockSize;

private:
    static Block* PopFrontAndUpdate(Block** ppBlock);

public:
    void* Allocate();
    void Free(void* data);
};
struct AllocatorBase
{
    struct VTable
    {
        typedef void* (*PFNAllocate)(AllocatorBase*, unsigned int);
        typedef void (*PFNFree)(AllocatorBase*, void*);

        PFNAllocate allocate;
        PFNFree free;
    };

    const VTable* pVTable;
};

struct AllocatorTypeUnused : public AllocatorBase
{
    UnusedSignedAllocator* pSignedAllocator;

    static void* Allocate(AllocatorBase* base, unsigned int len);
    static void Free(AllocatorBase* base, void* data);

    static const VTable s_vtable;
};

struct AllocatorTypeA : public AllocatorBase
{
    HMRFAllocator* pHMRFAllocator;
    int alignmentAndDir;
    int unknown;

    static void* Allocate(AllocatorBase* base, unsigned int len);
    static void Free(AllocatorBase* base, void* data);

    static const VTable s_vtable;
};

struct AllocatorTypeB : public AllocatorBase
{
    HPXEAllocator* pHPXEAllocator;
    int alignmentAndDir;
    int unknown;

    static void* Allocate(AllocatorBase* base, unsigned int len);
    static void Free(AllocatorBase* base, void* data);

    static const VTable s_vtable;
};

class AllocatorUnion
{
public:
    union
    {
        AllocatorBase base;
        AllocatorTypeA typeA;
        AllocatorTypeB typeB;
    } versions;

    void* Allocate(unsigned int len);
    void Free(void* data);

    void InitializeTypeB(HPXEAllocator* pAlloc, int alignAndDir);
    void InitializeTypeA(HMRFAllocator* pAlloc, int alignAndDir);
};

class SafeAllocator
{
public:
    SignedAllocatorHeader* pSignedAlloc;
    AllocatorUnion allocUnion;

    static unsigned int GetLiveCount();

    void ResetAllocatorPointer();

    void CreateTypeB(void* bufferStart, unsigned int bufferSize, int alignAndDir);
    void CreateTypeA(void* bufferStart, unsigned int bufferSize);

    void* Allocate(unsigned int len);
    void* AllocateReversed(unsigned int len);

    void Free(void* data);

    void Reset();

    void Destroy();

    unsigned int GetSize() const;

    unsigned int GetMaxPossibleAllocation() const;

    unsigned int GetSizeWithLargestBlockRemoved() const;

    SignedAllocatorHeader* GetSignedAllocator() const;
};
void SetOrClearBitInArray(void *obj, unsigned char *arr, int idx, int flag);
extern "C" void *func_0202ae18(void);
int CheckField0NonZero(int *ctx);
struct SearchStruct0202c1a4;
int GetSearchStructCurrentArrEntry(SearchStruct0202c1a4 *ctx);
extern "C" void func_ov017_021d0924(int a, int b, int p1, int flag);
extern "C" void _Z19ClearNibble0206ece8iiPhj(int a, int b, unsigned char *c, unsigned d);
extern "C" void *func_ov017_0218b5b0(void);
extern "C" int func_0202c508(void *ctx);
extern "C" void *func_02012fe4(void);
void *GetPointerFromArray0x3c(unsigned char *arr, unsigned idx);
struct AppendNode;
struct AppendList;
void AppendNodeToListField30(int a, AppendNode *msg, AppendList *list);
extern "C" void *_ZN9GameState11GetInstanceEv();
struct LightingManager {
    static LightingManager *GetInstance();
};
struct BattleStruct;
extern "C" int _ZNK9GameState11GetDayTimerEv(BattleStruct *battle);
extern "C" int _ZNK9GameState12GetTimeOfDayEv(BattleStruct *battle);
extern "C" void _ZN9GameState12SetTimeOfDayE9TimeOfDay(char *battle, int p1);
extern "C" void _Z27EnqueueEventTag147_021cdaa0v();
void *GetGlobal02109418(void);
extern "C" int func_020961b0(void *g, int p1);
int TestBitInByteArray(int obj, unsigned char *arr, int idx);
struct Struct020d9ae8;
extern "C" void _Z12Init020d9ae8P14Struct020d9ae8i(Struct020d9ae8 *node, int mode);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(TailList020469b4 *list, TailNode020469b4 *node);
extern "C" void func_0206e164(void *obj, int p1, int mode);
struct FindEntryById02096134Table;
extern "C" void *_Z21FindEntryById02096134P26FindEntryById02096134Tablei(FindEntryById02096134Table *table, int p1);
extern "C" void _Z24SetBitWithOffset0206eb64Phii(unsigned char *obj, int p2, int flag);
extern "C" void func_02018300(void *p0, void *node, int a, int b, int c);
extern "C" void func_ov017_021c1a98(void *ctx, int flag);
extern "C" void *_ZN9GameState20GetGameObjectByIndexEi(void *battle, int idx);
extern "C" void _Z18SetBitInArray0x8ecPhi(void *arr, int idx);
extern "C" void _Z18SetBitInArray0x910Phi(void *arr, int idx);
extern "C" void _Z27ToggleElemKey2FlagInMap2010i(int key);
extern "C" void _Z35SetElemFlag8IfOverlayActive020ae730i(int key);
extern "C" void _Z29SetElemFlag0x4PairAndNotify17i(int key);
extern "C" void _Z29SetElemFlag0x4QuadAndNotify17i(int key);
extern "C" void _ZN9GameState18SetDayTimerRunningEi(void *battle, int flag);
extern "C" void _Z31EnqueueEventTag23Field_021d0d58v();
extern "C" int _Z14ListContainsIdP16ListHead02046b60i(void *list, int id);
extern "C" void *func_ov017_021b8478(void *node);
extern "C" int _Z21IsField0xcNonNegativePi(void *p);
extern "C" void _Z20InitState60_021aa16cP11Obj021aa16c(void *node);
extern "C" void _Z17PrependNodeToHeadP16HeadList020469f8P16HeadNode020469f8(void *list, void *node);
extern "C" void _Z18Something_021a6b9cih(void *base, int flag);
extern "C" void *_Z27GetStatFieldPointer02064904Pvij(void *obj, int p1, int p2);
extern "C" void func_ov017_021a5568(void *node);
extern "C" void _Z26SetBytesAt20And21_021a55a4Phhh(void *node, int a, int b);
extern "C" void *_Z11GetBTRandomv();
extern "C" int _Z17NextRandomBetweenP6Randomii(void *rng, int lo, int hi);
extern "C" int _Z13NextRandomMaxP6Randomi(void *rng, int max);
extern short data_020e7de8[14];
extern "C" void *memmove(void *dst, const void *src, unsigned int n);
extern "C" void _Z27EnqueueEventTag142_021cd6d8P11Src021cd6d8(void *ev);
struct Src021cd6d8 {
    short f0, f1, f2, f3;
    unsigned char f4;
    short f5;
    signed char f6;
    int f7;
};
extern "C" void *_Z18GetField0x3b0ValueP9GameState(void *battle);
extern "C" void _Z33StoreFields0x1e4And0x1e8IfNonZeroPhii(void *rec, int a, int b);
extern "C" void _Z17SetFlag0x4At0x168Ph(void *rec);
extern "C" void _Z23ClearTwoWordsAndFlag0x4P21FlagsAndWords0202ea20(void *rec);
extern "C" void *_Z15GetData02108f0cv();
extern "C" void func_0202c288(void);
extern "C" void _Z29ResetFieldsToDefault_021b994cP12Obj_021b994c(void *rec);
extern "C" void _Z27EnqueueEventTag153_021d079chht(int a, int b, int c);
extern "C" void _Z36NotifyElemAndOverlay17OnFlag020ae990i(int key);
extern "C" void func_020aea40(int a, int b);
extern "C" void func_ov017_02191484(void *base);
extern "C" void _Z19ResetStruct020d3c08Pc(void *local);
extern "C" void _Z31InitAndMaybeStartStream020d3c28P11Obj020d3c28(void *local);
extern "C" void *_Z29GetElementCount0xb4Stride0x24Phi(void *local, int idx);
extern "C" void func_ov017_021913d0(void *base, int field);
struct ElemFlags3Bit0d3d78 { unsigned char field3 : 3; unsigned char rest : 5; };
extern int data_02108844;
extern "C" void _Z28ResetFieldGroup4444_0218b664Pc(void *base);
extern "C" void _Z27EnqueueEventTag154_021d0860hhh(int a, int b, int c);
extern "C" void _Z30SetFieldFromHelper491_02198f70Pvh(void *base, int b);
extern "C" void func_ov017_0219c520(void);
extern "C" void _Z25SetName56AndFlag_0218d7b0PhPc(void *base, void *local);
struct BitFlag17Entry { unsigned int pad : 17; unsigned int flag17 : 1; };

extern "C" int _Z20GetPackedNibbleFieldP25PackedNibbleArray0206e120i(void *arr, int idx);
extern "C" void _Z12Init020d9decP14Struct020d9deci(void *node, int mode);
extern "C" void _Z18SetFlagBit020d9fb4P9S020d9fb4i(void *node, int flag);
extern "C" void *_Z17GetPtrField0x2a04P9GameState(void *battle);
extern "C" int _Z17GetField5cb0ValuePc(void *p);
extern "C" int _Z17GetField5cb4ValuePc(void *p);
extern "C" int _Z17GetField5cb8ValuePc(void *p);
extern "C" void _Z20ClearRegions0206e080Pci(void *obj, int slot);
extern "C" void _Z31ClearIndexedEntryFields0206e0d0Pci(void *obj, int slot);
extern "C" void _Z24SetKeyedArrayBit0206e348Phii(void *obj, int p1, int flag);

#if defined(jpn)
#define REGION_VALUE(jpnValue, usaValue) jpnValue
#else
#define REGION_VALUE(jpnValue, usaValue) usaValue
#endif

struct CmdMsg64 { unsigned short cmd, p1, p2, p3, p4, p5; unsigned short rest[8]; };

struct FlagsField0x2e { unsigned short pad0x2e_lo : 4; unsigned short flagsHi : 12; };

extern "C" void func_020732cc(int p1);
extern "C" void _Z40SetHalfFieldsAndEnqueueIfActive_021d1c2ctt(unsigned short a, unsigned short b);
extern "C" void _Z26EnqueueEventTagB5_021d1dc0ssPisi(unsigned short a, short b, int *c, short d, int e);
extern AllocatorUnion data_02114e20;
void *AllocateAligned4(AllocatorUnion *alloc, unsigned int size);
extern "C" void _Z19TailForward02012da4P14AllocatorUnionPv(AllocatorUnion *alloc, void *data);
extern "C" void *func_02086f24(void *p, unsigned char b, SafeAllocator *alloc);
extern "C" void func_020aee04(unsigned short a, unsigned char b);
extern struct Str02109bf4 {
    char unk[0xc8];
    unsigned char low : 2;
    unsigned char foo : 1;
} data_02109bf4;
extern "C" void _Z27InitAndAppendEntity020dac40P12Root020dac40(void);
extern "C" void *_Z25GetCombatantWithFlag0x100P9GameStatei(void *battle, int idx);
extern "C" void *_Z15GetFieldAt0x150Ph(void *p);
extern "C" void _Z27RemoveSlotShiftDown0208386cP13Slots0208386ci(void *slots, int idx);
extern "C" void _Z25DecrementKeyValue020a0a08P14KeyMap020a0a08ii(void *map, int key, int amount);
extern "C" void _Z21SyncEightElementFlagsv(void);
extern "C" void _Z21RegisterSlotA020cf0fci(int p);
extern "C" void _Z21RegisterSlotB020cf1a8i(int p);
extern "C" void _Z23ApplySlotConfig02095cfcii(void *g, int idx);
extern "C" int func_0202c540(void *ctx);
extern "C" void *_ZN9GameState14GetProtagonistEv(void *battle);
extern "C" void _Z24CopyOutBattleField0x7ac0Pv(void *dst);
extern "C" void _Z23CopyHalfwordAndTwoBytesP19SmallRecord020643e0S0_(void *dst, void *src);
extern "C" int _Z22GetFieldPercentOver307P7S_a0870(void *p);
extern "C" int _Z22GetFieldPercentOver448P7S_a090c(void *p);
extern "C" int _Z22GetFieldPercentOver232P7S_a08a4(void *p);
extern "C" int _Z22GetFieldPercentOver944P7S_a08d8(void *p);

struct SnapshotE7 {
    unsigned char head[8];
    unsigned int a_lo : 17;
    unsigned int a_mid : 7;
    unsigned int a_hi : 7;
    unsigned int a_top : 1;
    unsigned int b_lo : 17;
    unsigned int b_mid : 7;
    unsigned int b_hi : 7;
    unsigned int b_top : 1;
    unsigned int c_lo : 9;
    unsigned int c_mid : 14;
    unsigned int c_top : 9;
    unsigned int d_lo : 8;
    unsigned int d_mid : 14;
    unsigned int d_hi : 10;
    unsigned int e_lo : 24;
    unsigned int done : 1;
    unsigned int e_top : 7;
    unsigned int total;
};
struct SrcWord44 { unsigned int v24 : 24; unsigned int hi8 : 8; };
struct SrcWord48 { unsigned int lo : 14; unsigned int v14 : 14; unsigned int hi : 4; };
struct SrcWord4c { unsigned int v9 : 9; unsigned int v14 : 14; unsigned int hi : 9; };
extern "C" void *_Z20GetGlobalPtr021075f4v(void);
extern "C" void *_Z29FindEntryPointerByKey0203df78Pvi(void *g, int key);
extern "C" void *_Z19GetField0xc02040538P9S02040538(void *entry);
extern "C" void _Z21RegisterSlotA020cf0fci(int p);
extern "C" int func_020ac2d4(int a, void *p1, void *p2, int flag);
extern "C" void func_020ac104(void *pooled, void *p1, int flag);
extern char data_0211e33c;
extern "C" void *_Z15InitObj021bdbf0Ph(void *node);
extern "C" void *_Z15InitObj021beba4Pc(void *node);
extern "C" void *_Z23FindEntryByKeys02019508P12Base02019508ii(void *base, int a, int b);
extern "C" void func_0206ea8c(void *obj, unsigned char a, short b, int flag);
extern "C" void _Z23SetFlag0x40AndToggle0x4P14Struct02013380ii(void *rec, int a, int b);
extern "C" void _Z19InitContext020e1154Pv(void *p);
extern "C" void func_ov017_021a9bc4(void *node, unsigned char b);
extern "C" void func_ov017_021a9a9c(void *node, unsigned char a, unsigned char b, unsigned short c, unsigned char d);
extern "C" void func_ov017_021a8614(void *base, short p1, unsigned short p2, unsigned short p3, unsigned short p4, unsigned short p5);
extern "C" void _Z27EnqueueEventTag141_021ce110itth(int a, unsigned short b, unsigned short c, unsigned char d);
extern "C" void func_0206e748(void *obj, int a, int b, int c, int d);
extern "C" void _Z20AppendNodeToField494P8Obj64af8P9Node64af8(void *obj, void *node);
extern "C" int _Z24CheckField0x56bLowNibbleP11Obj02061bd8(void *obj);
extern "C" void _Z21ClearFieldBit02053fe4P9T02053fe4(void *obj, int val, int flag);
extern "C" void _Z18TryClearFlags0x130Pht(void *obj, unsigned short flag);
extern "C" void func_ov017_02191108(void *base, int a, int b, int c, int d);
extern "C" void _Z21SetByteSavingPreviousP11Foo02033b58h(void *obj, unsigned char v);
extern "C" void *_Z17GetEntryTableBasev(void);
extern "C" void *_Z21GetElementStride0x318P21Element0x318_02028baci(void *table, int idx);
extern "C" void *_ZN9GameState27GetMaybeFieldMonsterByIndexEi(void *battle, int idx);
extern "C" void func_ov017_021a23b0(void *base, unsigned short v);
extern "C" void _Z27EnqueueEventTag134_021c9544iiii(int a, int b, int c, int d);
extern "C" int _Z13GetFieldAt0x0Pi(int *ctx);
extern "C" void _Z24UpdatePlayClocks020ac4f8i(int flag);
extern "C" void _Z17SetField5cbcValuePci(void *battle, int v);
extern "C" int _Z17GetField5cbcValuePc(void *battle);

// USA: func_02061c04
struct SharedFrame { unsigned int word0; unsigned short h4, h6, h8; };
struct Vec3 { int x, y, z; };
struct Vec3W { int w[3]; };
struct PackedRegSlots7f { unsigned int f0 : 7; unsigned int f1 : 4; unsigned int f2 : 5;
                          unsigned int f3 : 5; unsigned int f4 : 6; };
union SlotEntry { unsigned int w; struct { unsigned int id : 9; unsigned int pad9 : 2; unsigned int slot : 3; } b; };
struct EntryFlags { unsigned int pad0 : 10; unsigned int bit10 : 1; unsigned int pad11 : 21; };
struct Elem2Flags { unsigned short pad0 : 2; unsigned short bit2 : 1; unsigned short rest : 13; };

struct FrameB { short opt; unsigned short flags; unsigned short h4, h6, h8, ha, hc, he; };

static inline char *SubA(void *b) { return (char *)b + REGION_VALUE(0x2c4, 0x104); }
static inline char *SubB(char *a) { return a + REGION_VALUE(0x7000, 0x7400); }
struct Blk7400 { char pad[REGION_VALUE(0x7000, 0x7400)]; };
struct StatE7 {
    int r0;
    int r4;
    struct SrcWord44 w8;
    struct SrcWord48 wc;
    struct SrcWord4c w10;
    char pad14[0x40 - 0x14];
    struct SrcWord44 w40;
    char pad44[0x90 - 0x44];
    struct SnapshotE7 snap;
};
static inline struct SnapshotE7 *SnapE7(char *r) { return (struct SnapshotE7 *)(r + 0xcc); }
static inline int GetSlot332(void *obj) { return *((unsigned char *)obj + 0x332); }
static inline int Field134_30(void *c) { return *(unsigned short *)((char *)*(void **)((char *)c + 0x134) + 0x30); }
static inline int AngleMax() { return 0x6488; }
static inline int FxMul(int a, int b) { return (int)(((long long)a * b + 0x800) >> 12); }
extern "C" ARM int func_02061c04(void *obj, CmdMsg64 *msg, void *param3) {
    char cdLocal[REGION_VALUE(0xa4, 0xb8)];
    struct { int a0, a1, a2, a3; } sa;
    struct { int b0, b1, b2; } sb;
    struct Vec3 halfOut;
    CmdMsg64 m9b;
    CmdMsg64 m9c;
    CmdMsg64 m9d;
    CmdMsg64 m9e;
    CmdMsg64 m9f;
    struct Src021cd6d8 c0Local;
    unsigned short deck[14];
    struct { int a, b, c; } d8Local;
    SafeAllocator dbAlloc;
    struct Vec3 midOut;
    struct Vec3 half;
    struct Vec3 mid;
    struct Vec3 diff;
    struct LowRegion {
        short p1;
        short pad2;
        unsigned int fword0;
        unsigned short fh4, fh6, fh8;
        unsigned char d0, d1;
        short d2;
        unsigned char d3, d4;
        struct FrameB fb;
        struct PackedRegSlots7f packed;
    } lr;
    switch (msg->cmd) {
    case 0x64: {
        SetOrClearBitInArray(obj, (unsigned char *)obj + 0x8c, msg->p1, 1);
        void *ctx = func_0202ae18();
        if (CheckField0NonZero((int *)ctx) && !GetSearchStructCurrentArrEntry((SearchStruct0202c1a4 *)ctx))
            func_ov017_021d0924(0, 0, msg->p1, 1);
        return 1;
    }
    case 0x65: {
        SetOrClearBitInArray(obj, (unsigned char *)obj + 0x8c, msg->p1, 0);
        void *ctx = func_0202ae18();
        if (CheckField0NonZero((int *)ctx) && !GetSearchStructCurrentArrEntry((SearchStruct0202c1a4 *)ctx))
            func_ov017_021d0924(0, 0, msg->p1, 0);
        return 1;
    }
    case 0x66: {
        unsigned char slot = *((unsigned char *)obj + 0x332);
        SetOrClearBitInArray(obj, (unsigned char *)obj + slot * 0x1c + 3, msg->p1, 1);
        void *ctx = func_0202ae18();
        if (CheckField0NonZero((int *)ctx) && !GetSearchStructCurrentArrEntry((SearchStruct0202c1a4 *)ctx))
            func_ov017_021d0924(3, *((unsigned char *)obj + 0x332), msg->p1, 1);
        return 1;
    }
    case 0x67: {
        unsigned char slot = *((unsigned char *)obj + 0x332);
        SetOrClearBitInArray(obj, (unsigned char *)obj + slot * 0x1c + 3, msg->p1, 0);
        void *ctx = func_0202ae18();
        if (CheckField0NonZero((int *)ctx) && !GetSearchStructCurrentArrEntry((SearchStruct0202c1a4 *)ctx))
            func_ov017_021d0924(3, *((unsigned char *)obj + 0x332), msg->p1, 0);
        return 1;
    }
    case 0x68: {
        unsigned char slot = *((unsigned char *)obj + 0x332);
        SetOrClearBitInArray(obj, (unsigned char *)obj + slot * 0x1c + 0x10, msg->p1, 1);
        void *ctx = func_0202ae18();
        if (CheckField0NonZero((int *)ctx) && !GetSearchStructCurrentArrEntry((SearchStruct0202c1a4 *)ctx))
            func_ov017_021d0924(5, *((unsigned char *)obj + 0x332), msg->p1, 1);
        return 1;
    }
    case 0x69: {
        unsigned char slot = *((unsigned char *)obj + 0x332);
        SetOrClearBitInArray(obj, (unsigned char *)obj + slot * 0x1c + 0x10, msg->p1, 0);
        void *ctx = func_0202ae18();
        if (CheckField0NonZero((int *)ctx) && !GetSearchStructCurrentArrEntry((SearchStruct0202c1a4 *)ctx))
            func_ov017_021d0924(5, *((unsigned char *)obj + 0x332), msg->p1, 0);
        return 1;
    }
    case 0x6a: {
        void *p = func_ov017_0218b5b0();
        unsigned char *r5 = *(unsigned char **)((char *)p + 0x4000 + REGION_VALUE(0x214, 0x4c4));
        _Z19ClearNibble0206ece8iiPhj((int)r5, msg->p1, r5, 0x80);
        _Z19ClearNibble0206ece8iiPhj((int)r5, msg->p1, r5 + 0x80, 0x80);
        return 1;
    }
    case 0x6b: {
        void *ctx = func_0202ae18();
        if (func_0202c508(ctx))
            SetOrClearBitInArray(obj, (unsigned char *)obj + 0x8c, 0x113a, ((unsigned char *)msg)[2] == 0);
        return 1;
    }
    case 0x6c: {
        void *p0 = func_02012fe4();
        void *node = GetPointerFromArray0x3c((unsigned char *)((char *)p0 + REGION_VALUE(0x8c, 0x6c)), 2);
        while (node) {
            if (*((unsigned char *)node + 0x2c) == msg->p2 &&
                *((unsigned char *)node + 0x2d) == msg->p3 &&
                *(short *)((char *)node + 0x20) == (short)msg->p1) {
                FlagsField0x2e *f = (FlagsField0x2e *)((char *)node + 0x2e);
                if (!(f->flagsHi & 1))
                    f->flagsHi |= 4;
            }
            node = *(void **)((char *)node + 0x70);
        }
        return 1;
    }
    case 0x6d: {
        void *p0 = func_02012fe4();
        void *node = GetPointerFromArray0x3c((unsigned char *)((char *)p0 + REGION_VALUE(0x8c, 0x6c)), 2);
        while (node) {
            FlagsField0x2e *f = (FlagsField0x2e *)((char *)node + 0x2e);
            if (!(f->flagsHi & 1) &&
                *((unsigned char *)node + 0x2c) == msg->p2 &&
                *((unsigned char *)node + 0x2d) == msg->p3 &&
                *(short *)((char *)node + 0x20) == (short)msg->p1) {
                func_02018300(p0, node, 1, 1, 1);
            }
            node = *(void **)((char *)node + 0x70);
        }
        return 1;
    }
    case 0x99: {
        void *p0 = func_02012fe4();
        void *node = GetPointerFromArray0x3c((unsigned char *)((char *)p0 + REGION_VALUE(0x8c, 0x6c)), 2);
        while (node) {
            FlagsField0x2e *f = (FlagsField0x2e *)((char *)node + 0x2e);
            if (!(f->flagsHi & 1) &&
                *((unsigned char *)node + 0x2c) == msg->p2 &&
                *((unsigned char *)node + 0x2d) == msg->p3 &&
                *(short *)((char *)node + 0x20) == (short)msg->p1) {
                f->flagsHi |= 0x100;
                func_02018300(p0, node, 0, 1, 1);
            }
            node = *(void **)((char *)node + 0x70);
        }
        return 1;
    }
    case 0x6e: {
        void *battle = _ZN9GameState11GetInstanceEv();
        _ZN9GameState12SetTimeOfDayE9TimeOfDay((char *)battle, msg->p1);
        void *d = LightingManager::GetInstance();
        *(int *)((char *)d + 0x94) = _ZNK9GameState11GetDayTimerEv((BattleStruct *)battle);
        *(int *)((char *)d + 0x98) = _ZNK9GameState12GetTimeOfDayEv((BattleStruct *)battle);
        void *ctx = func_0202ae18();
        if (func_0202c508(ctx))
            _Z27EnqueueEventTag147_021cdaa0v();
        return 1;
    }
    case 0x72:
        msg->p2 = 1;
        AppendNodeToListField30((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    case 0x73:
        msg->p2 = 1;
        AppendNodeToListField30((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    case 0x74:
        AppendNodeToListField30((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    case 0x75:
        AppendNodeToListField30((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    case 0x76:
        AppendNodeToListField30((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    case 0x77:
        AppendNodeToListField30((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    case 0x78:
        AppendNodeToListField30((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    case 0x79: case 0x89: case 0xe1:
        AppendNodeToListField30((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    case 0x7a:
        AppendNodeToListField30((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    case 0x7b:
        AppendNodeToListField30((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    case 0x7c:
        AppendNodeToListField30((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    case 0x7d: {
        if (func_020961b0(GetGlobal02109418(), msg->p1) == 0)
            return 0;
        if (!TestBitInByteArray((int)obj, (unsigned char *)obj + 0x8c, 0x119d)) {
            void *p = func_ov017_0218b5b0();
            void *list = *(void **)((char *)p + 0x3000 + REGION_VALUE(0x4ec, 0x6fc));
            SetOrClearBitInArray(obj, (unsigned char *)obj + 0x8c, 0x119d, 1);
            void *node = *(void **)((char *)p + 0x3000 + REGION_VALUE(0x9a0, 0xbc0));
            _Z12Init020d9ae8P14Struct020d9ae8i((Struct020d9ae8 *)node, 1);
            AppendNodeToTail((TailList020469b4 *)list, (TailNode020469b4 *)node);
        }
        return 1;
    }
    case 0x7e: {
        int isTwo = _Z20GetPackedNibbleFieldP25PackedNibbleArray0206e120i(obj, msg->p1) == 2;
        if (!isTwo)
            return 1;
        void *p = func_ov017_0218b5b0();
        void *list = *(void **)((char *)p + 0x3000 + REGION_VALUE(0x4ec, 0x6fc));
        void *node = *(void **)((char *)p + 0x3000 + REGION_VALUE(0x99c, 0xbbc));
        _Z12Init020d9decP14Struct020d9deci(node, 0);
        _Z18SetFlagBit020d9fb4P9S020d9fb4i(node, 0);
        *(int *)((char *)node + 0x10) = msg->p1;
        if (*((unsigned char *)node + 2) == 0)
            AppendNodeToTail((TailList020469b4 *)list, (TailNode020469b4 *)node);
        return 1;
    }
    case 0x7f: {
        _Z21RegisterSlotA020cf0fci((int)&sa);
        _Z21RegisterSlotB020cf1a8i((int)&sb);
        lr.packed.f0 = sa.a0;
        lr.packed.f1 = sa.a1;
        lr.packed.f2 = sa.a2;
        lr.packed.f3 = sb.b0;
        lr.packed.f4 = sb.b1;
        void *g = GetGlobal02109418();
        *(unsigned int *)((char *)g + msg->p1 * 4 + 0x178) = *(unsigned int *)&lr.packed;
        _Z23ApplySlotConfig02095cfcii(g, msg->p1);
        return 1;
    }
    case 0x80:
        AppendNodeToListField30((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    case 0x81:
        func_0206e164(obj, msg->p1, 1);
        return 1;
    case 0x82: {
        void *ctx = func_0202ae18();
        if (CheckField0NonZero((int *)ctx)) {
            _Z21FindEntryById02096134P26FindEntryById02096134Tablei((FindEntryById02096134Table *)GetGlobal02109418(), msg->p1);
            if (!GetSearchStructCurrentArrEntry((SearchStruct0202c1a4 *)ctx)) {
                if (msg->p2 < 0x400)
                    func_ov017_021d0924(0, 0, msg->p2, 1);
                _Z24SetBitWithOffset0206eb64Phii((unsigned char *)obj, msg->p2, 1);
            } else {
                _Z24SetBitWithOffset0206eb64Phii((unsigned char *)obj, msg->p2, 1);
            }
        } else {
            _Z24SetBitWithOffset0206eb64Phii((unsigned char *)obj, msg->p2, 1);
        }
        return 1;
    }
    case 0x83: {
        void *ctx = func_0202ae18();
        if (CheckField0NonZero((int *)ctx)) {
            void *entry = _Z21FindEntryById02096134P26FindEntryById02096134Tablei((FindEntryById02096134Table *)GetGlobal02109418(), msg->p1);
            if (!GetSearchStructCurrentArrEntry((SearchStruct0202c1a4 *)ctx)) {
                if (!(entry != 0 && ((struct EntryFlags *)entry)->bit10 == 1) &&
                    msg->p2 < 0x400)
                    func_ov017_021d0924(0, 0, msg->p2, 0);
                _Z24SetBitWithOffset0206eb64Phii((unsigned char *)obj, msg->p2, 0);
            } else {
                if (entry != 0 && ((struct EntryFlags *)entry)->bit10 == 1)
                    _Z24SetBitWithOffset0206eb64Phii((unsigned char *)obj, msg->p2, 0);
            }
        } else {
            _Z24SetBitWithOffset0206eb64Phii((unsigned char *)obj, msg->p2, 0);
        }
        return 1;
    }
    case 0x84: {
        void *battle = _ZN9GameState11GetInstanceEv();
        lr.fb.ha = _Z17GetField5cb0ValuePc(battle);
        lr.fb.hc = _Z17GetField5cb4ValuePc(battle);
        lr.fb.he = _Z17GetField5cb8ValuePc(battle);
        AppendNodeToListField30((int)obj, (AppendNode *)msg, (AppendList *)param3);
        if (lr.fb.ha != msg->p2)
            _Z20ClearRegions0206e080Pci(obj, *((unsigned char *)obj + 0x332));
        if (lr.fb.hc != msg->p3)
            _Z31ClearIndexedEntryFields0206e0d0Pci(obj, *((unsigned char *)obj + 0x332));
        return 1;
    }
    case 0x85: case 0x8a: case 0xe2:
        AppendNodeToListField30((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    case 0x86: {
        void *ctx = func_0202ae18();
        if (CheckField0NonZero((int *)ctx))
            _Z27EnqueueEventTag141_021ce110itth((unsigned char)msg->p2, 1, msg->p1, 1);
        switch (msg->p2) {
        case 3:
            SetOrClearBitInArray(obj, (unsigned char *)obj + 0x8c, msg->p1, 1);
            func_ov017_021d0924(0, 0, msg->p1, 1);
            if (func_0202c540(ctx))
                func_0206e748(obj, 0, 0, msg->p1, 1);
            break;
        case 4: {
            SetOrClearBitInArray(obj, (unsigned char *)obj + *((unsigned char *)obj + 0x332) * 0x1c + 3, msg->p1, 1);
            func_ov017_021d0924(3, *((unsigned char *)obj + 0x332), msg->p1, 1);
            if (func_0202c540(ctx)) {
                int slot1 = GetSlot332(obj);
                func_0206e748(obj, 3, slot1, msg->p1, 1);
            }
            break;
        }
        case 5: {
            SetOrClearBitInArray(obj, (unsigned char *)obj + *((unsigned char *)obj + 0x332) * 0x1c + 0x10, msg->p1, 1);
            func_ov017_021d0924(5, *((unsigned char *)obj + 0x332), msg->p1, 1);
            if (func_0202c540(ctx)) {
                int slot2 = GetSlot332(obj);
                func_0206e748(obj, 5, slot2, msg->p1, 1);
            }
            break;
        }
        default:
            break;
        }
        return 1;
    }
    case 0x87: {
        void *ctx = func_0202ae18();
        if (CheckField0NonZero((int *)ctx))
            _Z27EnqueueEventTag141_021ce110itth((unsigned char)msg->p2, 0, msg->p1, 1);
        switch (msg->p2) {
        case 3:
            SetOrClearBitInArray(obj, (unsigned char *)obj + 0x8c, msg->p1, 0);
            func_ov017_021d0924(0, 0, msg->p1, 0);
            if (func_0202c540(ctx))
                func_0206e748(obj, 0, 0, msg->p1, 0);
            break;
        case 4: {
            SetOrClearBitInArray(obj, (unsigned char *)obj + *((unsigned char *)obj + 0x332) * 0x1c + 3, msg->p1, 0);
            func_ov017_021d0924(3, *((unsigned char *)obj + 0x332), msg->p1, 0);
            if (func_0202c540(ctx)) {
                int slot3 = GetSlot332(obj);
                func_0206e748(obj, 3, slot3, msg->p1, 0);
            }
            break;
        }
        case 5: {
            SetOrClearBitInArray(obj, (unsigned char *)obj + *((unsigned char *)obj + 0x332) * 0x1c + 0x10, msg->p1, 0);
            func_ov017_021d0924(5, *((unsigned char *)obj + 0x332), msg->p1, 0);
            if (func_0202c540(ctx)) {
                int slot4 = GetSlot332(obj);
                func_0206e748(obj, 5, slot4, msg->p1, 0);
            }
            break;
        }
        default:
            break;
        }
        return 1;
    }
    case 0x88: {
        void *p0 = func_02012fe4();
        void *node = GetPointerFromArray0x3c((unsigned char *)((char *)p0 + REGION_VALUE(0x8c, 0x6c)), 2);
        while (node) {
            if (*((unsigned char *)node + 0x2c) == msg->p2 &&
                *((unsigned char *)node + 0x2d) == msg->p3 &&
                *(short *)((char *)node + 0x20) == (short)msg->p1) {
                FlagsField0x2e *f = (FlagsField0x2e *)((char *)node + 0x2e);
                f->flagsHi &= ~4;
            }
            node = *(void **)((char *)node + 0x70);
        }
        return 1;
    }
    case 0x8b: {
        void *battle = _ZN9GameState11GetInstanceEv();
        void *p = _Z17GetPtrField0x2a04P9GameState(battle);
        unsigned int v = *(unsigned int *)((char *)p + 0xf6c) + *(unsigned int *)((char *)msg + 4);
        *(unsigned int *)((char *)p + 0xf6c) = v;
        if (v > 9999999)
            *(unsigned int *)((char *)p + 0xf6c) = 9999999;
        return 1;
    }
    case 0x8c: {
        void *battle = _ZN9GameState11GetInstanceEv();
        void *p = _Z17GetPtrField0x2a04P9GameState(battle);
        unsigned int v = *(unsigned int *)((char *)p + 0xf6c);
        unsigned int d = *(unsigned int *)((char *)msg + 4);
        *(unsigned int *)((char *)p + 0xf6c) = (v < d) ? 0 : (v - d);
        return 1;
    }
    case 0x8d:
        AppendNodeToListField30((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    case 0x8e:
        _Z24SetKeyedArrayBit0206e348Phii(obj, msg->p1, 1);
        return 1;
    case 0x8f: {
        if (msg->p1 == 2)
            return 1;
        void *base = func_ov017_0218b5b0();
        void *mem = ((SafeAllocator *)((char *)base + 0x164))->Allocate(0x30);
        if (mem) {
            func_02012fe4();
            struct Msg8fExt { short cmd, pad2; int f4, f8, fc, f10; int *f14; } *m = (struct Msg8fExt *)msg;
            char *n = (char *)mem;
            *(short *)(n + 0) = (short)m->f4;
            *(int *)(n + 0x14) = m->f8;
            *(int *)(n + 0x1c) = m->f10;
            *(int *)(n + 0x18) = m->fc;
            int *p14 = m->f14;
            *(int *)(n + 0x20) = p14[1];
            *(int *)(n + 0x28) = p14[3];
            *(int *)(n + 0x24) = p14[2];
            *(short *)(n + 2) = (short)(4096.0f * (3.14159274f * (float)p14[4] / 180.0f));
            short angle = *(short *)(n + 2);
            int lim = 0x6488;
            if (angle > lim)
                *(short *)(n + 2) -= lim;
            else if (angle < 0)
                *(short *)(n + 2) = angle + 0x6488;

                mid.x = (*(int *)(n + 0x14) + *(int *)(n + 0x20)) >> 1;
            mid.y = (*(int *)(n + 0x18) + *(int *)(n + 0x24)) >> 1;
            mid.z = (*(int *)(n + 0x1c) + *(int *)(n + 0x28)) >> 1;
            *(struct Vec3W *)&midOut = *(struct Vec3W *)&mid;
            *(int *)(n + 4) = midOut.x;
            *(int *)(n + 8) = midOut.y;
            *(int *)(n + 0xc) = midOut.z;

            diff.x = *(int *)(n + 0x14) - *(int *)(n + 0x20);
            diff.y = *(int *)(n + 0x18) - *(int *)(n + 0x24);
            diff.z = *(int *)(n + 0x1c) - *(int *)(n + 0x28);
            *(struct Vec3W *)&half = *(struct Vec3W *)&diff;
            *(struct Vec3W *)&halfOut = *(struct Vec3W *)&half;
            int hx = halfOut.x / 2;
            int hy = halfOut.y / 2;
            int sqy = FxMul(hy, hy);
            int sqx = FxMul(hx, hx);
            *(int *)(n + 0x10) = sqx + sqy;
            *(int *)(n + 0x2c) = 0;

            _Z20AppendNodeToField494P8Obj64af8P9Node64af8(obj, mem);
        }
        return 1;
    }
    case 0x90: {
        void *ctx = func_0202ae18();
        if (func_0202c540(ctx))
            return 1;
        int isTwo = _Z20GetPackedNibbleFieldP25PackedNibbleArray0206e120i(obj, msg->p1) == 2;
        if (!isTwo)
            return 1;
        unsigned int *p = (unsigned int *)((char *)GetGlobal02109418() + 4);
        while (p) {
            union SlotEntry *e = (union SlotEntry *)p;
            if (e->b.id == (unsigned short)msg->p1) {
                e->b.slot = msg->p2;
                break;
            }
            p = (unsigned int *)((char *)p + 0x10);
        }
        return 1;
    }
    case 0x91:
        AppendNodeToListField30((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    case 0x92:
        SetOrClearBitInArray(obj, (unsigned char *)obj + 0x8c, msg->p1 + 0x776, 1);
        return 1;
    case 0x93:
        SetOrClearBitInArray(obj, (unsigned char *)obj + 0x8c, msg->p1 + 0x776, 0);
        return 1;
    case 0x94: {
        void *battle = _ZN9GameState11GetInstanceEv();
        lr.fb.h4 = _Z17GetField5cb0ValuePc(battle);
        lr.fb.h6 = _Z17GetField5cb4ValuePc(battle);
        lr.fb.h8 = _Z17GetField5cb8ValuePc(battle);
        msg->p1 = 5;
        AppendNodeToListField30((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    }
    case 0x95: {
        void *p0 = func_02012fe4();
        if (!p0)
            return 0;
        void *entry = _Z23FindEntryByKeys02019508P12Base02019508ii(p0, msg->p1, msg->p2);
        if (!entry) {
            func_0206ea8c(obj, (unsigned char)msg->p1, (short)(msg->p2 + 0x80), 1);
            func_0206ea8c(obj, (unsigned char)msg->p1, (short)msg->p2, 0);
            return 1;
        }
        _Z23SetFlag0x40AndToggle0x4P14Struct02013380ii(entry, msg->p1, 0);
        return 1;
    }
    case 0x96: {
        void *p0 = func_02012fe4();
        if (!p0)
            return 0;
        void *entry = _Z23FindEntryByKeys02019508P12Base02019508ii(p0, msg->p1, msg->p2);
        if (!entry) {
            func_0206ea8c(obj, (unsigned char)msg->p1, (short)(msg->p2 + 0x80), 0);
            func_0206ea8c(obj, (unsigned char)msg->p1, (short)msg->p2, 1);
            return 1;
        }
        _Z23SetFlag0x40AndToggle0x4P14Struct02013380ii(entry, msg->p1, 1);
        return 1;
    }
    case 0x97: {
        void *p = func_ov017_0218b5b0();
        void *list = *(void **)((char *)p + 0x3000 + REGION_VALUE(0x4ec, 0x6fc));
        void *node = *(void **)((char *)p + 0x3000 + REGION_VALUE(0x940, 0xb60));
        _Z15InitObj021bdbf0Ph(node);
        *((unsigned char *)node + 0x11) = msg->p1;
        _Z17PrependNodeToHeadP16HeadList020469f8P16HeadNode020469f8(list, node);
        return 1;
    }
    case 0x9b: {
        m9b.cmd = 0x68;
        m9b.p1 = msg->p2;
        func_02061c04(obj, &m9b, param3);
        AppendNodeToListField30((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    }
    case 0x9c: {
        m9c.cmd = 0x7f;
        m9c.p1 = msg->p1;
        func_02061c04(obj, &m9c, param3);
        AppendNodeToListField30((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    }
    case 0x9d: {
        switch ((short)msg->p2) {
        case 0: m9d.cmd = 0x7d; break;
        case 2: m9d.cmd = 0x7f; break;
        case 3: m9d.cmd = 0x81; break;
        default: return 0;
        }
        m9d.p1 = msg->p1;
        func_02061c04(obj, &m9d, param3);
        AppendNodeToListField30((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    }
    case 0x9e: {
        m9e.cmd = 0x75;
        m9e.p1 = msg->p1;
        m9e.p2 = msg->p2;
        return func_02061c04(obj, &m9e, param3);
    }
    case 0x9f: {
        m9f.cmd = 0x74;
        m9f.p1 = msg->p1;
        m9f.p2 = msg->p2;
        return func_02061c04(obj, &m9f, param3);
    }
    case 0xa0:
        SetOrClearBitInArray(obj, (unsigned char *)obj + 0x8c, msg->p1 + 0x113f, 1);
        return 1;
    case 0xa1: {
        lr.fb.flags &= ~1;
        lr.fb.opt = -1;
        lr.fb.flags &= ~2;
        lr.fb.flags &= ~0xfffcu;
        lr.p1 = msg->p1;
        if (func_020ac2d4(0, &lr.p1, &lr.fb.opt, 1)) {
            lr.fb.flags |= 2;
            func_020ac104(&data_0211e33c, &lr.fb.opt, 1);
        }
        return 1;
    }
    case 0xa2:
        if (msg->p1 != 0)
            SetOrClearBitInArray(obj, (unsigned char *)obj + 0x8c, 0x113b, 0);
        else
            SetOrClearBitInArray(obj, (unsigned char *)obj + 0x8c, 0x113b, 1);
        return 1;
    case 0xc0: {
        void *battle = _ZN9GameState11GetInstanceEv();
        void *p0 = func_02012fe4();
        func_0202ae18();
        c0Local.f0 = 0;
        c0Local.f1 = 0;
        c0Local.f2 = 0;
        c0Local.f3 = 0;
        c0Local.f4 = 0;
        c0Local.f5 = 0;
        c0Local.f7 = 0;
        c0Local.f6 = -1;
        c0Local.f0 = *(unsigned short *)p0;
        c0Local.f1 = msg->p1;
        c0Local.f2 = 0;
        c0Local.f4 = 1;
        c0Local.f3 = -1;
        c0Local.f7 = _ZNK9GameState11GetDayTimerEv((BattleStruct *)battle);
        _Z27EnqueueEventTag142_021cd6d8P11Src021cd6d8(&c0Local);
        return 1;
    }
    case 0xa4: {
        void *p = func_ov017_0218b5b0();
        func_ov017_021c1a98(p, 0);
        return 1;
    }
    case 0xa5: {
        void *battle = _ZN9GameState11GetInstanceEv();
        void *combatant = _ZN9GameState20GetGameObjectByIndexEi(battle, 0);
        _Z18SetBitInArray0x8ecPhi(*(void **)((char *)combatant + REGION_VALUE(0x144, 0x150)), msg->p1);
        return 1;
    }
    case 0xa6: {
        void *battle = _ZN9GameState11GetInstanceEv();
        void *combatant = _ZN9GameState20GetGameObjectByIndexEi(battle, 0);
        _Z18SetBitInArray0x910Phi(*(void **)((char *)combatant + REGION_VALUE(0x144, 0x150)), msg->p1);
        return 1;
    }
    case 0xa7: {
        unsigned char b = ((unsigned char *)msg)[2];
        if (b == 0)
            _Z27ToggleElemKey2FlagInMap2010i(((unsigned char *)msg)[4]);
        else if (b == 6)
            _Z35SetElemFlag8IfOverlayActive020ae730i(((unsigned char *)msg)[4]);
        return 1;
    }
    case 0xa8:
        return 1;
    case 0xa9:
        if (((unsigned char *)msg)[2] == 0)
            _Z29SetElemFlag0x4PairAndNotify17i(((unsigned char *)msg)[4]);
        return 1;
    case 0xaa:
        _Z29SetElemFlag0x4QuadAndNotify17i((unsigned char)msg->p1);
        return 1;
    case 0xab:
        return 1;
    case 0xac:
        return 1;
    case 0xad:
        return 1;
    case 0xae:
        return 1;
    case 0xaf:
        SetOrClearBitInArray(obj, (unsigned char *)obj + 0x8c, msg->p1 + 0x1136, 0);
        return 1;
    case 0xb0: {
        void *global = GetGlobal02109418();
        BitFlag17Entry *entry = (BitFlag17Entry *)_Z21FindEntryById02096134P26FindEntryById02096134Tablei((FindEntryById02096134Table *)global, msg->p1);
        if (entry)
            entry->flag17 = msg->p2;
        return 1;
    }
    case 0xb1: {
        void *battle = _ZN9GameState11GetInstanceEv();
        _ZN9GameState12SetTimeOfDayE9TimeOfDay((char *)battle, msg->p2);
        void *d = LightingManager::GetInstance();
        *(int *)((char *)d + 0x94) = _ZNK9GameState11GetDayTimerEv((BattleStruct *)battle);
        *(int *)((char *)d + 0x98) = _ZNK9GameState12GetTimeOfDayEv((BattleStruct *)battle);
        _ZN9GameState18SetDayTimerRunningEi(battle, msg->p1 == 0);
        return 1;
    }
    case 0xb2: {
        void *base = func_ov017_0218b5b0();
        void *list = *(void **)((char *)base + 0x3000 + REGION_VALUE(0x4ec, 0x6fc));
        void *node = *(void **)((char *)base + 0x3000 + REGION_VALUE(0x948, 0xb68));
        _Z19InitContext020e1154Pv((void *)0xbb8);
        func_ov017_021a9bc4(node, ((unsigned char *)msg)[2]);
        func_ov017_021a9a9c(node, ((unsigned char *)msg)[4], ((unsigned char *)msg)[5], msg->p3,
                            ((unsigned char *)msg)[8]);
        AppendNodeToTail((TailList020469b4 *)list, (TailNode020469b4 *)node);
        return 1;
    }
    case 0xb3: {
        void *battle = _ZN9GameState11GetInstanceEv();
        void *p = _Z17GetPtrField0x2a04P9GameState(battle);
        if (msg->p1 != 0) {
            SetOrClearBitInArray(obj, (unsigned char *)obj + 0x8c, 0x113c, 1);
            *(unsigned int *)((char *)p + 0x2c94) = msg->p2;
        } else {
            SetOrClearBitInArray(obj, (unsigned char *)obj + 0x8c, 0x113c, 0);
            *(unsigned int *)((char *)p + 0x2c94) = *(unsigned int *)((char *)battle + REGION_VALUE(0x7c34, 0x7e74));
            void *ctx = func_0202ae18();
            if (CheckField0NonZero((int *)ctx) && !GetSearchStructCurrentArrEntry((SearchStruct0202c1a4 *)ctx))
                _Z31EnqueueEventTag23Field_021d0d58v();
        }
        return 1;
    }
    case 0xb4: {
        void *base = func_ov017_0218b5b0();
        void *list = *(void **)((char *)base + 0x3000 + REGION_VALUE(0x4ec, 0x6fc));
        if (!_Z14ListContainsIdP16ListHead02046b60i(list, 0xa))
            return 1;
        void *node = *(void **)((char *)base + 0x3000 + REGION_VALUE(0x508, 0x718));
        void *r = func_ov017_021b8478(node);
        if (!_Z21IsField0xcNonNegativePi(r))
            return 1;
        *(short *)((char *)r + 0x22) = (*(int *)((char *)r + 0xc) == msg->p1) ? msg->p2 : 0;
        return 1;
    }
    case 0xb5:
        return 1;
    case 0xb6:
        return 1;
    case 0xb7:
        return 1;
    case 0xb8: {
        void *base = func_ov017_0218b5b0();
        void *list = *(void **)((char *)base + 0x3000 + REGION_VALUE(0x4ec, 0x6fc));
        void *node = *(void **)((char *)base + 0x3000 + REGION_VALUE(0x968, 0xb88));
        _Z20InitState60_021aa16cP11Obj021aa16c(node);
        _Z17PrependNodeToHeadP16HeadList020469f8P16HeadNode020469f8(list, node);
        return 1;
    }
    case 0xb9: {
        void *base = func_ov017_0218b5b0();
        _Z18Something_021a6b9cih(base, 0);
        return 1;
    }
    case 0xba:
        SetOrClearBitInArray(obj, (unsigned char *)obj + 0x8c, 0x1138, msg->p1);
        return 1;
    case 0xbb:
        *(unsigned short *)((char *)obj + 0x2ca) = 0;
        return 1;
    case 0xbc: {
        void *p = _Z27GetStatFieldPointer02064904Pvij(obj, msg->p1, msg->p2);
        if (p) {
            switch (msg->p4) {
            case 0:
                *(unsigned short *)p = msg->p3;
                break;
            case 1: {
                int v = *(unsigned short *)p + msg->p3;
                if (v >= 0xffff)
                    *(unsigned short *)p = 0xffff;
                else
                    *(unsigned short *)p = v;
                break;
            }
            case 2: {
                int v = *(unsigned short *)p - msg->p3;
                if (v < 0)
                    *(unsigned short *)p = 0;
                else
                    *(unsigned short *)p = v;
                break;
            }
            default:
                break;
            }
        }
        return 1;
    }
    case 0xbd: {
        void *base = func_ov017_0218b5b0();
        void *list = *(void **)((char *)base + 0x3000 + REGION_VALUE(0x4ec, 0x6fc));
        void *node = *(void **)((char *)base + 0x3000 + REGION_VALUE(0x50c, 0x71c));
        func_ov017_021a5568(node);
        _Z26SetBytesAt20And21_021a55a4Phhh(node, 1, ((unsigned char *)msg)[2]);
        *(unsigned char *)((char *)node + 0x24) = 0;
        *(int *)((char *)node + 0x28) = 0;
        *(int *)((char *)node + 0x2c) = -1;
        AppendNodeToTail((TailList020469b4 *)list, (TailNode020469b4 *)node);
        return 1;
    }
    case 0xbe: {
        if (!_Z21FindEntryById02096134P26FindEntryById02096134Tablei((FindEntryById02096134Table *)GetGlobal02109418(), msg->p1))
            break;
        void *p = _Z27GetStatFieldPointer02064904Pvij(obj, msg->p1, msg->p2);
        if (!p)
            return 0;
        *(unsigned short *)p = _Z17NextRandomBetweenP6Randomii(_Z11GetBTRandomv(), msg->p3, msg->p4);
        return 1;
    }
    case 0xbf: {
        unsigned short count = 14;
        int n = 14;
        unsigned short *dst = deck;
        unsigned short *src = (unsigned short *)data_020e7de8;
        do {
            *dst = *src;
            ++src;
            ++dst;
        } while (--n);
        void *entry = _Z21FindEntryById02096134P26FindEntryById02096134Tablei((FindEntryById02096134Table *)GetGlobal02109418(), msg->p1);
        if (!entry)
            break;
        for (int j = 0; j < 5; j++) {
            int idx = _Z13NextRandomMaxP6Randomi(_Z11GetBTRandomv(), count);
            *(short *)((char *)entry + j * 2 + 4) = deck[idx];
            if (idx < count - 1)
                memmove(&deck[idx], &deck[idx + 1], count - (idx + 1));
            count--;
            deck[count] = 0;
        }
        return 1;
    }
    case 0xc1: {
        void *battle = _ZN9GameState11GetInstanceEv();
        void *rec = _Z18GetField0x3b0ValueP9GameState(battle);
        if (msg->p1 != 0) {
            _Z33StoreFields0x1e4And0x1e8IfNonZeroPhii(rec, 0x333, 1);
            _Z17SetFlag0x4At0x168Ph(rec);
        } else {
            _Z23ClearTwoWordsAndFlag0x4P21FlagsAndWords0202ea20(rec);
        }
        return 1;
    }
    case 0xc2: {
        void *d = _Z15GetData02108f0cv();
        *(unsigned char *)((char *)d + 0xa8) = msg->p1 * 10;
        return 1;
    }
    case 0xc3:
        func_ov017_0218b5b0();
        return 1;
    case 0xc4:
        return 1;
    case 0xc5: {
        void *battle = _ZN9GameState11GetInstanceEv();
        void *ctx = func_0202ae18();
        int v = _Z13GetFieldAt0x0Pi((int *)ctx);
        int byte = *((unsigned char *)ctx + 0x1000 + 0xd);
        int flag = 0;
        if ((v == 5 && byte > 1) || v == 6)
            flag = 1;
        _Z24UpdatePlayClocks020ac4f8i(flag);
        int cur = _Z17GetField5cbcValuePc(battle);
        int newVal = msg->p1;
        int a = cur;
        if (cur >= 0xd && cur <= 0xd) a = cur;
        else if (cur >= 0xe && cur <= 0xf) a = cur;
        else if (cur >= 0x10 && cur <= 0x11) a = cur;
        else if (cur >= 0x12 && cur <= 0x18) a = cur;
        else if (cur >= 0x19 && cur <= 0x1b) a = cur;
        else if (cur >= 0x1c && cur <= 0x21) a = cur;
        else if (cur >= 0x22 && cur <= 0x26) a = cur;
        else if (cur >= 0x28 && cur <= 0x5c) a = cur;
        else if (cur >= 0x5d && cur <= 0x5d) a = cur;
        else if (cur >= 0x5e && cur <= 0x64) a = cur;
        else if (cur >= 0x65 && cur <= 0x68) a = cur;
        else if (cur >= 0x69 && cur <= 0x6b) a = cur;
        else if (cur >= 0x6c && cur <= 0x71) a = cur;
        else if (cur >= 0x7b && cur <= 0x7c) a = cur;
        else if (cur >= 0x7d && cur <= 0x80) a = cur;
        else if (cur >= 0x81 && cur <= 0x85) a = cur;
        else if (cur >= 0x86 && cur <= 0x89) a = cur;
        else if (cur >= 0x8a && cur <= 0x8c) a = cur;
        else if (cur >= 0x8d && cur <= 0x92) a = cur;
        else if (cur >= 0x94 && cur <= 0x94) a = cur;
        int b = newVal;
        if (newVal >= 0xd && newVal <= 0xd) b = newVal;
        else if (newVal >= 0xe && newVal <= 0xf) b = newVal;
        else if (newVal >= 0x10 && newVal <= 0x11) b = newVal;
        else if (newVal >= 0x12 && newVal <= 0x18) b = newVal;
        else if (newVal >= 0x19 && newVal <= 0x1b) b = newVal;
        else if (newVal >= 0x1c && newVal <= 0x21) b = newVal;
        else if (newVal >= 0x22 && newVal <= 0x26) b = newVal;
        else if (newVal >= 0x28 && newVal <= 0x5c) b = newVal;
        else if (newVal >= 0x5d && newVal <= 0x5d) b = newVal;
        else if (newVal >= 0x5e && newVal <= 0x64) b = newVal;
        else if (newVal >= 0x65 && newVal <= 0x68) b = newVal;
        else if (newVal >= 0x69 && newVal <= 0x6b) b = newVal;
        else if (newVal >= 0x6c && newVal <= 0x71) b = newVal;
        else if (newVal >= 0x7b && newVal <= 0x7c) b = newVal;
        else if (newVal >= 0x7d && newVal <= 0x80) b = newVal;
        else if (newVal >= 0x81 && newVal <= 0x85) b = newVal;
        else if (newVal >= 0x86 && newVal <= 0x89) b = newVal;
        else if (newVal >= 0x8a && newVal <= 0x8c) b = newVal;
        else if (newVal >= 0x8d && newVal <= 0x92) b = newVal;
        else if (newVal >= 0x94 && newVal <= 0x94) b = newVal;
        if (a != b) {
            memset(SubB(SubA(battle)) + 0xa4, 0, 0x28);
        }
        _Z17SetField5cbcValuePci(battle, msg->p1);
        return 1;
    }
    case 0xc6: {
        void *ctx = func_0202ae18();
        func_0202c288();
        int lvl = *((unsigned char *)ctx + 0x100d);
        if (lvl <= 1)
            return 0;
        void *base = func_ov017_0218b5b0();
        void *rec = *(void **)((char *)base + 0x3000 + REGION_VALUE(0x500, 0x710));
        _Z29ResetFieldsToDefault_021b994cP12Obj_021b994c(rec);
        *((unsigned char *)rec + 0x130) = 1;
        void *battle = _ZN9GameState11GetInstanceEv();
        int v = *(int *)((char *)battle + 0x5000 + REGION_VALUE(0x4c4, 0x724));
        _Z27EnqueueEventTag153_021d079chht(4, 0, (unsigned short)v);
        *(int *)((char *)rec + 0x12c) = v;
        return 1;
    }
    case 0xc7:
        _Z36NotifyElemAndOverlay17OnFlag020ae990i(msg->p1 & 0xff);
        return 1;
    case 0xc8:
        return 1;
    case 0xc9: {
        unsigned char b = ((unsigned char *)msg)[2];
        if (b <= 7)
            func_020aea40(b, ((unsigned char *)msg)[4]);
        return 1;
    }
    case 0xca:
        SetOrClearBitInArray(obj, (unsigned char *)obj + 0x8c, msg->p1 + 0x1198, 1);
        return 1;
    case 0xcb: {
        void *battle = _ZN9GameState11GetInstanceEv();
        void *base = func_ov017_0218b5b0();
        for (int i = 0; i < 4; i++) {
            void *combatant = _Z25GetCombatantWithFlag0x100P9GameStatei(battle, i);
            if (!combatant)
                continue;
            if (!_Z24CheckField0x56bLowNibbleP11Obj02061bd8(combatant))
                continue;
            int hp = *(unsigned short *)((char *)*(void **)((char *)combatant + 0x130) + 4);
            if (hp > 0)
                continue;
            if (msg->p1 == 0) {
                unsigned short val = *(unsigned short *)((char *)*(void **)((char *)combatant + 0x134) + 0x30);
                _Z21ClearFieldBit02053fe4P9T02053fe4(combatant, val, 1);
            } else if (msg->p1 == 1) {
                int val = Field134_30(combatant);
                _Z21ClearFieldBit02053fe4P9T02053fe4(combatant, val / 2, 1);
            } else {
                _Z21ClearFieldBit02053fe4P9T02053fe4(combatant, 1, 1);
            }
            _Z18TryClearFlags0x130Pht(combatant, 1);
            func_ov017_02191108(base, 1, 1, 1, 1);
            _Z21SetByteSavingPreviousP11Foo02033b58h(combatant, 0);
            *(short *)((char *)combatant + 0xb2) = 0;
        }
        return 1;
    }
    case 0xcc:
        func_ov017_02191484(func_ov017_0218b5b0());
        return 1;
    case 0xcd: {
        void *base = func_ov017_0218b5b0();
        _Z19ResetStruct020d3c08Pc(cdLocal);
        _Z31InitAndMaybeStartStream020d3c28P11Obj020d3c28(cdLocal);
        void *elem = _Z29GetElementCount0xb4Stride0x24Phi(cdLocal, msg->p1);
        if (elem) {
            ElemFlags3Bit0d3d78 *f = (ElemFlags3Bit0d3d78 *)((char *)elem + REGION_VALUE(0xb, 0x10));
            func_ov017_021913d0(base, f->field3);
        }
        return 1;
    }
    case 0xce: {
        SetOrClearBitInArray(obj, (unsigned char *)obj + 0x8c, 0x79a, 1);
        void *ctx = func_0202ae18();
        if (func_0202c508(ctx)) {
            int rowBase;
            void *battle = _ZN9GameState11GetInstanceEv();
            void *base = func_ov017_0218b5b0();
            void *table = _Z17GetEntryTableBasev();
            for (int a = 0; a < 4; a++) {
                void *elem = _Z21GetElementStride0x318P21Element0x318_02028baci(table, a);
                if (!((struct Elem2Flags *)((char *)elem + 2))->bit2)
                    continue;
                unsigned short val = *(unsigned short *)elem;
                if ((val / 100) * 100 != 400)
                    continue;
                rowBase = a * 0xc + 0x70;
                for (int b = 0; b < 0xc; b++) {
                    void *c2 = _ZN9GameState27GetMaybeFieldMonsterByIndexEi(battle, b + rowBase);
                    if (!c2)
                        continue;
                    unsigned short v = *(unsigned short *)((char *)c2 + 0x100 + 0x6a);
                    func_ov017_021a23b0(base, v);
                    short p2 = *(short *)((char *)c2 + 2);
                    unsigned short valElem = *(unsigned short *)elem;
                    _Z27EnqueueEventTag134_021c9544iiii(valElem, b, p2, -1);
                }
            }
        }
        return 1;
    }
    case 0xcf: {
        void *pool = &data_02108844;
        if (pool)
            SetOrClearBitInArray(pool, (unsigned char *)pool + 0x8c, 0x384, msg->p1);
        void *base = func_ov017_0218b5b0();
        for (int i = 0; i < 4; i++)
            *(unsigned short *)((char *)base + REGION_VALUE(0x4100, 0x4400) + i * 2 + REGION_VALUE(0x9a, 0x4a)) =
                *(unsigned short *)((char *)msg + i * 2 + 4);
        return 1;
    }
    case 0xd0: {
        void *ctx = func_0202ae18();
        if (func_0202c508(ctx)) {
            void *battle = _ZN9GameState11GetInstanceEv();
            void *p = _Z17GetPtrField0x2a04P9GameState(battle);
            *(unsigned int *)((char *)p + 0x2c94) = msg->p1;
            *(unsigned int *)((char *)battle + REGION_VALUE(0x7c34, 0x7e74)) = msg->p1;
            _Z31EnqueueEventTag23Field_021d0d58v();
        }
        return 1;
    }
    case 0xd1: {
        void *base = func_ov017_0218b5b0();
        void *ctx = func_0202ae18();
        func_0202c288();
        int lvl = *((unsigned char *)ctx + 0x100d);
        if (lvl <= 1)
            return 1;
        _Z28ResetFieldGroup4444_0218b664Pc(base);
        _ZN9GameState11GetInstanceEv();
        signed char b = *((signed char *)base + REGION_VALUE(0x4196, 0x4446));
        _Z27EnqueueEventTag154_021d0860hhh(4, 0, b);
        *((unsigned char *)base + REGION_VALUE(0x4198, 0x4448)) = 1;
        b = *((signed char *)base + REGION_VALUE(0x4196, 0x4446));
        *((unsigned char *)base + REGION_VALUE(0x4197, 0x4447)) = b;
        return 0;
    }
    case 0xd2: {
        void *base = func_ov017_0218b5b0();
        _Z30SetFieldFromHelper491_02198f70Pvh(base, *((signed char *)base + REGION_VALUE(0x4196, 0x4446)));
        return 1;
    }
    case 0xd3: {

        struct Foo
        {
              char unk[0x1840];
            struct Bar {
                char unk[0xb4c];
                unsigned int num;
            } bar;
        };

        struct Sub {
            char unk[0x1000];
            Foo::Bar bar;
        };
        unsigned int mask = 1 << msg->p1;
        ((Sub *)((char *)func_02012fe4() + REGION_VALUE(0x860, 0x840)))->bar.num |= mask;
        return 1;
    }
    case 0xd4:
        func_ov017_0219c520();
        return 1;
    case 0xd5: {
        lr.d0 = 0;
        lr.d1 = 0;
        lr.d2 = 0;
        lr.d3 = 0;
        lr.d4 = 0;
        lr.d0 = (msg->p2 == 0);
        lr.d1 = (msg->p3 == 0);
        lr.d2 = msg->p4;
        lr.d3 = (msg->p5 == 0);
        void *base = func_ov017_0218b5b0();
        _Z25SetName56AndFlag_0218d7b0PhPc(base, (char *)&lr.d0);
        return 1;
    }
    case 0xd6: {
        void *battle = _ZN9GameState11GetInstanceEv();
        lr.fh4 = _Z17GetField5cb0ValuePc(battle);
        lr.fh6 = _Z17GetField5cb4ValuePc(battle);
        lr.fh8 = _Z17GetField5cb8ValuePc(battle);
        AppendNodeToListField30((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    }
    case 0xd7: {
        void *base = func_ov017_0218b5b0();
        func_ov017_021a8614(base, (short)msg->p1, msg->p2, msg->p3, msg->p4, msg->p5);
        return 1;
    }
    case 0xd8: {
        int p1 = *(short *)((char *)msg + 2);
        void *ctx = func_0202ae18();
        if (func_0202c508(ctx)) {
            void *p0 = func_02012fe4();
            *(short *)((char *)p0 + 0x2700 + REGION_VALUE(0xf4, 0xb4)) = p1;
            if (CheckField0NonZero((int *)ctx)) {
                _Z40SetHalfFieldsAndEnqueueIfActive_021d1c2ctt((unsigned char)p1, 0);
                _Z26EnqueueEventTagB5_021d1dc0ssPisi((unsigned short)p1, 0, (int *)&d8Local, 0, 0);
            }
        }
        return 1;
    }
    case 0xd9: {
        void *p = func_ov017_0218b5b0();
        void *list = *(void **)((char *)p + 0x3000 + REGION_VALUE(0x4ec, 0x6fc));
        void *node = *(void **)((char *)p + 0x3000 + REGION_VALUE(0x94c, 0xb6c));
        _Z15InitObj021beba4Pc(node);
        AppendNodeToTail((TailList020469b4 *)list, (TailNode020469b4 *)node);
        return 1;
    }
    case 0xda:
        func_020732cc(msg->p1);
        return 1;
    case 0xdb: {
        dbAlloc.ResetAllocatorPointer();
        dbAlloc.ResetAllocatorPointer();
        void *mem = AllocateAligned4(&data_02114e20, 0x1000);
        dbAlloc.CreateTypeA(mem, 0x1000);
        dbAlloc.Reset();
        void *battle = _ZN9GameState11GetInstanceEv();
        void *p = _Z17GetPtrField0x2a04P9GameState(battle);
        void *r = func_02086f24(p, (unsigned char)msg->p1, &dbAlloc);
        void *signedAlloc = dbAlloc.GetSignedAllocator();
        if (signedAlloc) {
            dbAlloc.Destroy();
            _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, signedAlloc);
        }
        return (int)r;
    }
    case 0xdc:
        func_020aee04(msg->p1, ((unsigned char *)msg)[4]);
        return 1;
    case 0xdd: {
        void *p = func_ov017_0218b5b0();
        func_ov017_021c1a98(p, 1);
        return 1;
    }
    case 0xde: {
        void *p0 = func_02012fe4();
        *((unsigned char *)p0 + 0x2000 + REGION_VALUE(0x810, 0x7d0)) = 0;
        return 1;
    }
    case 0xdf:
        SetOrClearBitInArray(&data_02108844, (unsigned char *)&data_02108844 + 0x8c, 0x799, msg->p1);
        return 1;
    case 0xe0:
        SetOrClearBitInArray(&data_02108844, (unsigned char *)&data_02108844 + 0x8c, 0x798, msg->p1);
        return 1;
    case 0xe3: {
        void *p = func_ov017_0218b5b0();
        (void)p;
        _Z27InitAndAppendEntity020dac40P12Root020dac40();
        return 1;
    }
    case 0xe4: {
        struct BitfieldStruct {
          char unk[0xc8];
            unsigned char low : 2;
            unsigned char foo : 1;
        };
        data_02109bf4.foo = !msg->p1;
        return 1;
    }
    case 0xe5: {
        void *battle = _ZN9GameState11GetInstanceEv();
        unsigned short s5 = *(unsigned short *)((char *)battle + REGION_VALUE(0x6f00, 0x7100) + REGION_VALUE(0x9c, 0xdc));
        short s6 = *(short *)((char *)battle + REGION_VALUE(0x6f00, 0x7100) + REGION_VALUE(0x9e, 0xde));
        short s7 = *(short *)((char *)battle + REGION_VALUE(0x6f00, 0x7100) + REGION_VALUE(0xa0, 0xe0));
        void *p = _Z17GetPtrField0x2a04P9GameState(battle);
        if (s5 == 0)
            return 1;
        if (s6 >= 0 && s6 <= 3) {
            void *combatant = _Z25GetCombatantWithFlag0x100P9GameStatei(battle, s6);
            if (!combatant)
                return 1;
            void *field = _Z15GetFieldAt0x150Ph(combatant);
            _Z27RemoveSlotShiftDown0208386cP13Slots0208386ci(field, (signed char)s7);
        } else {
            _Z25DecrementKeyValue020a0a08P14KeyMap020a0a08ii(p, (short)s5, 1);
        }
        return 1;
    }
    case 0xe6:
        SetOrClearBitInArray(obj, (unsigned char *)obj + 0x8c, msg->p1 + 0xbea, msg->p2);
        return 1;
    case 0xe7: {
        void *ctx = func_0202ae18();
        if (func_0202c540(ctx))
            return 1;
        SetOrClearBitInArray(obj, (unsigned char *)obj + 0x8c, 0x796, msg->p1);
        char *battle = (char*)_ZN9GameState11GetInstanceEv();
        struct StatE7 *st = (struct StatE7 *)((char *)&((struct Blk7400 *)SubA(battle))[1] + 0x3c);
        struct SnapshotE7 *snap = &st->snap;
        if (!snap->done) {
            void *fields = _Z17GetPtrField0x2a04P9GameState(battle);
            int level = 0;
            void *comb = _ZN9GameState14GetProtagonistEv(battle);
            if (comb)
                level = *(*(unsigned short **)((char *)comb + 0x134) + 0x18);
            lr.fword0 = 0;
            _Z24CopyOutBattleField0x7ac0Pv((void *)&lr.fword0);
            _Z23CopyHalfwordAndTwoBytesP19SmallRecord020643e0S0_(snap, st);
            _Z23CopyHalfwordAndTwoBytesP19SmallRecord020643e0S0_((char *)snap + 4, &st->r4);
            snap->a_lo = st->w8.v24;
            snap->a_mid = _Z22GetFieldPercentOver307P7S_a0870(st);
            snap->a_hi = _Z22GetFieldPercentOver448P7S_a090c(st);
            snap->b_lo = lr.fword0;
            snap->b_mid = _Z22GetFieldPercentOver232P7S_a08a4(st);
            snap->b_hi = _Z22GetFieldPercentOver944P7S_a08d8(st);
            snap->c_lo = st->w10.v9;
            snap->c_mid = st->wc.v14;
            snap->d_lo = st->w8.hi8;
            snap->d_mid = st->w10.v14;
            snap->d_hi = level;
            snap->e_lo = st->w40.v24;
            snap->total = *(unsigned int *)((char *)fields + 0xf6c) + *(unsigned int *)((char *)fields + 0xf68);
            snap->done = 1;
        }
        return 1;
    }
    case 0xe8: {
        void *g = _Z20GetGlobalPtr021075f4v();
        void *entry = _Z29FindEntryPointerByKey0203df78Pvi(g, msg->p1);
        if (!entry)
            return 1;
        void *f = _Z19GetField0xc02040538P9S02040538(entry);
        if (!f)
            return 1;
        unsigned char b = *((unsigned char *)f + 0xa);
        b = (b & ~0x38) | (((unsigned char)msg->p2 & 7) << 3);
        *((unsigned char *)f + 0xa) = b;
        return 1;
    }
    case 0xe9:
        _Z21SyncEightElementFlagsv();
        return 1;
    case 0x6f: case 0x70: case 0x71: case 0x98: case 0x9a: case 0xa3:
        break;
    default:
        break;
    }
    return 0;
}
