#include "enlace.h"
#include "nodo.h"

Nodo::Nodo(QString text, int x, int y)
{
    myTextColor = Qt::darkGreen;
    myOutlineColor = Qt::darkBlue;
    myBackgroundColor = Qt::white;
    // Una vez seteadas las propiedades de color
    // Hay que definir que flags (opciones) estan habilitadas para Nodo
    // En este caso le decimos que se va a poder mover y que es seleccionable
    this->setText(text);
    this->setPos(x,y);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges,true);

}
Nodo::~Nodo()

{
    // La destruccion de un nodo, repasa toda su lista de Enlaces(Aristas)
    // y les hace Delete, pero NO removemos la referencia de la lista
    // eso lo hara el destructor de cada enlace como el metodo removeLink
    // Por SIDE EFFECT del destructor de Enlace
    foreach (Enlace *link, myLinks)
           delete link;

}

void Nodo::setText(const QString &text)
{
    // Se debe llamar este metodo siempre y cuando el nodo vaya a cambiar
    // de tama�o (geometria), puesto que el nodo se ajustara al texto
    prepareGeometryChange();
    myText = text;
    update();
}

QString Nodo::text() const
{
    return this->myText;
}

void Nodo::setTextColor(const QColor &color)
{
    myTextColor = color;
    update();
}

QColor Nodo::textColor() const
{
     return this->myTextColor;

}

void Nodo::setOutlineColor(const QColor &color)

{
    myOutlineColor = color;
    update();
}

QColor Nodo::outlineColor() const
{
    return this->myOutlineColor;
}

void Nodo::setBackgroundColor(const QColor &color)
{
    myBackgroundColor = color;
    update();
}

QColor Nodo::backgroundColor() const
{
    return this->myBackgroundColor;
}

void Nodo::addLink(Enlace *link)
{
    // Solo agrega a la lista(Qlist) de links el enlace que viene de parametro
    // Este metodo lo usa el constructor de Enlace
    myLinks.append(link);
}

void Nodo::removeLink(Enlace *link)
{
   // Busca el link a borrar
    int val= myLinks.indexOf(link,0);
    if (val!=-1)
           myLinks.removeAt(val);


}
// Este metodo privado define basicamente el limite
// del nodo, el contorno
QRectF Nodo::outlineRect() const
{
    const int Padding = 20; // Se puede jugar con esta variable para el espaciado
                            // Pueden probar valores diferentes para ver que pasa???

    // esto es algo interesante, qApp es una referencia(apuntador) a toda
    // la aplicacion actual (la instancia en curso)
    // por omision QT la define, y de ella se pueden sacar varias caracteristicas

    QFontMetricsF metrics = qApp->font(); // Obtiene el font default asignado
    QRectF rect = metrics.boundingRect(myText); // Obtenga el rectangulo que cubre
                                                // el texto que quiero dibujar de acuerdo
                                                // a ese font

    // Ajuste ese rectangulo para dejarle espacio a los lados del texto
    rect.adjust(-Padding, -Padding, +Padding, +Padding);

    // Que efecto tiene esta linea ???, probar comentarla y probar para que
    // deduzcan que efecto tiene ?
    rect.translate(-rect.center());
    return rect;
}

// Este metodo es virtual puro por ende siempre debe implementarse
// Define el contorno del objeto
QRectF Nodo::boundingRect() const
{

    const int Margin = 1;
    // Solo hacemos llamada al privado que nosotros definimos arriba
    // y aun asi le agregamos otro peque�o margen
    return outlineRect().adjusted(-Margin, -Margin, +Margin, +Margin);
}

// Este metodo es virtual, no puro, pero es recomendable implementarlo
// Define un PATH de la figura que se esta pintando, ideal para figuras
// irregulares, aun asi tambien necesario para las otras figuras
QPainterPath Nodo::shape() const
{
    QRectF rect = outlineRect(); // Llama al metodo privado que ya implementamos

    QPainterPath path; // Declaramos el path
    // Agregamos al Path el rectangulo pero de una sola vez le definimos que sea
    // de esquinas redondeadas
    path.addEllipse(rect);
    return path;
}


// Este metodo pinta el nodo como queremos que se vea
void Nodo::paint(QPainter *painter,
                 const QStyleOptionGraphicsItem *option,
                 QWidget * /* widget */)
{
    // Definimos la pluma con el color asignado
    QPen pen(myOutlineColor);
    // este if es interesante, define si el nodo esta seleccionado
    // para que el contorno del nodo (linea) se pinte de forma punteada
    // y no solida
    if (option->state & QStyle::State_Selected) {
        pen.setStyle(Qt::DotLine);
        pen.setWidth(2);
    }

    painter->setPen(pen);

    // Aca revisa colisiones contra TODOS los items incluyendo las
    // aristas y no es lo correcto, deberia ser solo para nodos
    QList<QGraphicsItem *> colisiones =
            this->scene()->collidingItems(this,Qt::IntersectsItemShape);

    if  (colisiones.count()==0)
         painter->setBrush(myBackgroundColor);
    else
    {


      foreach (QGraphicsItem *GI,colisiones){
         if(dynamic_cast<Nodo*>(GI)){
                GI->update();
                painter->setBrush(Qt::red);
       }

      }

    }

    // Volvemos a llamar al metodo privado que nos retorna el
    // rectangulo de contorno del nodo
    QRectF rect = outlineRect();
    // Lo dibujamos
    painter->drawEllipse(rect);

    // Seteamos el color del texto y lo dibujamos dentro del rectangulo
    painter->setPen(myTextColor);
    painter->drawText(rect, Qt::AlignCenter, myText);
    this->setZValue(2);
}

// Cuando hacemos doble click al nodo, nos levanta un peque�o dialogo
// para poder cambiar el texto y nos lo regrese, por omision le pasamos
// de padre, el widget que genero el evento
void Nodo::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    QString text = QInputDialog::getText(event->widget(),
                           "Editar Texto", "Nuevo texto:",
                           QLineEdit::Normal, myText);
    if (!text.isEmpty()) // Si no esta vacio entonces setearlo
        this->setText(text);
}

// Calculo para el roundeness, probar los valores para ver el efecto
int Nodo::roundness(double size) const
{
    const int Diameter = 12;
    return 100 * Diameter / int(size);
}

QVariant Nodo::itemChange(GraphicsItemChange change,
                          const QVariant &value)
{
     qDebug() << "Updating enlance" << change;
    if (change == ItemPositionHasChanged) {
        foreach (Enlace *link, myLinks)
        {
            link->updatePosicion();

        }
    }
    return QGraphicsItem::itemChange(change, value);
}




