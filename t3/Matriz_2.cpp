#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector <int> v_salida;
vector <int> v_entrenamiento;

int matriz [2][2];


int main (){
	string linea;
	ifstream mi_salida("E10/Resultado.txt");
	ifstream mi_entrenamiento("E10/archivo10.txt");
	int numero;
	if(mi_salida.is_open()){
		while(getline(mi_salida,linea)){
			if(linea[0]=='-'){
				v_salida.push_back(-1);
				//cout << "ingreso negativo" << endl;
			}else{
				v_salida.push_back(1);
				//cout << "ingreso positivo" << endl;
				
			}
		}
	}else {
		cout << "no se abrio" << endl;
	}
	
	if(mi_entrenamiento.is_open()){
		while(getline(mi_entrenamiento,linea)){
			if(linea[0]=='-'){
				v_entrenamiento.push_back(-1);
			}
			else{
				v_entrenamiento.push_back(1);
			}

		}
	}else{
		cout << "no se abrio" << endl;
	}

	cout << v_entrenamiento.size() << " " << v_salida.size() << endl;
	matriz[0][0]=0;
	matriz[0][1]=0;
	matriz[1][0]=0;
	matriz[1][1]=0;
	//cout << "hola" << endl;
	vector <int>:: iterator It_Salida=v_salida.begin();
	vector <int>:: iterator It_Entrenamiento=v_entrenamiento.begin();

	for (int i=0;i<v_salida.size();i++){
		
		//cout << "Entrenamiento: "<< *It_Entrenamiento << " Salida: " << *It_Salida << endl;

		if(*It_Entrenamiento==*It_Salida){
			if(*It_Entrenamiento>0){
				matriz[0][0]+=1;
			}else{
				matriz[0][1]+=1;

			}
		}else{
			if(*It_Salida>0){
				matriz[1][0]+=1;

			}else{
				matriz[1][1]+=1;
			}

		}


		It_Entrenamiento++;
		It_Salida++;
		//cout << "chao" << endl;
	}
	string archivo_salida="E10/Matriz10.txt";
	ofstream as(archivo_salida);
	for(int i=0; i< 2;i++){
		for (int  j= 0; j < 2; j++)
		{	
			cout << matriz[i][j] << "\t";
			as << matriz[i][j] << "\t";
			/* code */
		}
		cout << endl;
		as << endl;
	}
	float matriz01=matriz[0][1];
	float matriz00=matriz[0][0];
	float matriz10=matriz[1][0];
	float matriz11=matriz[1][1];
	float tamano=v_salida.size();

	float Preccision=(matriz00)/(matriz00+matriz10)*100;
	float Recall=(matriz00)/(matriz00+matriz11)*100;
	float FScore=(2*Preccision*Recall)/(Preccision+Recall);

	
	
	//cout << (matriz00)/(matriz00+matriz10)*100 << endl;
	as << "Accuracy: " << ((matriz00+matriz01)/tamano)*100<< "%"  << ", Correctas: " << (matriz[0][1]+matriz[0][0]) << ", Incorrectas: " << (matriz[1][1]+matriz[1][0]) << ", total:" << v_salida.size() << endl;
	as << "Preccision: " << Preccision << "%" << endl;
	as << "Recall: " << Recall<< "%"  << endl;
	as << "F-Score: " << FScore<< "%"  << endl;

	return 0;
	
}



