#include <globaldefs.h>

struct BackgroundLoader;

extern "C" BackgroundLoader *_ZN16BackgroundLoader11GetInstanceEv();
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(BackgroundLoader *self, int task);
extern "C" int func_0207f84c(void *self);

struct NotifyEntriesStruct0207f8bc {
	char pad[0x1c];
	int field_1c;
	int field_20[3];
};

// KEEP-NAME
// USA: func_0207f8bc
extern "C" ARM int _Z18FlushNotifyEntriesP27NotifyEntriesStruct0207f8bc(struct NotifyEntriesStruct0207f8bc *self) {
	if (self->field_1c >= 0) {
		BackgroundLoader *loader = _ZN16BackgroundLoader11GetInstanceEv();
		_ZN16BackgroundLoader10RemoveTaskEi(loader, self->field_1c);
	}

	for (int i = 0; i < 3; i++) {
		BackgroundLoader *loader = _ZN16BackgroundLoader11GetInstanceEv();
		int task = self->field_20[i];
		if (task >= 0) {
			_ZN16BackgroundLoader10RemoveTaskEi(loader, task);
		}
	}

	return func_0207f84c(self);
}