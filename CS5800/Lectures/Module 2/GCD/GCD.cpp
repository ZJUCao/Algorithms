/**
 * @file    GCD.cpp
 * @brief   Euclidean algorithm for computing the greatest common divisor (GCD) of two integers a and b.
 *
 * The Euclidean algorithm is based on the principle that the GCD of two integers also divides their difference.
 * It repeatedly replaces the larger number by its remainder when divided by the smaller number,
 * until one of them becomes zero. The non-zero number is the GCD of the original two numbers.
 *
 * Time complexity: O(log min(a, b))
 *
 * @author  Troy
 * @date    2026-02-15
 */
#include <iostream>

using namespace std;

int main(void)
{
    int a, b;
    cin >> a >> b;

    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }

    cout << a << endl;

    return 0;
}