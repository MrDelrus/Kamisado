#include "piece_viewer.h"

PieceViewer::PieceViewer(const AssetManager& assetManager) : assetManager_(assetManager) {}

void PieceViewer::draw(const Piece& piece, const SDL_Rect& board_rectangle) const {

    SDL_Rect piece_rectangle;

    piece_rectangle.x = board_rectangle.x + piece.get_position().first * board_rectangle.w / 8;
    piece_rectangle.y = board_rectangle.y + (7 - piece.get_position().second) * board_rectangle.h / 8;
    piece_rectangle.w = board_rectangle.w / 8;
    piece_rectangle.h = board_rectangle.h / 8;

    SDL_Texture* piece_image = assetManager_.get_pieces_images()[static_cast<int8_t>(piece.get_player())][static_cast<int8_t>(piece.get_color())];

    SDL_RenderCopy(assetManager_.get_renderer(), piece_image, nullptr, &piece_rectangle);

}
