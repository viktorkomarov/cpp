#include <iostream>
#include <cstdint>
#include <vector>

struct Block
{
    uint64_t w = 0;
    uint64_t h = 0;
    uint64_t d = 0;
 
    uint64_t Volume(uint64_t r) {
        return r * w * h * d;
    }
};


int main() {
    uint64_t N, R;
    std::cin >> N >> R;

    std::vector<Block> blocks;
    for(uint64_t i = 0; i < N; ++i){
        Block block;
        std::cin >> block.w >> block.h >> block.d;
        blocks.push_back(block);
    }

    uint64_t sum = 0;
    for(auto& block : blocks) {
        sum += block.Volume(R);
    }
    std::cout << sum << std::endl;
    return 0;
}