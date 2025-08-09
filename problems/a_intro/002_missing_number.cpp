#include <iostream>
#include <vector>
#include <cassert>

/**
 *
 * 1 + 2 + 3 + 4
 *
 * S = n + (n - 1) + .. + 1 = 1 + 2 + ... + n
 * 2S = (n + 1) + ((n - 1) + 2 = n + 1) + ... + (n + 1)
 * S = (n * (n + 1)) / 2
 *
 */

int main()
{
    size_t n;
    std::cin >> n;
    size_t total = (n * (n + 1)) / 2;

    size_t sum = 0;
    size_t cur;
    for (size_t i = 0; i < n - 1; i++)
    {
        std::cin >> cur;
        sum += cur;
    }

    std::cout << total - sum << std::endl;

    return 0;
}