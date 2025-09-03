#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <string>
#include <initializer_list>


using std::out_of_range;
using std::to_string;
using std::ostream;
using std::endl;
using std::initializer_list;

template<class T>
class Vector {
public:
    // Constructor
    Vector(); // Default constructor

    /*If there are pointers in the class, we must overload the "Big three"
        - Assignment operator
        - Copy constructor
        - Destructor
    */
  
    Vector(const Vector<T>&); // Copy constructor: makes a deep copy from another vector
    Vector(size_t); // Constructor with initial size
    Vector(size_t, const T&); // Constructor with initial size and default value
    Vector(initializer_list<T>); // Constructor with initializer list

    // Destructor
    ~Vector(); // Releases allocated memory

    // Class-member functions
    const Vector<T>& operator=(const Vector<T>&); // Deep-copy assignment operator

    /* Subscript Operator ([]): to access elements by index.
        - Needs to be overloaded twice in the Vector
        - The one is on the left side of the assignment operator is modifiable and returns a reference.
        - The one on the right side is unmodifiable and returns a const reference.
    */
    T& operator [](size_t); // Subscript operator (lvalue)
    const T& operator [](size_t) const; // Subscript operator (rvalue)

    /* at() functions: to access elements by index with bounds checking.
        - Also needs to be overloaded twice in the Vector
     */
    T& at(size_t); // Returns the item at user-specified index (l-value)
    const T& at(size_t) const; // Returns the item at user-specified index (r-value)
    size_t size() const; // Returns the number of items in the vector
    bool empty() const; // Checks whether the vector is empty
    T& front(); // Returns a reference to the first element
    const T& front() const; // Returns a const reference to the first element
    T& back(); // Returns a reference to the last element
    const T& back() const; // Returns a const reference to the last element
    void push_back(const T&); // Inserts an element to the rear end of the vector
    void pop_back(); // Deletes the last element from the vector
    void insert(size_t, const T&); // Inserts an element at user-specified index
    void erase(size_t); // Deletes the element at user-specified index
    void clear(); // Deletes all elements from the vector
    void shrink_to_fit(); // Reduces capacity to fit the current size
    Vector<T> operator + (const Vector<T>&) const; // Overloads the + operator to concatenate two vectors
    Vector<T>& operator += (const Vector<T>&); // Overloads the += operator to append another vector



private:
    // Data fields
    static const size_t DEFAULT_CAPACITY; // Default initial capacity
    T* data; // Array to store the items in the vector
    size_t capacity; // Size of the allocated storage
    size_t num_of_items; // Number of items stored in the vector

    // Class member functions
    void resize(); // Doubles the capacity of the vector
    void reserve(size_t); // Reserves memory for a specified number of items
};

/* Implementation Vector class*/

// Static attribute
template<class T>
const size_t Vector<T>::DEFAULT_CAPACITY = 10;

// Constructors

// Default constructor
template<class T>
Vector<T>::Vector() : capacity(DEFAULT_CAPACITY), num_of_items(0) {
    data = new T[capacity]; // Allocate memory for the vector
} // Time complexity: O(1)

// Copy constructor
template<class T>
Vector<T>::Vector(const Vector<T>& other) {
    // Step 1: set all pointers to NULL
    data = NULL;

    // Step 2: Use the assignment operator to copy the data
    *this = other;
} // Time complexity: O(n)

// Constructor with initial size
template<class T>
Vector<T>::Vector(size_t initial_size) : num_of_items(initial_size) {
    capacity = initial_size < 10 ? 10 : initial_size; // Ensure minimum capacity
    data = new T[capacity]; // Allocate memory for the vector
    num_of_items = initial_size;
} // Time complexity: O(n)

// Constructor with initial size and default value
template<class T>
Vector<T>::Vector(size_t initial_size, const T& initial_value) {
    capacity = initial_size < 10 ? 10 : initial_size;
    num_of_items = initial_size;
    data = new T[capacity]; // Allocate memory for the vector
    for (size_t i = 0; i < num_of_items; ++i) {
        data[i] = initial_value; // Initialize all elements to the default value
    }
} // Time complexity: O(n)

