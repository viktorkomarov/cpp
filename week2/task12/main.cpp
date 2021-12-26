#include <iostream>
#include <map>
#include <string>

int main(){
    int n;
    std::cin >> n;

    std::map<std::string, std::string> capital_by_country;
    while (n--)
    {
        std::string cmd;
        std::cin >> cmd;

        if (cmd == "CHANGE_CAPITAL") {
            std::string country, capital;
            std::cin >> country >> capital;

            if (capital_by_country.count(country) == 0) {
                std::cout << "Introduce new country " << country << " with capital " << capital << std::endl;
            } else if (capital_by_country[country] == capital) {
                std::cout << "Country " << country << " hasn't changed its capital" << std::endl;
            } else {
                std::cout << "Country " << country << " has changed its capital from " << capital_by_country[country]  <<  " to " << capital << std::endl;
            }
            capital_by_country[country] = capital;
        } else if (cmd == "RENAME") {
            std::string old_country, new_country;
            std::cin >> old_country >> new_country;

            if (old_country == new_country || capital_by_country.count(old_country) == 0 || capital_by_country.count(new_country) > 0) {
                std::cout << "Incorrect rename, skip" << std::endl;
            } else {
                std::cout << "Country " << old_country << " with capital " 
                    << capital_by_country[old_country] << " has been renamed to " << new_country << std::endl;
                capital_by_country[new_country] = capital_by_country[old_country];
                capital_by_country.erase(old_country);
            }
            
        } else if (cmd == "ABOUT") {
            std::string country;
            std::cin >> country;

            if (capital_by_country.count(country) == 0){
                std::cout << "Country " << country << " doesn't exist" << std::endl;
            } else {
                std::cout << "Country " << country << " has capital " << capital_by_country[country] << std::endl;
            }
        } else if (cmd == "DUMP") {
            if (capital_by_country.size() == 0) {
                std::cout << "There are no countries in the world" << std::endl;
            } else {
                for(const auto& str : capital_by_country) {
                    std::cout << str.first << "/" << str.second << " ";
                }
                std::cout << std::endl;
            }
        }
    }
    
    return 0;
}