#include <globaldefs.h>
#include "World/Zone3D.h"
#include "Filesystem/FileIO.h"
#include "std_library_functions.h"

struct SBTXFile;

extern "C" void _Z25RestorePairTables0207df90Pc(char*);
extern "C" void _Z24BackupPairTables0207dfacPc(char*);

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_0201445c
extern "C" ARM bool _ZN6Zone3D16ProcessNSBTXFileEPKvjPKc(
    Zone3D* zone, SBTXFile* pFile, const void* pData, unsigned int pNameAddr, const char* pUnused)
{
    const char* pName = (const char*)pNameAddr;
    SafeAllocator* pAlloc = zone->pAllocator_68_;
    char* pGraph = (char*)zone->unknown_ptr_50_;
    unsigned int nSize;
    void* pRaw;
    Zone3D::Model3DListNode* pNode =
        (Zone3D::Model3DListNode*)pAlloc->Allocate(sizeof(Zone3D::Model3DListNode));
    Model3D* pModel;

    if (pNode) {
        pModel = &pNode->model_;
        pModel->Clear();
        pNode->filename_ = 0;
        pNode->pNext_ = 0;
        pNode->filename_ = (char*)pAlloc->Allocate(strlen(pName) + 1);
        if (pNode->filename_) {
            strcpy((char*)pNode->filename_, pName);
            pNode->pNext_ = zone->firstModel_418_;
            zone->firstModel_418_ = pNode;
            pRaw = DecompressLZ77FileIntoScratchSpace(*pAlloc, pFile, nSize);
            if (pRaw) {
                _Z25RestorePairTables0207df90Pc(pGraph);
                pModel->SetRawFile(pRaw, nSize);
                pModel->ClearRawFileCache();
                pModel->ProcessRawFile(Model3D::TextureStagingMode_Immediate);
                _Z24BackupPairTables0207dfacPc(pGraph);

                NSBXXTex* pTex = pModel->GetTEX0();
                if (pTex) {
                    zone->textureImageMemory_ += NSBXX_Tex_GetBlock1Length(pTex);
                    zone->texturePaletteMemory_ += NSBXX_Tex_GetBlock4Length(pTex);
                }
                bool bCopied = false;
                if (pTex) {
                    unsigned int nTexSize = pTex->block1Offset_;
                    void* pCopy = pAlloc->Allocate(nTexSize);
                    if (pCopy) {
                        memcpy(pCopy, pTex, nTexSize);
                        pModel->SetTEX0((NSBXXTex*)pCopy);
                        bCopied = true;
                    }
                }
                if (!bCopied) {
                    pModel->Clear();
                }
            }
        }
    }
    return true;
}
