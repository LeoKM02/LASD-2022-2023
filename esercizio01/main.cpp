
#include "zmytest/test.hpp"
#include "zlasdtest/test.hpp"

/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdexcept>

/* ************************************************************************** */

#define MYTEST_ID 1
#define LASDTEST_ID 2

void selectTest();

int main()
{

  std::cout << "\n:::             :::        ::::::::   :::::::::\n";
  std::cout << ":+:           :+: :+:     :+:    :+:  :+:    :+:\n";
  std::cout << "+:+          +:+   +:+    +:+         +:+    +:+\n";
  std::cout << "+#+         +#++:++#++:   +#++:++#++  +#+    +:+\n";
  std::cout << "+#+         +#+     +#+          +#+  +#+    +#+\n";
  std::cout << "#+#         #+#     #+#   #+#    #+#  #+#    #+#\n";
  std::cout << "##########  ###     ###    ########   #########\n\n";

  std::cout << "#     ##  #     # ##   ###  # ##  ##   ##    ###\n";
  std::cout << "#         ###   ##    #  #  ##        ####  ##  \n";
  std::cout << "#     ##  #  #  #     #  #  #     ##  #       ##\n";
  std::cout << "####  ##  ###   #      ###  #     ##   ##   ###  \n\n";

  std::cout << "===============================================\n";
  std::cout << "|       Welcome to LASD Libraries 2024!       |\n";
  std::cout << "===============================================\n";

  selectTest();
  
  std::cout << "\n===============================================\n";
  std::cout << "|               Closing program...            |\n";
  std::cout << "===============================================\n";

  return 0;
}

void selectTest()
{
  std::string input;
  unsigned short parsed_input;

  do
  {
    std::cout << "\n!~~~~~~~ LASD LIBRARIES 2024 ~~~~~~~!\n";

    std::cout << "\nChoose the test you want to execute:\n";

    std::cout << "\n(" << MYTEST_ID << ") Student's Test\n";
    std::cout << "(" << LASDTEST_ID << ") Professor's Test\n";
    std::cout << "\n(0) to Exit\n";

    std::cout << "\n> ";
    getline(std::cin, input);

    try
    {
      parsed_input = std::stoi(input);

      if (parsed_input == 0)
      {
        break;
      }
      else if (parsed_input == MYTEST_ID)
      {
        mytest();
      }
      else if (parsed_input == LASDTEST_ID)
      {
        lasdtest();
      }
      else
      {
        throw std::invalid_argument("");
      }
    }
    catch (const std::logic_error &err)
    {
      std::cout << "[!] Invalid option. Please retry.\n";
    }

  } while (true);

  std::cout << "\n!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~!\n";
}