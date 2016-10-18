#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/PCLPointCloud2.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>
#include <string>
#include <tf/transform_broadcaster.h>
#include <sensor_msgs/JointState.h>  
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

#define DEBUG 1
#define X_MIN .6
#define X_MAX 3
#define Z_MIN -2
#define Z_MAX 6
#define Y_MIN .6
#define Y_MAX 3
#define NY_MIN -3
#define NY_MAX -.6

//#define Y_MAX -1

//convenient typedefs
typedef pcl::PointXYZ PointT;
typedef pcl::PointCloud<PointT> PointCloud;
typedef pcl::PointNormal PointNormalT;
typedef pcl::PointCloud<PointNormalT> PointCloudWithNormals;


  pcl::PointCloud<pcl::PointXYZI>::Ptr cloudA (new pcl::PointCloud<pcl::PointXYZI> );
  pcl::PointCloud<pcl::PointXYZI>::Ptr cloudB (new pcl::PointCloud<pcl::PointXYZI> );
  //make the publisher global so we can publish from the callback
  ros::Publisher pub;
  ros::Publisher pub2;
  ros::Publisher pub3;
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
if(icp.getFitnessScore() > 0.01){
ROS_INFO("trying again");  
icp.setTransformationEstimation (teLM);
  icp.setMaximumIterations(500);
  pcl::PointCloud<pcl::PointXYZ> Final;
  icp.align (Final);
  std::cout << "has converged:" << icp.hasConverged() << " score: " << icp.getFitnessScore() << std::endl;
}
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
  ROS_INFO("GOT A CLOUD");
  pcl::PointCloud<pcl::PointXYZI>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZI>);
  sensor_msgs::PointCloud2 cloud_msg2 = *cloud_msg;
 
  //fix the naming discrepancy between ROS and PCL (from "intensities" to "intensity")

 ROS_INFO("GOT A CLOUD1");
  cloud_msg2.fields[3].name = "intensity";

 ROS_INFO("GOT A CLOUD2");
  pcl::fromROSMsg(cloud_msg2,*cloud);
  //crop the cloud
pcl::PointCloud<pcl::PointXYZI>::Ptr cloud_filteredxyz (new pcl::PointCloud<pcl::PointXYZI>);
pcl::PointCloud<pcl::PointXYZI>::Ptr garbage_filterx (new pcl::PointCloud<pcl::PointXYZI>);
pcl::PointCloud<pcl::PointXYZI>::Ptr garbage_filterxy (new pcl::PointCloud<pcl::PointXYZI>);
pcl::PointCloud<pcl::PointXYZI>::Ptr garbage_filterxyz (new pcl::PointCloud<pcl::PointXYZI>);
pcl::PointCloud<pcl::PointXYZI>::Ptr final (new pcl::PointCloud<pcl::PointXYZI>);
ROS_INFO("filtering");
// Create the filtering object
  pcl::PassThrough<pcl::PointXYZI> pass (true);
//filter z values  
  pass.setInputCloud (cloud);
  pass.setFilterFieldName ("z");
  pass.setFilterLimits (-1,5.5865);
  pass.filter (*cloud_filteredxyz);
ROS_INFO("filt1");
  pass.setInputCloud (cloud_filteredxyz);
  pass.setFilterFieldName ("x");
  pass.setFilterLimits (X_MIN,X_MAX);
  pass.filter (*garbage_filterx);  
ROS_INFO("filt2");
  pass.setInputCloud (cloud_filteredxyz);
  pass.setFilterFieldName ("y");
  pass.setFilterLimits (Y_MIN,Y_MAX);
  pass.filter (*garbage_filterxy); 
ROS_INFO("filt3");
  pass.setInputCloud (cloud_filteredxyz);
  pass.setFilterFieldName ("y");
  pass.setFilterLimits (NY_MIN,NY_MAX);
  pass.filter (*garbage_filterxyz);  
 ROS_INFO("filt4"); 
*final += *garbage_filterx;
*final += *garbage_filterxy;
*final += *garbage_filterxyz;

  // Convert to ROS data type
  sensor_msgs::PointCloud2 output;
  pcl::toROSMsg(*cloud, output);
  
  //store the cloud in th respective global
    if(cloudctr==0){
    //Populate the PCL pointcloud with the ROS message
    *cloudA = *final;
    ++cloudctr;
  }else{
    //Populate the PCL pointcloud with the ROS message
    *cloudB = *final;
    cloudctr=0;
  }
