#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Static variables to store no.boxes &
//height of the wall.
static int N,K;

//static variable to store Count of boxes used.
static int COUNT;

//static variables to store heights of towers formed
// by MIKE AND TRACY
// respectively..
static int MIKE,TRACY;



//This returns the total height of 
//tower that can be build with the 
//available boxes.
int sum(int a[],int n){
	int s=0;
	for(int i=0;i<n;i++)
	s+=a[i];
	
	return s;
}


//this method will first take a sorted array,
//then form the tower for MIKE with the max elements,
//then form the tower for TRACY with the remaining elements,
//this way less no.of boxes are consumed for all possible 
//inputs
void determineBoxes(int heights[]){
	
	for(int i=0;i<N&&MIKE<K;i++){
		if((sum(heights,N)-heights[i]) < K){
			continue;
		}
		else{
			MIKE+=heights[i];
			heights[i]=0;
			COUNT++;
		}
	}
	sort(heights,heights+N,greater<int>());
	for(int i=0;i<N && TRACY<K;i++){
		TRACY+=heights[i];
		heights[i]=0;
		COUNT++;
	}
		
	
	if(MIKE>=K && TRACY >= K){
		cout<<COUNT<<endl;
	}
	else{
		cout<<-1<<endl;
	}
	//cout<<"MIKE IS : "<<MIKE<<" TRACY IS : "<<TRACY<<endl;
	
}

//driver code:
int main(void){
	
	//take the number of test cases in : 
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
		COUNT=0;
		MIKE=0;
		TRACY=0;
		//take the input of heights:
		//and minimum height required:
		cin>>N>>K;
		
		//array to hold the heights:
		int heights[N];
		
		bool flag=false;
		//accept the heights :
		for(int j=0;j<N;j++){
			cin>>heights[j];
			if(heights[j]<1 || heights[j]>100000){
				flag=true;
				break;
			}
			
		}
		if(flag){
			cout<<-1<<endl;
			continue;
		}
		
		if(sum(heights,N)<2*K){
			cout<<-1<<endl;
			continue;
		}
		
		if(N>=1&&N<=4000 && K>=1&&K<=4000){
		//sort the array in descending order :
		sort(heights,heights+N,greater<int>());
		determineBoxes(heights);
		}
		else{
			cout<<-1<<endl;
			continue;
			}
 	}
	
	return 0;
}
