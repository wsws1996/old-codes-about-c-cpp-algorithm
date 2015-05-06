/*判断素数*/
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
/*不含12的判断*/
/*使用素数表可以更快,见NYOJ孪生素数标程*/
------------------------------------------------------------
/*浮点数排序使用qsort函数cmp函数的代码*/
------------------------------------------------------------
int cmp(const void * a,const void * b)
{
  double rs=*(double*)a-*(double*)b;
  if(fabs(rs)<1e-20)
    return 0;
  else
    return rs>0?-1:1;
}
//此为从大到小，如从小到大只改动else后的return语句
------------------------------------------------------------
/*快速排序*/
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