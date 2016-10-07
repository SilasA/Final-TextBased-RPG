#include "stdafx.h"
#include "FileManager.h"


FCONT FileManager::m_fcont;

FileManager::FileManager()
{
}


FileManager::~FileManager()
{
	RemoveAll();
}


void FileManager::AddFile(std::string&& id, std::string&& filename, bool create)
{
	if (m_fcont.find(id) == m_fcont.end() && m_fcont.size() != 0) return;
	m_fcont[id] = new File(filename, create);
}


void FileManager::RemoveFile(std::string&& id)
{
	delete m_fcont[id];
	m_fcont.erase(id);
}


void FileManager::RemoveAll()
{
	for (FCONT_IT it = m_fcont.begin(); it != m_fcont.end(); ++it)
		delete it->second;
	m_fcont.clear();
}


std::string FileManager::GetKeyVal(std::string&& id, std::string&& key)
{
	return m_fcont[id]->GetKeyVal(key);
}


void FileManager::SetKeyVal(std::string&& id, std::string&& key, std::string&& val)
{
	m_fcont[id]->SetKeyVal(key, val);
}


File* FileManager::GetFile(std::string && id)
{
	return m_fcont[id];
}
