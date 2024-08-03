#include "BoardClickEventHandler.h"

Position BoardClickEventHandler::handle(SceneryEvent event) {
    int x = event.x_click;
    int y = event.y_click;

    if (board_rectangle_.x > x || board_rectangle_.x + board_rectangle_.w <= x ||
        board_rectangle_.y > y || board_rectangle_.y + board_rectangle_.h <= y) {
        return {-1, -1};
    }


    Position position = {(x - board_rectangle_.x) / (board_rectangle_.w / 8), (board_rectangle_.y
        + board_rectangle_.h - y) / (board_rectangle_.h / 8)};

    return position;
}
