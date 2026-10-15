#include <globaldefs.h>
#include "System/Matrix.h"
#include "Graphics/Vector.h"

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

// USA: func_02013158
extern "C" ARM void func_02013158(Node13158* self, const Vector3fix* base, int* angle, const Vector3fix* scale)
{
    Matrix3x3 mat;
    int sine;
    int cosine;
    Node13158* n;
    cosine = fix32cos(*angle);
    sine = fix32sin(*angle);
    Mat3x3_WriteRotationY(&mat, sine, cosine);
    if (self->model != 0)
    {
        Vector3fix v;
        Mat3x3_ApplyToVector(&self->model->offset, &mat, &v);
        Vector3fix_Add(&v, base, &self->pos);
        self->heading = (int16_t)fix32ReduceAngle0To2Pi(*angle + self->model->rotZ);
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
                n->heading = (int16_t)fix32ReduceAngle0To2Pi(*angle + n->model->rotZ);
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
