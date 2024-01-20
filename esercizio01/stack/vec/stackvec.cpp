
namespace lasd {

/* ************************************************************************** */

template <typename Data>
inline StackVec<Data>::StackVec(const MappableContainer<Data>& con) {
    size = con.Size()*2;
    elements = new Data[size]{};
    con.Map([this](const Data& dat){
        Push(dat);
    });
}

template <typename Data>
inline StackVec<Data>::StackVec(MutableMappableContainer<Data>&& con) noexcept {
    size = con.Size()*2;
    elements = new Data[size]{};
    con.Map([this](Data& dat){
        Push(std::move(dat));
    });
}

template <typename Data>
inline StackVec<Data>::StackVec(const StackVec& con) {
    Vector<Data>(con);
    topIndex == con.topIndex;
}

template <typename Data>
inline StackVec<Data>::StackVec(StackVec&& con) noexcept {
    Vector<Data>(con);
    std::swap(topIndex, con.topIndex);
}

template <typename Data>
inline StackVec<Data>& StackVec<Data>::operator=(const StackVec& con) {
    Vector<Data>::operator=(con);
    topIndex = con.topIndex;
    return *this;
}

template <typename Data>
inline StackVec<Data>& StackVec<Data>::operator=(StackVec&& con) noexcept {
    Vector<Data>::operator=(con);
    std::swap(topIndex, con.topIndex);
    return *this;
}

template <typename Data>
inline bool StackVec<Data>::operator==(const StackVec<Data>& con) const noexcept {
    if(Size() == con.Size()){
        for(ulong i=0; i<Size(); ++i){
            if(elements[i] != con.elements[i]){
                return false;
            }
        }
        return true;
    }
    return false;
}

template <typename Data>
inline bool StackVec<Data>::operator!=(const StackVec<Data>& con) const noexcept {
    return (! operator==(con));
}

template <typename Data>
inline const Data& StackVec<Data>::Top() const {
    if(Empty()){
        throw std::length_error();
    }
    return elements[Size()-1];
}

template <typename Data>
inline Data& StackVec<Data>::Top() {
    if(Empty()){
        throw std::length_error();
    }
    return elements[Size()-1];
}

template <typename Data>
inline void StackVec<Data>::Pop() {
    if(Empty()){
        throw std::length_error();
    }
    --topIndex;
    Reduce();
}

template <typename Data>
inline Data StackVec<Data>::TopNPop() {
    if(Empty()){
        throw std::length_error();
    }
    return elements[--topIndex];
    Reduce();
}

template <typename Data>
inline void StackVec<Data>::Push(const Data& dat) {
    Expand();
    elements[topIndex++] = dat;
}

template <typename Data>
inline void StackVec<Data>::Push(Data&& dat) noexcept {
    Expand();
    elements[topIndex++] = std::move(dat);
}

template <typename Data>
inline bool StackVec<Data>::Empty() const noexcept {
    return (topIndex==0);
}

template <typename Data>
inline ulong StackVec<Data>::Size() const noexcept {
    return topIndex;
}

template <typename Data>
inline void StackVec<Data>::Clear() {
    topIndex = 0;
    Vector<Data>::Resize(DEFAULT_CAPACITY);
}

template <typename Data>
inline void StackVec<Data>::Expand() {
    if(topIndex >= size){
        Vector<Data>::Resize(size * 2);
    }
}

template <typename Data>
inline void StackVec<Data>::Reduce() {
    if(size!=DEFAULT_CAPACITY && topIndex==size/4){
        Vector<Data>::Resize(size / 2);
    }
}

/* ************************************************************************** */

}
