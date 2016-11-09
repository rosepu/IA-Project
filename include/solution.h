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

	public:
		solution();
		solution(instance &ins);

		/* Metodos de la clase */
		void greedy(int seed);
		solution& swap(int i, int j, int k);
		solution& swapBlock(int i, int j, int k, int len);
		void print_solution();
		int calculate_fitness();
		
		/* funciones get */
		int get_quality();

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
};


#endif
