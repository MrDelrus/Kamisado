#ifndef KAMISADO_ARBITER_H
#define KAMISADO_ARBITER_H

#include "board_controller.h"

class Arbiter {
private:
    BoardController& boardController_;
    Color current_color_;
    Player current_player_ = Player::First;
    enum class Step {
        Waiting,
        Preparing,
        Playing
    };
    Step step_ = Step::Waiting;
public:
    explicit Arbiter(BoardController&);

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
