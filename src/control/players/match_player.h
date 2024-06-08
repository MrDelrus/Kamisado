#ifndef KAMISADO_MATCH_PLAYER_H
#define KAMISADO_MATCH_PLAYER_H

#include <string>
#include "../../model/match/piece.h"

class MatchPlayer {
public:
    enum class Result {
        Success,
        Victory,
        Defeat
    };
    virtual void pass_position(std::string&&) = 0;
    virtual bool is_move_made() = 0;
    virtual std::string get_move() = 0;
    virtual void pass_game_result(Result);

    virtual ~MatchPlayer() = default;
};

#endif //KAMISADO_MATCH_PLAYER_H
