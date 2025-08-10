#include <iostream>
#include <cassert>
#include <vector>


/**
* CSES 1071 - Number Spiral
*
* Core insight: Transform 2D spiral navigation into diagonal + offset calculation
*
* Step 1: Recognize the symmetry
*  - Spiral has perfect symmetry along main diagonal (i == j)
*  - Any position (i,j) can be calculated from its diagonal anchor
*  - Key: n = max(i,j) determines which "layer" we're in
*
* Step 2: Find the diagonal formula (the anchor)
*  - Diagonal values hide a summation pattern:
*    diag(n) = T(n) + T(n-2) where T(k) = k*(k+1)/2
*  - This gives us diag(n) = n*(n+1)/2 + (n-2)*(n-1)/2
*  - No simulation needed - jump straight to diagonal value
*
* Step 3: Calculate offset and direction
*  - Offset = |i - j| (distance from diagonal)
*  - Direction depends on two binary conditions:
*    1) Layer parity: n % 2
*    2) Position: i > j
*
*  Build truth table:
*                n%2==0 | n%2==1
*    i > j:        -    |   +
*    i <= j:       +    |   -
*
*  PATTERN RECOGNITION: Alternating signs in 2x2 table = XOR!
*  Rule: Add if (n%2 == 0) XOR (i > j), subtract otherwise
*
* Takeaways:
*  - Saved myself from simulating the whole spiral by finding the diagonal pattern
*  - When you have 2 binary conditions affecting sign → build truth table → check for XOR
*  - That summation formula was hiding in plain sight once I wrote out the diagonal values
*/

int main() {
    int64_t trials;
    std::cin >> trials;
    for (int c = 0; c < trials; c++)
    {
        int64_t i, j;
        std::cin >> j; // row
        std::cin >> i; // col

        const int64_t max = std::max(i, j);
        if (max == 1)
        {
            std::cout << 1 << std::endl;
        }
        else
        {
            const int64_t diag = ((max * (max + 1)) / 2) + (((max - 2) * ((max - 2) + 1)) / 2);
            const int64_t offset = std::abs(i - j);
            const int64_t mult = ((std::max(i, j) % 2 == 0) ^ (i > j)) ? 1 : -1;
            std::cout << diag + (offset * mult) << std::endl;
        }
    }
}