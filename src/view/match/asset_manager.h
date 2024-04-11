#ifndef KAMISADO_ASSET_MANAGER_H
#define KAMISADO_ASSET_MANAGER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../../model/match/piece.h"

#include <vector>

class AssetManager {
private:
    SDL_Renderer* renderer_;
    std::vector<std::vector<SDL_Texture*>> pieces_images_;
    SDL_Texture* background_image_;
    SDL_Texture* board_image_;
public:
    AssetManager(SDL_Renderer*);
    SDL_Renderer* get_renderer() const;
    const std::vector<std::vector<SDL_Texture*>>& get_pieces_images() const;
    SDL_Texture* get_background_image() const;
    SDL_Texture* get_board_image() const;
};

#endif //KAMISADO_ASSET_MANAGER_H
