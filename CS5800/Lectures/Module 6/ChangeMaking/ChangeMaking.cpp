/**
 * @file ChangeMaking.cpp
 * @brief Change making problem
 *
 * @author Troy
 * @date 2026-02-19
 */
#include <iostream>

using namespace std;

/**
 * @brief Change making problem
 *
 * Cashier's Algorithm (greedy algorithm) to find the minimum number of coins
 *
 * @param[in]   n   The amount of money(in cents)
 * @return      int The minimum number of coins
 */
int changeMaking(int n)
{
    int dollar = n / 100;
    n %= 100;
    cout << "Dollars: " << dollar << endl;

    int quarter = n / 25;
    n %= 25;
    cout << "Quarters: " << quarter << endl;

    int dime = n / 10;
    n %= 10;
    cout << "Dimes: " << dime << endl;

    int nickel = n / 5;
    n %= 5;
    cout << "Nickels: " << nickel << endl;

    int penny = n;
    cout << "Pennies: " << penny << endl;

    return dollar + quarter + dime + nickel + penny;
}

int main(void)
{
    int n;
    cout << "Enter the amount of money(in cents): ";
    cin >> n;

    int minCoins = changeMaking(n);
    cout << "Minimum number of coins: " << minCoins << endl;

    return 0;
}