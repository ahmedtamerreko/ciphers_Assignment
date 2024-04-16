// Vignere Cipher
// Author Ahmed Tamer Shawky
// ID : 20230012
// Section : S23
#include <iostream>
#include <string>
using namespace std;
bool is_key_string_valid(string key_string)
{
    int key_size = key_string.size();
    // Check if the input size is correct
    if (key_string.size() >= 8)
    {
        cout << "You Should Enter Valid Key mustn't exceed 8 chracters\n";
        return false;
    }

    // Check if all characters are alphabets
    for (char c : key_string)
    {
        if (!isalpha(c))
        {
            cout << "(Please enter alphabetic characters only)\n";
            return false;
        }
    }

    // Check for uniqueness of characters
    for (int i = 0; i < key_size; i++)
    {
        for (int j = i + 1; j < key_size; j++)
        {
            if (i != j)
            {
                if (key_string[i] == key_string[j])
                {
                    cout << "(Please enter unique Diffrent letters)\n";
                    return false;
                }
            }
        }
    }

    // If all checks pass, return true
    return true;
}

void encrypt_message_Vignere(string text, string key)
{
    int key_size = key.size();

    for (int i = 0; i < text.size(); i++)
    {
        if (isalpha(text[i]))
        {
            cout << char(((text[i] + key[i % key_size]) % 26) + 65);
        }
        else
        {
            cout << text[i];
        }
    }
}
void uppercase(string &text)
{
    for (int i = 0; i < text.size(); i++)
    {
        text[i] = toupper(text[i]);
    }
}
void decrypt_message_vignere(string text, string key)
{
    int key_size = key.size();

    for (int i = 0; i < text.size(); i++)
    {
        if (isalpha(text[i]))
        {
            if (text[i] > key[i % key_size])
            {
                cout << char(5 * 26 + (text[i] - 'A') - key[i % key_size]);
            }
            else
            {
                cout << char(5 * 26 + (text[i] - 'A') - key[i % key_size] + 26);
            }
        }
        else
        {
            cout << text[i];
        }
    }
}
int main()
{
    while (true)
    {
        string choice;
        cout << "=======Welcome to Vignere Cipher========\n";
        cout << "please choose what do you want\n";
        cout << "[1] Encrypt the text\n";
        cout << "[2] Decrypt the text\n";
        cin >> choice;
        if (choice == "1")
        {
            string text;
            string key;
            cout << "\nPlease Enter The Key\n";
            cin >> key;
            if (is_key_string_valid(key))
            {
                cout << "please enter the text that you want to encrypt it\n";
                cin.ignore();
                getline(cin, text);
                if (text.size() > 80)
                {
                    cout << "your text must not exceed 80 chracters\n";
                    continue;
                }
                uppercase(key);
                uppercase(text);
                encrypt_message_Vignere(text, key);
            }
        }
        else if (choice == "2")
        {
            string text;
            string key;
            cout << "\nPlease Enter The Key\n";
            cin >> key;
            if (is_key_string_valid(key))
            {
                cout << "please enter the text that you want to decrypt it\n";
                cin.ignore();
                getline(cin, text);
                if (text.size() > 80)
                {
                    cout << "your text must not exceed 80 chracters\n";
                    continue;
                }
                uppercase(key);
                uppercase(text);
                decrypt_message_vignere(text, key);
            }
        }
        else
        {
            cout << "invalid choice\n";
        }
    }

    return 0;
}