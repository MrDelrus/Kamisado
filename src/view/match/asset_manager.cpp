#include "asset_manager.h"

AssetManager::AssetManager(SDL_Renderer* renderer)
        : renderer_(renderer), pieces_images_(2, std::vector<SDL_Texture*>(8)),
            background_image_(IMG_LoadTexture(
                renderer, "/home/mrdelrus/Programming/MyProjects/Kamisado/assets/images/game-background.png")),
            board_image_(IMG_LoadTexture(
                renderer, "/home/mrdelrus/Programming/MyProjects/Kamisado/assets/images/board.png")) {
    pieces_images_[static_cast<int8_t>(Player::First)][static_cast<int8_t>(Color::Brown)] = IMG_LoadTexture(renderer_,
                                                                                                            "/home/mrdelrus/Programming/MyProjects/Kamisado/assets/images/pieces/player1/brown-1.png");
    pieces_images_[static_cast<int8_t>(Player::First)][static_cast<int8_t>(Color::Darkblue)] = IMG_LoadTexture(
            renderer_,
            "/home/mrdelrus/Programming/MyProjects/Kamisado/assets/images/pieces/player1/darkblue-1.png");
    pieces_images_[static_cast<int8_t>(Player::First)][static_cast<int8_t>(Color::Green)] = IMG_LoadTexture(renderer_,
                                                                                                            "/home/mrdelrus/Programming/MyProjects/Kamisado/assets/images/pieces/player1/green-1.png");
    pieces_images_[static_cast<int8_t>(Player::First)][static_cast<int8_t>(Color::Lightblue)] = IMG_LoadTexture(
            renderer_,
            "/home/mrdelrus/Programming/MyProjects/Kamisado/assets/images/pieces/player1/lightblue-1.png");
    pieces_images_[static_cast<int8_t>(Player::First)][static_cast<int8_t>(Color::Orange)] = IMG_LoadTexture(renderer_,
                                                                                                             "/home/mrdelrus/Programming/MyProjects/Kamisado/assets/images/pieces/player1/orange-1.png");
    pieces_images_[static_cast<int8_t>(Player::First)][static_cast<int8_t>(Color::Pink)] = IMG_LoadTexture(renderer_,
                                                                                                           "/home/mrdelrus/Programming/MyProjects/Kamisado/assets/images/pieces/player1/pink-1.png");
    pieces_images_[static_cast<int8_t>(Player::First)][static_cast<int8_t>(Color::Red)] = IMG_LoadTexture(renderer_,
                                                                                                          "/home/mrdelrus/Programming/MyProjects/Kamisado/assets/images/pieces/player1/red-1.png");
    pieces_images_[static_cast<int8_t>(Player::First)][static_cast<int8_t>(Color::Yellow)] = IMG_LoadTexture(renderer_,
                                                                                                             "/home/mrdelrus/Programming/MyProjects/Kamisado/assets/images/pieces/player1/yellow-1.png");

    pieces_images_[static_cast<int8_t>(Player::Second)][static_cast<int8_t>(Color::Brown)] = IMG_LoadTexture(renderer_,
                                                                                                             "/home/mrdelrus/Programming/MyProjects/Kamisado/assets/images/pieces/player2/brown-2.png");
    pieces_images_[static_cast<int8_t>(Player::Second)][static_cast<int8_t>(Color::Darkblue)] = IMG_LoadTexture(
            renderer_,
            "/home/mrdelrus/Programming/MyProjects/Kamisado/assets/images/pieces/player2/darkblue-2.png");
    pieces_images_[static_cast<int8_t>(Player::Second)][static_cast<int8_t>(Color::Green)] = IMG_LoadTexture(renderer_,
                                                                                                             "/home/mrdelrus/Programming/MyProjects/Kamisado/assets/images/pieces/player2/green-2.png");
    pieces_images_[static_cast<int8_t>(Player::Second)][static_cast<int8_t>(Color::Lightblue)] = IMG_LoadTexture(
            renderer_,
            "/home/mrdelrus/Programming/MyProjects/Kamisado/assets/images/pieces/player2/lightblue-2.png");
    pieces_images_[static_cast<int8_t>(Player::Second)][static_cast<int8_t>(Color::Orange)] = IMG_LoadTexture(renderer_,
                                                                                                              "/home/mrdelrus/Programming/MyProjects/Kamisado/assets/images/pieces/player2/orange-2.png");
    pieces_images_[static_cast<int8_t>(Player::Second)][static_cast<int8_t>(Color::Pink)] = IMG_LoadTexture(renderer_,
                                                                                                            "/home/mrdelrus/Programming/MyProjects/Kamisado/assets/images/pieces/player2/pink-2.png");
    pieces_images_[static_cast<int8_t>(Player::Second)][static_cast<int8_t>(Color::Red)] = IMG_LoadTexture(renderer_,
                                                                                                           "/home/mrdelrus/Programming/MyProjects/Kamisado/assets/images/pieces/player2/red-2.png");
    pieces_images_[static_cast<int8_t>(Player::Second)][static_cast<int8_t>(Color::Yellow)] = IMG_LoadTexture(renderer_,
                                                                                                              "/home/mrdelrus/Programming/MyProjects/Kamisado/assets/images/pieces/player2/yellow-2.png");
}

SDL_Renderer* AssetManager::get_renderer() const {
    return renderer_;
}

const std::vector<std::vector<SDL_Texture*>>& AssetManager::get_pieces_images() const {
    return pieces_images_;
}

SDL_Texture* AssetManager::get_background_image() const {
    return background_image_;
}

SDL_Texture* AssetManager::get_board_image() const {
    return board_image_;
}
