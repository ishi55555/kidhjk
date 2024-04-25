#include <iostream>
#include <string>
using namespace std;

// Function to search for occurrences of a pattern in a text using naive pattern matching algorithm
void search(const string& pat, const string& txt) {
    int M = pat.size(); // Length of the pattern
    int N = txt.size(); // Length of the text

    // A loop to slide the pattern one position at a time in the text
    for (int i = 0; i <= N - M; i++) {
        int j;

        // Check for pattern match starting at index i in the text
        for (j = 0; j < M; j++) {
            // If characters don't match, break out of the loop
            if (txt[i + j] != pat[j]) {
                break;
            }
        }

        // If the loop ran to completion, it means the pattern was found at index i
        if (j == M) {
            cout << "Pattern found at index " << i << endl;
        }
    }
}

int main() {
    string txt, pat;

    // Input text from the user
    cout << "Enter the text: ";
    getline(cin, txt);

    // Input pattern from the user
    cout << "Enter the pattern: ";
    getline(cin, pat);

    // Call the search function to find occurrences of the pattern in the text
    search(pat, txt);

    return 0;
}
