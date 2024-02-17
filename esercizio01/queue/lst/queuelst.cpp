#include <iostream>

namespace lasd {

/* ************************************************************************** */

template<typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(const QueueLst& con){
    List<Data>::operator=(con);
    return *this;
}

template<typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(QueueLst&& con) noexcept{
    List<Data>::operator=(std::move(con));
    return *this;
}

template<typename Data>
inline bool QueueLst<Data>::operator==(const QueueLst& con) const noexcept{
    return List<Data>::operator==(con);
}

template<typename Data>
inline bool QueueLst<Data>::operator!=(const QueueLst& con) const noexcept{
    return List<Data>::operator!=(con);
}

template<typename Data>
inline const Data& QueueLst<Data>::Head() const{
    return List<Data>::Front();
}

template<typename Data>
inline Data& QueueLst<Data>::Head() {
    return List<Data>::Front();
}

template<typename Data>
inline void QueueLst<Data>::Dequeue() {
    List<Data>::RemoveFromFront();
}

template<typename Data>
inline Data QueueLst<Data>::HeadNDequeue() {
    return List<Data>::FrontNRemove();
}

template<typename Data>
inline void QueueLst<Data>::Enqueue(const Data& dat) {
    List<Data>::InsertAtBack(dat);
}

template<typename Data>
inline void QueueLst<Data>::Enqueue(Data&& dat) noexcept {
    List<Data>::InsertAtBack(dat);
}

template<typename Data>
inline void QueueLst<Data>::View() const noexcept{
    std::cout << "Size = " << this->Size() << "\n\n";
    
    this->Map([this](const Data& dat){
        if(this->Head() == dat){
            std::cout << "Head ->    ";
        }
        else{
            std::cout << "           ";
        }

        std::cout << dat << "\n";
    });
}

/* ************************************************************************** */

}
