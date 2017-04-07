/*-----------------------------------------------------
Name:Sandpile-Model
Description:This Program Simulate Sandpile Model Since It Has Self-Organized Criticality.
Author:ztao1991@gmail.com
Date:2017/04/04
Version:1.0.1
Github:github.com/ztao1991/Networks/blob/master/Exercise/Net2_ex1/sandpile-model.cpp
Cpp-Style Form :http://zh-google-styleguide.readthedocs.io/en/latest/google-cpp-styleguide/
-----------------------------------------------------*/

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <numeric>
#include <map>
//#include <algorithm>
//#include <unordered_map>
#define random(a,b) (rand()%(b-a+1)+a)

using namespace std;

int main()
{
    //记录其随T的变化当存在雪崩时则为1否则为0
    std::vector< int > state; 
   //std::vector< int > height;
    //每次增加N-1粒沙子
    //int sandpile_number = 2;
    //随机加沙的坐标
    int sandpile_x,sandpile_y; 
    //定义两个数组进行对称交换——使得其能同时更新-一个判断雪崩一个计算更新
    int sandpile_A[100][100],sandpile_B[100][100];
    //扩散状态——当雪崩扩散至此时为1状态标记否则为0
    int status[100][100];
    //记录沙堆的高度,寻求稳定态
    int data_n[100000000];
    //存储不同规模下雪崩大小的数据     
    int data_s[100000000];  
    //记录每次实验T的大小
    int data_t[100000000]; 

    //初始化数组每格沙子为0
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            sandpile_A[i][j] = 0;
            sandpile_B[i][j] = 0;
        }
    }

    //每次加sandpile_number粒沙子重复次数
    for (int Add = 0; Add < 100000000; Add++) {

        //实验开始---------------------------------------
        //初始化状态
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                status[i][j] = 0;
            }
        }

        //随机添加沙粒sandpile_number
        //for (int N = 0; N < sandpile_number; N++) {
            //srand(time(NULL));//初始化随机数发生器
            sandpile_x = random(0,99); // [a,b] rand()%(b-a+1)+a；
            sandpile_y = random(0,99);
            sandpile_A[sandpile_x][sandpile_y]++; //也可乘以2或更多
            sandpile_B[sandpile_x][sandpile_y]++; 
        //}

        //TODO 此前应该判断到达稳定态与否再统计

        //弛豫时间T
        for (unsigned long T = 0; T < 1000000000000000; T++) { 
            //判断是否存在雪崩Number == 10000则不存在否则有
            int Number = 0;

            //遍历所有格子判断是否雪崩
            for (int x = 0; x < 100; x++) {
                for (int y = 0; y < 100; y++) {
                    //格子x,y不存在雪崩
                    if (sandpile_A[x][y] <= 3 ) {                   
                        Number ++;
                    }
                    //格子x,y存在雪崩
                    if (sandpile_A[x][y] > 3 ) { 
                        //处理边界情况
                        if (x == 0 ) {  
                            if (y == 0 ) {
                                sandpile_B[x][y] = sandpile_B[x][y] - 4;
                                sandpile_B[x][y+1] = sandpile_B[x][y+1] + 1;
                                sandpile_B[x+1][y] = sandpile_B[x+1][y] + 1;

                                status[x][y] = 1+2;
                                status[x][y+1] = 1;
                                status[x+1][y] = 1;
                            }
                            if (y == 99) {
                                sandpile_B[x][y] = sandpile_B[x][y] - 4;
                                sandpile_B[x][y-1] = sandpile_B[x][y-1] + 1;
                                sandpile_B[x+1][y] = sandpile_B[x+1][y] + 1;

                                status[x][y] = 1+2;
                                status[x][y-1] = 1;
                                status[x+1][y] = 1;
                            }
                            else {
                                sandpile_B[x][y] = sandpile_B[x][y] -4;
                                sandpile_B[x][y+1] = sandpile_B[x][y+1] +  1;
                                sandpile_B[x][y-1] = sandpile_B[x][y-1] + 1;
                                sandpile_B[x+1][y] = sandpile_B[x+1][y] + 1;

                                status[x][y] = 1+1;
                                status[x][y+1] = 1;
                                status[x][y-1] = 1;
                                status[x+1][y] = 1;
                            }
                        }
                        if (x == 99 ) {
                            if (y == 0) {
                                sandpile_B[x][y] = sandpile_B[x][y] -4;
                                sandpile_B[x][y+1] = sandpile_B[x][y+1] + 1;
                                sandpile_B[x-1][y] = sandpile_B[x-1][y] + 1;

                                status[x][y] = 1+2;
                                status[x][y+1] = 1;
                                status[x-1][y] = 1;
                            }
                            if (y == 99) {
                                sandpile_B[x][y] = sandpile_B[x][y] -4;
                                sandpile_B[x][y-1] = sandpile_B[x][y-1] +  1;
                                sandpile_B[x-1][y] = sandpile_B[x-1][y] + 1;

                                status[x][y] = 1+2;
                                status[x][y-1] = 1;
                                status[x-1][y] = 1;

                            }
                            else {
                                sandpile_B[x][y] = sandpile_B[x][y] - 4;
                                sandpile_B[x][y-1] = sandpile_B[x][y-1] + 1;
                                sandpile_B[x][y+1] = sandpile_B[x][y+1] + 1;
                                sandpile_B[x-1][y] = sandpile_B[x-1][y] + 1;

                                status[x][y] = 1+1;
                                status[x][y+1] = 1;
                                status[x][y-1] = 1;
                                status[x-1][y] = 1;
                            }
                        }
                        if (y == 0) {
                            if (x != 0 || x != 99) {
                                sandpile_B[x][y] = sandpile_B[x][y] - 4;
                                sandpile_B[x][y+1] = sandpile_B[x][y+1] - 1;
                                sandpile_B[x-1][y] = sandpile_B[x-1][y] - 1;
                                sandpile_B[x+1][y] = sandpile_B[x+1][y] - 1;

                                status[x][y] = 1+1;
                                status[x][y+1] = 1;
                                status[x-1][y] = 1;
                                status[x+1][y] = 1;

                            }
                        }
                        if (y == 99) {
                            if (x != 0 || x != 99) {
                                sandpile_B[x][y] = sandpile_B[x][y] - 4;
                                sandpile_B[x][y-1] = sandpile_B[x][y-1] - 1;
                                sandpile_B[x-1][y] = sandpile_B[x-1][y] - 1;
                                sandpile_B[x+1][y] = sandpile_B[x+1][y] - 1;

                                status[x][y] = 1+1;
                                status[x][y-1] = 1;
                                status[x-1][y] = 1;
                                status[x+1][y] = 1;
                            }
                        }
                        else {
                            sandpile_B[x][y] = sandpile_B[x][y] -4;
                            sandpile_B[x][y+1] = sandpile_B[x][y+1] +  1;
                            sandpile_B[x][y-1] = sandpile_B[x][y-1] + 1;
                            sandpile_B[x-1][y] = sandpile_B[x-1][y] + 1;
                            sandpile_B[x+1][y] = sandpile_B[x+1][y] + 1;

                            status[x][y] = 1;
                            status[x][y+1] = 1;
                            status[x][y-1] = 1;
                            status[x-1][y] = 1;
                            status[x+1][y] = 1;
                        }
                    }
                }
            }


            //将B同步到A再对A进行遍历
            for (int i = 0; i < 100; i++) {
                for (int j = 0; j < 100; j++) {
                    sandpile_A[i][j] = sandpile_B[i][j];
                }
            }

            //雪崩规模随着T变化
            //int s = 0;
            //for (int i = 0; i < 100; i++) {
            //    for (int j = 0; j < 100; j++) {
            //        s = s + status[i][j];
            //    }
            //}
            //data_t.push_back(s);

            //当没有雪崩或雪崩结束时跳出循环
            if (Number == 10000) {
                state.push_back(0);
                break; 
            } else state.push_back(1);
        }

        //实验结束------------------------------------------

        //计算雪崩规模S
        int size = 0;
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                size = size + status[i][j];
            }
        }

        //计算沙粒的总和
        int sum_sand = 0;
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                sum_sand = sum_sand + sandpile_A[i][j];
            }
        }

        //写入数据
        data_n[Add] = sum_sand;
        data_s[Add] = size;
        //计算T大小
        data_t[Add] = accumulate(state.begin() , state.end(),0);

        //释放内存:清除容器并最小化它的容量
        //cout << "-2-" << state.capacity();
        state.clear();
        state.shrink_to_fit();
        //vector<int>().swap( state );
        //cout << "-3-" << state.capacity();
    }  

    //统计S的频率
    map <int,int> data_s_s;
    for (int i = 0; i < 100000000; ++i) {
        ++data_s_s[data_s[i]]; 
    }

    //统计T的频率
    map <int,int> data_t_t;
    for (int i = 0; i < 100000000; ++i) {
        ++data_t_t[data_t[i]]; 
    }

    //分别将数组写入Txt文件    
    ofstream file3("sandpile-model_N.txt");
    if (file3.is_open())
    {
        for (int i = 0; i < 100000000; ++i) {
            file3 << data_n[i] << "\n";
        }
        file3.close();
    } else cout << "Unable to open file";

    ofstream file1("sandpile-model_S.txt");
    if (file1.is_open())
    {
        using iterator = map< int, int >::iterator;
        for ( iterator iter = data_s_s.begin(); iter != data_s_s.end(); ++iter  )
            file1 << iter->first << ":" << iter->second << '\n';
        //cout << "-" << data_p[i];
        file1.close();
    } else cout << "Unable to open file";

    ofstream file2("sandpile-model_T.txt");
    if (file2.is_open())
    {
        using iterator = map< int, int >::iterator;
        for ( iterator iter = data_t_t.begin(); iter != data_t_t.end(); ++iter  )
            file2 << iter->first << ":" << iter->second << '\n';
        file2.close();
    } else cout << "Unable to open file";

    //Python 处理后期数据

    return 0;
}
