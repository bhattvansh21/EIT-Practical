#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char text[500];
    int key;
    char mode;

    cout << "Enter a message: ";
    cin.getline(text, sizeof(text));

    cout << "Enter the key: ";
    cin >> key;

    cout << "Choose mode - 'e' for encryption or 'd' for decryption: ";
    cin >> mode;

    for (int i = 0; text[i] != '\0'; ++i) {
        char ch = text[i];
        if (isalnum(ch)) {
            switch (mode) {
                case 'e':
                case 'E':
                    if (islower(ch)) {
                        ch = (ch - 'a' + key) % 26 + 'a';
                    } else if (isupper(ch)) {
                        ch = (ch - 'A' + key) % 26 + 'A';
                    } else if (isdigit(ch)) {
                        ch = (ch - '0' + key) % 10 + '0';
                    }
                    break;
                case 'd':
                case 'D':
                    if (islower(ch)) {
                        ch = (ch - 'a' - key + 26) % 26 + 'a';
                    } else if (isupper(ch)) {
                        ch = (ch - 'A' - key + 26) % 26 + 'A';
                    } else if (isdigit(ch)) {
                        ch = (ch - '0' - key + 10) % 10 + '0';
                    }
                    break;
                default:
                    cout << "Invalid mode. Use 'e' for encryption or 'd' for decryption." << endl;
                    return 1;
            }
        } else {
            cout << "Invalid Message";
            return 1;
        }
        text[i] = ch;
    }

    if (mode == 'e' || mode == 'E') {
        cout << "Encrypted message: " << text << endl;
    } else if (mode == 'd' || mode == 'D') {
        cout << "Decrypted message: " << text << endl;
    }

    return 0;
}

