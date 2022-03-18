#include<iostream>
#include<sstream>

using namespace std;

string reverse(string a){
	int n=a.size();

	for(int i=0;i<n/2;i++){
		swap(a[i],a[n-1-i]);
	}

	return a;
}

//a>=b 
string  StringSum(string a, string b){

	int d=0,u=0,n1=a.size(),n2=b.size();

	a=reverse(a);
	b=reverse(b);

	string sum;
	for(int i=0;i<n2;i++){
		int sum_aux = a[i]+b[i]-'0'-'0';
		sum_aux+= d;

		u=sum_aux%10;
		d=sum_aux/10;

		stringstream ss;
		string str;
		ss<<u;
		ss>>str;

		sum.append(str);

	}

	for(int i=n2;i<n1;i++){
		int sum_aux = a[i]-'0'+d;

		u = sum_aux%10;
		d = sum_aux/10;

		stringstream ss;
		string str;
		ss<<u;
		ss>>str;

		sum.append(str);

	}
	if(d!=0){
		stringstream ss;
		string str;
		ss<<d;
		ss>>str;

		sum.append(str);
	
	}
	
	return reverse(sum);

}

string list[105];

int main(){

	//n->number of strings
	int n;
	cin >> n;

	for(int i=0;i<n;i++){
		cin >> list[i];
	}

	string sum=list[0];
	for(int i=1;i<n;i++){
		sum=StringSum(sum,list[i]);
	}

	cout << sum << "\n";

	return 0;
}