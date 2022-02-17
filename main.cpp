// add your code as appropriate 
#include <iostream>
#include "reservoir.h"


int main()
{
  //Task A outputs 
  std::cout << "01/01/2018 : " << get_east_storage("01/01/2018") << " billion gallons\n"; 
  std::cout << "03/19/2018 : " << get_east_storage("03/19/2018") << " billion gallons\n"; 
  std::cout << "06/21/2018 : " << get_east_storage("06/21/2018") << " billion gallons\n"; 

  //Task B outputs 

  std::cout << "The minimum of the East basin storage is: " << get_min_east() << " billion gallons\n";
  std::cout << "The maximum of the East basin storage is: " << get_max_east() << " billion gallons\n";


  //Taks C outputs 
  std::cout << "Which basin had the most gallons on the 1st of January? " << compare_basins("01/01/2018") << "\n"; 
  std::cout << "Which basin had the most gallons on the 19th of March? " << compare_basins("03/19/2018") << "\n";
  std::cout << "Which basin had the most gallons on the 7th of January? " << compare_basins("01/07/2018") << "\n"; 
  
  return 0;
}
