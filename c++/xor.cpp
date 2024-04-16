// XOR Cipher
// Author Ahmed Tamer Shawky
// ID : 20230012
// Section : S23
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
string stringToHex(string &input) // Convert string to hexa after encrypting the texr
{
    string result = "";
    for (char c : input)
    {
        int ascii = static_cast<int>(c); // take it integer firstly as unicode to convert it easily
        stringstream ss;
        ss << hex << ascii;
        result += ss.str();
    }
    return result;
}
void cipher(string key, string text)
{
    int keySize = key.size();
    string cipherd = "";

    for (int i = 0; i < text.size(); i++)
    {
        cipherd += text[i] ^ key[i % keySize]; // using modulas to make sure we did not exceed key size 
    }
    cout << "ciphered text is " << cipherd;
    cout << "\nciphered text as hexa is " << stringToHex(cipherd) << "\n";
}

int hexadecimalToDecimal(string hexVal)
{
    int len = hexVal.size();

    // Initializing base value to 1, i.e 16^0
    int base = 1;

    int dec_val = 0;

    // Extracting characters as digits from last
    // character
    for (int i = len - 1; i >= 0; i--)
    {
        // if character lies in '0'-'9', converting
        // it to integral 0-9 by subtracting 48 from
        // ASCII value
        if (hexVal[i] >= '0' && hexVal[i] <= '9')
        {
            dec_val += (int(hexVal[i]) - 48) * base;

            // incrementing base by power
            base = base * 16;
        }

        // if character lies in 'A'-'F' , converting
        // it to integral 10 - 15 by subtracting 55
        // from ASCII value
        else if (hexVal[i] >= 'A' && hexVal[i] <= 'F')
        {
            dec_val += (int(hexVal[i]) - 55) * base;

            // incrementing base by power
            base = base * 16;
        }
    }
    return dec_val;
}
void decipher(string key, string hexaText)
{
    int keySize = key.size();
    string decipherd = "";
    for (int i = 0; i < hexaText.size(); i += 2)
    {
        if (hexaText[i] == ' ') // check if there are spaces
        {
            i -= 1;
            continue;
        }
        string carry = "";
        carry += hexaText[i];
        carry += hexaText[i + 1];
        decipherd += char(hexadecimalToDecimal(carry) ^ key[i % keySize]); // using modulas to make sure we did not exceed key size 
    }
    cout << "deciphered text is " << decipherd << "\n";
}
int main()
{
    while (true)
    {
        cout << "\n========welcome to XOR Encrypt & Decrypt text\n";
        cout << "what do you want to do?\n";
        cout << "[1] Encrypt\n";
        cout << "[2] Decrypt\n";
        string choice;
        cin >> choice;
        if (choice == "1")
        {
            string text;
            cout << "please Enter the text to encrypt it\n";
            cin.ignore();
            getline(cin, text);
            string key;
            cout << "please Enter The Key\n";
            cin >> key;
            cipher(key, text);
        }
        else if (choice == "2")
        {
            string hexaText;
            cout << "please enter the text as hexadecimal to decrypt it\n";
            cin.ignore();
            getline(cin, hexaText);
            string key;
            cout << "please Enter The Key\n";
            cin >> key;
            decipher(key, hexaText);
        }
        else
        {
            cout << "please choose valid input\n";
            continue;
        }
    }

    return 0;
}