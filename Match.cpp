#include "Match.h"
#include <iostream>

using namespace std;

Match::Match(const vector<string>& team_1_names, const vector<string>& team_2_names, int overs)
    : team_1(team_1_names), team_2(team_2_names), overs_per_player(overs) {}

void Match::start_innings(Team& team) {
    team.bat(overs_per_player);
    team.print_team_summary();
}

void Match::start() {
    cout << "\n***** Team 1 Batting *****\n";
    start_innings(team_1);

    if (team_1.all_players_out()) {
        cout << "All players are out! Switching to Team 2." << endl;
    }

    cout << "\n***** Team 2 Batting *****\n";
    start_innings(team_2);

    if (team_2.all_players_out()) {
        cout << "All players are out! Match ends." << endl;
    }

    determine_winner();
}

void Match::determine_winner() const {
    int team_1_score = team_1.get_total_score();
    int team_2_score = team_2.get_total_score();

    cout << "\n***** Match Result *****\n";

    cout << "Team 1 Score: " << team_1_score << endl;
    cout << "Team 2 Score: " << team_2_score << endl;

    if (team_1_score > team_2_score) {
        cout << "Team 1 wins!" << endl;
    } else if (team_2_score > team_1_score) {
        cout << "Team 2 wins!" << endl;
    } else {
        cout << "It's a tie!" << endl;
    }
}
