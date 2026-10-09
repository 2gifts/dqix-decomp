#include <globaldefs.h>
struct HeaderStruct { unsigned short* arr; unsigned short capacity, count, size, mask; };
struct SortedU16List0203e6c8 { unsigned short* arr; unsigned short capacity, count, size, mask; };
struct SortedU16List0203e63c { unsigned short* arr; unsigned short capacity, count, size, mask; };
void ResetHeader(HeaderStruct*);
int InsertKeyInSortedU16List(SortedU16List0203e6c8*, unsigned int);
unsigned char FindKeyInSortedU16List(SortedU16List0203e63c*, unsigned int);
void CleanInvalidateCacheRange(const void*, unsigned int);
// USA: func_0203e7b4
extern "C" ARM int func_0203e7b4(HeaderStruct* header, unsigned short* list, unsigned char* output, unsigned short* input, int capacity, int width, int height, int stride) {
    ResetHeader(header);
    if (!list || !output || !input) return 0;
    header->arr = list;
    header->capacity = capacity;
    header->mask = 0xfbde;
    header->arr[0] = 0x3e0;
    header->count++;
    header->size = 1;
    unsigned short* row;
    int y;
    int x;
    int remaining;
    remaining = height;
    row = input;
    for (y = remaining; y != 0; ) {
        unsigned short* p = row;
        for (x = width; x != 0; --x) {
            InsertKeyInSortedU16List((SortedU16List0203e6c8*)header, *p);
            p++;
        }
        --y;
        row += stride;
    }
    CleanInvalidateCacheRange(header->arr, header->count * 2);
    unsigned char* outrow = output;
    for (; remaining != 0; ) {
        unsigned char* dest = outrow;
        unsigned short* p = input;
        for (x = width; x != 0; --x) {
            *dest = FindKeyInSortedU16List((SortedU16List0203e63c*)header, *p++);
            dest++;
        }
        --remaining;
        outrow += width;
        input += stride;
    }
    CleanInvalidateCacheRange(output, width * height);
    ResetHeader(header);
    return 1;
}
