#include<cmath>
#include<iostream>
#include<vector>
#include<map>

using namespace std;

bool isPrime(int n){
	if(n<=1) return false;
	if(n<3) return true;


	for(int i=2;i<=pow(n,0.5);i++){
		if(n%i==0) return false;
	}

	return true;
}

vector<int> PrimeList(int n){
	vector<int> list;

	for(int i=2;i<=n;i++){
		if(isPrime(i)) list.push_back(i);
	}

	return list;
}

int NumberDivisors(int n, vector<int> PD){

	int number=1;
	map<int,int> PD_map;

	//Prime List
	//vector<int> PD = PrimeList(n);

	int i=0;
	while(n!=1){
		if(n%PD[i]==0){
			if(PD_map.find(PD[i])!=PD_map.end()) PD_map[PD[i]]=PD_map[PD[i]]+1;
			else{
				PD_map.insert(make_pair(PD[i],1));
			}
			n=n/PD[i];
		}
		else i++;
	}

	map<int,int>::iterator it;
	for(it=PD_map.begin();it!=PD_map.end();it++){
		number=number*(it->second+1);
	}

	return number;

}

int TriangularNumbers(int n_divisors, vector<int> PL){
	int n=1, number=0;
	while(true){
		number=number+n;
		//cout << number << "\n";
		if(NumberDivisors(number, PL)>n_divisors){
			return number;
		}
		n++;
	}

}
int main(){

	//n->primes and m->divisors
	int n,m;
	cin >> n >> m;
	
	vector<int> v = PrimeList(n);
	cout << TriangularNumbers(m,v) << "\n";


	return 0;
}