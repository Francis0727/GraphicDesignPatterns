#ifndef _COMPOSITE_H
#define _COMPOSITE_H

#include <vector>
#include <string>

class Entry{
public:
    virtual int getSize() = 0;
    virtual void add(Entry* pEntry) = 0; 
};

class File : public Entry {
public:
    File(int fileSize);
    virtual int getSize();
    virtual void add(Entry* pEntry);
private:
    int m_fileSize;
};

class Directory : public Entry {
public:
    virtual void add(Entry* pEntry);
    virtual int getSize();
private:
    std::vector<Entry*> m_pVecEntry;
};

#endif