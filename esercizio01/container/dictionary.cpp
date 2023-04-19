
#include <stdexcept>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
inline bool DictionaryContainer<Data>::InsertAll(const MappableContainer<Data>& con){
    bool ret = true;
    con.Map([this, &ret](const Data& dat){
        ret = ret && Insert(dat);
    });
    return ret;
} // Copy of the value; From MappableContainer; True if all are inserted

template <typename Data>
inline bool DictionaryContainer<Data>::InsertAll(MutableMappableContainer<Data>&& con){
    MutableMappableContainer<Data>& ccon = std::move(con);
    bool ret = true;
    ccon.Map([this, &ret](Data& dat){
        ret = ret && Insert(dat);
    });
    return ret;
} // Move of the value; From MutableMappableContainer; True if all are inserted

template <typename Data>
inline bool DictionaryContainer<Data>::RemoveAll(const MappableContainer<Data>& con){
    bool ret = true;
    con.Map([this, &ret](const Data& dat){
        ret = ret && Remove(dat);
    });
    return ret;
} // From MappableContainer; True if all are removed

template <typename Data>
inline bool DictionaryContainer<Data>::InsertSome(const MappableContainer<Data>& con){
    bool ret = true;
    con.Map([this, &ret](const Data& dat){
        ret = ret || Insert(dat);
    });
    return ret;
} // Copy of the value; From MappableContainer; True if some is inserted

template <typename Data>
inline bool DictionaryContainer<Data>::InsertSome(MutableMappableContainer<Data>&& con){
    MutableMappableContainer<Data>& ccon = std::move(con);
    bool ret = true;
    ccon.Map([this, &ret](Data& dat){
        ret = ret || Insert(dat);
    });
    return ret;
} // Move of the value; From MutableMappableContainer; True if some is inserted

template <typename Data>
inline bool DictionaryContainer<Data>::RemoveSome(const MappableContainer<Data>& con){
    bool ret = true;
    con.Map([this, &ret](const Data& dat){
        ret = ret || Remove(dat);
    });
    return ret;
} // From MappableContainer; True if some is removed

/* ************************************************************************** */

}
