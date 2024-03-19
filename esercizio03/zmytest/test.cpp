#include "test.hpp"

#include <iostream>
#include <stdexcept>
#include <string>
#include <random>
#include <limits>

void mytest(){

    unsigned short structure, type;

    do{
        structure = selectStructure();
        if(structure == 0) break;

        type = selectType();
        if(type == 0) continue;

        if(structure == HTCLSADR_ID){
            if(type == INT_ID){
                lasd::HashTableClsAdr<int> ht;
                fillHashTable(ht);
                testHashTable(ht);
            }
            else if(type == FLOAT_ID){
                lasd::HashTableClsAdr<float> ht;
                fillHashTable(ht);
                testHashTable(ht);
            }
            else if(type == STRING_ID){
                lasd::HashTableClsAdr<std::string> ht;
                fillHashTable(ht);
                testHashTable(ht);
            }
        }
        else if(structure == HTOPNADR_ID){
            if(type == INT_ID){
                lasd::HashTableOpnAdr<int> ht;
                fillHashTable(ht);
                testHashTable(ht);
            }
            else if(type == FLOAT_ID){
                lasd::HashTableOpnAdr<float> ht;
                fillHashTable(ht);
                testHashTable(ht);
            }
            else if(type == STRING_ID){
                lasd::HashTableOpnAdr<std::string> ht;
                fillHashTable(ht);
                testHashTable(ht);
            }
        }

    }while(true);
}





unsigned short selectStructure(){

    unsigned short parsed_input;

    std::cout << "\n\t!~~~~~~~ STUDENT TEST SUITE ~~~~~~~!\n";

    std::cout << "\n\tChoose the data structure:\n";

    std::cout << "\n\t(" << HTCLSADR_ID << ") HashTableClsAdr\n";
    std::cout << "\t(" << HTOPNADR_ID << ") HashTableOpnAdr\n";
    std::cout << "\n\t(0) to Exit\n";

    do{
        std::cout << "\n\t> ";

        try{
            getValue(parsed_input);

            if(
                parsed_input == 0 ||
                parsed_input == HTCLSADR_ID ||
                parsed_input == HTOPNADR_ID
            ){
                break;
            }
            else{
                throw std::invalid_argument("");
            }
        }
        catch(const std::logic_error& err){
            std::cout << "\t[!] Invalid option. Please retry.\n";
        }

    }while(true);

    return parsed_input;
}

unsigned short selectType(){
    unsigned short parsed_input;

    std::cout << "\n\tChoose the type of stored data:\n";

    std::cout << "\n\t(" << INT_ID << ") int\n";
    std::cout << "\t(" << FLOAT_ID << ") float\n";
    std::cout << "\t(" << STRING_ID << ") string\n";
    std::cout << "\n\t(0) to Go Back\n";

    do{
        std::cout << "\n\t> ";

        try{
            getValue(parsed_input);

            if(
                parsed_input == 0 ||
                parsed_input == INT_ID ||
                parsed_input == FLOAT_ID ||
                parsed_input == STRING_ID
            ){
                break;
            }
            else{
                throw std::invalid_argument("");
            }
        }
        catch(const std::logic_error& err){
            std::cout << "\t[!] Invalid option. Please retry.\n";
        }

    }while(true);

    return parsed_input;
}





void fillHashTable(lasd::HashTable<int>& ht){
    for(unsigned long i=0; i<DEFAULT_SIZE; ++i){
        ht.Insert(generateInt());
    }
}

void fillHashTable(lasd::HashTable<float>& ht){    
    for(unsigned long i=0; i<DEFAULT_SIZE; ++i){
        ht.Insert(generateFloat());
    }
}

void fillHashTable(lasd::HashTable<std::string>& ht){
    for(unsigned long i=0; i<DEFAULT_SIZE; ++i){
        ht.Insert(generateString());
    }
}





