#include <iostream>
#include <vector>
#include <cassert>


/**
* CSES 1092 – Two Sets
*
* Core insight: Pair ends to form constant-sum “chunks”, then use parity (of chunk count and leftover) to decide
* feasibility and construct sets.
*
* Overall takeaways:
*  - Observe symmetry in the problem to expose a simpler underlying structure.
*  - Split the problem into parts whose relationships can be reasoned about independently.
*  - Reduce complex parts to simpler, already-solved parts by transforming them or reusing known results.
*  - Encode the relationships (truth table, formula, etc.) and implement
*
* Step 1: Spot the summation structure
*  - Total = 1 + 2 + … + n
*  - Pair ends: (1,n), (2,n-1), (3,n-2), … → each pair sums to (n+1)
*  - Work only with whole “chunks” (never split a number).
*
* Step 2: Generalize
*  - n=7 → (1+7),(2+6),(3+5) + leftover 4 → solvable if I can place the 4
*  - n=6 → (1+6),(2+5),(3+4) → 3 chunks (odd), no leftover → feels impossible
*  - Emerging rule: let #chunks = floor(n/2). Even → can split evenly. Odd → need a leftover to “fix” parity
*
* Step 3: prove odd chunks case
*  - Odd #chunks with no leftover forces one side to take an extra chunk → totals differ → impossible.
*
* Step 4: unify odd number case with odd chunks
*  1) Peel: S(n) = 1 + n-1 + S(n−1)
*  2) Inspect S(n−1): it pairs into floor((n−1)/2) chunks (each sums to n)
*  3) If that chunk count is odd, observe near middle is (z-1),(z). So 1 can be added to (z-1) to equal z
*  4) Result: after splitting up middle, if an even number of whole chunks remain → alternate pairs to finish
*
* Step 5: Name the parities and compute
*  - is_even_num = (n % 2 == 0)            // leftover exists only when false
*  - #chunks
*      • n even  → #chunks = n/2 → even iff n % 4 == 0
*      • n odd   → #chunks = (n−1)/2 → even iff (n+1)/2 is even
*  - Condense to:
*      is_even_sum = ((n + 1 + is_even_num) % 4 == 0)
*
* Step 6: Truth table (two bits → feasibility)
*             is_even_sum
*                     0                1
* is_even_num +----------------+----------------+
*     0       | YES (odd+odd)  | NO             |
*             | see step 4     |                |
*             +----------------+----------------+
*     1       | NO             | YES            |
*             +----------------+----------------+
*
* Observe xor pattern: is_legal = is_even_num ^ is_even_sum
*
*/


int main()
{
    int64_t num;
    std::cin >> num;

    const bool is_even_num = num % 2 == 0;
    const bool is_even_sum = (num + 1 + is_even_num) % 4 == 0;

    const bool is_legal = is_even_num ^ is_even_sum;
    std::cout << (is_legal ? "YES" : "NO") << std::endl;

    if (is_legal)
    {
        if (is_even_num)
        {
            std::cout << (num / 2) << std::endl;
            bool is_first = true;
            for (int i = 0; i < num / 2; i += 2)
            {
                if (is_first) is_first = false;
                else std::cout << " ";

                std::cout << (i + 1) << " " << (num - i);
            }
            std::cout << std::endl;

            std::cout << (num / 2) << std::endl;
            is_first = true;
            for (int i = 1; i < num / 2; i += 2)
            {
                if (is_first) is_first = false;
                else std::cout << " ";

                std::cout << (i + 1) << " " << (num - i);
            }
            std::cout << std::endl;
        }
        else
        {
            // add 1 for odd part
            std::cout << 1 + (num / 2) << std::endl;
            std::cout << 1 << " " << (num / 2) + 1;
            for(int i = 1; i < num / 2; i += 2)
            {
                std::cout << " " << (i + 1) << " " << (num - i + 1);
            }
            std::cout << std::endl;

            std::cout << (num / 2) << std::endl;
            std::cout << (num / 2) + 2;
            for(int i = 2; i < num / 2; i += 2)
            {
                std::cout << " " << (i + 1) << " " << (num - i + 1);
            }
            std::cout << std::endl;
        }
    }

    return 0;
}