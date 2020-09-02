#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(void)
{
    int i,n=0,count1,count2;
    char team1[15],team2[15],team[15];
    count1=0;
    count2=0;
    scanf("%d",&n);
    gets(team1);
    if(n==1)
    {

        for(i=0; i<strlen(team1); i++)
        {
            printf("%c",team1[i]);
            if(i=(strlen(team1)-1))
            {
                printf("\n");
            }
        }
    }
    else
    {
        for(i=0; i<n; i++)
        {

            gets(team2);
            if(strcmp(team1,team2)==0)
            {
                count1++;
            }
            else
            {
                count2++;
            }
        }
        if(count1>count2)
        {
            for(i=0; i<strlen(team1); i++)
            {
                printf("%c",team1[i]);
            }
            printf("\n");
        }
        else
        {
            for(i=0; i<strlen(team2); i++)
            {
                printf("%c",team2[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
