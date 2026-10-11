// JPN: func_ov025_021dcf8c
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "std_library_functions.h"

#if defined(jpn)
enum { Field2a8 = 0x224, Field14c = 0x138, Field29c = 0x218, Fieldeac = 0xe28, Field5724 = 0x5914 };
#else
enum { Field2a8 = 0x2a8, Field14c = 0x14c, Field29c = 0x29c, Fieldeac = 0xeac, Field5724 = 0x5724 };
#endif

extern "C" void* _Z18GetSlotPtr02160f20Pv(void* obj);
void* GetData02108e10(void);
extern "C" void* _Z24SearchBothTables02079e2cPci(char* p, int key);
extern "C" void func_ov025_021e88d8(void* obj);
extern "C" void _Z21SetTwoFields_021e8a40Pcii(char* obj, int a, int b);
extern "C" void _Z17SetField_021e8a4cPci(char* obj, int v);
extern "C" void func_ov025_021e8d20(void* obj, int v);
extern "C" void func_ov025_021db8d8(void* obj);
extern "C" void* func_ov000_02169a58(char* node, int value);

struct StreamHeader;
extern "C" ARM void _Z24RunOverlayScript0216d1c4iP12StreamHeaderiPi(int arg0, struct StreamHeader* buffer, int length, int* out);

extern int data_ov025_021ef404;
extern char data_ov025_021ef454[];
extern "C" char _ZZ16GetTimer021ef974vE1s[];

struct SearchEntry_021dc694 {
    char pad0[4];
    unsigned int key : 12;
    char pad1[0x18 - 0x8];
    unsigned int : 5;
    unsigned int classField : 7;
};

// USA: func_ov025_021dc694
extern "C" ARM void func_ov025_021dc694(void* arg) {
    char* obj = (char*)arg;
    void* slot = _Z18GetSlotPtr02160f20Pv(obj);
    BackgroundLoader* loader = BackgroundLoader::GetInstance();

    if (loader->GetTaskStatus(data_ov025_021ef404) == 0) {
        return;
    }

    void* filePtr = 0;
    unsigned int fileLen = 0;
    loader->GetLoadedFileByID(data_ov025_021ef404, &filePtr, &fileLen);

    void* table = GetData02108e10();
    struct SearchEntry_021dc694* entry = (struct SearchEntry_021dc694*)_Z24SearchBothTables02079e2cPci((char*)table, *(short*)slot);

    if (filePtr != 0 && fileLen != 0 && entry != 0) {
        char pathBuf[0x50];
        sprintf(pathBuf, data_ov025_021ef454, entry->key);

        const void* narcPtr = 0;
        unsigned int narcLen = 0;
        if (GetFileInNarc(filePtr, pathBuf, &narcPtr, &narcLen, 0)) {
            int scriptOut = 0;
            _Z24RunOverlayScript0216d1c4iP12StreamHeaderiPi((int)(obj + 0x30), (struct StreamHeader*)narcPtr, narcLen, &scriptOut);
            if (scriptOut != 0) {
                func_ov025_021e88d8(obj + Field2a8);
                _Z21SetTwoFields_021e8a40Pcii(obj + Field2a8, (int)(obj + 0x30), (int)(obj + Field14c));
                _Z17SetField_021e8a4cPci(obj + Field2a8, *(int*)(obj + Field29c));
                func_ov025_021e8d20(obj + Field2a8, scriptOut);
                func_ov025_021db8d8(obj);
            }
        }
    }

    int status = *(int*)(obj + Fieldeac);
    if (status != 3 && status != 2 && status != 6) {
        int classField = entry->classField;
        int val = entry->key;
        if (classField == 0xc) {
            val = 0x158;
        }
        char* node = *(char**)(obj + Field5724);
        int result2 = (int)func_ov000_02169a58(node, val);
        if (result2 != 0) {
            func_ov025_021e88d8(obj + Field2a8);
            _Z21SetTwoFields_021e8a40Pcii(obj + Field2a8, (int)(obj + 0x30), (int)(obj + Field14c));
            _Z17SetField_021e8a4cPci(obj + Field2a8, *(int*)(obj + Field29c));
            func_ov025_021e8d20(obj + Field2a8, result2);
            func_ov025_021db8d8(obj);
        } else {
            *(int*)(obj + Fieldeac) = 5;
            *(int*)(_ZZ16GetTimer021ef974vE1s + 0x10) = 0;
            *(int*)(_ZZ16GetTimer021ef974vE1s + 8) = 0;
        }
    }

    loader->RemoveTask(data_ov025_021ef404);
    data_ov025_021ef404 = -1;
}
