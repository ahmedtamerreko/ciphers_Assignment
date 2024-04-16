
#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;
int j = 0;
void encrypt_reil(int key, string text)
{
    int textSize = text.size();
    char matrix[key][textSize];
    // Fill the array with zeros
    for (int i = 0; i < key; ++i)
    {
        for (int j = 0; j < textSize; ++j)
        {
            matrix[i][j] = '0';
        }
    }

    // Fill the matrix with characters from the string
    while (j < textSize)
    {
        for (int i = 0; i < key && j < textSize; ++i)
        {
            matrix[i][j] = text[j];
            ++j;
        }

        for (int k = key - 2; k > 0 && j < textSize; --k)
        {
            matrix[k][j] = text[j];
            ++j;
        }
    }
    cout << "the cipher text is ";
    // Print the characters from the matrix
    for (int l = 0; l < key; ++l)
    {
        for (int u = 0; u < textSize; ++u)
        {
            if (isalpha(matrix[l][u]))
            {
                cout << matrix[l][u];
            }
        }
    }
    cout << "\n";
}
void decrypt_reil(int key, string text)
{
    int textSize = text.size();
    // Declare a 2D array for the matrix
    char matrix[key][textSize];

    // Fill the array with zeros
    for (int i = 0; i < key; ++i)
    {
        for (int j = 0; j < textSize; ++j)
        {
            matrix[i][j] = '0';
        }
    }

    // Fill the matrix with characters from the string
    while (j < textSize)
    {
        for (int i = 0; i < key && j < textSize; ++i)
        {
            matrix[i][j] = '-';
            ++j;
        }

        for (int k = key - 2; k > 0 && j < textSize; --k)
        {
            matrix[k][j] = '-';
            ++j;
        }
    }
    j = 0;
    for (int r = 0; r < key; r++)
    {
        for (int c = 0; c < 28; c++)
        {
            if (matrix[r][c] == '-')
            {
                matrix[r][c] = text[j];
                j++;
            }
        }
    }
    j = 0;
    cout << "the original text is ";
    while (j < textSize)
    {
        for (int i = 0; i < key && j < textSize; ++i)
        {
            cout << matrix[i][j];
            ++j;
        }

        for (int k = key - 2; k > 0 && j < textSize; --k)
        {
            cout << matrix[k][j];
            ++j;
        }
    }
    cout << "\n";
}
string removeSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}
void lowercase(string &text)
{
    for (int i = 0; i < text.size(); i++)
    {
        text[i] = tolower(text[i]);
    }
}
int main()
{
    while (true)
    {
        string choice;
        cout << "=======Welcome to Reil-fence Cipher========\n";
        cout << "please choose what do you want\n";
        cout << "[1] Encrypt the text\n";
        cout << "[2] Decrypt the text\n";
        cin >> choice;
        if (choice == "1")
        {
            string text;
            int key;
            cout << "\nPlease Enter The Key Number\n";
            cin >> key;
            cout << "please enter the text that you want to encrypt it\n";
            cin.ignore();
            getline(cin, text);
            text = removeSpaces(text);
            lowercase(text);
            encrypt_reil(key, text);
        }
        else if (choice == "2")
        {
            string text;
            int key;
            cout << "\nPlease Enter The Key Number\n";
            cin >> key;
            cout << "please enter the text that you want to encrypt it\n";
            cin.ignore();
            getline(cin, text);
            text = removeSpaces(text);
            lowercase(text);
            decrypt_reil(key, text);
        }
        else
        {
            cout << "invalid choice\n";
        }
    }

    return 0;
}