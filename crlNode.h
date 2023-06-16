/*
FILE: crlNode.h

Summary: Node class is declared below, intended to be used in a linked list
         structure as part of a sequence. Nodes will be manipulated within
         the Sequence class. Function for the linkedlist tool-kit are also
         declared below, defined in crlNode.cpp file. Intended to be used
         with the Sequence class to further assist in Node managment and 
         organization.

Test Cases: N/A

Author: Josue 

Date: 05/08/2023

Summary of Modifications: N/A

Compiler: Ubuntu (g++)

TYPEDEFS for Node class:
    Node::value_type
        is the data type of the items in the Sequence.

CONSTRUCTOR for the Node class:
    Node(const value_type& val = value_type(), Node* ptr = nullptr)
        Postcondition: A new node is created with default values if none
                       are entered in by the user.

MUTATOR FUNCTION(S):
    void set_data(const value_type& val)
        Precondition: A Node has been created and currently exist.
        Postcondition: Data portion of the Node has been modified and
                       now holds new value that was entered.

    void set_link(Node* ptr)
        Preconditon: A Node has been created and currently exist.
        Postcondition: Link portion of the Node has been modified and
                       now holds new value that was entered.

ACCESSOR FUNCTION(S):
    const value_type get_data() const
        Precondition: A Node has been created currently exist.
        Postcondition: Returns a value of type const value_type which
                       comes from the data portion of the Node.

    const Node* get_link() const
        Precondition: A Node has been created and currently exist.
        Postcondition: Returns a value of type const Node* which
                       comes from the link portion of the Node.
    
    Node* get_link():
        Precondition: A Node has been created and currently exist.
        Postcondition: Returns a value of type Node* which comes
                       from the link portion of the Node.

NONMEMBER FUNCTIONS for the Node class:
    const bool if_value_exist(Node* cursor, const Node::value_type& val,
                              const int& val):
        Precondition: At least 1 Node exist.
        Postcondition: Returns a value of type const bool of true or false
                       depending if the value entered in by the user is
                       already in the list.

    Node* list_search(Node* cursor, const Node::value_type& val, 
                      const int& len):
        Precondition: At least 1 Node exist.
        Postcondition: Returns a value of type Node* which points to the
                       Node that contains the value that is searched for.

    const Node* list_search(const Node* cursor, const Node::value_type& val,
                            const int& len):
        Precondition: At least 1 Node exist.
        Postcondition: Returns a value of type const Node* which points
                       to the Node that contains the value that is 
                       searched for.

    void list_clear(Node*& head_ptr, Node*& tail_ptr, int& len):
        Precondition: Sequence object exist.
        Postcondition: Removes all Nodes in the Sequence and
                       changes many_nodes to zero.

    const int list_length(Node* head_ptr, Node* tail_ptr):
        Precondition: Sequence object exist.
        Postcondition: Returns a value of type const int which is the
                       amount of Nodes in the Sequence.
*/

#ifndef CRL_NODE_H
#define CRL_NODE_H

#include <string> // string

namespace Josue {

    class Node {
        public:
            // TYPEDEF
            typedef std::string value_type;

            // constructor
            Node(const value_type& val = value_type(), 
                 Node* ptr = nullptr) : data{val}, link{ptr} {}
            
            // destructor
            ~Node() = default;

            // mutator functions
            void set_data(const value_type& val) {data = val;}
            void set_link(Node* ptr) {link = ptr;}

            // accessor functions
            const value_type get_data() const {return data;}
            const Node* get_link() const {return link;}
            Node* get_link() {return link;}

        private:
            value_type data;
            Node* link;
    };

    // FUNCTIONS for linked list toolkit
    const bool if_value_exist(Node* cursor, const Node::value_type& val,
                              const int& len);
    Node* list_search(Node* cursor, const Node::value_type& val,
                      const int& len);
    const Node* list_search(const Node* cursor, const Node::value_type& val,
                            const int& len);
    void list_clear(Node*& head_ptr, Node*& tail_ptr, int& len);   
    const int list_length(Node* head_ptr, Node* tail_ptr);
}

#endif // CRL_NODE_H
