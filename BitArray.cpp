/*
You are given four integers: , , , . You will use them in order to create the sequence  with the following pseudo-code.

a[0] = S (modulo 2^31)
for i = 1 to N-1
    a[i] = a[i-1]*P+Q (modulo 2^31) 
Your task is to calculate the number of distinct integers in the sequence .

Input Format

Four space separated integers on a single line, , , , and  respectively.

Output Format

A single integer that denotes the number of distinct integers in the sequence .

Constraints




Sample Input

3 1 1 1
Sample Output

3
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;



int main() {
    unsigned long long n,s,p,q,r=0,ans=0,returned,v;
    n=100000000; s=1232077670; p=126810854; q=1536183938; 
    cin>>n>>s>>p>>q;
    unsigned long long i, a0=s, a=s, ap=0, k=0, kt=0;

    v=pow(2,31);
    
    for(i=0; i<n; i++){
        
        a=(a*p+q);
        a=a%v;
      
        if((a==a0 || a==ap) && i!=0){
            k=i+1;
            break;
        }
        ap=a;
    }
    if (i==n) k=i;


    cout <<k<<endl;

    return 0;
}