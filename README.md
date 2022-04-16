# ke-pkcs11-cryptoki
This repo contains a bare-minimum PKCS#11 Cryptoki implementation that can be used by anyone for their own systems.
This does not implement all functions that the PKCS#11 spec enlists - but do open an issue if you want to see a feature implemented.

[This](https://docs.oasis-open.org/pkcs11/pkcs11-base/v3.0/os/pkcs11-base-v3.0-os.html) is the link to PKCS#11 specification.

## How to Build

```
$ mkdir build
$ cd build
$ cmake ..
```

## How to Test
Once you have built the library and the test app, run the test application from build/ directory as below.
```
$ ./testapp
```
### Expected Output
If everything goes well, you should see the console output as below from the test application.
```
$ ./testapp
-------------------------------------------------------------------
Cryptoki Version: 		        3.0
Library Version: 		        0.1
PKCS#11 Library Manufacturer: 	Kickstart Embedded             
PKCS#11 Library Description: 	Kickstart Embedded PKCS#11 Lib
-------------------------------------------------------------------
```
