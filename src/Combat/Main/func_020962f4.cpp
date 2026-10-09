#include <globaldefs.h>
#include <std_library_functions.h>

struct PackedNibbleArray0206e120;
struct SearchRecord {
    unsigned int index : 9;
    unsigned int flags : 23;
    unsigned int words[3];
};
struct SortedSearchRecords { unsigned char count; char pad1[3]; SearchRecord records[8]; };
extern "C" PackedNibbleArray0206e120* func_0205ec34();
extern "C" void func_0206e164(PackedNibbleArray0206e120*, int, int);

// USA: func_020962f4
extern "C" ARM int func_020962f4(SortedSearchRecords* table, SearchRecord record) {
    SearchRecord saved[8];
    if (table->count >= 8) return 0;
    if (!table->count) memcpy(table->records, &record, 16);
    else {
        memcpy(saved, table->records, 128);
        unsigned char lower = 0;
        unsigned char upper = table->count - 1;
        while (upper - lower > 1) {
            unsigned char middle = (upper + lower) / 2;
            if (record.index == table->records[middle].index) return 0;
            if (table->records[middle].index < record.index) lower = middle;
            else if (table->records[middle].index > record.index) upper = middle;
        }
        if (table->records[lower].index <= record.index) {
            if (table->records[upper].index < record.index) lower = upper + 1;
            else lower = upper;
        }
        if (lower < table->count) memcpy(&table->records[lower + 1], &saved[lower], (table->count - lower) * 16);
        memcpy(&table->records[lower], &record, 16);
    }
    func_0206e164(func_0205ec34(), record.index, 2);
    ++table->count;
    return 1;
}
