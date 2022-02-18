#include "reverseorder.h"
#include <iostream>
#include <fstream> 
#include <climits> 
#include <array> 
#include <string> 


void reverse_order(std::string date1, std::string date2){
    int const LENGTH = 365; 

    std::ifstream fin("Current_Reservoir_Levels.tsv"); 
    if(fin.fail()){
        std::cerr << "File cannot be opened for reading." << std::endl; 
        exit(1); 
    }

    std::string junk; 
    getline(fin, junk); 

    std::string dates[LENGTH];
    std::string elevation[LENGTH];
    int count = 0; 
    bool the_date = false; 

    std::string date_tsv, eastSt, eastEl, westSt, westEl;
    while(fin >> date_tsv >> eastSt >> eastEl >> westSt >> westEl) {
        fin.ignore(INT_MAX, '\n');

        if(date_tsv.compare(date1) == 0) { 
            the_date = true; 
        }
        
        if(date_tsv.compare(date2) == 0) { 
            the_date = false; 
            dates[count] = date_tsv; 
            elevation[count] = westEl;
            count++;
        }

        if(the_date) { 
            dates[count] = date_tsv; 
            elevation[count] = westEl;
            count++;
        }
    }

    for(int i = count - 1; i >= 0; i--) {
        std::cout << dates[i] << " " << elevation[i] << " ft" << std::endl;
    }

    fin.close();
}
