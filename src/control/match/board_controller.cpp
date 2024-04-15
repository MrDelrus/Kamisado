#include "board_controller.h"
#include <valarray>

BoardController::BoardController(Board& board) : board_(board) {}

Board& BoardController::get_board() {
    return board_;
}

const Board& BoardController::get_board() const {
    return board_;
}

bool BoardController::is_movable(Color color, Player player) const {
    const std::vector<std::vector<Piece>>& pieces = board_.get_pieces();
    const std::set<Position>& blocked_squares = board_.get_blocked_squares();

    Position current = pieces[static_cast<int8_t>(player)][static_cast<int8_t>(color)].get_position();

    bool movable = false;

    for (int dx = -1; dx <= 1; ++dx) {
        int x = current.first + dx;
        int y = current.second + (player == Player::First ? 1 : -1);
        if (x >= 0 && x <= 7 && y >= 0 && y <= 7 && blocked_squares.count({x, y}) == 0) {
            movable = true;
            break;
        }
    }

    return movable;
}

std::vector<Position> BoardController::get_available_squares(Color color, Player player) const {

    std::vector<Position> available_squares;

    const std::vector<std::vector<Piece>>& pieces = board_.get_pieces();
    const std::set<Position>& blocked_squares = board_.get_blocked_squares();

    Position current = pieces[static_cast<int8_t>(player)][static_cast<int8_t>(color)].get_position();

    int dy = (player == Player::First ? 1 : -1);

    for (int dx = -1; dx <= 1; ++dx) {
        int x = current.first + dx;
        int y = current.second + dy;
        while (x >= 0 && x <= 7 && y >= 0 && y <= 7 && blocked_squares.count({x, y}) == 0) {
            available_squares.emplace_back(x, y);
            x += dx;
            y += dy;
        }
    }

    return available_squares;

}

bool BoardController::move(const Position& to, Color color, Player player) {
    std::vector<std::vector<Piece>>& pieces = board_.get_pieces();
    std::set<Position>& blocked_squares = board_.get_blocked_squares();

    if (blocked_squares.count(to) != 0) {
        return false;
    }

    Piece& piece = pieces[static_cast<int8_t>(player)][static_cast<int8_t>(color)];
    Position current = piece.get_position();

    if (to.second == current.second || to.second < current.second && player == Player::First || to.second > current.second
        && player == Player::Second || std::abs(to.first - current.first) != 0 && std::abs(to.first - current.first) != std::abs(to.second - current.second)) {
        return false;
    }

    int dx = (to.first - current.first > 0) ? 1 : (to.first == current.first) ? 0 : -1;
    int dy = (to.second - current.second > 0) ? 1 : -1;

    while (current.first += dx, current.second += dy, current != to) {
        if (blocked_squares.count(current) != 0) {
            return false;
        }
    }

    blocked_squares.erase(piece.get_position());
    piece.set_position(to);
    blocked_squares.insert(to);

    return true;

}