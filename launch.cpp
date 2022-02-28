#include <chrono>
#include <iostream>
#include <fstream>
#include <errno.h>
#include "Rapl.h"
#include <string.h>

using namespace std;


int main (int argc, char *argv[])
{
    int N = atoi(argv[2]);
    Rapl *rapl = new Rapl();
    int ms_pause = 100;       // sample every 100ms
	std::ofstream outfile ("rapl.csv", std::ios::out | std::ios::trunc);
	outfile << "Time" << ","
			<< "pp0 power" << ","
			<< "pkg power" << ","
			<< "pp1 power" << ","
			<< "dram power" << std::endl;
	bool started = false;
	float total_time;
	std::cout << "Running " << argv[1] << " " << N << " times" << std::endl;

    for ( int i = 0 ; i < N ; i ++ ) {
        std::cout << "Step " << i << std::endl;
        rapl->sample();
        float pkg_current_power = rapl->pkg_current_power();
		float pp0_current_power = rapl->pp0_current_power();
		float pp1_current_power = rapl->pp1_current_power();
		float dram_current_power = rapl->dram_current_power();
		if (! started){
    		total_time = rapl->total_time();
    		started = true;
    	}
        int exec_status = system(argv[1]);
		if (exec_status) {
			std::cout << "execv failed with error " << errno << " " << strerror(errno) << std::endl;
			return exec_status;
		}
        rapl->sample();
        float pkg_current_power_2 = rapl->pkg_current_power();
		float pp0_current_power_2 = rapl->pp0_current_power();
		float pp1_current_power_2 = rapl->pp1_current_power();
		float dram_current_power_2 = rapl->dram_current_power();
		float total_time_2 = rapl->total_time();
		outfile << total_time_2 - total_time << ","
				<< pp0_current_power_2 - pp0_current_power << ","
				<< pkg_current_power_2 - pkg_current_power << ","
				<< pp1_current_power_2 - pp1_current_power << ","
				<< dram_current_power_2 - dram_current_power << std::endl;
    }
    return 0;
}
