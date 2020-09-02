#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
int main()
{
    FILE *fp;
    fp=fopen("data_input_lrc.txt","w");
    vector<int>v;
    int i,j;
    int input,x,counter=0;
    cout<<"Enter the number of total bits :\n";
    cin>>input;
    cout<<"\nData is :\n\n";
    for(i=0; i<input; i++)
    {
        cin>>x;
        v.push_back(x);
    }
    for(i=0; i<input/4; i++)
    {
        for(j=i*4; j<(i*4+4); j++)
        {
            if(v[j]==1)
                counter++;
        }
        if(counter%2==0)
            v.push_back(0);
        else
            v.push_back(1);
        counter=0;
    }
     for(i=0; i<v.size(); i++)
    {
        fprintf(fp,"%d",v[i]);
    }
    fclose(fp);
}
