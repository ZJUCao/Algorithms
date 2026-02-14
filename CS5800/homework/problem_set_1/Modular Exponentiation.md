**Description**: Implement modular exponentiation in a way that outputs the intermediary steps of the algorithm.

Problem Statement: \***\*IMPORTANT\*\*** You are NOT allowed to use built in language functions which trivialize the task of computing exponents. Any submissions which use this and avoid the task at hand will be given a 0.

In this problem, you will have to efficiently implement modular exponentiation. Recall that the problem of modular-exponentiation is, given positive integers a and n, and a non-negative integer x, calculate ax mod n. One way of doing this is exponentiation by squaring. It involves repeatedly squaring the base a and reducing it mod n. Doing so yields the values a, $a^2$ mod n, $a^4$ mod n, $a^8$ mod n, ... etc. By combining these in the correct way, and using the fact that every number has a binary representation, we can compute $a^x$ mod n in time O(log x).

Implement modular-exponentiation by squaring, and output the intermediary values of $a^{2^i}$ mod n, as well as the final value $a^x$ mod n.

Note that in addition to the above, the challenge page also describes the input/output format, and
gives a few examples.

**Input Format**: The input will be exactly one line, with three space delimited integers a, x, and n.

**Constraints**: The integers will satisfy 2 ≤ a, x, n ≤ $2^{64}$.

**Output Format**: On the first line, output the d-bit binary representation of x.

On the next d lines, output the values:
$a^1$ mod n,
$a^2$ mod n,
$a^4$ mod n,
...
$a^{2^d}$ mod n,
On the last line, output $a^x$ mod n

**Sample Input**: 3 7 10

**Sample Output**: 111
3
9
1
7

**Explanation**: 7 in binary is written as 111.
31 = 3 mod 10
32 = 9 mod 10
34 = 81 = 1 mod 10
37 = 2187 = 7 mod 10
