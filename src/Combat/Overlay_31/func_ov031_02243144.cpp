#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Script.h"

struct RecentPeer { unsigned char address[6]; unsigned char age; unsigned char pad7; };
struct PeerIdentity { int field0; unsigned char address[6]; };
#if defined(jpn)
struct PeerScriptState {
    unsigned char pad0; unsigned char received; unsigned char pad2; unsigned char changed;
    unsigned char pad4; unsigned char ignoreAge; unsigned char age; char pad7[9];
    void* active; char pad14[4]; PeerIdentity* identity;
};
#else
struct PeerScriptState {
    unsigned char pad0[3]; unsigned char changed; unsigned char age; unsigned char pad5;
    unsigned char received; unsigned char ignoreAge; char pad8[0x10]; PeerIdentity* identity;
    char pad1c[0x18]; void* active;
};
#endif
extern PeerScriptState data_ov031_02291e04;
extern "C" int func_02001aec(const void*,const void*,unsigned int);

// JPN: func_ov031_02243924
// USA: func_ov031_02243144
extern "C" ARM int func_ov031_02243144(Script::Parameter* parameters) {
    if(!data_ov031_02291e04.active) return 1;
    if(data_ov031_02291e04.changed) return 1;
    parameters++->ToInt();
    unsigned char address[6];
    for(int i=0;i<6;++i) address[i]=(parameters++)->ToInt();
    if(!func_02001aec(address,data_ov031_02291e04.identity->address,6)) {
        data_ov031_02291e04.received=1;
        int slot=-1;
        int oldest=-1;
#if defined(jpn)
        RecentPeer* peers=(RecentPeer*)((char*)GameState::GetInstance()+0x7cdc);
#else
        RecentPeer* peers=(RecentPeer*)&GameState::GetInstance()->unk_6fc0[0x7fb0-0x6fc0];
#endif
        RecentPeer* peer=peers;
        for(int i=0;i<8;++i,++peer) {
            if(!func_02001aec(peer,address,6)) {
                slot=i;
                if(peer->age!=255 && !data_ov031_02291e04.ignoreAge) {
                    data_ov031_02291e04.age=peer->age;
                    return 1;
                }
                break;
            }
            if(oldest>peer->age || oldest<0) { slot=i; oldest=peer->age; }
        }
        data_ov031_02291e04.changed=1;
        peer=peers;
        for(int i=0;i<8;++i,++peer) {
            if(peer->age) {
                if(peer->age==255) peer->age=0;
                else --peer->age;
                if(!peer->age) memset(peer,0,sizeof(*peer));
            }
        }
        peer=&peers[slot];
        memcpy(peer,address,6);
        peer->age=7;
    }
    return 1;
}
