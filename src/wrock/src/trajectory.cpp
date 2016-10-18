#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/PCLPointCloud2.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>
#include <string>
#include <tf/transform_broadcaster.h>
#include <pcl/conversions.h>
#include "pcl_ros/transforms.h"
#include <iostream>
#include <pcl/filters/passthrough.h>
#include <pcl/io/pcd_io.h>
#include "std_msgs/String.h"
#include <sstream>
#include <pcl/filters/extract_indices.h>
#include <pcl/octree/octree.h>
#include <vector>
#include <ctime>
#include <boost/make_shared.hpp>
#include <pcl/point_representation.h>
#include <pcl/filters/filter.h>
#include <pcl/features/normal_3d.h>
#include <pcl/registration/icp.h>
#include <pcl/registration/icp_nl.h>
#include <pcl/registration/transforms.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <visualization_msgs/Marker.h>
#include <pcl/filters/normal_space.h>
#include <pcl/features/normal_3d.h>
#include <pcl/visualization/pcl_visualizer.h>


#define DEBUG 1
#define X_MIN 1
#define X_MAX 100
#define Z_MIN .75
#define Z_MAX 100
#define Y_MIN -100
#define Y_MAX -1

//convenient typedefs
typedef pcl::PointXYZ PointT;
typedef pcl::PointCloud<PointT> PointCloud;
typedef pcl::PointNormal PointNormalT;
typedef pcl::PointCloud<PointNormalT> PointCloudWithNormals;


  pcl::PointCloud<pcl::PointXYZI>::Ptr cloudA (new pcl::PointCloud<pcl::PointXYZI> );
  pcl::PointCloud<pcl::PointXYZI>::Ptr cloudB (new pcl::PointCloud<pcl::PointXYZI> );
  //make the publisher global so we can publish from the callback
  ros::Publisher pub;
  int cloudctr;
//convenient structure to handle our pointclouds
struct PCD
{
  PointCloud::Ptr cloud;
  std::string f_name;

  PCD() : cloud (new PointCloud) {};
};


////////////////////////////////////////////////////////////////////////////////
/** \brief Align a pair of PointCloud datasets and return the result
  * \param cloud_src the source PointCloud
  * \param cloud_tgt the target PointCloud
  * \param output the resultant aligned source PointCloud
  * \param final_transform the resultant transform between source and target
  */
void pairAlign (const PointCloud::Ptr cloud_src, const PointCloud::Ptr cloud_tgt, PointCloud::Ptr output, Eigen::Matrix4f &final_transform, bool downsample = false)
{

  pcl::IterativeClosestPoint<pcl::PointXYZ, pcl::PointXYZ> icp;
  icp.setInputSource (cloud_src);
  icp.setInputTarget (cloud_tgt);
  typedef pcl::registration::TransformationEstimationLM <pcl::PointXYZ, pcl::PointXYZ> te;
  boost::shared_ptr<te> teLM (new te);
  icp.setTransformationEstimation (teLM);
  icp.setMaximumIterations(100);
  pcl::PointCloud<pcl::PointXYZ> Final;
  icp.align (Final);
  std::cout << "has converged:" << icp.hasConverged() << " score: " << icp.getFitnessScore() << std::endl;
  std::cout << icp.getFinalTransformation() << std::endl;
  Eigen::Matrix4f T;
  Eigen::Matrix4f Ti = Eigen::Matrix4f::Identity (), prev, targetToSource;
  T = icp.getFinalTransformation();
  // Get the transformation from target to source
  targetToSource = T.inverse();
  // Transform target back in source frame
  pcl::transformPointCloud (*cloud_tgt, *output, targetToSource);
  final_transform = targetToSource;
}



