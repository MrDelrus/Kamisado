#include "arbiter_viewer.h"

ArbiterViewer::ArbiterViewer(const Board& board, const AssetManager& assetManager, const BoardViewer& boardViewer,
                             const PieceViewer& pieceViewer, const SDL_Rect& screen_rectangle)
                             : board_(board), assetManager_(assetManager), boardViewer_(boardViewer),
                             pieceViewer_(pieceViewer), screen_rectangle_(screen_rectangle) {}

void ArbiterViewer::draw() const {

    SDL_RenderClear(assetManager_.get_renderer());

    SDL_RenderCopy(assetManager_.get_renderer(), assetManager_.get_background_image(), nullptr, &screen_rectangle_);

    boardViewer_.draw();

    auto pieces = board_.get_pieces();

    for (int8_t player = 0; player < 2; ++player) {
        for (int8_t i = 0; i < 8; ++i) {
            pieceViewer_.draw(pieces[player][i]);
        }
    }

    SDL_RenderPresent(assetManager_.get_renderer());
}
