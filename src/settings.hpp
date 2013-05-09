/**

\file

\author Mattia Basaglia

\section License
This file is part of Knotter.

Copyright (C) 2012-2013  Mattia Basaglia

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
#ifndef SETTINGS_HPP
#define SETTINGS_HPP
#include <QObject>
#include <QMainWindow>
#include "string_toolbar.hpp"
#include <QMetaType>

class Settings : public QObject
{
    Q_OBJECT
    Q_ENUMS(Qt::ToolButtonStyle)

public:
    //typedef Qt::ToolButtonStyle ToolButtonStyle;

private:
    QString                 config_version; ///< Version of the setting file

    int                     m_icon_size;
    // language
    // performace
    // recent files
    // style
    // grid

    QList<String_Toolbar>   toolbars;
    bool                    m_save_ui; ///< Whether the GUI state must be loaded between sessions
    QByteArray              m_window_state;
    QByteArray              m_window_geometry;
    Qt::ToolButtonStyle     tool_button_style;
    bool                    m_graph_cache;
    bool                    m_fluid_refresh;
    QStringList             m_recent_files;
    int                     m_max_recent_files;

private:
    Settings();
    friend class Resource_Manager;

public:

    void load_config();
    void save_config();

    void initialize_window(QMainWindow*);
    void save_window(QMainWindow*);

    QString version() const;
    bool least_version(int maj,int min) const;
    bool current_version() const;

    void icon_size(int sz);
    int icon_size() const { return m_icon_size; }

    Qt::ToolButtonStyle button_style() const { return tool_button_style; }

    void button_style(Qt::ToolButtonStyle);

    bool graph_cache() const { return m_graph_cache; }
    bool fluid_refresh() const { return m_fluid_refresh; }

    void set_graph_cache(bool enable) { m_graph_cache = enable; }
    void set_fluid_refresh(bool enable) { m_fluid_refresh = enable; }

    bool save_ui() const { return m_save_ui; }
    void set_save_ui(bool save) { m_save_ui = save; }

    QStringList recent_files() const { return m_recent_files; }

    /**
     *  \brief Push a file name to the top of the recent files list
     *
     *  If the file is already in the list, it is moved to the top.
     */
    void add_recent_file(QString file_name);

    int max_recent_files() const { return m_max_recent_files; }
    void set_max_recent_files(int max);
    void clear_recent_files();

signals:
    void icon_size_changed(int);
    void tool_button_style_changed(Qt::ToolButtonStyle);
    void language_changed(/*todo*/);

};

Q_DECLARE_METATYPE(Qt::ToolButtonStyle)

#endif // SETTINGS_HPP