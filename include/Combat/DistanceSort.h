#pragma once

struct SortEntry_02056c3c {
    void *node;
    union {
        int key;
        float distance;
    };
};

extern "C" void func_02056c3c(void *base, SortEntry_02056c3c *entries, const int low, const int high);
extern "C" void func_0205765c(int value);
void ForwardField4To0205765c(int *obj);
