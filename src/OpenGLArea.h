#ifndef MPS_OPENGLAREA_H
#define MPS_OPENGLAREA_H

#include <gtkmm/glarea.h>
#include <epoxy/gl.h>


class OpenGLArea : public Gtk::GLArea{
public:
    OpenGLArea();
    virtual ~OpenGLArea();

protected:

};


#endif //MPS_OPENGLAREA_H
