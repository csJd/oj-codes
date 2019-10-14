/*
3
H
ASDFGH
ASDFDSAG

0
5
8
*/

#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int dist[128][128];

void init_dist(string s) {
    memset(dist, 0, sizeof(dist));
    int length = s.length();
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < i; ++j) {
            dist[s[i]][s[j]] = dist[s[j]][s[i]] = i - j;
        }
    }
}

int main() {
    int n_cases;
    cin >> n_cases;
    string keyb = "ADFGHS";

    while (n_cases--) {
        string inp;
        cin >> inp;
        int min_cost = INT_MAX;
        bool flag = true;
        while (flag) {
            init_dist(keyb);
            char last = keyb[0];
            int cost = 0;
            for (char c : inp) {
                cost += dist[c][last];
                last = c;
            }
            if (cost < min_cost) {
                min_cost = cost;
            }
            flag = next_permutation(keyb.begin(), keyb.end());
        }
        cout << min_cost << endl;
    }

    return 0;
}
