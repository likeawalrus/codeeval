#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char *argv[]) {
    string key = "BHISOECRTMGWYVALUZDNFJKPQX";
		string base = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		string encrypted = "012222 1114142503 0313012513 03141418192102 0113 2419182119021713 06131715070119";
		char arr[26];
		int place;
		for(int i = 0; i < key.length(); i ++){		
			//cout<<key.at(i)-'A'<<' ';
			place = key.at(i)-'A';
			arr[place] = base.at(i);
		}
		for(int x = 0; x<encrypted.length(); x=x+2){
			if(encrypted.at(x) == ' '){
				cout<<' ';
				x++;
			}
			place = stoi(encrypted.substr(x,2));
			cout<<arr[place];
		}
    return 0;
}
