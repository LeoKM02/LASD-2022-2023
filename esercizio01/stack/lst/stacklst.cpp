#include <iostream>

namespace lasd {

/* ************************************************************************** */

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
    return List<Data>::Front();
} // (non-mutable version; concrete function must throw std::length_error when empty)

template<typename Data>
inline Data& StackLst<Data>::Top(){
    return List<Data>::Front();
} // (mutable version; concrete function must throw std::length_error when empty)

template<typename Data>
inline void StackLst<Data>::Pop(){
    List<Data>::RemoveFromFront();
} // (concrete function must throw std::length_error when empty)

template<typename Data>
inline Data StackLst<Data>::TopNPop(){
    return List<Data>::FrontNRemove();
} // (concrete function must throw std::length_error when empty)

template<typename Data>
inline void StackLst<Data>::Push(const Data& dat){
    List<Data>::InsertAtFront(dat);
} // Copy of the value

template<typename Data>
inline void StackLst<Data>::Push(Data&& dat) noexcept{
    List<Data>::InsertAtFront(dat);
} // Move of the value

template<typename Data>
inline void StackLst<Data>::View() const noexcept{
    std::cout << "Size = " << this->Size() << "\n\n";

    this->Map([this](const Data& dat){
        if(this->Top() == dat){
            std::cout << "Top ->     ";
        }
        else{
            std::cout << "           ";
        }

        std::cout << dat << "\n";
    });
}

/* ************************************************************************** */

}
