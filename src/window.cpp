#include "window.h"

window::window(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder):
Gtk::Window(cobject),
_builder(builder)
{

    _builder->get_widget("comTypeImg", comTypeImg);
    _builder->get_widget("SharType", SharType);
    //Кнопки
    _builder->get_widget("raschet_dlin",raschet_dlin);
    _builder->get_widget("comType", comType);
    _builder->get_widget("rasch_rab", rasch_rab);

    //Пееременные
    _builder->get_widget("OsnR", OsnR);
    _builder->get_widget("OsnRr", OsnRr);
    _builder->get_widget("Plat_r", Plat_r);
    _builder->get_widget("CountHtang", CountHtang);
    _builder->get_widget("anglRas", anglRas);
    _builder->get_widget("rHarnOsn", rHarnOsn);
    _builder->get_widget("rHarnPla", rHarnPla);
    _builder->get_widget("Sh", Sh);
    _builder->get_widget("D", D);
    _builder->get_widget("V", V);
    _builder->get_widget("CountPoint", CountPoint);
    _builder->get_widget("anglPlatX", anglPlatX);
    _builder->get_widget("anglPlatY", anglPlatY);
    _builder->get_widget("anglPlatZ", anglPlatZ);
    _builder->get_widget("Lo", Lo);
    _builder->get_widget("Lp", Lp);
    _builder->get_widget("L", L);
    _builder->get_widget("Lmin",Lmin);
    _builder->get_widget("Lmax",Lmax);
    _builder->get_widget("rastMezhO_P", rastMezhO_P);
    _builder->get_widget("x0", xyz[0][0]);
    _builder->get_widget("x1", xyz[0][1]);
    _builder->get_widget("y0", xyz[1][0]);
    _builder->get_widget("y1", xyz[1][1]);
    _builder->get_widget("z0", xyz[2][0]);
    _builder->get_widget("z1", xyz[2][1]);
    _builder->get_widget("d", d);
    _builder->get_widget("d1", d1);
    _builder->get_widget("e", e);
    _builder->get_widget("e1", e1);

    for (int i = 0; i < 6; ++i) {
        std::string temp = "alfo";
        temp+=std::to_string(i);
        _builder->get_widget(temp,alfo[i]);
    }
    for (int i = 0; i < 6; ++i) {
        std::string temp = "alfp";
        temp+=std::to_string(i);
        _builder->get_widget(temp,alfp[i]);
    }

    for (int i = 0; i < 6; ++i) {
        std::string temp = "heightSh";
        temp+=std::to_string(i);
        _builder->get_widget(temp,heightSh[i]);
    }

    //Создание переменых

    OsnR->configure(Gtk::Adjustment::create(160.0,0.01, MAX_INT,0.01,10,0),1,2);
    OsnRr->configure(Gtk::Adjustment::create(2.0,0.0, MAX_INT,0.01,10,0),1,2);
    Plat_r->configure(Gtk::Adjustment::create(80.0,0.0,MAX_INT,0.01,10,0),1,2);
    CountHtang->configure(Gtk::Adjustment::create(3.0,2.0,6.0,1,10,0),1,0);
    anglRas->configure(Gtk::Adjustment::create(11.0,0.01,179.99,0.01,10,0),1,2);
    rHarnOsn->configure(Gtk::Adjustment::create(20.0,0.0, MAX_INT,0.01,10,0),1,2);
    rHarnPla->configure(Gtk::Adjustment::create(10.0,0.0,MAX_INT,0.01,10,0),1,2);
    Sh->configure(Gtk::Adjustment::create(100.0,0.01, MAX_INT,0.01,10,0),1,2);
    D->configure(Gtk::Adjustment::create(100.0,0.01, MAX_INT,0.01,10,0),1,2);
    V->configure(Gtk::Adjustment::create(100.0,0.01, MAX_INT,0.01,10,0),1,2);
    CountPoint->configure(Gtk::Adjustment::create(100.0,1.0, MAX_INT,0,0,0),1,0);
    anglPlatX->configure(Gtk::Adjustment::create(0,-90,90,0,10,0),1,0);
    anglPlatY->configure(Gtk::Adjustment::create(0,-90,90,0,10,0),1,0);
    anglPlatZ->configure(Gtk::Adjustment::create(0,-90,90,0,10,0),1,0);
    L->configure(Gtk::Adjustment::create(40,0,MAX_INT,0,10,0),1,0);
    Lo->configure(Gtk::Adjustment::create(40,0,MAX_INT,0,10,0),1,0);
    Lp->configure(Gtk::Adjustment::create(20,0,MAX_INT,0,10,0),1,0);
    Lmin->configure(Gtk::Adjustment::create(0,0,MAX_INT,0,0,0),1,2);
    Lmin->set_editable(false);
    Lmax->configure(Gtk::Adjustment::create(0,0,MAX_INT,0,0,0),1,2);
    Lmax->set_editable(false);
    rastMezhO_P->configure(Gtk::Adjustment::create(0,0,MAX_INT,0,0,0),1,0);
    rastMezhO_P->set_editable(false);
    d->configure(Gtk::Adjustment::create(26,0,MAX_INT,1,10,0),1,0);
    d1->configure(Gtk::Adjustment::create(10,0,MAX_INT,1,10,0),1,0);
    d->configure(Gtk::Adjustment::create(1,0,MAX_INT,1,10,0),1,0);
    d1->configure(Gtk::Adjustment::create(1,0,MAX_INT,1,10,0),1,0);


    CountPoint->set_editable(false);

    for (int i = 0; i < 6; ++i) {
        alfo[i]->configure(Gtk::Adjustment::create(0,0,360,0.01,10,0),1,2);
    }
    for (int i = 0; i < 6; ++i) {
        alfp[i]->configure(Gtk::Adjustment::create(0,0,360,0.01,10,0),1,2);
    }
    for (int i = 0; i < 6; ++i) {
        heightSh[i]->configure(Gtk::Adjustment::create(0,0,MAX_INT,0.01,10,0),1,2);
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            xyz[i][j]->configure(Gtk::Adjustment::create(0,-MAX_INT, MAX_INT,1,10,0),1,0);
        }
    }


    //Функции
    OsnR->signal_value_changed().connect(sigc::mem_fun(*this, &window::change_R));
    OsnRr->signal_value_changed().connect(sigc::mem_fun(*this, &window::change_R));
    Plat_r->signal_value_changed().connect(sigc::mem_fun(*this, &window::change_r));
    anglRas->signal_value_changed().connect(sigc::mem_fun(*this, &window::change_anglRas));
    d->signal_value_changed().connect(sigc::mem_fun(*this, &window::change_d));
    d1->signal_value_changed().connect(sigc::mem_fun(*this, &window::change_d));
    e->signal_value_changed().connect(sigc::mem_fun(*this, &window::change_e));
    e1->signal_value_changed().connect(sigc::mem_fun(*this, &window::change_e1));

    rHarnOsn->signal_value_changed().connect(sigc::mem_fun(*this, &window::change_rHarn));
    rHarnPla->signal_value_changed().connect(sigc::mem_fun(*this, &window::change_rHarn));
    CountHtang->signal_value_changed().connect(sigc::mem_fun(*this, &window::change_comType));

    for (int i = 0; i < 6; ++i) {
        alfo[i]->signal_value_changed().connect(
            sigc::bind(sigc::mem_fun(this, &window::alf_change),0,i, alfo[i]->get_adjustment())
            );
    }
    for (int i = 0; i < 6; ++i) {
        alfp[i]->signal_value_changed().connect(
                sigc::bind(sigc::mem_fun(this, &window::alf_change),1,i, alfp[i]->get_adjustment())
        );
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            xyz[i][j]->signal_value_changed().connect(sigc::mem_fun(*this, &window::change_xyz));
        }
    }
    for (int i = 0; i < 3; ++i) {
        xyz[i][0]->set_editable(false);
        xyz[i][0]->set_increments(0,0);
    }



    rasch_rab->signal_clicked().connect(sigc::mem_fun(*this, &window::raschet_rab));
    raschet_dlin->signal_clicked().connect(sigc::mem_fun(*this, &window::raschet_dlin_shtang));
    comType->signal_changed().connect(sigc::mem_fun(*this, &window::change_comType));

    change_comType();
    change_anglRas();
    xyz[0][1]->set_value(1000);
    xyz[1][1]->set_value(1000);
    xyz[2][0]->set_value(0);
    xyz[2][2]->set_value(2000);
}


