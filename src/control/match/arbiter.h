#ifndef KAMISADO_ARBITER_H
#define KAMISADO_ARBITER_H

#include "../../model/match/board.h"

class Arbiter {
private:
    Board board_;
    Color current_color_;
    Player current_player_ = Player::First;
    enum class Step {
        Waiting,
        Preparing,
        Playing
    };
    Step step_ = Step::Waiting;
public:
    enum class Result {
        Failed,
        First_wins,
        Second_wins,
        First_turn,
        Second_turn
    };

    void choose(const Position&);
    Result move(const Position&);

};

#endif //KAMISADO_ARBITER_H
