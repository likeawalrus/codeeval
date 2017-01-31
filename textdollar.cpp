#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
		int numbLength, currNumb = 0;
    while (getline(stream, line)) {
        // Do something with the line
				numbLength = line.length();
				currNumb = numbLength;
				for(int i = 0; i < numbLength; i++){
						if(currNumb%3 == 1 || currNumb%3 == 0){
							if(line.at(i) == '9'){
								cout<<"Nine";
							}
							else if(line.at(i) == '8'){
								cout<<"Eight";
							}
							else if(line.at(i) == '7'){
								cout<<"Seven";
							}
							else if(line.at(i) == '6'){
								cout<<"Six";
							}
							else if(line.at(i) == '5'){
								cout<<"Five";
							}
							else if(line.at(i) == '4'){
								cout<<"Four";
							}
							else if(line.at(i) == '3'){
								cout<<"Three";
							}
							else if(line.at(i) == '2'){
								cout<<"Two";
							}
							else if(line.at(i) == '1'){
								cout<<"One";
							}
							else if(line.at(i) == '0' && numbLength == 1){
								cout<<"Zero";
							}
						}						
						if(currNumb == 2 || currNumb == 5 || currNumb == 8 ){
							if(line.at(i) == '9'){
								cout<<"Ninety";
							}
							else if(line.at(i) == '8'){
								cout<<"Eighty";
							}
							else if(line.at(i) == '7'){
								cout<<"Seventy";
							}
							else if(line.at(i) == '6'){
								cout<<"Sixty";
							}
							else if(line.at(i) == '5'){
								cout<<"Fifty";
							}
							else if(line.at(i) == '4'){
								cout<<"Forty";
							}
							else if(line.at(i) == '3'){
								cout<<"Thirty";
							}
							else if(line.at(i) == '2'){
								cout<<"Twenty";
							}
							else if(line.at(i) == '1'){
								i++;
								currNumb--;
								if(line.at(i) == '9'){
									cout<<"Nineteen";
								}
								else if(line.at(i) == '8'){
									cout<<"Eighteen";
								}
								else if(line.at(i) == '7'){
									cout<<"Seventeen";
								}
								else if(line.at(i) == '6'){
									cout<<"Sixteen";
								}
								else if(line.at(i) == '5'){
									cout<<"Fifteen";
								}
								else if(line.at(i) == '4'){
									cout<<"Fourteen";
								}
								else if(line.at(i) == '3'){
									cout<<"Thirteen";
								}
								else if(line.at(i) == '2'){
									cout<<"Twelve";
								}
								else if(line.at(i) == '1'){
									cout<<"Eleven";
								}
								else if(line.at(i) == '0'){
									cout<<"Ten";
								}
								if(currNumb == 6){
									cout<<"Million";
								}
								if(currNumb == 3){
									cout<<"Thousand";
								}
							}
						}
						if(currNumb%3 == 0 && currNumb != 0 && line.at(i) != '0'){
							cout<<"Hundred";
						}
						if(currNumb == 7){
							cout<<"Million";
						}
						if(currNumb == 4){
							if(line.at(i) !='0' || (i-1)>=0 && line.at(i-1) != '0' || (i-2)>='0' && line.at(i-2) != '0'){
								cout<<"Thousand";
							}
						}
						currNumb--;
				}
				//if(line.at(0) == '1' && numbLength == 1){
				//	cout<<"Dollar"<<endl;
				//}
				//else{
					cout<<"Dollars"<<endl;
				//}
    }
    return 0;
}