void window::raschet_dlin_shtang(){

    double *DlinaShtang = new double [CountHtang->get_value_as_int()];
    //Первая строка
    k[0][0]=cos(anglPlatY->get_value()*M_PI/180)*cos(anglPlatZ->get_value()*M_PI/180);
    k[0][0]=floorf(k[0][0]*100)/100;
    k[0][1]=-1 * cos(anglPlatY->get_value() * M_PI / 180) * sin(anglPlatZ->get_value() * M_PI / 180);
    k[0][1]=floorf(k[0][1]*100)/100;
    k[0][2]=sin(anglPlatY->get_value()*M_PI/180);
    k[0][2]=floorf(k[0][2]*100)/100;
    k[0][3]=Sh->get_value();
    //Вторая строка
    k[1][0] = sin(anglPlatX->get_value() * M_PI / 180) * sin(anglPlatY->get_value() * M_PI / 180) * cos(anglPlatZ->get_value() * M_PI / 180) + cos(anglPlatX->get_value() * M_PI / 180) * sin(anglPlatZ->get_value() * M_PI / 180);
    k[1][0] = floorf(k[1][0]*100)/100;
    k[1][1] = -1 * sin(anglPlatX->get_value() * M_PI / 180) * sin(anglPlatY->get_value() * M_PI / 180) * sin(anglPlatZ->get_value() * M_PI / 180) + cos(anglPlatX->get_value() * M_PI / 180) * cos(anglPlatZ->get_value() * M_PI / 180);
    k[1][1] = floorf(k[1][1]*100)/100;
    k[1][2] = -1 * sin(anglPlatX->get_value() * M_PI / 180) * cos(anglPlatY->get_value() * M_PI / 180);
    k[1][2] = floorf(k[1][2]*100)/100;
    k[1][3]=D->get_value();
    //Третья строка
    k[2][0] = -1 * cos(anglPlatX->get_value() * M_PI / 180) * sin(anglPlatY->get_value() * M_PI / 180) * cos(anglPlatZ->get_value() * M_PI / 180) + sin(anglPlatX->get_value() * M_PI / 180) * sin(anglPlatZ->get_value() * M_PI / 180);
    k[2][0] = floorf(k[2][0]*100)/100;
    k[2][1] = cos(anglPlatX->get_value() * M_PI / 180) * sin(anglPlatY->get_value() * M_PI / 180) * sin(anglPlatZ->get_value() * M_PI / 180) + sin(anglPlatZ->get_value() * M_PI / 180) * cos(anglPlatZ->get_value() * M_PI / 180);
    k[2][1] = floorf(k[2][1]*100)/100;
    k[2][2] = cos(anglPlatX->get_value() * M_PI / 180) * cos(anglPlatY->get_value() * M_PI / 180);
    k[2][2] = floorf(k[2][2]*100)/100;
    k[2][3]=V->get_value();
    //Четвёртая строка
    k[3][0]=0;
    k[3][1]=0;
    k[3][2]=0;
    k[3][3]=1;

    Vmin = (OsnR->get_value() - Plat_r->get_value()) / (sin(arash * M_PI / 180) / cos(arash * M_PI / 180));
    Vmax = Vmin + V->get_value();
    dmin = -1 * D->get_value() / 2;
    dmax = D->get_value() / 2;
    Shmin = -1 * Sh->get_value() / 2;
    Shmax = Sh->get_value() / 2;
    step_V = (Vmax - Vmin) / (CountPoint->get_value() - 1);
    step_Dl = (dmax - dmin) / (CountPoint->get_value() - 1);
    step_Sh = (Shmax - Shmin) / (CountPoint->get_value() - 1);
    lmin = 1E+16;
    lmax = 0;

    for (int i = 0; i < CountHtang->get_value(); ++i) {

        for (int j = 0; j < CountPoint->get_value(); ++j) {
            k[2][3]=Vmin+j*step_V;

            for (int l = 0; l < CountPoint->get_value(); ++l) {
                k[1][3]=dmin+l*step_Dl;

                for (int m = 0; m < CountPoint->get_value(); ++m) {
                    k[0][3] = Shmin +m * step_Sh;
                    DlinaShtang[i]= fDlinaShtan(Plat_r->get_value(),OsnR->get_value(),0,0,0,alf[1][i], alf[0][i],0);
                    if(DlinaShtang[i]<lmin) lmin = DlinaShtang[i];
                    if(DlinaShtang[i]>lmax) lmax = DlinaShtang[i];
                }
            }
        }

        rastMezhO_P->set_value(sqrt(pow(lmin,2)-pow(OsnR->get_value()-Plat_r->get_value(),2)));

        Lmax->set_value(lmax);
        Lmin->set_value(lmin);

    }

}

