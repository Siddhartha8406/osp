#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    int fd;
    char buf[1024] = "Hello BIT";

    char *myfifo = "/ise/Desktop/tmp";
    mkfifo(myfifo, 0666);

    printf("Run Reader process to read the FIFO File\n");
    
    fd = open(myfifo, O_WRONLY);
    write(fd, buf, sizeof(buf));
    close(fd);
    unlink(myfifo);
    return 0;
}