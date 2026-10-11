struct Entry { unsigned char unused, id, level; unsigned char flags; };
extern "C" void func_020ca408(const void*, void*, unsigned);
// USA: func_ov031_02213a68
void Configure_02213a68(int id, void* record, int flags, unsigned char* state) {
 Entry* e=(Entry*)(state+0x46c);
 e->id=id;
 int v=((unsigned short*)record)[1];
 unsigned char level=(v&2) ? (unsigned char)(v>>2) : (unsigned char)((v>>2)+25);
 e->level=level;
 e->flags=(e->flags & ~0x7f) | (flags & 0x7f);
 func_020ca408(record,state+0xbf0,0xc0);
}
