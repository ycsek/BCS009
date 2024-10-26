#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // 定义双层集合
    vector<vector<int>> S = {{1, 3}, {1, 7, 8}, {5, 6}};

    // 遍历双层集合
    for (const auto &subset : S)
    {
        for (int elem : subset)
        {
            cout << elem << " ";
        }
        cout << endl;
    }
    return 0;
}