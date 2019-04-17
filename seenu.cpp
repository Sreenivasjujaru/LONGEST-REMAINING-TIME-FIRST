#include<stdio.h>
#include<stdlib.h>
int main()
{
	float avwt=0.0,avtt=0.0;
	char p[3]={'A','B','C'};
	int i,bursttt[3]={2,4,8},arrvt[3]={0,0,0},burstt[3]={2,4,8},pid[3]={2132, 2102, 2453 };
	int wt[3]={0,0,0},tt[3]={0,0,0},t=0,j=0,m=2,k;
	
	    printf("\n  Student      Id      Burst time      Arrival time");
	for(i=0;i<3;i++)
	{
		printf("\n    %c         %d          %d                %d",p[i],pid[i],burstt[i],arrvt[i]);
		t=t+burstt[i];
		tt[i]=tt[i]+burstt[i];
	}
	printf("\n\n\nGANTT CHART: ");
	printf("   |");
	for(i=0;i<t;i++)
	{
		for(j=0;j<3;j++)
		{
			if(burstt[j]>burstt[m])
			{
				m=j;
			}
			if(burstt[m]==burstt[j])
			{
				if(pid[m]>pid[j])
					m=j;
			}
		}
		burstt[m]=burstt[m]-1;
		for(k=0;k<3;k++)
		{
			if(m==k)
			{
				printf("");
			}
			else
			{
				if(burstt[k]>0)
				{
					wt[k] = wt[k] + 1;
			     	tt[k] = tt[k] + 1;
				}
			}
		}
		printf(" %c |",p[m]);
	}
    printf("\n               ");
	for(i=0;i<10;i++)
	{
		printf(" %d  ",i);
	}
	for(i=10;i<15;i++)
	{
		printf("%d  ",i);
	}
	printf("\n\n");
	    printf("\n  Student       Id       Burst time       Arrival time     Waiting time      Turnarround time ");
	for(i=0;i<3;i++)
	{
		printf("\n    %c          %d           %d                %d              %d                    %d ",p[i],pid[i],bursttt[i],arrvt[i],wt[i],tt[i]);
	
	}

	for(i=0;i<3;i++)
	{
		avwt+=wt[i];
		avtt+=tt[i];
	}
	avwt=avwt/3;
	avtt=avtt/3;
	printf("\n\nAverage Waiting Time = %f",avwt);
	printf("\nAverage Turnarround Time = %f",avtt);
	
}
