#if defined(jpn)
#define R(j,u) (j)
#define data_ov006_0215fffe data_ov006_02161350
#define func_ov006_0215f3d8 func_ov006_021607f8
#define func_ov006_0215f4dc func_ov006_021608fc
#define func_ov006_0215f740 func_ov006_02160b08
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Node02158cfc { char pad[0x1c]; Node02158cfc *next; };
struct Cont02158cfc { char pad[R(0x24, 0x2c)]; Node02158cfc *head; Node02158cfc *checkpointOut; };

// USA: func_ov006_02158cfc
ARM void Checkpoint02158cfc(Cont02158cfc *obj, Node02158cfc *target) {
	Node02158cfc *node = obj->head;
	Node02158cfc *checkpoint = node;
	signed char idx = 0;
	while (node) {
		if (idx % 16 == 0) { checkpoint = node; idx = 0; }
		if (node == target) break;
		idx++;
		node = node->next;
	}
	obj->checkpointOut = checkpoint;
}
