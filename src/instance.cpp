#include "instance.h"

instance::instance()
{
	init = false;
}

instance::instance(std::string &archivo_instancia)
{
	set_instance(archivo_instancia);
	init = true;
	set_patterns();
}	

void instance::set_instance(std::string &archivo_instancia)
{
	int aux = utility::readInstance(archivo_instancia, w, n, m, MAXW, MINW, NSLength2, NSLength3, A, MAXS, MINS, R, C2);
	if (aux == 1)
	{
		std::cerr << "\033[1;31mERROR: Formato de la instancia incorrecto.\033[0m" << std::endl;
		exit(1);
	} else if (aux == -1) {
		std::cerr << "\033[1;31mERROR: No se pudo abrir el archivo de la instancia.\033[0m" << std::endl;
		exit(1);
	}
}

void instance::set_patterns()
{
	if (!init) return;
	std::ostringstream os, os2;
	std::string freeC = std::string(1, A[m-1]);

	/* maximo de días trabajados consecutivos*/
	os << freeC << "[^" << freeC << "]{" << MAXW << "}[^" << freeC << "]+" << freeC; 
	patterns.push_back(os.str());
	
	os.str("");
	os.clear();

	/* minimo de días trabajados consecutivos*/
	os << freeC << "[^" << freeC << "]{1," << (MINW-1) << "}[^" << freeC << "]" << freeC;
	patterns.push_back(os.str());

	os.str("");
	os.clear();

	for (int i=0; i<m; i++)
	{
		/* máximo de días de un tipo consecutivos */
		os << A[i] << "{" << MAXS[i]+1 << ",}";
		patterns.push_back(os.str());

		/* mínimo de días de un tipo consecutivos */
		if (MINS[i]-1 != 0)
		{
			os2 << "[^" <<  A[i] << "]" << A[i] << "{1," << MINS[i]-1 << "}[^" <<  A[i] << "]";
			patterns.push_back(os2.str());
		}
		
		
		os.str("");
		os.clear();
		os2.str("");
		os2.clear();
	}

	/* secuencias de turno no permitidas */
	for (unsigned int i=0; i<C2.size(); i++)
	{
		patterns.push_back( std::string(C2[i].begin(), C2[i].end()) );
	}

}

int instance::get_w(){ return w; };

int instance::get_n(){ return n; };

int instance::get_m(){ return m; };

int instance::get_MAXW(){ return MAXW; };

int instance::get_MINW(){ return MINW; };

std::vector<char>  instance::get_A(){ return A; };

std::vector<int> instance::get_MAXS(){ return MAXS; };
 
std::vector<int> instance::get_MINS(){ return MINS; };

std::vector< std::vector<int> > instance::get_R(){ return R; };

std::vector< std::vector<char> > instance::get_C2(){ return C2; };

std::vector< std::string > instance::get_pattersn() { return patterns; }
