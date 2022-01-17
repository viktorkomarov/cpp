#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
  
    std::vector<int> nums(n);
    for (size_t i = 0; i < nums.size(); ++i) nums[i] = i+1;

    std::vector<std::vector<int>> num_of_nums;
    do{
        num_of_nums.push_back({begin(nums), end(nums)});
    }while(std::next_permutation(begin(nums), end(nums)));

    std::sort(rbegin(num_of_nums), rend(num_of_nums));

    for(const auto& nums : num_of_nums) 
    {
        bool first = true;
        for (int n : nums){
            if (!first) {
                std::cout << " ";
            }
            first = false;
            std::cout << n;
        }
        std::cout << std::endl;
    }
}