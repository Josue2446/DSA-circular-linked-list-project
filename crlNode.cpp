/*
FILE: crlNode.cpp

Summary: Definition of Node class functions alongside linkedlist tool-kit
         functions that are meant to be used in Sequence class.
         

Test Cases: N/A

Author: Josue

Date: 05/08/2023

Summary of Modifications: N/A

Compiler: Ubuntu (g++)

Class implemented: Node (see crlNode.h for documentation)
INVARIANT for the Node ADT:
    1. The data portion of the Node is stored in the private member
       variable 'data'
    2. The Link portion of the Node is stored in the private member 
       variable 'link'
    
*/

#include "crlNode.h"
#include <string> // string

namespace Josue {
    
    const bool if_value_exist(Node* cursor, const Node::value_type& val,
                              const int& len){

        Node::value_type str_one{""};
        
        for(int i = 0; i < len; i++){
            str_one = cursor->get_data();
            
            if(str_one == val)
                return true;
            else
                cursor = cursor->get_link();
        }
        return false;
    }

    const Node* list_search(const Node* cursor, const Node::value_type& val,
                            const int& len){

        for(int i = 0; i < len; i++){
            if(cursor->get_data() == val)
                return cursor;
            else
                cursor = cursor->get_link();
        }
        return nullptr;
    }

    Node* list_search(Node* cursor, const Node::value_type& val, 
                      const int& len){

        for(int i = 0; i < len; i++){
            if(cursor->get_data() == val)
                return cursor;
            else
                cursor = cursor->get_link();
        }
        return nullptr;
    }
    
    void list_clear(Node*& head_ptr, Node*& tail_ptr, int& len){
        for(int i = 0; i < len; i++){
            if(head_ptr == tail_ptr){
                head_ptr->set_link(nullptr);
                head_ptr = nullptr;
                delete tail_ptr;
                tail_ptr = nullptr;
                break;
            }
            tail_ptr->set_link(head_ptr->get_link());
            head_ptr->set_link(nullptr);
            delete head_ptr;
            head_ptr = tail_ptr->get_link();
        }
        len = 0;
        return;
    }

    const int list_length(Node* head_ptr, Node* tail_ptr){
        int len{0};

        while(head_ptr != tail_ptr){
            len++;
            head_ptr = head_ptr->get_link();
        }
        return len;
    }
}
