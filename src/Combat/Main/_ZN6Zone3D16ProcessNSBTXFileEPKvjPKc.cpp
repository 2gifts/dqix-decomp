#include <globaldefs.h>

#include "World/Zone3D.h"
#include "Filesystem/FileIO.h"
#include "std_library_functions.h"

extern "C" void _Z25RestorePairTables0207df90Pc(char*);
extern "C" void _Z24BackupPairTables0207dfacPc(char*);

// USA: func_0201445c
ARM bool Zone3D::ProcessNSBTXFile(const void* pFile, unsigned int fileSize, const char* pName)
{
    SafeAllocator* pAlloc = pAllocator_68_;
    char* pGraph = (char*)unknown_ptr_50_;
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
            pNode->pNext_ = firstModel_418_;
            firstModel_418_ = pNode;
            pRaw = DecompressLZ77FileIntoScratchSpace(*pAlloc, pFile, nSize);
            if (pRaw) {
                _Z25RestorePairTables0207df90Pc(pGraph);
                pModel->SetRawFile(pRaw, nSize);
                pModel->ClearRawFileCache();
                pModel->ProcessRawFile(Model3D::TextureStagingMode_Immediate);
                _Z24BackupPairTables0207dfacPc(pGraph);

                NSBXXTex* pTex = pModel->GetTEX0();
                if (pTex) {
                    textureImageMemory_ += NSBXX_Tex_GetBlock1Length(pTex);
                    texturePaletteMemory_ += NSBXX_Tex_GetBlock4Length(pTex);
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
