#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int T;
    ll a, b, l, c, d, m;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas)
    {
        printf("Case %d: ", cas);
        scanf("%lld%lld%lld", &a, &b, &l);
        m = a * b / gcd(a, b); //mΪa,b�����Լ��

        if(l % m) puts("impossible");
        else
        {
            //Ҫʹlcm(c,m) = l  c������Ҫ��l�в���m�е������Ӻ�l��ָ������m�е�������ȡ��l�е�ָ��
            c = l / m;   //����c�а�����l�в���m�е�������ȡl��ָ�� �� l��ָ������m�е�������ȡָ����
            //��ô����c����Ҫ����c��m�Ĺ���������ȡm�е�ָ��
            while((d = gcd(c, m)) != 1) //gcd(c,m) ȡc,m���������ӵ�Сָ����
            {
                c = c * d, m = m / d;
                d = gcd(c, m);
            }
            printf("%lld\n", c);
        }
    }
    return 0;
}
