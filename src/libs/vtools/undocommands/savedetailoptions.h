/************************************************************************
 **
 **  @file   savedetailoptions.h
 **  @author Roman Telezhynskyi <dismine(at)gmail.com>
 **  @date   12 6, 2014
 **
 **  @brief
 **  @copyright
 **  This source code is part of the Valentine project, a pattern making
 **  program, whose allow create and modeling patterns of clothing.
 **  Copyright (C) 2013-2015 Valentina project
 **  <https://bitbucket.org/dismine/valentina> All Rights Reserved.
 **
 **  Valentina is free software: you can redistribute it and/or modify
 **  it under the terms of the GNU General Public License as published by
 **  the Free Software Foundation, either version 3 of the License, or
 **  (at your option) any later version.
 **
 **  Valentina is distributed in the hope that it will be useful,
 **  but WITHOUT ANY WARRANTY; without even the implied warranty of
 **  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 **  GNU General Public License for more details.
 **
 **  You should have received a copy of the GNU General Public License
 **  along with Valentina.  If not, see <http://www.gnu.org/licenses/>.
 **
 *************************************************************************/

#ifndef SAVEDETAILOPTIONS_H
#define SAVEDETAILOPTIONS_H

#include <qcompilerdetection.h>
#include <QMetaObject>
#include <QObject>
#include <QString>
#include <QtGlobal>

#include "../tools/vtooldetail.h"
#include "vdetail.h"
#include "vundocommand.h"

class QDomElement;
class QGraphicsScene;
class QUndoCommand;
class VAbstractPattern;

class SaveDetailOptions : public VUndoCommand
{
    Q_OBJECT
public:
    SaveDetailOptions(const VDetail &oldDet, const VDetail &newDet, VAbstractPattern *doc, const quint32 &id,
                      QGraphicsScene *scene, QUndoCommand *parent = 0);
    virtual ~SaveDetailOptions() Q_DECL_OVERRIDE;
    virtual void undo() Q_DECL_OVERRIDE;
    virtual void redo() Q_DECL_OVERRIDE;
    virtual bool mergeWith(const QUndoCommand *command) Q_DECL_OVERRIDE;
    virtual int  id() const Q_DECL_OVERRIDE;
    quint32      getDetId() const;
    VDetail      getNewDet() const;
private:
    Q_DISABLE_COPY(SaveDetailOptions)
    const VDetail oldDet;
    VDetail       newDet;
    QGraphicsScene *scene;
    void         SaveDet(QDomElement &domElement, const VDetail &det);
    void         SavePatternPieceData(QDomElement &domElement, const VDetail &det);
    void         SavePatternInfo(QDomElement &domElement, const VDetail &det);
    void         SaveGrainline(QDomElement &domElement, const VDetail &det);
};

//---------------------------------------------------------------------------------------------------------------------
inline quint32 SaveDetailOptions::getDetId() const
{
    return nodeId;
}

//---------------------------------------------------------------------------------------------------------------------
inline VDetail SaveDetailOptions::getNewDet() const
{
    return newDet;
}

#endif // SAVEDETAILOPTIONS_H
