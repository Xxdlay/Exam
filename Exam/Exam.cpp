#include <iostream>
#include <cstring>
using namespace std;


void filteredTxt(const char* source, char* result, bool lat, bool cyr, bool punct, bool dig) {
    int length = strlen(source);
    for (int i = 0; i <= length; i++) {
        result[i] = source[i];
    }

    for (int i = 0; i < length; i++) {
        char ch = result[i];
        // Latin
        if (lat && ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))) {
            result[i] = ' ';
        }
        // Digits
        if (dig && (ch >= '0' && ch <= '9')) {
            result[i] = ' ';
        }
        // Punct
        if (punct && (ch == '.' || ch == ',' || ch == '!' || ch == '?' ||
            ch == ':' || ch == '-' || ch == '"' || ch == '\'')) {
            result[i] = ' ';
        }
        // Cyril
        if (cyr && ((ch >= 'а' && ch <= 'я') || (ch >= 'А' && ch <= 'Я') ||
            ch == 'і' || ch == 'І' || ch == 'ї' || ch == 'Ї' || ch == 'є' || ch == 'Є')) {
            result[i] = ' ';
        }
    }
}



void showMenu(const char* processedText, bool lat, bool cyr, bool punct, bool dig) {
    cout << endl << "====================================" << endl;
    cout << "Current result: " << processedText << endl;
    cout << "====================================" << endl;
    cout << "Choose a filter to toggle (ON/OFF):" << endl;
    cout << "1. Latin characters    [" << (lat ? "ON" : "OFF") << "]" << endl;
    cout << "2. Cyrillic characters [" << (cyr ? "ON" : "OFF") << "]" << endl;
    cout << "3. Punctuation marks   [" << (punct ? "ON" : "OFF") << "]" << endl;
    cout << "4. Digits              [" << (dig ? "ON" : "OFF") << "]" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}



int main() {
    char originalText[200];
    cout << "Enter your text: ";
    cin.getline(originalText, 200);

    bool fLatin = false;
    bool fCyrillic = false;
    bool fPunct = false;
    bool fDigits = false;
    int choice;
    char currentText[200];



    do {

        filteredTxt(originalText, currentText, fLatin, fCyrillic, fPunct, fDigits);
        showMenu(currentText, fLatin, fCyrillic, fPunct, fDigits);
        cin >> choice;

        switch (choice) {
        case 1: fLatin = !fLatin; break;
        case 2: fCyrillic = !fCyrillic; break;
        case 3: fPunct = !fPunct; break;
        case 4: fDigits = !fDigits; break;
        case 5: cout << "Goodbye!\n"; break;
        default: cout << "Invalid choice!\n"; break;
        }
    } while (choice != 5);
    return 0;
}