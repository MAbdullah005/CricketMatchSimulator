// Player.h
#ifndef PLAYER_H
#define PLAYER_H
using namespace std;
#include <string>

class Player {
private:
    std::string player_name;
    int balls_played;
    int total_score;
    int fours;     
    int sixes;     
    int dot_balls; 
    bool is_out;   

public:
    Player(std::string name);

    void set_score(int score);
    void set_ball_played(int played_ball);
    void set_out(bool out_status);

    string get_name() const;
    int get_balls_played() const;
    int get_score() const;
    int get_fours() const;
    int get_sixes() const;
    int get_dot_balls() const;
    bool is_player_out() const;

    float get_strike_rate() const;
    void reset();
    void add_four();
    void add_six();
    void add_dot_ball();
};

#endif
