#pragma once

struct BufferedScriptResult {
    unsigned short key;
    unsigned short values[3];
    unsigned short attributes[3];
    unsigned short resultId;
    unsigned short unknown10;
    unsigned short unknown12;
};

int RunBufferedStream0207416c(BufferedScriptResult* result, int key, const void* bytecode, unsigned int length);
int TryDecodeGlobalBitstreamEntry_02074114(BufferedScriptResult* result, int key);

typedef char BufferedScriptResultSizeCheck[sizeof(BufferedScriptResult) == 20 ? 1 : -1];
