cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(pcd_read)

find_package(PCL 1.3 REQUIRED )

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable(pcd_write_test pcd_write.cpp)
add_executable(pcd_read pcd_read.cpp)
add_executable(cloud_viewer cloud_viewer.cpp)
add_executable (pcl_visualizer_demo pcl_visualizer_demo.cpp)

target_link_libraries(pcd_write_test ${PCL_COMMON_LIBRARIES} ${PCL_IO_LIBRARIES})
target_link_libraries(pcd_read ${PCL_LIBRARIES})
target_link_libraries (cloud_viewer ${PCL_LIBRARIES})
target_link_libraries (pcl_visualizer_demo ${PCL_LIBRARIES})

