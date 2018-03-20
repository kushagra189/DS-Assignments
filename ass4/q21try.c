#include <stdio.h>
#include <string.h>

int s_array[123456];
char s[123456];
int tree[493824][10];
int array1[10],array2[10];

void construct_tree(int low,int high,int pos)
{
	if(low==high)
	{
		tree[pos][s_array[low]]++;
		return;
	}

	int mid=low+(high-low)/2;

	construct_tree(low,mid,2*pos);
	construct_tree(mid+1,high,2*pos+1);

	int i=0;
	while(i<10)
	{
		tree[pos][i]=tree[2*pos][i]+tree[2*pos+1][i];
		i++;
	}
	return;
}

void find_bucket(int arr[],int l,int r,int low,int high,int pos)
{
	if(l<=low && r>=high)
	{
		int i=0;
		while(i<10)
		{
			arr[i]+=tree[pos][i];
			i++;
		}
		return;
	}

	if(l>high || r<low)
	{
		return;

	}

	int mid=low+(high-low)/2;

	find_bucket(arr,l,r,low,mid,2*pos);
	find_bucket(arr,l,r,mid+1,high,2*pos+1);
}

void update_tree(int i,int low,int high,int val,int pos)
{
	if(low==high)
	{
		//s_array[pos]=val;
		tree[pos][s_array[i]]--;
		tree[pos][val]++;
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
		tree[pos][k]=tree[2*pos][k]+tree[2*pos+1][k];
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
			array1[i]=0;
			array2[i]=0;
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
					find_bucket(array2,l2,r2,1,n,1);

					for(k=0;k<10;k++)
					{
						if(array1[k]!=array2[k])
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
					find_bucket(array2,l2,r2,1,n,1);
					
					for(k=0;k<10;k++)
					{
						if(array1[k]!=array2[k])
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