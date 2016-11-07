#include "tabulist.h"

tabulist::tabulist(int tabu_length)
{
    (this->list).resize(tabu_length);
    this->length = tabu_length;
    this->current_position = 0;
    for (int i=0; i<tabu_length; i++)
    {
        (this->list)[i] = "";
    } 
}

tabulist::~tabulist(){}

int tabulist::add(std::string tabu_mov)
{
    list[current_position] = tabu_mov;
    current_position = (current_position + 1) % length;
    return 1;
}

bool tabulist::in(std::string tabu_mov)
{
    for (int i=0; i<length; i++)
    {
        if (list[i] == tabu_mov) return true;
    }
    return false;
}

int tabulist::len() { return this->length; }