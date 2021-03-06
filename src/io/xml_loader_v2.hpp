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

#ifndef XML_LOADER_V2_HPP
#define XML_LOADER_V2_HPP

#include <QDomDocument>
#include "graph.hpp"
#include <QStack>

/**
 *  \brief Load legacy files
 *
 *  Knot XML files v2 are for Knotter 0.5 - 0.8
 *
 *  This will also load knot v1 files ( generated by Knotter 0.1 - 0.4 ) with
 *  minor style information losses
 */
class XML_Loader_v2
{

private:
    static const int supported_version = 2;

    QDomDocument xml;
    QStack<QDomElement> current_elements;
    int version;
    QMap<QString,Node*> node_ids;

public:

    bool load ( QIODevice* input );

    void get_graph ( Graph &kv );

    Node* register_node ( QString id );

    bool enter( QString name);

    QPen get_pen ( QString name, QPen default_value );

    Node_Style get_cusp ( QString name );

    void leave();

    static bool supports_version(int v) { return v > 0 && v <= supported_version; }

};
#endif // XML_LOADER_V2_HPP
