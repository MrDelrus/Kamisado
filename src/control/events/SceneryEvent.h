#ifndef KAMISADO_SCENERYEVENT_H
#define KAMISADO_SCENERYEVENT_H

struct SceneryEvent {
    int x_click;
    int y_click;
    enum class Key {
        Escape,
        Enter
    };
    Key key;
    bool is_click;
};

#endif //KAMISADO_SCENERYEVENT_H
