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
    int rosterNum;
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

void rosterSelectionProcess(vector<List> &fullList, int rosterNum){
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
                fullList[i].insert(option);
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
            fullList[i].changeData(fullList[i].head, option, option2);
            cout << "Your updated team selection is:" << endl;
            fullList[i].print();
            cout << "If you would like to change a player on your team selection, type their name, otherwise type DONE" << endl;
            cin >> option;
        }
    }
}

int main(int argc, char * argv[]){
    
    vector<List> fullList = playerInsert();
   
    random_shuffle(begin(fullList), end(fullList));
   
    rosterNum = getRosterSize();

    rosterSelectionProcess(fullList, rosterNum);

    cout << fullList[0].getSize() << endl;

    int i = 0;
    int j = 0;
    bool exit = false;
    while (!exit){
        if (i >= fullList.size()){
            i = 0;
        }

        string owner = fullList[i].owner;
        bool escape = false;
        cout << "lopp" << endl;
        while (!escape){
            // get node from curret list's index
            string value = fullList[i].getDataAtIndex();
            auto search = map.find(value);
            if (search == map.end()){
                map.insert(make_pair(value, owner));      
                cout << "inserted draft " << value << " for player " << owner << endl;
                fullList[i].incIndex();
                // increment index;
                escape = true;
            }
            else {
                if (fullList[i].head == NULL){
                    cout << fullList[i].owner << ", please insert another player" << endl;
                    cin >> option; 
                    fullList[i].insert(option);
                }
                else fullList[i].incIndex();
            }
        }
        i++;
        j++;
        if (j >= (rosterNum * fullList.size())) {
            exit = true;
        }
    }
}