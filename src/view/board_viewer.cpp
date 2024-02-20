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

    auto pieces = board.get_pieces();
    auto pieces_images = assetManager.get_pieces_images();

    for (int8_t player = 0; player < 2; ++player) {
        for (int8_t i = 0; i < 8; ++i) {
            pieceViewer_.draw(pieces[player][i], assetManager.get_renderer(), pieces_images[player][i], board_rectangle);
        }
    }

}