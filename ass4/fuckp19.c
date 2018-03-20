#include <stdio.h>
#include <limits.h>
int max_seg_tree[431072]={0};
int min_seg_tree[431072]={1000000000};
int inp[131072]={0};
int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}

int max(int a,int b)
{
	if(a<b)
		return b;
	else
		return a;
}

void construct_min_tree(int low,int high,int pos)
{
	if(low==high)
	{
		min_seg_tree[pos]=inp[low];
		return;
	}
	int mid=low+(high-low)/2;
	construct_min_tree(low,mid,2*pos);
	construct_min_tree(mid+1,high,2*pos+1);
	min_seg_tree[pos]=min(min_seg_tree[2*pos],min_seg_tree[2*pos+1]);
	return;
}

void construct_max_tree(int low,int high,int pos)
{
	if(low==high)
	{
		max_seg_tree[pos]=inp[low];
		return;
	}
	int mid=low+(high-low)/2;
	construct_max_tree(low,mid,2*pos);
	construct_max_tree(mid+1,high,2*pos+1);
	max_seg_tree[pos]=max(max_seg_tree[2*pos],max_seg_tree[2*pos+1]);
	return;
}

int find_min(int l,int r,int low,int high,int pos)
{
	if(l<=low && r>=high)
	{
		return min_seg_tree[pos];
	}
	if(l>high || r<low)
	{
		return 1000000000;
	}
	int mid=low+(high-low)/2;

	return min(find_min(l,r,low,mid,2*pos),find_min(l,r,mid+1,high,2*pos+1));
}

void update_min_tree(int i,int low,int high,int val,int pos)
{
	if(i<low || i>high)
	{
		return;
	}
	if(low==high)
	{
		min_seg_tree[pos]=val;
		return;
	}
	int mid=low+(high-low)/2;
	if(i>=low && i<=mid)
	{
		update_min_tree(i,low,mid,val,2*pos);
	}
	else
	{
		update_min_tree(i,mid+1,high,val,2*pos+1);
	}
	min_seg_tree[pos]=min(min_seg_tree[2*pos],min_seg_tree[2*pos+1]);
	return;
}

int find_max(int l,int r,int low,int high,int pos)
{
	if(l<=low && r>=high)
	{
		return max_seg_tree[pos];
	}
	if(l>high || r<low)
	{
		return 0;
	}
	int mid=low+(high-low)/2;

	return max(find_max(l,r,low,mid,2*pos),find_max(l,r,mid+1,high,2*pos+1));
}

void update_max_tree(int i,int low,int high,int val,int pos)
{
	if(i<low || i>high)
	{
		return;
	}
	if(low==high)
	{
		max_seg_tree[pos]=val;
		return;
	}
	int mid=low+(high-low)/2;
	if(i>=low && i<=mid)
	{
		update_max_tree(i,low,mid,val,2*pos);
	}
	else
	{
		update_max_tree(i,mid+1,high,val,2*pos+1);
	}
	max_seg_tree[pos]=max(max_seg_tree[2*pos],max_seg_tree[2*pos+1]);
	return;
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int i,t;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&inp[i]);
	}
	construct_min_tree(1,n,1);
	construct_max_tree(1,n,1);

	for(i=0;i<m;i++)
	{
		//printf("%d\n",i);
		char p[2];
		scanf("%s",p);
		if(p[0]=='r')
		{
			int j,x;
			scanf("%d%d",&j,&x);
			inp[j]=x;
			update_min_tree(j,1,n,x,1);
			update_max_tree(j,1,n,x,1);
/*
for(t=1;t<=2*n-1;t++)
			printf("%d ",max_seg_tree[t]);
		printf("\n");
		for(t=1;t<=2*n-1;t++)
			printf("%d ",min_seg_tree[t]);
		printf("\n");
*/
		}
		else if(p[0]=='t')
		{
			int j,k;
			scanf("%d%d",&j,&k);
			int min=find_min(j,k,1,n,1);
			int max=find_max(j,k,1,n,1);
			//printf("%d %d\n",max,min);
			if(max-min>k-j+1)
			{
				printf("Yes\n");
			}
			else
			{
				printf("No\n");
			}
		}/*
		for(t=1;t<=2*n-1;t++)
			printf("%d ",max_seg_tree[t]);
		printf("\n");*/
		/*for(t=1;t<=2*n+1;t++)
			printf("%d ",min_seg_tree[t]);
		printf("\n");*/
	}
	return 0;
}