#ifndef _KE_CRYPTOKI_H
#define _KE_CRYPTOKI_H

#define PKCS11_API

// 1. CK_PTR: The indirection string for making a pointer to an
// object.

#define CK_PTR *

// 2. CK_DECLARE_FUNCTION(returnType, name): A macro which makes
// an importable Cryptoki library function declaration out of a
// return type and a function name.

#define CK_DECLARE_FUNCTION(returnType, name) returnType PKCS11_API name

// 3. CK_DECLARE_FUNCTION_POINTER(returnType, name): A macro
// which makes a Cryptoki API function pointer declaration or
// function pointer type declaration out of a return type and a
// function name.

#define CK_DECLARE_FUNCTION_POINTER(returnType, name) returnType PKCS11_API(*name)

// 4. CK_CALLBACK_FUNCTION(returnType, name): A macro which makes
// a function pointer type for an application callback out of
// a return type for the callback and a name for the callback.

#define CK_CALLBACK_FUNCTION(returnType, name) returnType(*name)

// 5. NULL_PTR: This macro is the value of a NULL pointer.

#ifndef NULL_PTR
#define NULL_PTR 0
#endif

#define KE_ENABLE_PKCS11_DEBUG_PRINTS           (0)

#if KE_ENABLE_PKCS11_DEBUG_PRINTS
#define KE_PKCS11_DEBUG_FUNC_PRINTF( x )        printf( x )
#define KE_PKCS11_DEBUG_RET_PRINTF( x )         printf( x )     
#else
#define KE_PKCS11_DEBUG_FUNC_PRINTF( x )
#define KE_PKCS11_DEBUG_RET_PRINTF( x )
#endif


#include "pkcs11.h"

#endif // _KE_CRYPTOKI_H 