#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main (void)
{
	char text[1500],pattern[1500];
	cin>>text;
	cin>>pattern;
	cout<<strlen(text)<<endl;
	cout<<strlen(pattern)<<endl;
	bool flag=true;
	int count=0;
	for (int i=0;i<(strlen(text)-strlen(pattern));i++)
	{
		for(int j=0;j<strlen(pattern);j++)
		{
		    if(text[i+j]==pattern[j])
            {
                flag=true;
            }
            else
            {
                flag=false;
                break;
            }

		}
		if(flag==true)
        {
            count++;
        }
	}
	cout<<count<<endl;
	return 0;
}
