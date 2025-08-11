#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

int main()
{
    uint64_t v;
    std::cin >> v;
    uint64_t ans = 1;
    uint64_t modulo = static_cast<uint64_t>(std::pow(10, 9) + 7);
    for (uint64_t i = 0; i < v; i++)
    {
        ans *= 2;
        ans %= modulo;
    }
    std::cout << ans << std::endl;
    return 0;
}