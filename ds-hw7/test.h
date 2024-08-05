#ifndef TEST_H
#define TEST_H
#include <iostream>
#include <vector>
#include <algorithm>
class Test
{
public:
    template <typename T>
    int QuickSelect(std::vector<T> data, int rank)
    {
        for (int lo = 0, hi = data.size() - 1; lo < hi;)
        {
            int i = lo, j = hi; // 目前要操作的区间
            T pivot = data[lo]; // 选取区间第一个数据作为划分依据
            while (i < j)       // 将小于划分依据的全放左边，大于划分依据的全放右边
            {
                while (i < j && data[j] >= pivot)
                    j--;
                data[i] = data[j];
                while (i < j && data[i] <= pivot)
                    i++;
                data[j] = data[i];
            }
            data[i] = pivot; // 再将作为划分依据的数据放到它对应顺序的位置
            if (rank <= i)
            { // 若rank比作为划分依据的数据所在的位置小
                hi -= 1;
            }
            if (rank >= i)
            { // 若rank比作为划分依据的数据所在的位置大
                lo += 1;
            }
        }
        return data[rank - 1];
    }
    template <typename T>
    int LinearSelect(std::vector<T> data, int rank, int Q)
    {
        if (data.size() <= Q)
        {
            return trivialSelect(data, rank);
        }
        else
        {
            // 把data分为n/Q个子序列并对将每个子序列的中位数拿出
            std::vector<T> allMedians;
            for (int i = 0; i < data.size(); i += Q)
            {
                if (i + Q < data.size()) // 剩下数据还够一个Q的大小
                {
                    sort(data.begin() + i, data.begin() + i + Q);
                    allMedians.push_back(data[i + Q / 2]);
                }
                else // 剩下数据不够一个Q的大小
                {
                    sort(data.begin() + i, data.end());
                    allMedians.push_back(data[i + (data.end() - (data.begin() + i)) / 2]);
                }
            }
            // 得到中位数的中位数作为划分依据（pivot）
            int divideDependency = LinearSelect(allMedians, allMedians.size() / 2, Q);
            // 将小于 pivot 的元素移到左侧，大于 pivot 的元素移到右侧
            auto left_end = std::partition(data.begin(), data.end(), [divideDependency](int x)
                                           { return x < divideDependency; });
            // 将等于 pivot 的元素移到中间
            auto right_end = std::partition(left_end, data.end(), [divideDependency](int x)
                                            { return x == divideDependency; });
            if (rank <= left_end - data.begin())
            {
                // 在L部分，继续递归
                std::vector<int> newVec(data.begin(), left_end);
                return LinearSelect(newVec, rank, Q);
            }
            else if (rank <= right_end - data.begin())
            {
                // 在M部分
                return divideDependency;
            }
            else
            { // 在 R部分，继续递归
                std::vector<int> newVec(right_end, data.end());
                return LinearSelect(newVec, rank - (right_end - data.begin()), Q);
            }
        }
    }

    template <typename T>
    int trivialSelect(std::vector<T> data, int rank)
    { // 用冒泡排序处理序列小于Q的基本情况
        int n = data.size();
        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = 0; j < n - i - 1; ++j)
            {
                if (data[j] > data[j + 1])
                {
                    std::swap(data[j], data[j + 1]);
                }
            }
        }
        return data[rank - 1];
    }
};

#endif
