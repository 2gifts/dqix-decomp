struct InsertNode0223fe20 {
    InsertNode0223fe20* previous;
    InsertNode0223fe20* next;
    void* key;
    const char* value;
    int field10;
    int field14;
};
typedef void* (*InsertAllocator0223fe20)(int, int);
extern InsertAllocator0223fe20 data_ov031_02290fc4;
extern int data_ov031_02290fc0;
extern "C" int func_ov031_02242e90(const char*, const char*);

// USA: func_ov031_0223fe20
extern "C" int func_ov031_0223fe20(void* destination, void* key, const char* value, int size) {
    InsertNode0223fe20** head = (InsertNode0223fe20**)destination;
    InsertNode0223fe20* first = *head;
    int found = 0;
    InsertNode0223fe20* node;
    if (first != 0) {
        node = first;
        if (func_ov031_02242e90((const char*)key, (const char*)first->key) != 0) {
            node = first->next;
            if (node != *head) do {
                if (func_ov031_02242e90((const char*)key, (const char*)node->key) == 0) {
                    found = 1;
                    break;
                }
                node = node->next;
            } while (node != *head);
        } else {
            found = 1;
        }
    }
    if (found) {
        node->value = value;
    } else {
        InsertNode0223fe20* created = (InsertNode0223fe20*)data_ov031_02290fc4(size, 4);
        switch ((unsigned int)created) {
        case 0:
            data_ov031_02290fc0 = 1;
            return 0;
        default:
            break;
        }
        created->key = key;
        created->value = value;
        created->field10 = 0;
        created->field14 = 0;
        if (*head == 0) {
            created->next = created;
            created->previous = created;
            *head = created;
        } else {
            created->previous = (*head)->previous;
            created->next = *head;
            (*head)->previous->next = created;
            (*head)->previous = created;
        }
    }
    return 1;
}
