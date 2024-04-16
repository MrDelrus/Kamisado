#include "arbiter_viewer.h"

ArbiterViewer::ArbiterViewer(const Board& board, const AssetManager& assetManager, const BoardViewer& boardViewer,
                             const PieceViewer& pieceViewer, const SquareFiller& squareFiller,
                             const SDL_Rect& screen_rectangle) : board_(board), assetManager_(assetManager),
                             boardViewer_(boardViewer), pieceViewer_(pieceViewer), squareFiller_(squareFiller),
                             screen_rectangle_(screen_rectangle) {}

void ArbiterViewer::draw(const std::vector<Position>& available_squares, Position last_move_to, Position last_move_from) const {

    SDL_Renderer* renderer = assetManager_.get_renderer();

    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, assetManager_.get_background_image(), nullptr, &screen_rectangle_);

    boardViewer_.draw();

    /*
    if (last_move_to.first >= 0 && last_move_to.first <= 7 && last_move_to.second >= 0 && last_move_to.second <= 7) {
        squareFiller_.draw(last_move_to, 255, 255, 0, 127);
    }

    if (last_move_from.first >= 0 && last_move_from.first <= 7 && last_move_from.second >= 0 && last_move_from.second <= 7) {
        squareFiller_.draw(last_move_from, 255, 255, 0, 127);
    } */

    for (auto position : available_squares) {
        squareFiller_.draw(position, 255, 255, 255, 100);
    }

    auto pieces = board_.get_pieces();

    for (int8_t player = 0; player < 2; ++player) {
        for (int8_t i = 0; i < 8; ++i) {
            pieceViewer_.draw(pieces[player][i]);
        }
    }

    SDL_RenderPresent(renderer);

}