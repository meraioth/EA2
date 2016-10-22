#include "fuerzabruta.cpp"
#include "KMP.cpp"
#include "Rabit-Karp.cpp"
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

void randomstr(const char *filename, const char *resultados_archivo){
	// pasara archivo text a string
	string test= get_file_contents(filename);
    FILE *resultados;
    cout << filename <<endl;
    resultados = fopen(resultados_archivo, "w+");
    for(int pattern_size = 100 ; pattern_size <= 10000 ; pattern_size+=100){
        fprintf(resultados,"%d\t",pattern_size);
        double res1 = 0, res2 = 0, res3 = 0, res4 = 0;
        for(int j = 0 ; j < 10 ; j++){
            string patron = gen_random(pattern_size);
            //algoritmo 1
        	BF beff(test);
        	//algoritmo 2
        	BM boyer(test,patron);
        	//algoritmo 3
        	KMPs km(test,patron);
        	//algoritmo 4
        	RK rabin(test);
            //para medir el tiempo de ejecucion
            clock_t comienzo;
        	double fin;

            comienzo=clock();
        	beff.findpattern(patron);
        	res1+=(clock()-comienzo)/(double)CLOCKS_PER_SEC;

            comienzo=clock();
        	boyer.search(patron);
        	res2+=(clock()-comienzo)/(double)CLOCKS_PER_SEC;

        	comienzo=clock();
        	km.KMPSearch(patron);
        	res3+=(clock()-comienzo)/(double)CLOCKS_PER_SEC;

        	comienzo=clock();
            rabin.search(patron);
        	res4+=(clock()-comienzo)/(double)CLOCKS_PER_SEC;
        }
        fprintf(resultados,"%lf\t",res1/10);
        fprintf(resultados,"%lf\t",res2/10);
        fprintf(resultados,"%lf\t",res3/10);
        fprintf(resultados,"%lf\n",res4/10);
    }
    fclose(resultados);
}

void en_texto(const char *filename, const char *resultados_archivo){
	// pasara archivo text a string
    cout << filename <<endl;
	string test= get_file_contents(filename);
    FILE *resultados;
    int size=test.size();
    char *resultado_buffer;
    resultados = fopen(resultados_archivo, "w+");
    for(int pattern_size = 100 ; pattern_size <= 10000 ; pattern_size+=100){

        fprintf(resultados,"%d\t",pattern_size);

        double fin1=0.0,fin2=0.0,fin3=0.0,fin4=0.0;
        for(int i = 0 ; i < 2 ; i ++){
            //posicion del patron contenido en el texto
            int patter_pos = rand()%(size - pattern_size);
            //patron a buscar
        	string patron(test.substr(patter_pos,pattern_size));
            //algoritmo 1
        	BF beff(test);
        	//algoritmo 2
        	BM boyer(test,patron);
        	//algoritmo 3
        	KMPs km(test,patron);
        	//algoritmo 4
        	RK rabin(test);
            //para medir el tiempo de ejecucion
            clock_t comienzo;

            comienzo=clock();
        	beff.findpattern(patron);
        	fin1=fin1+(clock()-comienzo)/(double)CLOCKS_PER_SEC;

            comienzo=clock();
        	boyer.search(patron);
        	fin2=fin2+(clock()-comienzo)/(double)CLOCKS_PER_SEC;

            comienzo=clock();
        	km.KMPSearch(patron);
        	fin3=fin3+(clock()-comienzo)/(double)CLOCKS_PER_SEC;

            comienzo=clock();
            rabin.search(patron);
        	fin4=fin4+(clock()-comienzo)/(double)CLOCKS_PER_SEC;
        }
        fin1=fin1/10.0;
        fin2=fin2/10.0;
        fin3=fin3/10.0;
        fin4=fin4/10,0;

        fprintf(resultados,"%lf\t",fin1);
        fprintf(resultados,"%lf\t",fin2);
        fprintf(resultados,"%lf\t",fin3);
        fprintf(resultados,"%lf\n",fin4);
    }
    fclose(resultados);
}

void supervisado( const char *resultados_archivo){
    string test;
    string patron;
    int size=100000;
    int pattern_size;

    for(int i = 0; i<size ; i++)
        test.push_back('A');
       
    
    test.push_back('B');
    

    FILE *resultados;
   
    char *resultado_buffer;
    resultados = fopen(resultados_archivo, "w+");
    for(int pattern_size = 100 ; pattern_size <= 10000 ; pattern_size+=100){
        for(int i = 0; i<pattern_size ; i++)
            patron.push_back('A');
    
        patron.push_back('B');

        fprintf(resultados,"%d\t",pattern_size);

        double fin1=0.0,fin2=0.0,fin3=0.0,fin4=0.0;
        for(int i = 0 ; i < 2 ; i ++){
           
            //algoritmo 1
            BF beff(test);
            //algoritmo 2
            BM boyer(test,patron);
            //algoritmo 3
            KMPs km(test,patron);
            //algoritmo 4
            RK rabin(test);
            //para medir el tiempo de ejecucion
            clock_t comienzo;

            comienzo=clock();
            beff.findpattern(patron);
            fin1=fin1+(clock()-comienzo)/(double)CLOCKS_PER_SEC;

            comienzo=clock();
            boyer.search(patron);
            fin2=fin2+(clock()-comienzo)/(double)CLOCKS_PER_SEC;

            comienzo=clock();
            km.KMPSearch(patron);
            fin3=fin3+(clock()-comienzo)/(double)CLOCKS_PER_SEC;

            comienzo=clock();
            rabin.search(patron);
            fin4=fin4+(clock()-comienzo)/(double)CLOCKS_PER_SEC;
        }
        fin1=fin1/10.0;
        fin2=fin2/10.0;
        fin3=fin3/10.0;
        fin4=fin4/10,0;
        cout<<"1: "<<fin1<<" 2: "<<fin2<<" 3: "<<fin3<<" 4:"<<fin4<<endl;
        fprintf(resultados,"%lf\t",fin1);
        fprintf(resultados,"%lf\t",fin2);
        fprintf(resultados,"%lf\t",fin3);
        fprintf(resultados,"%lf\n",fin4);
    }
    fclose(resultados);



}



int main(){
    srand (time(NULL));
    //experimentos sobre texto natural
    //randomstr("english.50MB","english50_r.txt");
    //randomstr("english.100MB","english100_r.txt");
    //randomstr("english.200MB","english200_r.txt");
    en_texto("english.50MB","english50_t.txt");
    en_texto("english.100MB","english100_t.txt");
    //en_texto("english.200MB","english200_t.txt");
    //experimentos sobre adn
    en_texto("dna.50MB","dna50_r.txt");
    en_texto("dna.100MB","dna100_r.txt");
    //en_texto("dna.200MB","dna200_r.txt");
    //randomstr("dna.50MB","dna50_t.txt");
    //randomstr("dna.100MB","dna100_t.txt");
    //randomstr("dna.200MB","dna200_t.txt");
    //experimento peor caso
    supervisado("supervisad.txt");
	return 0;
}
