#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findMinChange(int amount, int& minCoins, vector<int>& denominationsUsed, const vector<int>& denominations) {
    minCoins = 0;
    for (int i = 0; i < denominations.size(); i++) {
        while (amount >= denominations[i]) {
            amount -= denominations[i];
            denominationsUsed.push_back(denominations[i]);
            minCoins++;
        }
    }
}

int main() {

    int numDenominations;
    cout << "Enter the number of denominations: ";
    cin >> numDenominations;

    vector<int> denominations(numDenominations);
    cout << "Enter the denominations: ";
    for (int i = 0; i < numDenominations; i++) {
        cin >> denominations[i];
    }
    int amount;
    cout << "Enter the amount: ";
    cin >> amount;

    // Sort denominations in descending order
    sort(denominations.begin(), denominations.end(), greater<int>());

    int minCoins;
    vector<int> denominationsUsed;
    findMinChange(amount, minCoins, denominationsUsed, denominations);

    cout << "Minimal number of coins for " << amount << ": " << minCoins << endl;
    cout << "Denominations used: ";
    for (int i = 0; i < denominationsUsed.size(); i++)
        cout << denominationsUsed[i] << " ";
    return 0;
}

