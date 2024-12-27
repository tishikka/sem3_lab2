#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>



auto comp = [](const std::vector<std::string>& a, const std::vector<std::string>& b) -> bool {
    for (size_t i = 0; i < 4; ++i) { // Сравниваем только первые 4 части (байты)
        int partA = std::stoi(a[i]);
        int partB = std::stoi(b[i]);
        if (partA != partB) {
            return partA < partB; // Сортировка по возрастанию
        }
    }
    return false; 
};

