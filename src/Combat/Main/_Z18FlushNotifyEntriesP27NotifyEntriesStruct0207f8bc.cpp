#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct BackgroundLoader;

extern "C" int func_0207f84c(void *self);

struct NotifyEntriesStruct0207f8bc {
	char pad[0x1c];
	int field_1c;
#if !defined(jpn)
	int field_20[3];
#endif
};

// KEEP-NAME
// USA: func_0207f8bc
ARM int FlushNotifyEntries(struct NotifyEntriesStruct0207f8bc *self) {
	if (self->field_1c >= 0) {
		BackgroundLoader *loader = BackgroundLoader::GetInstance();
		loader->RemoveTask(self->field_1c);
	}

#if !defined(jpn)
	for (int i = 0; i < 3; i++) {
		BackgroundLoader *loader = BackgroundLoader::GetInstance();
		int task = self->field_20[i];
		if (task >= 0) {
			loader->RemoveTask(task);
		}
	}
#endif

	return func_0207f84c(self);
}
