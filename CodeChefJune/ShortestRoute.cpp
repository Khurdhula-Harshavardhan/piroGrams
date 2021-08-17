#include<bits/stdc++.h>
using namespace std;




long long SearchShortestLeft(long long stations[],long long destination){
	for(long long i=destination-1,distance=0; i>=0; i--,distance++){
		if(stations[i]!=1){
			continue;
		}
		else
			return distance;
	}
	return -1;
}

long long SearchShortestRight(long long stations[],long long destination,long long M){
	
	for(long long i=destination-1,distance=0; i<M; i++,distance++){
		if(stations[i]!=2){
			continue;
		}
		else
			return distance;
	}
	return -1;
}





int main(void){
	ios_base::sync_with_stdio(false);
cin.tie(NULL);
	
	long long T;
	
	cin>>T;
	for(long long i=0;i<T;i++){
		long long N,M;
	cin>>N>>M;
	long long stations[N],travellers[M];
	
	//Get them stations..
	for(long long i=0;i<N;i++)
		cin>>stations[i];
		
	long long destination;
	//Get them travellers....
	for(long long i=0;i<M;i++)
		{
			cin>>destination;
			
			if (destination != 1 || stations[destination-1]==0){
				long long left_distance,right_distance;
				
				left_distance=SearchShortestLeft(stations,destination);
				right_distance=SearchShortestRight(stations,destination,N);
				
				
				if(left_distance!=-1 && right_distance!=-1 && left_distance<=right_distance){
					cout<<left_distance<<" ";
				}
				else if(right_distance!=-1){
					cout<<right_distance<<" ";
				}
				else if(stations[0]==1){
					cout<<destination-1<<" ";
				}
				else{
					cout<<-1<<" ";
				}
			}
			else{
				cout<<0<<" ";
			}
		}	
			
		cout<<"\n";
	}
	
	return 0;
}

