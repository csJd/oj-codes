#include <cstdio>
using namespace std;
const int L = 1e5 + 10;
char from[L];

void toWave()
{
    for(int i = 0; from[i]; ++i)
    {
        if(from[i] == '+')
        {
            printf("/\\");
        }
        else
        {
            printf("__");
        }
    }
    puts("");
}

void toData()
{
    for(int i = 0; from[i]; i += 2)
    {
        if(from[i] == '/')
        {
            putchar('+');
        }
        else
        {
            putchar('-');
        }
    }
    puts("");
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", from);
        if(from[0] == '-' || from[0] == '+')
        {
            toWave();
        }
        else
        {
            toData();
        }
    }
    return 0;
}

/*
波形图
时间限制：C/C++语言 2000MS；其他语言 4000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
小明正在做物理实验，他在示波器上观察波形。在每一时刻，他能观察到两种可能的波形，一种是水平波形，由两个下划线组成：”__”。一种是脉冲波形，由一个斜杠和一个反斜杠组成：”/\”。
小明观察到一个水平波形就在数据表上记录一个减号”-”，观察到一个脉冲波形就在数据表上记录一个加号”+”。如小明观察到波形”__/\__/\/\__”，他就会记录”-+-++-”。
现在小明想实现纪录序列与波形之间的转化，你能帮助他吗？

输入
输入第一行一个数T表示测试数据组数（T<=10），每组数据为一个字符串，长度不超过100000，可能是波形图，也可能是纪录序列，输入保证合法。

输出
对于每组数据输出一行，如果输入是波形图，则输出对应的纪录序列，如果输入是纪录序列，则输出对应波形图。


样例输入
4
-+--+
__/\/\__
____/\__
---++-+--

样例输出
__/\____/\
-++-
--+-
______/\/\__/\____


Hint
样例输入第一行一个数4，表示有四组测试数据。接下来有4行，第一组，第四组是记录序列，第二组，第三组是波形图。

*/
