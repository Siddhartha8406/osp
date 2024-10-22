#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define MAX_BUF 1024

int main()
{
    int fd;
    char *myfifo = "/Users/siddharthareddy/temp/test";  // Correct absolute path
    char buf[MAX_BUF];

    fd = open(myfifo, O_RDONLY);  // Open FIFO for reading
    read(fd, buf, MAX_BUF);  // Read data from FIFO
    printf("Reader process has read: %s\n", buf);
    close(fd);  // Close the FIFO file descriptor

    // Optionally, delete the FIFO if you don't need it anymore
    unlink(myfifo);

    return 0;
}


//READER