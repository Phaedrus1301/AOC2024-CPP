#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

std::vector<int> split(const std::string& inpArr)
    {
        std::stringstream ss(inpArr);
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
    std::ifstream filestream("input1.txt");
    std::string test( (std::istreambuf_iterator<char>(filestream) ),
                      (std::istreambuf_iterator<char>()         ) );
    std::vector<int> left;
    std::vector<int> right;
    int total { 0 };

    auto nums = split(test);
    for(int i { 0 }; i < nums.size(); i++)
    {
        if(i % 2 == 0)
        {
            left.push_back(nums[i]);
        } else
        {
            right.push_back(nums[i]);
        }
    }

    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());
    std::cout << left.size() << '\n';
    std::cout << right.size() << '\n';

//PART 1 SOLUTION
//    for(int i { 0 }; i < left.size(); i++)
//    {
//        total += std::abs(left[i] - right[i]);
//    }
//    std::cout << total << std::endl;

//PART 2 SOLUTION
    for(int i { 0 }; i < left.size(); i++)
    {
        int counter { 0 };
        for(int j { 0 }; j < right.size(); j++)
        {
            if(left[i] == right[j])
            {
                counter += 1;
            }
        }
        total += (left[i] * counter);
    }
    std::cout << total << std::endl;

    return 0;
}
