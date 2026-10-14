#pragma once

#include <Memory/SafeAllocator.h>

struct GameResources;
struct Node02046a3c;

// Prefix initialized by Init021a124c. Allocation extent is not specified here.
struct ResourceInsertionNode {
    signed char type;
    unsigned char complete;
    unsigned char inList;
    unsigned char unknown3;
    Node02046a3c* next;
    SafeAllocator allocator;
    void* context;
    unsigned char mode;
    unsigned char selection;
    unsigned char unknown22;
};

void SetNodeFieldsAndInsert_021a120c(GameResources* resources, int mode, int selection);
