#include"stdafx.h"
#include <stdio.h>
int n, k, ok, arr[22], vis[22], count;

void DFS(int pos)
{
	if (count >= k)
	{
		if (count == k)
		{
			if (!ok)
			{
				ok = 1; printf("YES\n");
			}
			for (int i = 0; i < n; ++i)
			if (vis[i])
				printf("%d ", arr[i]);
			printf("\n");
		}
		return;
	}

	for (int i = pos; i < n; ++i)
	{
		count += arr[i];
		vis[i] = 1;
		DFS(i + 1);
		count -= arr[i];
		vis[i] = 0;
	}
}

int main()
{
	scanf("%d%d", &n, &k);
	ok = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", arr + i);
		vis[i] = 0;
	}
	count = 0;
	DFS(0);
	if (!ok)
		printf("NO\n");
	return 0;
}