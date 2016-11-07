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


#define MAXITERATIONS 100

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
	solution best_solution = current_solution, candidate_solution = current_solution;
	
	cout << "Solución obtenida mediante greedy (" << current_solution.get_quality() << ") :" << endl;
	current_solution.print_solution();
	cout << "--------------------------------------------------------------" << endl;
	

	tabulist lista_tabu(instancia.get_n()*20);

	string lastSwap, bestSwap;
	int lastSwapCount, minSwap;
	solution::move bestMov;

	for (int iteration = 0; iteration < MAXITERATIONS; iteration++)
	{
		minSwap = 100000;
		for (int i=0; i<instancia.get_w(); i++)
		{
			for (int j=0; j<instancia.get_n()-1; j++)
			{
				for (int k=j+1; k<instancia.get_n(); k++)
				{
					lastSwapCount = current_solution.eval_swap(i,j,k);
					if (lastSwapCount < minSwap)
					{
						lastSwap = utility::moveToString(i,j,k);
						if (!lista_tabu.in(lastSwap))
						{
							minSwap = lastSwapCount;
							bestMov.set(i,j,k);
							bestSwap = lastSwap;
						}
					}  
				}
			}
			
		}
		cout << minSwap << endl;
		//cout << bestMov.i << "\t" << bestMov.j << "\t" << bestMov.k << endl;
		current_solution = current_solution.swap(bestMov.i,bestMov.j,bestMov.k);
		lista_tabu.add(bestSwap);
		if (current_solution < best_solution)
		{
			best_solution = current_solution;
		}
	}
		
			
/*
	for (int iteration = 0; iteration < MAXITERATIONS; iteration++)
	{
		/*for encargado de generar el neighbour
		for (int i=0; i<instancia.get_w(); i++)
		{
			for (int j=0; j<instancia.get_n(); j++)
			{
				for (int k=j; k<instancia.get_n(); k++)
				{
					if (j != k)
					{
						lastSwapCount = current_solution.eval_swap(i,j,k);
						if (lastSwapCount < candidate_solution.get_quality() )
						{
							lastSwap = utility::moveToString(i,j,k);
							if (!lista_tabu.in(lastSwap) || lastSwapCount < best_solution.get_quality() )
							{
								candidate_solution = current_solution.swap(i,j,k);
								bestSwap = lastSwap;
							} 
						} 
					}
				}
			}			
		}

		current_solution = candidate_solution;
		lista_tabu.add(bestSwap);
		if (current_solution < best_solution)
		{
			best_solution = current_solution;
		}
	}*/
	
	cout << "Solución current (" << current_solution.get_quality() << ") :" << endl;
	current_solution.print_solution();
	cout << "Solución best (" << current_solution.get_quality() << ") :" << endl;
	best_solution.print_solution();
	cout << "--------------------------------------------------------------" << endl;

	return 0;
}