/* 
 * File:   main.cpp
 * Author: RR
 *
 * Created on April 12, 2015, 6:54 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

struct statsResult
{
    float avg;
    float median;
    int *mode;   //array containing the modes
    int nModes;  //number of modes in the array
    int maxFreq; //max frequency of modes
};

void filAry(int *,int);
void prntAry(int *,int);
statsResult *avgMedMode(int *,int);
void sortAry(int *,int);
float avgAry(int *,int);
float medAry(int *,int);
int modAry(int *,int *,int *,int);

void randAry(int *,int);


int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    int size = 50;
    int array[size];
    char input = 'Y';
    statsResult a;
    do{
        cout<<"Welcome to the Average, median and mode Function."<<endl;
        cout<<"Please enter the size of the Array you want to test."<<endl;
        cin>>size;
        randAry(array,size);
//        filAry(array,size);
        cout<<"print";
        prntAry(array,size);
        cout<<"maybe";
        a = *avgMedMode(array,size);
        cout<<"If you would like to enter another array, enter 'Y'"<<endl;
        cout<<"Or any other key to get back to main menu"<<endl;
        cin>>input;
    }while(input == 'Y'|| input == 'y');
    

    return 0;
}

statsResult *avgMedMode(int *a,int n){
    statsResult in;
    float h;
    int k;
    int array[n];
    
    sortAry(a,n);
    prntAry(a,n);
    h = avgAry(a,n);
    cout<<"maby";
    cout<<h;
    in.avg = h;
    cout<<"no?";
    h = medAry(a,n);
    cout<<"yea";
    in.median = h;
    k = modAry(a,in.mode,array,n);
    in.nModes = k;
    sortAry(array,in.nModes);
    k = array[in.nModes-1];
    in.maxFreq = k;
    
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
    cout<<avg;
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


void filAry(int *a,int n){
    cout<<"Enter in each number then press enter until all numbers are in."<<endl;
    int num;
    for(int i=0;i<n;i++){
        cin>>num;
        a[i] = num;
    }
}

void prntAry(int *a,int n){
    //Loop and print
    cout<<"here";
    int perLine = 9;
    cout<<endl;
    cout<<"but y";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}
void randAry(int *a,int n){
for(int i=0;i<n;i++)
        a[i]=rand()%15+10;
}