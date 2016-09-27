#include "fuerzabruta.cpp"
#include <iostream>
#include <vector>

using namespace std;


int main(){
	
string text = " ala la ola oala laa laa lalalalal";
string pattern = "la";

BF beff(text);
std::vector<int> v=beff.findpattern(pattern);

for (int i = 0; i < v.size(); ++i)
{
	cout<<v[i]<<endl;

	}



	return 0;
}