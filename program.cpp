#include <iostream>
#include <vector>
#include "Match.h"
using namespace std;
int main() {
    srand(time(0));

    vector<string> team_1_names = {
        "Babar Azam", "Naseem Shah", "Agha Salman", "Mohammad Amir", "Shaheen Afridi",
        "Shadab Khan", "Imad Wasim", "Fakar Zaman", "Haris Rauf", "Mohammad Rizwan", "Iftikhar Ahmad"
    };

    vector<string> team_2_names = {
        "Virat Kohli", "Rohit Sharma", "Shubman Gill", "Hardik Pandya", "Jasprit Bumrah",
        "Rishabh Pant", "KL Rahul", "Shreyas Iyer", "Mohammad Shami", "Yuzvendra Chahal", "Ravindra Jadeja"
    };

    int overs_per_player = 3;  // Each player faces 3 overs (18 balls)

    // Initialize the match with two teams
    Match match(team_1_names, team_2_names, overs_per_player);

    // Start the match
    match.start();

    return 0;
}
