#include <globaldefs.h>

#include "Combat/NodeLookup.h"
#include "Combat/WorkRecord.h"

// USA: func_0206db48
extern "C" ARM void func_0206db48(void *receiver, Rec0206bf2c *record) {
    Rec0206bf2c *node = (Rec0206bf2c *) FindNodeByByteId(receiver, record->field0);
    int category;
    if (record->flagsA_b1) {
        category = 0;
    } else if (record->flagsA_b3) {
        category = 1;
    } else if (record->field46 >= 0) {
        category = 2;
    } else if (record->field5 && !record->field8) {
        category = 3;
    } else if (record->field8) {
        category = 4;
    } else {
        category = 5;
    }
    if (node != 0) {
        while (node != 0) {
            int otherCategory;
            if (node->flagsA_b1) {
                otherCategory = 0;
            } else if (node->flagsA_b3) {
                otherCategory = 1;
            } else if (node->field46 >= 0) {
                otherCategory = 2;
            } else if (node->field5 && !node->field8) {
                otherCategory = 3;
            } else if (node->field8) {
                otherCategory = 4;
            } else {
                otherCategory = 5;
            }
            bool before = false;
            if (category < otherCategory) {
                before = true;
            } else if (category == otherCategory) {
                if (category == 4 || category == 1) {
                    int key      = record->field4 * 1000 + record->field5 * 10 + record->field6;
                    int otherKey = node->field4 * 1000 + node->field5 * 10 + node->field6;
                    if (key == otherKey && record->field44 < node->field44) {
                        before = true;
                    } else if (key < otherKey) {
                        before = true;
                    }
                } else if (record->field44 < node->field44) {
                    before = true;
                }
            }
            if (before) {
                break;
            }
            node = node->field70;
        }
        if (node == 0) {
            return;
        }
        if (node->field6c == 0) {
            if (node->field64 != 0) {
                node->field64->field68 = record;
            }
            if (node->field68 != 0) {
                node->field68->field64 = record;
            }
            record->field64 = node->field64;
            record->field68 = node->field68;
            node->field64   = 0;
            node->field68   = 0;
            if (record->field64 == 0) {
                *(Rec0206bf2c **) receiver = record;
            }
        }
        if (node->field6c != 0) {
            node->field6c->field70 = record;
        }
        record->field6c = node->field6c;
        record->field70 = node;
        node->field6c   = record;
    } else {
        if (*(Rec0206bf2c **) receiver != 0) {
            (*(Rec0206bf2c **) receiver)->field64 = record;
        }
        record->field68            = *(Rec0206bf2c **) receiver;
        *(Rec0206bf2c **) receiver = record;
    }
}
