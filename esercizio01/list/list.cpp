#include "list.hpp"

namespace lasd {

/* ************************************************************************** */

template<typename Data>
inline List<Data>::Node::Node(const Data& dat){
    elem = dat;
}

template<typename Data>
inline List<Data>::Node::Node(Data&& dat) noexcept {
    elem = std::move(dat);
}

template<typename Data>
inline List<Data>::Node::Node(const Node& nod) {
    elem = nod.elem;
}

template<typename Data>
inline List<Data>::Node::Node(Node&& nod) noexcept {
    std::swap(elem, node.elem);
    std::swap(next, node.next);
}

template<typename Data>
inline bool List<Data>::Node::operator==(const Node& nod) const noexcept{
    if(elem==nod.elem && next==nod.next) return true;
    return false;
}

template<typename Data>
inline bool List<Data>::Node::operator!=(const Node& nod) const noexcept{
    return (! operator==(nod));
}

template<typename Data>
List<Data>::List(const MappableContainer<Data>& con) {
    con.Map([this](const Data& dat){
        InsertAtBack(dat);
    });
}

template<typename Data>
List<Data>::List(MutableMappableContainer<Data>&& con) {
    con.Map([this](Data& dat){
        InsertAtBack(std::move(dat));
    });
}

template<typename Data>
List<Data>::List(const List& con) {
    Node * temp = con.head;
    while(temp != nullptr){
        InsertAtBack(temp->elem);
        temp = temp->next;
    }
}

template<typename Data>
List<Data>::List(List&& con) noexcept{
    std::swap(head, con.head);
    std::swap(tail, con.tail);
    std::swap(size, con.size);
}

template<typename Data>
List<Data>::~List() {
    Clear();
}

template<typename Data>
inline List<Data>& List<Data>::operator=(const List& con){
    List* temp = new List(con);
    std::swap(*temp, *this);
    delete temp;
    return *this;
}

template<typename Data>
inline List<Data>& List<Data>::operator=(List&& con) noexcept {
    std::swap(head, con.head);
    std::swap(tail, con.tail);
    std::swap(size, con.size);
    return *this;
}

template<typename Data>
inline bool List<Data>::operator==(const List& con) const noexcept {
    if(Size() == con.Size()){
        Node* temp = head;
        Node* tempcmp = con.head;
        while(temp != nullptr){
            if(temp->elem != tempcmp->elem){
                return false;
            }
            temp = temp->next;
            tempcmp = tempcmp->next;
        }
        return true;
    }
    return false;
}

template<typename Data>
inline bool List<Data>::operator!=(const List& con) const noexcept {
    return (! operator==(con));
}

template<typename Data>
inline void List<Data>::InsertAtFront(const Data& dat) {
    Node* temp = new Node(dat);
    if(head != nullptr){
        temp->next = head;
    }
    else{
        tail = temp;
    }
    head = temp;
    ++size;
}

template<typename Data>
inline void List<Data>::InsertAtFront(Data&& dat) noexcept {
    Node* temp = new Node(std::move(dat));
    if(head != nullptr){
        temp->next = head;
    }
    else{
        tail = temp;
    }
    head = temp;
    ++size;
}

template<typename Data>
inline void List<Data>::RemoveFromFront() {
    if(Size() == 0){
        throw std::length_error();
    }
    Node * temp = head->next;
    delete head;
    head = temp;
    if(head == nullptr){
        tail = nullptr;
    }
    --size;
}

template<typename Data>
inline Data List<Data>::FrontNRemove() {
    if(Size() == 0){
        throw std::length_error();
    }

    Data ret = Front();
    RemoveFromFront();
    return ret;
}

template<typename Data>
inline void List<Data>::InsertAtBack(const Data& dat) {
    Node* temp = new Node(dat);
    if(tail != nullptr){
        tail->next = temp;
    }
    else{
        head = temp;
    }
    tail = temp;
    ++size;
}

template<typename Data>
inline void List<Data>::InsertAtBack(Data&& dat) noexcept {
    Node* temp = new Node(std::move(dat));
    if(tail != nullptr){
        tail->next = temp;
    }
    else{
        head = temp;
    }
    tail = temp;
    ++size;
}

template<typename Data>
inline void List<Data>::Clear() {
    while(head != nullptr){
        RemoveFromFront();
    }
}

template<typename Data>
inline bool List<Data>::Exists(const Data& dat) const noexcept {
    Node * temp = head;
    while(temp != nullptr){
        if(temp->elem == dat){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

template<typename Data>
inline bool List<Data>::Insert(const Data& dat) {
    if(Exists(dat)){
        return false;
    }
    else{
        InsertAtBack(dat);
        return true;
    }
}

template<typename Data>
inline bool List<Data>::Insert(Data&& dat) {
    if(Exists(dat)){
        return false;
    }
    else{
        InsertAtBack(std::move(dat));
        return true;
    }
}

template<typename Data>
inline bool List<Data>::Remove(const Data& dat) {
    bool res = false;
    
    while(head!=nullptr && head->elem==dat){
        RemoveFromFront();
        res = true;
    }

    if(head != nullptr){
        Node* curr = head->next;
        Node* prev = head;
        Node* temp = nullptr;

        while(curr != nullptr){
            if(curr->elem == dat){
                temp = curr;
                prev->next = curr->next;
                curr = curr->next;
                res = true;
                if(tmp == tail){
                    tail = prev;
                }
                delete tmp;
                --size;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
            
        }
    }

    return res;
}

template<typename Data>
inline const Data& List<Data>::operator[](const ulong index) const {
    if(index >= Size()){
        throw std::out_of_range();
    }

    if(index == Size() - 1){
        return tail->elem;
    }

    Node* temp = head;
    ulong i = 0;
    while(i < index){
        temp = temp->next;
        ++i;
    }
    return temp->elem;
}

template<typename Data>
inline Data& List<Data>::operator[](const ulong index) {
    if(index >= Size()){
        throw std::out_of_range();
    }

    if(index == Size() - 1){
        return tail->elem;
    }

    Node* temp = head;
    ulong i = 0;
    while(i < index){
        temp = temp->next;
        ++i;
    }
    return temp->elem;
}

template<typename Data>
inline const Data& List<Data>::Front() const {
    if(Size() == 0){
        throw std::length_error();
    }
    return head->elem;
}

template<typename Data>
inline Data& List<Data>::Front() {
    if(Size() == 0){
        throw std::length_error();
    }
    return head->elem;
}

template<typename Data>
inline const Data& List<Data>::Back() const {
    if(Size() == 0){
        throw std::length_error();
    }
    return tail->elem;
}

template<typename Data>
inline Data& List<Data>::Back() {
    if(Size() == 0){
        throw std::length_error();
    }
    return tail->elem;
}

// Inherited member functions

template<typename Data>
inline void List<Data>::Fold(FoldFunctor fun, void * ret) const {
    PreOrderFold(fun, ret);
}

template<typename Data>
inline void List<Data>::PreOrderFold(FoldFunctor fun, void * ret) const {
    PreOrderFold(fun, ret, head);
}

template<typename Data>
inline void List<Data>::PostOrderFold(FoldFunctor fun, void * ret) const {
    PostOrderFold(fun, ret, head);
}

template<typename Data>
inline void List<Data>::Map(MapFunctor fun) const {
    PreOrderMap(fun);
}

template<typename Data>
inline void List<Data>::PreOrderMap(MapFunctor fun) const {
    PreOrderFold(fun, head);
}

template<typename Data>
inline void List<Data>::PostOrderMap(MapFunctor fun) const {
    PostOrderMap(fun, head);
}

template<typename Data>
inline void List<Data>::Map(MutableMapFunctor fun) {
    PreOrderMap(fun);
}

template<typename Data>
inline void List<Data>::PreOrderMap(MutableMapFunctor fun) {
    PreOrderMap(fun, head);
}

template<typename Data>
inline void List<Data>::PostOrderMap(MutableMapFunctor fun) {
    PostOrderMap(fun, head);
}

// Auxiliary member functions

template <typename Data>
inline void List<Data>::PreOrderFold(FoldFunctor fun, void * ret, Node * nod) const {
    if(nod != nullptr){
        fun(nod->elem, ret);
        PostOrderFold(fun, ret, nod->next);
    }
}

template<typename Data>
inline void List<Data>::PostOrderFold(FoldFunctor fun, void * ret, Node * nod) const {
    if(nod != nullptr){
        PostOrderFold(fun, ret, nod->next);
        fun(nod->elem, ret);
    }
}

template <typename Data>
inline void List<Data>::PreOrderMap(MapFunctor fun, Node * nod) const {
    if(nod != nullptr){
        fun(nod->elem);
        PostOrderMap(fun, nod->next);
    }
}

template<typename Data>
inline void List<Data>::PostOrderMap(MapFunctor fun, Node * nod) const {
    if(nod != nullptr){
        PostOrderMap(fun, nod->next);
        fun(nod->elem);
    }
}

template <typename Data>
inline void List<Data>::PreOrderMap(MutableMapFunctor fun, Node * nod) {
    if(nod != nullptr){
        fun(nod->elem);
        PostOrderMap(fun, nod->next);
    }
}

template <typename Data>
inline void List<Data>::PostOrderMap(MutableMapFunctor fun, Node * nod) {
    if(nod != nullptr){
        PostOrderMap(fun, nod->next);
        fun(nod->elem);
    }
}

/* ************************************************************************** */

}
