#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define NO_OF_CHARS 256

void badCharHeuristic(const string& str, int size, int badchar[NO_OF_CHARS]) {
    for (int i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;

    for (int i = 0; i < size; i++)
        badchar[(int)str[i]] = i;
}

void search(const string& txt, const string& pat) {
    int m = pat.size();
    int n = txt.size();
    int badchar[NO_OF_CHARS];

    badCharHeuristic(pat, m, badchar);

    int s = 0; 
    while (s <= (n - m)) {
        int j = m - 1;

        while (j >= 0 && pat[j] == txt[s + j])
            j--;

        if (j < 0) {
            cout << "Pattern occurs at shift = " << s << endl;
            s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
        } else
            s += max(1, j - badchar[txt[s + j]]);
    }
}

int main() {
    string txt, pat;
    cout << "Enter the text: ";
    getline(cin, txt);
    cout << "Enter the pattern: ";
    getline(cin, pat);
    search(txt, pat);
    return 0;
}

//O(m*n)
//Boyer Moore Algorithm for Pattern Searching
//Pattern searching is an important problem in computer science. When we do search for a string in a notepad/word file, browser, or database, pattern searching algorithms are used to show the search results.
//
//A typical problem statement would be- 
//
//” Given a text txt[0..n-1] and a pattern pat[0..m-1] where n is the length of the text and m is the length of the pattern, write a function search(char pat[], char txt[]) that prints all occurrences of pat[] in txt[]. You may assume that n > m. “
//Examples: 
//
//
//
//Input: txt[] = “THIS IS A TEST TEXT”
//pat[] = “TEST”
//
//Output: Pattern found at index 10
//
//Input: txt[] = “AABAACAADAABAABA”
//
//pat[] = “AABA”
//
//Output: Pattern found at index 0
//
//Pattern found at index 9
//
//Pattern found at index 12


//Boyer Moore is a combination of the following two approaches. 
//
//Bad Character Heuristic 
//Good Suffix Heuristic 
//
//Bad Character Heuristic
//The idea of bad character heuristic is simple. The character of the text which doesn’t match with the current character of the pattern is called the Bad Character. Upon mismatch, we shift the pattern until – 
//
//The mismatch becomes a match.
//Pattern P moves past the mismatched character.