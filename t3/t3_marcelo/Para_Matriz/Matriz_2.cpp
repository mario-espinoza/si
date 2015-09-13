#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <stdio.h>
#include <sys/stat.h>
using namespace std;

vector <int> v_salida;
vector <int> v_entrenamiento;

int matriz [2][2];
	float Preccision_T=0.0;
	float Recall_T=0.0;
	float FScore_T=0.0;
	float Accuracy_T=0.0;
	int TotalCorrectas=0;
	int TotalIncorrectas=0;

int main (){
	ofstream curva_roc("MaxEntL1/Matrices/curva_roc.txt");
	for(int a=1;a<11;a++){
	string linea;
	string nombre_entrenamiento;
	string nombre_modelo;

	nombre_entrenamiento="MaxEntL1/archivo";
	nombre_entrenamiento+=to_string(a);
	nombre_entrenamiento+=".txt";

	nombre_modelo="MaxEntL1/output";
	nombre_modelo+=to_string(a);
	nombre_modelo+="_MaxEntL1.txt";



	ifstream mi_salida(nombre_modelo);
	ifstream mi_entrenamiento(nombre_entrenamiento);
	int numero;
	int basura1,basura2;
	long double positivo, negativo;
	if(mi_salida.is_open()){


		while(!mi_salida.eof()){

			mi_salida >> basura1;
			mi_salida >> basura1;
			mi_salida >> positivo;
			mi_salida >> basura1;
			mi_salida >> negativo;

			//cout << "positivo: " << positivo << "negativo:" << negativo << endl;
			if(negativo>positivo){
				v_salida.push_back(-1);
				//cout << "ingreso negativo" << endl;
			}else if (negativo<positivo){
				v_salida.push_back(1);
				//cout << "ingreso positivo" << endl;
				
			}
			negativo=0.0000000;
			positivo=0.0000000;
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
	
	string archivo_salida="MaxEntL1/Matrices/Matriz";
	archivo_salida+=to_string(a);
	archivo_salida+=".txt";

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
	v_salida.clear();
	v_entrenamiento.clear();


	Accuracy_T+=((matriz00+matriz01)/tamano);
	Preccision_T+=Preccision;
	FScore_T+=FScore;
	Recall_T+=Recall;
	TotalCorrectas+=matriz[0][1]+matriz[0][0];
	TotalIncorrectas+=matriz[1][1]+matriz[1][0];

	curva_roc <<  (matriz11/(matriz11+matriz01)) << " " << (matriz00/(matriz00+matriz10))  << endl;
}

	string resultado_promedio="MaxEntL1/Matrices/RP.txt";
	ofstream resul(resultado_promedio);
	resul << "Accuracy Promedio: " << Accuracy_T/10 << ", Correctas: " << TotalCorrectas << ", Incorrectas:" << TotalIncorrectas << endl;
	resul << "Preccision Promedio: " << Preccision_T/10 << endl;
	resul << "Recall Promedio: " << Recall_T/10 << endl;
	resul << "F-Score Promedio: " << FScore_T/10 << endl;  
	return 0;
	
}



