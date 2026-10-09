#include <globaldefs.h>

struct AudioStream;
struct AudioStreamVtable {
    void (*field_00)(AudioStream*);
    void (*destroy)(AudioStream*);
    void (*field_08[4])(AudioStream*);
    void (*close)(AudioStream*);
};
struct AudioStream {
    AudioStreamVtable* vtable;
};
struct AudioResources {
    AudioStream* stream;
    unsigned char pad_04[0x30];
    void* decoder;
    unsigned char pad_38[0x20];
    void* buffer;
    void** firstBuffers;
    void** secondBuffers;
    void* parameters;
    void* firstScratch;
    void* secondScratch;
    void* workBuffers[2];
    unsigned char pad_78[0x1c];
    void* scratch;
    unsigned char pad_98[0x10];
    unsigned int capacity;
};
extern "C" void _Z26SafeAllocatorFree_0218bca8Pv(void*);

// USA: func_ov016_0218edac
extern "C" ARM void func_ov016_0218edac(AudioResources* resources) {
    if (resources->stream) {
        resources->stream->vtable->close(resources->stream);
        if (resources->stream) resources->stream->vtable->destroy(resources->stream);
    }
    _Z26SafeAllocatorFree_0218bca8Pv(resources->decoder);
    if (resources->firstBuffers) {
        unsigned int i = 0;
        if (i < resources->capacity) do {
            _Z26SafeAllocatorFree_0218bca8Pv(resources->firstBuffers[i]);
            i++;
        } while (i < resources->capacity);
        _Z26SafeAllocatorFree_0218bca8Pv(resources->firstBuffers);
    }
    if (resources->secondBuffers) {
        unsigned int i = 0;
        if (i < resources->capacity) do {
            _Z26SafeAllocatorFree_0218bca8Pv(resources->secondBuffers[i]);
            i++;
        } while (i < resources->capacity);
        _Z26SafeAllocatorFree_0218bca8Pv(resources->secondBuffers);
    }
    if (resources->parameters) _Z26SafeAllocatorFree_0218bca8Pv(resources->parameters);
    if (resources->firstScratch) _Z26SafeAllocatorFree_0218bca8Pv(resources->firstScratch);
    if (resources->secondScratch) _Z26SafeAllocatorFree_0218bca8Pv(resources->secondScratch);
    int i = 0;
    do {
        if (resources->workBuffers[i]) _Z26SafeAllocatorFree_0218bca8Pv(resources->workBuffers[i]);
        resources->workBuffers[i] = 0;
        i++;
    } while (i < 2);
    if (resources->scratch) _Z26SafeAllocatorFree_0218bca8Pv(resources->scratch);
    if (resources->buffer) _Z26SafeAllocatorFree_0218bca8Pv(resources->buffer);
    resources->stream = 0;
    resources->firstBuffers = 0;
    resources->secondBuffers = 0;
    resources->firstScratch = 0;
    resources->secondScratch = 0;
    resources->parameters = 0;
    resources->buffer = 0;
    resources->scratch = 0;
}
