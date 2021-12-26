#include <vector>

void Reverse(std::vector<int>& v){
    int l = 0, r = v.size()-1;
    while (l < r)
    {
        int temp = v[l];
        v[l] = v[r];
        v[r] = temp;
        l++;
        r--;
    }
}