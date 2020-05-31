#include "test.h"
#include <iostream>

void IntParser::print_data() {
    std::cout << _data << std::endl;
}

bool IntParser::data_parser(const std::string& str) {
    _data = std::stoi(str);
    return true;
}

void FloatParser::print_data() {
    std::cout << _data << std::endl;
}

bool FloatParser::data_parser(const std::string& str) {
    _data = std::stof(str);
    return true;
}

bool StrParser::data_parser(const std::string& str) {
    _data = str;
    return true;
}

void IntArrayParser::print_data() {
    std::cout << "(int_array)" << std::endl;
    for (const auto& item : _data) {
        std::cout << item << std::endl;
    }
}

bool IntArrayParser::data_parser(const std::string& str) {
    std::vector<std::string> array_split_vec = Utils::split_string(str, ":");
    if (array_split_vec.size() != 2) {
        //LOG : FATAL("int[] data format illegal");
        return false;
    }
    const size_t array_size = std::stoi(array_split_vec[0]);
    std::vector<std::string> array_content = Utils::split_string(array_split_vec[1], ",");
    if (array_content.size() != array_size) {
        //LOG : FATAL("int[] data size incorrect");
        return false;
    }
    std::vector<int> res;
    for (const auto& item : array_content) {
        res.emplace_back(std::stoi(item)); //TODO how to templatize it ?
    }
    _data.swap(res);
    return true;
}

void FloatArrayParser::print_data() {
    printf("(float_array)");
    for (const auto& item : _data) {
        std::cout << item << std::endl;
    }
}

//TODO <T>ArrayParser 
bool FloatArrayParser::data_parser(const std::string& str) {
    std::vector<std::string> array_split_vec = Utils::split_string(str, ":");
    if (array_split_vec.size() != 2) {
        //LOG : FATAL("int[] data format illegal");
        return false;
    }
    const size_t array_size = std::stoi(array_split_vec[0]);
    std::vector<std::string> array_content = Utils::split_string(array_split_vec[1], ",");
    if (array_content.size() != array_size) {
        //LOG : FATAL("int[] data size incorrect");
        return false;
    }
    std::vector<float> res;
    for (const auto& item : array_content) {
        res.emplace_back(std::stof(item)); //TODO how to templatize it ?
    }
    _data.swap(res);
    return true;
}

void StrArrayParser::print_data() {
    printf("(str_array)");
    for (const auto& item : _data) {
        std::cout << item << std::endl;
    }
}

bool StrArrayParser::data_parser(const std::string& str) {
    std::vector<std::string> array_split_vec = Utils::split_string(str, ":");
    if (array_split_vec.size() != 2) {
        //LOG : FATAL("int[] data format illegal");
        return false;
    }
    const size_t array_size = std::stoi(array_split_vec[0]);
    std::vector<std::string> array_content = Utils::split_string(array_split_vec[1], ",");
    if (array_content.size() != array_size) {
        //LOG : FATAL("int[] data size incorrect");
        return false;
    }
    std::vector<float> res;
    for (const auto& item : array_content) {
        res.emplace_back(std::stof(item)); //TODO how to templatize it ?
    }
    _data.swap(res);
    return true;
}

std::vector<std::string> Utils::split_string(const std::string& str, const std::string& separator) {
    std::vector<std::string> res;
    std::size_t start_index = 0;
    std::size_t end_index = str.find_first_of(separator);
    while (end_index != std::string::npos) {
        res.emplace_back(str.substr(start_index, end_index - start_index));
        start_index = end_index + sizeof(separator);
        end_index = str.find_first_of(separator, start_index);
    }

    if (start_index < str.size()) {
        res.emplace_back(str.substr(start_index));
    }

    return res;
}

