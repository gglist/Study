/*
    C언어 Hello, World! 예제
*/
#include <stdio.h>

int main(int argc, char *argv[])
{
    int arr[10] = {100, 98, 97, 95, 89, 76, 92, 96, 100, 99};
    int* parr = arr;
    int sum = 0;
    
    int arra[3] = {1, 2, 3};
    int (*parra)[3] = &arra;

    while (parr - arr <= 9) 
    {
        printf("Comp %p | %p | %ld\r\n", parr, arr, (parr - arr));
        sum += (*parr);
        parr++;
    }
    printf("내 시험 점수 평균 : %d \n", sum / 10);

    printf("arr : %p \n", arra);
    printf("parr : %p \n", parra);
    for(int idx = 0; idx < 3; idx++)
    {   
        printf("%d is %d \n", idx, *((*parra)+idx));
    }
    return 0;
}