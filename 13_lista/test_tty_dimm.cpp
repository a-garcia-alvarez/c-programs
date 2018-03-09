#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    struct winsize w;
     while(1) 
    {
    ioctl(0, TIOCGWINSZ, &w);
    printf("lines %d\n", w.ws_row);
    printf("columns %d\n", w.ws_col);
    usleep(1000000);
    }
    return 0;

}
