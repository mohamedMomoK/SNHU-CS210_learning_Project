#ifndef FREQUENCY_ANALYZER_H
#define FREQUENCY_ANALYZER_H

#include <string>
#include <map>
// first create a class that will store the frequence data in a map for any given file, and methods that will return or print all the info.
class FrequencyAnalyzer {
private:
    std::map<std::string, int> frequencyMap;

public:
    FrequencyAnalyzer(std::string fileName);
    int getFrequency(std::string item);
    void printFrequencyList();
    void printHistogram();
    void backupData(std::string backupFileName);
    int getItemCount();
};

#endif // FREQUENCY_ANALYZER_H
