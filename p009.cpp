#include<iostream>
#include<cmath>
#include<set>

using namespace std;
set<int> squaren;

void square(int n){
	for(int i=2;i<=n;i++){
		squaren.insert(pow(i,2));
	}
}

int spt(){
	int abc;

	for(int a=1;a<1000;a++){
		for(int b=a+1;b<1000;b++){
			int a2=pow(a,2),b2=pow(b,2);

			if(squaren.find(a2+b2)==squaren.end()) continue;

			int c=pow(a2+b2,0.5);

			if(a+b+c==1000){
				return a*b*c;
			}
		}
	}

	return abc;
}
int main(){

	int n;
	cin >> n;

	square(n);
	cout << spt() << "\n";
	
	return 0;
}