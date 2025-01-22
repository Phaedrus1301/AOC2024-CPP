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

bool checkVect(std::vector<int> someVector)
{
    int diff { 0 };
    for(int i = 0; i < someVector.size() - 1; i++)
    {
        diff = std::abs(someVector[i] - someVector[i + 1]);
        if(diff > 0 && diff < 4)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
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
                    safetyFlag = false;
                    break;
                }
            }
            if(safetyFlag)
            {
                counter += 1;
                safetyFlag = false;
            }
        }
        else
        {
            for(auto lvl: levels)
            {
                std::cout << lvl << " ";
            }
            std::cout << std::endl;
            bool once { false };
            for(int i { 0 }; i < (levels.size() - 1); i++)
            {
                diff = levels[i] - levels[i + 1];
                if((diff > 0 && diff < 4)||(diff > -4 && diff < 0))
                {
                    safetyFlag = true;
                }
                else
                {
                    std::cout << "diff mismatch " << levels[i] << " " << levels[i+1] << std::endl;
                    if(once)
                    {
                        safetyFlag = false;
                        break;
                    }
                    once = true;
                }
            }
            once = false;
            if(safetyFlag)
            {
                counter += 1;
            }
        }
        total += 1;
    }
    std::cout << "Total reports: " << total << std::endl;
    std::cout << "Safe reports: " << counter << std::endl;

    return 0;
}
