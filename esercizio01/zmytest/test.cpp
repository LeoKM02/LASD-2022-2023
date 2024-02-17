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

        if(structure == VECTOR_ID){
            if(type == INT_ID){
                lasd::Vector<int> vec(DEFAULT_SIZE);
                fillVector(vec);
                testVector(vec);
            }
            else if(type == FLOAT_ID){
                lasd::Vector<float> vec(DEFAULT_SIZE);
                fillVector(vec);
                testVector(vec);
            }
            else if(type == STRING_ID){
                lasd::Vector<std::string> vec(DEFAULT_SIZE);
                fillVector(vec);
                testVector(vec);
            }
        }
        else if(structure == LIST_ID){
            if(type == INT_ID){
                lasd::List<int> lst;
                fillList(lst);
                testList(lst);
            }
            else if(type == FLOAT_ID){
                lasd::List<float> lst;
                fillList(lst);
                testList(lst);
            }
            else if(type == STRING_ID){
                lasd::List<std::string> lst;
                fillList(lst);
                testList(lst);
            }
        }
        else if(structure == STACKVEC_ID){
            if(type == INT_ID){
                lasd::StackVec<int> stkvec;
                fillStack(stkvec);
                testStackVec(stkvec);
            }
            else if(type == FLOAT_ID){
                lasd::StackVec<float> stkvec;
                fillStack(stkvec);
                testStackVec(stkvec);
            }
            else if(type == STRING_ID){
                lasd::StackVec<std::string> stkvec;
                fillStack(stkvec);
                testStackVec(stkvec);
            }
        }
        else if(structure == STACKLST_ID){
            if(type == INT_ID){
                lasd::StackLst<int> stklst;
                fillStack(stklst);
                testStackLst(stklst);
            }
            else if(type == FLOAT_ID){
                lasd::StackLst<float> stklst;
                fillStack(stklst);
                testStackLst(stklst);
            }
            else if(type == STRING_ID){
                lasd::StackLst<std::string> stklst;
                fillStack(stklst);
                testStackLst(stklst);
            }
        }
        else if(structure == QUEUEVEC_ID){
            if(type == INT_ID){
                lasd::QueueVec<int> quevec;
                fillQueue(quevec);
                testQueueVec(quevec);
            }
            else if(type == FLOAT_ID){
                lasd::QueueVec<float> quevec;
                fillQueue(quevec);
                testQueueVec(quevec);
            }
            else if(type == STRING_ID){
                lasd::QueueVec<std::string> quevec;
                fillQueue(quevec);
                testQueueVec(quevec);
            }
        }
        else if(structure == QUEUELST_ID){
            if(type == INT_ID){
                lasd::QueueLst<int> quelst;
                fillQueue(quelst);
                testQueueLst(quelst);
            }
            else if(type == FLOAT_ID){
                lasd::QueueLst<float> quelst;
                fillQueue(quelst);
                testQueueLst(quelst);
            }
            else if(type == STRING_ID){
                lasd::QueueLst<std::string> quelst;
                fillQueue(quelst);
                testQueueLst(quelst);
            }
        }

    }while(true);
}





