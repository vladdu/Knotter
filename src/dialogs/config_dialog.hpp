/**

\file

\author Mattia Basaglia

\section License
This file is part of Knotter.

Copyright (C) 2012  Mattia Basaglia

Knotter is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Knotter is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/
#ifndef CONFIG_DIALOG_HPP
#define CONFIG_DIALOG_HPP

#include "ui_config_dialog.h"

class config_dialog : public QDialog, private Ui::config_dialog
{
        Q_OBJECT

        friend class Knot_Window;
    public:
        explicit config_dialog(QWidget *parent = 0);

        void set_icon_size ( QSize size );
        QSize get_icon_size() const;

        Qt::ToolButtonStyle get_tool_button_style() const;
        void set_tool_button_style ( Qt::ToolButtonStyle style );
};

#endif // CONFIG_DIALOG_HPP