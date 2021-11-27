#include <stdio.h>

int main(void)
{
    char buf[1000] = {0};
    int x/*aaa*/,y;
    x = 100;
    scanf(" %[^\n]", buf);
    printf("%s\n", buf);
    return 0;
}