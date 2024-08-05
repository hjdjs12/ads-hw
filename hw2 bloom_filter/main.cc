#include <iostream>
#include "MurmurHash3.h"
#include "bloom_filter.h"
#include <iomanip>

int main()
{
    // uint64_t key = 522123456789;
    // uint64_t hash[2] = {0};

    // MurmurHash3_x64_128(&key, sizeof(key), 1, hash);
    int n = 100;
    int m = 200;
    int k = 1;
    double total = 0;
    for (int seed = 0; seed < 10000; seed++)
    {

        BloomFilter *bloomFilter = new BloomFilter(n, m, k, MurmurHash3_x64_128, seed);
        bloomFilter->insert(0);
        bloomFilter->test(100, 100);
        total += bloomFilter->error_rate();
    }
    std::cout << "k = " << k << ", m = " << m << " rate = " << total / 10000.000;

    // std::cout << "Hash value: ";
    // for (int i = 0; i < 2; i++)
    // {
    //     std::cout << hash[i] << " ";
    // }
    // std::cout << std::endl;
    // // mod m-1
    // // only use hash[1]
    // int m = 100;
    // std::cout << hash[1] % (m - 1) << " ";

    return 0;
}
