#include "solution.h"

/* Constructor por defecto */
solution::solution()
{
	this->init = false;
}

/* Construcor de la clase */
solution::solution(instance &ins)
{
	this->instancia = ins;
	matrix.resize( ins.get_n() );
	for (int i=0; i<ins.get_n(); i++)
	{
		(matrix[i]).resize( ins.get_w() );
	}
	this->init = true;
}

solution solution::swap(int i, int j, int k)
{
	if (!(this->init)) return *this;

	char aux = matrix[j][i];
	
	matrix[j][i] = matrix[k][i];
	
	matrix[k][i] = aux;

	
	this->quality = solution::eval_String( solution::matrixToString() );

	return *this;
}

void solution::greedy(int seed)
{
	if (!(this->init)) return;
	srand48(seed); //drand48 [0.0, 1.0]

	int col_count, aux;
	char auxChar;
	std::vector< std::vector<char> > requirements;
	requirements.resize( instancia.get_w() );


	for (int i=0; i<instancia.get_w(); i++)
	{
		col_count = 0;
		for (int j=0; j<instancia.get_m()-1; j++)
		{
			aux = (instancia.get_R())[j][i];
			col_count += aux; 
			auxChar = instancia.get_A()[j];
			for (int k=0; k<aux; k++)
			{
				requirements[i].push_back(auxChar);
			}
		}
		auxChar = instancia.get_A()[instancia.get_m()-1];
		for (int j=0; j<instancia.get_n()-col_count; j++)
		{
			requirements[i].push_back(auxChar);
		}
	}

	for (int i=0; i<instancia.get_w(); i++)
	{
		for (int j=0; j<instancia.get_n(); j++)
		{
			aux = (int) (requirements[i].size() * drand48 ());
			matrix[j][i] = requirements[i][aux];
			requirements[i].erase(requirements[i].begin() + aux);
		}
	}
	this->quality = solution::eval_String( solution::matrixToString() );

}

