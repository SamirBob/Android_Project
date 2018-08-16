
/*************************************************************************
* 文件: freg.h
* 作者: SamirBob
* 邮箱: SamirBob@gmail.com 
* 创建时间: 2018年08月16日 星期四 10时59分26秒
*************************************************************************/
 
#ifndef _FAKE_REG_H_
#define _FAKE_REG_H_
 
#include <linux/cdev.h>
#include <linux/semaphore.h>
 
#define FREG_DEVICE_NODE_NAME "freg"
#define FREG_DEVICE_FILE_NAME "freg"
#define FREG_DEVICE_PROC_NAME "freg"
#define FREG_DEVICE_CLASS_NAME "freg"
 
struct fake_reg_dev{
    int val;
    struct semaphore sem;
    struct cdev dev;
};
 
#endif