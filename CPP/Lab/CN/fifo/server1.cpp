#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{

    char fname[100], buffer[1025];

    int req, res, file, n;

    mkfifo("req.fifo", 0777);
    mkfifo("res.fifo", 0777);

    printf("Waiting for request\n");

    req = open("req.fofo", O_RDONLY);
    res = open("res.fifo", O_WRONLY);

    read(req, fname, sizeof(fname));

    file = open(fname, O_RDONLY);

    if (file < 0)
    {
        write(res, "File not found", 57);
    }
    else
    {
        while ((n = read(file, buffer, sizeof(buffer))) > 0)
        {
            write(res, buffer, n);
        }
    }

    return 0;
}