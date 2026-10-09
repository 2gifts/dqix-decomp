#ifndef COMBAT_NODE_LOOKUP_H
#define COMBAT_NODE_LOOKUP_H

struct NodeDB20 {
    unsigned char id;
    char unk[0x67];
    NodeDB20 *next;
};

NodeDB20 *FindNodeByByteId(void *base, int key);
void UnlinkNodeByByteId0206dd68(void *base, int key);

#endif
