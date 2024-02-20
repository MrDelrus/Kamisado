#include "board_viewer.h"

void BoardViewer::draw(const Board& board, const AssetManager& assetManager, int width, int height) const {

    SDL_Rect background_rectangle;
    background_rectangle.x = 0;
    background_rectangle.y = 0;
    background_rectangle.w = width;
    background_rectangle.h = height;

    SDL_RenderCopy(assetManager.get_renderer(), assetManager.get_background_image(), NULL, &background_rectangle);

    SDL_Rect board_rectangle;
    board_rectangle.x = height / 16;
    board_rectangle.y = width / 16;
    board_rectangle.w = height - board_rectangle.y * 2;
    board_rectangle.h = board_rectangle.w;

    SDL_RenderCopy(assetManager.get_renderer(), assetManager.get_board_image(), NULL, &board_rectangle);

}