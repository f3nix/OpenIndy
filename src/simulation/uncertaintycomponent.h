#ifndef UNCERTAINTYCOMPONENT_H
#define UNCERTAINTYCOMPONENT_H

#include <QStringList>
#include <unitconverter.h>

/*!
 * \brief The UncertaintyComponent class
 *
 *  object to describe an uncertainty component of a
 *  simulation model
 */
class UncertaintyComponent
{
public:
    UncertaintyComponent();

    double value; //magnitude of the error
    double uncertainty; // uncertainty of the error
    UnitConverter::unitType errorUnit; // unit type of the error (metric, angular, ...)
    UnitConverter::dimensionType errorDimension; // dimension of the unit (mm, m ,...)

    QStringList distributions; //distributions in which the error could be determined at random

};

#endif // UNCERTAINTYCOMPONENT_H
