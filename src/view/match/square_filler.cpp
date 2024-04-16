#include "square_filler.h"

SquareFiller::SquareFiller(SDL_Renderer* renderer, const SDL_Rect& board_rectangle) : renderer_(renderer),
        board_rectangle_(board_rectangle) {}

void SquareFiller::draw(Position position, int red, int green, int blue, int alpha) const {

    SDL_SetRenderDrawColor(renderer_, red, green, blue, alpha);

    SDL_Rect rect;

    rect.x = board_rectangle_.x + position.first * board_rectangle_.w / 8;
    rect.y = board_rectangle_.y + (7 - position.second) * board_rectangle_.h / 8;
    rect.w = board_rectangle_.w / 8;
    rect.h = board_rectangle_.h / 8;

    SDL_RenderFillRect(renderer_, &rect);

}