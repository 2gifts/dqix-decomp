#include <globaldefs.h>
#include "Combat/ActorAction.h"

#if defined(jpn)
enum { kOffset26c = 0x260 };
#else
enum { kOffset26c = 0x26c };
#endif

// USA: func_020398b4
ARM void CopyBlockTo0x26c(GameObject* obj, SubBlock02038508* src) {
    ((SubBlock02038508*)((char*)obj + kOffset26c))->active = src->active;
    ((SubBlock02038508*)((char*)obj + kOffset26c))->command = src->command;
    ((SubBlock02038508*)((char*)obj + kOffset26c))->unknown2 = src->unknown2;
    ((SubBlock02038508*)((char*)obj + kOffset26c))->reversed = src->reversed;
    ((SubBlock02038508*)((char*)obj + kOffset26c))->unknown4 = src->unknown4;
    ((SubBlock02038508*)((char*)obj + kOffset26c))->heading = src->heading;
    ((SubBlock02038508*)((char*)obj + kOffset26c))->startHeading = src->startHeading;
    ((SubBlock02038508*)((char*)obj + kOffset26c))->endHeading = src->endHeading;
    ((SubBlock02038508*)((char*)obj + kOffset26c))->start = src->start;
    ((SubBlock02038508*)((char*)obj + kOffset26c))->end = src->end;
    ((SubBlock02038508*)((char*)obj + kOffset26c))->unknown24 = src->unknown24;
    ((SubBlock02038508*)((char*)obj + kOffset26c))->startControl = src->startControl;
    ((SubBlock02038508*)((char*)obj + kOffset26c))->endControl = src->endControl;
    ((SubBlock02038508*)((char*)obj + kOffset26c))->unknown48 = src->unknown48;
    ((SubBlock02038508*)((char*)obj + kOffset26c))->unknown4c = src->unknown4c;
    ((SubBlock02038508*)((char*)obj + kOffset26c))->unknown50 = src->unknown50;
    ((SubBlock02038508*)((char*)obj + kOffset26c))->unknown52 = src->unknown52;
    ((SubBlock02038508*)((char*)obj + kOffset26c))->unknown53 = src->unknown53;
    ((SubBlock02038508*)((char*)obj + kOffset26c))->unknown54 = src->unknown54;
    ((SubBlock02038508*)((char*)obj + kOffset26c))->startNode = src->startNode;
    ((SubBlock02038508*)((char*)obj + kOffset26c))->endNode = src->endNode;
    ((SubBlock02038508*)((char*)obj + kOffset26c))->unknown60 = src->unknown60;
}
