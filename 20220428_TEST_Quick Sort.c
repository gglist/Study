#include <stdio.h>
#include <stdlib.h>

#define MaxSiz 30

int score[MaxSiz];


void Quick_Recursive(int parm_data[], int parm_left, int parm_right);

void Quick_Sort(int parm_data[], int parm_count)
{
	Quick_Recursive(parm_data, 0, parm_count - 1);
}

void Quick_Recursive(int parm_data[], int parm_left, int parm_right)
{
	int pivot, left_hold, right_hold;
	left_hold = parm_left;
	right_hold = parm_right;
	// 0번째 원소를 pivot으로 선택한다.
	pivot = parm_data[parm_left];

	while(parm_left < parm_right)
	{
		while((parm_data[parm_right] >= pivot) && (parm_left < parm_right)) parm_right--;

		if(parm_left != parm_right)
		{
			parm_data[parm_left] = parm_data[parm_right];
		}

		while((parm_data[parm_left] <= pivot) && (parm_left < parm_right)) parm_left++;

		if(parm_left != parm_right)
		{
			parm_data[parm_right] = parm_data[parm_left];
			parm_right--;
		}
	}

	parm_data[parm_left] = pivot;
	pivot = parm_left;
	parm_left = left_hold;
	parm_right = right_hold;

	if(parm_left < pivot) Quick_Recursive(parm_data, parm_left, pivot - 1);

	if(parm_right > pivot) Quick_Recursive(parm_data, pivot + 1, parm_right);

}


int main(int argc, char *argv[])
{
	int i, N;
	int num=1;
	float sum, average, variance;
	int Q;

	printf("총 몇 개의 성적을 입력하실건가요?\n숫자를 입력후 enter를 쳐 주세요 \n");
	
	scanf("%d", &N);
	
	if(N>MaxSiz) {
		printf("데이터가 너무 많습니다. %d개까지 처리 가능합니다.\n", MaxSiz);
		exit(1);
	}
	Q=N;

	for(i=0; i<N; i++)
	{
		printf("성적%d을 입력 해 주세요",num);
		num++;
		scanf("%d", &score[i]);

	}
	for(sum=0.0, i=0; i<N; i++) sum+=score[i];
	
	average=sum/N;

	for(sum=0.0, i=0; i<N; i++) sum+=(score[i]-average)*(score[i]-average);
	
	variance=sum/N;

	//------------------------------------------------------------------------------------------------------------//
	Quick_Sort(score, Q);

	printf("=== 성적 정렬한 후 ===\n\n");
	
	for(i = 0; i < Q; i++) printf("%d   ", score[i]);
	
	printf("\n\n");

	printf("평균:%f 분산:%f이다.\n", average, variance);

	return 0;
}