/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtQml module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or (at your option) the GNU General
** Public license version 3 or any later version approved by the KDE Free
** Qt Foundation. The licenses are as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-2.0.html and
** https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/
#ifndef QV4COMPILER_P_H
#define QV4COMPILER_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtCore/qstring.h>
#include "qv4jsir_p.h"

QT_BEGIN_NAMESPACE

class QQmlPropertyData;

namespace QV4 {

namespace CompiledData {
struct Unit;
struct Lookup;
struct RegExp;
struct JSClassMember;
}

namespace Compiler {

struct Q_QML_PRIVATE_EXPORT StringTableGenerator {
    StringTableGenerator();

    int registerString(const QString &str);
    int getStringId(const QString &string) const;
    QString stringForIndex(int index) const { return strings.at(index); }
    uint stringCount() const { return strings.size(); }

    uint sizeOfTableAndData() const { return stringDataSize + strings.count() * sizeof(uint); }

    void clear();

    void serialize(CompiledData::Unit *unit);

private:
    QHash<QString, int> stringToId;
    QStringList strings;
    uint stringDataSize;
};

struct Q_QML_PRIVATE_EXPORT JSUnitGenerator {
    JSUnitGenerator(IR::Module *module);

    int registerString(const QString &str) { return stringTable.registerString(str); }
    int getStringId(const QString &string) const { return stringTable.getStringId(string); }
    QString stringForIndex(int index) const { return stringTable.stringForIndex(index); }

    uint registerGetterLookup(const QString &name);
    uint registerSetterLookup(const QString &name);
    uint registerGlobalGetterLookup(const QString &name);
    uint registerIndexedGetterLookup();
    uint registerIndexedSetterLookup();

    int registerRegExp(IR::RegExp *regexp);

    int registerConstant(ReturnedValue v);

    int registerJSClass(int count, IR::ExprList *args);

    enum GeneratorOption {
        GenerateWithStringTable,
        GenerateWithoutStringTable
    };

    QV4::CompiledData::Unit *generateUnit(GeneratorOption option = GenerateWithStringTable);
    // Returns bytes written
    int writeFunction(char *f, int index, IR::Function *irFunction);

    StringTableGenerator stringTable;
private:
    IR::Module *irModule;

    QHash<IR::Function *, uint> functionOffsets;
    QList<CompiledData::Lookup> lookups;
    QVector<CompiledData::RegExp> regexps;
    QVector<ReturnedValue> constants;
    QList<QList<CompiledData::JSClassMember> > jsClasses;
    uint jsClassDataSize;
};

}

}

QT_END_NAMESPACE

#endif
