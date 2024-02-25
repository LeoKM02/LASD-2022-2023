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

        if(structure == BTVEC_ID){
            if(type == INT_ID){
                lasd::List<int> lst;
                fillList(lst);
                lasd::BinaryTreeVec<int> btvec(lst);
                testBinaryTree(btvec);
            }
            else if(type == FLOAT_ID){
                lasd::List<float> lst;
                fillList(lst);
                lasd::BinaryTreeVec<float> btvec(lst);
                testBinaryTree(btvec);
            }
            else if(type == STRING_ID){
                lasd::List<std::string> lst;
                fillList(lst);
                lasd::BinaryTreeVec<std::string> btvec(lst);
                testBinaryTree(btvec);
            }
        }
        else if(structure == BTLNK_ID){
            if(type == INT_ID){
                lasd::List<int> lst;
                fillList(lst);
                lasd::BinaryTreeLnk<int> btlnk(lst);
                testBinaryTree(btlnk);
            }
            else if(type == FLOAT_ID){
                lasd::List<float> lst;
                fillList(lst);
                lasd::BinaryTreeLnk<float> btlnk(lst);
                testBinaryTree(btlnk);
            }
            else if(type == STRING_ID){
                lasd::List<std::string> lst;
                fillList(lst);
                lasd::BinaryTreeLnk<std::string> btlnk(lst);
                testBinaryTree(btlnk);
            }
        }
        else if(structure == BST_ID){
            if(type == INT_ID){
                lasd::List<int> lst;
                fillList(lst);
                lasd::BST<int> bst(lst);
                testBST(bst);
            }
            else if(type == FLOAT_ID){
                lasd::List<float> lst;
                fillList(lst);
                lasd::BST<float> bst(lst);
                testBST(bst);
            }
            else if(type == STRING_ID){
                lasd::List<std::string> lst;
                fillList(lst);
                lasd::BST<std::string> bst(lst);
                testBST(bst);
            }
        }

    }while(true);
}





unsigned short selectStructure(){

    unsigned short parsed_input;

    std::cout << "\n\t!~~~~~~~ STUDENT TEST SUITE ~~~~~~~!\n";

    std::cout << "\n\tChoose the data structure:\n";

    std::cout << "\n\t(" << BTVEC_ID << ") BinaryTreeVec\n";
    std::cout << "\t(" << BTLNK_ID << ") BinaryTreeLnk\n";
    std::cout << "\t(" << BST_ID << ") BST\n";
    std::cout << "\n\t(0) to Exit\n";

    do{
        std::cout << "\n\t> ";

        try{
            getValue(parsed_input);

            if(
                parsed_input == 0 ||
                parsed_input == BTVEC_ID ||
                parsed_input == BTLNK_ID ||
                parsed_input == BST_ID
            ){
                break;
            }
            else{
                throw std::invalid_argument("");
            }
        }
        catch(const std::logic_error& err){
            std::cout << "[!] Invalid option. Please retry.\n";
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
            std::cout << "[!] Invalid option. Please retry.\n";
        }

    }while(true);

    return parsed_input;
}





void fillList(lasd::List<int> & lst){
    for(unsigned long i=0; i<DEFAULT_SIZE; ++i){
        lst.Insert(generateInt());
    }
}

void fillList(lasd::List<float> & lst){    
    for(unsigned long i=0; i<DEFAULT_SIZE; ++i){
        lst.Insert(generateFloat());
    }
}

void fillList(lasd::List<std::string> & lst){
    for(unsigned long i=0; i<DEFAULT_SIZE; ++i){
        lst.Insert(generateString());
    }
}




