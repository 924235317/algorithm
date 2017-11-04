#include "kmp.h"
#include "util.hpp"

void GetNext(std::string s, std::vector<int> &next)
{
    int k = -1;
    int j = 0;
    std::size_t len = s.length();

    next.push_back(-1);

    while (j < len - 1)
    {
        if (k == -1 || s.at(k) == s.at(j))
        {
            ++k;
            ++j;
            next.push_back(k);
        }
        else
            k = next.at(k);
    }
}

void GetNextVal(std::string s, std::vector<int> &next)
{
    int k = -1;
    int j = 0;
    std::size_t len = s.length();
    next.resize(len);
    next.at(0)= -1;

    while (j < len - 1)
    {
        if (k == -1 || s.at(k) == s.at(j))
        {
            ++k;
            ++j;
            if  (s.at(k) != s.at(j))
                next.at(j) = k;
            else
                next.at(j) = next.at(k);
        }
        else
            k = next.at(k);
    }
}

void PrintNext(std::vector<int> next)
{
    std::cout << "Next array: ";
    for(std::size_t i = 0; i < next.size(); i++)
    {
        std::cout << next.at(i) << " ";
    }
    std::cout << std::endl;
}


int KMPSearch(std::string s, std::string t)
{
    int idx_s = 0;
    int idx_t = 0;

    int len_s = int(s.length());
    int len_t = int(t.length());

    std::vector<int> next;
    GetNextVal(t, next);
#ifdef DEBUG
    PrintNext(next);
#endif
    while(idx_s < len_s && idx_t < len_t)
    {
        if(len_t - idx_t > len_s - idx_s)
            return -1;
        if(idx_t == -1 || s.at(idx_s) == t.at(idx_t))
        {
            idx_s++;
            idx_t++;
        }
        else
            idx_t = next.at(idx_t);

#ifdef DEBUG
        std::cout << "---------------------------------------" << std::endl;
        std::cout << "idx_s: " << idx_s << " idx_t: " << idx_t << std::endl;
        PrintSpaces(idx_s);
        std::cout << "|" << std::endl;
        std::cout << s << std::endl;
        PrintSpaces(idx_s - idx_t);
        std::cout << t << std::endl;
#endif // DEBUG
    }
    return ((idx_t == len_t)? idx_s - len_t : -1);
}
