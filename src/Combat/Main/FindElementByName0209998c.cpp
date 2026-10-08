#include "Combat/Main/ElementLookup.h"
#include "std_library_functions.h"
#include <globaldefs.h>

// USA: func_0209998c
ARM struct Elem0209998c *FindElementByName0209998c(struct List0209998c *list, const char *name) {
    int i;
    for (i = 0; i < list->count; i++) {
        struct Elem0209998c *elem = &list->data[i];
        if (strcmp(elem->f5, name) == 0) return elem;
    }
    return NULL;
}
