#include <iostream>
#include <cstring>
#include "student.h"
using namespace std;

student::student(char* first, char* last, int idNum, float grade)
{
    firstN = first;
    lastN = last;
    ID = idNum;
    GPA = grade;
}
char* student::getFirst()
{   
    return firstN;
}
char* student::getLast()
{
    return lastN;
}
int student::getID()
{
    return ID;
}
float student::getGrade()
{
    return GPA;
}
student::~student()
{
    delete firstN, lastN, ID, GPA;
}
