//https://projecteuler.net/problem=3
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;


std::vector<long long> factor;
std::vector<long long > p_factor;

bool isPrime(long long num){
	bool prime = true;

	for(int i=2;i<pow(num,0.5);i++){
		if(num%i==0) prime=false;
	}

	return prime;
}

int main(){

	//Fatores
	long long number=600851475143;
	for(int i=2;i<=pow(number,0.5);i++){
		if(number%i==0){
			factor.push_back(i);
			factor.push_back(number/i);
		}
	}

	long long largest=0;

	//Fatores primos
	for(int i=0;i<factor.size();i++){
		if(isPrime(factor[i])) p_factor.push_back(factor[i]);
	}
	//Maior fator primo
	for(int i=0;i<p_factor.size();i++){
		if(p_factor[i]>largest) largest=p_factor[i];
	}

	cout << largest << "\n";

	return 0;
}