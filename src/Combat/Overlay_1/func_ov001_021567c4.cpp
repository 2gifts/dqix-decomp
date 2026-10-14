#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Resource/Brightness.h"

char* GetFieldIfFlag4_020100f8(char* gameState);
void SetField0x238True_020a2794(void* obj);
void ApplyVecFromField0x246_020a2718(char* actor);
extern "C" void func_0209c2e0(void* obj, int a, int b);
extern "C" void func_ov001_02154da0(void);
void ClearMultipleFieldBits_02156b20(void* obj);
extern "C" void func_ov017_021bb27c(void* obj);

extern char data_02109bf4;

struct State_021567c4 {
	unsigned char field_0x0;
	unsigned char done;
	char pad2[8];
	unsigned short nextState;
	#if defined(jpn)
 char padC[0x90 - 0xc];
#else
 char padC[0x94 - 0xc];
#endif
	int field_0x94;
};

static inline unsigned char* GetPtr3718(GameResources* resources) { SDK_NULL_ASSERT(resources); return (unsigned char*)resources->unknown_ptr_3718; }

// USA: func_ov001_021567c4
extern "C" ARM unsigned short func_ov001_021567c4(State_021567c4* self) {
	GameState* gameState = GameState::GetInstance();
	GameResources* resources = func_ov017_0218b5b0();
	gameState->GetUnknownGameObject();
	char* camera = GetFieldIfFlag4_020100f8((char*)gameState);
	GetPtr3718(resources)[1] = 1;
	func_ov001_02154da0();
	SetBrightness(resources, 0, 0x1e);
	SetField0x238True_020a2794(camera);
	ApplyVecFromField0x246_020a2718(camera);
	func_0209c2e0(&data_02109bf4, self->field_0x94, 0);
	ClearMultipleFieldBits_02156b20(self);
	func_ov017_021bb27c(self);
	self->done = 1;
	return self->nextState;
}
