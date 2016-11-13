#include "stdio.h"
#include <vector>
#include <deque>
#include <algorithm>
#include <cstring>

using namespace std;

deque<int> q,label;

int n,m;

vector<int> num;

int main()
{
	int i,j,k;
	scanf("%d %d",&n,&m);
	num.clear();
	for (i=0;i<n;i++)
	{
		scanf("%d",&k);
		num.push_back(k);
	}
	if (m == 1)
	{
		for (i=0;i<n;i++)
		{
			printf("%d ",num[i]);
		}
		printf("\n");
		for (i=0;i<n;i++)
		{
			printf("%d ",num[i]);
		}
		printf("\n");
		return 0;
	}
	q.clear();
	label.clear();
	for (i=0;i<m-1;i++)
	{
		if (q.empty())
		{
			q.push_back(num[i]);
			label.push_back(i);
		}
		else
		{
			while ((!q.empty()) && (q.back() >= num[i]))
			{
				q.pop_back();
				label.pop_back();
			}
			q.push_back(num[i]);
			label.push_back(i);
		}
	}
	for (i=m-1;i<n;i++)
	{
		while ((!label.empty()) && (label.front() < i-m+1))
		{
			label.pop_front();
			q.pop_front();
		}
		while ((!q.empty()) && (q.back() >= num[i]))
		{
			q.pop_back();
			label.pop_back();
		}
		q.push_back(num[i]);
		label.push_back(i);
		printf("%d",q.front());
		if (i<n-1) printf(" ");
	}
	printf("\n");
	q.clear();
	label.clear();
	for (i=0;i<m-1;i++)
	{
		if (q.empty())
		{
			q.push_back(num[i]);
			label.push_back(i);
		}
		else
		{
			while ((!q.empty()) && (q.back() <= num[i]))
			{
				q.pop_back();
				label.pop_back();
			}
			q.push_back(num[i]);
			label.push_back(i);
		}
	}
	for (i=m-1;i<n;i++)
	{
		while ((!label.empty()) && (label.front() < i-m+1))
		{
			label.pop_front();
			q.pop_front();
		}
		while ((!q.empty()) && (q.back() <= num[i]))
		{
			q.pop_back();
			label.pop_back();
		}
		q.push_back(num[i]);
		label.push_back(i);
		printf("%d",q.front());
		if (i<n-1) printf(" ");
	}
	printf("\n");
	return 0;
}
