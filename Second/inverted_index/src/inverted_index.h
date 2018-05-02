#ifndef __INVERTED_INDEX_H__
#define __INVERTED_INDEX_H__

#include <unordered_map>

using namespace std;

#define MAXLINE 1024

void ListFile(const char *name);
int FileType(const char *file_name);

class InvertedIndex
{
public:
	InvertedIndex(){}
	~InvertedIndex(){result_index_.clear();}

	int StatWords(const char* file_name);
	unordered_map<string,unordered_map<string,int>> result_index(){return result_index_;}
	

private:
	//存放倒排索引结果，key是单词，value也是map，该map的key是文件名，value是该单词在该文件中出现的次数
	unordered_map<string,unordered_map<string,int>> result_index_;
	
	int ParseWordsByLine(char* str_line, const char* file_name);
	void InsertWordToMap(char* word, const char* file_name);
};

#endif
//inverted_index.h