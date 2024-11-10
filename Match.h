#ifndef MATCH_H
#define MATCH_H
using namespace std;
#include "Team.h"

class Match {
private:
    Team team_1;
    Team team_2;
    int overs_per_player;  // Number of overs each player faces

public:
    Match(const vector<string>& team_1_names, const vector<string>& team_2_names, int overs);

    void start_innings(Team& team);
    void start();
    void determine_winner() const;
};

#endif
