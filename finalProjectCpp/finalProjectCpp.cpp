// finalProjectCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "string.h"
<<<<<<< HEAD
using namespace std;
int main()
{
    string name_ss;
    std::cout << "Hello World!\n";
    std::cin >> name_ss;
    std::cout << name_ss;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
=======
#include <thread>
#include "functions2.h"
#include "nodesManager.h"
#include "node.h"
#include <random>
#include <functional>
#include <sstream>
#include <iterator>
#include <stdio.h>
#include <cwchar>
#include <array>
using namespace std;
functions2 f;
vector<node> vecTry;
nodesManager nm; 
static void Always_rand(nodesManager f);
static void thread_logic_trrafic(node& n);
void getValuesFromMicro(std::string id, int numCars);
void runSimulation();
void getNumcarsAndId();
void processIdNumCars(const std::string& values);
using namespace std;
int main()
{
   
    f.read_graph(nm);

    std::vector<std::thread> threads_trraficLogic;
    std::vector<std::thread> threads_overWaiting;
    std::vector<std::thread> threads_updatePriority;
    std::vector<node>* nodes = nm.getAllNodes(); 

    //תהליכונים של ניהול רמזור בצומת
    for (auto& node : *nodes) {
         {

            threads_trraficLogic.emplace_back([&node]() {
                thread_logic_trrafic(node);
                });
        }
    }

    auto thread_rand = std::thread(Always_rand, std::ref(nm));

    //std::thread simulation(runSimulation);  // Create a thread for runSimulation
    //להחזיר
    // 
    //std::thread get_num_cars(getNumcarsAndId);  // Create a thread for getNumcarsAndId

     


    //join

    for (auto& t : threads_trraficLogic)
    {
        t.join();
    }
    thread_rand.join();
    //simulation.join();  // Wait for thread t1 to finish
    ///להחזיר!!!!
    //get_num_cars.join();
   /* for (auto& w : threads_overWaiting)
    {
        w.join();
    }
    for (auto& p : threads_overWaiting)
    {
        p.join();
    }
    thread_rand.join();*/
}
void Always_rand(nodesManager f)
{
    while (true)
    {
        //cout << f.getAllNodes()[0].getIdNode() << endl;

        //����� �� ��� ��� ������
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis3(1, 10);
        int When = dis3(gen);
        //cout << When << endl;
        std::this_thread::sleep_for(std::chrono::seconds(When));
        //cout << "I insert cars!!!" << endl;
        //��� ����� �� ������
        map<std::string, st> sts = f.getAllNodes()->at(1).getNodeSt();


        for (auto& s : sts) {
            //לקרוא מקובץ
            int num_cars = rand() % 7;
            for (size_t i = 0; i < num_cars; i++)
            {
                s.second.addCar(std::chrono::system_clock::now(), 0);
            }
        }
    }
    
}

void thread_logic_trrafic(node& n)
{
    //cout << "111" << endl;

    n.manageNode();
    

}

void getValuesFromMicro(string id, int numCars) {
    nodesManager nM;
    for (size_t i = 0; i < numCars; i++)
    {
        nM.getNodeById(5)->getNodeSt()[id].addCar(std::chrono::system_clock::now(), 0);

    }
}

void runSimulation()
{
    const char* cmd = "C:\\Users\\User\\Desktop\\runPython.bat";
    //קובץ האצווה של הסימולציה
    std::unique_ptr<FILE, decltype(&_pclose)> pipe1(_popen(cmd, "r"), _pclose);
    if (!pipe1) {
        throw std::runtime_error("popen() failed for cmd!");
    }

   /* int num_cars;
    std::string id_st;

    FILE* pipe = _popen("C:\\Users\\User\\Documents\\finalProject\\main.py", "r+");
    if (!pipe) {
        std::cerr << "Error opening pipe to Python simulation\n";
    }
    fscanf(pipe, "%d", &num_cars);
    fscanf(pipe, "%s", &id_st[0]);*/

}

void getNumcarsAndId()
{
    const char* cmd2 = "C:\\Users\\User\\Documents\\finalProject\\runNumCars.bat";
    std::string result1, result2;
    std::array<char, 128> buffer;





    //קובץ האצווה של מספר הרכבים
    std::unique_ptr<FILE, decltype(&_pclose)> pipe2(_popen(cmd2, "r"), _pclose);
    if (!pipe2) {
        throw std::runtime_error("popen() failed for cmd2!");
    }

    //קריאת הנתונים מהקובץ של מספר הרכבים
    while (fgets(buffer.data(), buffer.size(), pipe2.get()) != nullptr) {
        processIdNumCars(buffer.data());

        //result2 += buffer.data();
    }
}


void processIdNumCars(const std::string& values) {
    //cout << "in" << endl;
    std::istringstream iss(values);
    int number;
    std::string id;

    if (iss >> number >> id) {
        // Check if the number is not equal to 0
        if (number != 0) {
            // Call another function with the extracted values
            // For example:
            // anotherFunction(id, number);
            //std::cout << "resulttt: " << number << ", ID: " << id << std::endl;
        }
    }
}
>>>>>>> 291b4d0c445a10d666ce58a2a6915f0dfd4d609a
