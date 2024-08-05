#include <iostream>
#include <vector>
#include "test.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>
#include <chrono>
int main()
{
    std::vector<int> smallArray;
    std::vector<int> middleArray;
    std::vector<int> bigArray;
    for (int i = 0; i < 10; i++)
    {
        smallArray.push_back(i);
    }
    for (int i = 0; i < 1000; i++)
    {
        middleArray.push_back(i);
    }
    for (int i = 0; i < 10000; i++)
    {
        bigArray.push_back(i);
    }
    Test test;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::random_device rd;
    std::mt19937 gen(rd());

    for (int i = 0; i < 3; i++)
    {
        if (i == 0)
        {
            std::chrono::microseconds quickSelectsum0(0);
            std::chrono::microseconds linearSelectSum0(0);

            for (int i = 0; i < 10000; i++)
            {
                int randNumber = rand() % 10;
                auto start = std::chrono::high_resolution_clock::now();
                test.QuickSelect(smallArray, randNumber);
                auto end = std::chrono::high_resolution_clock::now();
                quickSelectsum0 += std::chrono::duration_cast<std::chrono::microseconds>(end - start);

                start = std::chrono::high_resolution_clock::now();
                test.LinearSelect(smallArray, randNumber, 5);
                end = std::chrono::high_resolution_clock::now();
                linearSelectSum0 += std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            }
            std::cout << "quick-smallArray-order: " << (quickSelectsum0.count() / 10000.00000) << std::endl;
            std::cout << "linear-smallArray-order: " << (linearSelectSum0.count() / 10000.00000) << std::endl;
        }
        else if (i == 1)
        {
            std::chrono::microseconds quickSelectsum0(0);
            std::chrono::microseconds linearSelectSum0(0);
            for (int i = 0; i < 10000; i++)
            {
                int randNumber = rand() % 1000;
                auto start = std::chrono::high_resolution_clock::now();
                test.QuickSelect(middleArray, randNumber);
                auto end = std::chrono::high_resolution_clock::now();
                quickSelectsum0 += std::chrono::duration_cast<std::chrono::microseconds>(end - start);

                start = std::chrono::high_resolution_clock::now();
                test.LinearSelect(middleArray, randNumber, 5);
                end = std::chrono::high_resolution_clock::now();
                linearSelectSum0 += std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            }
            std::cout << "quick-middleArray-order: " << (quickSelectsum0.count() / 10000.00000) << std::endl;
            std::cout << "linear-middleArray-order: " << (linearSelectSum0.count() / 10000.00000) << std::endl;
        }
        else
        {
            std::chrono::microseconds quickSelectsum0(0);
            std::chrono::microseconds linearSelectSum0(0);
            for (int i = 0; i < 10000; i++)
            {
                int randomNumber = rand() % 10000;
                auto start = std::chrono::high_resolution_clock::now();
                test.QuickSelect(bigArray, randomNumber);
                auto end = std::chrono::high_resolution_clock::now();
                quickSelectsum0 += std::chrono::duration_cast<std::chrono::microseconds>(end - start);

                start = std::chrono::high_resolution_clock::now();
                test.LinearSelect(bigArray, randomNumber, 5);
                end = std::chrono::high_resolution_clock::now();
                linearSelectSum0 += std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            }
            std::cout << "quick-bigArray-order: " << (quickSelectsum0.count() / 10000.00000) << std::endl;
            std::cout << "linear-bigArray-order: " << (linearSelectSum0.count() / 10000.00000) << std::endl;
        }
    }
    std::shuffle(smallArray.begin(), smallArray.end(), gen);
    std::shuffle(middleArray.begin(), middleArray.end(), gen);
    std::shuffle(bigArray.begin(), bigArray.end(), gen);

    for (int i = 0; i < 3; i++)
    {
        if (i == 0)
        {
            std::chrono::microseconds quickSelectsum0(0);
            std::chrono::microseconds linearSelectSum0(0);

            for (int i = 0; i < 10000; i++)
            {
                int randNumber = rand() % 10;
                auto start = std::chrono::high_resolution_clock::now();
                test.QuickSelect(smallArray, randNumber);
                auto end = std::chrono::high_resolution_clock::now();
                quickSelectsum0 += std::chrono::duration_cast<std::chrono::microseconds>(end - start);

                start = std::chrono::high_resolution_clock::now();
                test.LinearSelect(smallArray, randNumber, 5);
                end = std::chrono::high_resolution_clock::now();
                linearSelectSum0 += std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            }
            std::cout << "quick-smallArray-suffle: " << (quickSelectsum0.count() / 10000.00000) << std::endl;
            std::cout << "linear-smallArray-suffle: " << (linearSelectSum0.count() / 10000.00000) << std::endl;
        }
        else if (i == 1)
        {
            std::chrono::microseconds quickSelectsum0(0);
            std::chrono::microseconds linearSelectSum0(0);
            for (int i = 0; i < 10000; i++)
            {
                int randNumber = rand() % 1000;
                auto start = std::chrono::high_resolution_clock::now();
                test.QuickSelect(middleArray, randNumber);
                auto end = std::chrono::high_resolution_clock::now();
                quickSelectsum0 += std::chrono::duration_cast<std::chrono::microseconds>(end - start);

                start = std::chrono::high_resolution_clock::now();
                test.LinearSelect(middleArray, randNumber, 5);
                end = std::chrono::high_resolution_clock::now();
                linearSelectSum0 += std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            }
            std::cout << "quick-middleArray-suffle: " << (quickSelectsum0.count() / 10000.00000) << std::endl;
            std::cout << "linear-middleArray-suffle: " << (linearSelectSum0.count() / 10000.00000) << std::endl;
        }
        else
        {
            std::chrono::microseconds quickSelectsum0(0);
            std::chrono::microseconds linearSelectSum0(0);
            for (int i = 0; i < 10000; i++)
            {
                int randomNumber = rand() % 10000;
                auto start = std::chrono::high_resolution_clock::now();
                test.QuickSelect(bigArray, randomNumber);
                auto end = std::chrono::high_resolution_clock::now();
                quickSelectsum0 += std::chrono::duration_cast<std::chrono::microseconds>(end - start);

                start = std::chrono::high_resolution_clock::now();
                test.LinearSelect(bigArray, randomNumber, 5);
                end = std::chrono::high_resolution_clock::now();
                linearSelectSum0 += std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            }
            std::cout << "quick-bigArray-suffle: " << (quickSelectsum0.count() / 10000.00000) << std::endl;
            std::cout << "linear-bigArray-suffle: " << (linearSelectSum0.count() / 10000.00000) << std::endl;
        }
    }

    for (int i = 3; i < 50; i += 2)
    {
        std::chrono::microseconds linearSelectSum0(0);
        for (int j = 0; j < 10000; j++)
        {

            int randomNumber = rand() % 1000;
            auto start = std::chrono::high_resolution_clock::now();
            test.LinearSelect(middleArray, randomNumber, i);
            auto end = std::chrono::high_resolution_clock::now();
            linearSelectSum0 += std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        }
        std::cout << "linear-middleArray-Q=" << i << ":" << linearSelectSum0.count() / 10000.00000 << std::endl;
    }
}