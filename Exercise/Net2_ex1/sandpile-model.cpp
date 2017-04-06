#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <numeric>
#include <map>
//#include "gnuplot-iostream.h"
//#include <mgl2/mgl.h>
//#include <algorithm>
//#include <unordered_map>
//TODO 可以直接用一个变量控制
//TODO About T 随着T的变化 
#define random(a,b) (rand()%(b-a+1)+a)

using namespace std;
int main()
{

    std::vector< int > state; //记录其随T的变化当存在雪崩时则为1否则为0
    int sandpile_number = 2; //每次增加N-1粒沙子
    int sandpile_x,sandpile_y;//随机加沙的坐标
    int sandpile_A[100][100],sandpile_B[100][100]; //定义两个数组进行对称交换——使得其能同时更新-一个判断雪崩一个计算更新
    int status[100][100];//扩散状态——当雪崩扩散至此时为1状态标记否则为0
    //int state[100000000000000];//雪崩的大小S——对N次雪崩的规模进行统计
    int data_s[100000000];//存储不同规模下雪崩大小的数据       
    int data_t[100000000]; //记录每次实验T的大小

    //int data_p[10];//存储雪崩概率的数据

    //初始化数组
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            sandpile_A[i][j] = 0;
            sandpile_B[i][j] = 0;
        }
    }

    //使得每次实验沙堆的大小增加到很大很大Add次数越多规模越大
    //方案2:每次加1粒沙子重复1000000000000

    for (int Add = 0; Add < 100000000; Add++) {
        //int sandpile_number = 100;
        ////每次多增加10粒沙子
        //sandpile_number = sandpile_number + 10;

        //每次增加一粒沙子
        //sandpile_number ++;

        //实验开始
        //初始化状态
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                status[i][j] = 0;
            }
        }

        //初始化vector
        // vector<int> state; //记录其随T的变化当存在雪崩时则为1否则为0      规范：此定义全部在外围
        //cout << "-1-" << state.capacity();

        //随机添加沙粒sandpile_number
        for (int N = 0; N < sandpile_number; N++) {
            //srand(time(NULL));//初始化随机数发生器
            sandpile_x = random(0,99); // [a,b] rand()%(b-a+1)+a；
            sandpile_y = random(0,99);
            sandpile_A[sandpile_x][sandpile_y]++; //也可乘以2或更多
            sandpile_B[sandpile_x][sandpile_y]++; 
        }

        for (unsigned long T = 0; T < 1000000000000000; T++) { //弛豫时间T
            int Number = 0;

            //遍历所有格子判断是否雪崩
            for (int x = 0; x < 100; x++) {
                for (int y = 0; y < 100; y++) {
                    if (sandpile_A[x][y] <= 3 ) { //不存在雪崩
                        Number ++;
                    }

                    if (sandpile_A[x][y] > 3 ) { //存在雪崩
                        if (x == 0 ) { //处理边界情况
                            if (y == 0 ) {
                                sandpile_B[x][y] = sandpile_B[x][y] - 4;
                                sandpile_B[x][y+1] = sandpile_B[x][y+1] + 1;
                                sandpile_B[x+1][y] = sandpile_B[x+1][y] + 1;

                                status[x][y] = 1;
                                status[x][y+1] = 1;
                                status[x+1][y] = 1;
                            }
                            if (y == 99) {
                                sandpile_B[x][y] = sandpile_B[x][y] - 4;
                                sandpile_B[x][y-1] = sandpile_B[x][y-1] + 1;
                                sandpile_B[x+1][y] = sandpile_B[x+1][y] + 1;

                                status[x][y] = 1;
                                status[x][y-1] = 1;
                                status[x+1][y] = 1;
                            }
                            else {
                                sandpile_B[x][y] = sandpile_B[x][y] -4;
                                sandpile_B[x][y+1] = sandpile_B[x][y+1] +  1;
                                sandpile_B[x][y-1] = sandpile_B[x][y-1] + 1;
                                sandpile_B[x+1][y] = sandpile_B[x+1][y] + 1;

                                status[x][y] = 1;
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

                                status[x][y] = 1;
                                status[x][y+1] = 1;
                                status[x-1][y] = 1;
                            }
                            if (y == 99) {
                                sandpile_B[x][y] = sandpile_B[x][y] -4;
                                sandpile_B[x][y-1] = sandpile_B[x][y-1] +  1;
                                sandpile_B[x-1][y] = sandpile_B[x-1][y] + 1;

                                status[x][y] = 1;
                                status[x][y-1] = 1;
                                status[x-1][y] = 1;

                            }
                            else {
                                sandpile_B[x][y] = sandpile_B[x][y] - 4;
                                sandpile_B[x][y-1] = sandpile_B[x][y-1] + 1;
                                sandpile_B[x][y+1] = sandpile_B[x][y+1] + 1;
                                sandpile_B[x-1][y] = sandpile_B[x-1][y] + 1;

                                status[x][y] = 1;
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

                                status[x][y] = 1;
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

                                status[x][y] = 1;
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
                    // sandpile_B[i][j] = 0;
                }
            }

            ////雪崩规模随着T变化
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
            } else {
                state.push_back(1);
            }
        }

        //计算雪崩规模S
        int size = 0;
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                size = size + status[i][j];
            }
        }

        //计算迟豫时间的大小
        //int time = 0;
        //for (int i = 0; i < 100; i++) {
        //    for (int j = 0; j < 100; j++) {
        //        time = time + state[i][j];
        //    }
        //}

        //写入数据
        data_s[Add] = size;
        data_t[Add] = accumulate(state.begin() , state.end(),0);

        //释放内存:清除容器并最小化它的容量
        //cout << "-2-" << state.capacity();
        //vector<int>(state).swap(state);
        state.clear();
        state.shrink_to_fit();
        //vector<int>().swap( state );
        //cout << "-3-" << state.capacity();
    }  

    //输出
    //for (int i = 0; i < 10000; i++) {
    //    cout << "-" << data_s[i];
    //    //cout << "-" << data_p[i];
    //}

    //TODO 对数据进行排序和统计 http://biancheng.dnbcw.net/c/394200.html
    //int maxnum = 0;
    //int minnum = 0;
    //for (int i = 0; i < 10000; i++) {
    //    if (maxnum > data_s[i]) maxnum = data_s[i];
    //    if (minnum > data_s[i]) minnum = data_s[i];
    //}

    //可变数组vector存储数据 
    //vector <int> data_s_s; 
    //vector <int> data_s_p; 
    //for (int i = 0; i < 10000; i++) {
    //}

    //统计S的频率
    map <int,int> data_s_s;
    for (int i = 0; i < 100000000; ++i) {
        ++data_s_s[data_s[i]]; 
    }
    //cout << "Greatest: " << data_s_s.rbegin()->first << '\n';

    map <int,int> data_t_t;
    for (int i = 0; i < 100000000; ++i) {
        ++data_t_t[data_t[i]]; 
    }

    //输出
    // using iterator = map< int, int >::iterator;
    // for ( iterator iter = data_s_s.begin(); iter != data_s_s.end(); ++iter  )
    //   cout << iter->first << ": " << iter->second << '\n';

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

