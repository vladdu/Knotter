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
#include <QApplication>
#include "main_window.hpp"
#include "resource_manager.hpp"
#include "edge_type.hpp"
#include "command_line.hpp"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    resource_manager().register_cusp_shape(new Cusp_Pointed);
    resource_manager().register_cusp_shape(new Cusp_Rounded);
    resource_manager().register_cusp_shape(new Cusp_Polygonal);
    resource_manager().register_cusp_shape(new Cusp_Ogee);

    resource_manager().register_edge_type(new Edge_Normal);
    resource_manager().register_edge_type(new Edge_Inverted);
    resource_manager().register_edge_type(new Edge_Wall);
    resource_manager().register_edge_type(new Edge_Hole);

    resource_manager().initialize();

    Command_Line cmd(argc, argv);

    if ( !cmd.load_ui() )
        return 0;


    Main_Window mw;
    mw.show();

    foreach(QString s, cmd.files())
        mw.create_tab(s);

    return a.exec();
}
