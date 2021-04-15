#ifndef STUDENT_H
#define STUDENT_H

#include <cstring>
#include <iostream>
using namespace std;

class student
{

public:
    student(char* first, char* last, int idNum, float grade);
    ~student();
    char* getFirst();
    char* getLast();
    int getID();
    float getGrade();
private:
    char* firstN;
    char* lastN;
    int ID;
    float GPA;

};

#endif
