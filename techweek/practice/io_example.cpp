/*
 * PNU TECHWEEK Competition
 * Practice Session Python I/O Example
 */

#include <iostream>
using namespace std;

int main() {

    // Get N from standard input
    int N;
    cin >> N;

    // Declare array to contain vote results
    int votes[101];

    // get each vote result in 'votes' array with for loop
    for(int i=0; i<N; i++)
        cin >> votes[i];
        
    // calculate answer

    /*
    TO-DO part
    Uses votes[0] as a temporary answer
    */
    int answer = votes[0];

    // print answer
    cout << answer;

}