#ifndef FIRSTWINDOW_H
#define FIRSTWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QTreeWidget>
#include <QIcon>

#include <iostream>

#include "widget_infos.h"
#include "tache.h"

using namespace std;

class FirstWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit FirstWindow(QWidget *parent = 0);
    ~FirstWindow();

    // l'arborescence devient un parametre global pour y acceder dans les slots
    QTreeWidget * arbo;
    // l'objet courant dans l'arbre
    QTreeWidgetItem * currentItem;

    //icone "ajouter une sous-tache"
    QIcon * plusIcon;
    // icone supprimer la tache
    QIcon * supprIcon;

    // tache a la racine de toutes les taches courantes
    Tache * racine;

    // effacer les icones
    void eraseIcons(QTreeWidgetItem * item);
    
private:
    //bool drawerOpened;
    QGridLayout * mainLayout;

public slots:
    //void openDrawer();
    //void closeDrawer();
    void popup(); // d�clench� si bouton "Nouveau"
    void popup(QTreeWidgetItem* i, int n); // d�clench� si clic sur le "+" dans l'arbo
    void resetDisable(); // la fenetre principale revient active apres le popup Ajout
    void tacheChecked(QTreeWidgetItem* item,int n); // action quand la tache est check�e
    void showIcons(QTreeWidgetItem* item,int n); // affiche les icones "plus" et "supprimer" quand on passe la souris
    void deleteItem(); // supprimer une tache
    void sauvegarderSous();
};

#endif // FIRSTWINDOW_H
