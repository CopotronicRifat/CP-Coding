#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
int main(void)
{
    int count=0;
    float weight[4]= {0.2,0.1,0.52,0.7};
    float threshold=0.5,sum=0,substitute;
    int x[16][4]= {0,0,0,0,
                   0,0,0,1,
                   0,0,1,0,
                   0,0,1,1,
                   0,1,0,0,
                   0,1,0,1,
                   0,1,1,0,
                   0,1,1,1,
                   1,0,0,0,
                   1,0,0,1,
                   1,0,1,0,
                   1,0,1,1,
                   1,1,0,0,
                   1,1,0,1,
                   1,1,1,0,
                   1,1,1,1,
                  },i,j;
first:
    for(i=0; i<16; i++)
    {
second:
        count++;
        for(j=0; j<4; j++)
        {
            sum+=x[i][j]*weight[j];
            substitute=sum;
        }
        if(substitute>threshold && i<8)
        {
            printf("\nsum=%.2f\n",substitute);
            for(j=0; j<4; j++)
            {
                if(x[i][j]==1)
                {
                    weight[j]=weight[j]-x[i][j];
                    //if(weight[j]<0)
                    //{
                    //    weight[j]=(-1)*weight[j];
                    //}
                }
            }
        }
        if(sum<threshold && i>=8)
        {
            for(j=0; j<4; j++)
            {
                if(x[i][j]==1)
                {
                    weight[j]=x[i][j]+weight[j];
                }
            }
            goto first;
        }
        sum=0;
    }
    for(j=0; j<4; j++)
    {
        printf("\nweight[%d]=%.2f",j,weight[j]);
    }
    printf("\nNumber of iteration: %d",count);
    return 0;
}
