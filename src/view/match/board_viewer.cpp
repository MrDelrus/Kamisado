#include "board_viewer.h"

BoardViewer::BoardViewer(const AssetManager& assetManager, const SDL_Rect& board_rectangle)
                         : assetManager_(assetManager), board_rectangle_(board_rectangle) {}

void BoardViewer::draw() const {

    SDL_RenderCopy(assetManager_.get_renderer(), assetManager_.get_board_image(), nullptr, &board_rectangle_);

}