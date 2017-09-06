LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

# OpenCV Include
OPENCV_ROOT := $(LOCAL_PATH)/../../../OpenCV-android-sdk
OPENCV_CAMERA_MODULES := on
OPENCV_INSTALL_MODULES := on
OPENCV_LIB_TYPE := STATIC
include ${OPENCV_ROOT}/sdk/native/jni/OpenCV.mk

# always force this build to re-run its dependencies
FORCE_GYP := $(shell make -C ./../../	GypAndroid.mk)
include ./../../GypAndroid.mk
