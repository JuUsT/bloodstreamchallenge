#include "menuradiobutton.h"
#include <QPainter>

#include <QDebug>

MenuRadioButton::MenuRadioButton(QRectF rect, bool _checked)
{
    this->rect = rect;
    this->checked = _checked;
}

MenuRadioButton::~MenuRadioButton()
{

}

QRectF MenuRadioButton::boundingRect() const
{
    return rect;
}

void MenuRadioButton::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    if(checked)
        painter->drawPixmap(rect.toRect(), QPixmap(":/menu/ressources/img/menu/Combo_on.png"));
    else
        painter->drawPixmap(rect.toRect(), QPixmap(":/menu/ressources/img/menu/Combo_off.png"));
}

void MenuRadioButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mousePressEvent(event);
    qDebug() << "signal emit";
    emit checkStateChanged(this);
}

void MenuRadioButton::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}
bool MenuRadioButton::getChecked() const
{
    return checked;
}

void MenuRadioButton::setChecked(bool value)
{
    checked = value;
}
