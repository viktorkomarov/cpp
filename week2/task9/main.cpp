#include <iostream>
#include <vector>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::vector<bool> worry_queue;
    while (n--)
    {
        std::string cmd;
        std::cin >> cmd;

        if (cmd == "WORRY") {
            int idx;
            std::cin >> idx;

            worry_queue[idx] = true;
        } else if (cmd == "QUIET") {
            int idx;
            std::cin >> idx;

            worry_queue[idx] = false;
        } else if (cmd == "COME") {
            int count;
            std::cin >> count;

            worry_queue.resize(worry_queue.size() + count, false);
        } else if (cmd == "WORRY_COUNT") {
            int count = 0;
            for (auto b : worry_queue) {
                if (b) ++count;
            }
            std::cout << count << std::endl;
        }
    }

    return 0;
}