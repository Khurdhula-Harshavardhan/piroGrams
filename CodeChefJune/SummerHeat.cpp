#include<iostream>
using namespace std;

//A program by KH.
int main(void){
	int testcases;
	cin>>testcases;
	
	int water,pulp,RecomWater,RecomPulp;
	
	for(int i=0;i<testcases;i++){
		
		//take inputs.
		cin>>water>>pulp>>RecomWater>>RecomPulp;
		
		cout<<((RecomWater/water)+(RecomPulp/pulp))<<endl;
		
	}
}
