#include <iostream>
#include <string>
#include <algorithm>
#include <locale>
#include <windows.h>
#include <cctype>

using namespace std;


char toLowerRussian(char c) {
    if (c >= 'А' && c <= 'Я') {
        return c + 32;
    }
    return tolower(c);
}

string prepareString(const string& str) {
    string prepared;
    for (unsigned char c : str) {
        if (!isspace(c) && !ispunct(c)) {
            prepared += toLowerRussian(c);
        }
    }
    return prepared;
}

bool isPalindrome(const string& str) {
    string prepared = prepareString(str);
    string reversed = prepared;
    reverse(reversed.begin(), reversed.end());
    return prepared == reversed;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);


    string input;
    cout << "Введите строку для проверки на палиндром: ";
    getline(cin, input);

    if (isPalindrome(input)) {
        cout << "Да, это палиндром!" << endl;
    } else {
        cout << "Нет, это не палиндром." << endl;
    }

    return 0;
}
