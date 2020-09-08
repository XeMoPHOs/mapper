/*
 *    Copyright 2012, 2013 Thomas Schöps
 *    Copyright 2019, 2020 Kai Pastor
 *
 *    This file is part of OpenOrienteering.
 *
 *    OpenOrienteering is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    OpenOrienteering is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with OpenOrienteering.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef OPENORIENTEERING_STRETCH_MAP_DIALOG_H
#define OPENORIENTEERING_STRETCH_MAP_DIALOG_H

#include <functional>

#include <Qt>
#include <QtGlobal>
#include <QDialog>
#include <QObject>
#include <QString>

class QCheckBox;
class QDoubleSpinBox;
class QPushButton;
class QRadioButton;
class QWidget;

namespace OpenOrienteering {

class Map;


/**
 * Dialog for stretching or shrinking the whole map.
 */
class StretchMapDialog : public QDialog
{
Q_OBJECT
public:
	using StretchOp = std::function<void (Map&)>;
	
	/** Creates a new StretchMapDialog. */
	StretchMapDialog(const Map& map, double stretch_factor, QWidget* parent = nullptr, Qt::WindowFlags f = {});
	
	/** Performs the configured scaling on the given map. */
	void stretch(Map& map) const;
	
	/** Returns a scaling functor. */
	Q_REQUIRED_RESULT StretchOp makeStretch() const;
	
private slots:
	void updateWidgets();
	
private:
	QRadioButton* center_origin_radio;
	QRadioButton* center_georef_radio;
	QRadioButton* center_other_radio;
	QDoubleSpinBox* other_x_edit;
	QDoubleSpinBox* other_y_edit;
	
	QCheckBox* adjust_georeferencing_check;
	QCheckBox* adjust_templates_check;
	QPushButton* ok_button;
	
	const double stretch_factor;
};


}  // namespace OpenOrienteering

#endif
