LOCAL_PATH := $(call my-dir)
 
include $(CLEAR_VARS)
 
LOCAL_MODULE := freg.default
LOCAL_MODULE_RELATIVE_PATH := hw
LOCAL_SRC_FILES := freg.cpp
LOCAL_SHARED_LIBRARIES := liblog libcutils
LOCAL_MODULE_TAGS := optional
#LOCAL_CFLAGS := -Wno-unused-parameter
 
 
include $(BUILD_SHARED_LIBRARY)
