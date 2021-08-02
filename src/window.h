#ifndef MPS_WINDOW_H
#define MPS_WINDOW_H


#include <iostream>
#include <math.h>
#include <gtkmm.h>
#include "OpenGLArea.h"

class window : public Gtk::Window {
public:
    window(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder);
    virtual ~window() = default;

protected:


    void hSh_change(int id, const Glib::RefPtr<Gtk::Adjustment>& adj);
    void alf_change(int alf_id, int alf_count, const Glib::RefPtr<Gtk::Adjustment>& adj);
    void L_dis();
    void change_anglRas();
    void RashetPloshadiSech(long int n, float **Prostr);
    void change_xyz();
    void change_R();
    void change_r();
    void change_d();
    void change_e();
    void change_e1();
    void change_rHarn();
    void raschet_dlin_shtang();
    void raschet_rab();
    void change_comType();
    bool fIsPresentZven(float xv, float yv, float hv);
    double fDlinaShtan(double r1, double r, double Lx, double Ly, double Lz, double alfa, double alfao, double vsharnapla);


    long MAX_INT = 999999999;
    long int NMaxSech = 1000, p, Nz;
    double k[4][4], mZ[1000], PloshadiSech[1000], VV, Vmin, Vmax, dmin, dmax, Shmin, Shmax, step_V, step_Dl, step_Sh, lmin, lmax, arash, alf[2][6], hSh[6], hmin, hmax, step_h, step_x, step_y, step;
    Glib::RefPtr<Gtk::Builder> _builder;
    Gtk::Button *raschet_dlin, *rasch_rab;
    Gtk::ComboBoxText *comType, *SharType;
    Gtk::Image *comTypeImg;
    Gtk::SpinButton *OsnR, *e, *e1, *d1, *d, *OsnRr, *Plat_r, *CountHtang, *anglRas, *rHarnOsn, *rHarnPla, *Sh, *D, *V, *CountPoint, *anglPlatX, *anglPlatY, *anglPlatZ,*alfo[6], *alfp[6], *Lo, *Lp, *L, *Lmin, *Lmax, *heightSh[6], *xyz[3][2], *rastMezhO_P;

};


#endif //MPS_WINDOW_H
