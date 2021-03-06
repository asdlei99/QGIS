/***************************************************************************
                             qgsnumericformat.cpp
                             -------------------
    begin                : January 2020
    copyright            : (C) 2020 by Nyall Dawson
    email                : nyall dot dawson at gmail dot com

 ***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "qgsnumericformat.h"
#include "qgsxmlutils.h"

#include <QLocale>

QgsNumericFormatContext::QgsNumericFormatContext()
{
  QLocale l;
  mThousandsSep = l.groupSeparator();
  mDecimalSep = l.decimalPoint();
  mPercent = l.percent();
  mZeroDigit = l.zeroDigit();
  mNegativeSign = l.negativeSign();
  mPositiveSign = l.positiveSign();
  mExponential = l.exponential();
}

int QgsNumericFormat::sortKey()
{
  return 100;
}

double QgsNumericFormat::suggestSampleValue() const
{
  return 1234.56789123456;
}

void QgsNumericFormat::writeXml( QDomElement &element, QDomDocument &document, const QgsReadWriteContext &context ) const
{
  const QVariantMap config = configuration( context );
  QDomElement configElement = QgsXmlUtils::writeVariant( config, document );
  element.appendChild( configElement );
  element.setAttribute( QStringLiteral( "id" ), id() );
}

