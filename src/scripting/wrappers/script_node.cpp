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

#include "script_node.hpp"
#include "script_edge.hpp"
#include "script_graph.hpp"

Script_Node::Script_Node(Node *n, Script_Graph *graph):
    QObject(graph),
    m_wrapped_node(n), graph(graph), m_style(m_wrapped_node->style())
{
    connect(&m_style,SIGNAL(changed(Node_Style,Node_Style)),
            SLOT(emit_style_changed(Node_Style,Node_Style)));
}

Script_Node::Script_Node(const Script_Node &o)
    : QObject(o.parent()),
      m_wrapped_node(o.m_wrapped_node), graph(o.graph), m_style(m_wrapped_node->style())
{
    connect(&m_style,SIGNAL(changed(Node_Style,Node_Style)),
            SLOT(emit_style_changed(Node_Style,Node_Style)));
}

Script_Point Script_Node::pos() const
{
    return m_wrapped_node->pos();
}

void Script_Node::set_pos(Script_Point p)
{
    emit moved(p);
    m_wrapped_node->setPos(p);
}

void Script_Node::set_x(double x)
{
    emit moved(Script_Point(x,y()));
}

void Script_Node::set_y(double y)
{
    emit moved(Script_Point(x(),y));
}

bool Script_Node::selected() const
{
    return m_wrapped_node->isSelected();
}

void Script_Node::set_selected(bool b)
{
    m_wrapped_node->setSelected(b);
}

QList<Script_Edge*> Script_Node::edges() const
{
    QList<Script_Edge*> l;
    foreach(Edge* e, m_wrapped_node->edges())
        l << graph->script_edge(e);
    return l;
}

QObjectList Script_Node::edges_object() const
{
    QObjectList l;
    foreach(Edge* e, m_wrapped_node->edges())
        l << graph->script_edge(e);
    return l;
}

QString Script_Node::toString() const
{
    return "[node "+pos().toString()+"]";
}

bool Script_Node::has_edge_to(Script_Node *n) const
{
    return m_wrapped_node->has_edge_to(n->m_wrapped_node);
}


QObject* Script_Node::edge_to(Script_Node *n) const
{
    return graph->script_edge(m_wrapped_node->edge_to(n->m_wrapped_node));
}

bool Script_Node::compare(Script_Node *n) const
{
    return n->m_wrapped_node == m_wrapped_node;
}

void Script_Node::set_style(QObject *object)
{

    Script_Node_Style* style = qobject_cast<Script_Node_Style*>(object);
    if ( style )
        m_style.from_style(style->style());
}


void Script_Node::emit_style_changed(Node_Style before, Node_Style after)
{
    emit style_changed(m_wrapped_node,before,after);
}
