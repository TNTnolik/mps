#include "window.h"
#include "ui.h"


int main(int argc, char **argv) {

    Gtk::Main kit(argc,argv);

    auto builder = Gtk::Builder::create_from_string(ui);

    window *win = nullptr;

    builder->get_widget_derived("Window", win);

    kit.run(*win);

    delete win;

    return 0;
}
