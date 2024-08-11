#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

struct Flow {
    int id;
    int bandwith;
    int start_time;
    int send_time;
    Flow(int arg1, int arg2, int arg3, int arg4) : id(arg1), bandwith(arg2), start_time(arg3), send_time(arg4) {}
};

struct Port {
    int id;
    int bandwith;
    Port(int arg1, int arg2) : id(arg1), bandwith(arg2) {}
};

class Transfer {
public:
    Transfer(int folder_id_) : folder_id(folder_id_){}
    ~Transfer(){}
    
    int folder_id;
    std::string flow_file_path = "../data/" + std::to_string(folder_id) + "/flow.txt";
    std::string port_file_path = "../data/" + std::to_string(folder_id) + "/port.txt";
    std::string result_file_path = "../data/" + std::to_string(folder_id) + "/result.txt";
    void readPort(void);
    void readFlow(void);
    void processData(void);
    void saveResult(void);
    void clear() {
        data_buffer_flow.clear();
        data_buffer_port.clear();
        flowData.clear();
        portData.clear();
        res.clear();
    }
private:
    vector<string> data_buffer_flow;
    vector<string> data_buffer_port;
    vector<Flow> flowData;
    vector<Port> portData;
    vector<vector<int>> res;
    vector<int> readBase(const string &file_path, vector<string>& data_buffer);
};

vector<int> Transfer::readBase(const string &file_path, vector<string>& data_buffer)
{
    int num_row = 0, num_col = 0;
    ifstream ifs(file_path, ios::in);
    if (ifs.is_open())
    {
        string buf;
        while (getline(ifs, buf)) {

            //getline() 跨平台读取csv文件
            if (buf[buf.length() - 1] == '\r')
                buf.erase(buf.end() - 1);
                //cout << "这是linux系统" << endl;
            //#endif
        
            stringstream ss(buf);
            //ss << buf;
            string buff;
            if(num_row!=0) {
                while (getline(ss, buff, ','))
                {
                    data_buffer.push_back(buff); 
                    if (num_row==1)
                        ++num_col; //获取原始数据列数
                }
            }
            ++num_row; //获取原始数据行数
        }
    }
    else cerr << "File Open failed" << endl;
    ifs.close();
    --num_row;
    return vector<int>{num_row, num_col};
}

void Transfer::readPort(void){
    vector<int> num_row_and_col = readBase(port_file_path, data_buffer_port);
    int num_row = num_row_and_col[0];
    int num_col = num_row_and_col[1];
    
    for (int i = 0; i != num_row; ++i)
    {
        Port port_tmp(stoi(data_buffer_port[i*num_col]), stoi(data_buffer_port[i*num_col+1]));
        portData.emplace_back(port_tmp);
    }
}


void Transfer::readFlow(void){
    vector<int> num_row_and_col = readBase(flow_file_path, data_buffer_flow);
    int num_row = num_row_and_col[0];
    int num_col = num_row_and_col[1];
   
    for (int i = 0; i != num_row; ++i)
    {
        Flow flow_tmp(stoi(data_buffer_flow[i*num_col]),stoi(data_buffer_flow[i*num_col+1]),stoi(data_buffer_flow[i*num_col+2]),stoi(data_buffer_flow[i*num_col+3]));
        flowData.emplace_back(flow_tmp);
    }
}


void Transfer::processData(void){
    const int n = flowData.size();
    for(int i = 0; i < n; ++i){
        vector<int> tmp(3, 0);
        tmp[0] = flowData[i].id;
        /*
        bool flag = false;
        
        for(size_t j = 0; j < portData.size(); ++j){
            if(flowData[i].bandwith <= portData[i].bandwith){
               tmp[1] = portData[i].id; 
               flag = true;
               break;
            }
        }

        if(!flag) tmp[1] = 0; 
        */
        
        tmp[2] = flowData[i].start_time;
        res.emplace_back(tmp);
    }
}

void Transfer::saveResult(void){
    ofstream ofs; //写入txt文件
    ofs.open(result_file_path, ios::out);
    if(!ofs.is_open()) cerr << "File save failed!" << endl;
    const int n = res.size();
    for(int i = 0; i < n; ++i)
        ofs<<res[i][0] << "," << res[i][1] << "," << res[i][2] << endl;
}


int main(int argc, char *argv[])
{
    int folder_id = 0;
    while(1) {
        string flow_file_path = "../data/" + std::to_string(folder_id) + "/flow.txt";
        ifstream ifs(flow_file_path, ios::in);
        if (!ifs.is_open()){
            cerr << "Folder " << folder_id << " open failed "<< endl;
            break;
        }
        ifs.close();

        Transfer obj(folder_id);
        
        
        obj.readFlow();
        obj.readPort();
        obj.processData();
        obj.saveResult();
        obj.clear();
        ++folder_id;
        //if(folder_id > 1) break;
    }
    
    return 0;
}