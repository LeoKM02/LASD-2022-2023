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
void testBinaryTree(lasd::BinaryTree<Data> &){

}

template <typename Data>
void testBST(lasd::BST<Data> &){

}





template <typename Data>
void testPreOrderIterator(lasd::BTPreOrderIterator<Data> &){

}

template <typename Data>
void testPostOrderIterator(lasd::BTPostOrderIterator<Data> &){

}

template <typename Data>
void testInOrderIterator(lasd::BTInOrderIterator<Data> &){

}

template <typename Data>
void testBreadthIterator(lasd::BTBreadthIterator<Data> &){
    
}

// template <typename Data>
// void testVector(lasd::Vector<Data> & con){
//     const unsigned short OP_VIEW = 1;
//     const unsigned short OP_CLEAR = 2;
//     const unsigned short OP_RESIZE = 3;
//     const unsigned short OP_EXISTS = 4;
//     const unsigned short OP_ASSIGN = 5;
//     const unsigned short OP_SORT = 6;
//     const unsigned short OP_FILL = 7;

//     unsigned short parsed_input;

//     do{
//         std::cout << "\n\t\t!~~~~~~~ VECTOR ~~~~~~~!\n";

//         std::cout << "\n\t\tSelect operation:\n";

//         std::cout << "\n\t\t(" << OP_VIEW << ") VIEW: View container\n";
//         std::cout << "\t\t(" << OP_CLEAR << ") CLEAR: Clear container\n";
//         std::cout << "\t\t(" << OP_RESIZE << ") RESIZE: Resize container\n";
//         std::cout << "\t\t(" << OP_EXISTS << ") EXISTS: Check existence of value\n";
//         std::cout << "\t\t(" << OP_ASSIGN << ") ASSIGN: Assign value to cell\n";
//         std::cout << "\t\t(" << OP_SORT << ") SORT: Sort container\n";
//         std::cout << "\t\t(" << OP_FILL << ") FILL: Populate container with randomized values\n";
//         std::cout << "\n\t\t(0) to Exit\n";

//         std::cout << "\n\t\t> ";

//         try{
//             getValue(parsed_input);

//             if(parsed_input == 0){
//                 break;
//             }
//             else if(parsed_input == OP_VIEW){
//                 std::cout << "\n\t\tViewing container...\n\n";
//                 con.View();
//             }
//             else if(parsed_input == OP_CLEAR){
//                 con.Clear();
//                 std::cout << "\n\t\tContainer successfully cleared!\n\n";
//             }
//             else if(parsed_input == OP_RESIZE){

//                 unsigned long newsize;

//                 std::cout << "\n\t\tInsert new [Size] for container (0 - 1000000) > ";

//                 getValue(newsize);

//                 if(newsize > 1000000){
//                     throw std::out_of_range("Size value too big!");
//                 }

//                 con.Resize(newsize);

//                 std::cout << "\n\t\tContainer successfully resized!\n\n";
//             }
//             else if(parsed_input == OP_EXISTS){

//                 Data value;

//                 std::cout << "\n\t\tInsert the [Value] to search inside the container:\n";
//                 std::cout << "\n\t\t> ";

//                 getValue(value);

//                 if(con.Exists(value)){
//                     std::cout << "\n\t\tValue \"" << value << "\" found!\n\n";
//                 }
//                 else{
//                     std::cout << "\n\t\tValue \"" << value << "\" not found!\n\n";
//                 }
//             }
//             else if(parsed_input == OP_ASSIGN){
//                 unsigned long index;
//                 Data newvalue;

//                 std::cout << "\n\t\tInsert the [Index] of the cell:\n";
//                 std::cout << "\n\t\t> ";

//                 getValue(index);

//                 std::cout << "\n\t\tAssign the [Value]:\n";
//                 std::cout << "\n\t\t> ";

//                 getValue(newvalue);

//                 con[index] = newvalue;

//                 std::cout << "\n\t\tContainer successfully updated!\n\n";
//             }
//             else if(parsed_input == OP_SORT){
//                 con.Sort();
//                 std::cout << "\n\t\tContainer successfully sorted!\n\n";
//             }
//             else if(parsed_input == OP_FILL){
//                 std::cout << "\n\t\tRandomizing container contents...\n\n";
//                 fillVector(con);
//                 std::cout << "\n\t\tContainer successfully filled!\n\n";
//             }
//             else{
//                 throw std::invalid_argument("");
//             }
//         }
//         catch(const std::length_error& err){
//             std::cout << "\n\t\t[!] " << err.what() << "\n";
//         }
//         catch(const std::out_of_range& err){
//             std::cout << "\n\t\t[!] " << err.what() << "\n";
//         }
//         catch(const std::logic_error& err){
//             std::cout << "\n\t\t[!] Invalid option. Please retry.\n";
//         }

