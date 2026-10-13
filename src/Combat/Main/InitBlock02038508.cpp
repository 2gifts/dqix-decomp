#include <globaldefs.h>
#include "Combat/ActorAction.h"

// USA: func_02038508
ARM void InitBlock02038508(struct SubBlock02038508* p) {
    p->active = 0;
    p->command = 0;
    p->unknown2 = 0;
    p->reversed = 0;
    p->unknown4 = 0;
    p->heading = 0;
    p->startHeading = 0;
    p->endHeading = 0;
    p->unknown48 = 0;
    p->unknown4c = 0;
    p->unknown50 = 0;
    p->unknown52 = 0;
    p->unknown53 = 1;
    p->unknown54 = 0x64;
    p->startNode = 0;
    p->endNode = 0;
    p->unknown60 = 0;
    p->start.entries[0] = 0; p->start.entries[1] = 0; p->start.entries[2] = 0;
    p->end.entries[0] = 0; p->end.entries[1] = 0; p->end.entries[2] = 0;
    p->unknown24.entries[0] = 0; p->unknown24.entries[1] = 0; p->unknown24.entries[2] = 0;
    p->startControl.entries[0] = 0; p->startControl.entries[1] = 0; p->startControl.entries[2] = 0;
    p->endControl.entries[0] = 0; p->endControl.entries[1] = 0; p->endControl.entries[2] = 0;
}
