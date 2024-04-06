#include "board_viewer.h"

BoardViewer::BoardViewer(int width, int height, const Board& board, const AssetManager& assetManager, const PieceViewer& pieceViewer) :
        width_(width), height_(height), board_(board), assetManager_(assetManager), pieceViewer_(pieceViewer) {}

void BoardViewer::draw() const {

    SDL_Rect background_rectangle;
    background_rectangle.x = 0;
    background_rectangle.y = 0;
    background_rectangle.w = width_;
    background_rectangle.h = height_;

    SDL_RenderCopy(assetManager_.get_renderer(), assetManager_.get_background_image(), nullptr, &background_rectangle);

    SDL_Rect board_rectangle;
    board_rectangle.x = width_ / 16;
    board_rectangle.y = height_ / 16;
    board_rectangle.w = height_ - board_rectangle.y * 2;
    board_rectangle.h = board_rectangle.w;

    SDL_RenderCopy(assetManager_.get_renderer(), assetManager_.get_board_image(), nullptr, &board_rectangle);

    auto pieces = board_.get_pieces();

    for (int8_t player = 0; player < 2; ++player) {
        for (int8_t i = 0; i < 8; ++i) {
            pieceViewer_.draw(pieces[player][i], board_rectangle);
        }
    }

}