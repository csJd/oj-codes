#include <cstdio>
using namespace std;

void hanoi(int n, char a, char b, char c)
{
    if(n == 0) return;
    hanoi(n - 1, a, c, b);
    printf(" %c -> %c\n", a, b);
    hanoi(n - 1, c, b, a);
}

int main()
{
    int n;
    puts("输入盘子的个数 输入负数时结束\n");
    while(scanf("%d", &n), n >= 0)
    {
        printf("将 %d 个盘子从A移到B的方法如下:\n", n);
        hanoi(n, 'A', 'B', 'C');
        puts("");
    }
    return 0;
}