//     }while(true);

// }

// template <typename Data>
// void testList(lasd::List<Data> & con){
//     const unsigned short OP_VIEW = 1;
//     const unsigned short OP_CLEAR = 2;
//     const unsigned short OP_EXISTS = 3;
//     const unsigned short OP_DICTIONARY = 4;
//     const unsigned short OP_LIST = 5;
//     const unsigned short OP_FILL = 6;

//     const unsigned short OP_INSERT = 1;
//     const unsigned short OP_REMOVE = 2;

//     const unsigned short OP_INSERT_FRONT = 1;
//     const unsigned short OP_INSERT_BACK = 2;
//     const unsigned short OP_FRONT_N_REMOVE = 3;

//     unsigned short parsed_input;

//     do{
//         std::cout << "\n\t\t!~~~~~~~ LIST ~~~~~~~!\n";

//         std::cout << "\n\t\tSelect operation:\n";

//         std::cout << "\n\t\t(" << OP_VIEW << ") VIEW: View container\n";
//         std::cout << "\t\t(" << OP_CLEAR << ") CLEAR: Clear container\n";
//         std::cout << "\t\t(" << OP_EXISTS << ") EXISTS: Check existence of value\n";
//         std::cout << "\t\t(" << OP_DICTIONARY << ") DICTIONARY: Access to dictionary specific functions\n";
//         std::cout << "\t\t(" << OP_LIST << ") LIST: Access to list specific functions\n";
//         std::cout << "\t\t(" << OP_FILL << ") FILL: Populate container with randomized values\n";
//         std::cout << "\n\t\t(0) to Exit\n";

//         std::cout << "\n\t\t> ";

//         try{
//             getValue(parsed_input);

//             if(parsed_input == 0){
//                 break;
//             }
//             else if(parsed_input == OP_VIEW){
//                 std::cout << "\n\t\tViewing container...\n\n";
//                 con.View();
//             }
//             else if(parsed_input == OP_CLEAR){
//                 con.Clear();
//                 std::cout << "\n\t\tContainer successfully cleared!\n\n";
//             }
//             else if(parsed_input == OP_EXISTS){

//                 Data value;

//                 std::cout << "\n\t\tInsert the [Value] to search inside the container:\n";
//                 std::cout << "\n\t\t> ";

//                 getValue(value);

//                 if(con.Exists(value)){
//                     std::cout << "\n\t\tValue \"" << value << "\" found!\n\n";
//                 }
//                 else{
//                     std::cout << "\n\t\tValue \"" << value << "\" not found!\n\n";
//                 }
//             }
//             else if(parsed_input == OP_DICTIONARY){

//                 unsigned short in;

//                 std::cout << "\n\t\tSelect the dictionary operation:\n";

//                 std::cout << "\n\t\t(" << OP_INSERT << ") INSERT: Insert value into dictionary\n";
//                 std::cout << "\t\t(" << OP_REMOVE << ") REMOVE: Remove value from dictionary\n";
//                 std::cout << "\n\t\t(0) to Exit\n";

//                 std::cout << "\n\t\t> ";

//                 getValue(in);

//                 if(in == 0){
//                     continue;
//                 }
//                 else if(in == OP_INSERT){
//                     Data value;

//                     std::cout << "\n\t\tInsert the [Value] to insert:\n";
//                     std::cout << "\n\t\t> ";

//                     getValue(value);

//                     if(con.Insert(value)){
//                         std::cout << "\n\t\tThe value was successfully added to the dictionary!\n";
//                     }
//                     else{
//                         std::cout << "\n\t\tInsert failed!\n";
//                     }
//                 }
//                 else if(in == OP_REMOVE){
//                     Data value;

//                     std::cout << "\n\t\tInsert the [Value] to remove:\n";
//                     std::cout << "\n\t\t> ";

//                     getValue(value);

//                     if(con.Remove(value)){
//                         std::cout << "\n\t\tThe value was successfully removed from the dictionary!\n";
//                     }
//                     else{
//                         std::cout << "\n\t\tRemove failed!\n";
//                     }
//                 }
//                 else{
//                     throw std::invalid_argument("");
//                 }

