#include "Player.h"
using namespace std;

Player::Player(string name) {
    player_name = name;
    balls_played = 0;
    total_score = 0;
    fours = 0;
    sixes = 0;
    dot_balls = 0;
    is_out = false;
}

void Player::set_score(int score) {
    total_score += score;
    if (score == 4) {
        add_four();
    } else if (score == 6) {
        add_six();
    } else if (score == 0) {
        add_dot_ball();
    }
}

void Player::set_ball_played(int played_ball) {
    balls_played += played_ball;
}

void Player::set_out(bool out_status) {
    is_out = out_status;
}

string Player::get_name() const {
    return player_name;
}

int Player::get_balls_played() const {
    return balls_played;
}

int Player::get_score() const {
    return total_score;
}

int Player::get_fours() const {
    return fours;
}

int Player::get_sixes() const {
    return sixes;
}

int Player::get_dot_balls() const {
    return dot_balls;
}

bool Player::is_player_out() const {
    return is_out;
}

void Player::reset() {
    balls_played = 0;
    total_score = 0;
    fours = 0;
    sixes = 0;
    dot_balls = 0;
    is_out = false;
}

float Player::get_strike_rate() const {
    if (balls_played == 0) return 0.0;
    return static_cast<float>(total_score) / balls_played * 100.0;
}

void Player::add_four() {
    fours++;
}

void Player::add_six() {
    sixes++;
}

void Player::add_dot_ball() {
    dot_balls++;
}
