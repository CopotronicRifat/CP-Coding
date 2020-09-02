#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int main(void)
{
    int n;
    int count =0;
    int alpha[30]= {0};
    char s[1500];
    while(((scanf("%s",&s))==1))
    {
        for(int i=0; i<30; i++)
        {
            alpha[i]=0;
        }
        count =0;
        for(int i=0; i<strlen(s); i++)
        {
            alpha[toascii(s[i])-97]=1;
        }
        for(int i=0; i<30; i++)
        {
            if(alpha[i]==1)
            {
                count++;
            }
        }
        scanf("%d",&n);
        if(strlen(s)<n)
        {
            printf("impossible\n");
        }
        else
        {
            printf("%d\n",n-count);
        }
    }
    return 0;
}
