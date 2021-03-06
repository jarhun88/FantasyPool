#include "linked_list.h"
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

string option;
string option2;
int rosterNum;
unordered_map<string, string> map;

vector<List> playerInsert(){
    cout << "welcome to the FantasyPool generator" << endl;
    cout << "How many participants are there?" << endl;
    int num;
    cin >> num; 
    vector<List> fullList;
     
    for (int i = 0; i < num; i++){
        string player;
        // add player # somehow
        cout << "insert Player's name" << endl;
        cin >> player; 
        fullList.push_back(List(player));
    }
    return fullList;
}

int getRosterSize(){
    int size;
    cout << "Input # of players in roster" << endl;
    cin >> size;
    cout << endl;
    cout << size << " players allowed in a team" << endl;
    cout << endl;
    cout << "Randomizing player selection order" << endl;
    cout << endl;
    return size;
}

void rosterSelectionProcess(vector<List> &fullList){
    for (int i = 0; i < fullList.size(); i++){
        cout << fullList[i].owner << ", please insert " << rosterNum << " players one by one." << endl;
        cout << "If you would like to remove your last pick, type REMOVE and enter" << endl;
        int j = 0;
        while(j < rosterNum){
            cin >> option; 
            if (option == "REMOVE"){
                cout << fullList[i].head->data << " was removed from your list" << endl;
                fullList[i].removeHead();
                j--;
            }
            else {
                fullList[i].insertFront(option);
                j++;
            }
        }
        cout << "Your team selections are: " << endl;
        fullList[i].print();

        cout << "If you would like to change a player on your team selection, type their name, otherwise type DONE" << endl;
        cin >> option;
        while (option != "DONE"){
            cout << "Add the name of the new player you would like to exchange with" << endl;
            cin >> option2;
            fullList[i].changeData(option, option2);
            cout << "Your updated team selection is:" << endl;
            fullList[i].print();
            cout << "If you would like to change a player on your team selection, type their name, otherwise type DONE" << endl;
            cin >> option;
        }
    }
}

void drafting(vector<List> &fullList){
    int i = 0;
    int j = 0;
    bool exit = false;
    while (!exit){
        if (i >= fullList.size()){
            i = 0;
        }
        string owner = fullList[i].owner;
        bool escape = false;
        while (!escape){
            // get node from curret list's index
            string value = fullList[i].getDataAtIndex();
            auto search = map.find(value);
            if (search == map.end()){
                map.insert(make_pair(value, owner));      
                // cout << "inserted draft " << value << " for player " << owner << endl;
                fullList[i].incIndex();
                // cout << "Index incremented to " << index << endl;
                // increment index;
                escape = true;
            }
            else {
                int index = fullList[i].getIndex();
                if (index == 0){
                    fullList[i].removeHead();
                }
                else {
                    fullList[i].removeAtIndex(index);
                }
                cout << fullList[i].owner << ", please insert another player" << endl;
                cin >> option; 
                fullList[i].insertBack(option);
            }
        }
        i++;
        j++;
        if (j >= (rosterNum * fullList.size())) {
            exit = true;
        }
    }
}

void programEnd(vector<List> fullList) {
    cout << "Drafting Complete, Reading every participant's roster:" << endl;
    for (int i = 0; i < fullList.size(); i++){
        cout << fullList[i].owner << "'s roster: " << endl;
        fullList[i].print();
    }
    cout << "Have Fun!" << endl;
}

int main(){
    vector<List> fullList = playerInsert();
    random_shuffle(begin(fullList), end(fullList));
    rosterNum = getRosterSize();
    rosterSelectionProcess(fullList);
    drafting(fullList);
    programEnd(fullList);
}