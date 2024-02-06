#include "piece.h"

#include <utility>

Piece::Piece(Position position, Color color, Player player)
        : position_(std::move(position)), color_(color), player_(player) {}

Position Piece::get_position() {
    return position_;
}

void Piece::set_position(Position position) {
    position_ = std::move(position);
}

Color Piece::get_color() {
    return color_;
}

Player Piece::get_player() {
    return player_;
}