double window::fDlinaShtan(double r1, double r, double Lx, double Ly, double Lz, double alfa, double alfao,
                           double vsharnapla) {
    return sqrt(pow((r1 * cos(alfa) * k[0][0] + r1 * sin(alfa) * k[0][1] + 0 * k[0][2] + 1 * k[0][3] + Lx -
    ((r) * cos(alfao))), 2) + pow(((r1 * cos(alfa) * k[1][0] + r1 * sin(alfa) * k[1][1] + 0 * k[1][2] + k[1][3] +
    Ly - ((r) * sin(alfao)))), 2) + pow((r1 * cos(alfa) * k[2][0] + r1 * sin(alfa) * k[2][1] + k[2][3] + Lz + vsharnapla), 2));
}

void window::change_R() {
    if(OsnRr->get_value()!=0){
        Plat_r->set_value(OsnR->get_value()/OsnRr->get_value());
    };
}
void window::change_r() {
    if(OsnRr->get_value()!=0){
        OsnR->set_value(Plat_r->get_value()*OsnRr->get_value());
    };
}

void window::change_d() {
    if(d1->get_value()<d->get_value()){
        d1->set_value(d->get_value()+1);
    }
}

void window::change_e() {
    if(e->get_value()>rHarnPla->get_value()*2){
        e->set_value(rHarnPla->get_value()*2-1);
    }
}

