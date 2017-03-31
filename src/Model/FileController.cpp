/*
 * FileController.cpp

 *
 *  Created on: Mar 29, 2017
 *      Author: gkun9931
 */
#include "FileController.hpp"
  FastList<Meme> readDataFromFileAsList(string filename)
      {
	  FastList<Meme> dataSource;
	  string currentCSVLine;
	  int rowCount = 0;

	  ifstream dataFile(filename);

	  if(dataFile.is_open())
	      {
	      while(!dataFile.eof())
		  {
		  getline(dataFile, currentCSVLine, '\r');
		  stringstream parseCSV(currentCSVLine);
		  string title, tempHipster, tempDank, tempMainstream;
		  double quotient;
		  int dankness;
		  bool isCommon;

		  getline(parseCSV, title, ',');
		  getline(parseCSV, tempHipster, ',');
		  getline(parseCSV, tempDank, ',');
		  getline(parseCSV, tempMainstream, ',');
		  if(rowCount != 0)
		      {
			  quotient = stod(tempHipster);
			  dankness = stoi(tempDank);
			  isCommon = stoi(tempMainstream);
			  Meme temp(title);
			  temp.setDankness(dankness);
			  temp.setHipsterQuotienet(quotient);
			  temp.setMainstream(isCommon);
			  dataSource.add(temp);
		      }
		  rowCount++;
		  cout << currentCSVLine << endl;
		  }
	      dataFile.close();
	      }
	  else
	      {
	      cerr<<"NO FILE"<<endl;
	      }
	  return dataSource;
      }
  void FileController :: writeDataStatistics(FastList<Meme> dataSource, string filename)
      {
	  ofstream saveFile(filename);

	  if(saveFile.is_open())
	      {
	      saveFile<< "these are the contents of the list" << endl;
	      for(int index = 0; index < dataSource.getSize(); index++)
		  {
		  saveFile << "Meme Title " << dataSource.getFromIndex(index).getTitle() << endl;
		  }
	      }
	  else
	      {
	      cerr << "FILE UNAVAILABLE"<<endl;
	      }
      }
