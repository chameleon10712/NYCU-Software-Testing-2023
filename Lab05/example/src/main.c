#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void stackbufferoverflow(void)
{
    char buf[0x10];

    printf("Input (max: 0x10 chars) > ");
    fflush(stdout);

    // No bounds check!
    gets(buf);

    printf("Bye bye\n");
}

int main(int argc, char *argv[])
{
    stackbufferoverflow();

    printf("main end\n");
}