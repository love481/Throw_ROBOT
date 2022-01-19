/*
 *Author:Love Panta
 *Date:28/10/2021
 */
#ifndef _LIDAR_H_
#define _LIDAR_H_
#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Pose2D.h>
#include <tf/tf.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
class lidar
{
    private:
        ros::NodeHandle nh_;
        ros::Subscriber sub_;
        ros::Subscriber sub_amcl;
        ros::Publisher pub_;
        geometry_msgs::PoseStamped pose_;
        geometry_msgs::Pose2D pose2d_;
    
    void lidar_callback(const geometry_msgs::PoseStamped::ConstPtr& msg);
    void amcl_callback(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg);
    void initStep();
    public:
    lidar(){initStep();}
    lidar(lidar &&) = default;
    lidar(const lidar &) = default;
    lidar &operator=(lidar &&) = default;
    lidar &operator=(const lidar &) = default;
    ~lidar(){}
};
#endif // !_LIDAR_H_
