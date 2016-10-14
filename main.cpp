#include "fuerzabruta.cpp"
#include "KMP.cpp"
#include "Rabit-Karp.cpp"
#include "rabin-karp.cpp"
#include "Boyer-Moore.cpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <streambuf>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;



string get_file_contents(const char *filename)
{
  ifstream in(filename, ios::in | ios::binary);
  if (in)
  {
    return(string((istreambuf_iterator<char>(in)), istreambuf_iterator<char>()));
  };
}


int main(){
srand (time(NULL));
//rand() % 10 + 1;
string test= get_file_contents("proteins200MB");
//cout<<test.size()<<endl;
int size=test.size();
//cout<< int(0.00001*size)<<endl;
int pattern_size=0.00001*size;
//string patron(test.substr(10,rand()%pattern_size));
string patron("GLLLLLLLV");

cout<<patron<<endl;


clock_t comienzo;
comienzo=clock();


RK rabit(test);
vector<int> v2 = rabit.search(patron);


cout<<"Largo de apariciones:"<<v2.size()<<"tiempo:"<< (clock()-comienzo)/(double)CLOCKS_PER_SEC <<endl;




comienzo=clock();


KMPs km(test);
vector<int> v1=km.KMPSearch(patron);


cout<< "Largo de apariciones:"<<v1.size()<<"tiempo:"<<(clock()-comienzo)/(double)CLOCKS_PER_SEC <<endl;




comienzo=clock();


BF beff(test);
vector<int> v=beff.findpattern(patron);



cout<<"Largo de apariciones:"<<v.size()<<"tiempo:"<< (clock()-comienzo)/(double)CLOCKS_PER_SEC <<endl;

comienzo=clock();


RK2 rk(test);
vector<int> v3=rk.search(patron);



cout<< "Largo de apariciones:"<<v3.size()<<"tiempo:"<<(clock()-comienzo)/(double)CLOCKS_PER_SEC <<endl;



// for (int i = 0; i < v.size(); ++i)
// {
// 	cout<<v[i]<<'\t';

// 	}
// cout<<endl;

// KMPs km(text);
// vector<int> v1=km.KMPSearch(pattern);

// for (int i = 0; i < v1.size(); ++i)
// {
// 	cout<<v1[i]<<'\t';

// 	}
// cout<<endl;

// // RK rabit(text);
// // vector<int> v2 = rabit.search(pattern);
// // for (int i = 0; i < v2.size(); ++i)
// // {
// // 	cout<<v2[i]<<'\t';

// // 	}
// cout<<endl;
// BM boyer(text);
// vector <int> v3 = boyer.search(pattern);
// for (int i = 0; i < v3.size(); ++i)
// {
// 	cout<<v3[i]<<'\t';

// 	}
// cout<<endl;

	return 0;
}