#include "composite.h"

File::File(int fileSize) {
    this->m_fileSize = fileSize;
}

int File::getSize() {
    return this->m_fileSize;    
}

void File::add(Entry* pEntry) {
    throw std::string("文件中不可添加文件");
}

void Directory::add(Entry* pEntry) {
    m_pVecEntry.push_back(pEntry);
}

int Directory::getSize() {
    int size = 0;
    std::vector<Entry*>::iterator ite = m_pVecEntry.begin();
    for (;ite != m_pVecEntry.end();++ite){
        // 将子文件夹或文件的大小统计进来
        size += (*ite)->getSize();
    }
   return size; 
}