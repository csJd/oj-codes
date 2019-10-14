/*
与 0,0 构成长方形的个数

5
4
1 1
2 2
3 3
4 4
4
1 4
2 3
3 2
4 1
4
2 1
1 2
3 1
1 3
5
1 5
5 1
5 5
1 1
5 5
5
1 3
1 4
1 2
1 1
1 5

>>>
4
10
5
4
5
*/

#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

bool cmp(const pair<int, int> &x, const pair<int, int> &y) {
    return x.first < y.first;
}

int bisect(vector<int> arr, int k) {
    int len = arr.size();
    int le = 0, ri = len - 1, mid;
    while (le <= ri) {
        mid = (le + ri) >> 1;
        if (arr[mid] <= k) {
            le = mid + 1;
        } else {
            ri = mid - 1;
        }
    }
    return ri + 1; // the first > k
}

int main() {
    // not finished
    int n_cases;
    cin >> n_cases;
    while (n_cases--) {
        int n, x, y;
        cin >> n;
        int ans = 1;
        vector<pair<int, int>> points;
        for (int i = 0; i < n; ++i) {
            cin >> x >> y;
            points.push_back(make_pair(x, y));
        }
        sort(points.begin(), points.end(), cmp);
    }
    return 0;
}
