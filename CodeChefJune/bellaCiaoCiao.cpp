# include <bits/stdc++.h>
using namespace std;
int main()
{
    long long T;cin>>T;
    for(long long i=1; i<=T; i++)
    {
        
        long long D,d,P,Q;
        cin>>D>>d>>P>>Q;
        
        long long sum,n;
        n = D/d;
        
        sum = d * (P*n + Q*( (n-1)*(n)/2 ) );
        
        if(D%d==0)
        {
            cout<<sum<<endl;
        }
        else
        {
             sum = d * (P*n + Q*( (n-1)*(n)/2 ) );
             sum = sum + D%d*(P + n*Q);
             cout<<sum<<endl;
        }
        
    }
    return 0;
}