void window::change_e1() {
    if(e1->get_value()>rHarnOsn->get_value()*2){
        e1->set_value(rHarnOsn->get_value()*2-1);
    }
}

void window::change_rHarn() {
    if(OsnR->get_value()<rHarnOsn->get_value()){
        Gtk::MessageDialog dia (*this, "Внимание", false, Gtk::MESSAGE_WARNING);
        dia.set_secondary_text("Радиус r_шо не может быть больше Rmin основания!");
        dia.run();
        rHarnOsn->set_value(OsnR->get_value());
    }
    if(Plat_r->get_value()<rHarnPla->get_value()){
        Gtk::MessageDialog dia (*this, "Внимание", false, Gtk::MESSAGE_WARNING);
        dia.set_secondary_text("Радиус r_шп не может быть больше r платфоры!");
        dia.run();
        rHarnPla->set_value(Plat_r->get_value());
    }
    if(rHarnOsn->get_value()<=rHarnPla->get_value()){
        rHarnOsn->set_value(rHarnPla->get_value()+0.01);
    };
}

void window::change_anglRas(){
    arash = anglRas->get_value() / 2;
}

void window::change_comType() {
    switch (comType->get_active_row_number()) {
        case 0: //Равномерная
            for (int i = 0; i < 6; ++i) {
                alfo[i]->set_editable(false);
                alfo[i]->set_increments(0,0);
                alfp[i]->set_editable(false);
                alfp[i]->set_increments(0,0);
            }
            L_dis();
            for (int i = 0; i < CountHtang->get_value_as_int(); ++i) {
                alfo[i]->set_value(360/CountHtang->get_value_as_int()*i);
                alfp[i]->set_value(360/CountHtang->get_value_as_int()*i);
            }
            comTypeImg->set(Gdk::Pixbuf::create_from_file("img/0.gif",150,150));
            break;
        case 1: //Асиметричная
            L_dis();
            for (int i = 0; i < CountHtang->get_value_as_int(); ++i) {
                alfo[i]->set_editable(true);
                alfo[i]->set_increments(1,10);
                alfp[i]->set_editable(true);
                alfp[i]->set_increments(1,10);
            }
            comTypeImg->set(Gdk::Pixbuf::create_from_file("img/1.gif",150,150));
            break;
        case 2: //Симметричная
            if(CountHtang->get_value()!=6){
                comType->set_active(0);
                Gtk::MessageDialog dia (*this, "Внимание", false, Gtk::MESSAGE_WARNING);
                dia.set_secondary_text("Внимания для этого типа компановки должно быть 6 штанг!");
                dia.run();
                break;
            }
            L_dis();
            Lp->set_editable(true);
            Lp->set_increments(1,10);
            Lo->set_editable(true);
            Lo->set_increments(1,10);
            for (int i = 0; i < CountHtang->get_value_as_int(); ++i) {
                alfo[i]->set_editable(false);
                alfo[i]->set_increments(0,0);
                alfp[i]->set_editable(false);
                alfp[i]->set_increments(0,0);
            }
            comTypeImg->set(Gdk::Pixbuf::create_from_file("img/2.gif",150,150));

            if(Lo->get_value()>0){ //Оснавание
                if((1 - (Lo->get_value_as_int() / (2 * OsnR->get_value() * Lo->get_value_as_int() / (2 * OsnR->get_value()))))<0){
                    Gtk::MessageDialog dia (*this, "Внимание", false, Gtk::MESSAGE_WARNING);
                    dia.set_secondary_text("При заданных значениях радиуса основания R и расстояния между шарнирами на основании Lо конструкция не может существовать, поэтому рассчитать значения углов не возможно!");
                    dia.run();
                    for (int i = 0; i < CountHtang->get_value_as_int(); ++i) {
                        alfo[i]->set_value(0);
                    }
                    alfo[0]->set_editable(true);
                    alfo[0]->set_increments(1,10);
                } else {
                    float c1 = (2* asin(Lo->get_value()/(2*OsnR->get_value_as_int())))/M_PI*180/2;

                    alfo[0]->set_editable(true);
                    alfo[0]->set_increments(1,10);

                    alfo[0]->set_value(c1);
                    alfo[1]->set_value(120-c1);
                    alfo[2]->set_value(120+c1);
                    alfo[3]->set_value(240-c1);
                    alfo[4]->set_value(240+c1);
                    alfo[5]->set_value(360-c1);
                }
            }
            if(Lp->get_value()>0){
                if((1 - (Lp->get_value() / (2 * Plat_r->get_value() * Lp->get_value() / (2 * Plat_r->get_value()))) < 0)){
                    Gtk::MessageDialog dia (*this, "Внимание", false, Gtk::MESSAGE_WARNING);
                    dia.set_secondary_text("При заданных значениях радиуса основания r и расстояния между шарнирами на основании Lп конструкция не может существовать, поэтому рассчитать значения углов не возможно!");
                    dia.run();
                    for (int i = 0; i < CountHtang->get_value_as_int(); ++i) {
                        alfp[i]->set_value(0);
                    }
                    alfp[0]->set_editable(true);
                    alfp[0]->set_increments(1,10);
                } else {
                    float c1 = (2 * asin(Lp->get_value() / (2 * Plat_r->get_value()))) / M_PI * 180 / 2;

                    alfp[0]->set_editable(true);
                    alfp[0]->set_increments(1,10);

                    alfp[0]->set_value(c1);
                    alfp[1]->set_value(120-c1);
                    alfp[2]->set_value(120+c1);
                    alfp[3]->set_value(240-c1);
                    alfp[4]->set_value(240+c1);
                    alfp[5]->set_value(360-c1);
                }

            }
            break;


        case 3: //Попарная
            if(CountHtang->get_value()!=6){
                comType->set_active(0);
                Gtk::MessageDialog dia (*this, "Внимание", false, Gtk::MESSAGE_WARNING);
                dia.set_secondary_text("Внимания для этого типа компановки должно быть 6 штанг!");
                dia.run();
                break;
            }
            L_dis();
            L->set_editable(true);
            L->set_increments(1,10);
            for (int i = 0; i < CountHtang->get_value_as_int(); ++i) {
                alfo[i]->set_editable(false);
                alfo[i]->set_increments(0,0);
                alfp[i]->set_editable(false);
                alfp[i]->set_increments(0,0);
            }
            alfp[0]->set_editable(true);
            alfp[0]->set_increments(1,10);

            comTypeImg->set(Gdk::Pixbuf::create_from_file("img/3.gif",150,150));

            if((1 - (L->get_value() / (2 * OsnR->get_value()) * L->get_value() / (2 * OsnR->get_value()))) < 0){
                Gtk::MessageDialog dia (*this, "Внимание", false, Gtk::MESSAGE_WARNING);
                dia.set_secondary_text("При заданных значениях радиуса основания R и расстояния между шарнирами L конструкция не может существовать, поэтому рассчитать значения углов не возможно!");
                dia.run();
                for (int i = 0; i < CountHtang->get_value_as_int(); ++i) {
                    alfo[i]->set_value(0);
                    alfp[i]->set_value(0);
                }
            } else if ((1 - (L->get_value() / (2 * Plat_r->get_value()) * L->get_value() / (2 * Plat_r->get_value()))) < 0){
                Gtk::MessageDialog dia (*this, "Внимание", false, Gtk::MESSAGE_WARNING);
                dia.set_secondary_text("При заданных значениях радиуса платформы r и расстояния между шарнирами L конструкция не может существовать, поэтому рассчитать значения углов не возможно!");
                dia.run();
                for (int i = 0; i < CountHtang->get_value_as_int(); ++i) {
                    alfo[i]->set_value(0);
                    alfp[i]->set_value(0);
                }
            } else {
                float c1 = (2 * asin(L->get_value() / (2 * Plat_r->get_value()))) / M_PI * 180 / 2;

                alfp[0]->set_value(c1);
                alfp[1]->set_value(120-c1);
                alfp[2]->set_value(120+c1);
                alfp[3]->set_value(240-c1);
                alfp[4]->set_value(240+c1);
                alfp[5]->set_value(360-c1);

                c1 = (2 * asin(L->get_value() / (2 * OsnR->get_value()))) / M_PI * 180 / 2;

                alfo[0]->set_value(c1);
                alfo[1]->set_value(120-c1);
                alfo[2]->set_value(120+c1);
                alfo[3]->set_value(240-c1);
                alfo[4]->set_value(240+c1);
                alfo[5]->set_value(360-c1);
            }
            break;

        case 4: //Ферменая
            if(CountHtang->get_value()!=6){
                comType->set_active(0);
                Gtk::MessageDialog dia (*this, "Внимание", false, Gtk::MESSAGE_WARNING);
                dia.set_secondary_text("Внимания для этого типа компановки должно быть 6 штанг!");
                dia.run();
                break;
            }
            L_dis();
            Lp->set_editable(true);
            Lp->set_increments(1,10);
            Lo->set_editable(true);
            Lo->set_increments(1,10);
            for (int i = 0; i < CountHtang->get_value_as_int(); ++i) {
                alfo[i]->set_editable(false);
                alfo[i]->set_increments(0,0);
                alfp[i]->set_editable(false);
                alfp[i]->set_increments(0,0);
            }
            alfo[0]->set_editable(true);
            alfo[0]->set_increments(0.1,10);
            alfp[0]->set_editable(true);
            alfp[0]->set_increments(0.1,10);
            comTypeImg->set(Gdk::Pixbuf::create_from_file("img/4.gif",150,150));
            if((1 - (Lo->get_value() / (2 * OsnR->get_value()) * Lo->get_value() / (2 * OsnR->get_value()))) < 0 ){
                Gtk::MessageDialog dia (*this, "Внимание", false, Gtk::MESSAGE_WARNING);
                dia.set_secondary_text("При заданных значениях радиуса основания R и расстояния между шарнирами на основании Lо конструкция не может существовать, поэтому рассчитать значения углов не возможно!");
                dia.run();
                for (int i = 0; i < CountHtang->get_value_as_int(); ++i) {
                    alfo[i]->set_value(0);
                    alfp[i]->set_value(0);
                }
            } else if((1 - (Lp->get_value() / (2 * Plat_r->get_value()) * Lp->get_value() / (2 * Plat_r->get_value()))) < 0){
                Gtk::MessageDialog dia (*this, "Внимание", false, Gtk::MESSAGE_WARNING);
                dia.set_secondary_text("При заданных значениях радиуса основания r и расстояния между шарнирами на основании Lп конструкция не может существовать, поэтому рассчитать значения углов не возможно!");
                dia.run();
                for (int i = 0; i < CountHtang->get_value_as_int(); ++i) {
                    alfo[i]->set_value(0);
                    alfp[i]->set_value(0);
                }
            } else {
                float c1 = (2 * asin(Lo->get_value() / (2 * OsnR->get_value()))) / M_PI * 180 / 2;

                alfo[0]->set_value(c1);
                alfo[1]->set_value(120-c1);
                alfo[2]->set_value(120+c1);
                alfo[3]->set_value(240-c1);
                alfo[4]->set_value(240+c1);
                alfo[5]->set_value(360-c1);

                c1 = (120 - (2 * asin(Lp->get_value() / (2 * Plat_r->get_value()))) / M_PI * 180) / 2;

                alfp[0]->set_value(c1);
                alfp[1]->set_value(120-c1);
                alfp[2]->set_value(120+c1);
                alfp[3]->set_value(240-c1);
                alfp[4]->set_value(240+c1);
                alfp[5]->set_value(360-c1);
            }
            break;
    }
    for (int i = 0; i < 6; ++i) {
        heightSh[i]->set_editable(false);
        heightSh[i]->set_increments(0,0);
    }
    for (int i = 0; i < CountHtang->get_value_as_int(); ++i) {
        heightSh[i]->set_editable(true);
        heightSh[i]->set_increments(0.01,10);
    }
}

