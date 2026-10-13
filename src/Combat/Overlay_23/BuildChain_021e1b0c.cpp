#include <globaldefs.h>

struct SelectionChainEntry {
    SelectionChainEntry* next;
    unsigned char unknown4[6];
    unsigned short score;
    unsigned short unknownc;
    unsigned char selected : 1;
    unsigned char unknownFlag : 1;
    unsigned char category : 6;
    unsigned char attribute;
};

struct SelectionChain {
    SelectionChainEntry* first;
    SelectionChainEntry* entries;
    short count;
};

extern "C" SelectionChainEntry* func_ov023_021e1bac(SelectionChain* selection, int useFilters, int category, int attribute);

// USA: func_ov023_021e1b0c
ARM void BuildChain_021e1b0c(void* context, int useFilters, int category, int attribute) {
    SelectionChain* selection = (SelectionChain*)context;
	SelectionChainEntry* node = func_ov023_021e1bac(selection, useFilters, category, attribute);
	if (node == 0) return;
	selection->first = node;
	while (node != 0) {
		SelectionChainEntry* next = func_ov023_021e1bac(selection, useFilters, category, attribute);
		node->next = next;
		node = next;
	}
}
