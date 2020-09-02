#include<stdio.h>
#include<math.h>
#define eqn x*x*x-2*x-5
double F(double x)
{
    return ((x)*(x)*(x)-2*x-5);
}
double Fd(double x)
{
    return (3*(x)*(x)-2);
}

int main(){
void newton_raphson();
void false_pos();
void compare();

	int ch=5;
	while(ch)
	{
		printf("Enter your choice:\n1. Newton-Raphson Method\n2. False position method\n3.Compare\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			newton_raphson();
			break;
			case 2:
			false_pos();
			break;
			case 3:
			compare();
			break;

		}
	}

	return 0;
}
void newton_raphson()
{
	double x0,h,err,root,x1;
    int miter,iter;
    printf("Enter the first approximation ,the max error and the maximum number of iterations\n");
    scanf("%lf%lf%d",&x0,&err,&miter);
    iter=1;
    while(iter<=miter)
    {
        h=F(x0)/Fd(x0);
        x1=x0-h;
        printf("The approximation's value after %d iteration is %.12lf\n",iter,x1);
        if(fabs(h)<err)
        {
            root=x1;
            break;
        }
        else
        x0=x1;
        iter++;
    }
    if(root==x1)
    {
        printf("The root is: %.12lf\n",root);
        double fncvalue = F(root);
        printf("Value of F(root) is: %.12lf",fncvalue);
    }
    else
    printf("The unsufficent number of iteration");

}

void false_pos()
{

 float a,b,x,fa,fb;
	int c=1;
    int miter,iter=1;
    printf("Enter value of a  & b \n");
    scanf("%f %f",&a,&b);
	while(fabs(a-b)>.0001)
    {
	  printf("The approximation's value after %d iteration is %.12lf\n",iter,x);
		printf("%d\t%f\t%f\t",c++,a,b);
        x=a;
        fa= eqn;
        x=b;
        fb = eqn;
        x= (a*fb-b*fa)/(fb-fa);
        if(eqn == 0) break;
        else if(eqn > 0)
        {
            a=x;
        }
        else
        {
            b=x;
        }
        iter++;
		printf("%f\t%f\n",x,eqn);
    }
    printf("Root is= %lf\n",x);

}

void compare(){
printf("\n Newton Raphson Method is better than False Position Method due to less number of iterations ");
}
