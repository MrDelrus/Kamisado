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
    virtual void set_position(std::string&&) = 0;
    virtual bool is_move_made() = 0;
    virtual std::string get_move() = 0;
    virtual void set_game_result(Result) = 0;

    virtual ~MatchPlayer() = default;
};

#endif //KAMISADO_MATCH_PLAYER_H
