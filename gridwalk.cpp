/* Sample code to read in test cases: */
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//array to check if a location has been checked
bool checked[299][299] = {false};
vector<int> toSortX;
vector<int> toSortY;

void push (int x, int y){
	toSortX.push_back(x);
	toSortY.push_back(y);
}

int main(int argc, char *argv[]) {
		int counter = 0;
		int thePoint[2];
    int x = 0;
    int y = 0;
		push(x, y);
    while (!toSortX.empty()) {
			thePoint[0] = toSortX.back();
			toSortX.pop_back();
			thePoint[1] = toSortY.back();
			toSortY.pop_back();
			checked[thePoint[0]][thePoint[1]] = true;
			if(thePoint[0]/100+(thePoint[0]%100/10)+thePoint[0]%10+thePoint[1]/100+(thePoint[1]%100/10)+thePoint[1]%10 <= 19){
				counter+=1;
				if(!checked[thePoint[0]+1][thePoint[1]]){
					push(thePoint[0]+1, thePoint[1]);
				}
				if(!checked[thePoint[0]][thePoint[1]+1]){
					push(thePoint[0], thePoint[1]+1);
				}
			}	
    }
		counter-=299;
		counter*=4;
		counter+=1;
		cout<<counter<<endl;
    return 0;
}
