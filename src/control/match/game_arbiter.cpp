#include "game_arbiter.h"
#include <iostream>
#include "../players/fen.cpp"
#include <cassert>

GameArbiter::GameArbiter(MatchPlayer& player1, MatchPlayer& player2, Board& board, bool& is_running) :
    player1_(player1), player2_(player2), board_(board), is_running_(is_running) {
    player1_.pass_position(get_fen(board_));
}

GameArbiter::Result GameArbiter::move_to_position_(Position from, Position to) {

    std::set<Position>& blocked_squares = board_.get_blocked_squares();

    Piece& piece = board_.get_pieces()[static_cast<int8_t>(current_player_)][static_cast<int8_t>(
            current_color_)];

    blocked_squares.erase(piece.get_position());
    piece.set_position(to);
    blocked_squares.insert(to);

    if (current_player_ == Player::First && to.second == 7 || current_player_ == Player::Second && to.second == 0) {
        return Result::Victory;
    }

    std::vector<std::vector<bool>> used(2, std::vector<bool>(8, false));

    current_color_ = board_.get_color(to);

    auto is_movable = [](const Board& board, Color color, Player player) {
        const std::vector<std::vector<Piece>>& pieces = board.get_pieces();
        const std::set<Position>& blocked_squares = board.get_blocked_squares();

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
    };

    Player player = current_player_;

    while (!is_movable(board_, current_color_, current_player_)) {

        if (used[static_cast<int8_t>(player)][static_cast<int8_t>(current_color_)]) {
            return Result::Defeat;
        }
        used[static_cast<int8_t>(player)][static_cast<int8_t>(current_color_)] = true;

        current_color_ = board_.get_color(board_.get_pieces()[static_cast<int8_t>(player)][static_cast<int8_t>(
                current_color_)].get_position());

        if (player == Player::First) {
            player = Player::Second;
        } else {
            player = Player::First;
        }

    }

    current_player_ = player;

    return Result::Success;
}

bool GameArbiter::validate_(Position from, Position to) {
    std::vector<std::vector<Piece>>& pieces = board_.get_pieces();
    std::set<Position>& blocked_squares = board_.get_blocked_squares();

    if (!is_first_move_ && board_.get_pieces()[static_cast<int8_t>(current_player_)][
            static_cast<int8_t>(current_color_)].get_position() != from || is_first_move_ && from.second != 0) {
        return false;
    }
    if (is_first_move_) {
        current_color_ = board_.get_color(from);
    }

    Piece& piece = pieces[static_cast<int8_t>(current_player_)][static_cast<int8_t>(current_color_)];

    Position current = from;
    if (to.second == current.second || to.second < current.second && current_player_ == Player::First || to.second >
            current.second && current_player_ == Player::Second || std::abs(to.first - current.first) != 0 &&
            std::abs(to.first - current.first) != std::abs(to.second - current.second)) {
        return false;
    }

    int dx = (to.first - current.first > 0) ? 1 : (to.first == current.first) ? 0 : -1;
    int dy = (to.second - current.second > 0) ? 1 : -1;

    while (current.first += dx, current.second += dy, current != to) {
        if (blocked_squares.count(current) != 0) {
            return false;
        }
    }

    return true;

}

void GameArbiter::handle_move_result_(Result result) {
    if (result != Result::Success) {
        is_running_ = false;
        player1_.get_game_result(result);
    }
}

void GameArbiter::update() {
    MatchPlayer* current = &player1_;
    MatchPlayer* opponent = &player2_;
    if (current_player_ == Player::Second) {
        std::swap(current, opponent);
    }
    if (current->is_move_made()) {
        std::string move_fen = current->get_move();
        assert(move_fen.size() == 5);
        assert(move_fen[2] == '-');
        Position from = {move_fen[0] - 'a', move_fen[1] - '0'};
        Position to = {move_fen[3] - 'a', move_fen[4] - '0'};
        if (validate_(from, to)) {
            if (!is_first_move_) {
                is_first_move_ = false;
            }
            auto result = move_to_position_(from, to);
            if (result != Result::Success) {
                is_running_ = false;
                if (result == Result::Victory) {
                    current->get_game_result(Result::Victory);
                    opponent->get_game_result(Result::Defeat);
                } else {
                    current->get_game_result(Result::Defeat);
                    opponent->get_game_result(Result::Victory);
                }
            }
            if (is_running_) {
                opponent->pass_position(get_fen(board_));
            }
        }
    }
}