template <typename Data>
void testBinaryTree(lasd::MutableBinaryTree<Data> & con){
    const unsigned short OP_VIEW = 1;
    const unsigned short OP_CLEAR = 2;
    const unsigned short OP_EXISTS = 3;
    const unsigned short OP_ITER = 4;

    unsigned short parsed_input;

    do{
        std::cout << "\n\t\t!~~~~~~~ BINARY TREE ~~~~~~~!\n";

        std::cout << "\n\t\tSelect operation:\n";

        std::cout << "\n\t\t(" << OP_VIEW << ") VIEW: View container\n";
        std::cout << "\t\t(" << OP_CLEAR << ") CLEAR: Clear container\n";
        std::cout << "\t\t(" << OP_EXISTS << ") EXISTS: Check existence of value\n";
        std::cout << "\t\t(" << OP_ITER << ") ITER: Open iterator testing suite\n";
        std::cout << "\n\t\t(0) to Exit\n";

        std::cout << "\n\t\t> ";

        try{
            getValue(parsed_input);

            if(parsed_input == 0){
                break;
            }
            else if(parsed_input == OP_VIEW){
                std::cout << "\nViewing container...\n\n";
                con.View();
            }
            else if(parsed_input == OP_CLEAR){
                con.Clear();
                std::cout << "\nContainer successfully cleared!\n\n";
            }
            else if(parsed_input == OP_EXISTS){

                Data value;

                std::cout << "\n\t\tInsert the [Value] to search inside the container:\n";
                std::cout << "\n\t\t> ";

                getValue(value);

                if(con.Exists(value)){
                    std::cout << "\nValue \"" << value << "\" found!\n\n";
                }
                else{
                    std::cout << "\nValue \"" << value << "\" not found!\n\n";
                }
            }
            else if(parsed_input == OP_ITER){
                unsigned short in;

                std::cout << "\n\t\tSelect iterator:\n";

                std::cout << "\n\t\t(" << ITERPRE_ID << ") PreOrder Iterator\n";
                std::cout << "\t\t(" << ITERIN_ID << ") InOrder Iterator\n";
                std::cout << "\t\t(" << ITERPOST_ID << ") PostOrder Iterator\n";
                std::cout << "\t\t(" << ITERBREADTH_ID << ") Breadth Iterator\n";
                std::cout << "\n\t\t(0) to Exit\n";

                std::cout << "\n\t\t> ";

                getValue(in);

                if(in == ITERPRE_ID){
                    lasd::BTPreOrderIterator<Data> iter(con);
                    testPreOrderIterator(iter);
                }
                else if(in == ITERIN_ID){
                    lasd::BTInOrderIterator<Data> iter(con);
                    testInOrderIterator(iter);
                }
                else if(in == ITERPOST_ID){
                    lasd::BTPostOrderIterator<Data> iter(con);
                    testPostOrderIterator(iter);
                }
                else if(in == ITERBREADTH_ID){
                    lasd::BTBreadthIterator<Data> iter(con);
                    testBreadthIterator(iter);
                }
                else{
                    throw std::invalid_argument("");
                }
            }
            else{
                throw std::invalid_argument("");
            }
        }
        catch(const std::length_error& err){
            std::cout << "\n[!] " << err.what() << "\n";
        }
        catch(const std::out_of_range& err){
            std::cout << "\n[!] " << err.what() << "\n";
        }
        catch(const std::logic_error& err){
            std::cout << "\n[!] Invalid option. Please retry.\n";
        }

    }while(true);
}

