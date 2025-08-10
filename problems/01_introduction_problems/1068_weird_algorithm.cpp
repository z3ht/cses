#include <iostream>
#include <vector>
#include <cassert>


void solve(int64_t n)
{
    if (n == 1)
    {
        std::cout << std::endl;
        return;
    }

    if (n % 2 == 0)
    {
        n /= 2;
        std::cout << " " << n;
        solve(n);
    }
    else
    {
        n *= 3;
        n += 1;
        std::cout << " " << n;
        solve(n);
    }
}

int main()
{
    int64_t n;
    std::cin >> n;
    std::cout << n;
    solve(n);

    return 0;
}