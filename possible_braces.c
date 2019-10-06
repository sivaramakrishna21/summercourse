/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include<malloc.h>
#include <stdio.h>
int check(char i,char *arr,int n,int n1)
{
    int count=0,count1=0;
    for(int j=0;j<n;j++)
    {
        if(arr[j]=='(')
        count++;
        else if(arr[j]==')')
        count1++;
    }
    if(i=='(')
    {
        
        if(count==n1)
        return 0;
        return 1;
    }
    else
    {
        // printf("%d %d\n",count,count1);
        if(count1<count)
        return 1;
        return 0;
    }
    
}
void print_combinations(int terms,int n,char *arr)
{
    if(terms==2*n)
    {
        for(int i=0;i<2*n;i++)
        printf("%c",arr[i]);
        printf("\n");
        return;
    }
    if(check('(',arr,terms,n))
    {
        arr[terms]='(';
        print_combinations(terms+1,n,arr);
    }
    if(check(')',arr,terms,n))
    {
        arr[terms]=')';
        print_combinations(terms+1,n,arr);
    }
    // for(int i=0;i<=n;i++)
    // {
    //     if(check(i,arr,terms))
    //     {
    //         arr[terms]=;
    //         print_combinations(terms+1,n,arr);
    //     }
    // }
}

int main()
{
    int n;
    scanf("%d",&n);
    char *arr=(char *)malloc(sizeof(char)*2*n);
    print_combinations(0,n,arr);
}
