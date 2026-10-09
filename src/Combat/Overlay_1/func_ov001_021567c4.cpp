#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Resource/Brightness.h"

char* GetFieldIfFlag4(char* gameState);
void SetField0x238True(void* obj);
void ApplyVecFromField0x246(char* actor);
extern "C" void func_0209c2e0(void* obj, int a, int b);
extern "C" void func_ov001_02154da0(void);
extern "C" void _Z31ClearMultipleFieldBits_02156b20v(void* obj);
extern "C" void func_ov017_021bb27c(void* obj);

extern char data_02109bf4;

struct State_021567c4 {
	unsigned char field_0x0;
	unsigned char done;
	char pad2[8];
	unsigned short nextState;
	char padC[0x94 - 0xc];
	int field_0x94;
};

static inline unsigned char* GetPtr3718(GameResources* resources) {
	unsigned char* p = (unsigned char*)resources->unknown_ptr_3718;
	return p;
}

// USA: func_ov001_021567c4
extern "C" ARM unsigned short func_ov001_021567c4(State_021567c4* self) {
	GameState* gameState = GameState::GetInstance();
	GameResources* resources = func_ov017_0218b5b0();
	gameState->GetUnknownGameObject();
	char* camera = GetFieldIfFlag4((char*)gameState);
	GetPtr3718(resources)[1] = 1;
	func_ov001_02154da0();
	SetBrightness(resources, 0, 0x1e);
	SetField0x238True(camera);
	ApplyVecFromField0x246(camera);
	func_0209c2e0(&data_02109bf4, self->field_0x94, 0);
	_Z31ClearMultipleFieldBits_02156b20v(self);
	func_ov017_021bb27c(self);
	self->done = 1;
	return self->nextState;
}
