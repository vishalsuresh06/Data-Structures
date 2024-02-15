#include <vector>
#include <iostream>

using namespace std;
int num_comp = 0;

int Binary_Search(vector<int> &v, int x) { 
    int mid, low = 0;
    int high = (int) v.size()-1;
    while (low < high) {
        mid = (low+high)/2;
        if (num_comp++, v[mid] < x) 
            low = mid+1; 
        else 
            high = mid;
    }
    if (num_comp++, x == v[low]) return low; //OK: found return -1; //not found
    return -1;
}

int main() {
    vector<int> arr;
    int n = 2047;
    for(int i = 1;i <= n;++i)
        arr.push_back(i);
    cout << Binary_Search(arr, n) << "\n" << num_comp << endl;
    return 0;
}