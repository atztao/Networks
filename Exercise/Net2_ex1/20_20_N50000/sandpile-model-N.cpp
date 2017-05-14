/*-----------------------------------------------------
Name:Sandpile-Model-N
Description:This Program Get The Sandpile Model -When To Arrive At Steady State.
Author:ztao14191@gmail.com
Date:2017/04/04
Version:1.0.1
Github:github.com/ztao14190/Networks/blob/master/Exercise/Net2_ex1/sandpile-model.cpp
Cpp-Style Form :http://zh-google-styleguide.readthedocs.io/en/latest/google-cpp-styleguide/
-----------------------------------------------------*/
#include <iostream>
#include <fstream>
#define random(a,b) (rand()%(b-a+1)+a)

using namespace std;

int main()
{
    //随机加沙的坐标
    int sandpile_x,sandpile_y; 
//定义两个数组进行对称交换——使得其能同时更新-一个判断雪崩一个计算更新
    int sandpile_A[20][20],sandpile_B[20][20];
    //记录沙堆的高度,寻求稳定态 N=20000开始趋于稳定
    int data_N[50000];

    //初始化数组每格沙子为0
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            sandpile_A[i][j] = 0;
            sandpile_B[i][j] = 0;
        }
    }

    //每次加sandpile_number粒沙子重复次数
    for (int Add = 0; Add < 100000; Add++) {

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

        //弛豫时间T
        for (unsigned long T = 0; T < 200000000000000; T++) { 
            //判断是否存在雪崩Number == 2000则不存在否则有
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
                            else if (y == 19) {
                                sandpile_B[x][y] = sandpile_B[x][y] - 4;
                                sandpile_B[x][y-1] = sandpile_B[x][y-1] + 1;
                                sandpile_B[x+1][y] = sandpile_B[x+1][y] + 1;
                            }
                            else {
                                sandpile_B[x][y] = sandpile_B[x][y] - 4;
                                sandpile_B[x][y+1] = sandpile_B[x][y+1] + 1;
                                sandpile_B[x][y-1] = sandpile_B[x][y-1] + 1;
                                sandpile_B[x+1][y] = sandpile_B[x+1][y] + 1;
                            }
                        }
                        else if (x == 19 ) {
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
            if (Number == 400) break; 
        }
        //实验结束------------------------------------------

        //计算沙粒的总和
        int Sum_Sand = 0;
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                Sum_Sand = Sum_Sand + sandpile_A[i][j];
            }
        }

        data_N[Add] = Sum_Sand;
    }  

    //分别将数组写入Txt文件    
    ofstream file3("sandpile-model_N.txt");
    if (file3.is_open())
    {
        for (int i = 0; i < 50000; ++i) {
            file3 << data_N[i] << "\n";
        }
        file3.close();
    } else cout << "Unable to open file";

    //Python 处理后期数据

    return 0;
}
