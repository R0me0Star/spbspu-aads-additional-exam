#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>

namespace pozdnyakov {
  template< class T >
  struct Array {
    T * data;
    std::size_t size;
    std::size_t capacity;
  };

  template< class T >
  void pushBack(Array< T > & array, const T & value)
  {}

  template< class T >
  void clear(Array< T > & array) noexcept
  {
    delete[] array.data;
    array.data = nullptr;
    array.size = 0;
    array.capacity = 0;
  }
}

#endif
