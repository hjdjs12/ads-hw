#include <iostream>
#include <thread>
using namespace std;
#include <vector>
#include <mutex>
#include <mingw.thread.h>

int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return fib(n - 1) + fib(n - 2);
    }
}

int fibThread(int n, int threadMaxNum, int currentThreadNum)
{
    if (n <= 1)
        return n;
    if (currentThreadNum >= threadMaxNum)
    {
        return fib(n);
    }
    else if (currentThreadNum == threadMaxNum - 1)
    {
        int result;
        std::thread tmp = std::thread([&result, n, currentThreadNum, threadMaxNum]()
                                      { result = fibThread(n - 1, threadMaxNum, currentThreadNum + 1); });
        tmp.join();
        return fib(n - 2) + result;
    }
    else
    {
        std::vector<int> results(2);
        std::thread tmp1 = std::thread([&results, n, currentThreadNum, threadMaxNum]()
                                       { results[0] = fibThread(n - 1, threadMaxNum, currentThreadNum + 2); });
        std::thread tmp2 = std::thread([&results, n, currentThreadNum, threadMaxNum]()
                                       { results[1] = fibThread(n - 2, threadMaxNum, currentThreadNum + 2); });
        tmp1.join();
        tmp2.join();
        return results[0] + results[1];
    }
}
int main()
{
    int n = 40;
    int threadNums[] = {2, 4, 8, 16};

    // Part1：计算并输出第 40 个斐波那契数
    std::cout << "第 " << n << " 个斐波那契数为：" << fib(n) << std::endl;
    // Part2：计算加速比并输出结果
    std::cout << "Part2：计算加速比" << std::endl;
    for (int num : threadNums)
    {
        double totalTimeSingleThread = 0.0;
        double totalTimeMultiThread = 0.0;
        int iterations = 10; // 进行 10 次测试取平均值

        // 单线程计算斐波那契数的耗时
        for (int i = 0; i < iterations; ++i)
        {
            auto start = std::chrono::high_resolution_clock::now();
            fib(n);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = end - start;
            totalTimeSingleThread += duration.count();
        }

        // 多线程计算斐波那契数的耗时
        for (int i = 0; i < iterations; ++i)
        {
            auto start = std::chrono::high_resolution_clock::now();
            fibThread(n, num, 0);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = end - start;
            totalTimeMultiThread += duration.count();
        }

        // 计算加速比
        double speedup = totalTimeMultiThread / totalTimeSingleThread;

        std::cout << "线程数为 " << num << " 时，加速比为：" << speedup << std::endl;
    }

    return 0;
}