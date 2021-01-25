#include <iostream>
#include <ctime>
/*  
	clock(): 捕捉程序从运行到clock()被调用所用时间。
			 单位：clock tick（时钟打点）
	CLK_TCK: 机器每秒打点数             
*/

//CLK_TCK别拼错了 

clock_t start, stop;
double duration;

int main()
{
	start = clock();
	
	//MyFunction();
	
	stop = clock();
	duration = ( (double)( stop - start ) ) / CLK_TCK ;
	std::cout<<100000.0 * duration<<std::endl;
	
	return 0; 
 } 
