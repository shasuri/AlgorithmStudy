#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int players;
    cin >> players;

    vector<pair<int,pair<int,int>>> playerList;

    for(int i=0;i < players;i++){
        pair<int,pair<int,int>> player;
        int playerNum, lead, speed, boardering, score;
        
        cin >> playerNum >> lead >> speed >> boardering;

        player.first = playerNum;
        player.second.first = lead*speed*boardering;
        player.second.second = lead+speed+boardering;

        playerList.push_back(player);
    }

    struct {
        bool operator()(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b) const {
            if(a.second.first == b.second.first){
                if(a.second.second == b.second.second){
                    return a.first < b.first;
                }
                return a.second.second < b.second.second;
            }
            return a.second.first < b.second.first;
        }
    }comp;

    sort(playerList.begin(), playerList.end(), comp);

    for(int i=0;i < 3;i++){
        cout << playerList[i].first << " ";
    }
}