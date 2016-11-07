#ifndef TABULIST_H_
#define TABULIST_H_
 
#include <string>
#include <vector>

class tabulist
{
    private:
        std::vector<std::string> list;
        int length, current_position;

    public:
        tabulist(int tabu_length);
        ~tabulist();
        
        int add(std::string tabu_mov);
        bool in(std::string tabu_mov);
        int len();
};

#endif
