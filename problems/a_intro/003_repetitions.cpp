#include <iostream>
#include <vector>
#include <cassert>

int main()
{
    size_t max = 0;
    size_t cur = 0;
    char prev = ' ';

    std::string v;
    std::cin >> v;
    for (size_t i = 0; i < v.size(); i++)
    {
        if (v.at(i) == prev) cur += 1;
        else
        {
            max = std::max(max, cur);
            cur = 1;
            prev = v.at(i);
        }
    }
    if (cur != 0)
    {
        max = std::max(cur, max);
    }

    std::cout << max << std::endl;

    return 0;
}