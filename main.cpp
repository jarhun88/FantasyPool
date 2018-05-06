#include "linked_list.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// vector<List> arrayRandomizer(vector<List> &a){
//     int max = a.size() - 1;
//     for (int i = 0; i < a.size(); i++){
//         List temp = a[i];
//         int randint = rand() % max + i;
//         a[i] = a[randint];
//         a[randint] = temp;
//         cout << "randint is: " << randint << endl;
//         cout << "a[i] is : " << a[i].owner << endl;
//         cout <<"a[randint] is : " << a[randint].owner << endl;
//     }
//     return a;
// }

int main(int argc, char * argv[]){
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
    for (int i = 0; i < fullList.size(); i++){
        cout << fullList[i].owner << endl;
    }
    random_shuffle(begin(fullList), end(fullList));
    for (int i = 0; i < fullList.size(); i++){
        cout << fullList[i].owner << endl;
    }

    cout << "Input # of players in roster" << endl;
    cin >> rosterNum;
    cout << rosterNum << " players allowed in a team" << endl;
    for (int i = 0; i < fullList.size(); i++){
        cout << fullList[i].owner << ", please insert " << rosterNum << " players one by one." << endl;
        cout << "If you would like to remove your last pick, type REMOVE and enter" << endl;
        for (int j = 0; j < rosterNum; j++){
            string draft;
            cin >> draft; 
            if (draft == "REMOVE"){
                fullList[i].remove(fullList[i].head);
            }
            else 
                fullList[i].insert(fullList[i].head, draft);
        }
        cout << "Your team is: " << endl;
        fullList[i].print(fullList[i].head);
        cout << "If you would like to remove the last pick, type REMOVE, otherwise type DONE";
    }

}