//             }
//             else if(parsed_input == OP_LIST){
//                 unsigned short in;
                
//                 std::cout << "\n\t\tSelect the list operation:\n";

//                 std::cout << "\n\t\t(" << OP_INSERT_FRONT << ") INSERT AT FRONT: Insert value at the front of the list\n";
//                 std::cout << "\t\t(" << OP_INSERT_BACK << ") INSERT AT BACK: Insert value at the back of the list\n";
//                 std::cout << "\t\t(" << OP_FRONT_N_REMOVE << ") FRONT & REMOVE: Remove and receive value from the front of the list\n";
//                 std::cout << "\n\t\t(0) to Exit\n";

//                 std::cout << "\n\t\t> ";

//                 getValue(in);

//                 if(in == 0){
//                     continue;
//                 }
//                 else if(in == OP_INSERT_FRONT){
//                     Data value;

//                     std::cout << "\n\t\tInsert the [Value] to insert at front:\n";
//                     std::cout << "\n\t\t> ";

//                     getValue(value);

//                     con.InsertAtFront(value);

//                     std::cout << "\n\t\tThe value was successfully added to the front of the list!\n";
                    
//                 }
//                 else if(in == OP_INSERT_BACK){
//                     Data value;

//                     std::cout << "\n\t\tInsert the [Value] to insert at back:\n";
//                     std::cout << "\n\t\t> ";

//                     getValue(value);

//                     con.InsertAtBack(value);

//                     std::cout << "\n\t\tThe value was successfully added to the back of the list!\n";
//                 }
//                 else if(in == OP_FRONT_N_REMOVE){

//                     Data res = con.FrontNRemove();
//                     std::cout << "\n\t\tFront: " << res << "\n";

//                     std::cout << "\n\t\tThe front of the list was successfully removed!\n";
//                 }
//                 else{
//                     throw std::invalid_argument("");
//                 }
                
//             }
//             else if(parsed_input == OP_FILL){
//                 std::cout << "\n\t\tRandomizing container contents...\n\n";
//                 fillList(con);
//                 std::cout << "\n\t\tContainer successfully filled!\n\n";
//             }
//             else{
//                 throw std::invalid_argument("");
//             }
//         }
//         catch(const std::length_error& err){
//             std::cout << "\n\t\t[!] " << err.what() << "\n";
//         }
//         catch(const std::out_of_range& err){
//             std::cout << "\n\t\t[!] " << err.what() << "\n";
//         }
//         catch(const std::logic_error& err){
//             std::cout << "\n\t\t[!] Invalid option. Please retry.\n";
//         }

//     }while(true);
    
// }

// template <typename Data>
// void testStack(lasd::Stack<Data> & con){
//     const unsigned short OP_VIEW = 1;
//     const unsigned short OP_CLEAR = 2;
//     const unsigned short OP_PUSH = 3;
//     const unsigned short OP_TOP_N_POP = 4;
//     const unsigned short OP_FILL = 5;

//     unsigned short parsed_input;

//     do{
//         std::cout << "\n\t\t!~~~~~~~ STACK ~~~~~~~!\n";

//         std::cout << "\n\t\tSelect operation:\n";

//         std::cout << "\n\t\t(" << OP_VIEW << ") VIEW: View container\n";
//         std::cout << "\t\t(" << OP_CLEAR << ") CLEAR: Clear container\n";
//         std::cout << "\t\t(" << OP_PUSH << ") PUSH: Push value onto stack\n";
//         std::cout << "\t\t(" << OP_TOP_N_POP << ") TOP & POP: Pop value off stack and receive top\n";
//         std::cout << "\t\t(" << OP_FILL << ") FILL: Populate container with randomized values\n";
//         std::cout << "\n\t\t(0) to Exit\n";

//         std::cout << "\n\t\t> ";

//         try{
//             getValue(parsed_input);

//             if(parsed_input == 0){
//                 break;
//             }
//             else if(parsed_input == OP_VIEW){
//                 std::cout << "\n\t\tViewing container...\n\n";
//                 con.View();
//             }
//             else if(parsed_input == OP_CLEAR){
//                 con.Clear();
//                 std::cout << "\n\t\tContainer successfully cleared!\n\n";
//             }
//             else if(parsed_input == OP_PUSH){
//                 Data value;

//                 std::cout << "\n\t\tInsert the [Value] to push onto the top of the stack:\n";
//                 std::cout << "\n\t\t> ";

//                 getValue(value);

//                 con.Push(value);

