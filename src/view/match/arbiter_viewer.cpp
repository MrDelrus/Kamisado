#include "arbiter_viewer.h"

ArbiterViewer::ArbiterViewer(const Arbiter& arbiter, const AssetManager& assetManager, const BoardViewer& boardViewer,
                             const PieceViewer& pieceViewer, const SquareFiller& squareFiller,
                             SDL_Rect screen_rectangle) : arbiter_(arbiter), assetManager_(assetManager),
                             boardViewer_(boardViewer), pieceViewer_(pieceViewer), squareFiller_(squareFiller),
                             screen_rectangle_(screen_rectangle) {}

void ArbiterViewer::draw() const {

    SDL_Renderer* renderer = assetManager_.get_renderer();

    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, assetManager_.get_background_image(), nullptr, &screen_rectangle_);

    boardViewer_.draw();

    Position current_position = arbiter_.get_current_position();

    if (current_position.first >= 0 && current_position.first <= 7 && current_position.second >= 0 && current_position.second <= 7) {
        squareFiller_.draw(current_position, 0, 0, 0, 127);
    }

    const std::vector<Position>& available_squares = arbiter_.get_available_squares();

    for (auto position : available_squares) {
        squareFiller_.draw(position, 255, 255, 255, 100);
    }

    auto pieces = arbiter_.get_board().get_pieces();

    for (int8_t player = 0; player < 2; ++player) {
        for (int8_t i = 0; i < 8; ++i) {
            pieceViewer_.draw(pieces[player][i]);
        }
    }

    SDL_RenderPresent(renderer);

}