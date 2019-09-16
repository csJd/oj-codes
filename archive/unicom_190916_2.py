"""
试题描述:在日常消费中，超市收营员在结算后经常遇到需要给顾客找零的情况。为了
节省人力，我们需要编写一一个程序，要求输入顾客应付金额和实付金额，系统给出合适
的找零方案。
输入:输入应付金额和实付金额
输出:输出合适的找零方案(注意最后要输出一个分号，所有输出都是英文半角状态，
余额保留1位小数)

26.5 50
>> 23.5 10:2;1:3;0.5:1;

27 50
>> 23.0 10:2;1:3;
"""


from math import floor

price, pay = map(float, input().split())
repay = pay - price

moneys = [100, 50, 10, 5, 1, 0.5, 0.1]
ans = '%.1f ' % repay
for money in moneys:
    if repay >= money:
        cnt = floor(repay / money)
        repay -= cnt*money
        if money > 0.5:
            ans += "%.0f:%d" % (money, cnt)
        else:
            ans += "%.1f:%d" % (money, cnt)
        ans += ';'

print(ans)
