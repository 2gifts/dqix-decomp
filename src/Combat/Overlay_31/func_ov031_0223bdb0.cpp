#include <globaldefs.h>
#include <Graphics/NSBXX/RenderCommands_Common.h>

struct PackedRecordTableEntry {
    unsigned short count;
    unsigned short reserved;
    unsigned int offset;
};
struct HalfwordRecord {
    unsigned short fields[3];
    unsigned short reserved;
};
extern PackedRecordTableEntry* data_ov031_02290d2c[];
extern "C" void func_020ca3b8(const void* source, void* destination, unsigned int size);

// USA: func_ov031_0223bdb0
extern "C" ARM void func_ov031_0223bdb0(int tableIndex, int entryIndex, void* destination) {
    PackedRecordTableEntry* table = data_ov031_02290d2c[tableIndex];
    const unsigned char* source = (const unsigned char*)table + table[entryIndex].offset;
    int count = table[entryIndex].count;
    HalfwordRecord temporary;
    func_020ca3ec(0, &temporary, sizeof(temporary));
    HalfwordRecord* output = (HalfwordRecord*)destination;
    int i = 0;
    if (count <= 0) {
        return;
    }
    do {
        func_020ca3b8(source, &temporary, 6);
        func_020ca408(&temporary, output, sizeof(temporary));
        i++;
        source += 6;
        output++;
    } while (i < count);
}
