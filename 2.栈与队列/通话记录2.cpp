#include<cstdio>
#include<queue>
#include<iostream>
using namespace std;
int main()
{
    int f;
    string s;
    while(cin>>f>>s)
    {
        int i,j;
        queue<string>q[3];
        for(i=0;i<3;i++)
            while(!q[i].empty())
                q[i].pop();
        q[f].push(s);
        for(i=0;i<9;i++)
        {
            cin>>f>>s;
            q[f].push(s);
        }
        for(i=0;i<10;i++)
        {
            for(j=0;j<3;j++)
            {
                if(!q[j].empty())
                {
                    cout<<q[j].front();
                    q[j].pop();
                }
                else
                    cout<<"0";
                if(j!=2)
                    cout<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
