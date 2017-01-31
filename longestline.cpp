#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct node {
    string theString;
    node* nextNode = NULL;
};

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    getline(stream, line);
    int listSize = stoi(line, NULL, 0);
    node begin;
    begin.theString = "";
    begin.nextNode = NULL;
    node* head = &begin;
    while (getline(stream, line)) {
        int x = line.length();
        node * currNode = head;
        bool done = false;
        node * thisNode = new node;
        thisNode->theString = line;
        while(!done){
            if(currNode->nextNode == NULL){
                thisNode->nextNode = NULL;
                currNode->nextNode = thisNode;
                done = true;
            }
            else if(currNode->nextNode->theString.length() < x){
                thisNode->nextNode = currNode->nextNode;
                currNode->nextNode = thisNode;
                done = true;
            }
            else {
                currNode = currNode->nextNode;
            }
        }
    }
    node * currNode = head;
    for(int i = 0; i < listSize; i++){
        cout<<currNode->nextNode->theString<<endl;
        currNode = currNode->nextNode;
    }
    return 0;
}