template <typename Data>
void testBST(lasd::BST<Data>& con){
    const unsigned short OP_VIEW = 1;
    const unsigned short OP_CLEAR = 2;
    const unsigned short OP_EXISTS = 3;
    const unsigned short OP_ITER = 4;
    const unsigned short OP_INSERT = 5;
    const unsigned short OP_REMOVE = 6;
    const unsigned short OP_MIN_N_REMOVE = 7;
    const unsigned short OP_MAX_N_REMOVE = 8;
    const unsigned short OP_PREDECESSOR = 9;
    const unsigned short OP_PREDECESSOR_N_REMOVE = 10;
    const unsigned short OP_SUCCESSOR = 11;
    const unsigned short OP_SUCCESSOR_N_REMOVE = 12;
    
    unsigned short parsed_input;

    do{
        std::cout << "\n\t\t!~~~~~~~ BINARY SEARCH TREE ~~~~~~~!\n";

        std::cout << "\n\t\tSelect operation:\n";

        std::cout << "\n\t\t(" << OP_VIEW << ") VIEW: View container\n";
        std::cout << "\t\t(" << OP_CLEAR << ") CLEAR: Clear container\n";
        std::cout << "\t\t(" << OP_EXISTS << ") EXISTS: Check existence of value\n";
        std::cout << "\t\t(" << OP_ITER << ") ITER: Open iterator testing suite\n";
        std::cout << "\t\t(" << OP_INSERT << ") INSERT: Insert new value into tree\n";
        std::cout << "\t\t(" << OP_REMOVE << ") REMOVE: Remove existing value from tree\n";
        std::cout << "\t\t(" << OP_MIN_N_REMOVE << ") MIN & REMOVE: Get minimum value\n";
        std::cout << "\t\t(" << OP_MAX_N_REMOVE << ") MAX & REMOVE: Get maximum value\n";
        std::cout << "\t\t(" << OP_PREDECESSOR << ") PREDECESSOR: Get predecessor\n";
        std::cout << "\t\t(" << OP_PREDECESSOR_N_REMOVE << ") PREDECESSOR & REMOVE: Remove predecessor\n";
        std::cout << "\t\t(" << OP_SUCCESSOR << ") SUCCESSOR: Get successor\n";
        std::cout << "\t\t(" << OP_SUCCESSOR_N_REMOVE << ") SUCCESSOR & REMOVE: Remove successor\n";
        std::cout << "\n\t\t(0) to Exit\n";

        std::cout << "\n\t\t> ";

        try{
            getValue(parsed_input);

            if(parsed_input == 0){
                break;
            }
            else if(parsed_input == OP_VIEW){
                std::cout << "\nViewing container...\n\n";
                con.View();
            }
            else if(parsed_input == OP_CLEAR){
                con.Clear();
                std::cout << "\nContainer successfully cleared!\n\n";
            }
            else if(parsed_input == OP_EXISTS){
                Data value;

                std::cout << "\n\t\tInsert the [Value] to search inside the container:\n";
                std::cout << "\n\t\t> ";

                getValue(value);

                if(con.Exists(value)){
                    std::cout << "\nValue \"" << value << "\" found!\n\n";
                }
                else{
                    std::cout << "\nValue \"" << value << "\" not found!\n\n";
                }
            }
            else if(parsed_input == OP_ITER){
                unsigned short in;

                std::cout << "\n\t\tSelect iterator:\n";

                std::cout << "\n\t\t(" << ITERPRE_ID << ") PreOrder Iterator\n";
                std::cout << "\t\t(" << ITERIN_ID << ") InOrder Iterator\n";
                std::cout << "\t\t(" << ITERPOST_ID << ") PostOrder Iterator\n";
                std::cout << "\t\t(" << ITERBREADTH_ID << ") Breadth Iterator\n";
                std::cout << "\n\t\t(0) to Exit\n";

                std::cout << "\n\t\t> ";

                getValue(in);

                if(in == ITERPRE_ID){
                    lasd::BTPreOrderIterator<Data> iter(con);
                    testPreOrderIterator(iter);
                }
                else if(in == ITERIN_ID){
                    lasd::BTInOrderIterator<Data> iter(con);
                    testInOrderIterator(iter);
                }
                else if(in == ITERPOST_ID){
                    lasd::BTPostOrderIterator<Data> iter(con);
                    testPostOrderIterator(iter);
                }
                else if(in == ITERBREADTH_ID){
                    lasd::BTBreadthIterator<Data> iter(con);
                    testBreadthIterator(iter);
                }
                else{
                    throw std::invalid_argument("");
                }
            }
            else if(parsed_input == OP_INSERT){
                Data value;

                std::cout << "\n\t\tInsert [Value]:\n\t\t> ";
                getValue(value);

                if(con.Insert(value)){
                    std::cout << "\nValue inserted successfully!\n";
                }
                else{
                    std::cout << "\nInsert failed!\n";
                }
            }
            else if(parsed_input == OP_REMOVE){
                Data value;

                std::cout << "\n\t\tInsert [Value]:\n\t\t> ";
                getValue(value);

                if(con.Remove(value)){
                    std::cout << "\nValue removed successfully!\n";
                }
                else{
                    std::cout << "\nInsert failed!\n";
                }
            }
            else if(parsed_input == OP_MIN_N_REMOVE){
                Data min = con.MinNRemove();

                std::cout << "\nMin: " << min << "\n";
                std::cout << "\nMin successfully removed from tree!\n";
            }
            else if(parsed_input == OP_MAX_N_REMOVE){
                Data min = con.MaxNRemove();

                std::cout << "\nMax: " << min << "\n";
                std::cout << "\nMax successfully removed from tree!\n";
            }
            else if(parsed_input == OP_PREDECESSOR){
                Data value;

                std::cout << "\n\t\tInsert [Value]:\n\t\t> ";
                getValue(value);

                Data pred = con.Predecessor(value);
                std::cout << "\nPredecessor of " << value << ": " << pred << "\n";
            }
            else if(parsed_input == OP_PREDECESSOR_N_REMOVE){
                Data value;

                std::cout << "\n\t\tInsert [Value]:\n\t\t> ";
                getValue(value);

                Data pred = con.PredecessorNRemove(value);
                std::cout << "\nPredecessor of " << value << ": " << pred << "\n";
                std::cout << "\nPredecessor successfully removed from tree!\n";
            }
            else if(parsed_input == OP_SUCCESSOR){
                Data value;

                std::cout << "\n\t\tInsert [Value]:\n\t\t> ";
                getValue(value);

                Data succ = con.Successor(value);
                std::cout << "\nSuccessor of " << value << ": " << succ << "\n";
            }
            else if(parsed_input == OP_SUCCESSOR_N_REMOVE){
                Data value;

                std::cout << "\n\t\tInsert [Value]:\n\t\t> ";
                getValue(value);

                Data succ = con.SuccessorNRemove(value);
                std::cout << "\nSuccessor of " << value << ": " << succ << "\n";
                std::cout << "\nSuccessor successfully removed from tree!\n";
            }
            else{
                throw std::invalid_argument("");
            }
        }
        catch(const std::length_error& err){
            std::cout << "\n[!] " << err.what() << "\n";
        }
        catch(const std::out_of_range& err){
            std::cout << "\n[!] " << err.what() << "\n";
        }
        catch(const std::logic_error& err){
            std::cout << "\n[!] Invalid option. Please retry.\n";
        }

    }while(true);
}





