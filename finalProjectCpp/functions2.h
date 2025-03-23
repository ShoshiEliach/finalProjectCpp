#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <tuple>
#include "node.h"
#include <unordered_map>
#include <sstream>
#include <utility>
#include <unordered_set>
#include <algorithm>
#include <map>
#include <tuple>
#include <list>
#include"nodesManager.h"
class functions2
{
public:
    void parsePythonList(const std::vector<std::tuple<int, int, int>>& edges, nodesManager& nm);
    void read_graph(nodesManager& nm);
    void process_graph_data(std::pair<char, std::tuple<int, int, int>>* data, int size_d, nodesManager& nm);




    std::vector<std::string> findStlParallels(const std::string& input, const std::vector<std::string>& strings) {
        std::vector<std::string> equalStrings;

        for (const auto& str : strings) {
            if (checkStParallels(input, str)) {
                equalStrings.push_back(str);
            }
        }

        return equalStrings;
    }
    bool checkStParallels(const std::string& str1, const std::string& str2) {
        // Check if both strings are of length 2
        if (str1.length() != 2 || str2.length() != 2) {
            return false;
        }

        // Extract character and number from both strings
        char char1 = std::toupper(str1[0]);
        char char2 = std::toupper(str2[0]);
        int num1 = str1[1] - '0';
        int num2 = str2[1] - '0';

        // Check conditions: character is equal or number is equal with character 2 apart
        if (char1 == char2 || (num1 == num2 && std::abs(char1 - char2) == 2)) {
            return true;
        }

        return false;
    }
    std::string changeDieNumber(const std::string& dieString) {
        if (dieString.size() != 2) {
            return ""; // Return empty string for invalid input
        }

        char die = dieString[0];
        char number = dieString[1];

        if (number == '1') {
            number = '2';
        }
        else if (number == '2') {
            number = '1';
        }

        return std::string(1, die) + number;
    }
};





