#include "code_buffer.h"
#include <iostream>
#include <fstream>

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
    std::vector<std::string> res;
    for (const auto& item : array_content) {
        res.emplace_back(item); //TODO how to templatize it ?
    }
    _data.swap(res);
    return true;
}

void UserData::print_data() {
    std::cout << "(name) " << _name << "(age) " << _age << "(K/D/A)" << _kill << "/" << _dead << "/" << _assist << std::endl;
}

bool UserData::data_parser(const std::string& str) {
    std::vector<std::string> split_array =
        Utils::split_string(str, _str_separator);
    int array_size = split_array.size();

    if (array_size != get_member_cnt()) {
        //LOG FATAL("user_data size incorrect");
        return false;
    }
    // name
    _name = split_array[0];
    // age
    _age = std::stoi(split_array[1]);
    // kill
    _kill = std::stof(split_array[2]);
    // dead
    _dead = std::stof(split_array[3]);
    // assist
    _assist = std::stof(split_array[4]);
    return true;
}

DictParser::DictParser() :
    _total_col_cnt(0) {
    //初始化建立映射关系  
    _type_parser_map["int"] = new(std::nothrow) IntParser();
    _type_parser_map["float"] = new(std::nothrow) FloatParser();
    _type_parser_map["string"] = new(std::nothrow) StrParser();
    _type_parser_map["int_array"] = new(std::nothrow) IntArrayParser();
    _type_parser_map["float_array"] = new(std::nothrow) FloatArrayParser();
    _type_parser_map["str_array"] = new(std::nothrow) StrArrayParser();
    _type_parser_map["user_data"] = new(std::nothrow) UserData();
}

DictParser::~DictParser() {
    for (auto& item : _type_parser_map) {
        delete item.second;
    }
}

bool DictParser::read_file_by_line(const std::string& file_name) {
    std::ifstream data_file;
    data_file.open(file_name.c_str(), std::ifstream::in);
    //load failed
    if (data_file.fail()) {
        //LOG FATAL("Open file error");
        return -1;
    }
    std::string cur_line_str;
    int line = 0;
    //逐行读取数据 
    while (getline(data_file, cur_line_str)) {
        if (line == 0) {
            ++line;
            continue;
            //第一行获取每一列的数据类型   
            ++line;
            int ret = get_each_col_data_type(cur_line_str);
            if (ret == -1) {
                return -1;
            }
        } else if (line == 1) {
            //第二行获取每一列的数据类型   
            ++line;
            int ret = get_each_col_data_type(cur_line_str);
            if (ret == -1) {
                return -1;
            }
        } else {
            //第二行开始进行解析
            printf("\n");
            ++line;
            printf("line:%d,\n", line - 1);
            if (cur_line_str.empty()) {
                //LOG FATAL("line %d of data.conf is empty", line - 1);
                continue;
            }

            std::vector<std::string> each_col_data_value =
                Utils::split_string(cur_line_str, "\t");
            int cur_line_cnt = each_col_data_value.size();
            //该行数据数量与第一行的类型数量不匹配  
            if (cur_line_cnt != _total_col_cnt) {
                //LOG FATAL("line %d's columns_number incorrect", line - 1);
                continue;
            }

            for (int i = 0; i < cur_line_cnt; ++i) {
                //对每一列数据进行解析
                std::cout << "col: " << i + 1 << std::endl;
                std::string cur_col_data_str = each_col_data_value[i];
                if (cur_col_data_str.empty()) {
                    //LOG FATAL("line %d,column %d is empty", line - 1, i + 1);
                    continue;
                }
                int res = col_str_data_parser(cur_col_data_str, i, line);
                printf("\n");
                if (res == -1) {
                    continue;
                }
            }
        }
    }
    if (line == 0) {
        //LOG WARNING("data.conf is empty");
        return -1;
    }
    data_file.close();
    return 0;
}

bool DictParser::get_each_col_data_type(const std::string& first_line_str) {
    //根据词表文件的第一行，获取每一列的数据类型     
    if (first_line_str.empty()) {
        //LOG WARNING("data.conf is empty");
        return false;
    }
    _column_type = Utils::split_string(first_line_str, "\t");
    for (const auto& cur_str : _column_type) {
        auto it = _type_parser_map.find(cur_str);
        //在映射表中没找到该类型，表明输入的数据类型非法     
        if (it == _type_parser_map.end()) {
            //LOG FATAL("line 1,column %d is illegal date type", (int)(i + 1));
            return false;
        }
    }
    _total_col_cnt = _column_type.size();
    return true;
}

