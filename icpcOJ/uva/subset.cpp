#include<cstdio>
#include<cstring>
using namespace std;
const int N = 10005;

//�������취

//void psubset(int n, int *a, int cur)
//{
//    for(int i = 0; i < cur; ++i) printf("%d ", a[i]);
//    //��ӡ��ǰ����
//    printf("\n");
///**/int s = cur ? a[cur - 1] + 1 : 0;
//    //����ȷ����ǰԪ����С����ֵ
//    for(int i = s; i < n; ++i)
//    {
//        a[cur] = i;
//        psubset(n, a, cur + 1);//�ݹ鹹���Ӽ�
//    }
//}


//λ������

//void psubset(int n, int *b, int cur)
//{
//    if(cur == n)
//    {
//        for(int i = 0; i < cur; ++i)
//            if(b[i]) printf("%d ", i);    //��ӡ��ǰ����
//        printf("\n");
//        return;
//    }
//    b[cur] = 1;            //ѡ��cur��Ԫ��
//    psubset(n, b, cur + 1);
//    b[cur] = 0;            //��ѡ��cur��Ԫ��
//    psubset(n, b, cur + 1);
//}


//�����Ʒ�

void psubset(int n)
{
    for(int s = 0; s < 1 << n; ++s)
    {
        for(int i = 0; i < n; ++i)
            if(s & (1 << i)) printf("%d ", i);
        printf("\n");
    }
}

int main()
{
    int a[N], n;
    while(scanf("%d", &n))
    {
        psubset(n);
    }
    return 0;
}
