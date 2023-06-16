/*
FILE: TestCrlSequence.cpp

CLASS PROVIDED: Sequence (part of namespace Josue)

Summary: Driver file to test a Sequence object using Nodes that are declared
         in the crlNode.h file.

Test Cases: used valgrind to check for memory leaks, output:
            HEAP SUMMARY:
             in use at exit: 0 bytes in 0 blocks
             total heap usage: 9 allocs, 9 frees, 74,992 bytes allocated
             
            All heap blocks were freed -- no leaks are possible

            ERROR SUMMARY: 0 errors from 0 contexts (supressed: 0 from 0)

Author: Josue 

Date: 05/08/2023

Summary of Modifications: N/A
 
Compiler: Ubuntu (g++)

FUNCTION(S):
    void intro_message():
        Postcondition: Displays a greeting/intro message to the user
                       at the start of the program.
    void menu():
        Postcondition: Displays a menu with several option from which
                       the user can pick from.

    void ending_message():
        Postcondition: Displays a ending message when you user quits the
                       program.
*/


#include <iostream> // cout, endl
#include "Sequence.h"
#include "crlNode.h"
using namespace Josue;
using std::cout;
using std::endl;
using std::cin;

void intro_message();
void menu();
void ending_message();

int main() {
    Sequence s1;
    int choice{int()};
    Sequence::value_type temp{Sequence::value_type()};
    
    intro_message();

    do{
        menu();
        cin >> choice;
        cout << endl;

        switch(choice){
            case 1:
                s1.start();
                cout << "start complete!";
                break;

            case 2:
                if(s1.advance() == true)
                    cout << "advance complete!";
                else
                    cout << "List is empty, cannot advance....";
                break;

            case 3:
                cin.ignore(300, '\n');
                temp = "";
                cout << "Enter what you'd like to insert: ";
                getline(cin, temp);
                if(s1.insert(temp))
                    cout << "insert complete!";
                else
                    cout << temp << " has already been inserted...";
                break;

            case 4:
                cin.ignore(300, '\n');
                temp = "";
                cout << "Enter what you'd like to erase: ";
                getline(cin, temp);
                if(s1.erase(temp))
                    cout << "erase complete!";
                else
                    cout << "erase failed, value not found...";
                break;

            case 5:
                if(s1.size() > 0)
                    cout << "Current: " << s1.current();
                else
                    cout << "List is empty, there is no current...";
                break;

            case 6: 
                if(s1.size() > 0){
                    s1.remove_current();
                    cout << "current removed complete!";
                }
                else
                    cout << "List is empty, there is nothing to remove...";
                break;

            case 7:
                cout << "Size: " << s1.size();
                break;

            case 8:
                s1.print();
                break;

            case 9:
                break;

            default:
                cout << "INVALID ENTRY, try again....";
                break;
        }
        cout << endl << endl;
    }while(choice != 9);

    ending_message();

    cout << endl;
    return 0;
}

void intro_message(){
    cout << "HELLO! Pick an option in the menu....\n";
    return;
}

void menu(){
    cout << "1 - start\n";
    cout << "2 - advance\n";
    cout << "3 - insert\n";
    cout << "4 - erase\n";
    cout << "5 - get current\n";
    cout << "6 - remove current\n";
    cout << "7 - get size\n";
    cout << "8 - print\n";
    cout << "9 - QUIT\n\n";
    cout << "ENTER CHOICE: ";
    return;
}

void ending_message(){
    cout << "Have a nice day";
    return;
}
