/**
 * @file    Karatsuba.cpp
 * @brief   Karatsuba algorithm for computing the product of two integers.
 *
 * Karatsuba algorithm is a fast multiplication algorithm for computing the product of two integers.
 * It works by recursively breaking down the multiplication into smaller subproblems.
 *
 * Time complexity: O(n^log3)
 *
 * @author  Troy
 * @date    2026-02-15
 */
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/**
 * @brief   Remove leading zeros from a string.
 *
 * @param[in]   s   The string to remove leading zeros from.
 * @return  The string with leading zeros removed.
 */
string stripLeadingZeros(const string &s)
{
    size_t pos = s.find_first_not_of('0');
    return (pos == string::npos) ? "0" : s.substr(pos);
}

/**
 * @brief   Add two strings representing non-negative integers.
 *
 * @param[in]   a   The first string.
 * @param[in]   b   The second string.
 * @return  The sum of a and b as a string.
 */
string addStrings(const string &a, const string &b)
{
    string res;
    int carry = 0;
    int i = a.size() - 1, j = b.size() - 1;

    while ((i >= 0) || (j >= 0) || carry)
    {
        int sum = carry;
        if (i >= 0)
        {
            sum += a[i--] - '0';
        }
        if (j >= 0)
        {
            sum += b[j--] - '0';
        }
        res.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    reverse(res.begin(), res.end());
    return stripLeadingZeros(res);
}

/**
 * @brief   Subtract two strings representing non-negative integers.
 *
 * @param[in]   a   The first string.
 * @param[in]   b   The second string.
 * @return  The difference of a and b as a string.
 */
string subtractStrings(const string &a, const string &b)
{
    string res;
    int borrow = 0;
    int i = a.size() - 1, j = b.size() - 1;

    while (i >= 0)
    {
        int diff = (a[i] - '0') - borrow - (j >= 0 ? (b[j] - '0') : 0);
        if (diff < 0)
        {
            diff += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        res.push_back(diff + '0');
        i--;
        j--;
    }
    reverse(res.begin(), res.end());
    return stripLeadingZeros(res);
}

/**
 * @brief   Shift a string to the left by n positions.
 *
 * @param[in]   s   The string to shift.
 * @param[in]   n   The number of positions to shift.
 * @return  The shifted string.
 */
string shiftLeft(const string &s, int n)
{
    if (s == "0")
    {
        return "0";
    }
    return s + string(n, '0');
}

/**
 * @brief   Multiply two strings representing non-negative integers using simple multiplication.
 *
 * @param[in]   a   The first string.
 * @param[in]   b   The second string.
 * @return  The product of a and b as a string.
 */
string multiplySimple(const string &a, const string &b)
{
    int n = a.size(), m = b.size();
    string res(n + m, '0');

    for (int i = n - 1; i >= 0; i--)
    {
        int carry = 0;
        for (int j = m - 1; j >= 0; j--)
        {
            int sum = (res[i + j + 1] - '0') + (a[i] - '0') * (b[j] - '0') + carry;
            res[i + j + 1] = sum % 10 + '0';
            carry = sum / 10;
        }
        res[i] += carry;
    }
    return stripLeadingZeros(res);
}

/**
 * @brief   Multiply two strings representing non-negative integers using Karatsuba algorithm.
 *
 * @param[in]   x   The first string.
 * @param[in]   y   The second string.
 * @return  The product of x and y as a string.
 */
string karatsuba(const string &x, const string &y)
{
    string a = stripLeadingZeros(x);
    string b = stripLeadingZeros(y);

    if (a == "0" || b == "0")
    {
        return "0";
    }

    if (a.size() <= 32 || b.size() <= 32)
    {
        return multiplySimple(a, b);
    }

    int n = max(a.size(), b.size());
    if (n % 2)
    {
        n++;
    }

    a = string(n - a.size(), '0') + a;
    b = string(n - b.size(), '0') + b;

    int half = n / 2;

    string high1 = a.substr(0, half);
    string low1 = a.substr(half);
    string high2 = b.substr(0, half);
    string low2 = b.substr(half);

    string z0 = karatsuba(low1, low2);
    string z2 = karatsuba(high1, high2);

    string sum1 = addStrings(low1, high1);
    string sum2 = addStrings(low2, high2);

    string z1 = karatsuba(sum1, sum2);
    z1 = subtractStrings(subtractStrings(z1, z0), z2);

    return stripLeadingZeros(
        addStrings(
            addStrings(shiftLeft(z2, 2 * half),
                       shiftLeft(z1, half)),
            z0));
}

int main()
{
    string a, b;
    cout << "Enter first big integer: ";
    cin >> a;
    cout << "Enter second big integer: ";
    cin >> b;

    cout << a << " * " << b << " = " << karatsuba(a, b) << endl;
    return 0;
}
