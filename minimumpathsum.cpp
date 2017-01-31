#include <iostream>
#include <fstream>
using namespace std;
int matSize;



int traversePath(int ** theMat, int x, int y, int pathCost){
		int down, right, downCost, rightCost;
		bool dGo = true, rGo = true;
		if((x+1) == matSize && (y+1) == matSize){
				return pathCost;
		}
		else{
				if((x+1) < matSize){
						downCost = pathCost + theMat[x+1][y];
						down = traversePath(theMat, x+1,y,downCost);
				}
				else{
						dGo = false;//won't be going that way
				}
				if((y+1) < matSize){
						rightCost = pathCost + theMat[x][y+1];
						right = traversePath(theMat, x,y+1,rightCost);
				}
				else{
						rGo = false;
				}
		}
		if(rGo == true && dGo == true && down > right || dGo == false){
				return right;
		}		
		else{
				return down;
		}
}


int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
		int place0, place1;
		int ** theMat;
    while (getline(stream, line)) {
				matSize = stoi(line);
				theMat = new int *[matSize];
				//code to fill the array
				for(int i = 0; i < matSize; i++){
						theMat[i] = new int[matSize];
						getline(stream, line);
						place0 = 0;
						for(int j = 0; j < matSize; j++){
								place1 = line.find(',', place0);
								//cout<<place0<<" "<<place1<<endl;
								//cout<<line.substr(place0, place1-place0)<<endl;
								theMat[i][j] = stoi(line.substr(place0, place1-place0));
								place0 = place1+1;
						}
				}
				//code to traverse the array
				//I despise recursion, but it's an easy way to do this one
				cout<<traversePath(theMat, 0, 0, theMat[0][0])<<endl;
    }
    return 0;
}
