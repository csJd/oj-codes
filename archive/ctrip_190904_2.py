"""
AUC计算
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
ROC-AUC是一种常用的模型评价指标，它是ROC曲线下的面积。现在已知样本数据集的真实值(1为正样本，0为负样本)和某二分类器在该样本数据集上的预测值（属于正样本的概率，且各不相同），求ROC-AUC，精确到小数点后两位。

输入
第1行为训练样本的数量N。

第2到N+1行的每行为样本的实际类别与预测值，以空格分隔。

输出
计算ROC-AUC，精确到小数点后两位。


样例输入
10
1 0.90
0 0.70
1 0.60
1 0.55
0 0.52
1 0.40
0 0.38
0 0.35
1 0.31
0 0.10
样例输出
0.68

提示
可以按定义计算，也可以计算随机挑选一对正负样本，正样本的预测值大于负样本的预测值的概率。
"""


def main():
    pos_list = list()
    neg_list = list()
    n = int(input())
    for line in range(n):
        y, p = input().split()
        if y == '1':
            pos_list.append(float(p))
        else:
            neg_list.append(float(p))

    pos_list.sort()
    neg_list.sort()
    i = 0
    j = 0
    auc = 0
    n_pos = len(pos_list)
    n_neg = len(neg_list)
    if n_pos == 0:
        auc = 0
    elif n_neg == 0:
        auc = 1
    else:
        while i < n_pos:
            if j < n_neg and pos_list[i] > neg_list[j]:
                j += 1
            else:
                auc += 1/n_pos * j/n_neg
                i += 1

    print("%.2f" % auc)


if __name__ == "__main__":
    main()
