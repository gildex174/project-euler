#include<iostream>
#include<cmath>

using namespace std;

bool isPrime(int n){
	for(int i=2;i<=pow(n,0.5);i++){
		if(n%i==0) return false;
	}


	return true;
}

int nthPrime(int n){
	int i=1,j=3;

	if(n==1) return 2;

	while(i!=n){
		if(isPrime(j)){
			i++;
		}
		if(i==n) return j;
		j+=2;
	}
}

int main(){
	int n;
	cin >> n;

	cout << nthPrime(n) << "\n";


	return 0;
}