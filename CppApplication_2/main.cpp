/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on March 30, 2015, 1:15 PM
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>


using namespace std;

//User Libraries
#include "student.h"

//Global

//Function prototypes
Student *filStu(int);
void prntStu (Student *,int);
void wrtStu (char *, Student *, int);
Student *readStu(char *, int);

//Start execution here
int main(int argc, char** argv) {
    //
    srand(static_cast<unsigned int>(time(0)));
    
    int nStudents=36;
    Student *stu=filStu(nStudents);
    
    prntStu(stu,nStudents);

    return 0;
}

void prntStu (Student *a,int n){
    for(int rec=0;rec<n;rec++){
        cout<<"Student id = "<<a[rec].sid;
        cout<<" Score = "<<a[rec].score;
        cout<<" Grade = "<<a[rec].grade<<endl;
    }
    
}

Student *filStu(int n){
    //Accocate Memory
    Student *csc17a=new Student[n];
    //Fill each recored
    for(int rec=0;rec<n;rec++){
        csc17a[rec].sid=rand();
        csc17a[rec].score=rand()%30+70;
        if(csc17a[rec].score>89){csc17a[rec].grade='A';}
        else if(csc17a[rec].score>79){csc17a[rec].grade='B';}
        else {csc17a[rec].grade='C';}
        
    }
}