//https://projecteuler.net/problem=2
#include<iostream>

using namespace std;

#define MAX 4000000

int main(){

	int f1=1,f2=2,aux,sum=2;

	while(f2<=MAX){
		aux = f2;
		f2 = f1 + f2;
		f1 = aux;

		if(f2%2==0){
			sum+=f2;	
		} 
	}

	cout << sum << "\n";

	return 0;
}