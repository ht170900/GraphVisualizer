#include "graphvisualizer.h"
#include "ui_graphvisualizer.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QPainter>
#include <QVBoxLayout>
#include <QLayout>
#include <QLayoutItem>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>

GraphVisualizer::GraphVisualizer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GraphVisualizer)
{
    ui->setupUi(this);
    ui->browseButton->setStyleSheet(
        "QPushButton {"
        "  background-color: #28a745;"
        "  color: white;"
        "  border-radius: 6px;"
        "  padding: 10px 20px;"
        "  font-size: 14px;"
        "  font-weight: 600;"
        "}"
        "QPushButton:hover {"
        "  background-color: #218838;"
        "}"
        "QPushButton:pressed {"
        "  background-color: #1e7e34;"
        "}"
        );
    ui->filePathLineEdit->setStyleSheet(
        "QLineEdit {"
        "  padding: 8px;"
        "  border: 2px solid #ccc;"
        "  border-radius: 6px;"
        "  font-size: 14px;"
        "}"
        );

    ui->chartContainer->setStyleSheet(
        "background-color: transparent;"
        "border: none;"
        );

    qApp->setStyleSheet(
        "QMainWindow { background-color: #ffffff; }"
        "QStatusBar { background-color: #f1f3f5; }"
        );


    connect(ui->browseButton, &QPushButton::clicked, this, &GraphVisualizer::handleBrowseClicked);
}

GraphVisualizer::~GraphVisualizer()
{
    delete ui;
}

void GraphVisualizer::handleBrowseClicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Open CSV File", "", "CSV Files (*.csv);;Text Files (*.txt)");
    if (!filePath.isEmpty()) {
        ui->filePathLineEdit->setText(filePath);
        loadCSVAndPlot(filePath);
    }
}

void GraphVisualizer::loadCSVAndPlot(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Failed to open file.");
        return;
    }

    QTextStream in(&file);
    QLineSeries *series = new QLineSeries();

    int lineNumber = 0;
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty())
            continue;

        QStringList parts = line.split(',');
        if (parts.size() != 2) continue;

        bool okX, okY;
        double x = parts[0].toDouble(&okX);
        double y = parts[1].toDouble(&okY);
        if (okX && okY)
            series->append(x, y);

        lineNumber++;
    }

    file.close();
    series->setColor(Qt::red);
    series->setName("My Data");
    series->setPointsVisible(true);
    series->setPointLabelsVisible(false);
    series->setPen(QPen(Qt::red, 2));

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("2D Graph Visualization");
    chart->axes(Qt::Horizontal).first()->setTitleText("X Axis");
    chart->axes(Qt::Vertical).first()->setTitleText("Y Axis");

    QChartView *chartView = new QChartView(chart);
    chartView->setRubberBand(QChartView::RectangleRubberBand);
    chartView->setInteractive(true);
    chartView->setDragMode(QGraphicsView::ScrollHandDrag);
    chart->zoomReset();
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    chartView->setMinimumHeight(300);

    QLayout *layout = ui->chartContainer->layout();
    if (!layout) {
        layout = new QVBoxLayout(ui->chartContainer);
        ui->chartContainer->setLayout(layout);
    } else {
        QLayoutItem *child;
        while ((child = layout->takeAt(0)) != nullptr) {
            delete child->widget();
            delete child;
        }
    }

    layout->addWidget(chartView);

}

