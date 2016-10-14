
#include<stdio.h>
#include <string>
#include <iostream>
#include <vector>
 

#define ASCII 256
 using namespace std;
 int q = 101;
/* pat -> pattern
    txt -> text
    q -> A prime number
*/

class RK {

protected :
string txt;

public:
  RK( string text);
  vector<int> search(string pattern);


};
RK::RK(string str){
    txt=str;
}


vector<int> RK::search(string pat)
{   
    vector <int> ocurrence;
    int M = pat.length();
    int N = txt.length();
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;
 
    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M-1; i++)
        h = (h*ASCII)%q;
 
    // Calculate the hash value of pattern and first
    // window of text
    for (i = 0; i < M; i++)
    {
        p = (ASCII*p + pat[i])%q;
        t = (ASCII*t + txt[i])%q;
    }
 
    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++)
    {
 
        // Check the hash values of current window of text
        // and pattern. If the hash values match then only
        // check for characters on by one
        if ( p == t )
        {
            /* Check for characters one by one */
            for (j = 0; j < M; j++)
            {
                if (txt[i+j] != pat[j])
                    break;
            }
 
            // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
            if (j == M)
                ocurrence.push_back(i);
        }
 
        // Calculate hash value for next window of text: Remove
        // leading digit, add trailing digit
        if ( i < N-M )
        {
            t = (ASCII*(t - txt[i]*h) + txt[i+M])%q;
 
            // We might get negative value of t, converting it
            // to positive
            if (t < 0)
            t = (t + q);
        }
    }
    return ocurrence;
}
 
