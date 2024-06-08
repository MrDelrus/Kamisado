#include "project_runner_player.h"

ProjectRunnerPlayer::ProjectRunnerPlayer(SDL_Rect board_rectangle) : board_rectangle_(board_rectangle) {}

bool ProjectRunnerPlayer::is_movable_(Position from, Position to) {
    return true;
}

std::string ProjectRunnerPlayer::handle_mouse_click_(int x, int y) {
    if (board_rectangle_.x > x || board_rectangle_.x + board_rectangle_.w <= x ||
        board_rectangle_.y > y || board_rectangle_.y + board_rectangle_.h <= y) {
        return "";
    }

    Position position = {(x - board_rectangle_.x) / (board_rectangle_.w / 8), (board_rectangle_.y
                         + board_rectangle_.h - y) / (board_rectangle_.h / 8)};

    if (is_movable_(from_, position)) {
        std::string move(5, '-');
        move[0] = '0' + from_.first;
        move[1] = '0' + from_.second;
        move[3] = '0' + position.first;
        move[4] = '0' + position.second;
        return move;
    } else if (position.second == 0 && is_first_turn_) {
        from_ = position;
    }
    return "";
}


void ProjectRunnerPlayer::pass_position(std::string&& fen) {
    fen_ = std::move(fen);
    if (fen_.back() == '#') {
        is_first_turn_ = true;
    }
}

bool ProjectRunnerPlayer::is_move_made() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_MOUSEBUTTONDOWN) {
            int x = event.button.x;
            int y = event.button.y;
            std::string click_result = handle_mouse_click_(x, y);
            if (!click_result.empty()) {
                move_ = click_result;
                return true;
            }
        } else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE || event.type == SDL_QUIT) {
            move_ = "CONCEDE";
        }
    }
    return false;
}

std::string ProjectRunnerPlayer::get_move() {
    return move_;
}

void ProjectRunnerPlayer::pass_game_result(Result) {

}