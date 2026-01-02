#include <iostream>
using namespace std;

int conteo(){
	int contadorVolatil=0;
	string palabraVolatil;
	getline(cin, palabraVolatil);
	for(size_t i=0;i<palabraVolatil.length();i++){
		if(palabraVolatil[i] == ' '){
			contadorVolatil++;
		}	
	}
	return contadorVolatil+1;
}

int main(){
	cout<<conteo();
    return 69;
}
