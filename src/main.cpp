#include <iostream>
#include <stdlib.h> 
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include "utility.h"
#include "solution.h"
#include "instance.h"
#include "tabulist.h"


#define MAXITERATIONS 200000

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
	
	/* Instancia */
	instance instancia(archivo_instancia);

	solution current_solution(instancia);
	current_solution.greedy(seed); 
	solution best_solution = current_solution, candidate_solution = current_solution, best_candidate_silution  = current_solution;
	
	cout << "Solución obtenida mediante greedy (" << current_solution.get_quality() << ") :" << endl;
	current_solution.print_solution();
	cout << "--------------------------------------------------------------" << endl;
	current_solution.calculate_fitness();

	tabulist lista_tabu(instancia.get_n()*10);

	string lastSwap, bestSwap;
	int minSwap, iteration;

	for (iteration = 0; iteration < MAXITERATIONS; iteration++)
	{
		minSwap = 100000;
		for (int i=0; i<instancia.get_w(); i++)
		{
			for (int j=0; j<instancia.get_n()-1; j++)
			{
				for (int k=j+1; k<instancia.get_n(); k++)
				{
					candidate_solution = current_solution;
					candidate_solution = candidate_solution.swap(i,j,k);
					if (candidate_solution.get_quality() < minSwap)
					{	
						lastSwap = utility::moveToString(i,j,k);
						if (!lista_tabu.in(lastSwap) || minSwap < best_solution.get_quality() )
						{
							minSwap	= candidate_solution.get_quality();
							best_candidate_silution  = candidate_solution;
							bestSwap = lastSwap;
						}
					}
				}
			}
		}

		for (int l = 2; l <= 3; l++)
		{
			for (int i=0; i<instancia.get_w(); i++)
			{
				for (int j=0; j<instancia.get_n()-1; j++)
				{
					for (int k=j+1; k<instancia.get_n(); k++)
					{
						candidate_solution = current_solution;
						candidate_solution = candidate_solution.swapBlock(i,j,k,l);
						if (candidate_solution.get_quality() < minSwap)
						{	
							lastSwap = utility::moveToString(i,j,k);
							if (!lista_tabu.in(lastSwap) || minSwap < best_solution.get_quality() )
							{
								minSwap	= candidate_solution.get_quality();
								best_candidate_silution  = candidate_solution;
								bestSwap = lastSwap;
							}
						}
					}
				}
			}
		}

		lista_tabu.add(bestSwap);
		if (best_candidate_silution < best_solution)
		{
			best_solution = best_candidate_silution;
			if (best_solution.get_quality() == 0) break;
		}
		current_solution = best_candidate_silution;	
	}
	
	cout << "Solución current (" << current_solution.get_quality() << ") :" << endl;
	current_solution.print_solution();
	cout << "Solución best (" << best_solution.get_quality() << ") :" << endl;
	best_solution.print_solution();
	cout << "--------------------------------------------------------------" << endl ;
	cout << endl << "Solución fitnes (" << best_solution.calculate_fitness() << ")\t" << iteration << endl;


	return 0;
}