/* question link:  https://www.codechef.com/problems/CAKEDOOM  */
*****************************************************************

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t,n,i,k,flag,pos;
    string s;
    char left,right;
    cin>>t;
    while(t--)
    {
        cin>>k;
        cin>>s;
        n=s.length();
        flag=0;
        if(n==1)
        {
            if(s[0]=='?')
            s[0]='0';
            cout<<s<<endl;
        }
        else
        if(k==1)
        {
            cout<<"NO"<<endl;
        }
        else
        if(k==2)
        {
            if(n%2!=0)
            cout<<"NO"<<endl;
            else
            {
                pos=0;
                for(i=0;i<n;i++)
                {
                    if(s[i]!='?')
                    {
                        pos=i;
                        break;
                    }
                }
                for(i=pos+1;i<n;i++)
                {
                    if(s[i]=='?')
                    {
                        if(s[i-1]=='1')
                        s[i]='0';
                        else
                        s[i]='1';
                    }
                    else
                    if(s[i]==s[i-1])
                    {
                        flag=1;
                        break;
                    }
                }
                for(i=0;i<=pos;i++)
                {
                    if(s[i]=='?')
                    {
                        if(s[(i-1+n)%n]=='1')
                        s[i]='0';
                        else
                        s[i]='1';
                    }
                    else
                    if(s[i]==s[i-1])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                cout<<s<<endl;
                else
                cout<<"NO"<<endl;
            }
        }
        else
        if(k>=3)
        {
            flag=0;
            for(i=0;i<n;i++)
            {
                left=s[(i-1+n)%n];
                right=s[(i+1+n)%n];
                if(s[i]=='?')
                {
                if(left!='0' && right!='0')
                s[i]='0';
                else
                if(left=='0' && right=='0')
                s[i]='1';
                else
                if((left=='0' && right=='1') || (right=='0' && left=='1'))
                s[i]='2';
                else
                if(left!='1' && right!='1')
                s[i]='1';
                else
                flag=1;
                }
                else
                if(left==s[i] || right==s[i])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            cout<<"NO"<<endl;
            else
            cout<<s<<endl;
        }
    }
    return 0;
}
