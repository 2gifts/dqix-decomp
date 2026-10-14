#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

#if defined(jpn)
enum { kTextBufferOffset = 0x28, kMessageFlagOffset = 0x17e2, kStatusOffset = 0x868 };
#else
enum { kTextBufferOffset = 0x5c, kMessageFlagOffset = 0x19b2, kStatusOffset = 0x998 };
#endif

struct CombatantMessageController {
    char unknown0[0x10];
    void* substitutions;
    char unknown14[kTextBufferOffset - 0x14];
    char* textBuffer;
    char unknownAfterBuffer[kStatusOffset - kTextBufferOffset - sizeof(char*)];
    int status;
    char unknownAfterStatus[kMessageFlagOffset - kStatusOffset - sizeof(int)];
    unsigned char messageFlag;
};

CombatantMessageController* GetGlobalField0x1c020421a0(void);
extern "C" void func_020531f0(void* obj);
struct Obj020397cc;
void CancelPendingAction020397cc(struct Obj020397cc* obj, int arg1);
extern "C" void func_02046380(void* obj);
int CallFunc020e0434With02153694_020e51cc(int value);
extern "C" int sprintf(char* dst, const char* fmt, ...);
void InitObjFromCombatantId020e4bf4(void* obj, int combatantId);
#if !defined(jpn)
extern "C" void func_0204500c(void*, const char*, int, int);
#endif
#if defined(jpn)
extern "C" void func_0204500c(void*, const char*, int);
extern char data_ov017_021d882c[];
#endif
void SetByteField0x253_020397c0(void* obj);

struct CombatantMessageRequest {
    unsigned char unknown0;
    unsigned char done;
    unsigned char unknown2[6];
    unsigned char state;
    unsigned char partyMemberId;
};

// USA: func_ov017_021c3194  (semantic: ProcessCombatantMessageState_021c3194)
extern "C" ARM void func_ov017_021c3194(CombatantMessageRequest* request) {
    GameState* battleStruct = GameState::GetInstance();
    func_ov017_0218b5b0();
    GameObject* unknownActor = battleStruct->GetUnknownGameObject();
    GameObject* partyMember = battleStruct->GetPartyMemberByIndex(request->partyMemberId);
    CombatantMessageController* controller = GetGlobalField0x1c020421a0();

    if (partyMember == NULL) {
        request->state = 2;
    }

    unsigned char state = request->state;
    if (state == 0) {
        if (unknownActor != NULL) {
            func_020531f0(unknownActor);
            CancelPendingAction020397cc((struct Obj020397cc*)unknownActor, 1);
        }
        func_02046380(controller);
        char* buf = controller->textBuffer;
#if defined(jpn)
        sprintf(buf, data_ov017_021d882c, (char*)partyMember->baseStats_);
        func_0204500c(controller, buf, 0);

#else
        sprintf(buf, (const char*)CallFunc020e0434With02153694_020e51cc(0x25));
        char localBuf[0xc];
        InitObjFromCombatantId020e4bf4(localBuf, request->partyMemberId);
        controller->substitutions = localBuf;
        func_0204500c(controller, buf, 0, 0xe3);

#endif
        controller->messageFlag = 0;
        controller->status = 1;
        request->state = 1;
        return;
    }
    if (state == 1) {
        if (controller->status == 0) {
            request->state = 2;
        }
        return;
    }
    if (state == 2) {
        SetByteField0x253_020397c0(unknownActor);
        request->done = 1;
    }
}
