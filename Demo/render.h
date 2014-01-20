#ifndef RENDER_H
#define RENDER_H

#include <QWidget>
#include <QGraphicsScene>
class QGraphicsView;
class QGraphicsItemGroup;
class QTimer;
class MapSquare;
class Level;
class Unit;
class Obstacle;
class QTimer;
class GameView;
class Render : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit Render(GameView *_view, Level *level, QWidget *parent = 0);
    ~Render();


    void destroy();
signals:
    void moveUnits();
    void updateScore(QString score);
    void updateUnitCount(QString count);
    void endGame(QString score, bool victory);
public slots:
    void setAbilitySlot(int id);
    void unitUse(Unit *unit);
    void unitDie(Unit *unit);
    void unitWin(Unit *unit);
    void switchNext();
private slots:
    void gameTimer();
    void startGame();
    void toggleGame(bool _play);

private:
    //QGraphicsItemGroup *units;
    MapSquare* generatePath(int currentX, int currentY, Level *level);
    Level *renderedLevel;
    GameView *view;
    QList<Unit*> *listUnit;
    Unit *mainUnit;
    QTimer *mainTimer;
    QTimer *startTimer;
    int startCountDown;
    void keyPressEvent(QKeyEvent *event);
    int xFromOrientation(int x, int orientation);
    int yFromOrientation(int y, int orientation);

    //Configuration partie
    int unitCount;
    int unitDead;
    int unitUsed;
    int unitToInit;
    int unitWon;

    int winUnits;
    bool play;


    int score; //Score = (total-minima / survivants) *1000 - 50*deces
              //Score initial

    //Tableaux des images des composants
    QList<QPixmap*> *unitImages;
    QList<QPixmap*> *boostImages;
    QList<QPixmap*> *caillotImages;
    QList<QPixmap*> *chuteImages;
    QList<QPixmap*> *deviationImages;
    QList<QPixmap*> *bacterieImages;
    QList<QPixmap*> *unitsImages;


    QList<Obstacle*> *listObstacles;

    QList<MapSquare*> *listSquares;

    void calculateScore();
    void loadImages();
    void initializeGame();
    void deleteImages(QList<QPixmap*> *list);
    void deleteUnits(QList<Unit *> *list);
    MapSquare *checkSquare(int x, int y);
};

#endif // RENDER_H
