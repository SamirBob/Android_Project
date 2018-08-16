/*************************************************************************
* 文件: com_android_server_FregService.cpp
* 作者: SamirBob
* 邮箱: SamirBob@gmail.com 
* 创建时间: 2018年08月16日 星期四 15时40分51秒
*************************************************************************/
#define LOG_TAG "FregServiceJNI"
 
#include "jni.h"
#include "JNIHelp.h"
#include "android_runtime/AndroidRuntime.h"
 
#include <utils/misc.h>
 
#include <utils/Log.h>
#include <hardware/hardware.h>
#include <hardware/freg.h>
 
#include <stdio.h>
 
namespace android
{
    /**
     * 设置虚拟硬件设备freg的寄存器的值 
     */
    static void freg_setVal(JNIEnv *env, jobject clazz, jint ptr, jint value)
    {
        /**
         * 将参数ptr转换为freg_device_t的结构体变量 
         */
        freg_device_t *device = (freg_device_t*)ptr;
        if (!device)
        {
            ALOGE("Device freg is not open.");
            return;
        }
 
        int val = value;
        ALOGI("Set value %d to device freg.", val);
 
        device->set_val(device, val);
    }
 
    /**
     * 读取虚拟硬件设备freg的寄存器值
     */
    static jint freg_getVal(JNIEnv *env, jobject clazz, jint ptr)
    {
        /**
         * 将参数ptr转换为freg_device_t的结构体变量 
         */
        freg_device_t *device = (freg_device_t*)ptr;
        if (!device)
        {
            ALOGE("Device freg is not open.");
            return 0;
        }
 
        int val = 0;
        device->get_val(device, &val);
 
        ALOGI("Get value %d from device freg.", val);
 
        return val;
    }
 
    /**
     * 打开虚拟硬件设备freg
     */
    static inline int freg_device_open(const hw_module_t *module, struct freg_device_t **device)
    {
        return module->methods->open(module, FREG_HARDWARE_DEVICE_ID, (struct hw_device_t**)device);
    }
 
    /**
     * 初始化虚拟硬件设备freg
     */
    static jint freg_init(JNIEnv *env, jclass clazz)
    {
        hw_module_t *module;
        freg_device_t *device;
 
        ALOGI("Initializing HAL stub freg......");
 
        /**
         * 加载硬件抽象层模块freg
         */
        int err = hw_get_module(FREG_HARDWARE_MODULE_ID, (const struct hw_module_t**)&module);
        
        if (err)
        {
            ALOGE("Couldn't load %s module (%s)", FREG_HARDWARE_MODULE_ID, strerror(-err));
        } else {
            ALOGI("Device freg found.");
 
            /**
             *  打开虚拟硬件设备freg
             */
            if (freg_device_open(module, &device) == 0)
            {
                ALOGI("Device freg is open.");
 
                /**
                 * 将freg_device_t接口转换为整型值返回
                 */
                return (jint)device;
            }
 
            ALOGE("Failed to open device freg.");
            return 0;
        }
 
        ALOGE("Failed to get HAL stub freg.");
 
        return 0;
    }
    
    /**
     * Java本地接口方法表
     */
    static const JNINativeMethod method_table[] = {
        {"freg_init_native", "()I", (void*)freg_init},
        {"setVal_native", "(II)V", (void*)freg_setVal},
        {"getVal_native", "(I)I", (void*)freg_getVal},
    };
 
    /**
     * 注册Java本地接口方法
     */
    int register_android_server_FregService(JNIEnv *env)
    {
        return jniRegisterNativeMethods(env, "com/android/server/FregService", method_table, NELEM(method_table));
    }
}
