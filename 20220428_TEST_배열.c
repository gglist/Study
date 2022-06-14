/*
    C언어 Hello, World! 예제
*/
#include <stdio.h>

int main(int argc, char *argv[])
{
    int total;
    
    printf("전체 학생수 : ");
    scanf("%d", &total);

    int arr[total];
    int i, ave = 0;

    for (i = 0; i < total; i++) 
    {
        printf("%d 번째 학생의 성적은? ", i + 1);
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < total; i++) 
    {
        ave = ave + arr[i];
    }

    ave = ave / total;
    printf("전체 학생의 평균은 : %d \n", ave);

    /*
    for (i = 0; i < total; i++) 
    {
        printf("학생 %d : ", i + 1);
        
        if (arr[i] >= ave)
           printf("합격 \n");
        else
            printf("불합격 \n");
    }
    */
    /* SORT */
    for(int idx = 0; idx < total; idx++)
    {
        for(int jdx = 0; jdx < (total -1); jdx++)
        {
            if(idx == jdx)
                break;
            else if(arr[idx] > arr[jdx])
            {
                printf("comp %d > %d, %d, %d\r\n", arr[idx], arr[jdx], idx, jdx);
                ave = arr[jdx];
                arr[jdx] = arr[idx];
                arr[idx] = ave;
            }               
        }
    }
    for(int idx = 0; idx < total; idx++)
    {
        printf(" %d \r\n", arr[idx]);
    }
    /* Display Graph */
    /*
    for(int idx=0; idx<total; idx++)
    {
        printf("[%d]의 성적:",idx);
        for(int k=0; k<arr[idx]; k++)
        {
            printf("*");
        }
        printf("\n");
    }
    */
    return 0;
}