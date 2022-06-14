/*
    C언어 Hello, World! 예제
*/
#include <stdio.h>

#define TRIANGLE        0

int main(int argc, char *argv[])
{
    int input = 0;
    int sum = 1;
    int limit = 0;
    int val1 = 0;
    int val2 = 0;
    int buf = 0;

    printf("입력 하시오 : ");
    scanf("%d", &input);

#if TRIANGLE
    for(int idx = 1; idx <= input; idx++) // 삼각형
#else
    for(int idx = input; idx > 0; idx--)    // 역삼각형
#endif
    {
        limit = 1 + (2 * (idx -1));   
        printf("%05d", limit);

        for(int jdx = idx; jdx <= (input-1); jdx++)
        {
            printf(" ");
        }
        for(int zdx = 1; zdx <= limit; zdx++)
        {
            printf("*");
        }
        printf("\r\n");
    }
    /* 입력 받은 값까지 곱을 출력 */
    for(int idx = 1; idx <= input; idx++)
    {
        sum = sum * idx;
    }
    printf("multiplication SUM IS %d\r\n", sum);
    sum = 0;
    /* 1000 이하 3또는 5의 배수인 자연수들의 합 */
    for(int idx = 0; idx <= 1000; idx++)
    {
        if((idx % 3) == 0 || (idx % 5) == 0)
        {
            sum = sum + idx;
        }
    }
    printf("SUM IS %d\r\n", sum);
    sum = 0;
    /* 1000 이하 피보나치 수열의 짝수 항들의 합 */
    val1 = 0;
    val2 = 1;
    for(int idx = 1; val2 <= 1000000; idx++)
    {
        buf = val2;
        val2 = val1 + val2;
        val1 = buf;

        //printf("%d Setp is %d|%d\r\n", idx, val1, val2);

        if((idx%2) == 0)
        {
            sum = sum + val1;
        }
    }
    printf("SUM IS %d\r\n", sum);
    /* a + b + c = 2000, a > b > c, value is intiger*/
    int a = 0;
    int b = 0;
    int c = 0;
    sum = 0;
    for (c = 1; c <= 2000; c++) 
    {
		for (b = c + 1; b > c; b++) 
        {
			a = 2000 - b - c;
            
			if (a > b && b > c) 
            {
				sum++;
			}
			else break;
		}
	}
	printf("Counter is %d\r\n", sum);

    printf("%d = ", input);

    while(1)
    {
        if(input )
    }
    return 0;
}