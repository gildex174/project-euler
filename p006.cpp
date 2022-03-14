#include<iostream>
#include<cmath>

using namespace std;
int SumSquares(int n){
	int number;
	number=n*(n+1)*(2*n+1);
	number = number/6;

	return number;
}

int SquaresSum(int n){
	int number;
	number = pow(n,4)+2*pow(n,3)+pow(n,2);
	number = number/4;

	return number;
}
int main(){

	int  n;
	cin >> n;

	cout << SquaresSum(n)-SumSquares(n) << "\n";

	return 0;
}