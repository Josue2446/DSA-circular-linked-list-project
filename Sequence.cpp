/*
FILE: Sequence.cpp

Summary: Defines functions in Sequence class, function declarations are
         in Sequence.h file. Sequence class utilizes functions located in
         crlNode.h to manipulate a Linked List using functions in this class.
         Linked List tool-kit functions are also used to help in this class.
         Tool-kit fuctions located in crlNode.h file.
         
Test Cases: N/A

Author: Josue 

Date: 05/08/2023

Summary of Modifications: N/A

Compiler: Ubuntu (g++)

Class implemented: Sequence (see Sequence.h for documentation)
INVARIANT for the Sequence ADT:
    1. The items in the Sequence are stored in a linked list;
    2. The head pointer of the list is stored in the private member 
       variable 'head_ptr'
    3. The tail pointer of the list is stored in the private member
       variable 'tail_ptr'
    4. The current pointer of the list is stored in the private member
       variable 'current_ptr'
    5. The total number of items in the list is stored in the private
       member variable 'many_nodes'

*/

#include "Sequence.h"
#include <iostream> // cout, endl;
#include <cctype> // tolower

namespace Josue {

    void Sequence::start(){
        current_ptr = head_ptr;
        return;
    }

    const bool Sequence::advance(){
        if(many_nodes != 0){
            current_ptr = current_ptr->get_link();
            return true;
        }
        else
            return false;
    }

    const bool Sequence::insert(const value_type& val){
        if(if_value_exist(current_ptr, val, many_nodes) == true)
            return false;
        
        if(many_nodes == 0){
            head_ptr = new Node(val);
            head_ptr->set_link(head_ptr);
            current_ptr = head_ptr;
            tail_ptr = head_ptr;
        }

        else{
            Node* temp = new Node(val, tail_ptr->get_link());
            tail_ptr->set_link(temp);
            tail_ptr = temp;
        }

        many_nodes++;
        list_sort(head_ptr, tail_ptr);
        current_ptr = list_search(current_ptr, val, many_nodes);
        return true;
    }
    
    void Sequence::list_sort(Node* first, Node* second){
        if(many_nodes > 1){
            
            first = head_ptr;
            
            value_type str_one{value_type()};
            value_type str_two{value_type()};
            value_type temp{value_type()};

            for(first; first != tail_ptr; first = first->get_link()){
                second = first->get_link();
                   
                for(second; second != head_ptr; second = second->get_link()){
                    str_one = first->get_data();
                    for(char& ch : str_one)
                        ch = tolower(ch);

                    str_two = second->get_data();
                    for(char& ch : str_two)
                        ch = tolower(ch);

                    if(str_one > str_two){
                        temp = second->get_data();
                        second->set_data(first->get_data());
                        first->set_data(temp);
                    }
                }    
            }
        }
        return;
    }

    const bool Sequence::erase(const value_type& val){
        if(many_nodes > 0 && 
           if_value_exist(current_ptr, val, many_nodes) == true){

            if(many_nodes == 1){
                delete head_ptr;
                head_ptr = nullptr;
                tail_ptr = nullptr;
                current_ptr = nullptr;
            }
            
            else{
                Node* cursor = list_search(current_ptr, val, many_nodes);               
 
                if(cursor == head_ptr && many_nodes == 2){
                    current_ptr = tail_ptr;
    
                    delete head_ptr;
                    tail_ptr->set_link(tail_ptr);
                    head_ptr = tail_ptr;
                }

                else if(cursor == head_ptr && many_nodes > 2){
                    if(current_ptr == head_ptr)
                        current_ptr = current_ptr->get_link();

                    cursor = cursor->get_link();
                    delete head_ptr;
                    tail_ptr->set_link(cursor);
                    head_ptr = cursor;
                }

                else{
                    cursor->set_data(head_ptr->get_data());
                    cursor = head_ptr->get_link();

                    delete head_ptr;
                    tail_ptr->set_link(cursor);
                    head_ptr = cursor;
                    list_sort(head_ptr, tail_ptr);
                }
            }
            many_nodes--;
            return true;
        }
        return false;
    }

    const int Sequence::size() const {
        return many_nodes;
    }

    const Sequence::value_type Sequence::current() const {
        return current_ptr->get_data();
    }

    void Sequence::print() const {
        Node* cursor{head_ptr};

        for(int i = 0; i < many_nodes; i++){
            std::cout << cursor->get_data();
            std::cout << "\n";
            cursor = cursor->get_link();
        }
        return;
    }

    void Sequence::remove_current(){
        erase(current_ptr->get_data());
        return;
    }
}

