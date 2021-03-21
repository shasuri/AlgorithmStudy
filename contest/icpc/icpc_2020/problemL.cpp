#include <iostream>
#include <vector>

using namespace std;

int main(){
    int coinNum;
    int movePos1, movePos2;


    cin >> coinNum;

    string coinS;
    string coinT;

    cin >> coinS;
    cin >> coinT;

    cin >> movePos1 >> movePos2;
    string movedCoin;

    movedCoin += coinS[movePos1];
    movedCoin += coinS[movePos2];
    
    coinS.erase(movePos1,1);
    coinS.erase(movePos2-1,1);
    
    int j = 0;

    for(int i = 0; i < coinNum ; i++){
        if(j != coinNum-2 && coinS[j] == coinT[i]){
            j++;
        }

        else if(movedCoin.size() > 0 && coinT[i] == movedCoin[0]){
            movedCoin.erase(0,1);
        }

        else {
            cout << "NO";
            return 0;
        }
    }
    // if(movedCoin.size()==2){
    //     if(coinT[coinNum-2] == movedCoin[0]){
    //         if(coinT[coinNum-1] == movedCoin[1])
    //             cout << "YES";
    //     }
    // }
    // else
    // {
    //     cout<<"NO";
    // }
    cout << "YES";
    
    return 0;

}