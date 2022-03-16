#include<iostream>

using namespace std;

int matriz[25][25];

int Product(){
	int pro=1;

	for(int i=0;i<20;i++){
		for(int j=0;j<20;j++){

			//p_right
			if(j+3<20){
				int aux = matriz[i][j]*matriz[i][j+1]*matriz[i][j+2]*matriz[i][j+3];
				if(aux>pro) pro=aux;
			}

			//p_left
			if(j-3>=0){
				int aux = matriz[i][j]*matriz[i][j-1]*matriz[i][j-2]*matriz[i][j-3];
				if(aux>pro) pro=aux;		
			}
			//p_down
			if(i+3<20){
				int aux = matriz[i][j]*matriz[i+1][j]*matriz[i+2][j]*matriz[i+3][j];
				if(aux>pro) pro=aux;
			}

			//p_down
			if(i-3>=0){
				int aux = matriz[i][j]*matriz[i-1][j]*matriz[i-2][j]*matriz[i-3][j];
				if(aux>pro) pro=aux;			
			}

			//p_right_up
			if(j+3<20 and i-3>=0){
				int aux = matriz[i][j]*matriz[i-1][j+1]*matriz[i-2][j+2]*matriz[i-3][j+3];
				if(aux>pro) pro=aux;
			}

			//p_right_down
			if(j+3<20 and i+3<20){
				int aux = matriz[i][j]*matriz[i+1][j+1]*matriz[i+2][j+2]*matriz[i+3][j+3];
				if(aux>pro) pro=aux;

			}
			//p_left_up
			if(j-3>=0 and i-3>=0){
				int aux = matriz[i][j]*matriz[i-1][j-1]*matriz[i-2][j-2]*matriz[i-3][j-3];
				if(aux>pro) pro=aux;
			}

			//p_left_down
			if(j-3>=0 and i+3<20){
				int aux = matriz[i][j]*matriz[i+1][j-1]*matriz[i+2][j-2]*matriz[i+3][j-3];
				if(aux>pro) pro=aux;

			}


		}
	}
	return pro;
}

int main(){

	for(int i=0;i<20;i++){
		for(int j=0;j<20;j++){
			cin >> matriz[i][j];
		}
	}

	cout << Product() << "\n";


	return 0;
}