#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

std::vector<int> split(const std::string& inpoot)
{
    std::stringstream ss(inpoot);
    std::vector<int> words;
    for(std::string w; ss>>w;)
    {
        int n = std::stoi(w);
        words.push_back(n);
    }
    return words;
}

int main()
{

//PART 1 SOLUTION -
//    std::ifstream filestream("input.txt");
//    std::string floor;
//    int total { 0 };
//    int counter { 0 };
//    while(std::getline(filestream, floor))
//    {
//        auto levels = split(floor);
//        std::vector<int> ascendingcopy ( levels );
//        std::vector<int> descendingcopy ( levels );
//        std::sort(ascendingcopy.begin(), ascendingcopy.end());
//        std::sort(descendingcopy.begin(), descendingcopy.end(), std::greater<>());
//        int diff { 0 } ;
//        bool flag { false };
//
//        if(levels == descendingcopy || levels == ascendingcopy)
//        {
//            for(int i { 1 }; i < levels.size(); i++)
//            {
//                diff = std::abs(levels[i] - levels[i - 1]);
//                if(diff > 0 && diff < 4)
//                {
//                    flag = true;
//                }
//                else
//                {
//                    flag = false;
//                    break;
//                }
//            }
//            if(flag)
//            {
//                counter += 1;
//            }
//        }
//        total += 1;
//    }
//    std::cout << "Total reports: " << total << std::endl;
//    std::cout << "Safe reports: " << counter << std::endl;

//PART 2 SOLUTION -
    std::ifstream filestream("input.txt");
    std::string floor;
    int total { 0 };
    int counter { 0 };

    while(std::getline(filestream, floor))
    {
        auto levels = split(floor);
        std::vector<int> ascendingcopy ( levels );
        std::vector<int> descendingcopy ( levels );
        std::sort(ascendingcopy.begin(), ascendingcopy.end());
        std::sort(descendingcopy.begin(), descendingcopy.end(), std::greater<>());
        int diff { 0 } ;
        bool safetyFlag { false };

        if(levels == descendingcopy || levels == ascendingcopy)
        {
            for(int i { 0 }; i < (levels.size() - 1); i++)
            {
                diff = std::abs(levels[i] - levels[i + 1]);
                if(diff > 0 && diff < 4)
                {
                    safetyFlag = true;
                }
                else
                {
//                    for(auto lvl: levels)
//                    {
//                        std::cout << lvl << " ";
//                    }
//                    std::cout << std::endl;
                    //since we're in a sorted list if else, we only need to worry about below 2 conditions.
                    //diff being greater than 4 or less than 1
                    //numbers repeating
                    //66 60 59 58 51 48 45 42
                    //72 76 79 80 83 85 87 90
                    //22 20 15 14 12 7
                    //41 41 42 44 49 51 51
                    //both of these should be allowed only once. if it repeats then break.
                    int repeater { 0 };

                    repeater += 1;

                    if(repeater != 1)
                    {
                        safetyFlag = false;
                        break;
                    }
                }
            }
            if(safetyFlag)
            {
                counter += 1;
            }
        }
        else
        {
            for(auto lvl: levels)
            {
                std::cout << lvl << " ";
            }
            std::cout << std::endl;
        }
        total += 1;
    }
    std::cout << "Total reports: " << total << std::endl;
    std::cout << "Safe reports: " << counter << std::endl;

    return 0;
}
