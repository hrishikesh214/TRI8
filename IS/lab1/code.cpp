/**
 * @file code.cpp
 * @author PE06 Hrishikesh Vaze
 * @brief IS - LAB 1 - Caesar Cypher
 */

#include <iostream>
#include <string>
using namespace std;

/**
 * @brief Handles Caecar Cypher operations on string
 *
 */
class CaesarCypher
{
private:
    int key; // key to be used for encryption

public:
    CaesarCypher(int _key = 0) : key(_key){};
    /**
     * @brief Set the key for the cypher
     * @param _key
     */
    void set_key(int _key) { key = _key; };

    /**
     * @brief encrypts the string as per the key
     *
     * @param plain_text
     * @return string (cypehr text)
     */
    string encypt(string plain_text)
    {
        string cipher_text = plain_text;
        int len = plain_text.length();
        for (int i = 0; i < len; i++)
        {
            // lowercase
            if (cipher_text[i] >= 'a' || cipher_text[i] <= 'z')
            {
                cipher_text[i] = ((cipher_text[i] - 'a' + key) % 26) + 'a';
            }
            // uppercase
            else if (cipher_text[i] >= 'A' || cipher_text[i] <= 'Z')
            {
                cipher_text[i] = ((cipher_text[i] - 'A' + key) % 26) + 'A';
            }
        }
        return cipher_text;
    };

    /**
     * @brief decrypts the string as per the key
     *
     * @param cipher_text
     * @return string (plain text)
     */
    string decrypt(string cipher_text)
    {
        string plain_text = cipher_text;
        int len = cipher_text.length();
        for (int i = 0; i < len; i++)
        {
            // lowercase
            if (plain_text[i] >= 'a' || plain_text[i] <= 'z')
            {
                plain_text[i] = ((plain_text[i] - 'a' - key) % 26) + 'a';
            }
            // uppercase
            else if (plain_text[i] >= 'A' || plain_text[i] <= 'Z')
            {
                plain_text[i] = ((plain_text[i] - 'A' - key) % 26) + 'A';
            }
        }
        return plain_text;
    };
};

int main()
{
    int choice = 0;
    int temp_int = 0;
    CaesarCypher encryptor;
    string plain_text = "", cipher_text = "";

    do
    {
        cout << endl
             << "0. Exit" << endl
             << "1. Set Key" << endl
             << "2. Encypt" << endl
             << "3. Decrypt" << endl
             << "Enter choice: ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 0:
            break;

        case 1:
            cout << "Enter key: ";
            cin >> temp_int;
            encryptor.set_key(temp_int);
            break;
        case 2:
            cout << "Enter plain text: ";
            cin >> plain_text;
            cipher_text = encryptor.encypt(plain_text);
            cout << "Cipher text: " << cipher_text << endl;
            break;
        case 3:
            cout << "Enter cipher text: ";
            cin >> cipher_text;
            plain_text = encryptor.decrypt(cipher_text);
            cout << "Plain text: " << plain_text << endl;
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