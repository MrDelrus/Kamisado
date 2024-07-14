#include "ArbiterViewer.h"

ArbiterViewer::ArbiterViewer(const Board& board, const AssetManager& assetManager, const BoardViewer& boardViewer,
                             const PieceViewer& pieceViewer, const SquareFiller& squareFiller,
                             SDL_Rect screen_rectangle) : board_(board), assetManager_(assetManager),
                             boardViewer_(boardViewer), pieceViewer_(pieceViewer), squareFiller_(squareFiller),
                             screen_rectangle_(screen_rectangle) {}

void ArbiterViewer::draw() const {

    SDL_Renderer* renderer = assetManager_.get_renderer();

    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, assetManager_.get_background_image(), nullptr, &screen_rectangle_);

    boardViewer_.draw();

    auto pieces = board_.get_pieces();

    for (int8_t player = 0; player < 2; ++player) {
        for (int8_t i = 0; i < 8; ++i) {
            pieceViewer_.draw(pieces[player][i]);
        }
    }

    SDL_RenderPresent(renderer);

}