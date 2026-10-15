#include <globaldefs.h>

struct RenderSource0204bf44 {
    int type;
    int shift;
    short s8;
    short sa;
    short sc;
    short se;
    short s10;
    short s12;
    int pad14;
    int pad18;
    int m1c;
    unsigned int m20;
    int o24;
    int o28;
    int o2c;
    int o30;
    int pad34;
    int o38;
};

struct RenderParams0204bf44 {
    struct RenderSource0204bf44 *src;
    char *p4;
    char *p8;
    char *pc;
    char *p10;
    char *p14;
    int d18;
    int d1c;
    int d20;
    int d24;
    int d28;
    int d2c;
    int pad30[6];
    int d48;
};

// USA: func_0204bf44
ARM void InitRenderParams0204bf44(RenderParams0204bf44* d, int arg1, RenderSource0204bf44* s, unsigned int) {
    d->src = s;
    d->p4 = (char*)s + d->src->o24;
    d->p8 = (char*)s + d->src->o28;
    d->pc = (char*)s + d->src->o2c;
    d->p10 = (char*)s + d->src->o30;
    if (d->src->type == 3) {
        d->p14 = (char*)s + d->src->o38;
    }
    d->d24 = d->src->s8 << d->src->shift;
    d->d28 = d->src->sa << d->src->shift;
    d->d2c = d->src->sc << d->src->shift;
    d->d18 = d->src->se << d->src->shift;
    d->d1c = d->src->s10 << d->src->shift;
    d->d20 = d->src->s12 << d->src->shift;
    d->d48 = d->src->m1c * d->src->m20 + (d->src->m20 >> 1);
}