//                 std::cout << "\n\t\tThe value was successfully pushed onto the stack!\n\n";
//             }
//             else if(parsed_input == OP_TOP_N_POP){
//                 Data res = con.TopNPop();
//                 std::cout << "\n\t\tTop: " << res << "\n";
//                 std::cout << "\n\t\tPop successful!\n\n";
//             }
//             else if(parsed_input == OP_FILL){
//                 std::cout << "\n\t\tRandomizing container contents...\n\n";
//                 fillStack(con);
//                 std::cout << "\n\t\tContainer successfully filled!\n\n";
//             }
//             else{
//                 throw std::invalid_argument("");
//             }
//         }
//         catch(const std::length_error& err){
//             std::cout << "\n\t\t[!] " << err.what() << "\n";
//         }
//         catch(const std::out_of_range& err){
//             std::cout << "\n\t\t[!] " << err.what() << "\n";
//         }
//         catch(const std::logic_error& err){
//             std::cout << "\n\t\t[!] Invalid option. Please retry.\n";
//         }

//     }while(true);

    
// }

// template <typename Data>
// void testQueue(lasd::Queue<Data> & con){
//     const unsigned short OP_VIEW = 1;
//     const unsigned short OP_CLEAR = 2;
//     const unsigned short OP_ENQUEUE = 3;
//     const unsigned short OP_HEAD_N_DEQUEUE = 4;
//     const unsigned short OP_FILL = 5;

//     unsigned short parsed_input;

//     do{
//         std::cout << "\n\t\t!~~~~~~~ QUEUE ~~~~~~~!\n";

//         std::cout << "\n\t\tSelect operation:\n";

//         std::cout << "\n\t\t(" << OP_VIEW << ") VIEW: View container\n";
//         std::cout << "\t\t(" << OP_CLEAR << ") CLEAR: Clear container\n";
//         std::cout << "\t\t(" << OP_ENQUEUE << ") ENQUEUE: Enqueue value\n";
//         std::cout << "\t\t(" << OP_HEAD_N_DEQUEUE << ") HEAD & DEQUEUE: Dequeue value and receive head\n";
//         std::cout << "\t\t(" << OP_FILL << ") FILL: Populate container with randomized values\n";
//         std::cout << "\n\t\t(0) to Exit\n";

//         std::cout << "\n\t\t> ";

//         try{
//             getValue(parsed_input);

//             if(parsed_input == 0){
//                 break;
//             }
//             else if(parsed_input == OP_VIEW){
//                 std::cout << "\n\t\tViewing container...\n\n";
//                 con.View();
//             }
//             else if(parsed_input == OP_CLEAR){
//                 con.Clear();
//                 std::cout << "\n\t\tContainer successfully cleared!\n\n";
//             }
//             else if(parsed_input == OP_ENQUEUE){
//                 Data value;

//                 std::cout << "\n\t\tInsert the [Value] to enqueue:\n";
//                 std::cout << "\n\t\t> ";

//                 getValue(value);

//                 con.Enqueue(value);

//                 std::cout << "\n\t\tThe value was successfully enqueued!\n\n";
//             }
//             else if(parsed_input == OP_HEAD_N_DEQUEUE){
//                 Data res = con.HeadNDequeue();
//                 std::cout << "\n\t\tHead: " << res << "\n";
//                 std::cout << "\n\t\tDequeue successful!\n\n";
//             }
//             else if(parsed_input == OP_FILL){
//                 std::cout << "\n\t\tRandomizing container contents...\n\n";
//                 fillQueue(con);
//                 std::cout << "\n\t\tContainer successfully filled!\n\n";
//             }
//             else{
//                 throw std::invalid_argument("");
//             }
//         }
//         catch(const std::length_error& err){
//             std::cout << "\n\t\t[!] " << err.what() << "\n";
//         }
//         catch(const std::out_of_range& err){
//             std::cout << "\n\t\t[!] " << err.what() << "\n";
//         }
//         catch(const std::logic_error& err){
//             std::cout << "\n\t\t[!] Invalid option. Please retry.\n";
//         }

//     }while(true);
// }





int generateInt(){
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> int_dist(0, 10000);

    return int_dist(gen);
}

float generateFloat(){
    std::default_random_engine gen(std::random_device{}());
    std::uniform_real_distribution<float> float_dist(0, 100);

    return float_dist(gen);
}

std::string generateString()
{
    const std::string CHARACTERS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);

    std::string generateString;

    for (std::size_t i = 0; i < 10; ++i)
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

