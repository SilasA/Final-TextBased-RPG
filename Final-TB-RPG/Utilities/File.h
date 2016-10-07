#ifndef FILE_H
#define FILE_H


#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <iostream>

#define DELIM_CHAR '='

typedef std::pair<std::string, std::string> S_PAIR;	// Key and Value pair		
typedef std::map<std::string, std::string> DATA;	// Container for organized file content
typedef DATA::iterator DATA_IT;						// For iteration through DATA

class File
{
private:

	std::fstream m_file;

	// Data from the file
	DATA m_data;

	// Directory of the file
	std::string m_filename;

	// Opens a file stream depending on m_in's status
	// Returns if the file is now open
	bool open();
	
	// Closes any open streams and deletes the object pointed to
	void close();

	// Creates the file in the directory
	void create();

	// Stores the organized contents of the file into the map
	void store();
	// Empties (deletes) the data map
	void remove();

	// Writes the map's contents to the file
	void writedata();

	// Returns the key and value in an std::pair<std::string, std::string>
	// after separating them by the DELIM_CHAR
	S_PAIR findkeyval(std::string& line);

public:

	// Opens the stream for testing and if data is to be stored, it will store
	// it; otherwise it will close the stream and delete the object.
	File(std::string& filename, bool storedata);

	// Closes streams and deletes necessary objects
	~File();

	// If data is stored:
	//	Append the new data (new key and val or just new val)
	//  Write the new data to the file
	// If data isn't stored:
	//  Gather data temporarily from the file
	//  Append the new data
	//  Write to the file
	void SetKeyVal(std::string& key, std::string& val);

	// Returns the Corresponding value paired with the key
	std::string GetKeyVal(std::string& key);
};

#endif // FILE_H
