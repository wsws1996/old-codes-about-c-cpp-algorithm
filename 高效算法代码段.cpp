/*�ж�����*/
--------------------------------------------------------------
bool is_prime(int inf)
{
	int cal;
	double res;
	res = sqrt((double)inf);
	for (cal = 2; cal <= (int)res; ++cal)
	{
		if (inf % cal == 0)
			return false;
	}
	return true;
}
/*����12���ж�*/
/*ʹ����������Ը���,��NYOJ�����������*/
------------------------------------------------------------
/*����������ʹ��qsort����cmp�����Ĵ���*/
------------------------------------------------------------
int cmp(const void * a,const void * b)
{
  double rs=*(double*)a-*(double*)b;
  if(fabs(rs)<1e-20)
    return 0;
  else
    return rs>0?-1:1;
}
//��Ϊ�Ӵ�С�����С����ֻ�Ķ�else���return���
------------------------------------------------------------
/*��������*/
------------------------------------------------------------
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
------------------------------------------------------------