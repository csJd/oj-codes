#include <cstdio>
#include <cstring>
using namespace std;
const int N = 10000000;
char t[N], s[N];
char a[N] = {"-_=+qQwWeErRtTyYuUiIoOpP[{]}\\|aAsSdDfFgGhHjJkKlL;:\'\"zZxXcCvVbBnNmM,<.>/?"};
char b[N] = {"[{]}\'\",<.>pPyYfFgGcCrRlL/?=+\\|aAoOeEuUiIdDhHtTnNsS-_;:qQjJkKxXbBmMwWvVzZ"};
int main()
{
    memset(t, 0, sizeof(t));
    for(int i = 0; a[i]; ++i) t[a[i]] = b[i];
    while(gets(s) != NULL)
    {
        for(int i = 0; s[i] ; ++i)
            printf("%c", t[s[i]] ? t[s[i]] : s[i]);
        puts("");
    }
    return 0;
}
//Last modified :   2015-04-25 14:21



