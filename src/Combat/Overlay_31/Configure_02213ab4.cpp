struct Entry { unsigned char unused, id, level; unsigned char flags; };
extern "C" void func_020ca408(const void*, void*, unsigned);
// USA: func_ov031_02213ab4
void Configure_02213ab4(int index, void* record, int flags, unsigned char* state) {
 Entry* base=(Entry*)(state+0x444);
 Entry* e=base+index;
 int v=((unsigned short*)record)[1];
 unsigned char* dest=state+0x470+index*0xc0;
 unsigned int level;
 if(v&2) level=(unsigned char)(v>>2);
 else level=(unsigned char)((v>>2)+25);
 if((unsigned char)level>e->level) { e->level=level; e->flags=(e->flags & ~0x7f) | (flags & 0x7f); }
 func_020ca408(record,dest,0xc0);
}
