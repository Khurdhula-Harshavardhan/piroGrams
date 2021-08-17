#include<iostream>
#include<string>
using namespace std;



//variable to hold value of Lenght.
static int LENGHT;

//final output string , additional characters should be appended to this : 
static string output;

//char array holding all the letters
const char letters[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p'};


//this method converts 4 digit binary to return a char at a index of decimal.

//this is done by obtaining decimal from 8421 code.
char getCharacter(char eight,char four,char two,char one){
	int index=0;
	if(eight=='1')
	index+=8;
	if(four=='1')
	index+=4;
	if(two=='1')
	index+=2;
	if(one=='1')
	index+=1;
	
	//appending string.
	output=output+letters[index];
}


//this method will chop a stream of input code into 4 bits a set.

void chopDownCode(string code){
	for(int i=0;i<LENGHT;i+=4){
		getCharacter(code[i],code[i+1],code[i+2],code[i+3]);
	}
	
	
	
}


//this will be my driver code:

int main(void){
	
	//no of test cases :
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++){
		
		//lenght of input code:
		cin>>LENGHT;
		
		//we shall use string type to hold code:
		string code;
		cin>>code;
		
		//for every iteration output must be reset to a empty string.
		output="";
		
		//break the code: and then obtain literal.
		chopDownCode(code);
	
		cout<<output<<endl;
	}
	return 0;
}
