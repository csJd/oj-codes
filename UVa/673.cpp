//#include <bits/stdc++.h>
//using namespace std;
//int main()
//{
//    int cas;
//    char c;
//    cin >> cas;
//    getchar();
//    while(cas--)
//    {
//        stack<char> s;
//        while((c = getchar()) != '\n')
//        {
//            if(s.empty()) s.push(c);
//            else  if((c == ')' && s.top() == '(')
//                     || (c == ']' && s.top() == '['))
//                s.pop();
//            else s.push(c);
//        }
//        puts(s.empty() ? "Yes" : "No");
//    }
//    return 0;
//}

#include<cstdio>
using namespace std;
int main()
{
    int cas, top;
    char s[200], c;
    scanf("%d", &cas);
    getchar();
    while(cas--)
    {
        top = 0;
        while((c = getchar()) != '\n')
        {
            if(top == 0) s[top++] = c;
            else if(s[top - 1] == '(' && c == ')'
                    || s[top - 1] == '[' && c == ']')
                --top;
            else s[top++] = c;
        }
        puts(top ? "No" : "Yes");
    }
    return 0;
}
