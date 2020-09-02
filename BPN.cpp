#include<cstdio>
#include<cstdlib>
#include<cmath>
int main(void)
{
    int i,n,j,a,k;
    double c,weightij[10][10],weightjk[10][10],uhj[5],activj[5],uok[5],oaj[5],oaj1,netaj[10];
    double netak[5],c1,c2,activk[5],oak1,oak[5],delak[5],del,del1,sum,wsdel=0;
    double delweightjk[10][10],delweightij[10][10],deluok[5],deluhj[5];

    int input,hidden,output;
    printf("\nEnter the number of input layer: ");
    scanf("%d",&input);
    printf("\nEnter the number of hidden layer: ");
    scanf("%d",&hidden);
    printf("\nEnter the number of output layer: ");
    scanf("%d",&output);
    for(i=0; i<input; i++)
    {
        for(j=0; j<hidden; j++)
        {
            weightij[i][j]=(double)(rand()%10)/10;
            printf("%lf ",weightij[i][j]);
        }
    }
    for(i=0; i<hidden; i++)
    {
        for(j=0; j<output; j++)
        {
            weightjk[i][j]=(double)(rand()%10)/10;
            printf("%lf ",weightjk[i][j]);
        }

    }
    for(j=0; j<hidden; j++)
    {
        uhj[j]=(double)(rand()%10)/10;
        printf("%lf ",uhj[j]);
    }
    for(k=0; k<output; k++)
    {
        uok[k]=(double)(rand()%10)/10;
        printf("%lf ",uok[k]);
    }
    float eta1=0.1;
    float eta2=0.1;
    float k1=0.4;
    float k2=0.5;
    int o[16][5] = {  0,0,0,0,0,
                      0,0,0,1,0,
                      0,0,1,0,0,
                      0,0,1,1,0,
                      0,1,0,0,0,
                      0,1,0,1,0,
                      0,1,1,0,0,
                      0,1,1,1,0,
                      1,0,0,0,1,
                      1,0,0,1,1,
                      1,0,1,0,1,
                      1,0,1,1,1,
                      1,1,0,0,1,
                      1,1,0,1,1,
                      1,1,1,0,1,
                      1,1,1,1,1
                   };
    printf("\n");
    for(i=0; i<16; i++)
    {
        for(j=0; j<5; j++)
        {
            printf("%d ",o[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    int tar[4][2]= { 0,0,
                     0,1,
                     1,0,
                     1,1
                   };
    for(i=0; i<4; i++)
    {
        for(j=0; j<2; j++)
        {
            printf("tar[%d][%d]:%d ",i,j,tar[i][j]);
        }
        printf("\n");
    }
    for(a=0; a<1; a++)
    {
        c=0;
        do
        {
            for(j=0; j<hidden; j++)
            {
                c1=0;
                for(i=0; i<input; i++)
                {
                    c1+=weightij[j][i]*o[a][i];
                }
                netaj[j]=c1;
            }

            for(j=0; j<hidden; j++)
            {
                activj[j]=netaj[j]+uhj[j];
                printf("\nactivj[%d]: %lf",j,activj[j]);
                oaj1=1+exp(-(k1*activj[j]));
                oaj[j]=1/oaj1;
                printf("\n\tOaj[%d]:%lf",j,oaj[j]);
            }
            for(j=0; j<hidden; j++)
            {
                c2=0;
                for(k=0; k<output; k++)
                {
                    c2+=weightjk[j][k]*oaj[j];
                }
                netak[j]=c2;
                printf("\nnetak[%d]: %lf",j,netak[j]);
            }
            for(k=0; k<output; k++)
            {
                activk[k]=netak[k]+uok[k];
                printf("\nactivk[%d]: %lf",k,activk[k]);
                oak1=1+exp(-(k2*activk[k]));
                oak[k]=1/oak1;
                printf("\nOak[%d]: %lf",k,oak[k]);
            }
            n=floor(a/input);
            printf("\nN=%d",n);
            del1=0;
            for(k=0; k<output; k++)
            {
                delak[k]=tar[n][k]-oak[k];
                del1+=delak[k];
            }
            del=del1/output;

            printf("\nDelak1: %lf",delak[0]);
            printf("\nDelak2: %lf",delak[1]);
            printf("\nDel: %lf",del);
            if(del<=0.001)
            {
                for(j=0; j<hidden; j++)
                {
                    for(k=0; k<output; k++)
                    {
                        delweightjk[j][k]=eta2*k2*delak[k]*oaj[j]*oak[k]*(1-oak[k]);
                        printf("\ndelweightjk[%d][%d]: %lf ",j,k,delweightjk[j][k]);
                        weightjk[j][k]=weightjk[j][k]+delweightjk[j][k];
                        printf("\n%lf ",weightjk[j][k]);
                    }
                    deluok[j]=eta2*k2*delak[k]*oak[k]*(1-oak[k]);
                    uok[j]=uok[j]+deluok[j];
                    printf("%lf ",uok[j]);
                }

                for(j=0;j<hidden;j++)
                {
                    for(k=0;k<output;k++)
                    {
                        wsdel=wsdel+del*weightjk[j][k];
                    }
                }
                printf("\nWSDEL: %lf",wsdel);
                for(i=0; i<input; i++)
                {
                    for(j=0; j<hidden; j++)
                    {
                        delweightij[i][j]=eta1*k1*o[i][j]*oaj[j]*(1-oaj[j])*wsdel;
                        printf("\ndelweightij[%d][%d]: %lf ",i,j,delweightij[i][j]);
                        weightij[i][j]=weightij[i][j]+delweightij[i][j];
                        printf("\n%lf ",weightij[i][j]);
                    }
                    deluhj[i]=eta1*k1*oaj[j]*(1-oaj[j])*wsdel;
                    uhj[i]=uhj[i]+deluok[i];
                    printf("%lf ",uhj[i]);
                }
            }
            c++;
        }
        while(c<=3);
        printf("%f",c);
    }
    return 0;
}
