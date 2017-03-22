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
// Container for original & filtered data
pcl::PCLPointCloud2 cloud1;
pcl_conversions::toPCL(*cloud_msg, cloud1);
pcl::PointCloud<pcl::PointXYZ>::Ptr cloudconverted(new pcl::PointCloud<pcl::PointXYZ>);
pcl::fromPCLPointCloud2(cloud1,*cloudconverted);
//pcl::PCLPointCloud2 cloud_filtered;
// Convert to PCL data type

 // Perform the actual filtering
/*pcl::VoxelGrid<pcl::PCLPointCloud2> sor;
sor.setInputCloud (cloudPtr);
sor.setLeafSize (0.1, 0.1, 0.1);
sor.filter (cloud_filtered);*/
// Convert to ROS data type
/*sensor_msgs::PointCloud2 output;
pcl_conversions::fromPCL(cloud_filtered, output);*/
viewer.showCloud(cloudconverted);
// Publish the data
//pub.publish (output);
}


int main (int argc, char** argv)
{
  ros::init (argc, argv, "FirstTry");
  ros::NodeHandle nh;

  ros::Subscriber sub = nh.subscribe ("velodyne_points", 1, cloud_callback);

  ros::spin ();
}
