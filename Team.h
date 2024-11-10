#ifndef TEAM_H
#define TEAM_H
using namespace std;
#include <vector>
#include "Player.h"

class Team {
private:
    vector<Player> players;
    int total_score;

public:
    Team(const vector<string>& player_names);

    void bat(int overs_per_player);
    void reset();
    int get_total_score() const;
    void print_team_summary() const;
    bool all_players_out() const;
};

#endif
