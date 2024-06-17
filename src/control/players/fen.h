#ifndef KAMISADO_FEN_H
#define KAMISADO_FEN_H

#include "../../model/match/board.h"

std::string get_fen(const Board&, Position = {-1, -1});

#endif //KAMISADO_FEN_H
