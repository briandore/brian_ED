#ifndef NODO_H
#define NODO_H
#include <QApplication>
#include <QColor>
#include <QGraphicsItem>
#include <QFontMetricsF>
#include <QStyleOptionGraphicsItem>
#include <QPainter>
#include <QInputDialog>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>

// forward declaration .. importante notar que
// no esta include "enlace.h", el truco es hacerlo en el nodo.cpp
class Enlace;

class Nodo : public QGraphicsItem
{
 public:
    Nodo(QString text, int x, int y);
    ~Nodo();
    void setText(const QString &text);
    QString text() const;
    void setTextColor(const QColor &color);
    QColor textColor() const;
    void setOutlineColor(const QColor &color);
    QColor outlineColor() const;
    void setBackgroundColor(const QColor &color);
    QColor backgroundColor() const;

    // Metodos que permiten asociar un Enlace (arista) ya creada
    // a un nodo, o tambien des asociar (remover)
    void addLink(Enlace *link);
    void removeLink(Enlace *link);

    // Metodos importantes al implementar objetos heredados de
    // QGraphicsItem .. BoundingRec junto con Shape definen los
    // limites del objeto a pintar lo cual sirve despues para
    // detectar colisiones y obviamente Paint define la forma de como
    // se pintara ese objeto
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
        // Al darle doble clic a un nodo queremos que nos de la opcion
        // de poder cambiarle el texto
        void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
        QVariant itemChange(GraphicsItemChange change,
                                  const QVariant &value);
private:
        // Este metodo privado encapsula lo que requiere BoundingRect ..
        // En realidad se pudo haber hecho todo en boundingrect pero es para
        // tenerlo mas ordenado
        QRectF outlineRect() const;
        // La propiedad de curva en las esquinas del nodo
        int roundness(double size) const;
        // Cada nodo tiene un Qlist de Enlaces (aristas) conectadas a ese nodo
        QList<Enlace *> myLinks;
        QString myText;            // texto dentro del nodo
        QColor myTextColor;        // Color del texto
        QColor myBackgroundColor;  // Color de fondo del nodo
        QColor myOutlineColor;     // Color de las orillas

};

#endif // NODO_H
