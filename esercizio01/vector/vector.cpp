
namespace lasd {

/* ************************************************************************** */

template<typename Data>
Vector<Data>::Vector(const ulong s){
    size = s;
    elements = new Data[s]{};
}

template<typename Data>
Vector<Data>::Vector(const MappableContainer& con){
    size = s;
    elements = new Data[s]{};
}

/* ************************************************************************** */

}
