#include <globaldefs.h>
#include "World/Object3D.h"
#include "GameState/GameState.h"

struct SubBlock020398b4 {
    unsigned char a, b, c, reversed;
    unsigned short e;
    short heading, startHeading, endHeading;
    Vector3i start, end, v2, startCopy, endCopy;
    int field48, field4c;
    short field50;
    unsigned char field52, field53, field54;
    void* startNode;
    void* endNode;
    int field60;
};
struct Obj020399b0 {
    Object3D object;
    char padding[0xb2 - sizeof(Object3D)];
    short field_b2;
    char paddingb4[0x2c];
    unsigned char active : 1;
    unsigned char remaining : 7;
    char paddinge1[0xe8];
    signed char field_1c9;
    char field_1ca;
    signed char field_1cb;
    unsigned char field_1cc;
    char field_1cd;
    unsigned char flags_1ce;
    char padding1cf[0x9d];
    SubBlock020398b4 action;
};
struct Settings020399b0 {
    char padding[0x66];
    unsigned char enabled;
    char padding67[3];
    short ratio, nodeID;
};
struct Node_1e6d4 {
    int field0, kind;
    Vector3i position;
    char padding14[0xc];
    short heading;
    char padding22[0xc];
    unsigned short linkedID;
    unsigned char field30, flags;
};
struct NodeOwner_1e6d4;
struct Zone020399b0 { char padding[0x6c]; char nodes[1]; };
struct Obj02033874;
struct Bytes02033b88;
struct Obj020397cc;
struct Owner020398b4;
struct SubBlock02038508;
extern "C" void _Z24SetVecYFromValue02033874P11Obj02033874i(Obj02033874*, int);
void* GetField0x3f8Address(GameState*);
extern "C" Zone020399b0* func_02012fe4();
extern "C" void _Z30ClearBytesAndZeroBlock02039d24Ph(unsigned char*);
extern "C" void _Z17InitBlock02038508P16SubBlock02038508(SubBlock02038508*);
int SetByte0xbeShiftPrev(Bytes02033b88*, int);
extern "C" void func_ov017_021d3f00(SubBlock020398b4*, int, int);
extern "C" void _Z31EnqueueEventTag60Field_021d440ci(int);
Node_1e6d4* FindNodeKind9ById(NodeOwner_1e6d4*, int);
int fix32cos(int);
int fix32sin(int);
void CopyBlockTo0x26c(Owner020398b4*, SubBlock020398b4*);
extern "C" void _Z27CancelPendingAction020397ccP11Obj020397cci(Obj020397cc*, int);
extern const char data_020efb4e[];

#define SET_ACTION_POINTS(firstNode, secondNode, reverseValue) \
    block.endNode = secondNode; \
    block.startNode = firstNode; \
    block.start = firstNode->position; \
    block.end = secondNode->position; \
    block.startCopy = firstNode->position; \
    block.endCopy = secondNode->position; \
    block.startHeading = firstNode->heading; \
    block.endHeading = secondNode->heading; \
    block.startHeading -= 0x3243; \
    block.reversed = reverseValue; \
    block.endCopy.x = direction.x + block.endCopy.x; \
    block.endCopy.z += direction.z; \
    block.end.y -= 0x1000; \
    if (block.startHeading < 0) block.startHeading += 0x6487

// USA: func_020399b0
extern "C" ARM void func_020399b0(Obj020399b0* self, unsigned short field, const Vector3i* position, int heading) {
    self->object.SetField06(field);
    self->object.position_ = *position;
    _Z24SetVecYFromValue02033874P11Obj02033874i(reinterpret_cast<Obj02033874*>(self), heading);
    self->field_b2 = 0;
    if (self->field_1c9 > 0) self->flags_1ce |= 4;
    self->field_1cb = -1;
    self->field_1cc = 0;
    Settings020399b0* settings = static_cast<Settings020399b0*>(GetField0x3f8Address(GameState::GetInstance()));
    Zone020399b0* zone = func_02012fe4();
    _Z30ClearBytesAndZeroBlock02039d24Ph(reinterpret_cast<unsigned char*>(self));
    if (settings->enabled) {
        _Z17InitBlock02038508P16SubBlock02038508(reinterpret_cast<SubBlock02038508*>(&self->action));
        self->active = 0;
        self->object.DisableFlag(0x1180);
        SetByte0xbeShiftPrev(reinterpret_cast<Bytes02033b88*>(self), 0);
        func_ov017_021d3f00(&self->action, 0, 1);
    }
    if (settings->nodeID < 0) {
        SetByte0xbeShiftPrev(reinterpret_cast<Bytes02033b88*>(self), 0);
        return;
    }
    if (settings->nodeID == 9999) {
        self->object.DisableFlag(0x1000);
        _Z31EnqueueEventTag60Field_021d440ci(-1);
        func_ov017_021d3f00(&self->action, 0, 1);
        return;
    }
    SubBlock020398b4 block;
    _Z17InitBlock02038508P16SubBlock02038508(reinterpret_cast<SubBlock02038508*>(&block));
    Node_1e6d4* node = FindNodeKind9ById(reinterpret_cast<NodeOwner_1e6d4*>(zone->nodes), settings->nodeID);
    if (!node) return;
    int cosine = fix32cos(node->heading);
    Vector3i direction;
    direction.x = fix32sin(node->heading);
    direction.y = 0;
    direction.z = cosine;
    Vector3fix_Normalize(&direction, &direction);
    Node_1e6d4* linked = FindNodeKind9ById(reinterpret_cast<NodeOwner_1e6d4*>(zone->nodes), node->linkedID);
    if (!linked) return;
    if (node->flags & 1) {
        SET_ACTION_POINTS(linked, node, 1);
    } else {
        SET_ACTION_POINTS(node, linked, 0);
    }
    block.b = 2;
    block.a = 1;
    block.heading = node->heading;
    CopyBlockTo0x26c(reinterpret_cast<Owner020398b4*>(self), &block);
    int difference = block.end.y - block.start.y;
    int y = block.start.y + FIX32_MULTIPLY(difference, settings->ratio);
    Vector3i adjusted;
    adjusted = self->object.position_;
    adjusted.y = y;
    self->object.position_ = adjusted;
    _Z24SetVecYFromValue02033874P11Obj02033874i(reinterpret_cast<Obj02033874*>(self), node->heading);
    self->object.MaybeSetRegularAnimation(data_020efb4e, 0);
    self->object.EnableFlag(0x180);
    self->active = 1;
    _Z27CancelPendingAction020397ccP11Obj020397cci(reinterpret_cast<Obj020397cc*>(self), 1);
}
