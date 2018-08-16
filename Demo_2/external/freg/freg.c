/*************************************************************************
* 文件: freg.c
* 作者: SamirBob
* 邮箱: SamirBob@gmail.com 
* 创建时间: 2016年07月20日 星期三 22时58分58秒
*************************************************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
 
#define FREG_DEVICE_NAME "/dev/freg"
 
int main(int argc, char **argv)
{
    int fd  = -1;
    int val = 0;
 
    fd = open(FREG_DEVICE_NAME, O_RDWR);
    if (-1 == fd)
    {
        printf("Failed to open device %s.\n", FREG_DEVICE_NAME);
        return -1;
    }
 
    printf("Read original val:\n");
    read(fd, &val, sizeof(val));
    printf("%d.\n\n", val);
 
    val = 5;
    printf("Write val %d to %s.\n\n", val, FREG_DEVICE_NAME);
    write(fd, &val, sizeof(val));
 
    printf("Read the val again:\n");
    read(fd, &val, sizeof(val));
    printf("%d.\n\n", val);
 
    close(fd);
 
    return 0;
}