ROS_INFO("callback done");
}

int
main (int argc, char** argv)
{
  // Initialize ROS
  ros::init (argc, argv, "my_pcl_tutorial");
  ros::NodeHandle nh;


  // Create a ROS subscriber for the input point cloud
  ros::Subscriber sub = nh.subscribe ("assembled_cloud", 1, cloud_cb);

  pcl::PointCloud<pcl::PointXYZI>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZI>);
  pcl::PointCloud<pcl::PointXYZI>::Ptr cloudA_filtered (new pcl::PointCloud<pcl::PointXYZI> );
  // Create a ROS publisher for the output point cloud
  pub = nh.advertise<sensor_msgs::PointCloud2> ("cloud_B", 1);
  pub2 = nh.advertise<sensor_msgs::PointCloud2> ("cloud_A", 1);
  pub3 = nh.advertise<sensor_msgs::PointCloud2> ("cloud_final", 1);



  if(DEBUG){ 
  ROS_INFO("DEBUGGING");
  /* load a file
    if (pcl::io::loadPCDFile<pcl::PointXYZI> ("/home/mike/newcloud1.pcd", *cloudA) == -1) 
    {
      PCL_ERROR ("Couldn't read file test_pcd.pcd \n");

      return(0);
    }*/
  }
  //call the laser scan service here
  cloudctr = 0;
  //wait for the first cloud
  while(cloudctr == 0){
    ros::spinOnce();
    }
    
// extract the marker from cloud A
  pcl::PassThrough<pcl::PointXYZI> pass;
  pass.setInputCloud (cloudA);
  pass.setFilterFieldName ("intensity");
  pass.setFilterLimits (900, 1600);
  pass.filter (*cloudA_filtered);
  if(DEBUG){
    pcl::io::savePCDFileASCII ("/home/mike/filterA.pcd", *cloudA);
  }
  //downsample cloud A
  pcl::PointCloud<pcl::PointXYZI>::Ptr cloudA_downsampled (new    pcl::PointCloud<pcl::PointXYZI> );
  
  pcl::VoxelGrid<pcl::PointXYZI> sor;
  sor.setInputCloud (cloudA);
  sor.setLeafSize (0.05f, 0.05f, 0.05f);
  sor.filter (*cloudA_downsampled);
  if(DEBUG){
    pcl::io::savePCDFileASCII ("/home/mike/downsampleA.pcd", *cloudA_downsampled);
  }
  sensor_msgs::PointCloud2 outputA;
  pcl::toROSMsg(*cloudA, outputA);
  outputA.header.frame_id = "base_footprint";
  // Publish the data
  pub2.publish (outputA);
  ros::spinOnce();
  std::cerr << "PointCloudA after downsampling: " << cloudA_downsampled->width *      cloudA_downsampled->height << " data points (" << pcl::getFieldsList (*cloudA_downsampled) << ").\n";
  //wait for second cloud
ROS_INFO("waiting for second cloud");
  while(cloudctr == 1){
    ros::spinOnce();
  }

ROS_INFO("done waiting for second cloud");
  pcl::PointCloud<pcl::PointXYZI>::Ptr cloudB_filtered (new pcl::PointCloud<pcl::PointXYZI> );
  pcl::PointCloud<pcl::PointXYZI>::Ptr cloudB_aligned (new pcl::PointCloud<pcl::PointXYZI> );
  pcl::PointCloud<pcl::PointXYZI>::Ptr cloudB_filter_aligned (new pcl::PointCloud<pcl::PointXYZI> );
  pcl::PointCloud<pcl::PointXYZI>::Ptr cloudB_downsampled (new pcl::PointCloud<pcl::PointXYZI> );
  
  if(DEBUG){
   /* if (pcl::io::loadPCDFile<pcl::PointXYZI> ("/home/mike/newcloud3.pcd", *cloudB) == -1) 
     load a file
    {
      PCL_ERROR ("Couldn't read file test_pcd.pcd \n");

      return(0);
    }*/
  }
  //extract marker from cloud B
  pass.setInputCloud (cloudB);
  pass.setFilterFieldName ("intensity");
  pass.setFilterLimits (900, 1600);
  pass.filter (*cloudB_filtered);
  

  if(DEBUG){
    pcl::io::savePCDFileASCII ("/home/mike/filterB.pcd", *cloudB);
	}
	
	
	//Align the two clouds
	
	PointCloud::Ptr result (new PointCloud), source (new PointCloud), target (new PointCloud);
  Eigen::Matrix4f GlobalTransform = Eigen::Matrix4f::Identity (), pairTransform;

  // Fill in the source cloud data
  source->width  = cloudA_filtered->width;
  source->height = cloudA_filtered->height;
  source->points.resize (cloudA_filtered->width * cloudA_filtered->height);
