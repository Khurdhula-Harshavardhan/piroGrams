#include<bits/stdc++.h>
#include<iostream>
using namespace std;

static int SUM;

void compute(){
	int setters,probs,days;
	
	cin>>setters>>probs>>days;
	
	int Ai;
	
	for(int i=0;i<setters;i++){
		cin>>Ai;
		SUM+=Ai;
	}
	
	if((SUM/probs) <days){
		cout<<SUM/probs<<endl;
	}
	else{
		cout<<days<<endl;
	}
	
}

int main(void){
	int n;
	
	cin>>n;
	
	for(int i=0;i<n;i++){
		SUM=0;
		compute();
	}
	
	return 0;
}
