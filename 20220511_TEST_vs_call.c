/*
    C언어 Hello, World! 예제
*/
#include <stdio.h>
#include <stdarg.h>

double avg(double value, ...);
void printlog(const char *format, ...);
int sum(int num_args, ...);

int main(int argc, char *argv[])
{
    printlog("result : %.3lf \r\n", avg(1.01, 34.02, 3.45, 0.1));
    printlog("sum result : %d %d %d\r\n", sum(4, 1, 2, 3, 4), 123, 456);

    return 0;
}
double avg(double value, ...)
{
    double sum = 0;
    int num = 0;
    double val = 0;

    va_list ap;

    va_start(ap, value);

    while(value != 0.0)
    {        
        printf("value %d : %.3lf \r\n", num,  value);
        sum +=value;
        num++;
        value = va_arg(ap, double);
    }
    printlog("value %d : %.3lf \r\n", num,  value);

    va_end(ap);
    return (sum/num);
}

void printlog(const char *format, ...)
{
    va_list ap;
    char buf[256]={0};
    
    va_start(ap, format);
    vsprintf(buf, format, ap);
    printf("%s",buf);
    va_end(ap);
    //printf("%s", buf);
}

int sum(int num_args, ...)
{
    int sums = 0;
    int arg = 0;

    va_list ap;

    va_start(ap, num_args);

    for(int idx = 0; idx < num_args; idx++)
    {
        arg = va_arg(ap, int);
        sums += arg;
        printlog("value %d \r\n", arg);   
    }
    va_end(ap);
    return sums;
}