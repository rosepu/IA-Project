#include <iostream>
#include <stdlib.h> 
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>

namespace utility
{
    int readInstance(
        std::string &name, 
        int &w, 
        int &n, 
        int &m, 
        int &MAXW, 
        int &MINW,
        int &NSLength2, 
        int &NSLength3,
        std::vector<char> &A,
        std::vector<int> &MAXS,
        std::vector<int> &MINS,
        std::vector< std::vector<int> > &R,
        std::vector< std::vector<char> > &C2        
    );
}