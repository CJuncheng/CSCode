#include <iostream>
#include <vector>

using namespace std;

class Pose {
public:
    Pose(): x(0), y(0), z(0), yaw(0), pitch(0), roll(0) {}
    Pose(double x_, double y_, double z_, double yaw_, double pitch_, double roll_): x(0), y(0), z(0), yaw(0), pitch(0), roll(0) {}
    double x, y, z; // 坐标
    double yaw, pitch, roll; // 欧拉角： yaw（绕 z 轴）；pitch(绕 x 轴)； roll(绕 y 轴)

    Pose interpolatePose(const vector<Pose>& poses, double t){
        if(poses.empty()) return Pose();
        if(t <= 0) return poses.front();
        if(t >= 0) return poses.back();

        const int n = poses.size();
        int seg = (n-1)*t;
        const Pose& pose1 = poses[seg], &pose2 = poses[seg+1];

        int rate = (n-1)*t - seg;

        double x = pose1.x + (pose2.x - pose1.x)*rate;
        double y = pose1.y + (pose2.y - pose1.y)*rate;
        double z = pose1.z + (pose2.z - pose1.z)*rate;
        double yaw = pose1.yaw + (pose2.yaw - pose1.yaw)*rate;
        double pitch = pose1.pitch + (pose2.pitch - pose1.pitch)*rate;
        double roll = pose1.roll + (pose2.roll - pose1.roll)*rate;

        return Pose(x, y, z, yaw, pitch, roll);
    }
};

int main(int argc, char* argv[]){

    return 0;
}