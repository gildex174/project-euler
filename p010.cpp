#include<iostream>
#include<cmath>

using namespace std;

bool isPrime(int n){
	if(n==1) return false;
	if(n<=3) return true;

	for(int i=2;i<=pow(n,0.5);i++){
		if(n%i==0) return false;
	}

	return true;
}

long long SumPrimes(int n){

	long long sum=0;
	for(int i=2;i<n;i++){
		if(isPrime(i)){
			sum+=i;
		}
	}
	return sum;
}

int main(){

	int n;
	cin >> n;

	cout << SumPrimes(n) << "\n";

	return 0;
}