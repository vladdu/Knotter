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
#ifndef EDGE_HPP
#define EDGE_HPP

#include <QObject>
#include "node.hpp"

class Edge : public QObject
{
    Q_OBJECT

private:
    Node* v1;
    Node* v2;

public:
    explicit Edge(Node* v1, Node* v2, QObject *parent = 0);

    /// Whether node is one of its vetices
    bool is_vertex ( const Node* node ) const
    {
        return node == v1 or node == v2;
    }


    Node* vertex1() const
    {
        return v1;
    }

    Node* vertex2() const
    {
        return v2;
    }

    /**
     * Get other end node
     *
     * \pre n = vertex1 or n = vertex2
     *
     * Return other node or NULL on failure
     */
    Node* other(const Node* n) const
    {
        return n == v1 ? v2 : ( n == v2 ? v1 : NULL );
    }

public slots:
    /**
     *  Make vertices unaware of the edge
     *
     *  Removes this edge from the list of edges of both vertices
     */
    void detach();

    /**
     *  Make vertices aware of the edge
     *
     *  Add this edge to the list of edges of both vertices
     */
    void attach();
    
};

#endif // EDGE_HPP