bool DictParser::col_str_data_parser(const std::string& col_str, int index, int line) {
    //对输入的字符串进行解析 
    const std::string& cur_col_data_type = _column_type[index];
    auto it = _type_parser_map.find(cur_col_data_type);
    //找不到对应的映射关系  
    if (it == _type_parser_map.end()) {
        //LOG FATAL("line %d,column %d is illegal data type", line - 1, index + 1);
        return false;
    }
    bool ret = false;
    try {
         ret = it->second->data_parser(col_str);
    } catch (std::exception e) {
        std::cerr << e.what() << std::endl;
        ret = false;
    }
    //解析失败  
    if (!ret) {
        //LOG FATAL("line %d,column %d parse error", line - 1, index + 1);
        return false;
    }
    it->second->print_data();
    return true;
}


















std::vector<std::string> Utils::split_string(const std::string& str, const std::string& separator) {
    std::vector<std::string> res;
    std::size_t start_index = 0;
    std::size_t end_index = str.find_first_of(separator);
    while (end_index != std::string::npos) {
        res.emplace_back(str.substr(start_index, end_index - start_index));
        start_index = end_index + separator.size();
        end_index = str.find_first_of(separator, start_index);
    }

    if (start_index < str.size()) {
        res.emplace_back(str.substr(start_index));
    }

    return res;
}

bool LoaderFStream::load(const std::string& file_name) {
    if (file_name.empty()) {
        return false;
    }

    clear();
    std::ifstream in_file;
    in_file.open(file_name, std::ifstream::in);
    if (!in_file.good()) {
        //log
        return false;
    }
    {//parse label_ori
        std::string label_ori;
        std::getline(in_file, label_ori, '\n');
        label_ori = format_string(label_ori);
        //label_ori += '\t';

        std::vector<std::string> label_list = Utils::split_string(label_ori, "\t");
        for (const auto& str : label_list) {
            LabelInfo info;
            info.name = str;
            _label.emplace_back(info);
        }
    }
    {//parse type
        std::string type_ori;
        std::getline(in_file, type_ori, '\n');
        type_ori = format_string(type_ori);
        //label_ori += '\t';
        std::vector<std::string> type_list = Utils::split_string(type_ori, "\t");
        if (_label.size() != type_list.size()) {
            //log
            return false;
        }
        for (size_t i = 0; i < type_list.size(); ++i) {
            swap(_label[i].info, type_list[i]);
        }
    }

    {//parse real content
        std::string tmp_str;
        while (std::getline(in_file, tmp_str, '\n')) {
            tmp_str = format_string(tmp_str);
            //tmp_str += '\t';
            StringVector value_list = Utils::split_string(tmp_str, "\t");
            if (value_list.size() != _label.size()) {
                //TODO something wrong, log it and process
                //do not continue,
            }
            _content.emplace_back(value_list);
        }
    }

    return true;
}

std::string LoaderFStream::format_string(const std::string& str) {
    const size_t pos = str.find('\r', 0);
    if (-1 == pos) {
        return str;
    }
    return str.substr(0, pos);
}


//bool FileInterface::ExecuteSql(const char* sSql, Table* pTable)
//{
//    if (!sSql || !pTable)
//    {
//        return false;
//    }
//
//    Clear();
//    if (!LoaderFStream::load(sSql))
//    {
//        return false;
//    }
//
//    LabelVector labels;
//    if (!LoaderFStream::get_meta_list(labels))
//    {
//        return false;
//    }
//    int DBType = DB_COLUMN_Unkonw;
//    for (size_t i = 0; i < (size_t)labels.size(); ++i)
//    {
//        if (labels[i].info == "int8" ||
//            labels[i].info == "uint8" ||
//            labels[i].info == "int16" ||
//            labels[i].info == "uint16" ||
//            labels[i].info == "int32" ||
//            labels[i].info == "uint32"
//            )
//        {
//            DBType = DB_COLUMN_INT;
//        }
//        else if (labels[i].info == "int64" ||
//            labels[i].info == "uint64")
//        {
//            DBType = DB_COLUMN_INT64;
//        }
//        else if (labels[i].info == "f32")
//        {
//            DBType = DB_COLUMN_FLOAT;
//        }
//        else if (labels[i].info == "f64")
//        {
//            DBType = DB_COLUMN_DOUBLE;
//        }
//        else if (labels[i].info == "char")
//        {
//            DBType = DB_COLUMN_TEXT;
//        }
//        pTable->add_column((char*)labels[i].name.c_str(), i, DBType);
//    }
//
//
//    StringVector values;
//    int32_t idx = 0;
//    while (get_value_list(idx, values))
//    {
//        FillValues(pTable, values);
//        idx++;
//    }
//
//
//    return true;
//}
//
//void Table::add_column(const std::string& col_name, int32_t col_index, int32_t valueType) {
//    _colu
//}

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