// Constructor with initializer list
template<class T>
Vector<T>::Vector(initializer_list<T> init_list) {
    num_of_items = init_list.size();
    capacity = num_of_items < 10 ? 10 : num_of_items;
    data = new T[capacity]; // Allocate memory for the vector

    // Copy elements from the initializer list to the vector
    size_t i = 0;
    for (typename initializer_list<T>::const_iterator it = init_list.begin(); it != init_list.end(); ++it, ++i) {
        data[i] = *it;
    }
} // Time complexity: O(n)

// Destructor
template<class T>
Vector<T>::~Vector() {
    if (data) {
        delete[] data;
    }
} // Time complexity: O(1)

// Class-member functions

// Deep-copy assignment operator
template<class T>
const Vector<T>& Vector<T>::operator = (const Vector<T>& rhs) {
    // Step 1: Avoid self-assignment
    if (this != &rhs) {
        // Step 2: Delete all current dynamic memory.
        if (data) {
            delete[] data;
            data = NULL; // Set pointer to safe value after deletion
        }
        // Step 3: Copy static data fields
        capacity = rhs.capacity;
        num_of_items = rhs.num_of_items;

        // Step 4: Copy dynamic data fields.
        if (capacity) {
            data = new T[capacity]; // Allocate new memory
            for (size_t i = 0; i < num_of_items; ++i) {
                data[i] = rhs.data[i]; // Deep-copy each item
            }
        }
    }
    // Step 5: Return the current object
    return *this;
} // Time complexity: O(n)

// Subscript Operator - lvalue
template<class T>
T& Vector<T>::operator [](size_t index) {
    return data[index]; // Return a reference to the element at the specified index
} // Time complexity: O(1)

// Subscript Operator - rvalue
template<class T>
const T& Vector<T>::operator [](size_t index) const {
    return data[index]; // Return a const reference to the element at the specified index
} // Time complexity: O(1)

// Returns the item at user-specified index (l-value)
template<class T>
T& Vector<T>::at(size_t index) {
    if (index >= num_of_items) {
        throw out_of_range("Index out of bounds: " + to_string(index));
    }
    return data[index];
} // Time complexity: O(1)

// Returns the item at user-specified index (r-value)
template<class T>
const T& Vector<T>::at(size_t index) const {
    if (index >= num_of_items) {
        throw out_of_range("Index out of bounds: " + to_string(index));
    }
    return data[index];
} // Time complexity: O(1)

// Returns the number of items in the vector
template<class T>
size_t Vector<T>::size() const {
    return num_of_items;
} // Time complexity: O(1)

// Checks whether the vector is empty
template<class T>
bool Vector<T>::empty() const {
    return !size();
} // Time complexity: O(1)

// Returns a reference to the first element (l-value)
template<class T>
T& Vector<T>::front() {
    if (empty()) {
        throw out_of_range("Vector is empty");
    }
    return data[0];
} // Time complexity: O(1)

// Returns a const reference to the first element (r-value)
template<class T>
const T& Vector<T>::front() const {
    if (empty()) {
        throw out_of_range("Vector is empty");
    }
    return data[0];
} // Time complexity: O(1)

// Returns a reference to the last element (l-value)
template<class T>
T& Vector<T>::back() {
    if (empty()) {
        throw out_of_range("Vector is empty");
    }
    return data[num_of_items - 1];
} // Time complexity: O(1)

// Returns a const reference to the last element (r-value)
template<class T>
const T& Vector<T>::back() const {
    if (empty()) {
        throw out_of_range("Vector is empty");
    }
    return data[num_of_items - 1];
} // Time complexity: O(1)

// Doubles the capacity of the vector without changing the current data stored in it.
template<class T>
void Vector<T>::resize() {
    size_t new_capacity = (capacity == 0) ? DEFAULT_CAPACITY : capacity * 2; // Determine new capacity
    T* new_data = new T[new_capacity]; // Allocate new memory

    // Copy existing elements to the new memory block
    try {
        for (size_t i = 0; i < num_of_items; ++i) {
            new_data[i] = data[i];
        }
    } catch (...) { // Handle any exceptions that occur during copying
        delete[] new_data;
        throw;
    }
    delete[] data; // Release old memory
    data = new_data; // Point to the new memory block
    capacity = new_capacity; // Update capacity
} // Time complexity: O(n)

