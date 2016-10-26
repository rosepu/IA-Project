#include <iostream>
#include <stdlib.h>

using namespace std;

/* Variables globales */
char* archivo_instancia;
int seed;


int main(int argc, char const *argv[])
{
	cout << "\n\n--------------------------------------------------------------" << endl;
	cout << "Problema:\t\tRotating Workforce Scheduling Problem" << endl;
	cout << "Heurísticas usadas:\tGreedy, Tabu Search" << endl;
	cout << "Autor:\t\t\tRodrigo Sepúlveda Garrido" << endl;
	cout << "--------------------------------------------------------------" << endl;

	if (argc <= 2)
	{
		cerr << "\033[1;31mERROR: Faltan parámetros\033[0m" << endl;
		return -1;
	}
	archivo_instancia = (char*)argv[1];
	seed = atoi(argv[2]);

	cout << archivo_instancia << endl;
	cout << seed << endl;


	return 0;
}