void window::L_dis() {
    L->set_editable(false);
    L->set_increments(0,0);
    Lp->set_editable(false);
    Lp->set_increments(0,0);
    Lo->set_editable(false);
    Lo->set_increments(0,0);
}

void window::alf_change(int alf_id, int alf_count, const Glib::RefPtr<Gtk::Adjustment> &adj) {
    alf[alf_id][alf_count] = adj->get_value()*M_PI/180;
}

void window::change_xyz() {
    xyz[2][0]->set_value(0);
    for (int i = 0; i < 2; ++i) {
        xyz[i][0]->set_value(-xyz[i][0]->get_value_as_int());
    }
}

bool window::fIsPresentZven(double xv, double yv, double hv) {
    double *DlinaShtang = new double [CountHtang->get_value_as_int()];
    double amaxpl[CountHtang->get_value_as_int()], amaxo[CountHtang->get_value_as_int()], aminpl[CountHtang->get_value_as_int()], amino[CountHtang->get_value_as_int()];

    switch (SharType->get_active_row_number()) {
        case 0:
            for (int i = 0; i < CountHtang->get_value_as_int(); ++i) {
                if (heightSh[i] = 0) {
                    amaxpl[i] = M_PI - (asin(d->get_value() / (2 * rHarnPla->get_value())) + asin(e->get_value() / rHarnPla->get_value()));
                    aminpl[i] = asin(d->get_value() / (2 * rHarnPla->get_value())) + asin(e->get_value() / rHarnPla->get_value());
                    amaxo[i] = M_PI - (asin(d1->get_value() / (2 * rHarnOsn->get_value())) + asin(e1->get_value() / rHarnOsn->get_value()));
                    amino[i] = asin(d1->get_value() / (2 * rHarnOsn->get_value())) + asin(e1->get_value() / rHarnOsn->get_value());
                } else {
                    amaxpl[i] = M_PI / 2 - asin(d->get_value() / (2 * rHarnPla->get_value())) + asin(e->get_value() / rHarnPla->get_value());
                    aminpl[i] = 0;
                    amaxo[i] = M_PI - (asin(d1->get_value() / (2 * rHarnOsn->get_value())) + asin(e1->get_value() / rHarnOsn->get_value()));
                    amino[i] = asin(d1->get_value() / (2 * rHarnOsn->get_value())) + asin(e1->get_value() / rHarnOsn->get_value());
                }
            }
            break;
        case 1:
            for (int i = 0; i < CountHtang->get_value_as_int(); ++i) {
                if (heightSh[i] = 0) {
                    amaxpl[i] = 90;
                    aminpl[i] = 0;
                    amaxo[i] = M_PI - (asin(d1->get_value() / (2 * rHarnOsn->get_value())) + asin(e1->get_value() / rHarnOsn->get_value()));
                    amino[i] = asin(d1->get_value() / (2 * rHarnOsn->get_value())) + asin(e1->get_value() / rHarnOsn->get_value());
                } else {
                    amaxpl[i] = 90;
                    aminpl[i] = 0;
                    amaxo[i] = M_PI - (asin(d1->get_value() / (2 * rHarnOsn->get_value())) + asin(e1->get_value() / rHarnOsn->get_value()));
                    amino[i] = asin(d1->get_value() / (2 * rHarnOsn->get_value())) + asin(e1->get_value() / rHarnOsn->get_value());
                }
            }
            break;
    }

    k[0][0]=cos(anglPlatY->get_value()*M_PI/180)*cos(anglPlatZ->get_value()*M_PI/180);
    k[0][0]=floorf(k[0][0]*100)/100;
    k[0][1]=-cos(anglPlatY->get_value() * M_PI / 180) * sin(anglPlatZ->get_value() * M_PI / 180);
    k[0][1]=floorf(k[0][1]*100)/100;
    k[0][2]=sin(anglPlatY->get_value()*M_PI/180);
    k[0][2]=floorf(k[0][2]*100)/100;
    k[0][3]=xv;
    //Вторая строка
    k[1][0] = sin(anglPlatX->get_value() * M_PI / 180) * sin(anglPlatY->get_value() * M_PI / 180) * cos(anglPlatZ->get_value() * M_PI / 180) + cos(anglPlatX->get_value() * M_PI / 180) * sin(anglPlatZ->get_value() * M_PI / 180);
    k[1][0] = floorf(k[1][0]*100)/100;
    k[1][1] = -sin(anglPlatX->get_value() * M_PI / 180) * sin(anglPlatY->get_value() * M_PI / 180) * sin(anglPlatZ->get_value() * M_PI / 180) + cos(anglPlatX->get_value() * M_PI / 180) * cos(anglPlatZ->get_value() * M_PI / 180);
    k[1][1] = floorf(k[1][1]*100)/100;
    k[1][2] = -sin(anglPlatX->get_value() * M_PI / 180) * cos(anglPlatY->get_value() * M_PI / 180);
    k[1][2] = floorf(k[1][2]*100)/100;
    k[1][3]=yv;
    //Третья строка
    k[2][0] = -cos(anglPlatX->get_value() * M_PI / 180) * sin(anglPlatY->get_value() * M_PI / 180) * cos(anglPlatZ->get_value() * M_PI / 180) + sin(anglPlatX->get_value() * M_PI / 180) * sin(anglPlatZ->get_value() * M_PI / 180);
    k[2][0] = floorf(k[2][0]*100)/100;
    k[2][1] = cos(anglPlatX->get_value() * M_PI / 180) * sin(anglPlatY->get_value() * M_PI / 180) * sin(anglPlatZ->get_value() * M_PI / 180) + sin(anglPlatZ->get_value() * M_PI / 180) * cos(anglPlatZ->get_value() * M_PI / 180);
    k[2][1] = floorf(k[2][1]*100)/100;
    k[2][2] = cos(anglPlatX->get_value() * M_PI / 180) * cos(anglPlatY->get_value() * M_PI / 180);
    k[2][2] = floorf(k[2][2]*100)/100;
    k[2][3]=hv;

    for (int i = 0; i < CountHtang->get_value_as_int(); ++i) {
        DlinaShtang[i]= fDlinaShtan(Plat_r->get_value(), (OsnR->get_value()+p*step), 0, 0, 0, alf[1][i], alf[0][i], heightSh[i]->get_value());
        if(DlinaShtang[i]<lmin || DlinaShtang[i]>lmax){
            return false;
            break;
        }else{
            double a= asin((Plat_r->get_value()*k[2][0]+k[2][3]+heightSh[i]->get_value()))/DlinaShtang[i];
            if(((a < aminpl[i]) || (a > amaxpl[i])) || ((a < amino[i]) || (a > amaxo[i]))){
                return false;
                break;
            }
        }
    }
    return true;
}

