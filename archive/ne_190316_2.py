'''
题目描述
假设有一沓卡片，每张卡片上写着一个字符
我们重复以下步骤:
 a.取出最顶上的一张卡牌，抛弃
 b.如果剩余卡牌数量是偶数，则翻转整沓卡牌
 c.把此时最顶上的一张卡牌，放到这省卡片最后
一直重复此步骤直到手中没有扑克牌
例如abccd的抛弃顺序为acbdc
现在给出抛弃顺序，求原先的顺序
'''

s = input().strip()[::-1]
ret = list()
for c in s[:-1]:
    ret.insert(0, c)
    ret.insert(0, ret[-1])
    ret = ret[:-1]
    if len(ret) % 2 == 0:
        ret = ret[::-1]
print(s[-1] + (''.join(ret)))
