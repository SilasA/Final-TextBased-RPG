#include "stdafx.h"
#include "File.h"


File::File(std::string& filename, bool c)
{
	m_filename = filename;
	if (c) create();
	open();
	store();
	close();
}


File::~File()
{
	open();
	writedata();
	close();
}


bool File::open()
{
	m_file = std::fstream(m_filename, std::ios::in | std::ios::out);
	return m_file.is_open();
}


void File::close()
{
	if (m_file.is_open()) m_file.close();
}


void File::create()
{
	std::fstream tf = std::fstream(m_filename, std::ios::out);
	if (tf.is_open()) tf.close();
}


void File::store()
{
	std::string line;
	if (!m_file.is_open()) return;
	remove();
	while (std::getline(m_file, line))
	{
		m_data.emplace(findkeyval(line));
	}
}


void File::remove()
{
	m_data.clear();
}


void File::writedata()
{
	if (!m_file.is_open()) return;
	for (DATA_IT it = m_data.begin(); it != m_data.end(); ++it)
		m_file << it->first << DELIM_CHAR << it->second << std::endl;
}


S_PAIR File::findkeyval(std::string& line)
{
	std::istringstream lineStream(line);
	std::string key, val;
	std::getline(lineStream, key, DELIM_CHAR);
	std::getline(lineStream, val);
	return std::make_pair(key, val);
}


void File::SetKeyVal(std::string& key, std::string& val)
{
	m_data[key] = val;
}


std::string File::GetKeyVal(std::string& key)
{
	if (m_data.size() == 0) return std::string();
	if (m_data.find(key) == m_data.end()) return std::string();
	return m_data[key];
}

