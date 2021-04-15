//Kevin Lei code
#ifndef NODE_H
#define NODE_H

#include <cstring>
#include <iostream>
#include "student.h"

class node
{
	public:
		node(student* nstudent);
		node* getNext();
		student* getStudent();
		void setNext(node* newNext);
		void setStudent(student* newStudent);
		~node();
	private:
		student* nStudent;
		node* next;
};

#endif
