#include <globaldefs.h>
struct Values0208b788 { int x, y; float scale; unsigned short value; unsigned short pad; };
struct Table0208b788 { Values0208b788 rows[3]; };
extern Table0208b788 data_020e8d0c;
// USA: func_0208b788
extern "C" ARM void func_0208b788(int index, float factor, Values0208b788* out, int adjust) {
    Table0208b788 table = data_020e8d0c;
    if (adjust) table.rows[0].scale = 1.2f;
    Values0208b788* start = &table.rows[index];
    Values0208b788* end = &table.rows[index + 1];
    out->x = (int)((float)start->x + factor * (float)(end->x - start->x));
    out->y = (int)((float)start->y + factor * (float)(end->y - start->y));
    out->scale = start->scale + factor * (end->scale - start->scale);
    out->value = (unsigned int)((float)(unsigned int)start->value + factor * (float)(end->value - start->value));
}
