#pragma once
#include <map>
#include <string>
#include <iostream>
using namespace std;
class carsInSt
{
private:
	std::map<string, int> cars;
	bool values[4] = { false, false, false, false };

public:
	int index(string id)
	{
		int index = 0;
		for (const auto& pair : cars)
		{
			if (pair.first == id)
			{
				return index;
				break;
			}
			index++;
		}
		return -1;
	}

	void add_new_car(string id_car) 
	{
		cars[id_car]++;
		int i = index(id_car);
		if (i != -1) 
		{
			values[i] = true;
			FILE* pipe = _popen("python receiver.py", "w");
			if (!pipe) {
				std::cerr << "Error opening pipe" << std::endl;
			}

			// Write boolean values to the pipe
			for (bool value : values) {
				std::string str_value = value ? "True" : "False";
				fprintf(pipe, "%s\n", str_value.c_str());
			}

			_pclose(pipe);
			values[i] = false;


		}
			

	}
};

