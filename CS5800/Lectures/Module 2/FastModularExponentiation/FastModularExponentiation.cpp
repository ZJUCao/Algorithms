/**
 * @file    FastModularExponentiation.cpp
 * @brief   Fast modular exponentiation for computing a^b mod m.
 *
 * Fast modular exponentiation is an algorithm for computing a^b mod m.
 * It works by repeatedly squaring the base and reducing the exponent by half.
 *
 * Time complexity: O(log b)
 *
 * @author  Troy
 * @date    2026-02-15
 */
#include <iostream>

using namespace std;

/**
 * @brief   Fast modular exponentiation for computing a^b mod m.
 *
 * @param[in]   a   The base.
 * @param[in]   b   The exponent.
 * @param[in]   m   The modulus.
 * @return  The result of a^b mod m.
 */
int ModExp(int a, int b, int m)
{
    if (b == 0)
    {
        return 1;
    }

    int modExp = ModExp(a, b / 2, m);
    if (b % 2 == 0)
    {
        return (modExp * modExp) % m;
    }

    return (a * modExp * modExp) % m;
}

int main(void)
{
    int a, b, m;
    cin >> a >> b >> m;

    int result = ModExp(a, b, m);
    cout << result << endl;

    return 0;
}
