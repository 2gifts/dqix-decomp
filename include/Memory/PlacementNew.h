#pragma once

inline void* operator new(unsigned long, void* storage)
{
    return storage;
}
