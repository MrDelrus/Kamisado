#ifndef KAMISADO_BOARD_H
#define KAMISADO_BOARD_H

#include <vector>
#include <set>

#include "piece.h"

class Board {
private:
    std::vector<std::vector<Piece>> pieces_;
    std::set<Position> blocked_squares_;
    std::vector<std::vector<Color>> fields_;
public:
    Board();

    bool move(const Position&, Color, Player); // validate turn, then move piece; return result of validation

    Color get_color(const Position&);

    const std::vector<std::vector<Piece>>& get();

};

#endif //KAMISADO_BOARD_H