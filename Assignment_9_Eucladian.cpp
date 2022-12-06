#include <bits/stdc++.h>
using namespace std;

int findGCD(int num1, int num2)
{
    if (num1 == 0)
    return num2;
    return findGCD(num2 % num1, num1);
}

int main()
{
    int num1, num2;
    cout << "\n Enter 1st number : ";
    cin >> num1;

    cout << "\n Enter 2nd number : ";
    cin >> num2;

    int gcd = findGCD(num1, num2);
    cout << "\n GCD is " << gcd << endl;

    return 0;
}