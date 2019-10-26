#include<bits/stdc++.h>
using namespace std;
long long int maxarea(long long int a[],long long int n)
{
    stack<long long int> st;
    long long int maxarea=0;
    long long int area=0;
    long long int i;
    for(i=0;i<n;)
    {
        if(st.empty() || a[st.top()]<=a[i])
        {
            st.push(i);
            i++;
        }
        else
        {
            long long int top=st.top();
            st.pop();
            if(st.empty())
            {
                area=a[top]*i;
            }
            else
            {
                area=a[top]*(i-st.top()-1);
            }
            if(area>maxarea)
            maxarea=area;
        }
    }
        while(!st.empty())
        {
            long long int top=st.top();
            st.pop();
            if(st.empty())
            {
                area=a[top]*i;
            }
            else
            {
                area=a[top]*(i-st.top()-1);
            }
            if(area>maxarea)
            maxarea=area;
        }
    return maxarea;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int n,a[1000020],i,c;
    while(1)
    {
        cin>>n;
        if(n==0)
        break;
        else
        {
            for(i=0;i<n;i++)
            cin>>a[i];
            c=maxarea(a,n);
            cout<<c<<endl;
        }
    }
    return 0;
} 
