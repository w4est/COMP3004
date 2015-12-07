#ifndef RESULTSWINDOW_H
#define RESULTSWINDOW_H

#include <QWidget>
#include <QListWidgetItem>
#include <QScrollBar>
#include <QVBoxLayout>
#include <vector>
#include "resultframe.h"
#include "ProfileEntity.h"

#define vectorIntern std::vector<ProfileEntity>
#define vectorTotal std::vector<std::vector<ProfileEntity>>

namespace Ui {
class ResultsWindow;
}

class ResultsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ResultsWindow(vectorTotal, int groupSize, string projectName,QWidget *parent = 0, int _x = 150, int _y = 50);
    ~ResultsWindow();

private:
    Ui::ResultsWindow *ui;

    QVBoxLayout *layout, *scrollBoxLayout;
    QWidget *widget;
    std::vector<ResultFrame*> frameList;

    int maxSize;

    void buildSubLists(vectorTotal);
    QWidget* buildResultFrame(vectorIntern, int);
};

#endif // RESULTSWINDOW_H
