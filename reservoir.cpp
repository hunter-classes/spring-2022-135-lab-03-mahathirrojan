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
    getline(fin,junk); 

    std::string date_tsv, eastSt, eastEl, westSt, westEl; 
    while(fin >> date_tsv >> eastSt >> eastEl >> westSt >> westEl){
        fin.ignore(INT_MAX, '\n');
        //std::cout << date << " " << eastSt << std::endl;
        if(date_tsv == date){
        fin.close(); 
        return std::stod(eastSt);
        }
     
    }
    

}

double get_min_east(){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if(fin.fail()){
        std::cerr << "File cannot be opened for reading" << std::endl; 
        exit(1); 
    }
    std::string junk; 
    getline(fin, junk);

    double storage_min = INT_MAX; 


    std::string date_tsv, eastSt, eastEl, westSt, westEl; 
    while(fin >> date_tsv >> eastSt >> eastEl >> westSt >> westEl){
        fin.ignore(INT_MAX, '\n');

        if (std::stod(eastSt) < storage_min){
            storage_min = std::stod(eastSt); 
        }
    }

    fin.close();
    return storage_min; 

}

double get_max_east(){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if(fin.fail()){
        std::cerr << "File cannot be opened for reading" << std::endl; 
        exit(1); 
    }
    std::string junk; 
    getline(fin, junk);

    double storage_max = INT_MIN; 


    std::string date_tsv, eastSt, eastEl, westSt, westEl; 
    while(fin >> date_tsv >> eastSt >> eastEl >> westSt >> westEl){
        fin.ignore(INT_MAX, '\n');

        if (std::stod(eastSt) > storage_max){
            storage_max = std::stod(eastSt); 
        }
    }

    fin.close();
    return storage_max; 

}

std::string compare_basins(std::string date){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if(fin.fail()){
        std::cerr << "File cannot be opened for reading." << std::endl; 
        exit(1); 
    }

    std::string junk; 
    getline(fin,junk); 

    std::string date_tsv, eastSt, eastEl, westSt, westEl; 
    while(fin >> date_tsv >> eastSt >> eastEl >> westSt >> westEl){
        fin.ignore(INT_MAX, '\n');

        if(date_tsv == date){
            fin.close(); 
            if(std::stod(eastEl) > std::stod(westEl)){
                return "West"; 
            }
            else if(std::stod(eastEl) < std::stod(westEl)){
                return "East"; 
            }
            else{
                return "They are equal.";
            }
            
        }
    }
    return ""; 
}