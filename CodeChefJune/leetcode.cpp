#include<bits/stdc++.h>

#include<vector>
using namespace std;


void findPair(vector<int>elements,int targetVal){
	int n=elements.size();
	
	
	//sort the vector for Bsearch.
	std::sort(elements.begin(),elements.end());
	int diff;
	
	for(int i=0;i<n;i++){
		
		//subtract to get the key...
		diff=targetVal-elements[i];
		
		
		
		//check if the required key exists:
		if(binary_search(elements.begin() , elements.end(), diff)){
			
			//return indeces and go back.
			int temp=lower_bound(elements.begin() , elements.end(), diff) - elements.begin();
			cout<<"["<<i<<","<<temp<<"]\n";
			return;
		}
		else{
			//keep moving there's still hope. 
			continue;
		}

	}
	//NAH NEVER MIND, TURNS OUT IT WAS LIKE MRCET.
	cout<<"\n no such solution exists.";
}


int main(void){
	/*faster I/O... enable this for multiline inputs...
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);*/ 
    
    
    vector<int>v;
    
    int testcases,x;
    cin>>testcases;
    
    for(int i=0;i<testcases;i++){
    	int elements;
    	cout<<"Enter the number of elements: ";
    	cin>>elements;
    	
    	for(int take=0;take<elements;take++){
    		
    		cin>>x;
    		v.push_back(x);
		}
		
		int target;
		cout<<"\nEnter the target : ";
		cin>>target;
		
		findPair(v,target);
	}
}
