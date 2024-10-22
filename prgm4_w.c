#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>  // For strlen

int main()
{
    int fd;
    char buf[1024] = "Hello BIT";  // Data to be written

    char *myfifo = "/Users/siddharthareddy/temp/test";  // Correct absolute path
    mkfifo(myfifo, 0666);  // Create FIFO with appropriate permissions

    printf("Run Reader process to read the FIFO File\n");
    
    fd = open(myfifo, O_WRONLY);  // Open FIFO for writing
    write(fd, buf, strlen(buf) + 1);  // Write only the actual length of the string
    close(fd);  // Close the FIFO file descriptor

    return 0;
}

//WRITER