unsigned short selectStructure(){

    unsigned short parsed_input;

    std::cout << "\n\t!~~~~~~~ STUDENT TEST SUITE ~~~~~~~!\n";

    std::cout << "\n\tChoose the data structure:\n";

    std::cout << "\n\t(" << VECTOR_ID << ") Vector\n";
    std::cout << "\t(" << LIST_ID << ") List\n";
    std::cout << "\t(" << STACKVEC_ID << ") StackVec\n";
    std::cout << "\t(" << STACKLST_ID << ") StackLst\n";
    std::cout << "\t(" << QUEUEVEC_ID << ") QueueVec\n";
    std::cout << "\t(" << QUEUELST_ID << ") QueueLst\n";
    std::cout << "\n\t(0) to Exit\n";

    do{
        std::cout << "\n\t> ";

        try{
            getValue(parsed_input);

            if(
                parsed_input == 0 ||
                parsed_input == VECTOR_ID ||
                parsed_input == LIST_ID ||
                parsed_input == STACKVEC_ID ||
                parsed_input == STACKLST_ID ||
                parsed_input == QUEUEVEC_ID ||
                parsed_input == QUEUELST_ID
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





void fillVector(lasd::Vector<int> & vec){
    for(unsigned long i=0; i<vec.Size(); ++i){
        vec[i] = generateInt();
    }
}

void fillVector(lasd::Vector<float> & vec){    
    for(unsigned long i=0; i<vec.Size(); ++i){
        vec[i] = generateFloat();
    }
}

void fillVector(lasd::Vector<std::string> & vec){
    for(unsigned long i=0; i<vec.Size(); ++i){
        vec[i] = generateString();
    }
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





void fillStack(lasd::Stack<int> & stk){
    for(unsigned long i=0; i<DEFAULT_SIZE; ++i){
        stk.Push(generateInt());
    }
}

void fillStack(lasd::Stack<float> & stk){    
    for(unsigned long i=0; i<DEFAULT_SIZE; ++i){
        stk.Push(generateFloat());
    }
}

void fillStack(lasd::Stack<std::string> & stk){
    for(unsigned long i=0; i<DEFAULT_SIZE; ++i){
        stk.Push(generateString());
    }
}





void fillQueue(lasd::Queue<int> & que){
    for(unsigned long i=0; i<DEFAULT_SIZE; ++i){
        que.Enqueue(generateInt());
    }
}

void fillQueue(lasd::Queue<float> & que){    
    for(unsigned long i=0; i<DEFAULT_SIZE; ++i){
        que.Enqueue(generateFloat());
    }
}

void fillQueue(lasd::Queue<std::string> & que){
    for(unsigned long i=0; i<DEFAULT_SIZE; ++i){
        que.Enqueue(generateString());
    }
}





template <typename Data>
void testVector(lasd::Vector<Data> & vec){
    const unsigned short OP_VIEW = 1;
    const unsigned short OP_CLEAR = 2;
    const unsigned short OP_RESIZE = 3;
    const unsigned short OP_EXISTS = 4;
    const unsigned short OP_ASSIGN = 5;
    const unsigned short OP_FRONT = 6;
    const unsigned short OP_BACK = 7;
    const unsigned short OP_SORT = 8;

    unsigned short parsed_input;

    do{
        std::cout << "\n\t\t!~~~~~~~ VECTOR ~~~~~~~!\n";

        std::cout << "\n\t\tSelect operation:\n";

        std::cout << "\n\t\t(" << OP_VIEW << ") VIEW: View vector\n";
        std::cout << "\t\t(" << OP_CLEAR << ") CLEAR: Clear vector\n";
        std::cout << "\t\t(" << OP_RESIZE << ") RESIZE: Resize vector\n";
        std::cout << "\t\t(" << OP_EXISTS << ") EXISTS: Check existence of value\n";
        std::cout << "\t\t(" << OP_ASSIGN << ") ASSIGN: Assign value to cell\n";
        std::cout << "\t\t(" << OP_FRONT << ") FRONT: View front of vector\n";
        std::cout << "\t\t(" << OP_BACK << ") BACK: View back of vector\n";
        std::cout << "\t\t(" << OP_SORT << ") SORT: Sort vector\n";
        std::cout << "\n\t\t(0) to Exit\n";

        std::cout << "\n\t\t> ";

        try{
            getValue(parsed_input);

            if(parsed_input == 0){
                break;
            }
            else if(parsed_input == OP_VIEW){
                std::cout << "\nViewing vector...\n\n";
                vec.View();
            }
            else if(parsed_input == OP_CLEAR){
                vec.Clear();
                std::cout << "\nVector successfully cleared!\n\n";
            }
            else if(parsed_input == OP_RESIZE){

                unsigned long newsize;

                std::cout << "\nInsert new [Size] for vector > ";

                getValue(newsize);

                vec.Resize(newsize);
                fillVector(vec);

                std::cout << "\nVector successfully resized!\n\n";
            }
            else if(parsed_input == OP_EXISTS){

                Data value;

                std::cout << "\nInsert the [Value] to search inside the vector: > ";

                getValue(value);

                if(vec.Exists(value)){
                    std::cout << "\nValue [ " << value << " ] exists!\n\n";
                }
                else{
                    std::cout << "\nValue [ " << value << " ] does not exists!\n\n";
                }
            }
            else if(parsed_input == OP_ASSIGN){
                unsigned long index;
                Data newvalue;

                std::cout << "\nInsert the [Index] of the cell you would like to assign a value to: > ";

                getValue(index);

                std::cout << "\nInsert the [Value]: > ";

                getValue(newvalue);

                vec[index] = newvalue;

                std::cout << "\nVector successfully updated!\n\n";
            }
            else if(parsed_input == OP_FRONT){
                Data front = vec.Front();
                std::cout << "\nFront: " << front << "\n\n";
            }
            else if(parsed_input == OP_BACK){
                Data back = vec.Back();
                std::cout << "\nBack: " << back << "\n\n";
            }
            else if(parsed_input == OP_SORT){
                vec.Sort();
                std::cout << "\nVector successfully sorted!\n\n";
            }
            else{
                throw std::invalid_argument("");
            }
        }
        catch(const std::length_error& err){
            std::cout << "\t\t[!] " << err.what() << "\n";
        }
        catch(const std::out_of_range& err){
            std::cout << "\t\t[!] " << err.what() << "\n";
        }
        catch(const std::logic_error& err){
            std::cout << "\t\t[!] Invalid option. Please retry.\n";
        }

    }while(true);

}

template <typename Data>
void testList(lasd::List<Data> & lst){
    const unsigned short OP_VIEW = 1;
    const unsigned short OP_2 = 2;
    const unsigned short OP_3 = 3;
    const unsigned short OP_4 = 4;
    const unsigned short OP_5 = 5;
    const unsigned short OP_6 = 6;

    std::string input;
    unsigned short parsed_input;

    do{
        std::cout << "\n\t\t!~~~~~~~ LIST ~~~~~~~!\n";

        std::cout << "\n\t\tSelect operation:\n";

        std::cout << "\n\t\t(" << OP_VIEW << ") View\n";
        std::cout << "\t\t(" << OP_2 << ") a\n";
        std::cout << "\t\t(" << OP_3 << ") a\n";
        std::cout << "\t\t(" << OP_4 << ") a\n";
        std::cout << "\t\t(" << OP_5 << ") a\n";
        std::cout << "\t\t(" << OP_6 << ") a\n";
        std::cout << "\n\t\t(0) to Exit\n";

        std::cout << "\n\t\t> ";
        getline(std::cin, input);

        try{
            parsed_input = std::stoi(input);

            if(parsed_input == 0){
                break;
            }
            else if(parsed_input == OP_VIEW){
                std::cout << "\nViewing data structure...\n\n";
                lst.View();
            }
            else if(parsed_input == OP_2){

            }
            else if(parsed_input == OP_3){

            }
            else if(parsed_input == OP_4){

            }
            else if(parsed_input == OP_5){

            }
            else if(parsed_input == OP_6){

            }
            else{
                throw std::invalid_argument("");
            }
        }
        catch(const std::logic_error& err){
            std::cout << "\t\t[!] Invalid option. Please retry.\n";
        }

    }while(true);
    
}

template <typename Data>
void testStackVec(lasd::StackVec<Data> & stkvec){
    const unsigned short OP_VIEW = 1;
    const unsigned short OP_2 = 2;
    const unsigned short OP_3 = 3;
    const unsigned short OP_4 = 4;
    const unsigned short OP_5 = 5;
    const unsigned short OP_6 = 6;

    std::string input;
    unsigned short parsed_input;

    do{
        std::cout << "\n\t\t!~~~~~~~ STACKVEC ~~~~~~~!\n";

        std::cout << "\n\t\tSelect operation:\n";

        std::cout << "\n\t\t(" << OP_VIEW << ") View\n";
        std::cout << "\t\t(" << OP_2 << ") a\n";
        std::cout << "\t\t(" << OP_3 << ") a\n";
        std::cout << "\t\t(" << OP_4 << ") a\n";
        std::cout << "\t\t(" << OP_5 << ") a\n";
        std::cout << "\t\t(" << OP_6 << ") a\n";
        std::cout << "\n\t\t(0) to Exit\n";
        
        std::cout << "\n\t\t> ";
        getline(std::cin, input);

        try{
            parsed_input = std::stoi(input);

            if(parsed_input == 0){
                break;
            }
            else if(parsed_input == OP_VIEW){
                std::cout << "\nViewing data structure...\n\n";
                stkvec.View();
            }
            else if(parsed_input == OP_2){

            }
            else if(parsed_input == OP_3){

            }
            else if(parsed_input == OP_4){

            }
            else if(parsed_input == OP_5){

            }
            else if(parsed_input == OP_6){

            }
            else{
                throw std::invalid_argument("");
            }
        }
        catch(const std::logic_error& err){
            std::cout << "\t\t[!] Invalid option. Please retry.\n";
        }

    }while(true);
    
}

template <typename Data>
void testStackLst(lasd::StackLst<Data> & stklst){
    const unsigned short OP_VIEW = 1;
    const unsigned short OP_2 = 2;
    const unsigned short OP_3 = 3;
    const unsigned short OP_4 = 4;
    const unsigned short OP_5 = 5;
    const unsigned short OP_6 = 6;

    std::string input;
    unsigned short parsed_input;

    do{
        std::cout << "\n\t\t!~~~~~~~ STACKLST ~~~~~~~!\n";

        std::cout << "\n\t\tSelect operation:\n";

        std::cout << "\n\t\t(" << OP_VIEW << ") View\n";
        std::cout << "\t\t(" << OP_2 << ") a\n";
        std::cout << "\t\t(" << OP_3 << ") a\n";
        std::cout << "\t\t(" << OP_4 << ") a\n";
        std::cout << "\t\t(" << OP_5 << ") a\n";
        std::cout << "\t\t(" << OP_6 << ") a\n";
        std::cout << "\n\t\t(0) to Exit\n";

        std::cout << "\n\t\t> ";
        getline(std::cin, input);

        try{
            parsed_input = std::stoi(input);

            if(parsed_input == 0){
                break;
            }
            else if(parsed_input == OP_VIEW){
                std::cout << "\nViewing data structure...\n\n";
                stklst.View();
            }
            else if(parsed_input == OP_2){

            }
            else if(parsed_input == OP_3){

            }
            else if(parsed_input == OP_4){

            }
            else if(parsed_input == OP_5){

            }
            else if(parsed_input == OP_6){

            }
            else{
                throw std::invalid_argument("");
            }
        }
        catch(const std::logic_error& err){
            std::cout << "\t\t[!] Invalid option. Please retry.\n";
        }

    }while(true);
    
}

template <typename Data>
void testQueueVec(lasd::QueueVec<Data> & quevec){
    const unsigned short OP_VIEW = 1;
    const unsigned short OP_2 = 2;
    const unsigned short OP_3 = 3;
    const unsigned short OP_4 = 4;
    const unsigned short OP_5 = 5;
    const unsigned short OP_6 = 6;

    std::string input;
    unsigned short parsed_input;

    do{
        std::cout << "\n\t\t!~~~~~~~ QUEUEVEC ~~~~~~~!\n";
        
        std::cout << "\n\t\tSelect operation:\n";

        std::cout << "\n\t\t(" << OP_VIEW << ") View\n";
        std::cout << "\t\t(" << OP_2 << ") a\n";
        std::cout << "\t\t(" << OP_3 << ") a\n";
        std::cout << "\t\t(" << OP_4 << ") a\n";
        std::cout << "\t\t(" << OP_5 << ") a\n";
        std::cout << "\t\t(" << OP_6 << ") a\n";
        std::cout << "\n\t\t(0) to Exit\n";

        std::cout << "\n\t\t> ";
        getline(std::cin, input);

        try{
            parsed_input = std::stoi(input);

            if(parsed_input == 0){
                break;
            }
            else if(parsed_input == OP_VIEW){
                std::cout << "\nViewing data structure...\n\n";
                quevec.View();
            }
            else if(parsed_input == OP_2){

            }
            else if(parsed_input == OP_3){

            }
            else if(parsed_input == OP_4){

            }
            else if(parsed_input == OP_5){

            }
            else if(parsed_input == OP_6){

            }
            else{
                throw std::invalid_argument("");
            }
        }
        catch(const std::logic_error& err){
            std::cout << "\t\t[!] Invalid option. Please retry.\n";
        }

    }while(true);
    
}

template <typename Data>
void testQueueLst(lasd::QueueLst<Data> & quelst){
    const unsigned short OP_VIEW = 1;
    const unsigned short OP_2 = 2;
    const unsigned short OP_3 = 3;
    const unsigned short OP_4 = 4;
    const unsigned short OP_5 = 5;
    const unsigned short OP_6 = 6;

    std::string input;
    unsigned short parsed_input;

    do{
        std::cout << "\n\t\t!~~~~~~~ QUEUELST ~~~~~~~!\n";
        
        std::cout << "\n\t\tSelect operation:\n";

        std::cout << "\n\t\t(" << OP_VIEW << ") View\n";
        std::cout << "\t\t(" << OP_2 << ") a\n";
        std::cout << "\t\t(" << OP_3 << ") a\n";
        std::cout << "\t\t(" << OP_4 << ") a\n";
        std::cout << "\t\t(" << OP_5 << ") a\n";
        std::cout << "\t\t(" << OP_6 << ") a\n";
        std::cout << "\n\t\t(0) to Exit\n";
        
        std::cout << "\n\t\t> ";
        getline(std::cin, input);

        try{
            parsed_input = std::stoi(input);

            if(parsed_input == 0){
                break;
            }
            else if(parsed_input == OP_VIEW){
                std::cout << "\nViewing data structure...\n\n";
                quelst.View();
            }
            else if(parsed_input == OP_2){

            }
            else if(parsed_input == OP_3){

            }
            else if(parsed_input == OP_4){

            }
            else if(parsed_input == OP_5){

            }
            else if(parsed_input == OP_6){

            }
            else{
                throw std::invalid_argument("");
            }
        }
        catch(const std::logic_error& err){
            std::cout << "\t\t[!] Invalid option. Please retry.\n";
        }

    }while(true);
    
}





int generateInt(){
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> int_dist(-100, 100);

    return int_dist(gen);
}

float generateFloat(){
    std::default_random_engine gen(std::random_device{}());
    std::uniform_real_distribution<float> float_dist(-1, 1);

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

}

void getValue(std::string & dat){

}


