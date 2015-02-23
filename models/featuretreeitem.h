#ifndef FEATURETREEITEM_H
#define FEATURETREEITEM_H

#include <QObject>
#include <QPointer>

#include "featurewrapper.h"
#include "observation.h"
#include "reading.h"
#include "configuration.h"

//! class that holds an item in a featetreeviewmodel
class FeatureTreeItem : public QObject
{
    Q_OBJECT

public:
    FeatureTreeItem(QVariant display);
    ~FeatureTreeItem();

    bool getIsHeader();
    bool getIsFeature();
    void setFeature(FeatureWrapper *feature);
    FeatureWrapper *getFeature();
    bool getIsObservation();
    void setObservation(Observation *observation);
    Observation* getObservation();
    bool getIsReading();
    void setReading(Reading *reading);
    Reading *getReading();
    Configuration::ElementTypes getElementType();

    void setHasObservation(bool hasObservation);
    bool getHasObservation();
    void setHasReadingCartesian(bool hasReadingCartesian);
    bool getHasReadingCartesian();
    void setHasReadingPolar(bool hasReadingPolar);
    bool getHasReadingPolar();
    void setHasReadingDirection(bool hasReadingDirection);
    bool getHasReadingDirection();
    void setHasReadingDistance(bool hasReadingDistance);
    bool getHasReadingDistance();
    void setHasReadingLevel(bool hasReadingLevel);
    bool getHasReadingLevel();
    void setHasReadingTemperature(bool hasReadingTemperature);
    bool getHasReadingTemperature();

    void appendChild(QPointer<FeatureTreeItem> child);
    QPointer<FeatureTreeItem> getChild(int index);
    void removeChild(int index);
    void deleteChildren();
    int getChildCount();
    void setIndex(int index);
    int getIndex();
    bool hasParent();
    void setParent(QPointer<FeatureTreeItem> parent);
    QPointer<FeatureTreeItem> getParent();

    QVariant getDisplayValue();

private:
    void setIsHeader();
    void setIsFeature();
    void setIsObservation();
    void setIsReading();

    bool isHeader;
    bool isFeature;
    FeatureWrapper *feature;
    bool isObservation;
    Observation *observation;
    bool isReading;
    Reading *reading;

    bool hasObservation;
    bool hasDistanceReading;
    bool hasDirectionReading;
    bool hasCartesianReading;
    bool hasPolarReading;
    bool hasLevelReading;
    bool hasTemperatureReading;

    QList< QPointer<FeatureTreeItem> > children;
    QPointer<FeatureTreeItem> parent;

    int index;
    int childCount;

    QVariant displayValue;

};

#endif // FEATURETREEITEM_H
