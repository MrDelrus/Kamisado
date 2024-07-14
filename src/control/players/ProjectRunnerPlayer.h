#ifndef KAMISADO_PROJECTRUNNERPLAYER_H
#define KAMISADO_PROJECTRUNNERPLAYER_H

#include "MatchPlayer.h"
#include <SDL.h>

class ProjectRunnerPlayer : public MatchPlayer {
private:
    SDL_Rect board_rectangle_;
    std::string fen_;
    std::string move_;
    Position from_;
    Player player;
    bool is_turn_finished_ = false;
    bool is_first_turn_ = false;
private:
    bool is_movable_(Position from, Position to);
    std::string handle_mouse_click_(int x, int y);
public:
    ProjectRunnerPlayer(SDL_Rect board_rectangle);
    virtual void set_position(std::string&&) override;
    virtual bool is_move_made() override;
    virtual std::string get_move() override;
    virtual void set_game_result(Result) override;
    ~ProjectRunnerPlayer() override = default;
};

#endif //KAMISADO_PROJECTRUNNERPLAYER_H
