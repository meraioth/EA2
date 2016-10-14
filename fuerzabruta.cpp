#include <iostream>
#include <vector>
using namespace std;

class BF{
protected :
string text;
//string pattern;
//std::vector<int> ocurrencias;

public:
	BF( string text);
	vector<int> findpattern(string pattern);


};


BF::BF( string text){
		this->text = text;
		//this.pattern=pattern;

	}

 vector<int> BF::findpattern(string pattern){
		std::vector<int> ocurrencias;

		if(text.length()==0 || pattern.length()==0) return ocurrencias;
		
		int text_size=text.length();
		int pattern_size = pattern.length();


	    for(int i =0; i<text_size;i++){


	    	for (int j = 0; j < pattern_size; j++)
	    	{
	    		if(text[i+j] != pattern[j]) break;
	    		else if(j==pattern_size-1) ocurrencias.push_back(i);
	    	}

	    }

	    return ocurrencias;


	}