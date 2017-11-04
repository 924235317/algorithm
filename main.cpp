#include <iostream>
#include <string>
#include <vector>
#include "source/util.hpp"
#include "source/kmp.h"

using namespace std;

int main()
{
    std::string in_string1 = "aaaaaaaaaaaaabaaaaaaaaaaaax";
    std::string in_string2 = "aaaax";
    std::vector<int> next;
    GetNext(in_string2, next);

    //PrintSpaces(10);
    //std::cout << "a" << std::endl;
    int i = KMPSearch(in_string1, in_string2);
    std::cout << i << std::endl;
    return 0;
}
