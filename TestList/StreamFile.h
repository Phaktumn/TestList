//#define STREAM_FILE_H
//#ifdef STREAM_FILE_H
//
//#ifndef __cplusplus
//#error A C++ compiler is required!
//#endif
//
//#include "stdafx.h"
//#include <fstream>
//#include <string>
//#include <ctime>
//
//using namespace std;
//#define TRUE   1
//#define FALSE  0
// 
//#define _IF  10
//#define _OF  9
//
//class IO
//{
//public:
//	IO();
//	explicit IO(const string _file_);
//	void print_toFile(const string _Name, const string _Info);
//	void print_toFile_Error(const string _Info);	
//	void print_toFile(const string _Info);
//	const string& read_fromFile(const string _Name);
//	int openFile(int);
//	int closeFile(int);
//private:
//	int isOpen(int) const;
//	ofstream of_File;
//	ifstream if_File;
//	string _File_Name;
//};
//
//inline IO::IO()
//{//Default Constructor
//}
//
//inline IO::IO(const string _file_){
//	_File_Name = _file_;
//}
//
//inline void IO::print_toFile(const string _Name, const string _Info)
//{
//	time_t t = time(0);
//	of_File << "[" << _Name.c_str() << "]" << " INFO:  " 
//		<< _Info.c_str() << "   ->" << __DATE__ << " " << localtime(&t)->tm_hour << ":" << localtime(&t)->tm_min << ":" << localtime(&t)->tm_sec << "\n";
//}
//
//inline void IO::print_toFile_Error(const string _Info)
//{
//	time_t t = time(0);
//	of_File << "[ERROR]" << " INFO:  "
//		<< _Info.c_str() << "   ->" << __DATE__ << " " << localtime(&t)->tm_hour << ":" << localtime(&t)->tm_min << ":" << localtime(&t)->tm_sec << "\n";
//}
//
//inline void IO::print_toFile(const string _Info)
//{
//	of_File << _Info.c_str() << "\n";
//}
//
//inline const string& IO::read_fromFile(const string _Name)
//{
//	string _Aux;
//	if(openFile(_IF))
//		while ( getline(if_File, _Aux)) {
//			return _Aux;
//		}
//	closeFile(_IF);
//	return string(nullptr);
//}
//
//inline int IO::isOpen(int i) const{
//	if(i == _OF)
//		return of_File.is_open();
//	if (i == _IF)
//		return if_File.is_open();
//	return -1;
//}
//
///* Open file param = file type 9 for ifstream 10 for of stream */
//inline int IO::openFile(int i)
//{
//	if (i == _OF){
//		if(isOpen(_OF)){
//			print_toFile_Error("File Already Open");
//			return FALSE;
//		}
//		of_File = ofstream(_File_Name.c_str());
//		return TRUE;
//	}	
//	if (isOpen(_IF)) {
//		print_toFile_Error("File Already Open");
//		return FALSE;
//	}
//	if_File = ifstream(_File_Name.c_str());
//	return TRUE;
//}
//
//inline int IO::closeFile(int i)
//{
//	if (i == _OF){
//		if (!isOpen(_OF)){
//			print_toFile_Error("File Not Open");
//			return FALSE;
//		}
//		of_File.close();
//		return TRUE;
//	}
//	if (!isOpen(_IF)) {
//		print_toFile_Error("File Not Open");
//		return FALSE;
//	}
//	if_File.close();
//	return FALSE;
//}
//#endif
