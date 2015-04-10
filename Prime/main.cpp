/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on April 9, 2015, 4:06 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;


void fillArray(int *,int);
int fndPrime(int *,int *,int);
void prntArray(int *,int);
void fndPrim(int *,int *,int,int);
void prntPrim(int *,int*,int,int);

int main(int argc, char** argv) {

    const int SIZE = 1000;
    int array[SIZE];
    int brray[SIZE];
    int crray[SIZE];
    int hi;
    int value;
    
    
    
    fillArray(array,SIZE);
//    prntArray(array,SIZE);
    hi = fndPrime(array,brray,SIZE);
//    prntArray(brray,hi);
    cout<<"enter in a number to be checked"<<endl;
    cin>>value;
    fndPrim(brray,crray,hi,value);
//    prntArray(crray,hi);
    prntPrim(brray,crray,hi,value);
    
    
    return 0;
}

void prntPrim(int *a,int*b,int n,int num){
    cout<<"\n\n";
    cout<<num<<" = ";
    for(int i = 0;i<n;i++){
        if(b[i]!= 0){
            cout<<a[i]<<"^"<<b[i]<<"*";
            
        }
    }
}

void fndPrim(int *a,int *b,int n,int num){
    int i = 0;
    int test = 1;
    do{
        int j = 0;
        do{
            test = num%a[i];
            if(test==0){
                num = num/a[i];
                j++;
            }
        }while(test==0);
        b[i]=j;
        i++;
    }while(num!=1);
    
}

void prntArray(int *a,int n){
    cout<<endl;
    int perLine = 10;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
}

int fndPrime(int *a,int *b,int n){
    int i = 0;
    int test = 1;
    b[i]=a[0];
    i++;
    for(int k = 1 ;k<n;k++){
        int j = 0;
        do{
            test = a[k]%b[j];
            j++;
            if(j==i){
                b[j]=a[k];
                test = 0;
                i++;
            }
            
        }while(test != 0);
    }
    return i;
}

void fillArray(int *a,int n){
    for(int i = 0;i<n;i++){
        a[i]=(i+2);
    }
}