template <typename Data>
void testHashTable(lasd::HashTable<Data>& con){
    // const unsigned short OP_CLEAR = 2;
    // const unsigned short OP_EXISTS = 3;
    // const unsigned short OP_ITER = 4;

    // unsigned short parsed_input;

    // do{
    //     std::cout << "\n\t\t!~~~~~~~ HASHTABLE ~~~~~~~!\n";

    //     std::cout << "\n\t\tSelect operation:\n";

    //     std::cout << "\t\t(" << OP_CLEAR << ") CLEAR: Clear container\n";
    //     std::cout << "\t\t(" << OP_EXISTS << ") EXISTS: Check existence of value\n";
    //     std::cout << "\t\t(" << OP_ITER << ") ITER: Open iterator testing suite\n";
    //     std::cout << "\n\t\t(0) to Exit\n";

    //     std::cout << "\n\t\t> ";

    //     try{
    //         getValue(parsed_input);

    //         if(parsed_input == 0){
    //             break;
    //         }
    //         else if(parsed_input == OP_VIEW){
    //             std::cout << "\n\t\tViewing container...\n\n";
    //             con.View();
    //         }
    //         else if(parsed_input == OP_CLEAR){
    //             con.Clear();
    //             std::cout << "\n\t\tContainer successfully cleared!\n\n";
    //         }
    //         else if(parsed_input == OP_EXISTS){

    //             Data value;

    //             std::cout << "\n\t\tInsert the [Value] to search inside the container:\n";
    //             std::cout << "\n\t\t> ";

    //             getValue(value);

    //             if(con.Exists(value)){
    //                 std::cout << "\n\t\tValue \"" << value << "\" found!\n\n";
    //             }
    //             else{
    //                 std::cout << "\n\t\tValue \"" << value << "\" not found!\n\n";
    //             }
    //         }
    //         else if(parsed_input == OP_ITER){
    //             unsigned short in;

    //             std::cout << "\n\t\tSelect iterator:\n";

    //             std::cout << "\n\t\t(" << ITERPRE_ID << ") PreOrder Iterator\n";
    //             std::cout << "\t\t(" << ITERIN_ID << ") InOrder Iterator\n";
    //             std::cout << "\t\t(" << ITERPOST_ID << ") PostOrder Iterator\n";
    //             std::cout << "\t\t(" << ITERBREADTH_ID << ") Breadth Iterator\n";
    //             std::cout << "\n\t\t(0) to Exit\n";

    //             std::cout << "\n\t\t> ";

    //             getValue(in);

    //             if(in == ITERPRE_ID){
    //                 lasd::BTPreOrderIterator<Data> iter(con);
    //                 testPreOrderIterator(iter);
    //             }
    //             else if(in == ITERIN_ID){
    //                 lasd::BTInOrderIterator<Data> iter(con);
    //                 testInOrderIterator(iter);
    //             }
    //             else if(in == ITERPOST_ID){
    //                 lasd::BTPostOrderIterator<Data> iter(con);
    //                 testPostOrderIterator(iter);
    //             }
    //             else if(in == ITERBREADTH_ID){
    //                 lasd::BTBreadthIterator<Data> iter(con);
    //                 testBreadthIterator(iter);
    //             }
    //             else{
    //                 throw std::invalid_argument("");
    //             }
    //         }
    //         else{
    //             throw std::invalid_argument("");
    //         }
    //     }
    //     catch(const std::length_error& err){
    //         std::cout << "\n\t\t[!] " << err.what() << "\n";
    //     }
    //     catch(const std::out_of_range& err){
    //         std::cout << "\n\t\t[!] " << err.what() << "\n";
    //     }
    //     catch(const std::logic_error& err){
    //         std::cout << "\n\t\t[!] Invalid option. Please retry.\n";
    //     }

    // }while(true);
}





int generateInt(){
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> int_dist(0, 100);

    return int_dist(gen);
}

float generateFloat(){
    std::default_random_engine gen(std::random_device{}());
    std::uniform_real_distribution<float> float_dist(0, 10);

    return float_dist(gen);
}

std::string generateString()
{
    const std::string CHARACTERS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);

    std::string generateString;

    for (std::size_t i = 0; i < 5; ++i)
    {
        generateString += CHARACTERS[distribution(generator)];
    }

    return generateString;
}





void getValue(int & dat){
    std::string input;

    getline(std::cin, input);
    dat = std::stoi(input);
}

void getValue(unsigned short & dat){
    std::string input;

    getline(std::cin, input);
    dat = std::stoi(input);
}

void getValue(unsigned long & dat){
    std::string input;

    getline(std::cin, input);
    dat = std::stoul(input);
}

void getValue(float & dat){
    std::string input;

    getline(std::cin, input);
    dat = std::stof(input);
}

void getValue(std::string & dat){
    getline(std::cin, dat);
}

