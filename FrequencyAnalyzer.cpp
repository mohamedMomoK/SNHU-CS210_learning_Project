#include <fstream>
#include <iostream> 
#include <stdexcept>
#include <sstream>
#include <iterator>
#include "FrequencyAnalyzer.h"

//first create class to manage the frequency
FrequencyAnalyzer::FrequencyAnalyzer(std::string fileName) {
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        throw std::runtime_error("Failed to open input file");
    }

    // Read the entire file into a buffer
    std::stringstream buffer;
    buffer << inputFile.rdbuf();

    // Use of a istream_iterator to split the string into lines
    std::istream_iterator<std::string> begin(buffer);
    std::istream_iterator<std::string> end;

    for (std::istream_iterator<std::string> it = begin; it != end; ++it) {
        frequencyMap[*it]++;
    }
    inputFile.close();
}


int FrequencyAnalyzer::getFrequency(std::string item) {
     auto it = frequencyMap.find(item);
    if (it != frequencyMap.end()) {
        return frequencyMap[item];
    } else {
        return -1;
    }
}

void FrequencyAnalyzer::printFrequencyList() {
    for (std::pair<std::string, int> pair : frequencyMap) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
}

void FrequencyAnalyzer::printHistogram() {
    for (std::pair<std::string, int> pair : frequencyMap) {
        std::cout << pair.first << " ";
        std::cout << std::string(pair.second, '*') << std::endl;
    }
}

void FrequencyAnalyzer::backupData(std::string backupFileName) {
    std::ofstream outputFile(backupFileName);
    if (!outputFile.is_open()) {
            throw std::runtime_error("Failed to open output file");
        }
    for (std::pair<std::string, int> pair : frequencyMap) {
        outputFile << pair.first << " " << pair.second << std::endl;
    }
    outputFile.close();
}
int FrequencyAnalyzer::getItemCount() {
        return frequencyMap.size();
}