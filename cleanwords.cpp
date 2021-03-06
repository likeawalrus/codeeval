#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
		bool popped = false;
    while (getline(stream, line)) {
        // Do something with the line
				//for loop for a string
				popped = false;
				for(int i = 0; i<line.length(); i++){
					//get rid of leading junk
					while(i<line.length() && ((line.at(i) < 'a' || line.at(i) > 'z') && (line.at(i) < 'A' || line.at(i) > 'Z'))){
						i++;
					}
					//print following space if not end of line
					if(i<line.length() && popped == true)	{					
						cout<<' ';
					}
					//print word					
					while(i<line.length() && (line.at(i) >= 'a' && line.at(i) <= 'z' || line.at(i) >= 'A' && line.at(i) <= 'Z')){
						if(line.at(i) >= 'A' && line.at(i) <= 'Z'){
							cout<<((char)(line.at(i)+32));
						}
						else{
							cout<<line.at(i);
						}
						i++;
						popped = true;
					}
				}
				cout<<endl;				
    }
    return 0;
}
