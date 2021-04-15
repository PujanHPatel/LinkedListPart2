/*To Create a LinkedList implementation of Studnet List with added AVERAGE and Sorting functionality
 * Auhtor: Pujan Patel
 * Date 4/12/2021
 * Recived help from Mark Zhang
 */
#include <iostream>
#include <cstring>
#include <iomanip>
#include "student.h"
#include "node.h"
using namespace std;

node* addStudent(node* head, node* originalHead, student* newStudent);
node* deleteStudent(node* prev, node* head, node* originalHead, int IDnum);
void printList(node* head);
void average(node* head, float totalGPA, int totalStudents);

int main() {
    node* head = NULL;
    bool running = true;
    while (running == true) {
        char input[30];
        cout << "ADD, PRINT, DELETE, AVERAGE, QUIT" << endl;
        cin >> input;
        if(strcmp(input, "ADD") == 0) {//if ADD create new student into LL
            //takes user info 
            char* firstName = new char[100];
            char* lastName = new char[100];
            int idNumber = 0;
            float grade = 0.0;
            cout << "First name: " << endl;
            cin.clear();
            cin.ignore(9999, '\n');
            cin.getline(firstName, 100);
            cout << "Last name:" << endl;
            cin.getline(lastName, 100);
            cout << "ID number:" << endl;
            cin >> idNumber;
            cout << "GPA" << endl;
            cin.clear();
            cin.ignore(9999, '\n');
            cin >> grade;
            student* nnStudent = new student(firstName, lastName, idNumber, grade);
            head = addStudent(head, head, nnStudent);
        }
        else if(strcmp(input, "DELETE") == 0) {//if DELETE delete by studentID
            int studentID = 0;
            cout << "ID Number" << endl;
            cin >> studentID;
            head = deleteStudent(NULL, head, head, studentID);
        }
        else if(strcmp(input, "PRINT") == 0) {//if PRINT print
            printList(head);
        }
        else if(strcmp(input, "QUIT") == 0) {//if QUIT quit
            running = false; 
        }
        else if(strcmp(input, "AVERAGE") == 0) {//if AVERAGE average GPA{
            average(head, 0, 0);
        }
        else {//if none, reenter
            cout << "Please enter a valid command" << endl;
        }
    }
    return 0;
}

node* addStudent(node* head, node* originalHead, student* newStudent) {//ADD STUDENT
    node* temp = new node(newStudent);
    if(head == NULL){//if empty
        return temp;
    }
    else if(head != NULL && temp->getStudent()->getID() < originalHead->getStudent()->getID()) {//if ID less
        temp->setNext(originalHead);
        return temp;
    }
    if(head->getNext() == NULL || head->getNext()->getStudent()->getID() >= newStudent->getID()) {//if ID greater
        temp->setNext(head->getNext());
        head->setNext(temp);
        return originalHead;
    }
    else {//recursively add
        addStudent(head->getNext(), originalHead, newStudent);
    }
    return originalHead;
}

node* deleteStudent(node* prev, node* head1, node* originalHead, int idNumber) {//delete Student and reassign pointers
    bool studentFound = false;
    node* head = head1;
    if(head != NULL) {  
        if(head->getStudent()->getID() == idNumber && prev == NULL) {
            studentFound = true;
            head = head1->getNext();
            head1->~node();
            cout << "Student Deleted" << endl;
            return head;
        }
        else if(head->getStudent()->getID() == idNumber) {
            prev->setNext(head->getNext());
            head->~node();
            cout << "Student Deleted" << endl;
            studentFound = true;
            return originalHead;
        }
        if(studentFound == false && head->getNext() != NULL) {
            deleteStudent(head, head->getNext(), originalHead, idNumber);
        }
        else if(studentFound == false && head->getNext() == NULL) {
            cout << "Student Not Found" << endl;
            return originalHead;
        }
    }
    else {
        cout << "List Empty!" << endl;
        return originalHead;
    }
    return originalHead;
}

void printList(node* temp) {//print LL recursively
    if(temp != NULL) {
        cout << "\tFIRST NAME: "<< temp->getStudent()->getFirst() << endl;
        cout << "\tLAST NAME:  " << temp->getStudent()->getLast() << endl;
        cout << "\tID Number:  " << temp->getStudent()->getID() << endl;
        cout << "\tGPA:        " << temp->getStudent()->getGrade() << setprecision(2) << fixed << endl; 
        printList(temp->getNext());
    }
}

void average(node* head, float totalGPA, int totalStudents) {//average GPAs
    if(head != NULL) {
        totalGPA = totalGPA + head->getStudent()->getGrade();
        totalStudents++;
        head = head->getNext();
        average(head, totalGPA, totalStudents);
    }
    else if(head == NULL && totalStudents > 0) {
        float avg = totalGPA / totalStudents;
        cout << "Average GPA: " << setprecision(2) << fixed << avg << endl;
    }
    else {
        cout << "No Student in List" << endl;
    }
}
