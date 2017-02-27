#include<cstdio>
#include<cstring>
using namespace std;
const int N = 10005;

//增量构造法

//void psubset(int n, int *a, int cur)
//{
//    for(int i = 0; i < cur; ++i) printf("%d ", a[i]);
//    //打印当前集合
//    printf("\n");
///**/int s = cur ? a[cur - 1] + 1 : 0;
//    //定序，确定当前元素最小可能值
//    for(int i = s; i < n; ++i)
//    {
//        a[cur] = i;
//        psubset(n, a, cur + 1);//递归构造子集
//    }
//}


//位向量法

//void psubset(int n, int *b, int cur)
//{
//    if(cur == n)
//    {
//        for(int i = 0; i < cur; ++i)
//            if(b[i]) printf("%d ", i);    //打印当前集合
//        printf("\n");
//        return;
//    }
//    b[cur] = 1;            //选第cur个元素
//    psubset(n, b, cur + 1);
//    b[cur] = 0;            //不选第cur个元素
//    psubset(n, b, cur + 1);
//}


//二进制法

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
