#include <stdio.h>
#include <string.h>
#include "ke_cryptoki.h"

// Uncomment this to implement all the other functions - this function 
// list is returned by C_GetFunctionList (See below)
// static CK_FUNCTION_LIST ke_pkcs11FunctionList = {
//     { CRYPTOKI_VERSION_MAJOR, CRYPTOKI_VERSION_MINOR},
//     // Function Pointers - refer pkcs11.h for how to define each of these 
//     // Refer the PKCS#11 spec doc for the names of each of the functions 
//     C_Initialize,
//     C_Finalize,
//     C_GetInfo,
//     C_GetFunctionList,
//     C_GetSlotList,
//     C_GetSlotInfo,
//     C_GetTokenInfo,
//     C_GetMechanismList,
//     C_GetMechanismInfo,
//     C_InitToken,
//     C_InitPIN,
//     C_SetPIN,
//     C_OpenSession,
//     C_CloseSession,
//     C_CloseAllSessions,
//     C_GetSessionInfo,
//     C_GetOperationState,
//     C_SetOperationState,
//     C_Login,
//     C_Logout,
//     C_CreateObject,
//     C_CopyObject,
//     C_DestroyObject,
//     C_GetObjectSize,
//     C_GetAttributeValue,
//     C_SetAttributeValue,
//     C_FindObjectsInit,
//     C_FindObjects,
//     C_FindObjectsFinal,
//     C_EncryptInit,
//     C_Encrypt,
//     C_EncryptUpdate,
//     C_EncryptFinal,
//     C_DecryptInit,
//     C_Decrypt,
//     C_DecryptUpdate,
//     C_DecryptFinal,
//     C_DigestInit,
//     C_Digest,
//     C_DigestUpdate,
//     C_DigestKey,
//     C_DigestFinal,
//     C_SignInit,
//     C_Sign,
//     C_SignUpdate,
//     C_SignFinal,
//     C_SignRecoverInit,
//     C_SignRecover,
//     C_VerifyInit,
//     C_Verify,
//     C_VerifyUpdate,
//     C_VerifyFinal,
//     C_VerifyRecoverInit,
//     C_VerifyRecover,
//     C_DigestEncryptUpdate,
//     C_DecryptDigestUpdate,
//     C_SignEncryptUpdate,
//     C_DecryptVerifyUpdate,
//     C_GenerateKey,
//     C_GenerateKeyPair,
//     C_WrapKey,
//     C_UnwrapKey,
//     C_DeriveKey,
//     C_SeedRandom,
//     C_GenerateRandom,
//     C_GetFunctionStatus,
//     C_CancelFunction,
//     C_WaitForSlotEvent
// };

CK_RV C_Initialize(CK_VOID_PTR pInitArgs) {
    KE_PKCS11_DEBUG_FUNC_PRINTF("C_Initialize:\r\n");

    /* Implementation should handle a non-NULL input as well - assumes NULL here */
    if(pInitArgs == NULL) {
        KE_PKCS11_DEBUG_FUNC_PRINTF("...BAD PARAM...\r\n");
    }

    return CKR_OK;
}

CK_RV C_Finalize(CK_VOID_PTR pReserved) {
    KE_PKCS11_DEBUG_FUNC_PRINTF("C_Finalize:\r\n");

    /* Implementation should handle a non-NULL input as well - assumes NULL here */
    if(pReserved == NULL) {
        KE_PKCS11_DEBUG_FUNC_PRINTF("...BAD PARAM...\r\n");
    }

    return CKR_OK;
}

CK_RV C_GetInfo(CK_INFO_PTR pInfo) {
    KE_PKCS11_DEBUG_FUNC_PRINTF("C_GetInfo:\r\n");

    CK_VERSION ck_version = {CRYPTOKI_VERSION_MAJOR,CRYPTOKI_VERSION_MINOR};
    CK_VERSION lib_version = {0,1};
    CK_CHAR *lib_desc =  "Kickstart Embedded PKCS#11 Lib";
    CK_CHAR *mfr_desc =  "Kickstart Embedded";
    CK_BYTE looper;

    for(looper=0; looper<strlen((char *)lib_desc); ++looper) {
        pInfo->libraryDescription[looper] = lib_desc[looper];
    }
    for(looper=strlen((char *)lib_desc); looper<31; ++looper) {
        pInfo->libraryDescription[looper] = lib_desc[looper];
    }
    pInfo->libraryDescription[31] = '\0';

    for(looper=0; looper<strlen((char *)mfr_desc); ++looper) {
        pInfo->manufacturerID[looper] = mfr_desc[looper];
    }
    for(looper=strlen((char *)mfr_desc); looper<31; ++looper) {
        pInfo->manufacturerID[looper] = ' ';
    }
    pInfo->manufacturerID[31] = '\0';

    pInfo->cryptokiVersion = ck_version;
    pInfo->flags = 0;  
    pInfo->libraryVersion = lib_version;

    return CKR_OK;
}

// Uncomment this to make C_GetFunctionList available to the caller
// CK_RV C_GetFunctionList(CK_FUNCTION_LIST_PTR_PTR ppFunctionList) {
//     if(ppFunctionList == NULL) {
//         return CKR_ARGUMENTS_BAD;
//     }

//     *ppFunctionList = &ke_pkcs11FunctionList;
    
//     return CKR_OK;
// }
