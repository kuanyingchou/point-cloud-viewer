#ifndef PCLVIEWER_H
#define PCLVIEWER_H

// Qt
#include <QMainWindow>
#include <QFileDialog>
#include <QProgressDialog>
#include <QFuture>
#include <QFutureWatcher>
#include <QtConcurrentRun>

// Point Cloud Library
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/ply_io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/filters/filter.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/visualization/point_cloud_color_handlers.h>

// Boost
#include <boost/math/special_functions/round.hpp>

// Visualization Toolkit (VTK)
#include <vtkRenderWindow.h>

typedef pcl::PointXYZRGBA PointT;
typedef pcl::PointCloud<PointT> PointCloudT;

namespace Ui
{
  class PCLViewer;
}

class PCLViewer : public QMainWindow
{
  Q_OBJECT

  public:
    /** @brief Constructor */
    explicit
    PCLViewer (QWidget *parent = 0);

    /** @brief Destructor */
    ~PCLViewer ();

    void
    render ();

    void
    loadFile (QString &filename);

  public slots:
    void
    browseFileButtonPressed ();

    /** @brief Triggered whenever the "Load file" button is clicked */
    void
    loadFileButtonPressed ();

    /** @brief Triggered whenever a button in the "Color mode" group is clicked */
    void
    updateColor ();

    void
    pSliderValueChanged (int value);

  protected:
    /** @brief The PCL visualizer object */
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer_;

    /** @brief The point cloud displayed */
    PointCloudT::Ptr cloud_;

    void
    updateViewer(pcl::visualization::PointCloudColorHandler<pcl::PointXYZRGBA> &handler);


  private:
    /** @brief ui pointer */
    Ui::PCLViewer *ui;

    bool first_time;
};

#endif // PCLVIEWER_H
