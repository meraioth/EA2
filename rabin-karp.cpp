
#include "iostream"
#include <string>
#include <cmath>
#include <vector>
#define b 10
#define prime 101
typedef long long  llu;

using namespace std;


class RK2 {

protected :
string txt;

public:
  RK2( string text);
  vector<int> search(string pattern);
  llu hash_generate(string str);


};
RK2::RK2(string str){
    txt=str;
}


llu RK2::hash_generate(string str){
	
	llu hash_val=0;

	for(int i=0, l=str.length()-1 ;i< str.length();i++ , l--){
		hash_val+= (str[i])*pow(b,l);
		



	}
	return hash_val;
}


vector<int> RK2::search(string pattern){
	int L = pattern.length();
	int n = txt.length();
	bool check;
	vector <int > ocurrence;
	llu hash_pat = hash_generate(pattern);
	llu h1 = hash_generate(txt.substr(0,L));
	int hp=hash_pat%prime;
	int ht=h1%prime;



	if (hp == ht){
		check=true;
		for(int i=0;i<L;i++){
			if(txt[i]!=pattern[i]) check=false;

			}
		if(check) ocurrence.push_back(0);
		
	}
	else {
		for(int i=1;i<=n-L;i++){
			int aux = b*h1;
			h1= (b*(h1-(int)pow(b,L-1)*txt[i-1])+(int)txt[i+L-1]) ;
			ht=h1%prime;
			if(hp==ht){
				check=true;
				for(int j=0;j<L;j++){
					if(txt[i+j]!=pattern[j]) check=false;

				}
				if(check) ocurrence.push_back(i);
			}
		}

	}
	return ocurrence;

}