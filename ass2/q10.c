#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,j;
		int n[3];
		int h[3][100003];
		int s[3]={0};
		for(i=0;i<3;i++)
		{
			scanf("%d",&n[i]);
			for(j=0;j<n[i];j++)
			{
				scanf("%d",&h[i][j]);
				s[i]+=h[i][j];
			}
		}
		int p=n[0];
		int q=n[1];
		int r=n[2];
		while(1)
		{
			if(s[0]>s[1] || s[0]>s[2])
			{
				s[0]=s[0]-h[0][p-1];
				p--;
			}
			else if(s[1]>s[0] || s[1]>s[2])
			{
				s[1]=s[1]-h[1][q-1];
				q--;
			}
			else if(s[2]>s[0] || s[2]>s[1])
			{
				s[2]=s[2]-h[2][r-1];
				r--;
			}
			else if(s[0]==s[1] && s[0]==s[2])
			{
				break;
			}
		}
		printf("%d\n",s[0]);
	}
	return 0;
}
