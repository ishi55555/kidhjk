#include <iostream>
#include <string>
#include <vector>

using namespace std;

void computeLPSArray(const string& pat, vector<int>& lps);

void KMPSearch(const string& pat, const string& txt) {
    int M = pat.length();
    int N = txt.length();

    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    vector<int> lps(M);

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, lps);

    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            cout << "Found pattern at index " << i - j << endl;
            j = lps[j - 1];
        }

        // mismatch after j matches
        else if (i < N && pat[j] != txt[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}

// Fills lps[] for given pattern pat[0..M-1]
void computeLPSArray(const string& pat, vector<int>& lps) {
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < pat.length()) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Driver code
int main() {
    string txt, pat;
    cout << "Enter the text: ";
    getline(cin, txt);
    cout << "Enter the pattern: ";
    getline(cin, pat);

    KMPSearch(pat, txt);
    return 0;
}

//O(m+n)

