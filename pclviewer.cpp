// based on http://pointclouds.org/documentation/tutorials/qt_colorize_cloud.php#qt-colorize-cloud

#include "pclviewer.h"
#include "build/ui_pclviewer.h"
#include "Eigen/Dense"

PCLViewer::PCLViewer (QWidget *parent) :
    QMainWindow (parent),
    ui (new Ui::PCLViewer)
{
  ui->setupUi (this);
  this->setWindowTitle ("Point Cloud Viewer");

  cloud_.reset (new PointCloudT);

  // Set up the QVTK window
  viewer_.reset (new pcl::visualization::PCLVisualizer ("viewer", false));
  viewer_->setBackgroundColor (0.1, 0.1, 0.1); // so that we can see black points
  ui->qvtkWidget->SetRenderWindow (viewer_->getRenderWindow ());
  viewer_->setupInteractor (ui->qvtkWidget->GetInteractor (), ui->qvtkWidget->GetRenderWindow ());
  viewer_->setShowFPS(false);
  // ui->qvtkWidget->update ();

  // io
  connect (ui->pushButton_browse, SIGNAL(clicked ()), this, SLOT(browseFileButtonPressed ()));
  connect (ui->pushButton_load, SIGNAL(clicked ()), this, SLOT(loadFileButtonPressed ()));

  // point color
  connect (ui->radioButton_Original, SIGNAL(clicked ()), this, SLOT(colorSelected()));
  connect (ui->radioButton_Red, SIGNAL(clicked ()), this, SLOT(colorSelected()));
  connect (ui->radioButton_Green, SIGNAL(clicked ()), this, SLOT(colorSelected()));
  connect (ui->radioButton_Blue, SIGNAL(clicked ()), this, SLOT(colorSelected()));
  connect (ui->radioButton_Rainbow, SIGNAL(clicked ()), this, SLOT(colorSelected()));

  // point size
  connect (ui->horizontalSlider_p, SIGNAL (valueChanged (int)), this, SLOT (pSliderValueChanged (int)));

  this->first_time = true;

  QString filename = ui->lineEdit_path->text();
  load(filename);
  viewer_->resetCamera ();
  ui->qvtkWidget->update ();
}

PCLViewer::~PCLViewer ()
{
  delete ui;
}

void
PCLViewer::load(QString &filename) 
{
  QProgressDialog dialog("Loading...", "Cancel", 0, 0, this);
  dialog.setWindowModality(Qt::WindowModal);
  dialog.setCancelButton(0); // since `QtConcurrent::run` cannot be canceled
  dialog.setValue(0);

  PCL_INFO("File chosen: %s\n", filename.toStdString ().c_str ());

  QFutureWatcher<void> futureWatcher;

  QObject::connect(&futureWatcher, SIGNAL(finished()), &dialog, SLOT(reset()));
  QObject::connect(&dialog, SIGNAL(canceled()), &futureWatcher, SLOT(cancel()));

  // note: `run()` can not be canceled
  QFuture<void> future = QtConcurrent::run(this, &PCLViewer::loadAsync, filename);

  // start loading
  futureWatcher.setFuture(future);

  // show progress dialog
  dialog.exec();

  futureWatcher.waitForFinished();

}

void
PCLViewer::paintCloud()
{
  // Only 1 of the button can be checked at the time (mutual exclusivity) in a group of radio buttons
  if (ui->radioButton_Original->isChecked ())
  {
    PCL_INFO("Original chosen\n");
    pcl::visualization::PointCloudColorHandlerRGBField<pcl::PointXYZRGBA> handler(cloud_);
    addOrUpdateCloud(handler);
  }
  else if (ui->radioButton_Red->isChecked ())
  {
    PCL_INFO("Red chosen\n");
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGBA> handler(cloud_, 255, 0, 0);
    addOrUpdateCloud(handler);
  }
  else if (ui->radioButton_Green->isChecked ())
  {
    PCL_INFO("Green chosen\n");
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGBA> handler(cloud_, 0, 255, 0);
    addOrUpdateCloud(handler);
  }
  else if (ui->radioButton_Blue->isChecked ())
  {
    PCL_INFO("Blue chosen\n");
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGBA> handler(cloud_, 0, 0, 255);
    addOrUpdateCloud(handler);
  }
  else
  {
    PCL_INFO("Rainbow chosen\n");
    pcl::visualization::PointCloudColorHandlerGenericField<pcl::PointXYZRGBA> handler (cloud_, "y");
    addOrUpdateCloud(handler);
  }

}


// slots

void
PCLViewer::browseFileButtonPressed ()
{

  QString dir;
  QFileInfo fi(ui->lineEdit_path->text());

  if(fi.exists()) 
  {
    dir = fi.dir().path();
  } else {
    dir = "/home/";
  }

  QString filename = QFileDialog::getOpenFileName (this, tr ("Open point cloud"), 
      dir.toStdString().c_str(), tr ("Point cloud data (*.pcd *.ply)"));

  if (filename.isEmpty ())
    return;

  ui->lineEdit_path->setText(filename);

}

void
PCLViewer::loadFileButtonPressed ()
{
  QString filename = ui->lineEdit_path->text();
  load(filename);
}

void
PCLViewer::colorSelected ()
{
  paintCloud();
  ui->qvtkWidget->update ();
}

void
PCLViewer::pSliderValueChanged (int value)
{
  viewer_->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, value, "cloud");
  ui->qvtkWidget->update ();
}

// helpers

void
PCLViewer::addOrUpdateCloud(pcl::visualization::PointCloudColorHandler<pcl::PointXYZRGBA> &handler)
{
  if(first_time) 
  {
    viewer_->addPointCloud (cloud_, handler, "cloud");
    first_time = false;
  } 
  else
  {
    viewer_->updatePointCloud (cloud_, handler, "cloud");
  }
}

void
PCLViewer::loadAsync(QString &filename) 
{
  PointCloudT::Ptr cloud_tmp (new PointCloudT);

  int return_status;

  if (filename.endsWith (".pcd", Qt::CaseInsensitive))
    return_status = pcl::io::loadPCDFile (filename.toStdString (), *cloud_tmp);
  else
    return_status = pcl::io::loadPLYFile (filename.toStdString (), *cloud_tmp);

  if (return_status != 0)
  {
    PCL_ERROR("Error reading point cloud %s\n", filename.toStdString ().c_str ());
    return;
  }

  // If point cloud contains NaN values, remove them before updating the visualizer point cloud
  if (cloud_tmp->is_dense)
    pcl::copyPointCloud (*cloud_tmp, *cloud_);
  else
  {
    PCL_WARN("Cloud is not dense! Non finite points will be removed\n");
    std::vector<int> vec;
    pcl::removeNaNFromPointCloud (*cloud_tmp, *cloud_, vec);
  }

  paintCloud();
}

