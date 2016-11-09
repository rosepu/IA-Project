#ifndef UTILITY_H_
#define UTILITY_H_

#include <iostream>
#include <stdlib.h> 
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <vector>
#include <regex>

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

    std::string moveToString(int i, int j, int k);

    std::string moveToString(int i, int j, int k, int l);

    int distance(int wb_size, int min, int max);

    // int countMatchInRegex(std::string s, std::string re);
}

#endif