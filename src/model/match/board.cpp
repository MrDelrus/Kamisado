#include <cstdlib>

#include "board.h"

Board::Board() : pieces_(2),
        fields_({{Color::Brown, Color::Green, Color::Red, Color::Yellow, Color::Pink, Color::Lightblue, Color::Darkblue, Color::Orange},
                {Color::Lightblue, Color::Brown, Color::Yellow, Color::Darkblue, Color::Green, Color::Pink, Color::Orange, Color::Red},
                {Color::Darkblue, Color::Yellow, Color::Brown, Color::Lightblue, Color::Red, Color::Orange, Color::Pink, Color::Green},
                {Color::Yellow, Color::Red, Color::Green, Color::Brown, Color::Orange, Color::Darkblue, Color::Lightblue, Color::Pink},
                {Color::Pink, Color::Lightblue, Color::Darkblue, Color::Orange, Color::Brown, Color::Green, Color::Red, Color::Yellow},
                {Color::Green, Color::Pink, Color::Orange, Color::Red, Color::Lightblue, Color::Brown, Color::Yellow, Color::Darkblue},
                {Color::Red, Color::Orange, Color::Pink, Color::Green, Color::Darkblue, Color::Yellow, Color::Brown, Color::Lightblue},
                {Color::Orange, Color::Darkblue, Color::Lightblue, Color::Pink, Color::Yellow, Color::Red, Color::Green, Color::Brown}}) {
    pieces_[0].reserve(8);
    pieces_[1].reserve(8);

    for (int8_t i = 0; i < 8; ++i) {
        auto color = static_cast<Color>(i);

        pieces_[static_cast<int8_t>(Player::First)].emplace_back(Position(i, 0), color, Player::First);
        blocked_squares_.emplace(i, 0);

        pieces_[static_cast<int8_t>(Player::Second)].emplace_back(Position(7 - i, 7), color, Player::Second);
        blocked_squares_.emplace(7 - i, 7);
    }

    fields_ = {};
}

Color Board::get_color(const Position& position) {
    return fields_[position.first][position.second];
}

std::vector<std::vector<Piece>>& Board::get_pieces() {
    return pieces_;
}

const std::vector<std::vector<Piece>>& Board::get_pieces() const {
    return pieces_;
}

std::set<Position>& Board::get_blocked_squares() {
    return blocked_squares_;
}

const std::set<Position>& Board::get_blocked_squares() const {
    return blocked_squares_;
}

