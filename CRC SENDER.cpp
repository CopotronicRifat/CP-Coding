#include<stdio.h>
#include<string.h>

int main()
{
    char d[40],p[20],temp[40];
    int i,j,n,k,t,n1,x,y,rem;
    printf("Enter Codeword:");
    gets(d);

    printf("Enter pattern:");
    gets(p);

    k=strlen(p);
    n1=strlen(d);

    for(;;)
    {

        for(i=0; i<n1; i++)
        {
            if(d[i]!='0')
                break;
        }
        if((n1-i)<k)
        {
            rem=(n1-i);
            break;
        }

        int j=0;
        for(; i<n1; i++,j++)
            d[j]=d[i];
        d[j]='\0';

        n1=strlen(d);

        for(j=0; j<k; j++)
        {

            x=int(d[j])-48;
            y=int(p[j])-48;
            x^=y;

            x+=48;
            d[j]=char(x);
        }

    }
    if(rem==0)
        printf("\n\nNo error found");
    else
        printf("\n\nError found");
    return 0;
}
