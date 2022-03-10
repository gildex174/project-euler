//Find the largest palindrome made from the product of two 3-digit numbers.
#include<iostream>
#include<sstream>

using namespace std;

bool isPalindrome(int x, int y){
	stringstream ss;
	string str;
	int number = x*y;

	ss << number;
	ss >> str;

	for(int i=0;i<str.size()/2;i++){
		if(str[i]!=str[str.size()-i-1]) return false;
	}

	return true;
}

int lpp(){
	int largest=-1;

	for(int i=100;i<1000;i++){
		for(int j=100;j<1000;j++){
			int aux = i*j;

			if(isPalindrome(i,j)){
				if(i*j>largest) largest=i*j;
			}
		}
	}

	return largest;
}

int main(){

	cout << lpp() << "\n";
	
	return 0;
}