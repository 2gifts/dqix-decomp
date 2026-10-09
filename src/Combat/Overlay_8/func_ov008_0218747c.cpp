#include <globaldefs.h>
#include <GameState/GameState.h>

struct PlayClock020ac644 { unsigned short hours; unsigned char minutes; unsigned char seconds; };
struct ClockTotals { char pad[0x3c]; PlayClock020ac644 clocks[2]; };
struct GameClockTotals { char pad[0x7504]; ClockTotals totals; };
struct PlayTimeDisplay {
    char pad0[0xb10];
    signed char state;
    unsigned char phase;
    char pad1[6];
    unsigned int dirtyFlags;
    char pad2[0x18];
    int disabled;
    char pad3[8];
    PlayClock020ac644 clocks[2];
};
struct SearchClock { char pad[0x100d]; unsigned char count; };
struct TimeStamp020103f0;
struct TimeStamp020104cc;
struct _Z27ClearShortByteByte_02184598P27ClearShortByteByte_02184598;
struct PlayClock020ac614;
extern "C" void _Z33ComputeElapsedPlayTimeHMS020103f0P17TimeStamp020103f0PtPhS2_(TimeStamp020103f0*, unsigned short*, unsigned char*, unsigned char*);
extern "C" SearchClock* func_0202ae18();
int GetFieldAt0x0(int*);
extern "C" void _Z33ComputeElapsedPlayTimeHMS020104ccP17TimeStamp020104ccPtPhS2_(TimeStamp020104cc*, unsigned short*, unsigned char*, unsigned char*);
extern "C" void _Z27ClearShortByteByte_02184598P27ClearShortByteByte_02184598(struct _Z27ClearShortByteByte_02184598P27ClearShortByteByte_02184598*);
extern "C" void _Z25AddPlayClockHours020ac614P17PlayClock020ac614i(PlayClock020ac614*, int);
extern "C" void _Z27AddPlayClockMinutes020ac644P17PlayClock020ac644i(PlayClock020ac644*, int);
static inline ClockTotals* GetTotals(GameState* game) { ClockTotals* value = &((GameClockTotals*)game)->totals; return value; }

// USA: func_ov008_0218747c
extern "C" ARM void func_ov008_0218747c(PlayTimeDisplay* display, int mode) {
    if (display->disabled) return;
    if (display->state == 12 && display->phase < 6) return;
    GameState* game = GameState::GetInstance();
    PlayClock020ac644* output = 0;
    ClockTotals* totals = GetTotals(game);
    PlayClock020ac644* saved = 0;
    unsigned short hours = 0;
    unsigned char minutes = 0;
    unsigned char seconds = 0;
    PlayClock020ac644* singlePlayerSaved = &totals->clocks[0];
    PlayClock020ac644* multiplayerSaved = singlePlayerSaved + 1;
    if (mode == 0) {
        output = &display->clocks[0];
        saved = singlePlayerSaved;
        _Z33ComputeElapsedPlayTimeHMS020103f0P17TimeStamp020103f0PtPhS2_((TimeStamp020103f0*)game, &hours, &minutes, &seconds);
    } else if (mode == 1) {
        output = &display->clocks[1];
        saved = multiplayerSaved;
        SearchClock* search = func_0202ae18();
        int state = GetFieldAt0x0((int*)search);
        int count = search->count;
        if ((state == 5 && count > 1) || state == 6) {
            _Z33ComputeElapsedPlayTimeHMS020104ccP17TimeStamp020104ccPtPhS2_((TimeStamp020104cc*)game, &hours, &minutes, &seconds);
        } else {
            hours = 0;
            minutes = 0;
            seconds = 0;
        }
    }
    if (!output || !saved) return;
    unsigned char previousMinutes = output->minutes;
    _Z27ClearShortByteByte_02184598P27ClearShortByteByte_02184598((struct _Z27ClearShortByteByte_02184598P27ClearShortByteByte_02184598*)output);
    _Z25AddPlayClockHours020ac614P17PlayClock020ac614i((PlayClock020ac614*)output, (unsigned short)(saved->hours + hours));
    _Z27AddPlayClockMinutes020ac644P17PlayClock020ac644i(output, (unsigned char)(saved->minutes + minutes));
    output->seconds += (unsigned char)(saved->seconds + seconds);
    unsigned char total = output->seconds;
    if (total > 59) {
        unsigned char carryMinutes = total / 60;
        if (output->hours == 9999 && output->minutes + carryMinutes > 59) {
            output->hours = 9999;
            output->minutes = 59;
            output->seconds = 59;
        } else {
            _Z27AddPlayClockMinutes020ac644P17PlayClock020ac644i(output, carryMinutes);
            output->seconds %= 60;
        }
    }
    if (output->minutes != previousMinutes) {
        if (mode == 0) display->dirtyFlags |= 0x800;
        else if (mode == 1) display->dirtyFlags |= 0x1000;
    }
}
