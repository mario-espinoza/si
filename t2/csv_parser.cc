#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream  data("datos.csv");

    std::string line;
    while(std::getline(data,line))
    {
        std::stringstream  lineStream(line);
        std::string        cell;
        while(std::getline(lineStream,cell,','))
        {
            // You have a cell!!!!
        }
    }
 }

int crossValidation(int partitions, int fileSize)
{
	//TODO: Call svm_light and re
	//for(int

}

float getAccuracy()
{
	float acc=0;

	return acc;
};

float getAverageAccuracy()
{};

float getRecall()
{
	float acc=0;

	return acc;
};

float getPrecision()
{
	float acc=0;

	return acc;
};

float getFScore()
{
};

void getConfussionMatrix()
{
}


/*
Calcule la accuracy y la matriz de confusión. Además, la precisión, recall y F­Score de ambas clases por split. Entregue también los promedios de los diez splits. Comente acerca de los errores ¿Hay algún patrón? ¿Cómo podría mejorar? ¿Qué puede decir de los errores? ¿Hay alguna correlación entre el número de palabras de las respuestas y su tipo? ¿Existe alguna relación entre el tipo de la pregunta y la distribución de las clases de sus respuesta? Comente que observa por categoría (de primer nivel): ¿Hay categorías con una mayor tasa de error? Tome en cuenta sólo las categorías más frecuentes en su conjunto de datos.
*/
