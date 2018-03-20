#include <stdio.h>
#include <string.h>

struct node
{
	int store[10];
};

int s_array[123456];
char s[123456];
struct node tree[493824];
struct node array1,array2;

void construct_tree(int low,int high,int pos)
{
	if(low==high)
	{
		tree[pos].store[s_array[low]]++;
		return;
	}

	int mid=low+(high-low)/2;

	construct_tree(low,mid,2*pos);
	construct_tree(mid+1,high,2*pos+1);

	int i=0;
	while(i<10)
	{
		tree[pos].store[i]=tree[2*pos].store[i]+tree[2*pos+1].store[i];
		i++;
	}
	return;
}

void find_bucket(struct node buck,int l,int r,int low,int high,int pos)
{
	struct node ans;
	//buck[10]={0};

	if(l<=low && r>=high)
	{
		int i=0;
		while(i<10)
		{
			array1.store[i]+=tree[pos].store[i];
			i++;
		}
		return;
	}

	if(l>high || r<low)
	{
		return;

	}

	int mid=low+(high-low)/2;

	int i=0;
	while(i<10)
	{
		ans.store[i]=find_bucket(l,r,low,mid,2*pos).store[i]+find_bucket(l,r,mid+1,high,2*pos+1).store[i];
		i++;
	}
	return ans;
}

void find_bucket1(struct node buck,int l,int r,int low,int high,int pos)
{
	struct node ans;
	//buck[10]={0};

	if(l<=low && r>=high)
	{
		int i=0;
		while(i<10)
		{
			array2.store[i]+=tree[pos].store[i];
			i++;
		}
		return;
	}

	if(l>high || r<low)
	{
		return;

	}

	int mid=low+(high-low)/2;

	int i=0;
	while(i<10)
	{
		ans.store[i]=find_bucket(l,r,low,mid,2*pos).store[i]+find_bucket(l,r,mid+1,high,2*pos+1).store[i];
		i++;
	}
	return ans;
}

void update_tree(int i,int low,int high,int val,int pos)
{
	if(low==high)
	{
		//s_array[pos]=val;
		tree[pos].store[s_array[i]]--;
		tree[pos].store[val]++;
		return;
	}

	int mid=low+(high-low)/2;

	if(i>=low && i<=mid)
	{
		update_tree(i,low,mid,val,2*pos);
	}
	else
	{
		update_tree(i,mid+1,high,val,2*pos+1);
	}

	int k;
	for(k=0;k<10;k++)
	{
		tree[pos].store[k]=tree[2*pos].store[k]+tree[2*pos+1].store[k];
	}
	return;
}

int main()
{
	scanf("%s",s);
	int i;
	int n=strlen(s);
	for(i=1;i<=n;i++)
	{
		s_array[i]=s[i-1]-'0';
	}
	construct_tree(1,n,1);
	int q;
	scanf("%d",&q);

	while(q--)
	{
		for(i=0;i<10;i++)
		{
			array1.store[i]=0;
			array2.store[i]=0;
		}

		int p;
		scanf("%d",&p);
		if(p==1)
		{

			int pos,num;
			scanf("%d%d",&pos,&num);
			update_tree(pos,1,n,num,1);
			s_array[pos]=num;
			//for(i=0;i<10;i++)
			//printf("%d ",tree[1].store[i]);
		//printf("\n");
			/*for (i=1;i<=n;i++)
			{
				printf("%d ",s_array[i]);
			}
			printf("\n");*/
		}
		else if(p==2)
		{
			int l1,l2,r1,r2;
			int flag=0,k;
			scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
			if((r1-l1)!=(r2-l2))
			{
				printf("NO\n");
			}
			else if(l1==l2 && r1==r2)
			{
				printf("YES\n");
			}
			else
			{
				if(l2>r1)
				{
					find_bucket(array1,l1,r1,1,n,1);
					find_bucket1(array2,l2,r2,1,n,1);

					for(k=0;k<10;k++)
					{
						if(array1.store[k]!=array2.store[k])
						{
							flag=0;
							break;
						}
						else
						{
							flag=1;
						}
					}
					if(flag)
					{
						printf("YES\n");
					}
					else
					{
						printf("NO\n");
					}
				}
				else
				{
					find_bucket(array1,l1,r1,1,n,1);
					find_bucket1(array2,l2,r2,1,n,1);
					
					for(k=0;k<10;k++)
					{
						if(array1.store[k]!=array2.store[k])
						{
							flag=0;
							break;
						}
						else
						{
							flag=1;
						}
					}
					if(flag)
					{
						printf("YES\n");
					}
					else
					{
						printf("NO\n");
					}
				}
			}
		}
	}
	return 0;
}