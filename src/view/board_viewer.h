#ifndef KAMISADO_BOARD_VIEWER_H
#define KAMISADO_BOARD_VIEWER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../model/match/board.h"
#include "../model/match/piece.h"

class BoardViewer {
private:
    const int WIDTH_ = 800;
    const int HEIGHT_ = 600;

    Board board_;
    SDL_Renderer* renderer_;
    std::vector<std::vector<SDL_Texture*>> pieces_images_;
    SDL_Texture* background_image_;
    SDL_Texture* board_image_;
public:
    BoardViewer(SDL_Renderer* renderer);
    void draw();
private:
    std::pair<int, int> get_screen_position_(int8_t x, int8_t y);
};

#endif //KAMISADO_BOARD_VIEWER_H
