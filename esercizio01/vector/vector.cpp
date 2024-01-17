
namespace lasd {

/* ************************************************************************** */

template<typename Data>
Vector<Data>::Vector(const ulong s){
    size = s;
    elements = new Data[size]{};
}

template<typename Data>
Vector<Data>::Vector(const MappableContainer<Data>& con){
    size = con.size;
    elements = new Data[size]{};
    ulong i = 0;
    con.Map([this, &i](const Data& dat){
        elements[i] = dat;
        ++i;
    });
}

template<typename Data>
Vector<Data>::Vector(MutableMappableContainer<Data>&& con) {
    size = con.Size();
    elements = new Data[size]{};
    ulong i = 0;
    con.Map([this, &i](Data& dat){
        elements[i] = std::move(dat);
        ++i;
    });
}

template<typename Data>
Vector<Data>::Vector(const Vector& con) {
    size = con.size;
    std::copy(con.elements, con.elements + con.size, elements);
}

template<typename Data>
Vector<Data>::Vector(Vector&& con) noexcept {
    std::swap(con.size, size);
    std::swap(con.elements, elements);
}

template<typename Data>
Vector<Data>::~Vector(){
    delete[] elements;
}

template<typename Data>
Vector<Data>& Vector<Data>::operator=(const Vector& con){
    Vector * newcon = new Vector(con);
    std::swap(*newcon, *this);
    delete newcon;
    return *this;
}

template<typename Data>
Vector<Data>& Vector<Data>::operator=(Vector&& con) noexcept {
    Vector * newcon = new Vector(con);
    std::swap(*newcon, *this);
    delete newcon;
    return *this;
}

template<typename Data>
inline bool Vector<Data>::operator==(const Vector& con) const noexcept {
    if(size == con.size){
        for(ulong i=0; i<size; ++i){
            if(elements[i] != con.elements[i]){
                return false;
            }
        }
        return true;
    }
    else{
        return false;
    }
}

template<typename Data>
inline bool Vector<Data>::operator!=(const Vector& con) const noexcept {
    if(size == con.size){
        for(ulong i=0; i<size; ++i){
            if(elements[i] != con.elements[i]){
                return true;
            }
        }
        return false;
    }
    else{
        return true;
    }
}

template<typename Data>
inline void Vector<Data>::Clear() {
    size = 0;
    delete[] elements;
    elements = nullptr;
}

template<typename Data>
inline void Vector<Data>::Resize(const ulong newsize) {
    size = newsize;
    if(s>0){
        Data * temp = new Data[newsize];
        ulong lim = (size < newsize)? size : newsize;
        ulong i;
        while(i<lim){
            temp[i++] = elements[i];
        }
        while(i<newsize){
            temp[i++] = 0;
        }
        delete[] elements;
        elements = temp;
    }
    else{
        delete[] elements;
        elements = nullptr;
    }
}

template<typename Data>
inline bool Vector<Data>::Exists(const Data& dat) const noexcept {
    for(ulong i=0; i<size; ++i){
        if(elements[i] == dat){
            return true;
        }
    }
    return false;
}

template<typename Data>
inline const Data& Vector<Data>::operator[](const ulong i) const {
    if(i>=size){
        throw std::out_of_range();
    }
    return elements[i];
}

template<typename Data>
inline Data& Vector<Data>::operator[](const ulong i) {
    if(i>=size){
        throw std::out_of_range();
    }
    return elements[i];
}

template<typename Data>
inline const Data& Vector<Data>::Front() const {
    if(size==0){
        throw std::length_error();
    }
    return elements[0];
}

template<typename Data>
inline Data& Vector<Data>::Front(){
    if(size==0){
        throw std::length_error();
    }
    return elements[0];
}

template<typename Data>
inline const Data& Vector<Data>::Back() const {
    if(size==0){
        throw std::length_error();
    }
    return elements[size - 1];
}

template<typename Data>
inline Data& Vector<Data>::Back(){
    if(size==0){
        throw std::length_error();
    }
    return elements[size - 1];
}

template<typename Data>
inline void Vector<Data>::Sort() noexcept {
    QuickSort(0, size-1);
}

template<typename Data>
void Vector<Data>::QuickSort(const ulong p, const ulong r) noexcept {
    if(p<r){
        ulong q = Partiziona(p, r);
        QuickSort(p, q);
        QuickSort(q+1, r);
    }
}

template<typename Data>
ulong Vector<Data>::Partiziona(const ulong p, const ulong r) noexcept {
    Data x = elements[p];
    ulong i = p-1;
    ulong j = r+1;
    do{
        do{}while(elements[--j]<=x);
        do{}while(elements[++i]>=x);
        if(i<j){
            std::swap(elements[i], elements[j]);
        }
    }while(i>=j);
    return j;
}

/* ************************************************************************** */

}
