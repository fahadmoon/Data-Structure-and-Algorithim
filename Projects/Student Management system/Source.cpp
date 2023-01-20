#include <iostream>
#include <fstream>
#include <string>
#include<stdio.h>
#include <iomanip> //using library setw()
using namespace std;

class Teachernode
{
public:
    int rNo;
    string nameStudent;
    int DSAmarks, CAmarks, LAmarks, CSmarks, MVCmarks, ISLmarks; //subjects
    char garde;//Date of birth
    node* next;
    node* prev;
    Teachernode()
    {
        next = NULL;
        prev = NULL;
    }
};
