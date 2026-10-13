#include <globaldefs.h>

#if defined(jpn)
#define func_0200e830 func_0200e6f4
#define func_0200df80 func_0200de44
#define func_0200f2ec func_0200f1b0
#endif

struct ExceptionContext {
    const char* typeName;
    void* exceptionObject;
    unsigned int cleanup;
    void* currentException;
    unsigned int returnAddress;
    void* savedStack;
    void* frameBase;
};

struct ExceptionTableCursor {
    unsigned int functionStart;
    void* header;
    void* cursor;
    void* rangeStart;
    void* rangeEnd;
    unsigned int unknown14;
};

struct HandlerMatch {
    int objectAdjustment;
    const char* typeName;
    int handlerOffset;
    int exceptionSlotOffset;
};

extern "C" void* func_0200dad4(unsigned int, ExceptionTableCursor*);
extern "C" void func_0200efb8();
extern "C" void func_0200f1fc(ExceptionContext*, ExceptionTableCursor*);
extern "C" void* func_0200e830(ExceptionContext*, ExceptionTableCursor*);
extern "C" unsigned char* func_0200ea68(ExceptionContext*, ExceptionTableCursor*, HandlerMatch*);
extern "C" void* func_0200d9e4(void*, int*);
extern "C" void* func_0200d958(void*, int*);
extern "C" void func_0200df80(ExceptionContext*, ExceptionTableCursor*, unsigned char*);
extern "C" void func_0200ec44(ExceptionContext*, int, int);
extern "C" void func_0200f2ec(ExceptionContext*, ExceptionTableCursor*, unsigned int);

// USA: func_0200eca0
// KEEP-NAME
extern "C" ARM void func_0200eca0(ExceptionContext* context) {
    ExceptionTableCursor table;
    HandlerMatch handler;
    func_0200dad4(context->returnAddress, &table);
    if (!table.header) func_0200efb8();
    func_0200f1fc(context, &table);
    if (context->typeName) context->currentException = 0;
    else {
        context->currentException = func_0200e830(context, &table);
        if (!context->currentException) func_0200efb8();
    }
    unsigned char* record = func_0200ea68(context, &table, &handler);
    handler.typeName = (const char*)(record[1] | record[2] << 8 | record[3] << 16 | record[4] << 24);
    void* cursor = func_0200d9e4(record + 5, &handler.handlerOffset);
    func_0200d958(cursor, &handler.exceptionSlotOffset);
    func_0200df80(context, &table, record);
    func_0200ec44(context, handler.exceptionSlotOffset, handler.objectAdjustment);
    func_0200f2ec(context, &table, table.functionStart + handler.handlerOffset);
}
