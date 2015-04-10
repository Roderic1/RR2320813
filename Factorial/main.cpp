/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on April 9, 2015, 3:28 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    int n = 2;
    
    do{
        
        double test = 1;
        for(int i =1;i<=n;i++){
            test *= i;
        }
        cout<<test<<endl;
        n++;
        cout<<n<<endl;
        
    }while(n != 171);
    return 0;
}

