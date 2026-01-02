#include<iostream>
#include<vector>
using namespace std;

void componentes(string operacion, vector<char>& numerosVector, vector<char>& signosVector, vector<char>& otrosVector){
	string volatilNums = "0123456789", volatilSingos = "+-*/%";
	for(size_t i=0;i<operacion.length();i++){
		if(volatilNums.find(operacion[i]) != string::npos){ //por que existe eso del npos :c
			numerosVector.push_back(operacion[i]);
		}else if(volatilSingos.find(operacion[i]) != string::npos){
			signosVector.push_back(operacion[i]);
		}else{
			otrosVector.push_back(operacion[i]);
		}
	}
	cout<<"numeros: \n";
	for(size_t i=0;i<numerosVector.size();i++){
		cout<<numerosVector[i]<<"\n";
	}
	cout<<"signos: \n";
	for(size_t i=0;i<signosVector.size();i++){
		cout<<signosVector[i]<<"\n";
	}
	cout<<"otros: \n";
	for(size_t i=0;i<otrosVector.size();i++){
		cout<<otrosVector[i]<<"\n";
	}
}

int main(){
	vector<char> numerosVector, signosVector, otrosVector;
	string operacion;
	getline(cin,operacion);
	componentes(operacion, numerosVector, signosVector, otrosVector);
    return 69;
}
