/* メッセージ送信 */
#include <ros/ros.h>                       // ROSヘッダファイル
#include <std_msgs/Float64.h>             // メッセージヘッダファイル

int main(int argc, char **argv) {
    ros::init(argc, argv, "pub_test");        // ノードの初期化（ノード名を"pub_test"に設定）
    ros::NodeHandle nh;                       // ノードハンドルの生成
    ros::Publisher pub = nh.advertise<std_msgs::Float64>("test/sin", 1000);  // パブリッシャー生成
    ros::Rate rate(20);                       // 周期設定（20Hzに設定）
    while(ros::ok()) {                        // Ctrl+Cが押されるまで繰り返し
        double d;
        std_msgs::Float64 msg;
        for(int i = 0; i < 20; i++) {           // サイン波を１波生成
            msg.data = sin(3.14159 / 10 * i);     // メッセージの作成
            ROS_INFO_STREAM(msg.data);            // 計算結果を表示
            pub.publish(msg);                     // メッセージの発行
            rate.sleep();                         // 指定された周期待ち（ループ内の他処理時間を引いた時間待つ）
        }
    }
}
