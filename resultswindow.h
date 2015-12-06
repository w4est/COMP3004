#ifndef RESULTSWINDOW_H
#define RESULTSWINDOW_H

#include <QWidget>
#include <QListWidgetItem>
#include <QScrollBar>
#include <QVBoxLayout>
#include <vector>
#include "resultframe.h"

#define vectorIntern int
#define vectorTotal int

namespace Ui {
class ResultsWindow;
}

class ResultsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ResultsWindow(vectorTotal, QWidget *parent = 0, int _x = 150, int _y = 50);
    ~ResultsWindow();

private:
    Ui::ResultsWindow *ui;

    QVBoxLayout *layout, *scrollBoxLayout;
    QWidget *widget;
    std::vector<ResultFrame*> frameList;

    void buildSubLists(vectorTotal);
    QWidget* buildResultFrame(vectorIntern);
};

#endif // RESULTSWINDOW_H
