#include<stdio.h>
int main()
{
    int a[20][20];
    int n,i,j;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i==j)
            {
                printf("%d ",a[i][j]);
            }
        }
    }
    return 0;
}
