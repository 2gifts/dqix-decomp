#include <globaldefs.h>
#include "System/ProcessorContext.h"

struct ContextIdentifierState {
    char unknown0[8];
    unsigned short currentIdentifier;
};

struct ContextIdentifierRecord {
    int active;
    char unknown4[6];
    unsigned short identifier;
};

extern ContextIdentifierState data_ov031_0224c980;

// USA: func_ov031_02203078
extern "C" ARM unsigned short func_ov031_02203078(void) {
    int duplicate;
    ProcessorContext* context;
    unsigned short identifier;
    ProcessorContext* firstContext = data_02111304.firstContext;
    do {
        duplicate = 0;
        ++data_ov031_0224c980.currentIdentifier;
        if (data_ov031_0224c980.currentIdentifier < 1024 ||
            data_ov031_0224c980.currentIdentifier >= 5000) {
            data_ov031_0224c980.currentIdentifier = 1024;
        }
        context = firstContext;
        if (context != NULL) {
            identifier = data_ov031_0224c980.currentIdentifier;
            do {
                ContextIdentifierRecord* record = (ContextIdentifierRecord*)context->unknown_A4;
                if (record != NULL && record->active != 0 &&
                    record->identifier == identifier) {
                    duplicate = 1;
                    break;
                }
                context = context->pNext;
            } while (context != NULL);
        }
    } while (duplicate != 0);
    return data_ov031_0224c980.currentIdentifier;
}
