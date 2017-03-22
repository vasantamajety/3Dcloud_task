#include <iostream>
#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>


pcl::visualization::CloudViewer viewer("Cloud Viewer");

void cloud_callback (const sensor_msgs::PointCloud2ConstPtr& cloud_msg)
{
pcl::PCLPointCloud2 cloud1;

//void 	toPCL (const sensor_msgs::PointCloud2 &pc2, pcl::PCLPointCloud2 &pcl_pc2)
pcl_conversions::toPCL(*cloud_msg, cloud1);

//Creates two pcl::PointCloud<pcl::PointXYZ> boost shared pointers and initializes them
//The type of each point is set to PointXYZ
pcl::PointCloud<pcl::PointXYZ>::Ptr cloudconverted(new pcl::PointCloud<pcl::PointXYZ>);

//fromPCLPointCloud2 (const pcl::PCLPointCloud2& msg, pcl::PointCloud<PointT>& cloud)
//brief Convert a PCLPointCloud2 binary data blob into a pcl::PointCloud<T> object
pcl::fromPCLPointCloud2(cloud1,*cloudconverted);

viewer.showCloud(cloudconverted);
}


int main (int argc, char** argv)
{
  ros::init (argc, argv, "FirstTry");
  ros::NodeHandle nh;

  ros::Subscriber sub = nh.subscribe ("velodyne_points", 1, cloud_callback);

  ros::spin ();
}
