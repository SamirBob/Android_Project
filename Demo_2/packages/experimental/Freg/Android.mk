LOCAL_PATH := $(call my-dir)
 
include $(CLEAR_VARS)
 
# Only compile source java files in this apk.
LOCAL_SRC_FILES := $(call all-java-files-under, src)
 
LOCAL_PACKAGE_NAME := Freg
 
#LOCAL_SDK_VERSION := current
 
LOCAL_MODULE_TAGS := optional
 
include $(BUILD_PACKAGE)
