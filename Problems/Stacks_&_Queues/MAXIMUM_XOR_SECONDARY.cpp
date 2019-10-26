/*    question link:  https://codeforces.com/problemset/problem/281/D    */
***************************************************************************
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int i,n,ans,a[1000000];
    stack<long long int> st;
	cin>>n;
	for(i=0;i<n;i++)
	cin>>a[i];
	ans=0;
	for(i=0;i<n;i++)
	{
	    while(!st.empty())
	    {
	        if(st.top()<a[i])
	        {
	            ans=max(ans,st.top()^a[i]);
	            st.pop();
	        }
	        else
	        {
	            ans=max(ans,st.top()^a[i]);
	            break;
	        }
	    }
	    st.push(a[i]);
	}
	cout<<ans<<endl;
	return 0;
}
