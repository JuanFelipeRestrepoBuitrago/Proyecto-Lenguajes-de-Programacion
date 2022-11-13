#ifndef BOARD_H
#define BOARD_H

#include <QMainWindow>
#include <string>

using namespace std;

namespace Ui {
class Board;
}

class Board : public QMainWindow
{
    Q_OBJECT

public:
    explicit Board(QWidget *parent = nullptr);
    ~Board();
    void printBoard(string s[8][8]);
protected:
    void resizeEvent(QResizeEvent *e);

private slots:
    void on_yesButton_clicked();

    void on_noButton_clicked();

private:
    Ui::Board *ui;
    map<string, QIcon> icons;
};

#endif // BOARD_H
