/**
 * @file code.cpp
 * @author PE06 Hrishikesh Vaze
 * @brief IS - LAB 3 - asymetric RSA
 */

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <math.h>
using namespace std;

bool is_prime(int n)
{
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int inverse_mod(int a, int m)
{
    for (int x = 1; x < m; x++)
        if (((a % m) * (x % m)) % m == 1)
            return x;
    return -1; // error
}

int gcd(int a, int b)
{
    if (b == 0)
        return a; // base case
    else
        return gcd(b, a % b);
}

class AsymmetricRSA
{
public:
    static std::vector<string> encrypt(int p, int q, int plaintext)
    {
        if (!is_prime(p) || !is_prime(q))
            return {"P and Q should be Prime!", ""};
        int ciphertext = -1;
        int n = p * q;
        int phi = (p - 1) * (q - 1);
        int e = 2;
        while (e < phi)
        {
            if (gcd(e, phi) == 1)
                break;
            e++;
        }
        cout << "e = " << e << endl;
        int d = inverse_mod(e, phi);
        ciphertext = ((int)pow(plaintext, e)) % n;

        return {to_string(ciphertext), to_string(n), to_string(d)};
    }

    static std::vector<string> decrypt(int n, int d, int ciphertext)
    {
        int plaintext = ciphertext;
        cout << "d = " << d << endl;
        cout << "n = " << n << endl;
        plaintext = ((int)pow(ciphertext, d)) % n;
        return {to_string(((int)pow(ciphertext, d)) % n)};
    }
};

int main()
{
    int choice = 0;
    int p = 0, q = 0, n = 0, d = 0, data = 0;
    std::vector<string> result;

    do
    {
        cout << endl
             << "Asymetric RSA" << endl
             << "0. Exit" << endl
             << "1. Encrypt" << endl
             << "2. Decrypt" << endl
             << "Enter choice: ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 0:
            break;
        case 1:
            cout << "Enter P: ";
            cin >> p;
            cout << "Enter Q: ";
            cin >> q;
            cout << "Enter PlainText: ";
            cin >> data;
            result = AsymmetricRSA::encrypt(p, q, data);
            cout << "CipherText: " << result[0] << endl;
            if (result[1] != "")
                cout << "N: " << result[1] << endl
                     << "Public Key: " << result[2] << endl;
            break;
        case 2:
            cout << "Enter N: ";
            cin >> n;
            cout << "Enter D: ";
            cin >> d;
            cout << "Enter CipherText: ";
            cin >> data;
            result = AsymmetricRSA::decrypt(n, d, data);
            cout << "PlainText: " << result[0] << endl;
            break;
        default:
            cout << endl
                 << "Invalid Choice!";
        }
        cout << endl;
    } while (choice != 0);
    cout << endl;
    return 0;
}

/*

2 * 2 * 2 * 2 * 2 * 3

on decryptside = take, n, d, cipher

*/