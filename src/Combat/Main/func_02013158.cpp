#include <globaldefs.h>

typedef long long int64_t;
typedef short int16_t;

#define FIX32_MULTIPLY(a,b) (int)(((int64_t)(a) * (int64_t)(b) + (int64_t)0x800) >> (int64_t)12)

struct Vector3fix
{
    int x;
    int y;
    int z;
};

struct Matrix3x3
{
    int entries[9];
};

struct Model13158
{
    char pad_0[8];
    Vector3fix offset;
    char pad_14[2];
    int16_t rotZ;
    char pad_18[2];
    int16_t m1;
    int16_t m2;
    int16_t m3;
};

struct Node13158
{
    char pad_0[6];
    int16_t heading;
    Vector3fix pos;
    Vector3fix rot;
    Model13158* model;
    char pad_24[8];
    Node13158* child;
    Node13158* next;
};

extern "C" void Mat3x3_WriteRotationY(Matrix3x3* out, int sine, int cosine);
extern "C" void Mat3x3_ApplyToVector(const Vector3fix* inVec, const Matrix3x3* inMat, Vector3fix* out);
extern "C" void Vector3fix_Add(const Vector3fix* a, const Vector3fix* b, Vector3fix* out);
extern "C" int _Z8fix32cosi(int x);
extern "C" int _Z8fix32sini(int x);
extern "C" int _Z22fix32ReduceAngle0To2Pii(int angle);

// USA: func_02013158
extern "C" ARM void func_02013158(Node13158* self, const Vector3fix* base, int* angle, const Vector3fix* scale)
{
    Matrix3x3 mat;
    int sine;
    int cosine;
    Node13158* n;
    cosine = _Z8fix32cosi(*angle);
    sine = _Z8fix32sini(*angle);
    Mat3x3_WriteRotationY(&mat, sine, cosine);
    if (self->model != 0)
    {
        Vector3fix v;
        Mat3x3_ApplyToVector(&self->model->offset, &mat, &v);
        Vector3fix_Add(&v, base, &self->pos);
        self->heading = (int16_t)_Z22fix32ReduceAngle0To2Pii(*angle + self->model->rotZ);
        self->rot.x = FIX32_MULTIPLY(self->model->m1, scale->x);
        self->rot.y = FIX32_MULTIPLY(self->model->m2, scale->y);
        self->rot.z = FIX32_MULTIPLY(self->model->m3, scale->z);
    }
    n = self->next;
    if (n != 0)
    {
        while (n != 0)
        {
            Vector3fix w;
            int a;
            if (n->model != 0)
            {
                Mat3x3_ApplyToVector(&n->model->offset, &mat, &w);
                Vector3fix_Add(&w, base, &n->pos);
                n->heading = (int16_t)_Z22fix32ReduceAngle0To2Pii(*angle + n->model->rotZ);
                n->rot.x = FIX32_MULTIPLY(n->model->m1, scale->x);
                n->rot.y = FIX32_MULTIPLY(n->model->m2, scale->y);
                n->rot.z = FIX32_MULTIPLY(n->model->m3, scale->z);
            }
            if (n->child != 0)
            {
                a = n->heading;
                func_02013158(n->child, &n->pos, &a, &n->rot);
            }
            n = n->next;
        }
    }
    if (self->child != 0)
    {
        int b;
        b = self->heading;
        func_02013158(self->child, &self->pos, &b, &self->rot);
    }
}