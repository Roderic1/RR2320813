/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on April 8, 2015, 5:10 PM
 */

#include <cstdlib>
#include <iostream>

#include "bankAcc.h"

using namespace std;

int totDepo();
int totWith();
void display(BankAcc);
int main(int argc, char** argv) {

    float deposit;
    float total = 0;
    float withdraw;
    float bal;
    int depo;
    BankAcc a;
    
    cout<<"Enter in the begining balance."<<endl;
    cin>>bal;
    bal *= 100;
    a.balBeg = bal;
    
    a.depTot = totDepo();
    cout<<"\nTotal deposited was"<<a.depTot<<endl;
    a.withTot = totWith();
    cout<<"The total withdrawn is "<<a.withTot<<endl;
    
    
    display(a);
    
   cout<<deposit;
    return 0;
}

int totDepo(){
    float deposit;
    float total = 0;
    do{
        cout<<"Enter the amount of each check individually"<<endl;
        cout<<"Press enter after entering the amonut"<<endl;
        cout<<"Enter -1 when finished"<<endl;
        cin>>deposit;
        if(deposit != -1)
            total+=deposit;
        cout<<total<<endl;
        
    } while(deposit != -1);
    total *= 100;
    cout<<total<<endl;
    return total;
}

int totWith(){
    float withDrw;
    float total = 0;
    do{
        cout<<"Enter the amount of each withdraw individually"<<endl;
        cout<<"Press enter after inputing the amonut"<<endl;
        cout<<"Enter -1 when finished"<<endl;
        cin>>withDrw;
        if(withDrw != -1)
            total+=withDrw;
        cout<<total;
        
    } while(withDrw != -1);
    total *= 100;
//    cout<<total<<endl;
    return total;
}

void display(BankAcc a){
    float tot = 0;
    cout<<"Account #:   "<<a.accNum<<endl;
    tot = a.balBeg + a.depTot - a.withTot;
    cout <<tot<<endl;
    tot /= 100;
//    cout<<tot<<endl;
//    if(tot < 0){
//        tot = tot - 12;
//        cout<<"Your balance went below 0, and you have been ";
//        cout<<"assed a $12 overdraw fee"<<endl;
//    }
    
    cout<<"Your balence is:    "<<tot;
}