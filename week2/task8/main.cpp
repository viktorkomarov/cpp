#include <iostream>
#include <vector>

void print_vector(const std::vector<int>& v)
{
    for(auto& item : v) std::cout << item << " ";
    std::cout << std::endl;
}

int main() {
    int n; 
    std::cin >> n;
    std::vector<int> temps(n);
   
    int avg = 0;
    for(int& t : temps){
        std::cin >> t;
        avg += t;
    }
    avg /= temps.size();

    int count = 0;
    std::vector<int> res;
    for (int i = 0; i < temps.size(); ++i) {
        if (temps[i] > avg) {
            ++count;
            res.push_back(i);
        }
    }
    std::cout << count << std::endl;
    print_vector(res);
    return 0;
}