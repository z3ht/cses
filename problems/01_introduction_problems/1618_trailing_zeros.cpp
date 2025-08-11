#include <iostream>

#include <iostream>

/**
* Factorial Trailing Zeros
*
* Problem: Count trailing zeros in n! without actually calculating n!.
*
* Generalizations
*  - When direct multiplication overflows or is O(n), look for a factor-based shortcut.
*  - Translate “digit” properties into divisibility/factor counts.
*  - Prove which prime limits the count before ignoring others (here, 5s limit, not 2s).
*
* Step 1: Start from constraints (why we need a shortcut)
*  - n! overflows fast and computing it is O(n) → too slow for large n.
*  - We need a result computed from n alone in < o(n) time
*
* Step 2: What is a trailing zero?
*  - A trailing zero means “divisible by 10”
*  - 10 = 2 × 5, so each trailing zero comes from a (2,5) pair
*  - Once a trailing zero shows up, it won't go away
*     * prime factors are additive
*     * multiplication by whole numbers doesn't change zero-d decimals. Similar concept here.
*
* Step 3: Think in factors, not digits
*  - Multiplication pools prime factors; factors never disappear → once a (2,5) forms, that zero “never goes away”
*  - Decimal digits/carries can look tricky, but factor counts are stable and carry-free to track.
*
* Step 4: Identify the bottleneck
*  - In n!, 2s are far more common than 5s (every even contributes 2s).
*  - Therefore zeros are limited by the number of 5s, not 2s.
*  - Proving this is hard, but its true. See below comment.
*
* Step 5: Count 5s
*  - Multiples of 5 contribute one 5 each
*  - Multiples of 25 contribute an extra, 125 another, etc.
*  - zeros = ⌊n/5⌋ + ⌊n/25⌋ + ⌊n/125⌋ + … (stop when the term becomes 0)
*/

/**
 * Proof that v2(n!) >= v5(n!) for all n >= 0:
 *
 * for 1, 2, 3, 4, 5 ... 10
 * its obvious there are more 2s than 5s
 *
 * so we need to be most worried about near prime numbers
 * (i.e. 25 which is divisible by 5 and 5, not 2. Also 50, 75, etc.)
 *
 * Fact: For any prime p, the exponent of p in n! is
 *   v_p(n!) = floor(n/p) + floor(n/p^2) + floor(n/p^3) + ...
 * This works because floor(n/p) counts numbers with at least one factor p,
 * floor(n/p^2) adds one more for numbers with a second p, and so on.
 *
 * For p = 2 and p = 5:
 *   For every k >= 1,  2^k <= 5^k  =>  floor(n / 2^k) >= floor(n / 5^k)
 *
 * Summing over k:
 *   v_2(n!) = sum_{k>=1} floor(n / 2^k)
 *          >= sum_{k>=1} floor(n / 5^k) = v_5(n!)
 *
 * Strict inequality holds for n >= 2 since floor(n/2) > floor(n/5).
 *
 * This handles all cases automatically:
 *   - "Almost primes" and composites contribute the correct count of 2s/5s
 *     because they appear in multiple terms (e.g., 50 is counted in n/5 and n/25).
 *
 * Consequence: Trailing zeros in n! are min(v2, v5) = v5. Counting 5s is enough.
 */

int main() {
    long long n;
    std::cin >> n;

    long long z = 0;
    while (n) {
        n /= 5;
        z += n;
    }
    std::cout << z << '\n';
}


int main() {
    long long n;
    std::cin >> n;

    long long z = 0;
    while (n) {
        n /= 5;
        z += n;
    }
    std::cout << z << '\n';
}
