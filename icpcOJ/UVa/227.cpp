#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 8;
char s[N][N], mov[1000], t;
int r, c;

int main()
{
    int cas = 0;
    while(gets(s[1] + 1) && s[1][1] != 'Z')
    {
        for(int j = 1; j < 6; ++j)
            if(s[1][j] == ' ') r = 1, c = j;
        for(int i = 2; i < 6; ++i)
        {
            gets(s[i] + 1);
            for(int j = 1; j < 6; ++j)
                if(s[i][j] == ' ') r = i, c = j;
        }

        if(cas++) printf("\n");
        printf("Puzzle #%d:\n", cas);

        int win = 1;
        while(gets(mov))
        {
            int i;
            for(i = 0; mov[i]; ++i)
            {
                if(!win) continue;
                t = mov[i];
                if((t == 'A' && r == 1) || (t == 'B' && r == 5)) win = 0;
                if((t == 'L' && c == 1) || (t == 'R' && c == 5)) win = 0;
                if(win)
                {
                    if(t == 'A') swap(s[r][c], s[r - 1][c]), --r;
                    if(t == 'B') swap(s[r][c], s[r + 1][c]), ++r;
                    if(t == 'L') swap(s[r][c], s[r][c - 1]), --c;
                    if(t == 'R') swap(s[r][c], s[r][c + 1]), ++c;
                }
            }
            if(mov[i - 1] == '0') break;
        }

        if(win)
        {
            for(int i = 1; i < 6; ++i)
                for(int j = 1; j < 6; ++j)
                    printf("%c%c", s[i][j], j < 5 ? ' ' : '\n');
        }
        else printf("This puzzle has no final configuration.\n");
    }
    return 0;
}

//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//const int N = 8;
//char s[N][N], mov[1000], t;
//int r, c, l;
//
//bool moved()
//{
//    bool ret = true;
//    int i;
//    while(gets(mov))
//    {
//        for(i = 0; mov[i]; ++i)
//        {
//            if(!ret) continue;
//            t = mov[i];
//            if((t == 'A' && r == 1) || (t == 'B' && r == 5)) ret = 0;
//            if((t == 'L' && c == 1) || (t == 'R' && c == 5)) ret = 0;
//
//            if(ret)
//            {
//                if(t == 'A') swap(s[r][c], s[r - 1][c]), --r;
//                if(t == 'B') swap(s[r][c], s[r + 1][c]), ++r;
//                if(t == 'L') swap(s[r][c], s[r][c - 1]), --c;
//                if(t == 'R') swap(s[r][c], s[r][c + 1]), ++c;
//            }
//        }
//        if(i > 0 && mov[i - 1] == '0') break;
//    }
//    return ret;
//}
//
//int main()
//{
//    int cas = 0;
//    while(gets(s[1] + 1) && s[1][1] != 'Z')
//    {
//        for(int j = 1; j < 6; ++j) if(s[1][j] == ' ') r = 1, c = j;
//        for(int i = 2; i < 6; ++i)
//        {
//            gets(s[i] + 1);
//            for(int j = 1; j < 6; ++j)
//                if(s[i][j] == ' ') r = i, c = j;
//        }
//
//        if(cas++) printf("\n");
//        printf("Puzzle #%d:\n", cas);
//
//        if(moved())
//        {
//            for(int i = 1; i < 6; ++i)
//            {
//                for(int j = 1; j < 5; ++j)
//                    printf("%c ", s[i][j]);
//                printf("%c\n", s[i][5]);
//            }
//        }
//        else printf("This puzzle has no final configuration.\n");
//    }
//    return 0;
//}
