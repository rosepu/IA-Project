#ifndef INSTANCE_H_
#define INSTANCE_H_

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include "utility.h"

class instance
{
	private:
		/* Valores de la instancia */
		bool init;
		int w,n,m, MAXW, MINW, NSLength2, NSLength3;
		std::vector<char> A;
		std::vector<int> MAXS, MINS;
		std::vector< std::vector<int> > R;
		std::vector< std::vector<int> > C2;
		std::vector< std::string > patterns;
		std::map<char, int> map_A;
		
		void set_patterns();

	public:
	
		instance();
		instance(std::string &archivo_instancia);
		
		/* congifura la instancia (por si tiene que cambiarse, mas que nada para el constructor instance() ) */
		void set_instance(std::string &archivo_instancia);
		

		/* funciones get (para evitar modificaciones) */
		int get_w();
		int get_n();
		int get_m();
		int get_MAXW();
		int get_MINW();
		int get_NSLength2();
		int get_NSLength3();
		std::vector<char> get_A();
		std::vector<int> get_MAXS(); 
		std::vector<int> get_MINS();
		std::vector< std::vector<int> > get_R();
		std::vector< std::vector<int> > get_C2();
		std::vector< std::string > get_pattersn();
		std::map<char, int> get_mapA();
};

#endif