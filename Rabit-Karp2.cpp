#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <math.h>

#define ASCII 256
using namespace std;
static int prime = 101;

class RK2 {

protected:
    string text;

private:
    

    long recalculateHash(string str,int oldIndex, int newIndex,long oldHash, int patternLen) {
        long newHash = oldHash - str[oldIndex];
        newHash = newHash/prime;
        newHash += str[newIndex]*pow(prime, patternLen - 1);
        return newHash;
    }

    long createHash(string str, int end){
        long hash = 0;
        for (int i = 0 ; i <= end; i++) {
            hash += str[i]*pow(prime,i);
        }
        return hash;
    }

    bool checkEqual(string str1,int start1,int end1, string str2,int start2,int end2){
        if(end1 - start1 != end2 - start2) {
            return false;
        }
        while(start1 <= end1 && start2 <= end2){
            if(str1[start1] != str2[start2]){
                return false;
            }
            start1++;
            start2++;
        }
        return true;
    }

public:
    RK2(string str){
        text=str;
    }
    vector<int> search(string pattern){
        vector <int> ocurrence;
        int m = pattern.length();
        int n = text.length();
        long patternHash = createHash(pattern, m - 1);
        long textHash = createHash(text, m - 1);
        for (int i = 1; i <= n - m + 1; i++) {
            if(patternHash == textHash && checkEqual(text, i - 1, i + m - 2, pattern, 0, m - 1)) {
                ocurrence.push_back(i-1);
            }
            if(i < n - m + 1) {
                textHash = recalculateHash(text, i - 1, i + m - 1, textHash, m);
            }
        }
        return ocurrence;
    }


};


