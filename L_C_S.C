#include<stdio.h>
#include<conio.h>
#include<string.h>
void LCS_PROBLEM(char X[], char Y[], int m, int n )
{
    // m=length of string X
    // n=length of string Y
    int L[20][20];
    char a[20][20];
    int i,j;

     for (i=0; i<=m; i++)
     {
	for (j=0; j<=n; j++)
	{
	   if (i == 0 || j == 0)
		L[i][j] = 0;
		a[i][j] = ' ';
	}
     }

    for (i=1; i<=m; i++)
    {
	for (j=1; j<=n; j++)
	{
	     if (X[i-1] == Y[j-1])
	     {
		  L[i][j] = L[i-1][j-1] + 1;
		  a[i][j] = 'd';
	     }
	     else
	     {
		  L[i][j] = max(L[i-1][j], L[i][j-1]);
		  a[i][j] = 'u';
	     }
	}
     }

     printf("\n\nLCS TABLE :\n-------------------------------------------\n       ");
     for(i=0;i<n;i++)
     {
	printf("%c   ",Y[i]);
     }
     printf("\n");

     for (i=0; i<=m; i++)
     {
	if(i==0)
	{   printf("   ");  }
	if(i!=0)
	{   printf("%c  ",X[i-1]);  }
	for (j=0; j<=n; j++)
	{
	    printf("%d %c  ",L[i][j],a[i][j]);
	}
	printf("\n");
     }
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

void main()
{
    char X[10],Y[10];
    int len1,len2,x;
    clrscr();
    printf("\nEnter the String X : ");
    scanf("%s",&X);
    printf("\nEnter the String Y : ");
    scanf("%s",&Y);
    printf("\nX = %s",X);
    printf("\nY = %s",Y);
    len1=strlen(X);
    len2=strlen(Y);
    LCS_PROBLEM(X,Y,len1,len2);
    getch();
p}