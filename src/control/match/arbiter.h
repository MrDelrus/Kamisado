#ifndef KAMISADO_ARBITER_H
#define KAMISADO_ARBITER_H

#include "board_controller.h"

class Arbiter {
public:
    enum class Step {
        Waiting,
        Preparing,
        Playing
    };
private:
    BoardController& boardController_;
    Color current_color_;
    Player current_player_ = Player::First;
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

    Step get_step();
    void choose(const Position&);
    Result move(const Position&);

    std::vector<Position> get_available_squares() const;
    Position get_current_position() const;

};

#endif //KAMISADO_ARBITER_H
