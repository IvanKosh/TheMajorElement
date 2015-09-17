/* 
 * File:   main.cpp
 * Author: bat
 *
 * Created on 17 Сентябрь 2015 г., 18:51
 */

#include <iostream>
#include <fstream>
using namespace std;

short strToNum(string str) {
    switch (str.length()) {
        case 1:
            return str[0]-48;
        case 2:
            return (str[0]-48)*10 + str[1]-48;
        case 3:
            return (str[0]-48)*100 + (str[1]-48)*10 + str[2]-48;
    }
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    short l, i, j, count;
    short mas[101];
    bool test;
    while (getline(stream, line)) {
        for (i = 0; i < 101; i++) {
            mas[i] = 0;
        }
        l = line.length();
        j = 0;
        count = 1;
        for (i = 0; i < l; i++) {
            if (line[i] == ',') {
                mas[strToNum(line.substr(j, i-j))]++;
                j = i+1;
                count ++;
            }
        }
        mas[strToNum(line.substr(j, i-j))]++;
        l = 0;
        test = false;
        for (i = 0; i < 101; i++) {
            if (mas[i] > count/2) {
                l = i;
                test = true;
                break;
            }
        }
        
        if (test) {
            cout << l << endl;
        }
        else {
            cout << "None" << endl;
        }
    }
    return 0;
}