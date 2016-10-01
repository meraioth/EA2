/* Program for Bad Character Heuristic of Boyer Moore String Matching Algorithm */
 
//# include <limits.h>
# include <string.h>
#include <iostream>
#include <algorithm>
#include <vector> 

# define ASCII 256

using namespace std;
 
//Bucket en donde en la posicion letra indica la ultima aparicion
vector <int> badCharHeuristic( string str)
{
    vector <int> badchar(str.length());
    int i;
    int size = str.length();
 
    // Initialize all occurrences as -1
    for (i = 0; i < ASCII; i++)
         badchar[i] = -1;
 
    // Fill the actual value of last occurrence of a character
    for (i = 0; i < size; i++)
         badchar[(int) str[i]] = i;

       return badchar;
}
 
/* A pattern searching function that uses Bad Character Heuristic of
   Boyer Moore Algorithm */
vector <int> search( string txt,  string pat)
{   vector<int> occurrence;
    int m = pat.length();
    int n = txt.length();
 
    vector<int> badchar =badCharHeuristic(pat);
 
 
    int s = 0;
    while(s <= (n - m))
    {
        int j = m-1;
 
       
        while(j >= 0 && pat[j] == txt[s+j])
            j--;
 
        
        if (j < 0)
        {   occurrence.push_back(s);
            printf("\n pattern occurs at shift = %d", s);
 
            if(s+m< n) s+= m-badchar[txt[s+m]];
            else s+=1;
           
 
        }
 
        else
    
            s += max(1, j - badchar[txt[s+j]]);
    }
    return occurrence;
}
 
/* Driver program to test above funtion */
int main()
{
    char txt[] = "ABAAABCD";
    char pat[] = "ABC";
    search(txt, pat);
    string str ("ABABDABACDABABCABAB");
    string patron ("ABABCABAB");
    search(str,patron);
    return 0;
}