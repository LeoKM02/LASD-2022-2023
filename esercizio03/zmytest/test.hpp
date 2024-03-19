#ifndef MYTEST_HPP
#define MYTEST_HPP

#include "../container/container.hpp"
#include "../container/testable.hpp"
#include "../container/dictionary.hpp"
#include "../container/linear.hpp"

#include "../vector/vector.hpp"

#include "../list/list.hpp"

#include "../hashtable/hashtable.hpp"
#include "../hashtable/clsadr/htclsadr.hpp"
#include "../hashtable/opnadr/htopnadr.hpp"

#include <string>
#include <iostream>

#define HTCLSADR_ID 1
#define HTOPNADR_ID 2

#define INT_ID 1
#define FLOAT_ID 2
#define STRING_ID 3

#define DEFAULT_SIZE 100

void mytest();

unsigned short selectStructure();
unsigned short selectType();

template <typename Data>
void fillHashTable(lasd::HashTable<Data> &);
void fillHashTable(lasd::HashTable<int> &);
void fillHashTable(lasd::HashTable<float> &);
void fillHashTable(lasd::HashTable<std::string> &);

template <typename Data>
void testHashTable(lasd::HashTable<Data> &);

int generateInt();
float generateFloat();
std::string generateString();

template <typename Data>
void getValue(Data &){}
void getValue(int &);
void getValue(unsigned short &);
void getValue(unsigned long &);
void getValue(float &);
void getValue(std::string &);

#endif