void cloud_cb (const sensor_msgs::PointCloud2ConstPtr& cloud_msg)
{
 /* ROS_INFO("GOT A CLOUD");
  pcl::PointCloud<pcl::PointXYZI>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZI>);
  sensor_msgs::PointCloud2 cloud_msg2 = *cloud_msg;
  //fix the naming discrepancy between ROS and PCL (from "intensities" to "intensity")
  cloud_msg2.fields[3].name = "intensity";
  pcl::fromROSMsg(cloud_msg2,*cloud);
  //crop the cloud
pcl::PointCloud<pcl::PointXYZI>::Ptr cloud_filteredxyz (new pcl::PointCloud<pcl::PointXYZI>);
pcl::PointCloud<pcl::PointXYZI>::Ptr garbage_filterx (new pcl::PointCloud<pcl::PointXYZI>);
pcl::PointCloud<pcl::PointXYZI>::Ptr garbage_filterxy (new pcl::PointCloud<pcl::PointXYZI>);
pcl::PointCloud<pcl::PointXYZI>::Ptr garbage_filterxyz (new pcl::PointCloud<pcl::PointXYZI>);
pcl::PointCloud<pcl::PointXYZI>::Ptr final (new pcl::PointCloud<pcl::PointXYZI>);

// Create the filtering object
  pcl::PassThrough<pcl::PointXYZI> pass (true);
//filter z values  
  pass.setInputCloud (cloud);
  pass.setFilterFieldName ("z");
  pass.setFilterLimits (-.1,1.5865);
  pass.filter (*cloud_filteredxyz);

  pass.setInputCloud (cloud_filteredxyz);
  pass.setFilterFieldName ("x");
  pass.setFilterLimits (X_MIN,X_MAX);
  pass.filter (*garbage_filterx);  

  pass.setInputCloud (cloud_filteredxyz);
  pass.setFilterFieldName ("y");
  pass.setFilterLimits (Y_MIN,Y_MAX);
  pass.filter (*garbage_filterxy); 

  pass.setInputCloud (cloud_filteredxyz);
  pass.setFilterFieldName ("z");
  pass.setFilterLimits (Z_MIN,Z_MAX);
  pass.filter (*garbage_filterxyz);  
  
*final += *garbage_filterx;
*final += *garbage_filterxy;
*final += *garbage_filterxyz;

  // Convert to ROS data type
  sensor_msgs::PointCloud2 output;
  pcl::toROSMsg(*final, output);
  
  //store the cloud in th respective global
    if(cloudctr==0){
    //Populate the PCL pointcloud with the ROS message
    *cloudA = *final;
    ++cloudctr;
  }else{
    //Populate the PCL pointcloud with the ROS message
    *cloudB = *final;
    ++cloudctr;
  }*/
}

