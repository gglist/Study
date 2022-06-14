/*
    C언어 Hello, World! 예제
*/
#include <stdio.h>

int max_number(int *parr);
int sort(int *parr, int);

int main(int argc, char *argv[])
{
    int arr[10];
    int i;
    /* 사용자로 부터 원소를 입력 받는다. */
    for (i = 0; i < 10; i++) 
    {
        scanf("%d", &arr[i]);
    }
    printf("입력한 배열 중 가장 큰 수 : %d \n", max_number(arr));

    /* sort */
    sort(arr, 1);

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