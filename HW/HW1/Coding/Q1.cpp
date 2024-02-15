#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

bool On1(vector<int> v) {
    std::unordered_set<int> nums;
    bool hasNonZero = false;
    bool has12Num = false;
    
    for (int num : v) {
        if (num%12 == 0)
            has12Num = true;
        else if (num != 0)
            hasNonZero = true;

        if (hasNonZero && has12Num)
            return true;

        if (num % 3 == 0) {
            if (nums.find(num / 3) != nums.end())
                return true;
            if (nums.find(num / 4) != nums.end()) 
                return true;
        }
        nums.insert(num);
    }
    
    return false;
}

bool On2(vector<int> v) {
    for (int i = 0;i < v.size();++i) 
        for (int j = i+1;j < v.size();++j) 
            if (v[i] * v[j] % 12 == 0)
                return true;
    return false;
}

int main() {
    cout << On1(vector<int> {12,1,1,1,1}) << endl;
    return 0;
}