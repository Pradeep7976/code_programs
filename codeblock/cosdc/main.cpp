#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void display(vector<int>v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int t=1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int ans=0;
        while(n!=1)
        {
            n=a.size();
            int u=a[0];
            vector<int>::iterator it;
            it=a.begin();
            a.erase(a.begin());
            for(int i=1;i<n;i++)
            {
                it++;
                int last=a[i];

                if(a[i]==u)
                {
                    //cout<<"HI"<<i<<" "<<endl;
                    ans++;
                    a.erase(it);
                }
                if(a.size()==1)
                {
                    if(a[0]==u)
                    {
                        cout<<"hi";
                        cout<<"sdfsdfasdfasdf"<<endl;
                        display(a);
                        ans++;
                    }
                    break;
                }
                display(a);
            }
            n=a.size();
        }
        cout<<ans;
    }
    return 0;
}
