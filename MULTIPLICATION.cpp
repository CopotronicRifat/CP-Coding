#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int main(void)
{
    char a[300],b[300];
    int c[600];
    int res[600];
    int mul[600][600];
    int lenA,lenB;
    while(scanf("%s%s",&a,&b)==2)
    {
        lenA=strlen(a);
        lenB=strlen(b);
        int maxx=max(lenA,lenB);
        //printf("a=%c, b=%c",a[lenA-1],b[lenB-1]);
        int count=2*maxx*maxx;
        //printf("Count: %d ",count);
        int sum=0,carry=0,cc=0,dd=0;
        for(int i=lenA-1; i>=0; i--)
        {
            for(int l=0; l<dd; l++)
            {
                c[count--]=0;
                cc++;
            }
            dd++;
            for(int j=lenB-1; j>=0; j--)
            {
                sum=(((a[i]-48)*(b[j]-48))+carry)%10;
                carry=(((a[i]-48)*(b[j]-48))+carry)/10;
                printf("\na=%c, b=%c",a[i],b[j]);
                printf("\nSum: %d\nCarry: %d",sum,carry);
                c[count--]=sum;
                cc++;
            }
            c[count--]=carry;
            cc++;
            for(int k=cc; k<2*maxx; k++)
            {
                c[count--]=0;
            }
            cc=0;
            carry=0;
        }
        int mm=2*maxx*maxx;
        for(int i=0; i<maxx; i++)
        {
            for(int j=0; j<2*maxx; j++)
            {
                mul[i][j]=c[mm];
                mm--;
            }
        }
        int summ=0,car=0;
        for(int i=0; i<2*maxx; i++)
        {
            summ=0;
            for(int j=0; j<maxx; j++)
            {
                summ=summ+mul[j][i];
            }
            summ=summ+car;
            //printf("%d ",summ%10);
            res[i]=summ%10;
            car=summ/10;
        }
        int flag;
        for(int i=2*maxx; i>=0; i--)
        {
            if(res[i]!=0)
            {
                flag=i;
                break;
            }
        }
        printf("\nMultiplication result is: ");
        for(int i=flag; i>=0; i--)
        {
            printf("%d",res[i]);
        }
        printf("\n");

        for(int i=0; i<300; i++)
        {
            a[i]=0;
            b[i]=0;
        }
        for(int i=0; i<600; i++)
        {
            c[i]=0;
            res[i]=0;
            for(int j=0; j<600; j++)
            {
                mul[i][j]=0;
            }
        }

    }

    return 0;
}
