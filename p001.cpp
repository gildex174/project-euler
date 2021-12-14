//https://projecteuler.net/problem=1
#include<iostream>

using namespace std;

int main(){

	int n=1000,sum=0;

	for(int i=1;i<n;i++){
		if(i%3==0 or i%5==0)
			sum += i;
	}

	cout << sum << "\n";

	return 0;
}