template <typename Data>
void testPreOrderIterator(lasd::BTPreOrderIterator<Data> & iter){
    const unsigned short OP_VIEW = 1;
    const unsigned short OP_INCREMENT = 2;
    const unsigned short OP_RESET = 3;

    unsigned short parsed_input;

    do{
        std::cout << "\n\t\t\t!~~~~~~~ PREORDER ITERATOR ~~~~~~~!\n";

        std::cout << "\n\t\t\tSelect operation:\n";

        std::cout << "\n\t\t\t(" << OP_VIEW << ") VIEW: View current element\n";
        std::cout << "\t\t\t(" << OP_INCREMENT << ") INCREMENT: Increment iterator\n";
        std::cout << "\t\t\t(" << OP_RESET << ") RESET: Reset iterator\n";
        std::cout << "\n\t\t\t(0) to Exit\n";

        std::cout << "\n\t\t\t> ";

        try{
            getValue(parsed_input);

            if(parsed_input == 0){
                break;
            }
            else if(parsed_input == OP_VIEW){
                Data currelem = *iter;
                std::cout << "\nCurrent element: " << currelem << "\n";
            }
            else if(parsed_input == OP_INCREMENT){
                ++iter;
                std::cout << "\nIterator incremented!\n";
            }
            else if(parsed_input == OP_RESET){
                iter.Reset();
                std::cout << "\nIterator reset!\n";
            }
            else{
                throw std::invalid_argument("");
            }
        }
        catch(const std::length_error& err){
            std::cout << "\n[!] " << err.what() << "\n";
        }
        catch(const std::out_of_range& err){
            std::cout << "\n[!] " << err.what() << "\n";
        }
        catch(const std::logic_error& err){
            std::cout << "\n[!] Invalid option. Please retry.\n";
        }

    }while(true);
}

template <typename Data>
void testPostOrderIterator(lasd::BTPostOrderIterator<Data> & iter){
    const unsigned short OP_VIEW = 1;
    const unsigned short OP_INCREMENT = 2;
    const unsigned short OP_RESET = 3;

    unsigned short parsed_input;

    do{
        std::cout << "\n\t\t\t!~~~~~~~ POSTORDER ITERATOR ~~~~~~~!\n";

        std::cout << "\n\t\t\tSelect operation:\n";

        std::cout << "\n\t\t\t(" << OP_VIEW << ") VIEW: View current element\n";
        std::cout << "\t\t\t(" << OP_INCREMENT << ") INCREMENT: Increment iterator\n";
        std::cout << "\t\t\t(" << OP_RESET << ") RESET: Reset iterator\n";
        std::cout << "\n\t\t\t(0) to Exit\n";

        std::cout << "\n\t\t\t> ";

        try{
            getValue(parsed_input);

            if(parsed_input == 0){
                break;
            }
            else if(parsed_input == OP_VIEW){
                Data currelem = *iter;
                std::cout << "\nCurrent element: " << currelem << "\n";
            }
            else if(parsed_input == OP_INCREMENT){
                ++iter;
                std::cout << "\nIterator incremented!\n";
            }
            else if(parsed_input == OP_RESET){
                iter.Reset();
                std::cout << "\nIterator reset!\n";
            }
            else{
                throw std::invalid_argument("");
            }
        }
        catch(const std::length_error& err){
            std::cout << "\n[!] " << err.what() << "\n";
        }
        catch(const std::out_of_range& err){
            std::cout << "\n[!] " << err.what() << "\n";
        }
        catch(const std::logic_error& err){
            std::cout << "\n[!] Invalid option. Please retry.\n";
        }

    }while(true);
}

