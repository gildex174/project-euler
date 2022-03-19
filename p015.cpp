#include<iostream>
#include<cmath>


using namespace std;

/*
Problem -> Permutations of Right(R) and Down(D)
R->D->R->...->D; n terms 
P = [(2n)!]/(n!*n!)
P = {[2^(n/2)]*[(2n-1)*(2n-3)*...*(n+1)]}/[(n/2)!]

*/

long long factorial(int n){
	long long product=1;
	for(int i=1;i<=n;i++){
		product=product*i;
	}

	return product;
}

long long PermutationPaths(int n){
	long long p1=1;
	for(int i=n+1;i<=2*n-1;i+=2){
		p1 = p1*i;
	}

	p1=p1*pow(2,n/2);

	return p1/factorial(n/2);
}

int main(){

	int n;
	cin >> n;

	cout << PermutationPaths(n) << "\n";

	return 0;
}