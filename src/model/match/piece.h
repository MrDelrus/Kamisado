#ifndef KAMISADO_PIECE_H
#define KAMISADO_PIECE_H

#include <cinttypes>
#include <vector>

using Position = std::pair<int, int>;

enum class Color : int8_t {
    Brown = 0,
    Green = 1,
    Red = 2,
    Yellow = 3,
    Pink = 4,
    Lightblue = 5,
    Darkblue = 6,
    Orange = 7
};

enum class Player : int8_t {
    First = 0,
    Second = 1
};

class Piece {
private:
    Position position_;
    Color color_;  // for view
    Player player_;  // for view

public:
    Piece(Position, Color, Player);

    Position get_position();
    void set_position(Position);

    Color get_color();
    Player get_player();

};

#endif //KAMISADO_PIECE_H
