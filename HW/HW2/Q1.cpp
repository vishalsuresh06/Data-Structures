#include <list>
#include <iostream>
#include <unordered_set>

std::list<int> intersection(const std::list<int>& l1,
                            const std::list<int>& l2) {
    std::unordered_set<int> l1Set;
    std::list<int> result;

    for (int i : l1) 
        l1Set.insert(i);

    for (int i : l2)
        if (l1Set.count(i) == 1)
            result.push_back(i);

    return result;
}

int main() {
    std::list<int> l1 = {2,9,11};
    std::list<int> l2 = {11,7,15};
    std::list<int> result = intersection(l1, l2);

    for (int i : result)
        std::cout << i << " " << std::endl;
    return 0;
}