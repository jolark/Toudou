#ifndef WIDGET_DATE_H
#define WIDGET_DATE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QGridLayout>
#include <QRadioButton>
#include <QCalendarWidget>
#include <QTimeEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QTreeWidget>
#include <QHeaderView>
#include "firstwindow.h"


class widget_date : public QWidget
{
    Q_OBJECT
    
public:
    explicit widget_date(FirstWindow * fw, QWidget *parent = 0);
    ~widget_date();

    QDateTime getDate();
    void setDate(QDateTime d);

    bool hasDate();
    
private:
    FirstWindow * FirstW;
    QWidget * abswidget;
    QCalendarWidget * calendar;
    QTimeEdit * time;
    QWidget * relwidget;
    QSpinBox * spin;
    QComboBox * unit;
    QComboBox * avapr;
    QTreeWidget * tree;
    int choix;
    QDateTime date;

public slots:
    void afficher_abs();
    void afficher_rel();
    void afficher_rien();
    void date_modifiee();
};

#endif // WIDGET_DATE_H
