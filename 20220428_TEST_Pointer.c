/*
    C언어 Hello, World! 예제
*/
#include <stdio.h>

int main(int argc, char *argv[])
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int* ptr;
    int *aptr[3];

    ptr = arr[0];

    *(aptr + 0) = &(*(arr[2] +1));

    printf("Pointer size is %ld \r\n", sizeof(aptr));
    printf("Pointer is %p \r\n", aptr[0]);
    printf("Pointer is %p \r\n", aptr[1]);
    printf("Pointer is %p \r\n", aptr[2]);

    printf("Pointer is %d \r\n", *aptr[0]);
    printf("Pointer is %d \r\n", *aptr[1]);

    printf("array value is %d \r\n", arr[2][0]);

    printf("arr[] 의 주소값: %p \r\n", &arr[0][0]);
    printf("ptr       의값 : %p \r\n", ptr);
    /*
    printf("arr[] 의 주소값: %p \r\n", &arr);
    printf("arr[] 의 주소값: %p \r\n", &arr[0]);
    printf("ptr 의값 : %p \r\n", ptr);
    */
    /*
    for(int idx = 0; idx < 10; idx++)
    {
        printf("arr[%d] 의 주소값: %p ", idx, &arr[idx]);
        printf("(ptr + %d)의 값 : %p ", idx, (ptr + idx));

        if(&arr[idx] == (ptr + idx))
        {
            printf(" --> 일치\r\n");
        }
        else
        {
            printf(" --> 불일치\r\n");
        }
    }
    */
    return 0;
}