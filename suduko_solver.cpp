#include <stdio.h>
int table_unfill(int a[9][9],int *row,int *col)
{
    for(*row=0;*row<9;*row=*row+1)
    {
        for(*col=0;*col<9;*col=*col+1)
        {
            if(a[*row][*col]==0)
            return 1;
        }
    }
    return 0;
}
int issafe(int a[9][9],int i,int j,int k)
{
    for(int ind=0;ind<9;ind++)
    {
        if(a[i][ind]==k)
        return 0;
        if(a[ind][j]==k)
        return 0;
        
    }
    i=i-i%3;
    j=j-j%3;
    for(int val1=i;val1<i+3;val1++)
    {
        for(int val2=j;val2<j+3;val2++)
        {
            if(a[val1][val2]==k)
            return 0;
        }
    }
    return 1;
}

int checkfull(int a[9][9])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(a[i][j]==0)
            return 0;
        }
    }
    return 1;
}
int fillsuduko(int a[9][9])
{
    int row,col;
    if(checkfull(a)==1)
    return 1;
    if(table_unfill(a,&row,&col)==0)
        return 0;
    for(int val=1;val<10;val++)
    {
        if(issafe(a,row,col,val))
        {
            a[row][col]=val;
            if(fillsuduko(a)==1)
            return 1;
            a[row][col]=0;
        }
    }
    return 0;
}
int main() {
	int tests,a[9][9];
	scanf("%d",&tests);
	for(int i=0;i<9;i++)
	{
	    for(int j=0;j<9;j++)
	    {
	        scanf("%d",&a[i][j]);
	    }
	}
	fillsuduko(a);
	for(int i=0;i<9;i++)
	{
	    for(int j=0;j<9;j++)
	    printf("%d ",a[i][j]);
	    printf("\n");
	}
}
