#include <globaldefs.h>

#include "Combat/Main/MessageSlotTable.h"

// USA: func_020dd9b4
extern "C" ARM void func_020dd9b4(MessageSlotTable_020dd7ac *table, unsigned int kind, void *firstValue, void *secondValue) {
    if (firstValue == 0 || secondValue == 0) {
        return;
    }
    if (kind >= 12) {
        return;
    }
    switch (kind) {
        case 0:
            *(unsigned short *) firstValue  = table->f3c;
            *(unsigned short *) secondValue = table->f3e;
            return;
        case 1:
            *(unsigned short *) firstValue  = table->f40;
            *(unsigned short *) secondValue = table->f42;
            return;
        case 2:
            *(int *) firstValue  = table->f44;
            *(int *) secondValue = table->f48;
            return;
        case 3:
            *(int *) firstValue  = table->f4c;
            *(int *) secondValue = table->f50;
            return;
        case 4:
            *(int *) firstValue  = table->f54;
            *(int *) secondValue = table->f58;
            return;
        case 5:
            *(int *) firstValue  = table->f5c;
            *(int *) secondValue = table->f60;
            return;
        case 6:
            *(unsigned short *) firstValue  = table->f64;
            *(unsigned short *) secondValue = table->f66;
            return;
        case 7:
            *(unsigned short *) firstValue  = table->f68;
            *(unsigned short *) secondValue = table->f6a;
            return;
        case 8:
            *(unsigned short *) firstValue  = table->f6c;
            *(unsigned short *) secondValue = table->f6e;
            return;
        case 9:
            *(unsigned short *) firstValue  = table->f70;
            *(unsigned short *) secondValue = table->f72;
            return;
        case 10:
            *(unsigned short *) firstValue  = table->f74;
            *(unsigned short *) secondValue = table->f76;
            return;
        case 11:
            *(unsigned short *) firstValue  = table->f78;
            *(unsigned short *) secondValue = table->f7a;
            return;
    }
}
