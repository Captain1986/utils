/*********************************************************
* 参考：https://blog.csdn.net/n5/article/details/70143942
* windows32/64平台_WIN32都会被定义，而_WIN64只在64位windows上定义，因此要先判断_WIN64
* 所有的apple系统都会定义 __APPLE__，包括MacOSX和iOS
* TARGET_IPHONE_SIMULATOR 是 TARGET_OS_IPHONE 的子集，
* TARGET_OS_IPHONE 是 TARGET_OS_MAC的子集。也就是说iOS模拟器上会同时定义这三个宏。因此判断的时候要先判断子集。
* 另外mac上可以用以下命令行获取GCC定义的预编译宏：
* gcc -arch i386 -dM -E - < /dev/null | sort  （i386可替换为arm64等）
*********************************************************/

#ifdef _WIN32
   //define something for Windows (32-bit and 64-bit, this part is common)
   #ifdef _WIN64
      //define something for Windows (64-bit only)
   #else
      //define something for Windows (32-bit only)
   #endif
#elif __APPLE__
   #include "TargetConditionals.h"
   #if TARGET_IPHONE_SIMULATOR
       // iOS Simulator
   #elif TARGET_OS_IPHONE
       // iOS device
   #elif TARGET_OS_MAC
       // Other kinds of Mac OS
   #else
       #   error "Unknown Apple platform"
   #endif
#elif __ANDROID__
   // android
#elif __linux__
   // linux
#elif __unix__ // all unices not caught above
   // Unix
#elif defined(_POSIX_VERSION)
   // POSIX
#else
   #   error "Unknown compiler"
#endif

