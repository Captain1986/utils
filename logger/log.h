/**************************************************************
 * 一个轻量级log工具，打印log到控制台，可使用在Android, Linux上
 * 需要在Makefile中打开_DEBUG_宏
 * 默认打印在Linux中，如果是Android系统，请打开__ANDROID__宏
 * ************************************************************/

#ifndef __LOG_H__
#define __LOG_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _DEBUG_
#undef  LOG_TAG
#define LOG_TAG "Captain"
#ifdef __ANDROID__
//#include <utils/Log.h>
#include <android/log.h>
#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__);
#define LOGW(...)  __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__);
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__);
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__);
#else  /* !_ANDROID_ */
#include <stdio.h>
#define LOGI(...) \
     do { \
        printf("%s-%s(%d line) ", LOG_TAG, __FILE__, __LINE__); printf(__VA_ARGS__); printf("\n"); \
	 } while (0)

#define LOGW(...) \
     do { \
         printf("%s-%s(%d line) ", LOG_TAG, __FILE__, __LINE__); printf(__VA_ARGS__); printf("\n"); \
	 } while (0)

#define LOGE(...) \
     do { \
         printf("%s-%s(%d line) ", LOG_TAG, __FILE__, __LINE__); printf(__VA_ARGS__); printf("\n"); \
	 } while (0)

#define LOGD(...) \
     do { \
         printf("%s-%s(%d line) ", LOG_TAG, __FILE__, __LINE__); printf(__VA_ARGS__); printf("\n"); \
	 } while (0)
#endif /* !_ANDROID_ */
#else  /* !_DEBUG */
#define LOGI(...)
#define LOGW(...)
#define LOGE(...)
#define LOGD(...)
#endif

#ifdef __cplusplus
}
#endif

#endif /* __LOG_H__ */

/* EOF */

