// add your code as appropriate 
#include <iostream>
#include "reservoir.h"
#include <fstream> 
#include <cstdlib> 
#include <climits> 
#include "reverseorder.h" 
#include <string> 


int main()
{
  std::cout << "Task A outputs:" << std::endl; 
  std::cout << "01/01/2018 : " << get_east_storage("01/01/2018") << " billion gallons\n"; 
  std::cout << "03/19/2018 : " << get_east_storage("03/19/2018") << " billion gallons\n"; 
  std::cout << "06/21/2018 : " << get_east_storage("06/21/2018") << " billion gallons\n"; 

  std::cout << "Task B outputs: " << std::endl;  

  std::cout << "The minimum of the East basin storage is: " << get_min_east() << " billion gallons\n";
  std::cout << "The maximum of the East basin storage is: " << get_max_east() << " billion gallons\n";


  std::cout << "Taks C outputs: " << std::endl;  
  std::cout << "Which basin had the most gallons on the 1st of January? " << compare_basins("01/01/2018") << "\n"; 
  std::cout << "Which basin had the most gallons on the 19th of March? " << compare_basins("03/19/2018") << "\n";
  std::cout << "Which basin had the most gallons on the 7th of January? " << compare_basins("01/07/2018") << "\n"; 
  
  std::cout << "Task D outputs: " << std::endl; 
  std::cout << "reverse order from 04/20/2018 to 4/25/2018: " << std::endl; 
  reverse_order("04/20/2018", "04/25/2018"); 
  std::cout << "reverse order from 05/28/2021 to 06/02/2018" << std::endl; 
  reverse_order("05/28/2018", "06/02/2018");
  
  return 0;
}
