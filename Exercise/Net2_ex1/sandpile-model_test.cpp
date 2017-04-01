#include <iostream>
#include <vector>
// #include <stdlib.h>
//#include "gnuplot-iostream.h"
// #include <mgl2/mgl.h>


//TODO About T 随着T的变化 
#define random(a,b) (rand()%(b-a+1)+a)

using namespace std;
int main()
{
    int sandpile_A[10][10],sandpile_B[10][10]; //定义两个数组进行对称交换——使得其能同时更新-一个判断一个计算更新
    int status[10][10];//扩散状态——当雪崩扩散至此时为1状态标记否则为0
    //int state[10];//雪崩状态——N次实验发生雪崩的概率——状态0 or 1
    int sizes[20];//雪崩的大小S——对N次雪崩的规模进行统计
    int data_s[100];//存储不同规模下雪崩大小的数据
    //int data_p[10];//存储雪崩概率的数据
    vector <int> data_t; //Folow T Change

    //使得每次实验沙堆的大小增加到很大很大Add次数越多规模越大
    //方案2:每次加1粒沙子重复1000000000000

    int sandpile_number = 100;
    for (int Add = 0; Add < 100; Add++) {
        //每次多增加10粒沙子
        sandpile_number = sandpile_number + 10;
        for (int i = 0; i < 10; i++) {
            //state[i] = 0;
            sizes[i] = 0;
        }

        //相同条件下重复进行n次实验发生计算雪崩概率--考虑是否应该平均化处理:这样的随机性更强了，可以考虑在之前的基础上加沙
        for (int n = 0; n < 20; n++) { 

            //初始化数组
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    sandpile_A[i][j] = 0;
                    sandpile_B[i][j] = 0;
                    status[i][j] = 0;
                }
            }

            //添加沙粒sandpile_number
            for (int N = 0; N < sandpile_number; N++) { 
                int sandpile_x,sandpile_y;
                sandpile_x = random(0,9); // [a,b] rand()%(b-a+1)+a；
                sandpile_y = random(0,9);
                sandpile_A[sandpile_x][sandpile_y]++; //也可乘以2或更多
                sandpile_B[sandpile_x][sandpile_y]++;
            }

            //            for (int x = 0; x < 10; x++) {
            //                for (int y = 0; y < 10; y++) {
            //                    cout << "-" << sandpile_A[x][y];
            //                    }
            //                }

            for (int T = 0; T < 10000000; T++) { //弛豫时间T
                int Number = 0;
                //遍历所有格子

                for (int x = 0; x < 10; x++) {
                    for (int y = 0; y < 10; y++) {
                        if (sandpile_A[x][y] <= 3 ) { //不存在雪崩
                            Number ++;
                        }

                        if (sandpile_A[x][y] > 3 ) { //存在雪崩
                            //state[n] = 1;//发生雪崩的状态
                            if (x == 0 ) { //处理边界情况
                                if (y == 0 ) {
                                    sandpile_B[x][y] = sandpile_B[x][y] - 4;
                                    sandpile_B[x][y+1] = sandpile_B[x][y+1] + 1;
                                    sandpile_B[x+1][y] = sandpile_B[x+1][y] + 1;

                                    status[x][y] = 1;
                                    status[x][y+1] = 1;
                                    status[x+1][y] = 1;
                                }
                                if (y == 9) {
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
                            if (x == 9 ) {
                                if (y == 0) {
                                    sandpile_B[x][y] = sandpile_B[x][y] -4;
                                    sandpile_B[x][y+1] = sandpile_B[x][y+1] + 1;
                                    sandpile_B[x-1][y] = sandpile_B[x-1][y] + 1;

                                    status[x][y] = 1;
                                    status[x][y+1] = 1;
                                    status[x-1][y] = 1;
                                }
                                if (y == 9) {
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
                                if (x != 0 || x != 9) {
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
                            if (y == 9) {
                                if (x != 0 || x != 9) {
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
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        sandpile_A[i][j] = sandpile_B[i][j];
                        // sandpile_B[i][j] = 0;
                    }
                }

                //雪崩规模随着T变化
                //int s = 0;
                //for (int i = 0; i < 10; i++) {
                //    for (int j = 0; j < 10; j++) {
                //        s = s + status[i][j];
                //    }
                //}
                //data_t.push_back(s);

                //当没有雪崩时跳出循环
                if (Number == 100) {
                    break; 
                }
            }

            //计算雪崩规模S
            int size = 0;
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    size = size + status[i][j];
                }
            }
            //计入数组
            sizes[n] = size;
        }

        //计算雪崩大小的20次实验的平均
        // int p = 0;
        int size_average = 0;
        for (int i = 0 ; i < 20; i++) {
            //p = p + state[i]/10;
            size_average = size_average + sizes[i]/20;
        }

        //写入数据
        data_s[Add] = size_average;
        //data_p[Add] = p;
    }  

    for (int i = 0; i < 100; i++) {
        cout << "-" << data_s[i];
        //cout << "-" << data_p[i];
    }

    return 0;
}

