LOCAL_PATH      := $(call my-dir)
TARGET_ARCH     := arm
TARGET_PLATFORM := android-21
include $(CLEAR_VARS)
 
LOCAL_CFLAGS += -D__linux__ -D__embedded__ -D__android__ -W -Wall
LOCAL_CFLAGS += -O3 -fomit-frame-pointer -fstrict-aliasing -ffunction-sections -fdata-sections -ffast-math

LOCAL_CPPFLAGS := -O2 -fvisibility-inlines-hidden -fomit-frame-pointer -fstrict-aliasing -ffunction-sections -fdata-sections -ffast-math

LOCAL_LDFLAGS += -Wl,--gc-sections

LOCAL_CFLAGS += -fopenmp
LOCAL_CPPFLAGS += -fopenmp
LOCAL_LDFLAGS += -fopenmp
 
LOCAL_SRC_FILES := ../src/foo.cpp \
                   ../src/bar.cpp

LOCAL_C_INCLUDES       := $(LOCAL_PATH)/../include \
                          $(LOCAL_PATH)/../3rdparty/opencv/include

LOCAL_LDLIBS           += -llog \
                          -lopencv_highgui -lopencv_video -lopencv_imgcodecs -lopencv_calib3d -lopencv_imgproc -lopencv_core \
                          -ltegra_hal -lcpufeatures -llibprotobuf -ltbb

LOCAL_LDFLAGS          += -L$(SYSROOT)/usr/lib \
                          -L$(LOCAL_PATH)/../3rdparty/opencv/armeabi-v7a \
                          -L$(LOCAL_PATH)/../3rdparty/opencv/3rdparty/libs/armeabi-v7a

LOCAL_LDFLAGS         += -ljnigraphics -lz

LOCAL_MODULE           := libFoo

include $(BUILD_SHARED_LIBRARY)

