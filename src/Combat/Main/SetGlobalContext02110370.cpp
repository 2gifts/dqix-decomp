#include <globaldefs.h>

extern void* data_02110370;

// USA: func_020bd42c
ARM void* SetGlobalContext02110370_020bd42c(void* value) {
    void* previous = data_02110370;
    data_02110370 = value;
    return previous;
}
