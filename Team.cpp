// Team.cpp
#include "Team.h"
#include <iostream>
#include <limits>

using namespace std;

Team::Team(const std::vector<std::string>& player_names) {
    total_score = 0;
    for (const auto& name : player_names) {
        players.push_back(Player(name));
    }
}

void Team::bat(int overs_per_player) {
    int total_balls = overs_per_player * 6;

    for (auto& player : players) {
        if (player.is_player_out()) continue;

        cout << "\n" << player.get_name() << " is batting!" << endl;
        int score, balls_faced = 0;

        while (balls_faced < total_balls) {
            cout << "Ball " << balls_faced + 1 << ": ";
            while (true) {
                if (!(cin >> score)) {
                    cout << "Invalid input. Please enter a number between 0 and 6, or -1 for out." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                if (score == -1) {
                    cout << "OUT!" << endl;
                    player.set_out(true);
                    break;
                }
                if (score < 0 || score > 6) {
                    cout << "Invalid score. Please enter a score between 0 and 6, or -1 for out." << endl;
                    continue;
                }

                player.set_score(score);
                player.set_ball_played(1);
                balls_faced++;
                break;
            }
            if (player.is_player_out()) break;
        }

        cout << "Total Score for " << player.get_name() << ": " << player.get_score() << endl;
        cout << "Balls faced: " << player.get_balls_played() << endl;
    }
}

void Team::reset() {
    total_score = 0;
    for (auto& player : players) {
        player.reset();
    }
}

int Team::get_total_score() const {
    int score = 0;
    for (const auto& player : players) {
        score += player.get_score();
    }
    return score;
}

void Team::print_team_summary() const {
    cout << "\n<<<<<<<<<<<<<  Team Summary >>>>>>>>>>>>>>" << endl;
    cout << "Player Name \t Score \t Balls Played \t Fours \t Sixes \t Strike Rate \t Dot Balls" << endl;

    for (const auto& player : players) {
        cout << player.get_name() << "\t\t" << player.get_score() << "\t\t" 
             << player.get_balls_played() << "\t\t" << player.get_fours() << "\t\t" 
             << player.get_sixes() << "\t\t" << player.get_strike_rate() << "\t\t"
             << player.get_dot_balls() << endl;
    }

    cout << "Total Team Score: " << get_total_score() << endl;
}

bool Team::all_players_out() const {
    for (const auto& player : players) {
        if (!player.is_player_out()) {
            return false;
        }
    }
    return true;
}
