#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
			int stopper = line.find_first_of(',');
			string theX = line.substr(0, stopper);
			int semicolon = line.find_first_of(';');
			string theY = line.substr(stopper+1, (semicolon-stopper));
			string theGrid = line.substr(semicolon+1);
			int matX = stoi(theX);
			int matY = stoi(theY);
			int ** theMatrix;
			theMatrix = new int * [matX];
			for(int i = 0; i < matX; i++){
				theMatrix[i] = new int [matY];
			}
			//next we need to add values to matrix
			for(int i = 0; i < matX; i++){
				for(int j = 0; j < matY; j++){
					if(theGrid[i*matY+j] == '*'){
						theMatrix[i][j] = 9;
					}	
					else{
						theMatrix[i][j] = 0;
					}
				}
			}
			//then we need to math out where the mines are
			for(int i = 0; i < matX; i++){
				for(int j = 0; j < matY; j++){
					if(theMatrix[i][j] >= 9){
						if(i > 0){
							theMatrix[i-1][j] += 1;
						}
						if(i < (matX-1)){
							theMatrix[i+1][j] += 1;
						}
						if(j > 0){
							theMatrix[i][j-1] += 1;
						}
						if(j < (matY-1)){
							theMatrix[i][j+1] += 1;
						}
						if(i > 0 && j > 0){
							theMatrix[i-1][j-1] += 1;
						}
						if(i > 0 && j < (matY-1)){
							theMatrix[i-1][j+1] += 1;
						}
						if(i < (matX-1) && j > 0){
							theMatrix[i+1][j-1] += 1;
						}
						if(i < (matX-1) && j < (matY-1)){
							theMatrix[i+1][j+1] += 1;
						}
					}	
				}
			}
			//then we just print a bunch of stuff out
			for(int i = 0; i < matX; i++){
				for(int j = 0; j < matY; j++){
					if(theMatrix[i][j] >= 9){
						cout<<'*';
					}	
					else{
						cout<<theMatrix[i][j];
					}
				}
			}
			cout<<endl;			
    }
    return 0;
}
