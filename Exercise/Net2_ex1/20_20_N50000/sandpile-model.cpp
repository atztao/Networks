/*-----------------------------------------------------
Name:Sandpile-Model
Description:This Program Simulate Sandpile Model Since It Has Self-Organized Criticality.
Author:ztao11991@gmail.com
Date:2017/04/04
Version:1.0.1
Github:github.com/ztao11991/Networks/blob/master/Exercise/Net2_ex1/sandpile-model.cpp
Cpp-Style Form :http://zh-google-styleguide.readthedocs.io/en/latest/google-cpp-styleguide/
-----------------------------------------------------*/
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <numeric>
//#include <algorithm>
#include <map>
//#include <unordered_map>
#define random(a,b) (rand()%(b-a+1)+a)

using namespace std;

int main()
{
    srand((unsigned int) time(NULL));  
    //记录其随T的变化当存在雪崩时则为1否则为0
    //std::vector< int > height;
    //每次增加N-1粒沙子
    //int sandpile_number = 2;
    //随机加沙的坐标
    int sandpile_x,sandpile_y; 
    //定义两个数组进行对称交换——使得其能同时更新-一个判断雪崩一个计算更新
    int sandpile_A[20][20],sandpile_B[20][20];
    //扩散状态——当雪崩扩散至此时为1状态标记否则为0
    //存储不同规模下雪崩大小的数据     
    std::vector<int> data_s;  
    //记录每次实验T的大小
    std::vector<int> data_t; 

    //初始化数组每格沙子为0
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            sandpile_A[i][j] = 0;
            sandpile_B[i][j] = 0;
        }
    }

    //每次加sandpile_number粒沙子重复次数
    for (int Add = 0; Add < 1000000; Add++) {
        //记录雪崩的规模
        int Avalanche = 0;

        //弛豫记录时间长度
        int Time = 0;


        //实验开始---------------------------------------

        //随机添加沙粒sandpile_number
        //for (int N = 0; N < sandpile_number; N++) {
        //srand(time(NULL));//初始化随机数发生器

        sandpile_x = random(0,19); // [a,b] rand()%(b-a+1)+a；
        sandpile_y = random(0,19);
        // sandpile_x = 0;
        // sandpile_y = 0;
        sandpile_A[sandpile_x][sandpile_y]++; //也可乘以2或更多
        sandpile_B[sandpile_x][sandpile_y]++; 
        //}

        //此前应该判断到达稳定态与否再统计N=20200

        //弛豫时间T
        for (unsigned long T = 0; T < 10000000000000; T++) { 
            //判断是否存在雪崩Number == 200则不存在否则有
            int Number = 0;

            //遍历所有格子判断是否雪崩
            for (int x = 0; x < 20; x++) {
                for (int y = 0; y < 20; y++) {
                    //格子x,y存在雪崩
                    if (sandpile_A[x][y] > 3) { 
                        //处理边界情况
                        if (x == 0 ) {  
                            if (y == 0 ) {
                                sandpile_B[x][y] = sandpile_B[x][y] - 4;
                                sandpile_B[x][y+1] = sandpile_B[x][y+1] + 1;
                                sandpile_B[x+1][y] = sandpile_B[x+1][y] + 1;

                            }
                            else if(y == 19) {
                                sandpile_B[x][y] = sandpile_B[x][y] - 4;
                                sandpile_B[x][y-1] = sandpile_B[x][y-1] + 1;
                                sandpile_B[x+1][y] = sandpile_B[x+1][y] + 1;

                            }

                            else {
                                sandpile_B[x][y] = sandpile_B[x][y] - 4;
                                sandpile_B[x][y+1] = sandpile_B[x][y+1] + 1;
                                sandpile_B[x][y-2] = sandpile_B[x][y-1] + 1;
                                sandpile_B[x+1][y] = sandpile_B[x+1][y] + 1;

                            }
                        }
                        else if (x == 19) {
                            if (y == 0) {
                                sandpile_B[x][y] = sandpile_B[x][y] - 4;
                                sandpile_B[x][y+1] = sandpile_B[x][y+1] + 1;
                                sandpile_B[x-1][y] = sandpile_B[x-1][y] + 1;
                            }
                            else if (y == 19) {
                                sandpile_B[x][y] = sandpile_B[x][y] - 4;
                                sandpile_B[x][y-1] = sandpile_B[x][y-1] + 1;
                                sandpile_B[x-1][y] = sandpile_B[x-1][y] + 1;

                            }
                            else {
                                sandpile_B[x][y] = sandpile_B[x][y] - 4;
                                sandpile_B[x][y-1] = sandpile_B[x][y-1] + 1;
                                sandpile_B[x][y+1] = sandpile_B[x][y+1] + 1;
                                sandpile_B[x-1][y] = sandpile_B[x-1][y] + 1;
                            }
                        }
                        else if (y == 0 && x != 0 && x != 19) {
                            sandpile_B[x][y] = sandpile_B[x][y] - 4;
                            sandpile_B[x][y+1] = sandpile_B[x][y+1] + 1;
                            sandpile_B[x-1][y] = sandpile_B[x-1][y] + 1;
                            sandpile_B[x+1][y] = sandpile_B[x+1][y] + 1;

                        }
                        else if (y == 19 && x != 0 && x != 19) {
                            sandpile_B[x][y] = sandpile_B[x][y] - 4;
                            sandpile_B[x][y-1] = sandpile_B[x][y-1] + 1;
                            sandpile_B[x-1][y] = sandpile_B[x-1][y] + 1;
                            sandpile_B[x+1][y] = sandpile_B[x+1][y] + 1;

                        }
                        else {
                            sandpile_B[x][y] = sandpile_B[x][y] - 4;
                            sandpile_B[x][y+1] = sandpile_B[x][y+1] + 1;
                            sandpile_B[x][y-1] = sandpile_B[x][y-1] + 1;
                            sandpile_B[x-1][y] = sandpile_B[x-1][y] + 1;
                            sandpile_B[x+1][y] = sandpile_B[x+1][y] + 1;
                        }
                    } else Number++;
                }
            }

            //将B同步到A再对A进行遍历
            for (int i = 0; i < 20; i++) {
                for (int j = 0; j < 20; j++) {
                    sandpile_A[i][j] = sandpile_B[i][j];
                }
            }

            //当没有雪崩或雪崩结束时跳出循环
            if (Number == 400) {
                Time = T - 1;
                break; 
            } else Avalanche = Avalanche + 400 - Number;
        }

        //实验结束------------------------------------------

        //到达稳定态时开始计算统计 Sandpile Steady State
        if ( Add > 20000 ) {
            //计算雪崩规模S
            data_s.push_back(Avalanche);
            //计算T大小
            data_t.push_back(Time);

            data_s.shrink_to_fit();
            data_t.shrink_to_fit();
        }
    }  

    //统计S的频率
    map <int,int> data_s_s;
    for (size_t i = 0; i < data_s.size() ; ++i) {
        ++data_s_s[data_s[i]]; 
    }

    //统计T的频率
    map <int,int> data_t_t;
    for (size_t i = 0; i < data_t.size() ; ++i) {
        ++data_t_t[data_t[i]]; 
    }

    //分别将数组写入Txt文件    
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
