//#pragma once
//#include <iostream>
//#include "libxl.h"
//#include <string>
//#include <string.h>
//#include <vector>
//using namespace libxl;
//using namespace std;
//class fromExcel
//{
//
//    //כתיבת נתונים לפי עמודות
//
//    int main() {
//        Book* book = xlCreateBook(); // Create a new Excel workbook
//
//        if (book) {
//            Sheet* sheet = book->addSheet("dd"); // Add a new sheet to the workbook
//
//            if (sheet) {
//                // Data to write to the Excel file by columns
//                std::vector<std::vector<std::string>> data = {
//                    {"Name", "Age", "City"},
//                    {"Alice", "25", "New York"},
//                    {"Bob", "30", "London"},
//                    {"Charlie", "22", "Paris"}
//                };
//
//                // Write data to Excel by columns
//                for (size_t col = 0; col < data[0].size(); col++) {
//                    for (size_t row = 0; row < data.size(); row++) {
//                        sheet->write(row + 1, col + 1, data[row][col].c_str()); // Write data to the sheet
//                    }
//                }
//
//                // Save the Excel file
//                if (book->save("output.xlsx")) {
//                    std::cout << "Data has been written to the Excel file." << std::endl;
//                }
//                else {
//                    std::cerr << "Error saving the Excel file." << std::endl;
//                }
//            }
//
//            book->release(); // Release the Excel workbook
//        }
//        else {
//            std::cerr << "Error creating the Excel workbook." << std::endl;
//        }
//
//        return 0;
//    }
//
//
//    //כתיבה לפי גיליונות
//
//
//    int main() {
//        Book* book = xlCreateBook(); // Create a new Excel workbook
//
//        if (book) {
//            std::wstring name(L"st");
//            const wchar_t* szName = name.c_str();
//            // Add Sheet1
//            Sheet* sheet1 = book->addSheet(szName,sheet1); // Add a new sheet to the workbook
//            if (sheet1) {
//                // Data for Sheet1
//                std::vector<std::vector<std::string>> dataSheet1 = {
//                    {"Name", "Age", "City"},
//                    {"Alice", "25", "New York"},
//                    {"Bob", "30", "London"},
//                    {"Charlie", "22", "Paris"}
//                };
//
//                std::vector<std::vector<std::wstring>> dataSheet1_wstring;
//
//                for (const auto& row : dataSheet1) {
//                    std::vector<std::wstring> newRow;
//                    for (const auto& cell : row) {
//                        // Convert std::string to std::wstring
//                        std::wstring wcell(cell.begin(), cell.end());
//                        newRow.push_back(wcell);
//                    }
//                    dataSheet1_wstring.push_back(newRow);
//                }
//
//                // Write data to Sheet1 by columns
//                for (size_t col = 0; col < dataSheet1[0].size(); col++) {
//                    for (size_t row = 0; row < dataSheet1.size(); row++) {
//                        sheet1->writeStr(row + 1, col + 1, dataSheet1_wstring[row][col].c_str()); // Write data to Sheet1
//                    }
//                }
//            }
//
//            // Add Sheet2
//            Sheet* sheet2 = book->addSheet("Sheet2"); // Add another sheet to the workbook
//            if (sheet2) {
//                // Data for Sheet2
//                std::vector<std::vector<std::string>> dataSheet2 = {
//                    {"Company", "Revenue"},
//                    {"ABC Corp", "1000000"},
//                    {"XYZ Inc", "750000"},
//                    {"123 Company", "500000"}
//                };
//
//                // Write data to Sheet2 by columns
//                for (size_t col = 0; col < dataSheet2[0].size(); col++) {
//                    for (size_t row = 0; row < dataSheet2.size(); row++) {
//                        sheet2->write(row + 1, col + 1, dataSheet2[row][col].c_str()); // Write data to Sheet2
//                    }
//                }
//            }
//
//            // Save the Excel file
//};
//
