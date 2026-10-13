#include <globaldefs.h>

extern "C" void (* volatile data_ov031_02290fc8)(void*);

struct ListNode02240e1c {
	ListNode02240e1c* next;
};

// USA: func_ov031_02240e1c  (semantic: FreeCircularList02240e1c)
extern "C" ARM void func_ov031_02240e1c(ListNode02240e1c* head) {
	if (!head) return;
	do {
		ListNode02240e1c* next = head->next;
		if (head != next) {
			ListNode02240e1c* next2 = *(ListNode02240e1c* *)&next->next;
			data_ov031_02290fc8(next);
			head->next = next2;
		} else {
			data_ov031_02290fc8(head);
			head = NULL;
		}
	} while (head);
}
