#include <vector>
#include <iostream>

int find_max_value(int i, int size, std::vector<int> v) {
    if (i == size-1)
        return v[i];
    return std::max(v[i], find_max_value(i+1, size, v));
}

int main() {
    std::vector<int> v;
    for (int i = 1;i <= 5;++i)
        v.push_back(i);
    v.insert(v.begin()+2, 100);
    int len = 5;
    std::cout << find_max_value(0, len, v) << std::endl;
    return 0;
}