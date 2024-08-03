#include "fen.h"

positionInformation get_fen(const Board& board, Position from) {
    /*
     Returns string with length 67. First 64 letters represent the board ('.' if cell is empty, 'x' if black piece is
     here and 'X' if white piece is here). 65th symbol is '#' and last 2 represent the current piece, or '#'
     */
    auto pieces = board.get_pieces();
    auto char_from_piece = [] (const Piece&) {
        return 'x';
    };
    std::string fen(67, '.');
    for (int i = 0; i < 2; ++i) {
        for (auto piece : pieces[i]) {
            Position position = piece.get_position();
            fen[8 * position.first + position.second] = char_from_piece(piece);
        }
    }
    fen[64] = '#';
    if (from.first >= 0 && from.first <= 7 && from.second >= 0 && from.second <= 7) {
        fen[65] = from.first + '0';
        fen[66] = from.second + '0';
    }
    return fen;
}

