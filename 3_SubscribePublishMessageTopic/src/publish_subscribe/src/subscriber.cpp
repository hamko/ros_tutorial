/* メッセージ受信 */
#include <ros/ros.h>                       // ROSヘッダファイル
#include <std_msgs/Float64.h>             // メッセージヘッダファイル

void messageCallBack(const std_msgs::Float64& msg) {  // メッセージ受信時に呼ばれるコールバック関数
    ROS_INFO_STREAM(msg.data);                // 標準出力へ受信したメッセージを表示
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "sub_test");        // ノードの初期化（ノード名を"sub_test"に設定）
    ros::NodeHandle nh;                       // ノードハンドルの生成
    ros::Subscriber sub = nh.subscribe("test/sin", 1000, &messageCallBack);  // サブスクライバ生成（コールバック関数の登録）
    ros::spin();                              // 無限待ち
}
