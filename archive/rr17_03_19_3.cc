#include <iostream>
#include <vector>
using namespace std;
std::vector<char> v;
int main() {
    long long b;
    while (cin >> b) {
        int x, y;
        for (int i = 2; i < b; i++) {
            if (b % i == 1) {
                x = i;
                break;
            }
        }
        long long b1 = b + 1;
        long long b2 = b * b - 1;
        for (int i = 2; i <= b1; i++) {
            if (b1 % i == 0 && b2 % i == 0) {
                y = i;
                break;
            }
        }
        cout << x << ' ' << y << endl;
    }
}

/*
神奇的规律
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 32768KB；其他语言 557056KB
题目描述：
小明学习数学的时候发现两个神奇的规律：
假设现在有一个十进制数字n=a0*1+a1*10+a2*102+a3*103+.....+ak*10k。
1. 要判断n能否被3整除，只需要验证各位和能否被3整除，即sum=a0+a1+a2+....+ak能否被3整除。如果sum能被3整除，那么n就能被3整除。
2. 要判断n能否被11整除，只需要验证偶数位和与奇数位和的差能否被11整除，
即diff=（a0+a2+a4+....）-（a1+a3+a5+...）能否被11整除。如果diff能被11整除，那么n就能被11整除。
例如81和1243可以用上述方法分别验证能否被3和11整除。
现在小明想让你帮忙写段程序求出b进制下分别满足上述规律的最小的x和最小的y。
即n=a0*1+a1*b+a2*b2+a3*b3+.....+ak*bk，
n能被xi整除，当且仅当sum=a0+a1+a2+....+ak能被xi整除，x为最小的xi。
n能被yi整除，当且仅当diff=（a0+a2+a4+.....）-（a1+a3+a5+.....）能被yi整除，y为最小的yi。

输入
输入数据有多组，每组数据包含一个数字b(3<=b<=10^6)

输出
输出x和y


样例输入
10
120

样例输出
3 11
7 11
*/
