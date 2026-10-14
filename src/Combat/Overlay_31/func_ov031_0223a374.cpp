#include <globaldefs.h>

struct PhaseState_0223a374 {
    int pad[0x10];
    int mode;
    int step;
};

typedef void (*ReportFn_0223a374)(int, const char*, ...);

struct PhaseContext_0223a374 {
    ReportFn_0223a374 Report;
    PhaseState_0223a374* state;
};

extern PhaseContext_0223a374 data_ov031_02290d18;
extern const char data_ov031_0224c4fc[];
extern const char data_ov031_0224c520[];

extern "C" void func_ov031_02239368(int);
extern "C" int func_ov031_02239a24();
extern "C" int func_ov031_02239a74();
int CheckFirstOrRunTen_0223a358();
int TryClearSubEffectAndSetField54_02239924();
int RegisterTagAndSetField54_02239954();

// USA: func_ov031_0223a374
extern "C" ARM void func_ov031_0223a374(void) {
    int phase = data_ov031_02290d18.state->mode;
    if (phase == 1) {
        ReportFn_0223a374 report = data_ov031_02290d18.Report;
        if (report != 0) {
            report(0x8000000, data_ov031_0224c4fc);
        }
        return;
    }
    {
        ReportFn_0223a374 reportBusy = data_ov031_02290d18.Report;
        if (reportBusy != 0) {
            reportBusy(0x8000000, data_ov031_0224c520, phase);
        }
    }

    int mode = data_ov031_02290d18.state->mode;
    if (mode != 6 && mode != 5 && mode != 4) {
        func_ov031_02239368(3);
        CheckFirstOrRunTen_0223a358();
        return;
    }
    func_ov031_02239368(3);
    switch (data_ov031_02290d18.state->step) {
    case 3:
        if (func_ov031_02239a24() == 0) {
            CheckFirstOrRunTen_0223a358();
        }
        break;
    case 1:
    case 5:
        if (func_ov031_02239a74() == 0) {
            CheckFirstOrRunTen_0223a358();
        }
        break;
    case 2:
        if (TryClearSubEffectAndSetField54_02239924() == 0) {
            CheckFirstOrRunTen_0223a358();
        }
        break;
    case 0:
    case 4:
        if (RegisterTagAndSetField54_02239954() == 0) {
            CheckFirstOrRunTen_0223a358();
        }
        break;
    }
}
