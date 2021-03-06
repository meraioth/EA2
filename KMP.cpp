
#include<stdio.h>
#include<string>
#include<stdlib.h>
#include <vector>
#include <iostream>
 

using namespace std;

class KMPs {

protected :
string txt;
vector <int> prepro;

public:
  KMPs( string text, string pattern);
  int KMPSearch(string pattern);
  vector <int> PS(string pat);



};
KMPs::KMPs(string str,string pattern){
  txt=str;
  prepro = PS(pattern);
}





 
int KMPs::KMPSearch(string pat)
{
    int M = pat.length();
    int N = txt.length();
    vector <int> ocurrence;
    
    
    int j  = 0;  
 
    vector <int> lps = prepro;
 
    int i = 0; 
    while (i < N)
    {
      if (pat[j] == txt[i])
      {
        j++;
        i++;
      }
 
      if (j == M)
      {
        return i-M;
        j = lps[j-1];
      }
 
      else if (i < N && pat[j] != txt[i])
      {
        if (j != 0)
         j = lps[j-1];
        else
         i = i+1;
      }
    }
    return 0;
}
 
vector <int> KMPs::PS(string pat)
{
    int M = pat.length();
    int len = 0; 
    int i;
    std::vector<int> lps(M);
    lps[0]=0; 
    i = 1;
 
    
    while (i < M)
    {
       if (pat[i] == pat[len])
       {
         len++;
         lps[i] = len;
         i++;
       }
       else 
       {
         if (len != 0)
         {
           len = lps[len-1];
 
         }
         else 
         {
           lps[i] = 0;
           i++;
         }
       }
    }
    
    return lps;
}
 
