/*************************************************************************
* 文件: freg.h
* 作者: SamirBob
* 邮箱: SamirBob@gmail.com 
* 创建时间: 2018年08月16日 星期四 13时44分16秒
*************************************************************************/
 
#ifndef ANDROID_FREG_INTERFACE_H
#define ANDROID_FREG_INTERFACE_H
 
#include <hardware/hardware.h>
 
__BEGIN_DECLS
 
/**
 * 定义模块ID
 */
#define FREG_HARDWARE_MODULE_ID "freg"
 
/**
 * 定义设备ID
 */
#define FREG_HARDWARE_DEVICE_ID "freg"
 
#define FREG_MODULE_API_VERSION_1_0 HARDWARE_MODULE_API_VERSION(1, 0)
#define FREG_MODULE_API_VERSION_CURRENT FREG_MODULE_API_VERSION_1_0
 
 
#define FREG_DEVICE_API_VERSION_1_0 HARDWARE_DEVICE_API_VERSION(1, 0)
#define FREG_DEVICE_API_VERSION_CURRENT FREG_DEVICE_API_VERSION_1_0
 
/**
 * 自定义模块结构体
 */
struct freg_module_t{
    struct hw_module_t common;
};
 
 
/**
 * 自定义设备结构体
 */
struct freg_device_t{
    struct hw_device_t common;
    int fd;
    int (*set_val)(struct freg_device_t *dev, int val);
    int (*get_val)(struct freg_device_t *dev, int *val);
};
 
__END_DECLS
 
#endif
