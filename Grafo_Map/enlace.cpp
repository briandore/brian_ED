#include "enlace.h"
#include "nodo.h"

// El constructor de enlace por fuerza debe recibir el nodo origen y destino
Enlace::Enlace(Nodo *nodo_origen, Nodo *nodo_destino, QString peso)
{
    this->nodo_origen = nodo_origen;
    this->nodo_destino = nodo_destino;
    this->peso = peso;
    // llamar el metodo de addlink para asociar este enlace a la lista
    // MyLinks de cada nodo
       nodo_origen->addLink(this);
       nodo_destino->addLink(this);

    // Las aristas son seleccionables (para poder borrarlas)
       setFlags(QGraphicsItem::ItemIsSelectable);

       // este valor define que aparecen atras o delante de otros objetos
       // la regla es que los valores menores aparecen atras
       // Se le asigna -1 para que aparezcan detras de los nodos, ya que los
       // nodos por omision empiezan en 0, este valor es el que debe cambiarse
       // para traer al frente o mandar atras a un objeto
       setZValue(-1);
       // Definir el color de la linea
       setColor(Qt::darkRed);
       this->updatePosicion();
}

Enlace::~Enlace()
{
    // Cuando un enlace se destruye, se encarga de llamar
    // al metodo removeLink de cada nodo para que cada nodo quite
    // y remueva de su lista de MyLinks a esta arista.
    nodo_origen->removeLink(this);
    nodo_destino->removeLink(this);
    qDebug() << "Destructor de Enlace";
}

void Enlace::setColor(const QColor &color)
{
    setPen(QPen(color, 1.0));
}

QColor Enlace::color() const
{
    return pen().color();
}

void Enlace::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                 QWidget *widget)
{
    //Dibujar la linea del centro de un nodo al otro
    // en color rojo

    painter->setPen(Qt::red);
    painter->setBrush(Qt::red);

    if (option->state & QStyle::State_Selected) {
        painter->setPen(Qt::blue);
        painter->setBrush(Qt::blue);

    }
    QLineF centerLine(this->getNodoOrigen()->pos(),
                      this->getNodoDestino()->pos());
   int x = abs(this->getNodoDestino()->x()-this->getNodoOrigen()->x())/2;
   int y =abs(this->getNodoDestino()->y()-this->getNodoOrigen()->y())/2 ;

   QPoint p;
   p.setX(x);   p.setY(y);
    this->setLine(centerLine);
    // o se pudo usar painter->drawLine(centerLine);
    painter->drawLine(this->line());
    painter->drawText(p,peso);
    qDebug() << "Painting de Enlace";
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    this->setZValue(-1);

}

void Enlace::updatePosicion()
{
    // Este metodo actualiza la posicion de la linea
    //
    setLine(QLineF(this->nodo_origen->pos(), this->nodo_destino->pos()));

}

