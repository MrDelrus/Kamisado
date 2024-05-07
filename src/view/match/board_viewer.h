#ifndef KAMISADO_BOARD_VIEWER_H
#define KAMISADO_BOARD_VIEWER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "asset_manager.h"

class BoardViewer {
private:
    const AssetManager& assetManager_;
    const SDL_Rect board_rectangle_;
public:
    BoardViewer(const AssetManager&, SDL_Rect board_rectangle);
    void draw() const;
};

#endif //KAMISADO_BOARD_VIEWER_H
