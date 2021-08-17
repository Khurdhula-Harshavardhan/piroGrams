#include<iostream>
#include<bits/stdc++.h>
using namespace std;

static int N,M;
static int COUNT;

//method to return sum of the arrays:
int sum(int a[],int n){
	int s=0;
	for(int i=0;i<n;i++){
		s+=a[i];
	}
	return s;
}


//this is a linear search used to search for the indexed
//element
int position(int a[],int n,int key){
	for(int pos=0;pos<n;pos++){
		if(key==a[pos]){
			return pos;
		}
	}
}


//this method takes a array in and
//implements std::min_element to
//determine the smallest element in the array
//then the linear search method is used to 
//return the position of the element.
int mini(int a[],int n){
	int* index;
	int pos;
	index = std::min_element(a+0,a+n);
	pos=position(a,n,*index);
	
	
	return pos;
	
}

//this method takes a array in and
//implements std::min_element to
//determine the smallest element in the array
//then the linear search method is used to 
//return the position of the element.

int maxi(int b[],int m){
	int* index;
	int pos;
	index = std::max_element(b+0,b+m);
	pos=position(b,m,*index);
	
	
	return pos;
}


//this method iterates and keeps swapping
//vote packs until john either wins
//or terminates with -1.
void determineSwaps(int john[],int jack[]){
	//logic to cheat.
	for(int i=0;i<N;i++){
		int min=mini(john,N),max=maxi(jack,M),temp;
		
		temp=jack[max];
		jack[max]=john[min];
		john[min]=temp;
		COUNT++;
		if(sum(john,N)>sum(jack,M))
		break;
	}
	if(sum(john,N)>sum(jack,M)){
		cout<<COUNT<<endl;
	}
	else{
		cout<<-1<<endl;
	}
}

int main(void){
	//take the number of test cases : 
	int t;
	cin>>t;
	
	//repeat this process: 
	for(int i=0;i<t;i++){
		COUNT=0;
		
		//take the sizes of john's and jack's votes:
		cin>>N>>M;
		int john[N],jack[M];
		
		
		//take the vote packs in :
		for(int j=0;j<N;j++)
		cin>>john[j];
		
		//take the vote packs in :
		for(int j=0;j<M;j++)
		cin>>jack[j];
		
		//if by default john is winning 
		//it is un neccessary to swap votes.
		//so our minimum swap would be ZERO.
		if(sum(john,N)>sum(jack,M)){
			cout<<0<<endl;
			continue;
		}
		else{
			//sort is a inbuilt function to sort arrays:
			//it is a hybrid function that 
			//uses appropriate algorithms to sort an array:
			
			//let's sort john in ascending order:
			sort(john,john+N);
			
			//let's sort jack in descending order:
			sort(jack,jack+M,greater<int>());
			
			determineSwaps(john,jack);
			
		}
	}
	return 0;
}

