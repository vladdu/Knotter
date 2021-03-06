/**
  
\file

\author Mattia Basaglia

\section License
This file is part of Knotter.

Copyright (C) 2012-2014  Mattia Basaglia

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

#ifndef DOCK_SCRIPT_LOG_HPP
#define DOCK_SCRIPT_LOG_HPP

#include "ui_dock_script_log.h"
#include "script_window.hpp"
#include "plugin.hpp"

class Dock_Script_Log : public QDockWidget, private Ui::Dock_Script_Log
{
    Q_OBJECT

    Main_Window*  target_window;///< Script object window wrapee
    bool          local_run;    ///< If is currently being executed code from the console itself
    QString       filename;     ///< Name of the open file
    Plugin*       plugin;       ///< The loaded plugin (if any)
public:
    explicit Dock_Script_Log(Main_Window* mw);

    void set_tool_button_style(Qt::ToolButtonStyle style);

    void setVisible(bool visible);

public slots:
    void open_script_file(QString new_file);
    void load_plugin(Plugin* p);

protected:
    void changeEvent(QEvent *e);

private:
    static QString escape_html(QString s);

    void save_file(QString file_name);


private slots:
    void unload_plugin();
    void script_error(QString file,int line,QString msg, QStringList trace = QStringList());
    void script_output(QString text);
    void run_script(const QString &source, QString file_name, int line_number, bool echo);
    void on_button_run_clicked();
    void editor_resized(QSize sz);
    void new_file();
    void open_file();
    void save_file();
    void save_file_as();
    void toggle_dialog(bool dialog);
    void open_external_editor();
    /**
     * @brief Save file and reload plugin sources
     */
    void deploy_plugin();
    void on_text_output_anchorClicked(const QUrl &arg1);
};

#endif // DOCK_SCRIPT_LOG_HPP
