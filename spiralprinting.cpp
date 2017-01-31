#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line, toAdd;
		int row, column, space, space2;
		char *** arrX;
		char ** arrY;
    while (getline(stream, line)) {
				space = line.find(';');
				row = stoi(line.substr(0, space));
				arrX = new char**[row];
				space2 = line.find(';', space+1);
				column = stoi(line.substr(space+1, space2-space-1));
				for(int i = 0; i < row; i++){
						arrX[i] = new char*[column];
				}
				for(int i = 0; i < row; i ++) {
						for(int j = 0; j < column; j++){
								space = space2;
								space2 = line.find(' ', space+1);
								toAdd = line.substr(space+1, space2-space-1);
								arrX[i][j] = new char[toAdd.length()+1];
								for(int k = 0; k < toAdd.length(); k++){
										arrX[i][j][k] = toAdd.at(k);
								}
								arrX[i][j][toAdd.length()] = 0;
						}
				}
				int beginX = 0;
				int endX = row;
				int beginY = 0;
				int endY = column;
				int counterX = 0;
				int counterY = 0;
				//cout<<"made it this far"<<endl;
				int k = 0;
				while(arrX[counterX][counterY][k] != 0){
						cout<<arrX[counterX][counterY][k];
						k++;
				}
				k = 0;
				counterY++;
				while(beginX < endX && beginY < endY){
						while(counterY < endY){
								cout<<" ";
								while(arrX[counterX][counterY][k] != 0){
										cout<<arrX[counterX][counterY][k];
										k++;
								}
								k = 0;
								counterY++;
						}
						counterY--;
						counterX++;
						while(counterX < endX){
								cout<<" ";
								while(arrX[counterX][counterY][k] != 0){
										cout<<arrX[counterX][counterY][k];
										k++;
								}
								k = 0;
								counterX++;
						}						
						counterX--;
						counterY--;
						//cout<<"at this point"<<beginX<<" "<<endX<<" "<<beginY<<" "<<endY<<endl;
						while(counterY>=beginY && beginX != endX-1){
								cout<<" ";
								while(arrX[counterX][counterY][k] != 0){
										cout<<arrX[counterX][counterY][k];
										k++;
								}
								k = 0;
								counterY--;
						}
						counterY++;
						counterX--;
						while(counterX>beginX && beginY != endY-1){
								cout<<" ";
								while(arrX[counterX][counterY][k] != 0){
										cout<<arrX[counterX][counterY][k];
										k++;
								}
								k = 0;
								counterX--;
						}
						beginX+=1;
						endX-=1;
						beginY +=1;
						endY-=1;
						counterX = beginX;
						counterY = beginY;						
				}
				cout<<endl;				
    }
    return 0;
}
