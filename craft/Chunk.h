#pragma once
#include<iostream>
#include<vector>
#include"CubeManager.h"

/**
* @file Chunk.h
* @author zf
* @date 2017/11/26
* @brief
* 地图相关
* 1.尝试用横 16，纵 16，高 256 的长方体区域来表示一个区块
* 2.可将地图写入文件
* 3.利用vector数组来储存区块资料
* 4.以数组中的数（用无符号整型就可以了）来表示是哪一个方块
*/
using namespace std;

class Chunk
{
public:
	Chunk();
	~Chunk();
	void print_test();

	/**
	* @brief 构建一个区块
	*/
	bool creat_chunk(CubeManager &cube_mgr);


	/**
	* @param x:数组第一位，y:第二位，z:第三位,new_block:新方块的编号
	* @return false:修改对应数据失败 ture:修改对应数据成功
	* @brief 修改chunk中某一的方块种类函数
	*/
	bool set_data(size_t x, size_t y, size_t z, size_t new_block);

	/**
	* @param x:数组第一位，y:第二位，z:第三位
	* @return -1:输入的数字越界 其他:返回对应的方块编号
	* @brief 获取chunk中某一点的方块种类函数
	*/
	int get_data(size_t x, size_t y, size_t z);
private:
	///一个chunk的长
	const size_t chunk_x = 16;
	///一个chunk的高
	const size_t chunk_y = 256;
	///一个chunk的深(按屏幕坐标系)
	const size_t chunk_z = 16;
	///数据储存数组
	vector<vector<vector<size_t>>> chunk_data;



};
