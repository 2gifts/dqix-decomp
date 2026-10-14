#include <globaldefs.h>

struct Obj0223c534;
struct Collection02226d48 {
    Obj0223c534* entries[4];
    void* unknown_0x10[10];
    void* unknown_0x38[2];
    void* unknown_0x40[2];
    void* entryResources[4];
};
extern Collection02226d48* data_ov031_02250c00;
extern Collection02226d48* data_ov031_02250c00_arg;
extern "C" void func_ov031_0223e2c0(int, void*);
extern "C" void func_ov031_0223ba20(void*);
void ProcessField28AndDispatch670_0223c534(Obj0223c534*);
extern "C" void func_ov031_0223da58(void*);
extern "C" void func_ov031_0223cf70(Collection02226d48**);

// USA: func_ov031_02226d48
extern "C" ARM void func_ov031_02226d48(void* object) {
    func_ov031_0223e2c0(0, object);
    {
        int i = 0;
        do {
            func_ov031_0223ba20(data_ov031_02250c00->entryResources[i]);
            ProcessField28AndDispatch670_0223c534(data_ov031_02250c00->entries[i]);
        } while (++i < 4);
    }
    {
        int i = 0;
        do { func_ov031_0223ba20(data_ov031_02250c00->unknown_0x40[i]); } while (++i < 2);
    }
    {
        int i = 0;
        do { func_ov031_0223da58(data_ov031_02250c00->unknown_0x38[i]); } while (++i < 2);
    }
    {
        int i = 0;
        do { func_ov031_0223da58(data_ov031_02250c00->unknown_0x10[i]); } while (++i < 10);
    }
    func_ov031_0223cf70(&data_ov031_02250c00_arg);
}
