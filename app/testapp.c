#include <stdio.h>
#include "ke_cryptoki.h"

CK_INFO info;
CK_RV retval;

int main(void) {

    retval = C_GetInfo(&info);

    if(retval == CKR_OK) {
        printf("-------------------------------------------------------------------\r\n");
        printf("Cryptoki Version: \t\t%d.%d\r\n",info.cryptokiVersion.major,info.cryptokiVersion.minor);
        printf("Library Version: \t\t%d.%d\r\n",info.libraryVersion.major,info.libraryVersion.minor);
        printf("PKCS#11 Library Manufacturer: \t%s\r\n",info.manufacturerID);
        printf("PKCS#11 Library Description: \t%s\r\n",info.libraryDescription);
        printf("-------------------------------------------------------------------\r\n");
        printf("\r\n");
    }
    else {
        printf("Get Info failed...exiting\r\n");
    }

    return 0;
}