#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int a[N], b[N];

int main()
{
    int i, n;
    while(~scanf("%d", &n), n)
    {
        for(i = 0; i < n; ++i)
            scanf("%d %d", &a[i], &b[i]);
        sort(a, a + n);
        sort(b, b + n);
        for(i = 0; i < n; ++i)
            if(a[i] != b[i]) break;
        if(i < n) puts("NO");
        else puts("YES");
    }
    return 0;
}

//#include <bits/stdc++.h>
//using namespace std;
//map<int, int> m;
//int main()
//{
//    int a, b, n;
//    while(~scanf("%d", &n), n)
//    {
//        m.clear();
//        for(int i = 0; i < n; ++i)
//        {
//            scanf("%d%d", &a, &b);
//            if(m.count(b) && m[b] == a) m.erase(b);
//            else m.insert(make_pair(a, b));
//        }
//        if(m.empty()) puts("YES");
//        else puts("NO");
//    }
//    return 0;
//}
