#include "fuerzabruta.cpp"
#include "KMP.cpp"
#include "Rabit-Karp.cpp"
#include "Rabit-Karp2.cpp"
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
  }
  else return 0;
}

string gen_random(const int len) {
	string str;
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < len; ++i) {
        str.push_back(alphanum[rand() % (sizeof(alphanum) - 1)]);
    }

    return str;
}


void randomstr(const char *filename){
	// pasara archivo text a string
	string test= get_file_contents(filename);
	//cout<<test.size()<<endl;
	int size=test.size();
	//cout<< int(0.00001*size)<<endl;
	//tamaño del patron a buscar
	int pattern_size=30;
	// posicion del patron a buscar
	//int patter_pos = rand()%(size - pattern_size);
	string patron= gen_random(pattern_size);
	//string patron("GLLLLLLLV");
	cout << patron<< endl;

	//cout<<patron<<endl;
	//algoritmo 1
	BF beff(test);
	//algoritmo 2
	BM boyer(test,patron);
	//algoritmo 3
	KMPs km(test,patron);
	//algoritmo 4
	RK rabit(test);
	//algoritmo 4*
	//RK2 rk(test);
	
	clock_t comienzo;
	double fin;


	
	int v1,v2,v3,v4,v4_2 ;

	comienzo=clock();
	v1=beff.findpattern(patron);
	fin=(clock()-comienzo)/(double)CLOCKS_PER_SEC;
	cout <<"Tiempo de fuerza bruta :"<< fin<<" indice encontrado :"<<v1<<endl;


	comienzo=clock();
	v2=boyer.search(patron);
	fin=(clock()-comienzo)/(double)CLOCKS_PER_SEC;
	cout <<"Tiempo de boyer moore :"<< fin<<" indice encontrado :"<<v2<<endl;


	comienzo=clock();
	v3=km.KMPSearch(patron);
	fin=(clock()-comienzo)/(double)CLOCKS_PER_SEC;
	cout <<"Tiempo de KMP :"<< fin<<" indice encontrado :"<<v3<<endl;
	v3 = rabit.search(patron);

	comienzo=clock();
	v4=rabit.search(patron);
	fin=(clock()-comienzo)/(double)CLOCKS_PER_SEC;
	cout <<"Tiempo de Rabit-Karp :"<< fin<<" indice encontrado :"<<v4<<endl;
	
	// comienzo=clock();
	// v4_2=rk.search(patron);
	// fin=(clock()-comienzo)/(double)CLOCKS_PER_SEC;
	// cout <<"Tiempo de Rabit-Karp 2:"<< fin<<endl;


}


int en_texto(const char *filename){
	// pasara archivo text a string
	string test= get_file_contents(filename);
	//cout<<test.size()<<endl;
	int size=test.size();
	//cout<< int(0.00001*size)<<endl;
	//tamaño del patron a buscar
	int pattern_size=30;
	// posicion del patron a buscar
	int patter_pos = rand()%(size - pattern_size);
	string patron(test.substr(patter_pos,pattern_size));
	//string patron("GLLLLLLLV");

	cout<<patron<<endl;
	//algoritmo 1
	BF beff(test);
	//algoritmo 2
	BM boyer(test,patron);
	//algoritmo 3
	KMPs km(test,patron);
	//algoritmo 4
	RK rabit(test);
	//algoritmo 4*
	RK2 rk(test);
	
	clock_t comienzo;
	double fin;


	
	int v1,v2,v3,v4,v4_2 ;

		comienzo=clock();
	v1=beff.findpattern(patron);
	fin=(clock()-comienzo)/(double)CLOCKS_PER_SEC;
	cout <<"Tiempo de fuerza bruta :"<< fin<<" indice encontrado :"<<v1<<endl;


	comienzo=clock();
	v2=boyer.search(patron);
	fin=(clock()-comienzo)/(double)CLOCKS_PER_SEC;
	cout <<"Tiempo de boyer moore :"<< fin<<" indice encontrado :"<<v2<<endl;


	comienzo=clock();
	v3=km.KMPSearch(patron);
	fin=(clock()-comienzo)/(double)CLOCKS_PER_SEC;
	cout <<"Tiempo de KMP :"<< fin<<" indice encontrado :"<<v3<<endl;
	v3 = rabit.search(patron);

	comienzo=clock();
	v4=rabit.search(patron);
	fin=(clock()-comienzo)/(double)CLOCKS_PER_SEC;
	cout <<"Tiempo de Rabit-Karp :"<< fin<<" indice encontrado :"<<v4<<endl;
	
	// comienzo=clock();
	// v4_2=rk.search(patron);
	// fin=(clock()-comienzo)/(double)CLOCKS_PER_SEC;
	// cout <<"Tiempo de Rabit-Karp 2:"<< fin<<endl;
	// for ( int i = 0 ; i<v1.size();i++) {
	// 	cout<< v1[i]<<" "<<v2[i]<<" "<<v3[i]<<" "<<v4[i]<<endl;
	// }
	
 return 0;
}


int main(){
srand (time(NULL));


randomstr("dna.200MB");

en_texto("dna.200MB");


	return 0;
}