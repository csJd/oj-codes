#include <cstdio>
using namespace std;
char s[105];

int main()
{
    int T, n, m, p, exp;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", s);
        if(s[0] == '-')   //底数为负直接输出负号 后面和正数一样处理
        {
            putchar('-');
            for(int i = 0; s[i]; ++i)
                s[i] = s[i + 1];
        }

        for(int i = 0; s[i]; ++i)
        {
            if(s[i] == '.') m = i;                 //m记录小数点的下标
            if(s[i] == 'e' || s[i] == 'E') n = i;  //n记录E的下标
        }

        exp = 0;                                   //exp为E后面的数
        for(int i = n + 1; s[i]; ++i)
        {
            if(s[i] == '-') ++i;
            exp = exp * 10 + s[i] - '0';
        }
        if(s[n + 1] == '-') exp = -exp;

        p = m + exp;     //p为小数点要被移到的位置
        if(p <= 0)       //小数点移到最前面还不够 肯定没有前导0
        {
            printf("0.");
            while(p++) putchar('0');  //p <= 0时需要补|p|个0
            for(int i = 0; i < n; ++i)
                if(s[i] != '.') putchar(s[i]);
        }

        else
        {
            while(n <= p) s[n++] = '0';//确保后面有足够的0供小数点移动
            for(int i = m; i < p; ++i) s[i] = s[i + 1];
            for(int i = m; i > p; --i) s[i] = s[i - 1];
            s[p] = '.';                //小数点移到正确位置

            if(s[n - 1] == '.') --n;   //小数点移到了最后一位不输出
            int flag = 0;              //flag为0说明是前导0  不输出
            for(int i = 0; i < n; ++i)
            {
                if(s[i] != '0' || s[i + 1] == '.') flag = 1;
                if(flag) putchar(s[i]);
            }
        }
        puts("");
    }
    return 0;
}
//Last modified :  2015-11-25 21:00 CST

