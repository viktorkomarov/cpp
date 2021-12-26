#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    const std::vector<int> day_per_month = {31, 28, 31,30,31, 30,31,31,30,31,30,31}; 
    int current_month = 0;
    std::vector<std::vector<std::string>> jobs(day_per_month[current_month]);
    while (n--)
    {
        std::string cmd;
        std::cin >> cmd;

        if (cmd == "ADD") {
            int day;
            std::string job;

            std::cin >> day >> job;
            jobs[day-1].push_back(job);
        } else if (cmd == "DUMP") {
            int day;
            std::cin >> day;

            std::cout << jobs[day-1].size();
            for (auto job : jobs[day-1]) std::cout << " " << job;
            std::cout << std::endl;
        } else if (cmd == "NEXT") {
            int new_month = (current_month+1) % day_per_month.size();
            std::vector<std::string> migrate_job;
            if (day_per_month[current_month] > day_per_month[new_month]) {
                for (int i = day_per_month[new_month]; i < day_per_month[current_month]; ++i) {
                    for(auto job : jobs[i]) migrate_job.push_back(job);
                }
            }
            
            current_month = new_month;
            jobs.resize(day_per_month[current_month]);
            if (migrate_job.size() > 0) {
                jobs[jobs.size()-1].insert(end(jobs[jobs.size()-1]), begin(migrate_job), end(migrate_job));
            }
        }
    }

    return 0;
}