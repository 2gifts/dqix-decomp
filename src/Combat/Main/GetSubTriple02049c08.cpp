#include <globaldefs.h>
#include "GameState/GameState.h"
#include "System/Matrix.h"

extern "C" void __clear(void* destination, int size);

struct ObjectVectors02049c08 {
    int unknown0;
    Vector3i vector4;
    Vector3i vector10;
};

struct Obj02049c08 {
    GameObject base;
    ObjectVectors02049c08* vectors;
};

ARM Vector3i GetSubTriple02049c08(Obj02049c08* object) {
    Vector3i result;
    __clear(&result, sizeof(result));
    if (object->vectors == NULL) return result;
    fix32_t x = object->vectors->vector10.x;
    fix32_t z = object->vectors->vector10.z;
    result.x = x;
    result.y = 0xcc;
    result.z = z;
    return result;
}
