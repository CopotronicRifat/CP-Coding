#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
int main()
{
    FILE *fp;
    fp=fopen("data_input.txt","r");
    vector<int>v;
    int i,j,k=0,c=0;
    int x,counter=0;
    char input;
    while((input=fgetc(fp))!=EOF)
    {
        x=input-48;
        v.push_back(x);
    }
    for(i=0; i<4; i++)
    {
        for(j=i; j<v.size()-4; j+=4)
        {
            if(v[j]==1)
                counter++;
        }
        if((counter%2==0&&v[v.size()-4+k]==0)||(counter%2==1 && v[v.size()-4+k]==1))
        {
              c++;
              k++;
        }
        else
        {
            cout<<"Data is not Correct.";
            cout<<"\n";
            return 0;
        }
        counter=0;
    }
    if(c==4)
        cout<<"Data is Correct and Data is :\n\n";
        for(i=0;i<v.size()-4;i++)
            cout<<v[i];
        cout<<"\n";
    fclose(fp);
    return 0;
}
