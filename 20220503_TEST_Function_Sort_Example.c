/*
    C언어 Hello, World! 예제
*/
#include <stdio.h>

int max_number(int *parr);
int factorize(int num);
int GetPrimeCount(int num);
int sort(int *parr, int);

int gcds(int num1, int num2);

int main(int argc, char *argv[])
{
    int input1, input2;

    scanf("%d %d", &input1, &input2);
    printf("%d, %d \r\n", input1, input2);
    gcds(input1, input2);

    return 0;
}
int gcds(int num1, int num2)
{
    int temp = 0;
    int buf1 = 0, buf2 = 0;
   
    buf1 = num1;
    buf2 = num2;

    while(1)
    {
        if(buf1 > buf2)
        {
            if((buf1 % buf2) == 0)
            {
                break;
            }
            else
            {                
                if((buf1 % buf2) > buf2)
                {
                    buf1 = buf1 % buf2;
                }
                else
                {
                    temp = buf2;
                    buf2 = buf1 % buf2;
                    buf1 = temp;
                }
            }
        }
        else
        {
            temp = buf2;
            buf2 = buf1;
            buf1 = temp;
        }
    }
    printf("GCD is %d \r\n", buf2);
    return 0;
}
int max_number(int *parr)
{
    int max = parr[0];

    for(int i = 1; i < 10; i++)
    {
        if(parr[i] > max)
            max = parr[i];
    }

    return max;
}
/* 소수의 갯수 */
int GetPrimeCount(int num)
{
    int count  = 1;
    //printf("2");
    for(int idx = 2; idx <= num; idx++)
    {
        //isPrime = 1;
        for(int jdx = 2; jdx < idx; jdx++)
        {
            if(idx % jdx == 0)
            {
                break;
            }
            else if(idx == (jdx+1))
            {
               //printf(", %d", idx);
               count++;
            }
        }        
    }
    //printf("\r\n");
    return count;
}
/* 소인수 분해 */
int factorize(int num)
{
    int count = 0;
    while(num != 1)
    {
        if(count++ == 100) 
            break;
        for(int idx = 2; idx <= num; idx++)
        {
            if(num % idx == 0)
            {
                printf("%d%s",idx,idx == num ? "" : " X ");
                num /= idx;
                break;
            }
        }
    }
    printf("\r\n");
    return 0;
}
/* 정렬 함수 */
/* 인자 Sort : 0 내림차순, 1 오름차순 */
int sort(int *parr,int sort)
{
    int total = 10;
    int ave = 0;
    int flag = 0;

   for(int idx = 0; idx < total; idx++)
    {
        for(int jdx = 0; jdx < (total -1); jdx++)
        {
            if(idx == jdx)
                break;
            else if((parr[idx] < parr[jdx]) && (sort == 0))
            {
                //printf("comp %d > %d, %d, %d\r\n", parr[idx], parr[jdx], idx, jdx);
                flag = 1;
            }    
            else if((parr[idx] > parr[jdx]) && (sort == 1))
            {
                //printf("comp %d > %d, %d, %d\r\n", parr[idx], parr[jdx], idx, jdx);
                flag = 1;
            }    
            if(flag)
            {
                ave = parr[jdx];
                parr[jdx] = parr[idx];
                parr[idx] = ave;
                flag = 0;
            }        
        }
    }
    for(int idx = 0; idx < total; idx++)
    {
        printf(" %d \r\n", parr[idx]);
    } 

    return 0;
}