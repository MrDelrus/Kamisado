#include "click_controller.h"

ClickController::ClickController(int width, int height) : width_(width), height_(height) {}

Position ClickController::get_position(int x_click, int y_click) {

    int x = width_ / 16;
    int y = height_ / 16;
    int w = height_ - y * 2;
    int h = w;

    int x_cell = (x_click - x) / (w / 8);
    int y_cell = (y + h - y_click) / (h / 8);

    return {x_cell, y_cell};
}
