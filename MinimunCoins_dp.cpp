#include <bits/stdc++.h>
using namespace std;

vector<int> coin;
int dp[1000] = { 0 };

int minCoins(int amt, int M)
{
    for(int i=1; i<=amt; i++){
        dp[i]=INT_MAX;
    }
    for(int i=1;i<=amt;i++){
        for(int j=0; j<M;j++){
            if(coin[j] <= i){
                dp[i]=min(dp[i],1+dp[i-coin[j]]);
            }
        }
    }
    return dp[amt];
}

int main()
{
    int amt, n;
    cout << "\nEnter the desired amount: "; cin >> amt;
    cout << "Enter the number of coins: "; cin >> n;

    cout << "Enter the coins: " << endl;
    for(int i = 0; i < n; i++){
        int ele;
        cin >> ele;
        coin.push_back(ele);
    }

    chrono::time_point<chrono::system_clock> start, end;
    start = chrono::system_clock::now();

    cout << "\nMinimum coins needed are " << minCoins(amt, n);

    end = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;

    cout << "\nElapsed time: " << elapsed_seconds.count() << "s\n";
}