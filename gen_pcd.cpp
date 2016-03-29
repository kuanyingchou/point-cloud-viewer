#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <boost/lexical_cast.hpp>

// based on http://pointclouds.org/documentation/tutorials/writing_pcd.php#writing-pcd

pcl::PointCloud<pcl::PointXYZ>::Ptr
createRandomCloud(int width, int height)
{
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);

  cloud->width    = width;
  cloud->height   = height;
  cloud->is_dense = false;
  cloud->points.resize (cloud->width * cloud->height);

  for (size_t i = 0; i < cloud->points.size (); ++i)
  {
    cloud->points[i].x = 1024 * rand () / (RAND_MAX + 1.0f);
    cloud->points[i].y = 1024 * rand () / (RAND_MAX + 1.0f);
    cloud->points[i].z = 1024 * rand () / (RAND_MAX + 1.0f);
  }
  return cloud;
}


int
main (int argc, char** argv)
{

  int n = 1;

  // 10
  // 100
  // 1000
  // 10000
  // 100000
  // 1000000
  // 10000000

  for(int i=0; i<7; i++) {
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud = createRandomCloud(n, 10);

    pcl::io::savePCDFileASCII ("test_pcd_" + boost::lexical_cast<std::string>(i) + ".pcd", *cloud);

    std::cerr << "Saved " << cloud->points.size () << " data points." << std::endl;

    // for (size_t i = 0; i < cloud->points.size (); ++i)
    //   std::cerr << "    " << cloud->points[i].x << " " << cloud->points[i].y << " " << cloud->points[i].z << std::endl;

    n *= 10;

  }

  return (0);
}
