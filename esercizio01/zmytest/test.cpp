#include "test.hpp"

#include <iostream>

void mytest(){

    int structure, type;
    ulong size;

    std::cout<<"\n~*~#~*~ Welcome to the Student Test Suite ~*~#~*~\n";

    structure = chooseStructure();

    std::cout<<"\n~*~#~*~ Goodbye ~*~#~*~\n";
}

int chooseStructure(){
    
    std::string input;

    std::cout<<"\nChoose your structure:\n";

    std::cout<<"\n(1) Vector\n";
    std::cout<<"(2) List\n";
    std::cout<<"(3) StackVec\n";
    std::cout<<"(4) StackLst\n";
    std::cout<<"(5) QueueVec\n";
    std::cout<<"(6) QueueLst\n";

    do{
        std::cout<<"\n> ";
        getline(std::cin, input);

        if (input.compare("1") == 0){
            break;
        }
        else if (input.compare("2") == 0){
            break;
        }
        else if (input.compare("3") == 0){
            break;
        }
        else if (input.compare("4") == 0){
            break;
        }
        else if (input.compare("5") == 0){
            break;
        }
        else if (input.compare("6") == 0){
            break;
        }
        else{
            std::cout<<"[!] Invalid option. Please retry.\n";
            continue;
        }

    }while(true);
}
