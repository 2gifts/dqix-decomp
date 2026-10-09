#include <globaldefs.h>

struct PatternList_0200e984 { int count, field4, field8; unsigned char* entries; };
struct MatchState_0200e984;
struct ScanTail { int fields_[21]; };
struct ScanOwner {
    void* text_; int fields_[6]; ScanTail tail_;
};
struct ScanCursor {
    int field0_, field4_; unsigned char* instruction_;
    int fieldC_, field10_, field14_;
};
struct ScanContext { ScanCursor cursor_; ScanOwner owner_; };
struct PatternRecord { unsigned char* pattern_; int first_, second_; };
extern "C" int func_0200dbdc(ScanContext*);
extern "C" int func_0200dbf8(ScanContext*);
extern "C" unsigned char* func_0200d9e4(unsigned char*, int*);
extern "C" unsigned char* func_0200d958(unsigned char*, int*);
extern "C" int func_0200eff0(void*, unsigned char*, MatchState_0200e984*);
extern "C" int func_0200e984(void*, PatternList_0200e984*);
extern "C" void func_0200ea08(ScanOwner*, ScanCursor*, PatternList_0200e984*, unsigned char*);
extern "C" void func_0200efb8();

// USA: func_0200ea68
extern "C" ARM unsigned char* func_0200ea68(ScanOwner* owner, ScanCursor* cursor, MatchState_0200e984* state) {
    ScanContext context;
    PatternRecord patternRecord;
    PatternList_0200e984 list;
    context.cursor_.field0_ = cursor->field0_;
    context.cursor_.field4_ = cursor->field4_;
    context.cursor_.instruction_ = cursor->instruction_;
    context.cursor_.fieldC_ = cursor->fieldC_;
    context.cursor_.field10_ = cursor->field10_;
    context.cursor_.field14_ = cursor->field14_;
    context.owner_.text_ = owner->text_;
    context.owner_.fields_[0] = owner->fields_[0];
    context.owner_.fields_[1] = owner->fields_[1];
    context.owner_.fields_[2] = owner->fields_[2];
    context.owner_.fields_[3] = owner->fields_[3];
    context.owner_.fields_[4] = owner->fields_[4];
    context.owner_.fields_[5] = owner->fields_[5];
    context.owner_.tail_ = owner->tail_;
    int opcode = func_0200dbdc(&context);
    for (;;) {
        switch (opcode) {
        case 12: {
            unsigned char* data = context.cursor_.instruction_;
            patternRecord.pattern_ = (unsigned char*)(data[1] | (data[2] << 8) | (data[3] << 16) | (data[4] << 24));
            unsigned char* next = func_0200d9e4(data + 5, &patternRecord.first_);
            func_0200d958(next, &patternRecord.second_);
            if (!func_0200eff0(owner->text_, patternRecord.pattern_, state)) break;
            goto done;
        }
        case 15: {
            unsigned char* next = func_0200d9e4(context.cursor_.instruction_ + 1, &list.count);
            next = func_0200d9e4(next, &list.field4);
            list.entries = func_0200d958(next, &list.field8);
            if (!func_0200e984(owner->text_, &list)) func_0200ea08(owner, cursor, &list, context.cursor_.instruction_);
            break;
        }
        case 0: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 13: case 16: case 17: case 18: case 19:
            break;
        default:
            func_0200efb8();
            goto done;
        }
        opcode = func_0200dbf8(&context);
    }
done:
    return context.cursor_.instruction_;
}
