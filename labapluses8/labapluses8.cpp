#include <iostream>
#include <windows.h>
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

typedef bool (*FindCharactersFunc)(const char*, const char*);

int main() {
    setlocale(LC_ALL, "RU");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(0, "");

    HINSTANCE hGetProcIDDLL = LoadLibrary(L"libapluses.dll");
    if (!hGetProcIDDLL) {
        cout << "Не удалось загрузить библиотеку" << endl;
        return 1;
    }

    FindCharactersFunc finderLetts = (FindCharactersFunc)GetProcAddress(hGetProcIDDLL, "FindLetters");
    if (!finderLetts) {
        cout << "Ошибка при загрузке библиотеки" << endl;
        FreeLibrary(hGetProcIDDLL);
        return 1;
    }

    string in_stroka, symb;

    do {
        cout << "Введите строку: ";
        getline(cin, in_stroka);
        if (in_stroka.empty()) {
            cout << "пустая строка" << endl;
        }
    } while (in_stroka.empty());

    cout << "Введите символы, которые нужно найти в строке: ";
    cin >> symb;

    bool result = finderLetts(in_stroka.c_str(), symb.c_str());
    if (result) {
        cout << "\n...выполняется поиск <" + symb + "> " + " в строке '" + in_stroka + " '";
        cout << "\n";
        cout << "\n";
        cout << "\n > Все символы были найдены в строке [TRUE]" << endl;
    }
    else {
        cout << "> Не все символы были найдены в строке [FALSE]" << endl;
    }

    FreeLibrary(hGetProcIDDLL);
    return 0;
}
