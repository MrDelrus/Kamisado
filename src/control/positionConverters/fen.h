#ifndef KAMISADO_FEN_H
#define KAMISADO_FEN_H

#include "../../model/match/Board.h"

struct positionInformation {
    Position pieces[16];
    int current_piece = -1;
};

positionInformation get_fen(const Board&, Position = {-1, -1});

#endif //KAMISADO_FEN_H
