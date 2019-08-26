/*
https://www.nowcoder.com/practice/4060ac7e3e404ad1a894ef3e17650423

题目描述
请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/

#include <cstring>
#include <cstdio>
using namespace std;

class Solution
{
public:
    void replaceSpace(char *str, int length)
    {
        if (str == NULL || length <= 0)
        {
            return;
        }
        int n_spaces = 0;
        for (int i = 0; str[i] != 0; ++i)
        {
            if (str[i] == ' ')
            {
                ++n_spaces;
            }
        }
        int old_length = strlen(str);
        int new_length = old_length + 2 * n_spaces;
        if (new_length > length)
        {
            return;
        }

        str[new_length] = '\0';
        for (int j = new_length - 1, i = old_length - 1; i >= 0; --i, --j)
        {
            if (str[i] == ' ')
            {
                j -= 2;
                strncpy(str + j, "%20", 3);
            }
            else
            {
                str[j] = str[i];
            }
        }
    }
};

int main(){
    Solution solu;
    char s[] = "123 45  ";
    s[6] = '\0';
    solu.replaceSpace(s, 9);
    printf("'%s'\n", s);
    char s1[] = "";
    solu.replaceSpace(s1, 1);
    printf("'%s'\n", s1);
    char s2[] = " helloworld  ";
    s2[11] = 0;
    solu.replaceSpace(s2, 13);
    printf("'%s'\n", s2);

    return 0;
}
