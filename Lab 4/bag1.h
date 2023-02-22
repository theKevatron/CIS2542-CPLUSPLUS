// Lab #4 - CIS 2542 NET03
// Kevin Morales
// 
// FILE: bag1.h
// CLASS PROVIDED: bag (part of the namespace main_savitch_3)
//
// TYPEDEF and MEMBER CONSTANTS for the bag class:
//   typedef ____ value_type
//     bag::value_type is the data type of the items in the bag. It may be any of
//     the C++ built-in types (int, char, etc.), or a class with a default
//     constructor, an assignment operator, and operators to
//     test for equality (x == y) and non-equality (x != y).
//
//   typedef ____ size_type
//     bag::size_type is the data type of any variable that keeps track of how many items
//     are in a bag.
//
//   static const size_type CAPACITY = _____
//     bag::CAPACITY is the maximum number of items that a bag can hold.
//
// CONSTRUCTOR for the bag class:
//   bag( )
//     Postcondition: The bag has been initialized as an empty bag.
//
// MODIFICATION MEMBER FUNCTIONS for the bag class:
//   size_type erase(const value_type& target);
//     Postcondition: All copies of target have been removed from the bag.
//     The return value is the number of copies removed (which could be zero).
//
//   void erase_one(const value_type& target)
//     Postcondition: If target was in the bag, then one copy has been removed;
//     otherwise the bag is unchanged. A true return value indicates that one
//     copy was removed; false indicates that nothing was removed.
//
//   void insert(const value_type& entry)
//     Precondition:  size( ) < CAPACITY.
//     Postcondition: A new copy of entry has been added to the bag.
//
//   void operator +=(const bag& addend)
//     Precondition:  size( ) + addend.size( ) <= CAPACITY.
//     Postcondition: Each item in addend has been added to this bag.
//
// CONSTANT MEMBER FUNCTIONS for the bag class:
//   size_type size( ) const
//     Postcondition: The return value is the total number of items in the bag.
//
//   size_type count(const value_type& target) const
//     Postcondition: The return value is number of times target is in the bag.
//
// NONMEMBER FUNCTIONS for the bag class:
//   bag operator +(const bag& b1, const bag& b2)
//     Precondition:  b1.size( ) + b2.size( ) <= bag::CAPACITY.
//     Postcondition: The bag returned is the union of b1 and b2.
//
// VALUE SEMANTICS for the bag class:
//    Assignments and the copy constructor may be used with bag objects.

#ifndef MAIN_SAVITCH_BAG1_H
#define MAIN_SAVITCH_BAG1_H
#include <cstdlib>  // Provides size_t
#include <cassert>
#include <iostream>

using namespace std;

namespace main_savitch_3
{
    class bag
    {
    public:
        // TYPEDEFS and MEMBER CONSTANTS
        typedef int value_type;
        typedef std::size_t size_type;
        static const size_type CAPACITY = 30;
        // CONSTRUCTOR
        bag() { used = 0; }
        // MODIFICATION MEMBER FUNCTIONS
        size_type erase(const value_type& target);
        bool erase_one(const value_type& target);
        void insert(const value_type& entry);
        void operator +=(const bag& addend);
        // CONSTANT MEMBER FUNCTIONS
        size_type size() const { return used; }
        size_type count(const value_type& target) const;

        void test() const;

    private:
        value_type data[CAPACITY];  // The array to store items
        size_type used;             // How much of array is used
    };

    // NONMEMBER FUNCTIONS for the bag class
    bag operator +(const bag& b1, const bag& b2) 
    {
        // a = b +c
        bag temp;

        temp += b1;
        temp += b2;

        return temp;
    }

    //   void operator +=(const bag& addend)
    //     Precondition:  size( ) + addend.size( ) <= CAPACITY.
    //     Postcondition: Each item in addend has been added to this bag.
    void bag::operator +=(const bag& addend) 
    {
        assert(size() + addend.size() <= CAPACITY);

        for (size_type i = 0; i < addend.used; i++) 
        {
            data[used + i] = addend.data[i];
        }
        used += addend.used;
    }

    //   size_type erase(const value_type& target);
    //     Postcondition: All copies of target have been removed from the bag.
    //     The return value is the number of copies removed (which could be zero).
    bag::size_type bag::erase(const value_type& target) 
    {
        size_type counter = 0;

        while (erase_one(target))
            counter++;

        return counter;
    }

    //   void erase_one(const value_type& target)
    //     Postcondition: If target was in the bag, then one copy has been removed;
    //     otherwise the bag is unchanged. A true return value indicates that one
    //     copy was removed; false indicates that nothing was removed.
    bool bag::erase_one(const value_type& target) 
    {
        for (size_type i = 0; i < used; i++) 
        {
            if (target == data[i])
            {
                // Remove element at data[i]
                data[i] = data[used - 1];
                used--;

                return true;
            }
        }
        return false;
    }


    //   size_type count(const value_type& target) const
    //     Postcondition: The return value is number of times target is in the bag.
    bag::size_type bag::count(const value_type& target) const 
    {
        size_type counter = 0;
        for (size_type i = 0; i < used; i++) 
        {
            if (target == data[i])
                counter++;
        }
        return counter;
    }


    void bag::test() const
    {
        // Print out the contents of the bag
        cout << "{";
        for (size_type i = 0; i < used; i++)
        {
            cout << data[i] << ",";
        }
        cout << "} used = " << used << endl;
    }

    //   void insert(const value_type& entry)
    //     Precondition:  size( ) < CAPACITY.
    //     Postcondition: A new copy of entry has been added to the bag.
    void bag::insert(const value_type& entry) 
    {
        assert(size() < bag::CAPACITY);

        // Put entry into next open slot in array
        data[used] = entry;
        used++;
    }
}
#endif