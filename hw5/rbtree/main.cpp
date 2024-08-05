#include <iostream>
#include "rbtree.h"
#include <cstdlib>
#include <ctime>
void shuffle(int arr[], int size) {
    srand(time(NULL)); // 初始化随机种子
    for (int i = size - 1; i > 0; --i) {
        // 生成一个小于等于当前下标的随机数
        int j = rand() % (i + 1);
        // 将当前元素与随机下标对应的元素进行交换
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
int main() {
    RedBlackTree tree;
//
//    tree.insert(7);
//    tree.insert(3);
//    tree.insert(18);
//    tree.insert(10);
//    tree.insert(22);
//    tree.insert(8);
//    tree.insert(11);
//    tree.insert(26);
int element[10000];
for(int i = 1; i <= 10000; i++){
    element[i-1] = i;
}
for(int i = 0; i < 10000; i++){
    tree.insert(element[i]);
}
std::cout <<"fixTime:"<< tree.fixTime << " RotationTime:" << tree.rotationTime << "  ColorChangeTime:" << tree.colorChangeTime;

//    std::cout << "Inorder traversal of the constructed tree: \n";
//    tree.inorder();
//    std::cout << std::endl;

    return 0;
}
