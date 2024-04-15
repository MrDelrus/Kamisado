#include "arbiter.h"

Arbiter::Arbiter(BoardController& boardController) : boardController_(boardController) {}

Arbiter::Step Arbiter::get_step() {
    return step_;
}

void Arbiter::choose(const Position& from) {
    if (step_ != Step::Playing && from.second == 0) {
        current_color_ = boardController_.get_board().get_color(from);
        step_ = Step::Preparing;
    }
}

Arbiter::Result Arbiter::move(const Position& to) {
    if (step_ == Step::Waiting || !boardController_.move(to, current_color_, current_player_)) {
        return Result::Failed;
    }

    if (step_ == Step::Preparing) {
        step_ = Step::Playing;
    }

    if (to.second == 7) {
        return Result::First_wins;
    }
    if (to.second == 0) {
        return Result::Second_wins;
    }

    Player player = current_player_;

    std::vector<std::vector<bool>> used(2, std::vector<bool>(8, false));

    if (current_player_ == Player::First) {
        current_player_ = Player::Second;
    } else {
        current_player_ = Player::First;
    }

    current_color_ = boardController_.get_board().get_color(to);

    while (!boardController_.is_movable(current_color_, current_player_)) {
        if (used[static_cast<int8_t>(current_player_)][static_cast<int8_t>(current_color_)]) {
            if (player == Player::First) {
                return Result::Second_wins;
            } else {
                return Result::First_wins;
            }
        }
        used[static_cast<int8_t>(current_player_)][static_cast<int8_t>(current_color_)] = true;

        Board& board = boardController_.get_board();
        current_color_ = board.get_color(board.get_pieces()[static_cast<int8_t>(current_player_)][static_cast<int8_t>(current_color_)].get_position());

        if (current_player_ == Player::First) {
            current_player_ = Player::Second;
        } else {
            current_player_ = Player::First;
        }

    }

    if (current_player_ == Player::First) {
        return Result::First_turn;
    } else {
        return Result::Second_turn;
    }

}

std::vector<Position> Arbiter::get_available_squares() const {

    return boardController_.get_available_squares(current_color_, current_player_);

}

Position Arbiter::get_current_position() const {
    if (step_ == Step::Waiting) {
        return {-1, -1};
    }
    return boardController_.get_board().get_pieces()[static_cast<int8_t>(current_player_)][static_cast<int8_t>(current_color_)].get_position();
}