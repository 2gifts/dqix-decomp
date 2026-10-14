#include <globaldefs.h>
struct Frame020aff0c {
    unsigned char* data;
    unsigned int field_0x4;
};
struct Track020aff0c {
    unsigned short count;
    unsigned short field_0x2;
    unsigned int field_0x4;
    unsigned int field_0x8;
    Frame020aff0c* frames;
};
struct ExtraTrack020aff0c {
    unsigned short count;
    unsigned short field_0x2;
    void* data;
    void** items;
};
struct Extra020aff0c {
    unsigned short count;
    unsigned short field_0x2;
    ExtraTrack020aff0c* tracks;
};
struct Extension020aff0c {
    unsigned int field_0x0;
    unsigned int field_0x4;
    Extra020aff0c extra;
};
struct Bank020aff0c {
    unsigned short count;
    unsigned short field_0x2;
    Track020aff0c* tracks;
    Frame020aff0c* frames;
    unsigned char* data;
    unsigned int field_0x10;
    Extension020aff0c* extension;
};
// USA: func_020aff0c
extern "C" ARM void func_020aff0c(Bank020aff0c* bank) {
    bank->tracks = (Track020aff0c*)((unsigned int)bank->tracks + (unsigned int)bank);
    bank->frames = (Frame020aff0c*)((unsigned int)bank->frames + (unsigned int)bank);
    bank->data = (unsigned char*)((unsigned int)bank->data + (unsigned int)bank);
    unsigned short i;
    unsigned short frameIndex;
    Track020aff0c* tracks;
    Frame020aff0c* frames;
    unsigned char* data;
    data = bank->data;
    i = 0;
    tracks = bank->tracks;
    frames = bank->frames;
    if ((unsigned int)bank->count > i) do {
        tracks[i].frames = (Frame020aff0c*)((unsigned int)tracks[i].frames + (unsigned int)frames);
        frameIndex = 0;
        if ((unsigned int)tracks[i].count > frameIndex) do {
            tracks[i].frames[frameIndex].data = (unsigned char*)((unsigned int)tracks[i].frames[frameIndex].data + (unsigned int)data);
            frameIndex++;
        } while (tracks[i].count > frameIndex);
        i++;
    } while (bank->count > i);
    if (!bank->extension) return;
    bank->extension = (Extension020aff0c*)((unsigned int)bank->extension + (unsigned int)bank);
    Extra020aff0c* extra = &bank->extension->extra;
    extra->tracks = (ExtraTrack020aff0c*)((unsigned int)extra->tracks + (unsigned int)extra);
    unsigned int index = 0;
    unsigned int itemIndex;
    ExtraTrack020aff0c* track;
    if (extra->count > index) {
        unsigned int trackOffset = 0;
        do {
            track = (ExtraTrack020aff0c*)((unsigned char*)extra->tracks + trackOffset);
            track->data = (void*)((unsigned int)track->data + (unsigned int)extra);
            track->items = (void**)((unsigned int)track->items + (unsigned int)extra);
            itemIndex = 0;
            if (track->count > itemIndex) {
                unsigned int itemOffset = 0;
                do {
                    itemIndex++;
                    *(unsigned int*)((unsigned char*)track->items + itemOffset) += (unsigned int)extra;
                    itemOffset += 4;
                } while (itemIndex < track->count);
            }
            index++;
            trackOffset += 12;
        } while (index < extra->count);
    }
}
