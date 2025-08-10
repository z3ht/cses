#include <iostream>
#include <cassert>
#include <vector>


/**
* CSES 1072 – Two Knights
*
* Problem: Count ways to place two identical knights on an n×n board so they don’t attack.
*
* Step 1: Total placements (no restrictions)
*  - N = n² squares
*  - Knights identical → choose 2 squares: C(N, 2) = N*(N-1)/2
*  - Pattern: derive combinations by starting from permutations N*(N-1) and dividing by 2! for identical pieces
*
* Step 2: Subtract attacking pairs
*  - Knights attack only in 2×3 or 3×2 rectangles
*  - Each rectangle has exactly 2 attacking pairs
*  - Count rectangles: (n-1)*(n-2) each way → attacks = 4*(n-1)*(n-2)
*  - Pattern: replace per-cell move checks with counting how often a local motif fits
*
* Step 3: Final formula
*  - result = C(n², 2) − 4*(n-1)*(n-2)
*
* Takeaways:
*  - Start from labeled permutations → divide by identical permutations to get combinations
*  - Recognize small repeating patterns to avoid per-square simulation
*/

int main() {
    int64_t t;
    std::cin >> t;

    for (int n = 1; n <= t; n++)
    {
        const int64_t m = n * n;
        const int64_t combos = (m * (m - 1)) / 2;

        int64_t checks = 0;
        if (n >= 3)
        {
            checks += ((n - 2) * (n - 1) * 2) + ((n-2) * (n-1) * 2);
        }
        const int64_t result = combos - checks;
        std::cout << "\n" << result;
    }
    std::cout << std::endl;
}