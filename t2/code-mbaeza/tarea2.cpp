#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <regex>
using namespace std;

map <string, int> mapa;	
map <string,int> mapa2;
map <string,int>::iterator iterMap;

	
set <string> sete;
set <string>::iterator It_Set;
int matriz[10000][1000];
int main (){
	const regex patron("([a-zA-Z]+)");

	string linea;
	int cont=0;
	string palabra;
	ifstream mi_archivo ("Final.csv");
	size_t palabra_encontrada1;//correos
	size_t palabra_encontrada2;//paginas
	size_t palabra_encontrada3;// "
	
	if(mi_archivo.is_open()){

		while(getline (mi_archivo,linea)){
			
			//istringstream iss(linea);
			stringstream variable(linea);
			string palabra;
			

				while(getline(variable, palabra, ' ')){

					palabra_encontrada1=palabra.find("@");
					palabra_encontrada2=palabra.find("www");
					palabra_encontrada3=palabra.find("com");
					if (palabra_encontrada1!=string::npos || palabra_encontrada2!=string::npos || 
						palabra_encontrada3!=string::npos)
					{	
						continue;
						/* code */
					}
					if(palabra=="True" || palabra=="False"){
						continue;
					}else{
						//PARA ELIMINAR ";"
						/*if(palabra_encontrada3!=string::npos){

							palabra=palabra.substr(1,palabra.size()-1);
							transform(palabra.begin(),palabra.end(),palabra.begin(),::tolower);
							//cout << palabra << endl;
							sete.insert(palabra);
							continue;
						}*/
						if(palabra[0]==';' || palabra[0]=='~'){

							if(regex_match(palabra,patron)){

								palabra=palabra.substr(1,palabra.size()-1);
								transform(palabra.begin(),palabra.end(),palabra.begin(),::tolower);
								//cout << palabra << endl;
								sete.insert(palabra);
							}else{
								continue;
							}
							
						}else{
							//PARA no ingresar palabras// 
							if(palabra.size()==1 || palabra.size()>20 || palabra=="\n"){
								continue;
							}else{
								if(regex_match(palabra,patron)){

									transform(palabra.begin(),palabra.end(),palabra.begin(),::tolower);		
									sete.insert(palabra);
								}else{
									continue;
								}
								
							}
														
						}
						
					}
					
				}
			
			cont++;
		}


		mi_archivo.close();
		
	}else
		cout << "No se abrio el archivo" << endl;

	cout << sete.size() << endl;
	cout << cont << endl;
	It_Set=sete.begin();
	for(int i=0; i< sete.size();i++){
		mapa[*It_Set]=i;
		It_Set++;

	}	
/*	
	for(auto x:mapa){
		cout << x.first << ": " << x.second << " " << endl; 
	}
	cout << "hola" << endl;
*/

	/*

		//llenar matriz de 0...	

	*/
	


	for(int i=0;i<cont;i++){
		for(int j=0;j<sete.size()+1;j++){
			matriz[i][j]=0;
		}
	}

	cout << "hola" << endl;

	//guardar en la matriz...


	ifstream mi_archivo2 ("Final.csv");
	int VF;
	int cont2=0;
	if(mi_archivo2.is_open()){

		while(getline (mi_archivo2,linea)){
			
			//istringstream iss(linea);
			stringstream variable(linea);
			string palabra;
			

				while(getline(variable, palabra, ' ')){

					palabra_encontrada1=palabra.find("@");
					palabra_encontrada2=palabra.find("www");
					palabra_encontrada3=palabra.find("com");
					if (palabra_encontrada1!=string::npos || palabra_encontrada2!=string::npos || 
						palabra_encontrada3!=string::npos)
					{	
						continue;
						/* code */
					}

					if(palabra=="True" || palabra=="False"){
						if(palabra=="True"){
						 VF=1;
						}else{
							VF=-1;
						}
						continue;
					}else{
						//PARA ELIMINAR ";"
						/*if(palabra_encontrada3!=string::npos){
							
							palabra=palabra.substr(1,palabra.size()-1);
							transform(palabra.begin(),palabra.end(),palabra.begin(),::tolower);
							//cout << palabra << endl;
							sete.insert(palabra);
							continue;
						}*/
						if(palabra[0]==';' || palabra[0]=='~'){
							if(regex_match(palabra,patron)){
								palabra=palabra.substr(1,palabra.size()-1);
								transform(palabra.begin(),palabra.end(),palabra.begin(),::tolower);
								//cout << palabra << endl;
								mapa2[palabra]+=1;
							}else{
								continue;
							}
						

						}else{
							//PARA no ingresar palabras// 
							if(palabra.size()==1 || palabra.size()>20 || palabra=="\n"){
								continue;
							}else{
								if(regex_match(palabra,patron)){
									transform(palabra.begin(),palabra.end(),palabra.begin(),::tolower);		
									mapa2[palabra]+=1;
								}else{
									continue;
								}
								
							}
														
						}
						
					}
					
				}
				//llenar la matriz....
				for(auto x:mapa2){
					iterMap=mapa.find(x.first);
					matriz[cont2][iterMap->second]=x.second;
					matriz[cont2][sete.size()-1]=VF;
				}
				mapa2.clear();

			
			cont2++;
		}


		mi_archivo2.close();
		
	}else
		cout << "No se abrio el archivo" << endl;	
	/*
	for(int i=0; i< cont2;i++){
		for(int j=0; j< sete.size();j++){
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}*/

	string nom_ar="archivo";

/*
	for(int i=0;i<cont;i++){	

		if((i)%10==0){
			nom_ar="archivo";
			nom_ar=nom_ar+to_string((i/10)+1);
			nom_ar=nom_ar+".txt";
		}
		
		ofstream archi(nom_ar);
		
		int k=0;
		if(i+10<cont){

		for(k=i;k<i+10;k++){
			
			if(matriz[k][sete.size()-1]>0){
				archi << "+" << 1 << " ";		
			}else{
				archi << "-" << 1 << " ";
			}
			for(int j=0;j<sete.size()-1;j++){
				if(matriz[k][j]>0){
					archi << j << ":" << matriz[k][j] << " ";
					
				}			
			}
			archi << "#algo" << endl;
		}
		}else{
			for(k=i;k<cont;k++){
				if(matriz[k][sete.size()-1]>0){
				archi << "+" << 1 << " ";		
			}else{
				archi << "-" << 1 << " ";
			}
				for(int j=0;j<sete.size()-1;j++){
					if(matriz[k][j]>0){
						archi << j << ":" << matriz[k][j] << " ";
					
				}			
			}
			archi << "#algo" << endl;
			}
			break;

		}
		if(i+9<cont){
			i+=9;
		}
		
	
	}*/
	int algo=0;
	int hasta=cont2/10;
	for(int i=0;i<10;i++){
	
		nom_ar="archivo";
		nom_ar=nom_ar+to_string(i+1);
		nom_ar=nom_ar+".txt";	
		
		ofstream archi(nom_ar);
		algo=(cont2/10)*i;
		cout << "algo: " << algo << endl;
		cout << "hasta: " << hasta << endl;

		for (int k=algo;k<hasta;k++){
			archi << k << ") ";	

			if(matriz[k][sete.size()-1]>0){
				archi << "+" << 1 << " ";		
			}else{
				archi << "-" << 1 << " ";
			}

			for(int j=0;j<sete.size()-1;j++){
					if(matriz[k][j]>0){
						archi << j << ":" << matriz[k][j] << " ";
					
				}

			}
			archi << "#algo" << endl;
		}
		if(cont2-hasta<cont2/10){
			for(int k=hasta;k<cont2;k++){
				archi << k << ") ";	

			if(matriz[k][sete.size()-1]>0){
				archi << "+" << 1 << " ";		
			}else{
				archi << "-" << 1 << " ";
			}

			for(int j=0;j<sete.size()-1;j++){
					if(matriz[k][j]>0){
						archi << j << ":" << matriz[k][j] << " ";
					
				}

			}
			archi << "#algo" << endl;
			}

		}
		hasta+=cont2/10;


	}


	return 0;
}





