#include <globaldefs.h>

#include "World/Zone3D.h"
#include "Filesystem/FileIO.h"
#include "std_library_functions.h"

void RestorePairTables0207df90(char*);
void BackupPairTables0207dfac(char*);

// USA: func_0201445c
ARM bool Zone3D::ProcessNSBTXFile_0201445c(const void* pFile, unsigned int fileSize, const char* pName)
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
                RestorePairTables0207df90(pGraph);
                pModel->SetRawFile(pRaw, nSize);
                pModel->ClearRawFileCache();
                pModel->ProcessRawFile(Model3D::TextureStagingMode_Immediate);
                BackupPairTables0207dfac(pGraph);

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
