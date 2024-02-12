#ifndef KAMISADO_BOARD_VIEWER_H
#define KAMISADO_BOARD_VIEWER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../model/match/board.h"
#include "asset_manager.h"

class BoardViewer {
public:
    void draw(const Board&, const AssetManager&, int width, int height) const;
};

#endif //KAMISADO_BOARD_VIEWER_H
