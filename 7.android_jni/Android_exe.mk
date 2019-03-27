LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_ARM_MODE := arm

LOCAL_SRC_FILES:= \
        ../sample/main.cpp

LOCAL_C_INCLUDES += \
    $(LOCAL_PATH)/../3rdparty/opencv/include \
    $(LOCAL_PATH)/../include

LOCAL_LDLIBS           += -llog \
                          -lopencv_highgui -lopencv_video -lopencv_imgcodecs -lopencv_calib3d -lopencv_imgproc -lopencv_core \
                          -llibwebp -llibtiff -llibpng -lz -llibjpeg-turbo -llibjasper -lIlmImf \
                          -ltegra_hal -lcpufeatures -llibprotobuf -ltbb \
                          -lFoo

LOCAL_LDFLAGS          += \
                          -L$(LOCAL_PATH)/../3rdparty/opencv/armeabi-v7a \
                          -L$(LOCAL_PATH)/../3rdparty/opencv/3rdparty/libs/armeabi-v7a \
                          -L$(LOCAL_PATH)/..

LOCAL_CFLAGS := -Werror

#LOCAL_SHARED_LIBRARIES += libFoo

LOCAL_MODULE_TAGS := optional

LOCAL_MODULE:= EXENAME

include $(BUILD_EXECUTABLE)

