/* 
 * File:   main.cpp
 * Author: RR
 *
 * Created on April 12, 2015, 2:55 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

void prntAry(int *,int);
void filArray(int *,int);
void sortAry(int *,int);
float avgAry(int *,int);
float medAry(int *,int);
int modAry(int *,int *,int *,int);
/*
 * 
 */
int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    const int SIZE = 43;
    int array[SIZE],brray[SIZE],crray[SIZE];
    float av;
    float me;
    int numMode;
    int hi;
    filArray(array,SIZE);
    prntAry(array,SIZE);
    sortAry(array,SIZE);
    prntAry(array,SIZE);
    av = avgAry(array,SIZE);
    cout<<av;
    me = medAry(array,SIZE);
    cout<<"herer"<<me;
    numMode = modAry(array,brray,crray,SIZE);
    cout<<"ist this"<<numMode<<endl;
    prntAry(brray,numMode);
    prntAry(crray,numMode);
    sortAry(crray,numMode);
    
    prntAry(crray,numMode);
    hi = crray[numMode-1];
    cout<<"the highest number of modes is "<<hi;
    

    return 0;
}


int modAry(int *a,int *b,int *c,int n){
    int i = 0;
    int k = 1;
    int r = 0;
    b[0] = a[0];
    do{
        int j = 1;
        do{
            if(a[i]==a[k]){
                j++;
                k++;
            }
            else
                i = k;
        }while(i!=k);
        k++;
        c[r] = j;
        r++;
        b[r] = a[i];
    }while(i < n);
    return r;
}

float medAry(int *a,int n){
    int test;
    float med;
    test = n%2;
    if(test==0){
        test=n/2;
        med = a[test];
    }
    else{
        test = n/2;
        med = (a[test]+a[test+1]);
        med = med/2;
    }
    return med;
}

float avgAry(int *a,int n){
    float avg = 0;
    for(int i = 0;i < n;i++){
        avg += a[i];
    }
    avg = avg/n;
    return avg;
    
}

void sortAry(int *a,int n){
    int startScan, min, value;
    for(startScan = 0;startScan < (n-1);startScan++){
        min = startScan;
        value = a[startScan];
        for(int index = startScan + 1;index < n;index++){
            if(a[index] < value){
            value = a[index];
            min = index;
            }
        }
        a[min] = a[startScan];
        a[startScan] = value;
    }
}

void filArray(int *a,int n){
for(int i=0;i<n;i++)
        a[i]=rand()%15+10;
}

void prntAry(int *a,int n){
    //Loop and print
    int perLine = 10;
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}