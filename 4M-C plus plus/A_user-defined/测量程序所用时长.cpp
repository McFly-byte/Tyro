#include <iostream>
#include <ctime>
/*  
	clock(): ��׽��������е�clock()����������ʱ�䡣
			 ��λ��clock tick��ʱ�Ӵ�㣩
	CLK_TCK: ����ÿ������             
*/

//CLK_TCK��ƴ���� 

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
