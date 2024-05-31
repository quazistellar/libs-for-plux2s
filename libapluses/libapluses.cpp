#include <iostream>
#include <string>
using namespace std;

extern "C" {
    __declspec(dllexport) bool FindLetters(const char* in_stroka, const char* finderLetts) {
        string str(in_stroka);
        string chars(finderLetts);

        for (char c : chars) {
            if (str.find(c) == string::npos) {
                return false;
            }
        }

        return true;
    }
}