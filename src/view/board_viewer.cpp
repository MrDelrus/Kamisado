#include "board_viewer.h"

BoardViewer::BoardViewer(SDL_Renderer* renderer)
        : renderer_(renderer), pieces_images_(2, std::vector<SDL_Texture*>(8)),
          background_image_(IMG_LoadTexture(
                renderer, "/home/mrdelrus/Programming/MyProjects/Kamisado/assets/images/game-background.png")),
          board_image_(IMG_LoadTexture(
                renderer, "/home/mrdelrus/Programming/MyProjects/Kamisado/assets/images/board.png")) {
    pieces_images_[static_cast<int8_t>(Player::First)][static_cast<int8_t>(Color::Brown)] = IMG_LoadTexture(renderer_,
        "/home/mrdelrus/Programming/MyProjects/Kamisado/assets/images/pieces/player1/brown-1.png");
    pieces_images_[static_cast<int8_t>(Player::First)][static_cast<int8_t>(Color::Darkblue)] = IMG_LoadTexture(renderer_,
        "/home/mrdelrus/Programming/MyProjects/Kamisado/assets/images/pieces/player1/darkblue-1.png");
    pieces_images_[static_cast<int8_t>(Player::First)][static_cast<int8_t>(Color::Green)] = IMG_LoadTexture(renderer_,
        "/home/mrdelrus/Programming/MyProjects/Kamisado/assets/images/pieces/player1/green-1.png");
    pieces_images_[static_cast<int8_t>(Player::First)][static_cast<int8_t>(Color::Lightblue)] = IMG_LoadTexture(renderer_,
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
    pieces_images_[static_cast<int8_t>(Player::Second)][static_cast<int8_t>(Color::Darkblue)] = IMG_LoadTexture(renderer_,
        "/home/mrdelrus/Programming/MyProjects/Kamisado/assets/images/pieces/player2/darkblue-2.png");
    pieces_images_[static_cast<int8_t>(Player::Second)][static_cast<int8_t>(Color::Green)] = IMG_LoadTexture(renderer_,
        "/home/mrdelrus/Programming/MyProjects/Kamisado/assets/images/pieces/player2/green-2.png");
    pieces_images_[static_cast<int8_t>(Player::Second)][static_cast<int8_t>(Color::Lightblue)] = IMG_LoadTexture(renderer_,
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

void BoardViewer::draw() {

    SDL_Rect background_rectangle;
    background_rectangle.x = 0;
    background_rectangle.y = 0;
    background_rectangle.w = WIDTH_;
    background_rectangle.h = HEIGHT_;

    SDL_RenderCopy(renderer_, background_image_, NULL, &background_rectangle);

    SDL_Rect board_rectangle;
    board_rectangle.x = HEIGHT_ / 16;
    board_rectangle.y = WIDTH_ / 16;
    board_rectangle.w = HEIGHT_ - board_rectangle.y * 2;
    board_rectangle.h = board_rectangle.w;

    SDL_RenderCopy(renderer_, board_image_, NULL, &board_rectangle);

    auto pieces = board_.get();

    for (int8_t player = 0; player < 2; ++player) {

        for (int8_t i = 0; i < 8; ++i) {

            Position position = pieces[player][i].get_position();
            SDL_Rect piece_rectangle;

            piece_rectangle.x = board_rectangle.x + position.first * board_rectangle.w / 8;
            piece_rectangle.y = board_rectangle.y + (7 - position.second) * board_rectangle.h / 8;
            piece_rectangle.w = board_rectangle.w / 8;
            piece_rectangle.h = board_rectangle.h / 8;

            SDL_RenderCopy(renderer_, pieces_images_[player][i], NULL, &piece_rectangle);

        }

    }

}