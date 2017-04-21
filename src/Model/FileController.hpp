/*
 * FileControlller.hpp
 *
 *  Created on: Mar 29, 2017
 *      Author: gkun9931
 */

#ifndef MODEL_FILECONTROLLER_HPP_
#define MODEL_FILECONTROLLER_HPP_
#include "../Model/FastList.hpp"
#include "../Model/Meme.hpp"
#include"../Model/BinarySearchTree.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "CrimeData.hpp"
using namespace std;
class FileController
    {
private:
    FastList<Meme> memeList;
public:
    FastList<Meme> readDataFromFileAsList(string filename);
    void writeDataStatistics(FastList<Meme> source, string filename);
    BinarySearchTree<CrimeData> readCrimeDataToBinarySearchTree(string filename);
    };




#endif /* MODEL_FILECONTROLLER_HPP_ */
