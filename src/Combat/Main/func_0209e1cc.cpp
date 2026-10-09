#include <globaldefs.h>

#include "Combat/Main/CandidateFilter.h"
#include <std_library_functions.h>

struct CandidateKindWord {
    unsigned short unknown0 : 2;
    unsigned short kind : 4;
    unsigned short unknown6 : 10;
};

struct CandidateClassByte {
    unsigned char classification : 4;
    unsigned char unknown4 : 4;
};

struct CandidatePayloadWord {
    unsigned char bytes[4];
};

struct CandidateFilterPrefix {
    unsigned int primaryFlags;
    unsigned char unknown04[4];
    unsigned int secondaryFlags;
    unsigned char unknown0c[12];
    CandidateKindWord primaryKind;
    CandidateKindWord secondaryKind;
    CandidateClassByte primaryClass;
    CandidateClassByte secondaryClass;
    unsigned char unknown1e[10];
    CandidatePayloadWord primaryPayload;
    CandidatePayloadWord secondaryPayload;
};

// USA: func_0209e1cc
extern "C" ARM int func_0209e1cc(void *receiver, void *record, int mode, int parameter) {
    unsigned int mask;
    CandidateFilterPrefix *candidate;
    unsigned int kind;
    unsigned int classification;
    CandidatePayloadWord payload;
    unsigned int flags;

    mask      = static_cast<unsigned int>(parameter);
    candidate = static_cast<CandidateFilterPrefix *>(record);

    if (mode == 0) {
        kind           = candidate->primaryKind.kind;
        flags          = candidate->primaryFlags;
        classification = candidate->primaryClass.classification;
        memcpy(&payload, &candidate->primaryPayload, sizeof(payload));
    } else {
        kind           = candidate->secondaryKind.kind;
        classification = candidate->secondaryClass.classification;
        flags          = candidate->secondaryFlags;
        memcpy(&payload, &candidate->secondaryPayload, sizeof(payload));
    }

    if ((mask & 0x1) && (flags & 0x80000) && kind == 2) return 1;
    if ((mask & 0x2) && (flags & 0x80000) && kind == 3) return 1;
    if ((mask & 0x4) && (flags & 0x80000) && kind == 5) return 1;
    if ((mask & 0x8) && (flags & 0x80000) && kind == 4) return 1;
    if ((mask & 0x10) && (flags & 0x80000) && kind == 7) return 1;
    if ((mask & 0x20) && (flags & 0x80000) && kind == 6) return 1;
    if ((mask & 0x40) && (flags & 0x80000) && kind == 8) return 1;
    if ((mask & 0x80) && (flags & 0x80000) && kind == 10) return 1;
    if ((mask & 0x100) && (flags & 0x80000) && kind == 9) return 1;
    if ((mask & 0x200) && (flags & 0x80000) && kind == 1) return 1;
    if ((mask & 0x400) && classification == 1) return 1;
    if ((mask & 0x800) && classification == 2) return 1;
    if ((mask & 0x1000) && classification == 4) return 1;
    if ((mask & 0x2000) && classification == 5) return 1;
    if ((mask & 0x4000) && classification == 6) return 1;
    if ((mask & 0x8000) && classification == 7) return 1;
    if ((mask & 0x10000) && classification == 8) return 1;
    return 0;
}
