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

bool Board::move(const Position& to, Color color, Player player) {
    Piece& piece = pieces_[static_cast<int8_t>(player)][static_cast<int8_t>(color)];
    Position current = piece.get_position();

    if (to.second == current.second or to.second < current.second and player == Player::First or
        to.second > current.second and player == Player::Second or
        std::abs(to.first - current.first) != std::abs(to.second - current.second)) {
        return false;
    }

    int dx = (to.first - current.first > 0) ? 1 : (to.first == current.first) ? 0 : -1;
    int dy = (to.second - current.first > 0) ? 1 : -1;

    while (current.first += dx, current.second += dy, current != to) {
        if (blocked_squares_.count(current) != 0) {
            return false;
        }
    }

    blocked_squares_.erase(piece.get_position());
    piece.set_position(to);
    blocked_squares_.insert(to);

    return true;

}

Color Board::get_color(const Position& position) {
    return fields_[position.first][position.second];
}

const std::vector<std::vector<Piece>>& Board::get() {
    return pieces_;
}
