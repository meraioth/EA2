
#include "iostream"
#include <string>
#include <cmath>
#include <vector>
#define b 10
#define m 101
typedef long long  llu;

using namespace std;

llu hash_generate(string str){
	
	llu hash_val=0;

	for(int i=0, l=str.length()-1 ;i< str.length();i++ , l--){
		hash_val+= (str[i])*pow(b,l);
		



	}
	return hash_val;
}


vector<int> rabin_karp(string text, string pattern){
	int L = pattern.length();
	int n = text.length();
	cout<<"text : "<<n<<" pattern :"<<L<<endl;
	bool check;
	vector <int > ocurrence;
	llu hash_pat = hash_generate(pattern);
	llu h1 = hash_generate(text.substr(0,L));
	cout << "patron :"<<pattern<<" substr :"<<text.substr(0,L)<<endl;
	int hp=hash_pat%m;
	int ht=h1%m;



	if (hp == ht){
		cout<< " Encontrado "<<endl;
		check=true;
		for(int i=0;i<L;i++){
			if(text[i]!=pattern[i]) check=false;

			}
		if(check) ocurrence.push_back(0);
		
	}
	else {
		for(int i=1;i<=n-L;i++){
			cout<<"i:"<<i<<"  L:  "<<L<<"         substring :"<<text.substr(i,L)<<endl;
			cout<<"caracter a sacar :"<<text[i-1]<<" caracter a colocar :"<<text[i+L-1]<<endl;
			cout<<"hash pattern : "<<hash_pat << " hash text desde :"<<i<<" hasta :"<<i+L-1 << "  :"<<h1<<endl;
			int aux = b*h1;
			cout<<"b*h1 :"<<aux<<endl;
			cout<<"b^L-1*text[i-1] :"<<(int)pow(b,L-1)*text[i-1]<<endl;
			h1= (b*(h1-(int)pow(b,L-1)*text[i-1])+(int)text[i+L-1]) ;
			ht=h1%m;
			if(hp==ht){
				check=true;
				for(int j=0;j<L;j++){
					if(text[i+j]!=pattern[j]) check=false;

				}
				if(check) ocurrence.push_back(i);
			}
		}

	}
	return ocurrence;

}



int main(){

	string str("489001230120301203122");
	string str1("203012");
	int aux = hash_generate(str);
	cout<<"hash"<<aux<<endl;
	vector<int > found=rabin_karp(str,str1);
	
	for(int i=0;i<found.size();i++){
		cout<<"encontrado en posicion"<<found[0]<<endl;
	}
	return 0;
}




