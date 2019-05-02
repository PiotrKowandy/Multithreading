/*
Multithreading, Sum of two vectors;
*/

#include <iostream>
#include <vector>
#include <thread>

void add_elements(std::vector<int> &v, int &sum, int number){
    std::cout<< "\n\n";
    std::cout<< "I'm thread " << number;
    for (auto e : v){
        sum +=e;
    }
    std::cout<< "\n\n";
}


int main (int argc, char *argv[]){

    std::vector<int> v1 = {3,5,7,3,2}, v2 = {4,1,1,2,0};
    int sum1=0, sum2=0;

	std::thread first (add_elements, std::ref(v1), std::ref(sum1), 1);
	std::thread second (add_elements, std::ref(v2), std::ref(sum2), 2);

	std::cout<< "Both threads are running concurrently.\n";

	first.join();
	second.join();

    std::cout<<"Sum1 = " << sum1 <<"\n";
    std::cout<<"Sum2 = " << sum2 <<"\n\n";
    std::cout<<"Sum1 + Sum2 = " << sum1+sum2 <<"\n";

	return 0;
}
