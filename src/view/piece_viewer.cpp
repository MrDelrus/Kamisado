#include "piece_viewer.h"

void PieceViewer::draw(const Piece& piece, SDL_Renderer* renderer, SDL_Texture* piece_image, const SDL_Rect& board_rectangle) const {

    SDL_Rect piece_rectangle;

    piece_rectangle.x = board_rectangle.x + piece.get_position().first * board_rectangle.w / 8;
    piece_rectangle.y = board_rectangle.y + (7 - piece.get_position().second) * board_rectangle.h / 8;
    piece_rectangle.w = board_rectangle.w / 8;
    piece_rectangle.h = board_rectangle.h / 8;

    SDL_RenderCopy(renderer, piece_image, nullptr, &piece_rectangle);

}