std::cout << "Done Resizing" << std::endl;
  for (size_t i = 0; i < source->points.size (); ++i)
  {
    source->points[i].x = cloudA_filtered->points[i].x;
    source->points[i].y = cloudA_filtered->points[i].y;
    source->points[i].z = cloudA_filtered->points[i].z;
  }

  // Fill in the target cloud data
  target->width  = cloudB_filtered->width;
  target->height = cloudB_filtered->height;
  target->points.resize (cloudB_filtered->width * cloudB_filtered->height);

  for (size_t i = 0; i < target->points.size (); ++i)
  {
    target->points[i].x = cloudB_filtered->points[i].x;
    target->points[i].y = cloudB_filtered->points[i].y;
    target->points[i].z = cloudB_filtered->points[i].z;
  }

  //do the actual aligning
  PointCloud::Ptr temp (new PointCloud);
  pairAlign (source, target, temp, pairTransform, false);
  std::cout << "Done Aligning" << std::endl;
  pcl::transformPointCloud (*cloudB, *cloudB_aligned, pairTransform);
  pcl::transformPointCloud (*cloudB_filtered, *cloudB_filter_aligned, pairTransform);
  if(DEBUG){
    pcl::io::savePCDFileASCII ("/home/mike/newcloudaligned.pcd", *cloudB_aligned);
    pcl::io::savePCDFileASCII ("/home/mike/filterbaligned.pcd", *cloudB_filter_aligned);
  }

  //calculate thickness
  float resolution = 128.0f;
  pcl::octree::OctreePointCloudSearch<pcl::PointXYZI> octree (resolution);
  octree.setInputCloud (cloudA_downsampled);
  octree.addPointsFromInputCloud ();
  pcl::PointXYZI searchPoint;
  // Neighbors within radius search
  std::vector<int> pointIdxRadiusSearch;
  std::vector<float> pointRadiusSquaredDistance;
  float radius = .5;
  float mind = 100;
  float maxd = 0;
  int K = 1;
  std::vector<int> pointIdxNKNSearch;
  std::vector<float> pointNKNSquaredDistance;
  //Downsample cloud B
  sor.setInputCloud (cloudB_aligned);
  sor.setLeafSize (0.05f, 0.05f, 0.05f);
  sor.filter (*cloudB_downsampled);

  std::cout << "Beginning Neighbour Search using " << cloudA_downsampled->width *      cloudA_downsampled->height <<" and " << cloudB_downsampled->width *      cloudB_downsampled->height << " points" << std::endl;
  //Look for the nearest neighbor in cloud A of each point in cloud B 
  BOOST_FOREACH (pcl::PointXYZI& pt, cloudB_downsampled->points){
    searchPoint.x = pt.x;
    searchPoint.y = pt.y;
    searchPoint.z = pt.z;

    if(octree.nearestKSearch (searchPoint, K, pointIdxNKNSearch, pointNKNSquaredDistance) > 0){
      if(pointNKNSquaredDistance[0]<.15)
        pt.intensity = pointNKNSquaredDistance[0];
      else
        pt.intensity = 0;
    }
  }

  if(DEBUG){
    pcl::io::savePCDFileASCII ("/home/mike/newcoloured.pcd", *cloudB_downsampled);
  }
  pcl::io::savePCDFileASCII ("/home/mike/output.pcd", *cloudB_downsampled);
  sensor_msgs::PointCloud2 output;
  pcl::toROSMsg(*cloudB_downsampled, output);
  output.header.frame_id = "base_footprint";
  // Publish the data
  pub3.publish (output);
  ros::spinOnce();
  std::cout << "Done" << std::endl;
  
}
