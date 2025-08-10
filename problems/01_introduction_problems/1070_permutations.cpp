#include <iostream>
#include <cassert>
#include <vector>

/**
 * Problem: Arrange numbers 1 to n such that no adjacent pair differs by 1
 *
 *  Core principle: Transform n connection decisions into:
 *  1) Find groupings where each group contains either:
 *    - no disallowed edges
 *    - only allowed edges
 *  2) Minimize BETWEEN-group connections (ideally to 1)
 *  3) Prove those few connections are safe
 *  4) Resolve the edge cases where they're not
 *
 * Step 1: Model as a graph problem
 *  - Nodes: numbers 1 to n
 *  - Forbidden edges: 1-2, 2-3, 3-4, ..., (n-1)-n
 *  - This forms one long chain: 1 - 2 - 3 - ... - n
 *
 * Step 2: Mental graph manipulation - what groupings avoid forbidden edges?
 *  - Try random groupings → too messy, too many cross-group edges to verify
 *  - Try sequential chunks [1,2], [3,4], ... → doesn't work, forbidden edges within chunks
 *  - Try by parity [evens], [odds] → interesting! All forbidden edges go BETWEEN groups
 *    (1-2 crosses, 2-3 crosses, 3-4 crosses, ...)
 *
 *  RED FLAGS that a partition is too complex:
 *   - Can't describe it in one sentence ("first element, then every other..." = bad)
 *   - Need arithmetic gymnastics to generate it (i+1, i+3, v-i*2, etc.)
 *   - Can't prove it's elements are safe together
 *   - Too many small partitions that will later need to be chained together
 *
 *  Verify partitions are internally safe, THEN decide ordering
 *
 * Step 3: Minimize and verify the join points
 *  - Need exactly ONE connection between chains (to form a single permutation)
 *  - Where to connect? Try the ends: [2,4,6,...,last_even] → [1,3,5,...,last_odd]
 *  - Critical check: is |last_even - 1 (first_odd)| ≠ 1?
 *    - For n≥4, this gap is always safe (worst case n=4: |4-1|=3)
 *
 *  AVOID: Interleaving or clever arrangements (each = more connections to verify)
 *  SIMPLEST: Just concatenate complete partitions with one bridge
 *
 * Step 4: Edge cases fall out from the join verification
 *  - n=1: single node, no edges needed
 *  - n=2,3: no solution
 *  - n≥4: general case
 */

int main() {
    int64_t v;
    std::cin >> v;

    if (v == 1)
    {
        std::cout << 1 << std::endl;
        return 0;
    }
    if (v == 2 || v == 3)
    {
        std::cout << "NO SOLUTION" << std::endl;
        return 0;
    }
    else
    {
        std::cout << 2;
        for (int i = 4; i <= v; i += 2)
        {
            std::cout << " " << i;
        }
        for (int i = 1; i <= v; i += 2)
        {
            std::cout << " " << i;
        }
        std::cout << std::endl;

        return 0;
    }
}