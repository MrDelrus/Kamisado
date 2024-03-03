#ifndef KAMISADO_BOARD_CONTROLLER_H
#define KAMISADO_BOARD_CONTROLLER_H

#include "../../model/match/board.h"

class BoardController {
private:
    Board board_;
public:
    Board& get_board();
    const Board& get_board() const;

    bool is_movable(Color, Player);
    bool move(const Position&, Color, Player); // validate turn, then move piece; return result of validation
};
#endif //KAMISADO_BOARD_CONTROLLER_H
