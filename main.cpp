#include <iostream>
#include <unistd.h>
#include "FrequencyAnalyzer.h"

void menu(FrequencyAnalyzer analyzer) {
    std::cout << "Number of items: " << analyzer.getItemCount() << std::endl;
    std::cout << "Menu Options:" << std::endl;
    std::cout << "1. Look up item frequency" << std::endl;
    std::cout << "2. Print frequency list" << std::endl;
    std::cout << "3. Print histogram" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}


int main() {
    //creatig the path for the file in the currrent dirrectory
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        std::string current_directory(cwd);
        std::string input_file_path = current_directory + "/CornerGrocer/CS210_Project_Three_Input_File.txt";
        std::string output_file_path = current_directory + "/CornerGrocer/frequency.dat";

        FrequencyAnalyzer analyzer = FrequencyAnalyzer(input_file_path);
        int choice;
        std::string item;
        //code main logic
        while (true) {
            menu(analyzer);
            std::cin >> choice;
            switch (choice) {
                case 1:
                    std::cout << "Enter item to look up: ";
                    std::cin >> item;
                    if(analyzer.getFrequency(item)==-1){
                        std::cout <<item<< " is not in file"<<std::endl;
                        continue;
                    }else{
                        std::cout << "Frequency of " << item << ": " << analyzer.getFrequency(item) << std::endl;
                    }
                    break;
                case 2:
                    analyzer.printFrequencyList();
                    break;
                case 3:
                    analyzer.printHistogram();
                    break;
                case 4:
                    analyzer.backupData(output_file_path);
                    std::cout << "Exiting program..." << std::endl;
                    return 0;
                default:
                    std::cout << "Invalid choice. Please enter a number between 1 and 4." << std::endl;
            }
        }

    } else {
        std::cerr << "getcwd() error" << std::endl;
        return 1;
    }
    return 0;

}
