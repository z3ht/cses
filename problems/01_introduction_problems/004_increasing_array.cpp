#include <iostream>
#include <vector>
#include <cassert>

int main()
{
    size_t req = 0;
    int64_t prev = 0;

    size_t l;
    std::cin >> l;
    for (size_t i = 0; i < l; i++)
    {
        int64_t v;
        std::cin >> v;

        req += std::max(static_cast<int64_t>(0), prev - v);
        prev = std::max(prev, v);
    }

    std::cout << req << std::endl;

    return 0;
}