int
main (int argc, char** argv)
{
  // Initialize ROS
  ros::init (argc, argv, "my_pcl_tutorial");
  ros::NodeHandle nh;


  
  pcl::PointCloud<pcl::PointXYZI>::Ptr cloudA (new pcl::PointCloud<pcl::PointXYZI>);
  pcl::PointCloud<pcl::PointXYZI> cloudB;
  pcl::PointCloud<pcl::PointXYZI>::Ptr cloudA_filtered (new pcl::PointCloud<pcl::PointXYZI> );
  // Create a ROS publisher for the output point cloud
  pub = nh.advertise<sensor_msgs::PointCloud2> ("assembled_cloud", 1);
    ros::Publisher marker_pub = nh.advertise<visualization_msgs::Marker>("visualization_marker", 1);
    
 if (pcl::io::loadPCDFile<pcl::PointXYZI> ("/home/mike/newcloud3.pcd", *cloudA) == -1) 
    {
      PCL_ERROR ("Couldn't read file test_pcd.pcd \n");

      return(0);
    }  
  float maxX =0;
  float maxY =0;
  float maxZ =0;  
  BOOST_FOREACH (pcl::PointXYZI& p, cloudA->points){
  if(p.intensity > 1500){
    if(p.y < maxY){ 
      maxX = p.x;
      maxY = p.y;
      maxZ = p.z;
      }
    }
 }
  
  ROS_INFO("MAX: %f -- %f -- %f",maxX,maxY,maxZ);
  
  pcl::PointXYZI start[6];
  pcl::PointXYZI foundpt[6];
    std::vector<int> pointIdxNKNSearch;
  std::vector<float> pointNKNSquaredDistance;
    pcl::PointXYZI searchPoint;
    int K = 1;
    float resolution = 128.0f;

  pcl::octree::OctreePointCloudSearch<pcl::PointXYZI> octree (resolution);

  octree.setInputCloud (cloudA);
  octree.addPointsFromInputCloud ();
  start[0].x = 1.3;
  start[0].y = maxY;
  start[0].z = 0;
  start[1].x = 1.2;
  start[1].y = start[0].y-0.25;
  start[1].z = start[0].z;
  start[2].x = 1.2;
  start[2].y = start[1].y;
  start[2].z = start[1].z+0.1;
  start[3].x = 1.3;
  start[3].y = start[2].y+0.25;
  start[3].z = start[2].z;
  start[4].x = 1.3;
  start[4].y = start[3].y;
  start[4].z = start[3].z+0.1;
  start[5].x = 1.2;
  start[5].y = start[4].y-0.25;
  start[5].z = start[4].z;
  
  
      
    
    uint32_t shape = visualization_msgs::Marker::ARROW;
     visualization_msgs::Marker marker;
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker.header.frame_id = "/base_footprint";
    marker.header.stamp = ros::Time::now();
    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker.ns = "basic_shapes";
    marker.id = 0;
    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    marker.type = shape;
    // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    marker.action = visualization_msgs::Marker::ADD;
    // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
    marker.pose.position.x = 0;
    marker.pose.position.y = 0;
    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker.scale.x = 0.01;
    marker.scale.y = 0.01;
    marker.scale.z = 0.01;

    // Set the color -- be sure to set alpha to something non-zero!
    marker.color.r = 0.0f;
    marker.color.g = 0.0f;
    marker.color.b = 1.0f;
    marker.color.a = 1.0;
    marker.lifetime = ros::Duration();
    
  for(int ctr = 0; ctr < 6; ++ctr){
    if (octree.nearestKSearch (start[ctr], K, pointIdxNKNSearch, pointNKNSquaredDistance) > 0){
        foundpt[ctr] = cloudA->points[pointIdxNKNSearch[0]];
        ROS_INFO("Found pt %f/%f/%f near %f/%f/%f",foundpt[ctr].x,foundpt[ctr].y,foundpt[ctr].z,start[ctr].x,start[ctr].y,start[ctr].z);
        }
        
     cloudB.push_back (foundpt[ctr]);
     }
        
    ROS_INFO("Size: %d",cloudB.width*cloudB.height);
    ROS_INFO("SizeA: %d",cloudA->width*cloudA->height);
    // Create the normal estimation class, and pass the input dataset to it
  pcl::NormalEstimation<pcl::PointXYZI, pcl::Normal> ne;
    // set parameters
  pcl::PointCloud<pcl::PointXYZI>::Ptr cloudptr = cloudB.makeShared();
  ne.setInputCloud (cloudptr);

    ROS_INFO("Size2: %d -- %lu",cloudptr->width*cloudptr->height, cloudptr->points.size());
  // Pass the original data (before downsampling) as the search surface
  ne.setSearchSurface (cloudA);
  // Create an empty kdtree representation, and pass it to the normal estimation object.
  // Its content will be filled inside the object, based on the given surface dataset.
  pcl::search::KdTree<pcl::PointXYZI>::Ptr tree (new pcl::search::KdTree<pcl::PointXYZI> ());
  ne.setSearchMethod (tree);

  // Output datasets
  pcl::PointCloud<pcl::Normal>::Ptr cloud_normals (new pcl::PointCloud<pcl::Normal> ());

  // Use all neighbors in a sphere of radius 3cm
  ne.setRadiusSearch (0.05);
  ne.setViewPoint (-10, 10, 10);
  // Compute the features
  ne.compute (*cloud_normals);
  
  ROS_INFO("%lu",cloud_normals->points.size());
  

      marker.points.resize(2);
      
  for(int ctr = 0; ctr < 6; ++ctr){

     marker.id = ctr;
     marker.points[0].x = foundpt[ctr].x;
     marker.points[0].y = foundpt[ctr].y;
     marker.points[0].z = foundpt[ctr].z;
     marker.points[1].x = foundpt[ctr].x + cloud_normals->points[ctr].normal[0]/10;
     marker.points[1].y = foundpt[ctr].y + cloud_normals->points[ctr].normal[1]/10;
     marker.points[1].z = foundpt[ctr].z + cloud_normals->points[ctr].normal[2]/10;
     ROS_INFO("Found pt %f/%f/%f normal %f/%f/%f",foundpt[ctr].x,foundpt[ctr].y,foundpt[ctr].z,cloud_normals->points[ctr].normal[0],cloud_normals->points[ctr].normal[1],cloud_normals->points[ctr].normal[2]);
        ROS_INFO("%lu",cloud_normals->points.size ());
     marker_pub.publish(marker);
     }
      
    
     
std::cout << "Saving Cloud" << std::endl;
    sensor_msgs::PointCloud2 output;
  pcl::toROSMsg(*cloudA, output);
  output.header.frame_id = "base_footprint";
    pub.publish(output);


    marker_pub.publish(marker);


  
  
}
