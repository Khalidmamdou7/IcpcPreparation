// problem description: https://codeforces.com/group/k43ChfKeWS/contest/391788/problem/B

// key learnings: 
//      - use the approach of edit distance problem to solve problems related to strings

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll rec(string& a, string& b, vector<vector<ll>>& dp, int i, int j) {
    if(i < 0 || j < 0)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    if(a[i] == b[j])
        return dp[i][j] = 1 + rec(a, b, dp, i - 1, j - 1);
    
    return dp[i][j] = max(rec(a, b, dp, i - 1, j), rec(a, b, dp, i, j - 1));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a, b;
    cin >> a >> b;
    vector<vector<ll>> dp(a.size(), vector<ll>(b.size(), -1));
    cout << rec(a, b, dp, a.size() - 1, b.size() - 1);

    
    return 0;
}