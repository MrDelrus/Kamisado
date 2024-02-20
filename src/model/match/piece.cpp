#include "piece.h"

#include <utility>

Piece::Piece(Position position, Color color, Player player)
        : position_(std::move(position)), color_(color), player_(player) {}

void Piece::set_position(Position position) {
    position_ = std::move(position);
}

Position Piece::get_position() const {
    return position_;
}

Color Piece::get_color() const {
    return color_;
}

Player Piece::get_player() const {
    return player_;
}