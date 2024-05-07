#include "piece_viewer.h"

PieceViewer::PieceViewer(const AssetManager& assetManager, SDL_Rect board_rectangle) : assetManager_(assetManager),
        board_rectangle_(board_rectangle) {}

void PieceViewer::draw(const Piece& piece) const {

    SDL_Rect piece_rectangle;

    piece_rectangle.x = board_rectangle_.x + piece.get_position().first * board_rectangle_.w / 8;
    piece_rectangle.y = board_rectangle_.y + (7 - piece.get_position().second) * board_rectangle_.h / 8;
    piece_rectangle.w = board_rectangle_.w / 8;
    piece_rectangle.h = board_rectangle_.h / 8;

    SDL_Texture* piece_image = assetManager_.get_pieces_images()[static_cast<int8_t>(piece.get_player())][static_cast<int8_t>(piece.get_color())];

    SDL_RenderCopy(assetManager_.get_renderer(), piece_image, nullptr, &piece_rectangle);

}
