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

string StringSum(string a, string b){
	string major, minor;
	if(a.size()>b.size()){
		major=a;
		minor=b;
	}
	else{
		major=b;
		minor=a;
	}
	int n1=major.size(), n2=minor.size();

	major = reverse(major);
	minor = reverse(minor);

	int d=0,u=0;

	string sum;
	for(int i=0;i<n2;i++){
		int sum_aux = major[i]+minor[i]-'0'-'0';
		sum_aux+=d;

		u=sum_aux%10;
		d=sum_aux/10;

		stringstream ss;
		string str;
		ss<<u;
		ss>>str;

		sum.append(str);
	}

	for(int i=n2;i<n1;i++){
		int sum_aux = major[i]-'0';
		sum_aux+=d;

		u=sum_aux%10;
		d=sum_aux/10;

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

string StringMultiplication(string a, string b){

	int n1=a.size(), n2=b.size();
	a = reverse(a);
	b = reverse(b);

	string sum="0";

	//i and j -> number of zeros
	for(int i=0;i<n1;i++){
		//digit a[i]
		int li = a[i]-'0';

		for(int j=0;j<n2;j++){

			//digit a[j]
			int lj = b[j]-'0';
			int pro = li*lj;

			stringstream ss;
			string str_pro;

			ss<<pro;
			ss>>str_pro;

			for(int z=0;z<i+j;z++){
				str_pro=str_pro+"0";
			}

			sum = StringSum(str_pro,sum);
		}
	}

	return sum;
}

int SumDigits(string a){
	int sum=0, n=a.size();

	for(int i=0;i<n;i++){
		int aux = a[i]-'0';
		sum+=aux;
	}
	return sum;
}

int main(){

	string num="1024";

	for(int i=1;i<100;i++){
		num=StringMultiplication(num,"1024");
	}

	cout << SumDigits(num) << "\n";
	
	return 0;
}