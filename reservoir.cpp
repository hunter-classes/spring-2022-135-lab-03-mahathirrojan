#include <iostream> 
#include <cstdlib> 
#include <climits> 
#include <string> 
#include <fstream> 

double get_east_storage(std::string date){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if(fin.fail()){
        std::cerr << "File cannot be opened for reading" << std::endl; 
        exit(1); 
    }

    std::string junk; 
    getline(fin, junk); 

    std::string date_tsv, eastSt, eastEl, westSt, westEl; 
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl){
        fin.ignore(INT_MAX, '\n');
        std::cout << date << " " << eastSt << std::endl;
    }
    if(date_tsv.compare(date) == 0){
        fin.close(); 
    }
    return std::stod(eastSt);

}