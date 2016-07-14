#include <ros/ros.h>
#include <std_msgs/Float64.h>

int main(int argc, char **argv) {
    ros::init(argc, argv, "pub_test"); // node name = pub_test
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::Float64>("test/sin", 1000); // queue size = 1000
    ros::Rate rate(20); // 20 Hz
    while(ros::ok()) {
        double d;
        std_msgs::Float64 msg;
        for(int i = 0; i < 20; i++) { // sin function
            msg.data = sin(3.14159 / 10 * i); 
            ROS_INFO_STREAM(msg.data);
            pub.publish(msg);
            rate.sleep(); // wait 5 ms control cycle
        }
    }
}
