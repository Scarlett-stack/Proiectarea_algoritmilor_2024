#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
using namespace std;

#define LETTERS_MAX_INTEGER 125

ifstream in("playwithstrings.in");
ofstream out("playwithstrings.out");

bool canBePalindrome(string s) {
    int letters[LETTERS_MAX_INTEGER] = {0};

    for (unsigned int i = 0; i < s.size(); i++) {
        letters[(int)s[i]]++;
    }

    int odd = 0;

    for (unsigned int i = 0; i < LETTERS_MAX_INTEGER; i++) {
        if (letters[i] % 2 == 1) {
            odd++;
            if (odd > 1) {
                return false;
            }
        }
    }

    return true;
}

bool isomorphicStrings(string s, string t) {
    if (s.size() != t.size())
        return false;

    char isomorphicS[LETTERS_MAX_INTEGER];
    char isomorphicT[LETTERS_MAX_INTEGER];

    memset(isomorphicS, '-', LETTERS_MAX_INTEGER);
    memset(isomorphicT, '-', LETTERS_MAX_INTEGER);

    for (unsigned int i = 0; i < s.size(); i++) {
        if (isomorphicS[(int)s[i]] != '-') {
            if (isomorphicS[(int)s[i]] != t[i])
                return false;
            continue;
        }

        if (isomorphicT[(int)t[i]] != '-') {
            if (isomorphicT[(int)t[i]] != s[i])
                return false;
            continue;
        }

        isomorphicS[(int)s[i]] = t[i];
        isomorphicT[(int)t[i]] = s[i];
    }
    return true;
}

int main() {
    int T, query;
    string s, t;

    in >> T;

    for (int i = 0; i < T; i++) {
        in >> query;

        if (query == 1) {
            in >> s;
            if (canBePalindrome(s))
                out << "True\n";
            else
                out << "False\n";
        }
        else {
            in >> s >> t;
            if (isomorphicStrings(s, t))
                out << "True\n";
            else
                out << "False\n";
        }
    }
    return 0;
}