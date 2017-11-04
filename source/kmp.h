#include <iostream>
#include <string>
#include <vector>

#define DEBUG

/*
*@bref Get the 'next' array used in KMP algirothm
*@param [in] s - String need to get next array
*@param [in] next - Next array
*/
void GetNext(std::string s, std::vector<int> &next);


int KMPSearch(std::string s, std::string t);
