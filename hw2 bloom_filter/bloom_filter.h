#ifndef BLOOM_FILTER_H
#define BLOOM_FILTER_H
#include <iostream>
using namespace std;
#include <vector>
#include <cmath>
class BloomFilter
{
public:
    int k;
    int m;
    int error_time;
    int *elem;
    int n;
    int insert_start;
    int fun_seed;
    void (*hash_fun_arr)(const void *, const int, const uint32_t, void *);
    double error_rate()
    {
        return (double)error_time / 100.000;
    }
    BloomFilter(int n_count, int m_count, int k_count, void (*fun)(const void *, const int, const uint32_t, void *), int seed) : n(n_count), m(m_count), k(k_count), hash_fun_arr(fun), error_time(0)
    {
        elem = new int[m]{0};
        fun_seed = seed;
    }
    void insert(int start)
    {
        insert_start = start;
        int *index = new int[2];
        for (int i = start; i < start + n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                // int val = i + j;
                // hash_fun_arr(&val, sizeof(val), fun_seed, index);
                int val = fun_seed + j * 500;
                hash_fun_arr(&i, sizeof(i), val, index);
                elem[abs(index[1]) % m] = 1;
            }
        }
    }
    void test(int start, int num)
    {
        int *get = new int[k]; // 每一次测试的取值集合
        int *tmp = new int[2];
        bool isAllTri;
        for (int i = start; i < start + num; i++)
        {
            isAllTri = true;
            for (int j = 1; j <= k; j++)
            {
                // int val = i + j;
                // hash_fun_arr(&val, sizeof(val), fun_seed, tmp);

                int val = fun_seed + j * 500;
                hash_fun_arr(&i, sizeof(i), val, tmp);
                get[j - 1] = abs(tmp[1] % m);
            }
            for (int j = 0; j < k; j++)
            {
                if (elem[get[j]] == 0)
                {
                    isAllTri = false;
                    break;
                }
            }
            if (isAllTri)
            {
                error_time++;
            }
        }
    }
    //     bool isExist(int *get)
    //     {
    //         int *insert_arr = new int[k];
    //         int *tmp = new int[2];
    //         bool equal = 0;
    //         for (int i = insert_start; i < insert_start + n; i++)
    //         {
    //             equal = true;
    //             for (int j = 1; j <= k; j++)
    //             {
    //                 int val = i + j;
    //                 hash_fun_arr(&val, sizeof(val), 1, tmp);
    //                 insert_arr[j - 1] = abs(tmp[1] % m);
    //             }
    //             for (int i = 0; i < k; i++)
    //             {
    //                 if (get[i] != insert_arr[i])
    //                 {
    //                     equal = false;
    //                     break;
    //                 }
    //             }
    //             if (equal)
    //             {
    //                 return true;
    //             }
    //         }
    //         return false;
    //     }
};

#endif