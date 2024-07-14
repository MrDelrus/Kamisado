#ifndef KAMISADO_BOARDVIEWER_H
#define KAMISADO_BOARDVIEWER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "AssetManager.h"

class BoardViewer {
private:
    const AssetManager& assetManager_;
    const SDL_Rect board_rectangle_;
public:
    BoardViewer(const AssetManager&, SDL_Rect board_rectangle);
    void draw() const;
};

#endif //KAMISADO_BOARDVIEWER_H
