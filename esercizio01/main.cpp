
#include "zmytest/test.hpp"

#include "zlasdtest/test.hpp"

/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

void chooseTest();

int main() {
  chooseTest();
  return 0;
}

void chooseTest(){
  std::string input;

  std::cout<<"===============================================\n";
  std::cout<<"|       Welcome to LASD Libraries 2024!       |\n";
  std::cout<<"===============================================\n";

  std::cout<<"\nChoose the test you want to execute:\n";

  std::cout<<"\n(1) Student's Test\n";
  std::cout<<"(2) Professor's Test\n";
  std::cout<<"(0) to Exit\n";

  do{
    std::cout<<"\n> ";
    getline(std::cin, input);

    if (input.compare("0") == 0){
      break;
    }
    else if (input.compare("1") == 0){
      mytest();
    }
    else if (input.compare("2") == 0){
      lasdtest();
    }
    else{
      std::cout<<"[!] Invalid option. Please retry.\n";
      continue;
    }

  }while(true);

  std::cout<<"\n===============================================\n";
  std::cout<<"|               Closing program...            |\n";
  std::cout<<"===============================================\n";

  std::cout<<"\nGoodbye!\n\n";

}