void solution::print_solution()
{
	if (!init) return;
	std::cout << "  ";
	for (int i=1; i<instancia.get_w()+1; i++) std::cout << i << " ";
	std::cout << std::endl;


	for (int i=0; i<instancia.get_n(); i++)
	{
		std::cout << i+1 << " ";
		for (int j=0; j<instancia.get_w(); j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	} 
}

std::string solution::matrixToString()
{
	std::string cadena;
	/* Trasforma la matrix a un string */
	for (int q=0; q<instancia.get_n(); q++) cadena += std::string(matrix[q].begin(), matrix[q].end());
	return cadena;
}

int solution::eval_String(std::string cadena)
{
	std::string subC1, subC2, subC3, subC4, subC5;
	int C_len = cadena.size();

	subC1 = cadena.back() + cadena[0];
	subC2 = cadena.substr(C_len-2, C_len) + cadena[0];
	subC3 = cadena.back() + cadena[0] + cadena[1];
	subC4 = cadena.substr(C_len-instancia.get_MAXW()-1, C_len) + cadena[0];
	subC5 = cadena.back() + cadena.substr(0, instancia.get_MAXW()+1);

	int match_count = 0;
	std::vector< std::string > pat = instancia.get_pattersn();
	for (unsigned int q=0; q<pat.size(); q++)
	{
		match_count += 1;//utility::countMatchInRegex(cadena, pat[q]);
		match_count += 1;//utility::countMatchInRegex(subC1, pat[q]);
		match_count += 1;//utility::countMatchInRegex(subC2, pat[q]);
		match_count += 1;//utility::countMatchInRegex(subC3, pat[q]);
		match_count += 1;//utility::countMatchInRegex(subC4, pat[q]);
		match_count += 1;//utility::countMatchInRegex(subC5, pat[q]);
	}
	return match_count;
}

int solution::eval_swap(int i, int j, int k)
{
	std::string cadena, cadenaOJ, cadenaOK, cadenaSK, cadenaSJ;
	int indexJ = j*instancia.get_w() + i;
	int indexK = k*instancia.get_w() + i;
	int maxw = instancia.get_MAXW();

	cadena = solution::matrixToString();

	if (indexJ < maxw*2) {
		cadenaOJ = (cadena + cadena).substr(cadena.size() + indexJ - maxw, 1+maxw*4);
	} else if (indexJ > (int) cadena.size() - maxw*2) {
		cadenaOJ = (cadena + cadena).substr(indexJ - maxw, 1+maxw*4);
	} else {
		cadenaOJ = cadena.substr(indexJ - maxw, 1+maxw*4);
	}

	if (indexK < maxw*2) {
		cadenaOK = (cadena + cadena).substr(cadena.size() + indexK - maxw, 1+maxw*4);
	} else if (indexK > (int) cadena.size() - maxw*2) {
		cadenaOK = (cadena + cadena).substr(indexK - maxw, 1+maxw*4);
	} else { 
		cadenaOK = cadena.substr(indexK - maxw, 1+maxw*4);
	}

	/* Realiza el swap en el string */
	cadenaSJ = cadenaOJ.substr(0, maxw) + cadenaOK[maxw] + (cadenaOJ.substr(maxw+1, maxw));
	cadenaSK = cadenaOK.substr(0, maxw) + cadenaOJ[maxw] + (cadenaOK.substr(maxw+1, maxw));

	/* Cuenta las restricciones */
	int match_countO = 0, match_countS=0;
	std::vector< std::string > pat = instancia.get_pattersn();
	
	for (unsigned int q=0; q<pat.size(); q++)
	{
		match_countO += 1;//utility::countMatchInRegex(cadenaOJ, pat[q]);
		match_countO += 1;//utility::countMatchInRegex(cadenaOK, pat[q]);
		match_countS += 1;//utility::countMatchInRegex(cadenaSJ, pat[q]);
		match_countS += 1;//utility::countMatchInRegex(cadenaSK, pat[q]);
	}

	return match_countS - match_countO;
}

int solution::calculate_fitness()
{
	/* Generar bloques */
	char lastChar, currentChar, dayOff = instancia.get_A()[ instancia.get_m() - 1 ];
	std::ostringstream os_wb, os_sb;

	std::vector<std::vector<std::string> > block;
	block.resize( instancia.get_m() +1 );
	int i, j;

	/* Busca un inicio de un bloque */
	lastChar = ' ';
	for (i=0; i<instancia.get_n(); i++)
	{
		for (j=0; j<instancia.get_w(); j++)
		{
			currentChar = matrix[i][j];
			if (lastChar == dayOff && currentChar != dayOff) {
				/* inicia un bloque */
				os_wb << currentChar;
				os_sb << currentChar;

				goto swbFound;
			} else {
				lastChar = currentChar;
			}
		}
	}

	swbFound:
	std::cout << i << "\t" << j << std::endl;

	
	for (i=i; i<instancia.get_n(); i++)
	{
		
		for (j=j; j<instancia.get_w(); j++)
		{
			currentChar = matrix[i][j];
			if (lastChar == currentChar)
			{
				os_sb << currentChar;
			} else {
				int poss = std::find(instancia.get_A().begin(), instancia.get_A().end(), lastChar) - instancia.get_A().begin();
				std::cout << poss << "\t" << lastChar << std::endl;
				std::cout << i << "\t" << j << std::endl;
			}
/*
			if (lastChar != dayOff && currentChar == dayOff ) {
				 
			} else if (lastChar == dayOff && currentChar != dayOff) {

			} else if ()
*/
		}
		std::cout << std::endl;
	} 
	


	/* Evaluar bloques */

	/* Cuenta las secuencias invalidas */
	return 0;
}

int solution::get_quality(){ return this->quality; }

solution::move::move(){}

solution::move::move(int i, int j, int k)
{
	this->i =  i;
	this->j = j;
	this->k = k;
}

void solution::move::set(int i, int j, int k)
{
	this->i =  i;
	this->j = j;
	this->k = k;
}