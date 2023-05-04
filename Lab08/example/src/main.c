#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUF_SIZE 0x20

int main()
{
    char account[BUF_SIZE] = { 0 };
    char passwrd[BUF_SIZE] = { 0 };

    printf("Account: ");
    fgets(account, BUF_SIZE, stdin);

    printf("Password: ");
    fgets(passwrd, BUF_SIZE, stdin);

    if (!strcmp(account, "SQLAB\n") && !strcmp(passwrd, "BALQS\n")) {
        printf("AC!\n");
        return 0;
    } else {
        printf("WA!\n");
        return 1;
    }
}