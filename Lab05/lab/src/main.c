#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// 1 --- 2 --- 3
//    |     |
//    |     -- 4 --- 5
//    |
//    -- 4 --- 5

void func1(void);
void func2(void);
void func3(void);
void func4(void);
void func5(void);

void func1(void)
{
    func2();
    func4();
}

void func2(void)
{
    func3();
    func4();
}

void func3(void)
{
}

void func4(void)
{
    func5();
}

void func5(void)
{
}

int main(int argc, char *argv[])
{
    func1();
}