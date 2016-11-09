#ifndef SOLUTION_H_
#define SOLUTION_H_
 
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include "instance.h"

class solution
{
	private:
		instance instancia;
		int quality;
		bool init;
		std::vector< std::vector<char> > matrix;  //[Week][Colum]

		std::string matrixToString();
		int eval_String(std::string cadena);
		


	public:
		solution();
		solution(instance &ins);

		/* Metodos de la clase */
		void set_instance(instance* ins);
		void greedy(int seed);
		solution& swap(int i, int j, int k);
		solution& swapBlock(int i, int j, int k, int len);
		int eval_swap(int i, int j, int k);
		void get_best_neighbour();
		void print_solution();
		int calculate_fitness();
		

		/* funciones get */
		int get_quality();

		//TODO: funcion para obtener el workload

		/* Sobre escritura de operadores */
		solution& operator=(const solution& sol)
		{
			this->instancia = sol.instancia;
			this->quality = sol.quality;
			this->matrix = sol.matrix;
			this->init = sol.init;
			return *this;
		}


		bool operator <(const solution& right)
		{
			return this->quality < right.quality;
		}
		bool operator >(const solution& right)
		{
			return this->quality > right.quality;
		}
		//TODO: sobre escribir los operadores == > <
	
		/* nested class */
		class move
		{
			public:
				int i,j,k;
				move();
				move(int i, int j, int k);
				void set(int i, int j, int k);
		};
};


#endif
