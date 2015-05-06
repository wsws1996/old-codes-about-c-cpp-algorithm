# include<stdio.h>

int FindPos(int *head,int low,int up)
{
	int val=head[low];
	while(low<up)
	{
		while (low<up && head[up]>=val)
			--up;
		head[low]=head[up];
		
		while(low<up && head[low]<=val)
			++low;
		head[up]=head[low];
	}
	head[low]=val;
	return low;
}

void QuickSort(int *head,int low,int up)
{
	int pos;
	if(low<up)
	{
		pos=FindPos(head,low,up);
		QuickSort(head,low,pos-1);
		QuickSort(head,pos+1,up);
	}
}

int main (void)
{
	int num,cnt;
	scanf("%d",&num);
	int data[num];
	for(cnt=0;cnt<num;++cnt)
		scanf("%d",data+cnt);
	QuickSort(data,0,num-1);
	for(cnt=0;cnt<num;++cnt)
		printf("%d\n",data[cnt]);
	return 0;
 } 
