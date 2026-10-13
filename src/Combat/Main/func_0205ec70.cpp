#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct SimpleCommand {
    unsigned short type;
    short param;
    union {
        short h[4];
        unsigned char b[4];
        int i;
        char* str;
    } data;
    SimpleCommand* next;
};

struct CompoundCommand {
    unsigned short type;
    union {
        short h;
        unsigned char b;
    } param;
    union {
        int w[4];
        short h[8];
        unsigned char b[16];
    } data;
    CompoundCommand* next;
    int extra;
};

struct ParseState {
    int index;
    int value;
    int tag;
};

// USA: func_0205ec70  (semantic: ParseVariantList_0205ec70)
extern "C" ARM void func_0205ec70(SafeAllocator* allocator, int count, const Script::Parameter* params, SimpleCommand** simpleHead, CompoundCommand** compoundHead) {
    SimpleCommand* prevSimple = 0;
    CompoundCommand* prevCompound = 0;
    ParseState state;
    state.index = 0;

    while (state.index < count) {
        state.value = params->ToInt();
        params++;
        state.tag = state.value >> 16;

        if (state.tag < 100 || state.tag >= 500) {
            SimpleCommand* cmd = (SimpleCommand*)allocator->Allocate(sizeof(SimpleCommand));
            if (cmd == 0) return;
            if (*simpleHead == 0) *simpleHead = cmd;
            else prevSimple->next = cmd;

            switch (state.tag) {
            case 29: {
                cmd->type = state.tag;
                cmd->data.h[0] = state.value;
                cmd->data.h[1] = (params++)->ToInt();
                int deg = (params++)->ToInt();
                float rad = 3.14159274f * deg / 180.0f;
                if (rad > 3.14159274f * 2.0f) rad -= 3.14159274f * 2.0f;
                else if (rad < 0.0f) rad += 3.14159274f * 2.0f;
                cmd->param = (int)(4096.0f * rad);
                state.index += 2;
                break;
            }
            case 32:
            case 33: {
                int v = (params++)->ToInt();
                cmd->type = state.tag;
                cmd->data.b[0] = (unsigned int)v >> 24;
                cmd->data.b[1] = (unsigned int)v >> 16;
                cmd->data.b[2] = (unsigned int)v >> 8;
                cmd->data.b[3] = v;
                state.index += 1;
                break;
            }
            case 44: case 47: case 48: case 49: case 70: case 73: case 75: case 76: case 83: case 90: case 500:
                cmd->type = state.tag;
                cmd->param = state.value;
                cmd->data.h[0] = (params++)->ToInt();
                state.index += 1;
                break;
            case 85:
                cmd->type = state.tag;
                cmd->param = state.value;
                cmd->data.i = (params++)->ToInt();
                state.index += 1;
                break;
            case 46: {
                cmd->type = state.tag;
                cmd->param = state.value;
                int v = (params++)->ToInt();
                cmd->data.h[0] = v >> 16;
                cmd->data.h[1] = v;
                state.index += 1;
                break;
            }
            case 66: {
                cmd->type = state.tag;
                cmd->param = state.value;
                int v = (params++)->ToInt();
                cmd->data.h[0] = v >> 16;
                cmd->data.h[1] = v;
                state.index += 1;
                break;
            }
            case 50:
            case 82: {
                unsigned short type = state.tag;
                int q0 = (params++)->ToInt();
                int q1 = (params++)->ToInt();
                int q2 = (params++)->ToInt();
                int q3 = (params++)->ToInt();
                cmd->type = type;
                cmd->param = 1;
                cmd->data.h[0] = state.value;
                cmd->data.h[1] = q0 >> 16;
                cmd->data.h[2] = q0;
                cmd->data.h[3] = q1 >> 16;
                state.index += 4;
                SimpleCommand* second = (SimpleCommand*)allocator->Allocate(sizeof(SimpleCommand));
                second->type = type;
                second->param = 2;
                second->data.h[0] = q1;
                second->data.h[1] = q2 >> 16;
                second->data.h[2] = q2;
                second->data.h[3] = q3;
                cmd->next = second;
                cmd = second;
                break;
            }
            case 69:
                cmd->type = state.tag;
                cmd->param = state.value;
                cmd->data.str = (char*)allocator->Allocate(11);
                memcpy(cmd->data.str, (params++)->ToString(), 11);
                state.index += 1;
                break;
            case 52: case 55: case 62: case 63: {
                cmd->type = state.tag;
                cmd->param = state.value;
                int v = (params++)->ToInt();
                cmd->data.h[0] = v >> 16;
                cmd->data.h[1] = v;
                state.index += 1;
                break;
            }
            case 53: case 54: case 56: case 57: case 58: case 59: case 60: case 61: {
                cmd->type = state.tag;
                cmd->param = state.value;
                int v0 = (params++)->ToInt();
                cmd->data.h[0] = v0 >> 16;
                cmd->data.h[1] = v0;
                int v1 = (params++)->ToInt();
                cmd->data.h[2] = v1 >> 16;
                cmd->data.h[3] = v1;
                state.index += 2;
                break;
            }
            case 64:
            case 65: {
                cmd->type = state.tag;
                cmd->data.h[0] = state.value;
                int v0 = (params++)->ToInt();
                cmd->data.h[1] = v0 >> 16;
                cmd->data.h[2] = v0;
                int v1 = (params++)->ToInt();
                cmd->data.h[3] = v1 >> 16;
                state.index += 2;
                break;
            }
            case 74:
                cmd->type = state.tag;
                cmd->param = (params++)->ToInt();
                state.index += 1;
                break;
            case 78: {
                cmd->type = state.tag;
                cmd->param = state.value;
                int v0 = (params++)->ToInt();
                cmd->data.h[0] = v0 >> 16;
                cmd->data.h[1] = v0;
                int v1 = (params++)->ToInt();
                cmd->data.h[2] = v1;
                state.index += 2;
                break;
            }
            case 79:
                cmd->type = state.tag;
                cmd->data.b[0] = state.value;
                cmd->param = (params++)->ToInt();
                state.index += 1;
                break;
            case 91:
                cmd->type = state.tag;
                cmd->data.b[0] = state.value;
                cmd->param = (params++)->ToInt();
                state.index += 1;
                break;
            default:
                cmd->type = state.tag;
                cmd->param = state.value;
                break;
            }

            cmd->next = 0;
            prevSimple = cmd;
        } else {
            CompoundCommand* cmd = (CompoundCommand*)allocator->Allocate(sizeof(CompoundCommand));
            if (cmd == 0) return;
            if (*compoundHead == 0) *compoundHead = cmd;
            else prevCompound->next = cmd;

            switch (state.tag) {
            case 116: case 117: case 118: case 130: case 131: case 133: case 134: case 135: case 138:
            case 144: case 149: case 150: case 155: case 158: case 159: case 176: case 177: case 179:
            case 180: case 226: case 230: case 232:
                cmd->type = state.tag;
                cmd->param.h = state.value;
                cmd->data.h[0] = (params++)->ToInt() >> 16;
                state.index += 1;
                break;
            case 122: {
                cmd->type = state.tag;
                cmd->param.h = state.value;
                float x = (params++)->ToFloat();
                float y = (params++)->ToFloat();
                float z = (params++)->ToFloat();
                cmd->data.w[0] = (int)(x > 0 ? x * 4096.0f + 0.5f : x * 4096.0f - 0.5f);
                cmd->data.w[1] = (int)(y > 0 ? y * 4096.0f + 0.5f : y * 4096.0f - 0.5f);
                cmd->data.w[2] = (int)(z > 0 ? z * 4096.0f + 0.5f : z * 4096.0f - 0.5f);
                state.index += 3;
                break;
            }
            case 132: case 148: case 214:
                cmd->type = state.tag;
                cmd->param.h = state.value;
                cmd->data.h[0] = (params++)->ToInt();
                cmd->data.h[1] = (params++)->ToInt();
                cmd->data.h[2] = (params++)->ToInt();
                state.index += 3;
                break;
            case 123: {
                cmd->type = state.tag;
                cmd->param.h = state.value;
                float x = (params++)->ToFloat();
                cmd->data.h[0] = (short)(x > 0 ? (short)(x * 4096.0f + 0.5f) : (short)(x * 4096.0f - 0.5f));
                state.index += 1;
                break;
            }
            case 108: case 109: case 136: case 152: case 153: case 154: {
                cmd->type = state.tag;
                cmd->data.h[0] = state.value;
                cmd->data.h[1] = (params++)->ToInt();
                int deg = (params++)->ToInt();
                float rad = 3.14159274f * deg / 180.0f;
                if (rad > 3.14159274f * 2.0f) rad -= 3.14159274f * 2.0f;
                else if (rad < 0.0f) rad += 3.14159274f * 2.0f;
                cmd->param.h = (int)(4096.0f * rad);
                state.index += 2;
                break;
            }
            case 139:
            case 140:
                cmd->type = state.tag;
                cmd->data.w[0] = (params++)->ToInt();
                state.index += 1;
                break;
            case 143: {
                cmd->type = state.tag;
                int a0 = (int)((params++)->ToFloat() * 4096.0f);
                int a1 = (int)((params++)->ToFloat() * 4096.0f);
                int a2 = (int)((params++)->ToFloat() * 4096.0f);
                int a3 = (int)((params++)->ToFloat() * 4096.0f);
                int a4 = (int)((params++)->ToFloat() * 4096.0f);
                int a5 = (int)((params++)->ToFloat() * 4096.0f);
                int a6 = (params++)->ToInt();
                cmd->param.h = 1;
                cmd->data.w[0] = (unsigned short)state.value;
                cmd->data.w[1] = a0;
                cmd->data.w[2] = a1;
                cmd->data.w[3] = a2;
                CompoundCommand* second = (CompoundCommand*)allocator->Allocate(sizeof(CompoundCommand));
                second->type = cmd->type;
                second->param.h = 2;
                second->data.w[3] = a6;
                second->data.w[0] = a3;
                second->data.w[1] = a4;
                second->data.w[2] = a5;
                cmd->next = second;
                cmd->extra = 0;
                cmd = second;
                state.index += 7;
                break;
            }
            case 156:
            case 157: {
                cmd->type = state.tag;
                cmd->param.h = state.value;
                int v = (params++)->ToInt();
                cmd->data.h[0] = v >> 16;
                cmd->data.h[1] = v;
                state.index += 1;
                break;
            }
            case 167: case 168: case 169: case 171: case 172: case 174: case 196: case 200: case 201:
                cmd->type = state.tag;
                cmd->param.b = state.value;
                cmd->data.b[0] = (params++)->ToInt() >> 16;
                state.index += 1;
                break;
            case 178: {
                cmd->type = state.tag;
                cmd->param.b = state.value;
                int v0 = (params++)->ToInt();
                cmd->data.b[0] = v0 >> 16;
                cmd->data.b[1] = v0;
                cmd->data.h[1] = (params++)->ToInt();
                int v2 = (params++)->ToInt();
                cmd->data.b[4] = v2 >> 16;
                state.index += 3;
                break;
            }
            case 188: {
                cmd->type = state.tag;
                cmd->param.h = state.value;
                int v0 = (params++)->ToInt();
                cmd->data.h[0] = v0 >> 16;
                cmd->data.h[1] = v0;
                int v1 = (params++)->ToInt();
                cmd->data.h[2] = v1;
                state.index += 2;
                break;
            }
            case 189:
                cmd->type = state.tag;
                cmd->param.b = (unsigned short)state.value != 0;
                break;
            case 190: {
                cmd->type = state.tag;
                cmd->param.h = state.value;
                int v0 = (params++)->ToInt();
                cmd->data.h[0] = v0 >> 16;
                cmd->data.h[1] = v0;
                int v1 = (params++)->ToInt();
                cmd->data.h[2] = v1;
                state.index += 2;
                break;
            }
            case 195:
                cmd->type = state.tag;
                cmd->param.b = state.value;
                cmd->data.b[0] = (params++)->ToInt() >> 16;
                state.index += 1;
                break;
            case 207: {
                cmd->type = state.tag;
                cmd->param.h = state.value;
                int v0 = (params++)->ToInt();
                cmd->data.h[0] = v0 >> 16;
                cmd->data.h[1] = v0;
                int v1 = (params++)->ToInt();
                cmd->data.h[2] = v1 >> 16;
                cmd->data.h[3] = v1;
                state.index += 2;
                break;
            }
            case 213: {
                cmd->type = state.tag;
                cmd->data.h[0] = state.value;
                int v0 = (params++)->ToInt();
                cmd->data.h[1] = v0 >> 16;
                cmd->data.h[2] = v0;
                int v1 = (params++)->ToInt();
                cmd->data.h[3] = v1;
                state.index += 2;
                break;
            }
            case 215: {
                cmd->type = state.tag;
                cmd->param.h = state.value;
                int v0 = (params++)->ToInt();
                cmd->data.h[0] = v0 >> 16;
                cmd->data.h[1] = v0;
                int v1 = (params++)->ToInt();
                cmd->data.h[2] = v1 >> 16;
                cmd->data.h[3] = v1;
                state.index += 2;
                break;
            }
            case 220:
                cmd->type = state.tag;
                cmd->param.h = (state.value & 0xff00) >> 8;
                cmd->data.b[0] = state.value;
                break;
            default:
                cmd->type = state.tag;
                cmd->param.h = state.value;
                break;
            }

            cmd->next = 0;
            cmd->extra = 0;
            prevCompound = cmd;
        }

        state.index++;
    }
}
