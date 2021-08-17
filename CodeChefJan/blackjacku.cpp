#include<iostream>
#include<bits/stdc++.h>
using namespace std;

static int unplayable,LowerBound,UpperBound,N,COUNT,inde;



//check that its within the range mentioned i.e upperbound && lowerbound
bool verify(int n){
	if(n>=LowerBound && n<=UpperBound){
		return true;
	}
	else{
		return false;
	}
}



//check if it can be played
bool canbePlayed(int x,int y){
	x=x+y;
	if(verify(x) || x<LowerBound){
		return true;
	}
	else
	{
		return false;
	}
}


//play the cards
void playCards(int a[]){
	int sum=0;
	int playable[N];
	
	
	if(verify(a[0])){
		cout<<0<<endl;
	}
	else{
		for(int i=0;i<N && !verify(sum);i++){
			if(canbePlayed(sum,a[i])){
				sum=sum+a[i];
				if(verify(sum))
				{
					break;
				
				}
				playable[inde]=a[i];
				inde++;
			}
			else{
				if(inde!=0){
				sort(playable,playable+inde,greater<int>());
				for(int i=0;i<inde;i++){
					if(canbePlayed(sum,playable[i])){
						sum=sum+playable[i];
						COUNT++;
						if(verify(sum))
							{
							break;
							}
					}
					else
					continue;
				}
			}
			else{
				unplayable++;
			}
		
		}
		
	}
	if(unplayable!=N && verify(sum) && COUNT<=2){
			cout<<COUNT<<endl;
		}
		else{
			cout<<-1<<endl;
		}
}
}

//driver code
int main(void){
	int test_cases;
	
	cin>>test_cases;
	for(int i=0;i<test_cases;i++){
		cin>>N>>LowerBound>>UpperBound;
		COUNT=0;
		unplayable=0;
		inde=0;
		int cards[N];
		for(int j=0;j<N;j++){
			cin>>cards[j];
		}
		if(cards[0]>UpperBound){
			cout<<-1<<endl;
			continue;
		}
		
		playCards(cards);
	}
}