void window::RashetPloshadiSech(long n, double Prostr[3][100*100*100]) {
    bool IsTrue;
    Nz=0;
    for (int i = 0; i < n; ++i) {
        IsTrue=false;
        for (int j = 0; j < Nz; ++j) {
            if(Prostr[2][i]==mZ[j]){
                IsTrue= true;
            }
        }
        if(!IsTrue){
            Nz+=1;
            mZ[Nz]=Prostr[3][i];
        }
    }
    for (int i = 0; i < Nz; ++i) {
        for (int j = 0; j < n; ++j) {
            if(Prostr[3][j]==mZ[i]){
                PloshadiSech[i]+=1;
            }
        }

    }
}

void window::raschet_rab() {
    long int NumPoint, CountIsPres;

    p = 0;
    step = 0;

    long CountAllPoint = pow(CountPoint->get_value_as_int(),3);


    double RabPrX[CountAllPoint], RabPrY[CountAllPoint], RabPrH[CountAllPoint], RabPrIsPresent[CountAllPoint], PloshadSechMax, hh, yy, xx;
    double Prostr[3][100*100*100];

    hmin=xyz[0][0]->get_value()+rastMezhO_P->get_value_as_int();
    hmax=xyz[0][1]->get_value()+rastMezhO_P->get_value_as_int();

    step_h = (hmax-hmin)/(CountPoint->get_value()-1);
    step_x = (xyz[0][1]->get_value_as_int()-xyz[0][0]->get_value_as_int())/(CountPoint->get_value()-1);
    step_y = (xyz[1][1]->get_value_as_int()-xyz[1][0]->get_value_as_int())/(CountPoint->get_value()-1);

    NumPoint=0;
    for (int i = 0; i < CountPoint->get_value_as_int(); ++i) {
        hh=hmin+i*step_h;
        for (int j = 0; j < CountPoint->get_value_as_int(); ++j) {
            yy=xyz[1][0]->get_value_as_int()+j*step_y;
            for (int l = 0; l < CountPoint->get_value_as_int(); ++l) {
                xx = xyz[0][0]->get_value_as_int()+l*step_x;
                NumPoint=NumPoint+1;
                RabPrX[NumPoint]=xx;
                RabPrY[NumPoint]=yy;
                RabPrH[NumPoint]=hh;
                if(fIsPresentZven(xx,yy,hh)){
                    RabPrIsPresent[NumPoint]=1;
                } else {
                    RabPrIsPresent[NumPoint]=0;
                }
            }
        }
    }
    CountIsPres = 0;

    for (int i = 0; i < NumPoint; ++i) {
        if(RabPrIsPresent[i]){
            CountIsPres = CountIsPres + 1;
            Prostr[0][CountIsPres] = RabPrX[i];
            Prostr[1][CountIsPres] = RabPrY[i];
            Prostr[2][CountIsPres] = RabPrH[i];
        }
    }

    RashetPloshadiSech(CountIsPres, Prostr);

    PloshadSechMax = PloshadiSech[0] * step_x * step_y;
    for (int i = 1; i < Nz; ++i) {
        if(PloshadiSech[i] * step_x * step_y > PloshadSechMax) {
            PloshadSechMax = PloshadiSech[i] * step_x * step_y;
        }
    }
    std::cout<<PloshadSechMax;

    VV=0;
    for (int i = 0; i < Nz; ++i) {
        VV = VV + PloshadiSech[i] * step_x * step_y * step_h;
    }
    std::cout<<std::endl<<VV;
}