// Inserts an item to the rear end of the vector
template<class T>
void Vector<T>::push_back(const T& item) {
    if (size() == capacity) {
        resize();
    }
    data[num_of_items++] = item;
} // Time complexity: O(1)

// Deletes the last element from the vector
template<class T>
void Vector<T>::pop_back() {
    if (empty()) {
        throw out_of_range("Vector is empty");
    }
    --num_of_items;
} // Time complexity: O(1)

// Inserts an element at user-specified index
template<class T>
void Vector<T>::insert(size_t index, const T& item) {
    if (index > num_of_items) {
        throw out_of_range("Index out of bounds: " + to_string(index));
    }
    if (num_of_items == capacity) {
        resize(); // ensure data[size()] is valid
    }

    // Data right shifting: make room at index
    for (size_t i = num_of_items; i > index; --i) {
        data[i] = data[i - 1];  // Shift elements to the right
    }
    data[index] = item; // Insert the new item
    ++num_of_items;
} // Time complexity: O(n)

// Deletes the element at user-specified index
template<class T>
void Vector<T>::erase(size_t index) {
    if (index >= num_of_items) {
        throw out_of_range("Index out of bounds: " + to_string(index));
    }

    // Data shifting
    for (size_t i = index; i < num_of_items - 1; ++i) {
        data[i] = data[i + 1]; // Shift elements to the left
    }
    --num_of_items;
} // Time complexity: O(n)

// Deletes all elements from the vector
template<class T>
void Vector<T>::clear() {
    delete[] data;
    data = NULL;
    capacity = 0;
    num_of_items = 0;
} // Time complexity: O(n)

// Reduces capacity to fit the current size
template<class T>
void Vector<T>::shrink_to_fit() {
    if (size() < capacity) {
        T* new_data = new T[size()];
        for (size_t i = 0; i < size(); ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = size();
    }
} // Time complexity: O(n)

// Reserves memory for a specified number of items
template<class T>
void Vector<T>::reserve(size_t new_capacity) {
    if (new_capacity <= capacity) { return; }
    T* new_data = new T[new_capacity];
    try {
        for (size_t i = 0; i < size(); ++i) {
            new_data[i] = data[i];
        }
    } catch (...) {
        delete[] new_data;
        throw;
    }
    delete[] data;
    data = new_data;
    capacity = new_capacity;
} // Time complexity: O(n)

// Overloads the += operator to append another vector
template<class T>
Vector<T>& Vector<T>::operator += (const Vector<T>& other) {

    // Self-append check
    if (&other == this) {
        // self-append: copy current range to a temp first
        const size_t n = num_of_items;
        if (n == 0) return *this;
        reserve(num_of_items + n);

        T* tmp = new T[n];
        try {
            for (size_t i = 0; i < n; ++i) tmp[i] = data[i];
            for (size_t i = 0; i < n; ++i) data[num_of_items + i] = tmp[i];
        } catch (...) { delete[] tmp; throw; }
        delete[] tmp;
        num_of_items += n;
        return *this;
    }

    size_t old_size = size();
    reserve(size() + other.size());
    for (size_t i = 0; i < other.size(); ++i) {
        data[old_size + i] = other.data[i];
    }
    num_of_items += other.size();
    return *this;
} // Time complexity: O(n)

// Overloads the + operator to concatenate two vectors
template<class T>
Vector<T> Vector<T>::operator + (const Vector<T>& other) const {
    Vector<T> result = *this; // Start with a copy of the current vector
    result += other; // Use the += operator to append the other vector
    return result;
} // Time complexity: O(n)

// Stream insertion operator
template<class T>
ostream& operator << (ostream& out, const Vector<T>& vec) {
    out << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        out << vec.at(i);
        if (i < vec.size() - 1) {
            out << ", ";
        }
    }
    out << "]";
    return out;
} // Time complexity: O(n)



#endif
