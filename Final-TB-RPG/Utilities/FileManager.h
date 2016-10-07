#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "File.h"

typedef std::map<std::string, File*> FCONT;
typedef FCONT::iterator FCONT_IT;

class FileManager
{
private:

	static FCONT m_fcont;

public:

	static void AddFile(std::string&& id, std::string&& filename, bool create);

	static void RemoveFile(std::string&& id);

	static void RemoveAll();

	static std::string GetKeyVal(std::string&& id, std::string&& key);

	static void SetKeyVal(std::string&& id, std::string&& key, std::string&& val);

	static File* GetFile(std::string&& id);

	FileManager();
	~FileManager();

};


#endif // FILE_MANAGER_H
