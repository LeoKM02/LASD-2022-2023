
namespace lasd {

/* ************************************************************************** */

template<typename Data>
StackLst<Data>::StackLst(const MappableContainer<Data>& con){
    List<Data>::List(con);
}

template<typename Data>
StackLst<Data>::StackLst(MutableMappableContainer<Data>&& con) noexcept {
    List<Data>::List(std::move(con));
}

template<typename Data>
StackLst<Data>::StackLst(const StackLst& con){
    List<Data>::List(con);
}

template<typename Data>
StackLst<Data>::StackLst(StackLst&& con) noexcept {
    List<Data>::List(std::move(con));
}

template<typename Data>
StackLst<Data>& StackLst<Data>::operator=(const StackLst& con){
    List<Data>::operator=(con);
    return *this;
}

template<typename Data>
StackLst<Data>& StackLst<Data>::operator=(StackLst&& con) noexcept{
    List<Data>::operator=(std::move(con));
    return *this;
}

template<typename Data>
inline bool StackLst<Data>::operator==(const StackLst& con) const noexcept{
    return List<Data>::operator==(con);
}

template<typename Data>
inline bool StackLst<Data>::operator!=(const StackLst& con) const noexcept{
    return List<Data>::operator!=(con);
}

template<typename Data>
inline const Data& StackLst<Data>::Top() const{
    return Front();
} // (non-mutable version; concrete function must throw std::length_error when empty)

template<typename Data>
inline Data& StackLst<Data>::Top(){
    return Front();
} // (mutable version; concrete function must throw std::length_error when empty)

template<typename Data>
inline void StackLst<Data>::Pop(){
    RemoveFromFront();
} // (concrete function must throw std::length_error when empty)

template<typename Data>
inline Data StackLst<Data>::TopNPop(){
    Data top = Top();
    Pop();
    return top;
} // (concrete function must throw std::length_error when empty)

template<typename Data>
inline void StackLst<Data>::Push(const Data& dat){
    InsertAtFront(dat);
} // Copy of the value

template<typename Data>
inline void StackLst<Data>::Push(Data&& dat) noexcept{
    InsertAtFront(std::move(dat));
} // Move of the value

/* ************************************************************************** */

}
