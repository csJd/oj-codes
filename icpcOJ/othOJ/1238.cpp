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
        if(s[0] == '-')   //����Ϊ��ֱ��������� ���������һ������
        {
            putchar('-');
            for(int i = 0; s[i]; ++i)
                s[i] = s[i + 1];
        }

        for(int i = 0; s[i]; ++i)
        {
            if(s[i] == '.') m = i;                 //m��¼С������±�
            if(s[i] == 'e' || s[i] == 'E') n = i;  //n��¼E���±�
        }

        exp = 0;                                   //expΪE�������
        for(int i = n + 1; s[i]; ++i)
        {
            if(s[i] == '-') ++i;
            exp = exp * 10 + s[i] - '0';
        }
        if(s[n + 1] == '-') exp = -exp;

        p = m + exp;     //pΪС����Ҫ���Ƶ���λ��
        if(p <= 0)       //С�����Ƶ���ǰ�滹���� �϶�û��ǰ��0
        {
            printf("0.");
            while(p++) putchar('0');  //p <= 0ʱ��Ҫ��|p|��0
            for(int i = 0; i < n; ++i)
                if(s[i] != '.') putchar(s[i]);
        }

        else
        {
            while(n <= p) s[n++] = '0';//ȷ���������㹻��0��С�����ƶ�
            for(int i = m; i < p; ++i) s[i] = s[i + 1];
            for(int i = m; i > p; --i) s[i] = s[i - 1];
            s[p] = '.';                //С�����Ƶ���ȷλ��

            if(s[n - 1] == '.') --n;   //С�����Ƶ������һλ�����
            int flag = 0;              //flagΪ0˵����ǰ��0  �����
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

