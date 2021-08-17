#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//A program by KH

int KhHasGotEmMoney(long long int D,long long int d,long long int P,long long int Q){
	long long int totald=(D-1)/d;
	long long int temp=D-(d*totald);
	long long int x=0;
	
	long long int n=totald-1;
	
	x+=d*((((float)n)/2)*(1+n));
	x+=(temp*totald);
	
	return (D*P)+(x*Q);
}


int main(void){
    
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
	
    long long int testcases;
	cin>>testcases;
    long long int D,d,P,Q;
	for(long long int i=0;i<testcases;i++){
		cin>>D>>d>>P>>Q;
		if((D-d)==1){
			cout<<(D*P)+Q<<"\n";
		}
		else
		cout<<KhHasGotEmMoney(D,d,P,Q)<<"\n";
	}
}

