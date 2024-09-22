// combine.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <filesystem>
#include <string>
void renamefile(std::string& path) {
	std::vector<std::string> t;
	for (const auto& entry : std::filesystem::directory_iterator(path)) {
		auto filename = entry.path().filename();
		if (std::filesystem::is_regular_file(entry.status())) {
			t.push_back(path + "\\" + filename.string());
			std::cout << "Found file: " << path + "\\" + filename.string() << std::endl;
		}
	}
	if (t.empty())
	{
		std::cout << "这里没有文件\n";
		return;
	}
	else
	{
		int di = 0;
		for (auto i: t)
		{		
			di++;
			std::cout << i.c_str() << "-->" << (i.substr(0, i.find_last_of('\\') + 1) + std::to_string(di) + ".jpg.nmlgb").c_str() << std::endl;
			rename(i.c_str(), (i.substr(0, i.find_last_of('\\') + 1) + std::to_string(di) + ".jpg.nmlgb").c_str());
		}
	}
	t.clear();
	for (const auto& entry : std::filesystem::directory_iterator(path)) {
		auto filename = entry.path().filename();
		if (std::filesystem::is_regular_file(entry.status())) {
			t.push_back(path + "\\" + filename.string());
			//std::cout << "Found file: " << path + "\\" + filename.string() << std::endl;
		}
	}
	for (auto i : t)
	{		
		std::cout << i.c_str() << "-->" << i.substr(0, i.find_last_of('.')).c_str() << std::endl;
		rename(i.c_str(), i.substr(0, i.find_last_of('.')).c_str());
	}
}

void combinefile(std::string& path1, std::string& path2) {
	int f_count = 0;
	std::vector<std::string> t;
	for (const auto& entry : std::filesystem::directory_iterator(path1)) {
		auto filename = entry.path().filename();
		if (std::filesystem::is_regular_file(entry.status())) {
			t.push_back(path1 + "\\" + filename.string());
			std::cout << "Found file: " << path1 + "\\" + filename.string() << std::endl;
		}
	}
	if (!t.empty())
	{
		for (auto i : t)
		{
			f_count++;
			std::cout << i.c_str() << "-->" << (i.substr(0, i.find_last_of('\\') + 1) + std::to_string(f_count) + ".jpg.nmlgb").c_str() << std::endl;
			rename(i.c_str(), (i.substr(0, i.find_last_of('\\') + 1) + std::to_string(f_count) + ".jpg.nmlgb").c_str());
		}
		t.clear();
	}
	for (const auto& entry : std::filesystem::directory_iterator(path2)) {
		auto filename = entry.path().filename();
		if (std::filesystem::is_regular_file(entry.status())) {
			t.push_back(path2 + "\\" + filename.string());
			std::cout << "Found file2: " << path2 + "\\" + filename.string() << std::endl;
		}
	}
	if (!t.empty())
	{
		for (auto i : t)
		{
			f_count++;
			std::cout << i.c_str() << "-->" << (path1 + "\\" + std::to_string(f_count) + ".jpg.nmlgb").c_str() << std::endl;
			std::filesystem::rename(i.c_str(), (path1 + "\\" + std::to_string(f_count) + ".jpg.nmlgb").c_str());
		}
		t.clear();
	}
	for (const auto& entry : std::filesystem::directory_iterator(path1)) {
		auto filename = entry.path().filename();
		if (std::filesystem::is_regular_file(entry.status())) {
			t.push_back(path1 + "\\" + filename.string());
			std::cout << "Found file1: " << path1 + "\\" + filename.string() << std::endl;
		}
	}
	for (auto i : t)
	{
		std::cout << i.c_str() << "-->" << i.substr(0, i.find_last_of('.')).c_str() << std::endl;
		rename(i.c_str(), i.substr(0, i.find_last_of('.')).c_str());
	}
}

int main(int argc, char** argv)
{
	if (argc == 2)//排列图片名字
	{
		std::cout << "开始整理的文件夹：" << argv[1] << std::endl;
		std::string t = argv[1];
		renamefile(t);
		return 0;
	}
	if (argc == 3)
	{
		std::cout << "开始合并的文件夹：" << argv[1] << " & " << argv[2] << std::endl;
		std::string t1 = argv[1];
		std::string t2 = argv[2];
		combinefile(t1, t2);
		return 0;
	}
    std::cout << "使用说明：\n";
	std::cout << "请使用命令行：cmd.exe\n";
	std::cout << "【1】combine.exe 文件夹\n";
	std::cout << "【2】combine.exe 文件夹1 文件夹2\n";
	std::cout << "【1】整理文件夹内的文件使其从1依次递增命名便于训练";
	std::cout << "【2】把文件夹2的文件移动到文件夹1，并整理文件夹1内的文件使其从1依次递增命名便于训练";
	std::cout << "instructions:\n";
	std::cout << "Please use the command line: cmd.exe\n";
	std::cout << "[1]combine.exe DIR\n";
	std::cout << "[2]combine.exe DIR1 DIR2\n";
	std::cout << "[1]Organize the files in the folder so that they are named incrementally from 1 to facilitate training\n";
	std::cout << "[2]Move the files from folder 2 to folder 1, and organize the files in folder 1 so that they are named incrementally from 1 to facilitate training\n";
	getchar();
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
