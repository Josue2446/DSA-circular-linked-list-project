/*
FILE: Sequence.h

Summary: Declares Sequence class, functions are in Sequence.cpp.
         Sequence class utilizes functions located in crlNode.h to
         manipulate a Linked List using functions in this class, along
         side fuctions that are part of the Linked List tool-kit also 
         located in crlNode.h.
         

Test Cases: N/A

Author: Josue 

Date: 05/08/2023

Summary of Modifications: N/A

Compiler: Ubuntu (g++)

TYPEDEFS for Sequence class:
    Node::value_type value_type
        is the data type of the items in the Sequence.

CONSTRUCTOR for the Sequence class:
    Sequence():
        Postcondition: The Sequence is empty with all private
                       member variable being set to default values.

    DELETED CONSTRUCTORS:
        1.) Sequence(const Sequence& rhs) - copy constructor
        2.) Sequence(Sequence&& rhs) - move constructor

DESTRUCTOR for the Sequence class:
    ~Sequence():
        Precondition: A Sequence object exist.
        Postcondition: Once a Sequence object leaves scope,
                       a call to list_clear will be made and will
                       free any of the memory that was allocated by the
                       user when running the program.

OPERATORS:
    Deleted operators:
        1.) Sequence& operator = (const Sequence& rhs) - copy assignment
        2.) Sequence& operator = (Sequence&& rhs) - move assignment

MUTATOR FUNCTION(S):
    void start():
        Precondition: A Sequence object exist.
        Postcondition: current_ptr moves to the start of the
                       Sequence.

    const bool advance():
        Precondition: A Sequence object exist and has at least 1 item.
        Postcondition: current_ptr advance to the next item in the 
                       Sequence which is determined by the link portion
                       of the Node it is currently pointing to.

    const bool erase(const value_type& val):
        Precondition: A Sequence object exist.
        Postcondition: If the value the user enters exist in the Sequence,
                       it will be erased and return a value of true.
                       Futhermore, if current_ptr is pointing to the item 
                       that is erased, it will advance forward. Otherwise, 
                       if the item is not present in the Sequence, a 
                       value of false will be returned with the Sequence 
                       remaining unchanged. A successful erase call will
                       decrease the size of the Sequence by 1.

    const bool insert(const value_type& val):
        Precondition: A Sequence object exist.
        Postcondition: A new item is added to the Sequence object and sorted
                       accordingly, also returns a value of true. If the
                       entered item by the user is already in the sequence,
                       a value of false will be returned with the Sequence
                       remaining unchanged. A successful insert call will
                       increase the size of the Sequence by 1 and 
                       current_ptr will now be pointing to the newly added
                       item.

    void remove_current():
        Precondition: A Sequence object exist and has at least 1 item.
        Postcondition: Whatever the current item happens to be will be
                       erased from the Sequence. If there happens to be
                       only 1 item in the Sequence, current_ptr will be 
                       set to nullptr, otherwise, it will advance to the
                       next item in the Sequence. A successfull call to
                       remove_current will derease the size of the Sequence
                       by 1.

ACCESSOR FUNCTION(S):
    void print() const:
        Precondition: A Sequence object exist.
        Postcondition: All the items in the Sequence are printed, if
                       there are no items, nothing is printed.

    const int size() const:
        Precondition: A Sequence object exist.
        Postcondition: Returns the number of items in the current Sequence
                       object which comes from the private memeber variable
                       'many_nodes' which is of type INT (integer).

    const value_type current() const:
        Precondition: A Sequence object exist with at least 1 item.
        Postcondition: Returns a value of type value_type that is currently
                       being pointed to by the private member variable
                       'current_ptr'.

PRIVATE MEMBER FUNCTION(S):
    void list_sort(Node* first, Node* second):
        Precondition: A Sequence object exist and a successful call to
                      the insert function has been made.
        Postcondition: All the items in the Sequence will be sorted in
                       alphabetical order, A-Z.

*/


#ifndef SEQUENCE_H
#define SEQUENCE_H

#include "crlNode.h"

namespace Josue {

    class Sequence {
        public:
            // TYPEDEFS
            typedef Node::value_type value_type;
    
            // constructor
            Sequence() : head_ptr{nullptr}, tail_ptr{nullptr},
                         current_ptr{nullptr}, many_nodes{0} {}
            
            // no copy or move constructors
            Sequence(const Sequence& rhs) = delete;
            Sequence(Sequence&& rhs) = delete;

            // no move or copy assignment operators
            Sequence& operator = (const Sequence& rhs) = delete;
            Sequence& operator = (Sequence&& rhs) = delete;

            // destructor
            ~Sequence() {list_clear(head_ptr, tail_ptr, many_nodes);}

            // Mutator function(s)
            void start();
            const bool advance();
            const bool erase(const value_type& val);
            const bool insert(const value_type& val);
            void remove_current();

            // accessor function(s)
            void print() const;
            const int size() const;
            const value_type current() const;
        private:
            Node* head_ptr;
            Node* tail_ptr;
            Node* current_ptr;
            int many_nodes;
            // private member function(s)
            void list_sort(Node* first, Node* end);
    };
}

#endif // SEQUENCE_H
