#ifndef KAMISADO_GAME_ARBITER_H
#define KAMISADO_GAME_ARBITER_H

#include "arbiter.h"
#include "../players/match_player.h"
#include "../../view/match/arbiter_viewer.h"

class GameArbiter {
private:
    using Result = MatchPlayer::Result;
private:
    MatchPlayer& player1_;
    MatchPlayer& player2_;
    Board& board_;
    Color current_color_;
    Player current_player_ = Player::First;
    bool is_first_move_ = true;
    bool& is_running_;
private:
    Result move_to_position_(Position, Position);
    bool validate_(Position, Position);
    void handle_move_result_(Result);
public:
    GameArbiter(MatchPlayer&, MatchPlayer&, Board&, bool&);
    void update();
};

#endif //KAMISADO_GAME_ARBITER_H
