#include<iostream>
#include<vector>
#include<cmath>
#include<map>

using namespace std;

vector<int> PL; //Prime List

bool isPrime(int n){

	if(n==1) return false;
	if(n<=3) return true;

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

vector<int> PrimeFactors(int n){
	vector<int> list;

	int i=0;
	while(n!=1){
		if(n%PL[i]==0){
			list.push_back(PL[i]);
			n=n/PL[i];
		}
		else i++;
	}

	return list;
}

int SmallestMultiple(int n){

	int resp=1;
	map<int,int> FactorsG;

	for(int i=2;i<=n;i++){
		vector<int> PF=PrimeFactors(i);
		map<int,int> FactorsI;

		//-------
		for(int i=0;i<PF.size();i++){
			if(FactorsI.find(PF[i])!=FactorsI.end()){
				FactorsI[PF[i]]++;
			}
			else{
				FactorsI.insert(make_pair(PF[i],1));
			}
		}
		//--------

		map<int,int>::iterator it;
		for(it=FactorsI.begin();it!=FactorsI.end();it++){
			if(FactorsG.find(it->first)==FactorsG.end()){
				FactorsG.insert(make_pair(it->first,it->second));
			}
			else{
				if(it->second>FactorsG[it->first]){
					FactorsG[it->first]=it->second;
				}
			}
		}
	}

	map<int,int>::iterator it;
	for(it=FactorsG.begin();it!=FactorsG.end();it++){
		resp=resp*pow(it->first,it->second);
	}


	return resp;
}


int main(){

	int n;
	cin >> n;

	PL = PrimeList(n);
	cout << SmallestMultiple(n) << "\n";


	return 0;
}