template <typename Data>
void testInOrderIterator(lasd::BTInOrderIterator<Data> & iter){
    const unsigned short OP_VIEW = 1;
    const unsigned short OP_INCREMENT = 2;
    const unsigned short OP_RESET = 3;

    unsigned short parsed_input;

    do{
        std::cout << "\n\t\t\t!~~~~~~~ INORDER ITERATOR ~~~~~~~!\n";

        std::cout << "\n\t\t\tSelect operation:\n";

        std::cout << "\n\t\t\t(" << OP_VIEW << ") VIEW: View current element\n";
        std::cout << "\t\t\t(" << OP_INCREMENT << ") INCREMENT: Increment iterator\n";
        std::cout << "\t\t\t(" << OP_RESET << ") RESET: Reset iterator\n";
        std::cout << "\n\t\t\t(0) to Exit\n";

        std::cout << "\n\t\t\t> ";

        try{
            getValue(parsed_input);

            if(parsed_input == 0){
                break;
            }
            else if(parsed_input == OP_VIEW){
                Data currelem = *iter;
                std::cout << "\nCurrent element: " << currelem << "\n";
            }
            else if(parsed_input == OP_INCREMENT){
                ++iter;
                std::cout << "\nIterator incremented!\n";
            }
            else if(parsed_input == OP_RESET){
                iter.Reset();
                std::cout << "\nIterator reset!\n";
            }
            else{
                throw std::invalid_argument("");
            }
        }
        catch(const std::length_error& err){
            std::cout << "\n[!] " << err.what() << "\n";
        }
        catch(const std::out_of_range& err){
            std::cout << "\n[!] " << err.what() << "\n";
        }
        catch(const std::logic_error& err){
            std::cout << "\n[!] Invalid option. Please retry.\n";
        }

    }while(true);
}

template <typename Data>
void testBreadthIterator(lasd::BTBreadthIterator<Data> & iter){
    const unsigned short OP_VIEW = 1;
    const unsigned short OP_INCREMENT = 2;
    const unsigned short OP_RESET = 3;

    unsigned short parsed_input;

    do{
        std::cout << "\n\t\t\t!~~~~~~~ BREADTH ITERATOR ~~~~~~~!\n";

        std::cout << "\n\t\t\tSelect operation:\n";

        std::cout << "\n\t\t\t(" << OP_VIEW << ") VIEW: View current element\n";
        std::cout << "\t\t\t(" << OP_INCREMENT << ") INCREMENT: Increment iterator\n";
        std::cout << "\t\t\t(" << OP_RESET << ") RESET: Reset iterator\n";
        std::cout << "\n\t\t\t(0) to Exit\n";

        std::cout << "\n\t\t\t> ";

        try{
            getValue(parsed_input);

            if(parsed_input == 0){
                break;
            }
            else if(parsed_input == OP_VIEW){
                Data currelem = *iter;
                std::cout << "\nCurrent element: " << currelem << "\n";
            }
            else if(parsed_input == OP_INCREMENT){
                ++iter;
                std::cout << "\nIterator incremented!\n";
            }
            else if(parsed_input == OP_RESET){
                iter.Reset();
                std::cout << "\nIterator reset!\n";
            }
            else{
                throw std::invalid_argument("");
            }
        }
        catch(const std::length_error& err){
            std::cout << "\n[!] " << err.what() << "\n";
        }
        catch(const std::out_of_range& err){
            std::cout << "\n[!] " << err.what() << "\n";
        }
        catch(const std::logic_error& err){
            std::cout << "\n[!] Invalid option. Please retry.\n";
        }

    }while(true);
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

