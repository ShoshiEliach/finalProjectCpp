// try.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <string>
#include "string.h"
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
#include <mutex>
using namespace std;
std::mutex mtx;

functions2 f;
vector<node> vecTry;
nodesManager nm; 
static void Always_rand(nodesManager f, std::mutex& mtx);
static void thread_logic_trrafic(node& n,  std::mutex& mtx);
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
    std::vector<std::shared_ptr<std::mutex>> shared_mtxs;


    //תהליכונים של ניהול רמזור בצומת
    for (auto& node : *nodes) 
    {

         {
            std::shared_ptr<std::mutex> shared_mtx = std::make_shared<std::mutex>(mtx);


            threads_trraficLogic.emplace_back([&node, &shared_mtx]() 
                {
                thread_logic_trrafic(node,*shared_mtx);
                });
            shared_mtxs.push_back(shared_mtx);

        }
    }

    auto thread_rand = std::thread(Always_rand, std::ref(nm), std::ref(mtx));

    std::thread simulation(runSimulation);  // Create a thread for runSimulation
    
     
    std::thread get_num_cars(getNumcarsAndId);  // Create a thread for getNumcarsAndId

     


    //join

    for (auto& t : threads_trraficLogic)
    {
        t.join();
    }
    thread_rand.join();
    simulation.join();  
     Wait for thread t1 to finish
    get_num_cars.join();
   for (auto& w : threads_overWaiting)
    {
        w.join();
    }
    for (auto& p : threads_overWaiting)
    {
        p.join();
    }
    thread_rand.join();
}
void Always_rand(nodesManager f, std::mutex& mtx)
{
    while (true)
    {

        //cout << f.getAllNodes()[0].getIdNode() << endl;

       
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis3(1, 10);
        int When = dis3(gen);
        cout << When << endl;
        std::this_thread::sleep_for(std::chrono::seconds(When));
        cout << "I insert cars!!!" << endl;
        std::lock_guard<std::mutex> lock(mtx);

        map<std::string, st> sts = f.getAllNodes()->at(1).getNodeSt();


        for (auto& s : sts) {
            //read from file
            int num_cars = rand() % 7;
            for (size_t i = 0; i < num_cars; i++)
            {
                s.second.addCar(std::chrono::system_clock::now(), 0);
            }
        }
    }
    
}

void thread_logic_trrafic(node& n,  std::mutex& mtx)
{
    std::lock_guard<std::mutex> lock(mtx);

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