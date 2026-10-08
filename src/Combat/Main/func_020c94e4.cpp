#include <globaldefs.h>

typedef void (*VCountAlarmHandler)(void* arg);

struct VCountAlarm
{
    VCountAlarmHandler handler;
    void* arg;
    unsigned long tag;
    unsigned long frame;
    short line;
    short delay;
    VCountAlarm* prev;
    VCountAlarm* next;
    int periodic;
    int finished;
    int canceled;
};

struct VAlarmData
{
    unsigned short isInitialized;
    long previousVCount;
    long frameCount;
    VCountAlarm* head;
    VCountAlarm* tail;
};

extern VAlarmData data_02111654;
extern "C" char data_027e0000[];

struct ClassifyPointRegionStruct;
struct VCountAlarmNode;
struct VCountAlarmNode020c92d0;

unsigned int DisableSpecificInterrupts(unsigned int flagMask);
unsigned int AcknowledgeSpecificInterrupts(unsigned int flagMask);
long StoreValueCountingDecreases(int line);
int ClassifyPointRegion(ClassifyPointRegionStruct* alarm, int currentFrame, int currentLine);
void UnlinkVCountAlarmNode(VCountAlarmNode* alarm);
void InsertVCountAlarmNode(VCountAlarmNode020c92d0* alarm);
extern "C" void func_020c945c(VCountAlarm* alarm);

#define DISPSTAT (*(volatile unsigned short*)0x04000004)
#define VCOUNT (*(volatile unsigned short*)0x04000006)

static inline long GetVCount()
{
    return VCOUNT;
}

// USA: func_020c94e4
extern "C" ARM void func_020c94e4()
{
    VCountAlarm* alarm;
    VCountAlarmHandler handler;
    long check;
    long currentLine;
    long currentFrame;

    DisableSpecificInterrupts(4);
    DISPSTAT &= ~0x20;
    *(unsigned int*)((unsigned int)data_027e0000 + 0x3ff8) |= 4;
    unsigned short status = DISPSTAT;
    currentLine = ((status >> 8) & 0xff) | ((status << 1) & 0x100);
    currentFrame = StoreValueCountingDecreases(currentLine - 1);

    if (NULL == (alarm = data_02111654.head))
    {
        return;
    }
    do
    {
        currentLine = GetVCount();
        currentFrame = StoreValueCountingDecreases(currentLine);
        check = ClassifyPointRegion((ClassifyPointRegionStruct*)alarm, currentFrame, currentLine);
        switch (check)
        {
        case 0:
            func_020c945c(alarm);
            if (alarm->line != GetVCount() || alarm->frame != currentFrame)
            {
                return;
            }
            DisableSpecificInterrupts(4);
            DISPSTAT &= ~0x20;
            AcknowledgeSpecificInterrupts(4);
        case 1:
            handler = alarm->handler;
            UnlinkVCountAlarmNode((VCountAlarmNode*)alarm);
            alarm->handler = NULL;
            if (handler)
            {
                handler(alarm->arg);
            }
            if (alarm->periodic && !alarm->canceled)
            {
                alarm->handler = handler;
                alarm->frame = data_02111654.frameCount + 1;
                InsertVCountAlarmNode((VCountAlarmNode020c92d0*)alarm);
            }
            break;
        case 2:
            UnlinkVCountAlarmNode((VCountAlarmNode*)alarm);
            alarm->frame = data_02111654.frameCount + 1;
            InsertVCountAlarmNode((VCountAlarmNode020c92d0*)alarm);
            break;
        }
    } while (NULL != (alarm = data_02111654.head));
}
