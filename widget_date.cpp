#include "widget_date.h"

widget_date::widget_date(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout * mainlayout = new QVBoxLayout();
    this->setLayout(mainlayout);

    // Boutons choix date absolue/relative
    QWidget * choicewidget = new QWidget();
    QHBoxLayout * choicelayout = new QHBoxLayout();
    QRadioButton * dateabs = new QRadioButton("Date pr�cise",this);
    choicelayout->addWidget(dateabs);
    QRadioButton * daterel = new QRadioButton("Date relative � une autre t�che");
    choicelayout->addWidget(daterel);
    choicewidget->setLayout(choicelayout);
    mainlayout->addWidget(choicewidget);

    // Choix abs
    abswidget = new QWidget();
    QFormLayout * abslayout = new QFormLayout();
    QCalendarWidget * calendar = new QCalendarWidget();
    abslayout->addRow("Date :",calendar);
    QTimeEdit * time = new QTimeEdit();
    abslayout->addRow("Heure :",time);
    abswidget->setLayout(abslayout);
    mainlayout->addWidget(abswidget);
    abswidget->setVisible(false);

    // Choix rel
    relwidget = new QWidget();
    QGridLayout * rellayout = new QGridLayout();
    QSpinBox * spin = new QSpinBox();
    spin->setMinimum(1);
    spin->setMaximum(12);
    rellayout->addWidget(spin,0,0);
    QComboBox * unit = new QComboBox();
    unit->addItem("minute(s)");
    unit->addItem("heure(s)");
    unit->addItem("jour(s)");
    unit->addItem("semaine(s)");
    unit->addItem("mois");
    rellayout->addWidget(unit,0,1);
    QComboBox * avapr = new QComboBox();
    avapr->addItem("avant");
    avapr->addItem("apr�s");
    rellayout->addWidget(avapr,0,2);
    // TODO : Ajouter widget pour selectionner la tache
    relwidget->setLayout(rellayout);
    mainlayout->addWidget(relwidget);
    relwidget->setVisible(false);

    // Connect boutons choix -- widget correspondant
    QObject::connect(dateabs,SIGNAL(clicked()),this,SLOT(afficher_abs()));
    QObject::connect(daterel,SIGNAL(clicked()),this,SLOT(afficher_rel()));

    // Bouton date absolue choisi par d�faut
    dateabs->click();
}

widget_date::~widget_date()
{

}


// SLOTS

void widget_date::afficher_abs()
{
    abswidget->setVisible(true);
    relwidget->setVisible(false);
}


void widget_date::afficher_rel()
{
    abswidget->setVisible(false);
    relwidget->setVisible(true);
}
