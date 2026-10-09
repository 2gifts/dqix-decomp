#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"
#include "Resource/Script.h"

extern signed char data_ov003_02180cd0;
extern const char data_ov003_02180bd8[];
extern Script::OpcodeLookupEntry data_ov003_02180bc8[];

struct Self0217be40 {
	char pad0[0x12d];
	signed char fileIndex;
	char pad12e[0x13c - 0x12e];
	int taskId;
	unsigned char mode;
	signed char step;
};

// USA: func_ov003_0217be40
extern "C" ARM void func_ov003_0217be40(struct Self0217be40* self) {
	BackgroundLoader* loader = BackgroundLoader::GetInstance();
	GameResources* res = func_ov017_0218b5b0();

	if (self->step == 0) {
		GameState::GetInstance();
		if (self->fileIndex >= 0) {
			data_ov003_02180cd0 = self->fileIndex;
			self->taskId = loader->QueueLoadFile(data_ov003_02180bd8, NULL);
			SetBrightness(res, -16, 10);
			self->step++;
		}
	} else if (self->step == 1) {
		if (loader->GetTaskStatus(self->taskId) != 0) {
			void* code;
			unsigned int length;
			Script script;
			if (loader->GetDetailedTaskStatus(self->taskId) != 2) {
				loader->RemoveTask(self->taskId);
				self->mode = 4;
				self->step = 0;
			}
			loader->GetLoadedFileByID(self->taskId, &code, &length);
			script.Initialize();
			script.SetOpcodeLookup(data_ov003_02180bc8);
			script.Load(code, length);
			script.Execute();
			self->mode = 1;
			self->step = 0;
		}
	}
}
