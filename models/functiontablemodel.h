#ifndef FUNCTIONTABLEMODEL_H
#define FUNCTIONTABLEMODEL_H

#include <QAbstractTableModel>
#include <QObject>
#include <QPointer>
#include <QList>

#include "oijob.h"
#include "types.h"
#include "util.h"
#include "systemdbmanager.h"

/*!
 * \brief The FunctionTableModel class
 */
class FunctionTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit FunctionTableModel(QObject *parent = 0);

    //########################################
    //override methods of abstract table model
    //########################################

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    //######################################
    //get or set currently available plugins
    //######################################

    const QList<sdb::Plugin> &getPlugins() const;
    void setPlugins(const QList<sdb::Plugin> &plugins);

private slots:

    //###########################################
    //update the model when job state has changed
    //###########################################

    void updateModel();

private:

    void connectJob();
    void disconnectJob();

private:

    //###########################
    //currently available plugins
    //###########################

    QList<sdb::Plugin> plugins;
    
};

#endif // FUNCTIONTABLEMODEL_H