//#include <iostream>
//#include <fstream>
//#include <string>
//#include <sstream>
//
//std::string LoaderFStream::FormatString(std::string& str)
//{
//    size_t pos2 = str.find('\r', 0);
//    if (pos2 == -1)
//    {
//        return str;
//    }
//    return str.substr(0, pos2);
//}
//
//bool LoaderFStream::Load(const char* sFile)
//{
//    if (!sFile)
//    {
//        return false;
//    }
//    Clear();
//    std::ifstream infile;
//    infile.open(sFile, std::ifstream::in);
//    if (!infile.good())
//    {
//        printf("ifstream error! file name is %s\n", sFile);
//        return false;
//    }
//    //get name
//    char buffer[MAX_CFG_LINE_SIZE];
//    std::string slab;
//    infile.getline(buffer, MAX_CFG_LINE_SIZE, '\n');
//    slab = buffer;
//    slab = FormatString(slab);
//    slab += '\t';
//
//    //get info
//    char infobuffer[MAX_CFG_LINE_SIZE];
//    std::string slabInfo;
//    infile.getline(infobuffer, MAX_CFG_LINE_SIZE, '\n');
//    slabInfo = infobuffer;
//    slabInfo = FormatString(slabInfo);
//    slabInfo += '\t';
//
//    StringVector tmpVal;
//    while (infile.getline(buffer, MAX_CFG_LINE_SIZE, '\n'))
//    {
//        std::string tmpV = buffer;
//        tmpV = FormatString(tmpV);
//        tmpV += '\t';
//        tmpVal.push_back(tmpV);
//    }
//
//    {//paser label
//        size_t pos1 = -1;
//        std::string tmpString = slab;
//        while (true)
//        {
//            size_t pos2 = tmpString.find('\t', ++pos1);
//            if (pos2 == -1)
//            {
//                break;
//            }
//            std::string val = tmpString.substr(pos1, pos2 - pos1);
//            pos1 = pos2;
//            LabelInfo info;
//            info.m_Name = val;
//            m_Label.push_back(info);
//        }
//    }
//
//    {//paser info
//        size_t pos1 = -1;
//        std::string tmpString = slabInfo;
//        int32_t idx = 0;
//        while (true)
//        {
//            size_t pos2 = tmpString.find('\t', ++pos1);
//            if (pos2 == -1)
//            {
//                break;
//            }
//            std::string info = tmpString.substr(pos1, pos2 - pos1);
//            pos1 = pos2;
//            if (idx >= (int32_t)m_Label.size())
//            {
//                return false;
//            }
//            m_Label[idx].m_Info = info;
//            idx++;
//        }
//    }
//
//    {//paser val
//        for (int32_t i = 0; i < (int32_t)tmpVal.size(); ++i)
//        {
//            size_t pos1 = -1;
//            std::string tmpString = tmpVal[i];
//            StringVector valList;
//            while (true)
//            {
//                size_t pos2 = tmpString.find('\t', ++pos1);
//                if (pos2 == -1)
//                {
//                    break;
//                }
//                std::string val = tmpString.substr(pos1, pos2 - pos1);
//                pos1 = pos2;
//                valList.push_back(val);
//            }
//            m_Val.push_back(valList);
//        }
//    }
//
//    return true;
//}
//bool LoaderFStream::Save(const char* sFile)
//{
//    if (!sFile)
//    {
//        return false;
//    }
//    if (m_Label.empty())
//    {
//        return false;
//    }
//    std::ofstream ofile;
//    ofile.open(sFile, std::ifstream::out);
//    if (!ofile.good())
//    {
//        printf("ifstream error! file name is %s\n", sFile);
//        return false;
//    }
//    //write label name
//    //write label type
//    std::stringstream sstr;
//    std::stringstream ssType;
//    sstr << m_Label[0].m_Name.c_str();
//    ssType << m_Label[0].m_Info.c_str();
//    for (int32_t i = 1; i < (int32_t)m_Label.size(); ++i)
//    {
//        sstr << "\t" << m_Label[i].m_Name.c_str();
//        ssType << "\t" << m_Label[i].m_Info.c_str();
//    }
//    sstr << "\n";
//    ssType << "\n";
//    ofile << sstr.str().c_str();
//    ofile << ssType.str().c_str();
//
//    //write value
//    for (int32_t i = 0; i < (int32_t)m_Val.size(); ++i)
//    {
//        StringVector& vec = m_Val[i];
//        if (vec.empty())
//        {
//            continue;
//        }
//        std::stringstream ssVal;
//        ssVal << vec[0].c_str();
//        for (int32_t x = 1; x < (int32_t)vec.size(); ++x)
//        {
//            ssVal << "\t" << vec[x].c_str();
//        }
//        ssVal << "\n";
//        ofile << ssVal.str().c_str();
//    }
//
//    //close
//    ofile.close();
//    return true;
//}
//bool LoaderFStream::GetLabelList(LabelVector& list)
//{
//    list = m_Label;
//    return true;
//}
//bool LoaderFStream::GetValueList(int32_t index, StringVector& list)
//{
//    if (index < 0 || index >= (int32_t)m_Val.size())
//    {
//        return false;
//    }
//    list = m_Val[index];
//    return true;
//}
//void LoaderFStream::Clear()
//{
//    m_Label.clear();
//    for (int32_t i = 0; i < (int32_t)m_Val.size(); ++i)
//    {
//        m_Val[i].clear();
//    }
//    m_Val.clear();
//}
