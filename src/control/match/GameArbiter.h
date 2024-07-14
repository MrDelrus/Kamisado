#ifndef KAMISADO_GAMEARBITER_H
#define KAMISADO_GAMEARBITER_H

#include "Arbiter.h"
#include "../players/MatchPlayer.h"
#include "../../view/match/ArbiterViewer.h"

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
private:
    Result move_to_position_(Position, Position);
    bool validate_(Position, Position);
public:
    GameArbiter(MatchPlayer&, MatchPlayer&, Board&);
    std::string update();
};

#endif //KAMISADO_GAMEARBITER_H
