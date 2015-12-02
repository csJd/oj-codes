#include<cstdio>
char s[][15] = {"      *", "     * *", "* * * * * * *", " * *     * *", "  *       *"};
int main()
{
    for(int i = 0; i < 5; ++i) printf("%s\n", s[i]);
    for(int i = 3; i >= 0; --i) printf("%s\n", s[i]);
    return 0;
}
