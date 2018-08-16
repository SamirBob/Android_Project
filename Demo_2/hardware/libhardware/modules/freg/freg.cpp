/*************************************************************************
* 文件: freg.cpp
* 作者: SamirBob
* 邮箱: SamirBob@gmail.com 
* 创建时间: 2018年08月16日 星期四 14时05分31秒
*************************************************************************/
 
#define LOG_TAG "freg_hw"
 
#include <hardware/hardware.h>
#include <hardware/freg.h>
 
#include <fcntl.h>
#include <errno.h>
#include <malloc.h>
 
#include <cutils/log.h>
#include <cutils/atomic.h>
 
#define DEVICE_NAME "/dev/freg"
#define MODULE_NAME "Freg"
#define MODULE_AUTHOR "SamirBob@gmail.com"
 
/**
 * 设备打开和关闭接口
 */
 
static int freg_device_open(const struct hw_module_t *module, const char *id, struct hw_device_t **device);
static int freg_device_close(struct hw_device_t *device);
 
/**
 * 设备寄存器读写接口
 */
static int freg_get_val(struct freg_device_t *dev, int *val);
static int freg_set_val(struct freg_device_t *dev, int val);
 
/**
 * 定义模块操作方法结构体变量
 */
static struct hw_module_methods_t freg_module_methods = {
    .open = freg_device_open,
};
 
/**
 * 定义模块结构体变量
 */
struct freg_module_t HAL_MODULE_INFO_SYM = {
    .common = {
        .tag = HARDWARE_MODULE_TAG,
        .version_major = 1,
        .version_minor = 0,
        .id = FREG_HARDWARE_MODULE_ID,
        .name = MODULE_NAME,
        .author = MODULE_AUTHOR,
        .methods = &freg_module_methods,
    }
};
 
static int freg_device_open(const struct hw_module_t *module, const char *id, struct hw_device_t **device)
{
    if (!strcmp(id, FREG_HARDWARE_DEVICE_ID))
    {
        struct freg_device_t *dev;
 
        dev = (struct freg_device_t*)malloc(sizeof(struct freg_device_t));
        if (!dev)
        {
            ALOGE("Failed to alloc space for freg_device_t.");
            return -ENOMEM;
        }
 
        memset(dev, 0, sizeof(struct freg_device_t));
 
        dev->common.tag = HARDWARE_DEVICE_TAG;
        dev->common.version = HARDWARE_DEVICE_API_VERSION(1, 0);
        dev->common.module = (hw_module_t*)module;
        dev->common.close = freg_device_close;
        dev->set_val = freg_set_val;
        dev->get_val = freg_get_val;
 
        if ((dev->fd = open(DEVICE_NAME, O_RDWR)) == -1)
        {
            ALOGE("Failed to open device file /dev/freg -- %s.", strerror(errno));
            free(dev);
            return -EFAULT;
        }else
        {
            ALOGE("Open device file /dev/freg successfully.");
        }
 
       // *device = &(dev->common);
        *device = (hw_device_t*)dev;
 
        return 0;
    }
 
    return -EFAULT;
}
 
static int freg_device_close(struct hw_device_t *device)
{
    struct freg_device_t *freg_device = (struct freg_device_t*)device;
    if (freg_device)
    {
        close(freg_device->fd);
        free(freg_device);
    }
 
    return 0;
}
 
static int freg_get_val(struct freg_device_t *dev, int *val)
{
    if (!dev)
    {
        ALOGE("Null dev pointer");
        return -EFAULT;
    }
 
    if (!val)
    {
        ALOGE("Null val pointer");
        return -EFAULT;
    }
 
    read(dev->fd, val, sizeof(*val));
 
    ALOGI("Get value %d from device file /dev/freg.", *val);
 
    return 0;
}
 
static int freg_set_val(struct freg_device_t *dev, int val)
{
    if (!dev)
    {
        ALOGE("Null dev pointer");
        return -EFAULT;
    }
 
    ALOGI("Set value %d to device file /dev/freg.", val);
    write(dev->fd, &val, sizeof(val));
 
    return 0;
}
