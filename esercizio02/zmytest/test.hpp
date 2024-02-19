#ifndef MYTEST_HPP
#define MYTEST_HPP

#include "../iterator/iterator.hpp"
#include "../list/list.hpp"
#include "../binarytree/binarytree.hpp"
#include "../binarytree/lnk/binarytreelnk.hpp"
#include "../binarytree/vec/binarytreevec.hpp"
#include "../bst/bst.hpp"

#include <string>

#define BTVEC_ID 1
#define BTLNK_ID 2
#define BST_ID 3

#define ITERPRE_ID 1
#define ITERIN_ID 2
#define ITERPOST_ID 3
#define ITERBREADTH_ID 4

#define INT_ID 1
#define FLOAT_ID 2
#define STRING_ID 3

#define DEFAULT_SIZE 10

void mytest();

unsigned short selectStructure();
unsigned short selectType();

template <typename Data>
void fillList(lasd::List<Data> &);
void fillList(lasd::List<int> &);
void fillList(lasd::List<float> &);
void fillList(lasd::List<std::string> &);

template <typename Data>
void testBinaryTree(lasd::BinaryTree<Data> &);
template <typename Data>
void testBST(lasd::BST<Data> &);

template <typename Data>
void testPreOrderIterator(lasd::BTPreOrderIterator<Data> &);
template <typename Data>
void testPostOrderIterator(lasd::BTPostOrderIterator<Data> &);
template <typename Data>
void testInOrderIterator(lasd::BTInOrderIterator<Data> &);
template <typename Data>
void testBreadthIterator(lasd::BTBreadthIterator<Data> &);

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