/*
3
123 456
15 20
20 15
*/

#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt[10] = {0};
    int case_cnt[10] = {0};
    int a, b;
    vector<int> vec;

    while (n--) {
        cin >> a >> b;
        vec.clear();
        vec.push_back(a);
        vec.push_back(b);
        memset(case_cnt, 0, sizeof(case_cnt));
        int base = 1;
        int ans = 0;
        while (b) {
            int tmp = (b % 10) * a * base;
            ans += tmp;
            vec.push_back(tmp);
            b /= 10;
            base *= 10;
        }
        vec.push_back(ans);
        for (int x : vec) {
            while (x) {
                case_cnt[x % 10] += 1;
                x /= 10;
            }
        }
        for (int i = 1; i < 10; ++i) {
            cout << case_cnt[i] << (i < 9 ? ' ' : '\n');
            cnt[i] += case_cnt[i];
        }
    }

    int maxv = 1;
    for (int i = 2; i < 10; ++i) {
        if (cnt[i] > cnt[maxv]) {
            maxv = i;
        }
    }
    cout << maxv << endl;

    return 0;
}
