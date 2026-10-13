#include <globaldefs.h>
#include <Graphics/NSBXX/RenderCommands_Common.h>

extern "C" int func_ov031_0220eb88(int);
extern "C" int func_ov031_0220eb30(void);
extern "C" int _Z30GetOffset10FromResult_0220ec04i(int);

// USA: func_ov031_0221efe8
extern "C" THUMB int func_ov031_0221efe8(unsigned char* destination, int capacity) {
    func_ov031_0220eb88(1);
    int count = func_ov031_0220eb30();
    if (count > 0) {
        int index = 0;
        if (index < count) do {
            if (index >= capacity) break;
            func_020ca408(reinterpret_cast<const void*>(_Z30GetOffset10FromResult_0220ec04i((unsigned short)index)), destination, 0xc0);
            ++index;
            destination += 0xc0;
        } while (index < count);
    }
    func_ov031_0220eb88(0);
    return count;
}