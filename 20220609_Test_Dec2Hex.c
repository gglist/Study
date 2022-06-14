/*
    C언어 Hello, World! 예제
*/
#include <stdio.h>

long hex2dec(char *a);

int main(int argc, char *argv[])
{
    char buf[10]={0,};
    long dec = 0;

    printf("Hex is >> ");
    scanf("%s", buf);

    printf("\r\ninput is %s\r\n", buf);
    dec = hex2dec(buf);
    printf("dec is %ld\r\n", dec);

    return 0;
}

long hex2dec(char *a)
{
    char c;
    unsigned char diff;
    long ret = 0;

    while(*a)
    {
        c = *a++;
        diff = c - '0';
        if(diff > 9)
            {
                printf("%d %d ", c, diff);
                diff = (c | 0x20) - 'a';
                printf("%d\r\n", diff);
                if(diff > 5)
                {
                    return ret;
                }
                diff += 10;
            }
        ret = (ret << 4) + diff;
    }
    return ret;
}