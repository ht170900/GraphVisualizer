#ifndef GRAPHVISUALIZER_H
#define GRAPHVISUALIZER_H

#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>

QT_BEGIN_NAMESPACE
namespace Ui { class GraphVisualizer; }
QT_END_NAMESPACE

class GraphVisualizer : public QMainWindow
{
    Q_OBJECT

public:
    GraphVisualizer(QWidget *parent = nullptr);
    ~GraphVisualizer();

private slots:
    void handleBrowseClicked();

private:
    Ui::GraphVisualizer *ui;
    void loadCSVAndPlot(const QString &filePath);
};

#endif
