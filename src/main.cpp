#include <iostream>
#include <stdlib.h> 
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include "utility.h"

using namespace std;

/* Variables globales */
string archivo_instancia;
int seed;


int main(int argc, char const *argv[])
{
	cout << "\n\n--------------------------------------------------------------" << endl;
	cout << "Problema:\t\tRotating Workforce Scheduling Problem" << endl;
	cout << "Heurísticas usadas:\tGreedy, Tabu Search" << endl;
	cout << "Autor:\t\t\tRodrigo Sepúlveda Garrido" << endl;
	cout << "--------------------------------------------------------------" << endl;

	/* argumentos del programa */
	if (argc <= 2)
	{
		cerr << "\033[1;31mERROR: Faltan parámetros\033[0m" << endl;
		exit(1);
	}
	archivo_instancia = string("Instancias/") + string((char*)argv[1]);
	seed = atoi(argv[2]);
	
	/* Valores de la instancia */
	int w,n,m, MAXW, MINW, NSLength2, NSLength3;
    vector<char> A;
    vector<int> MAXS, MINS;
    vector< vector<int> > R;
    vector< vector<char> > C2;
	
	int aux = utility::readInstance(archivo_instancia, w, n, m, MAXW, MINW, NSLength2, NSLength3, A, MAXS, MINS, R, C2);
	if (aux == 1)
	{
		cerr << "\033[1;31mERROR: Formato de la instancia incorrecto.\033[0m" << endl;
		exit(1);
	} else if (aux == -1) {
		cerr << "\033[1;31mERROR: No se pudo abrir el archivo de la instancia.\033[0m" << endl;
		exit(1);
	}
	
	 


	return 0;
}