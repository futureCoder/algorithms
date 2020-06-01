#ifndef TEST_H
#define TEST_H

#include <unordered_map>
#include <string>
#include <vector>
#include <map>

namespace Utils {
    std::vector<std::string> split_string(const std::string& str,
                                          const std::string& separator);
}

enum class Datatype {
    INT = 0,
    FLOAT,
    STRING,
    INT_ARRAY,
    FLOAT_ARRAY,
    STRING_ARRAY,
    USER_TYPE,
    DATA_TYPE_NUM
};

class ParserInterface {
public:
    virtual ~ParserInterface() {}

    virtual Datatype data_type() = 0;

    virtual bool data_parser(const std::string& str) = 0;

    virtual void print_data() = 0;
};

class IntParser : public ParserInterface {
public:
    IntParser() : _data(0) {}

    ~IntParser() = default;

    Datatype data_type() override {
        return Datatype::INT;
    }

    bool data_parser(const std::string& str) override;

    void print_data() override;

private:
    int _data;
};

class FloatParser : public ParserInterface {
public:
    FloatParser() : _data(0.0) {}

    ~FloatParser() {}

    Datatype data_type() override {
        return Datatype::FLOAT;
    }

    void print_data() override;

    bool data_parser(const std::string& str) override;

private:
    float _data;

};

class StrParser : public ParserInterface {
public:
    StrParser() : _data("") {}

    ~StrParser() {}

    Datatype data_type() override {
        return Datatype::STRING;
    }

    void print_data() override {
        printf("(string)%s ", _data.c_str());
    }

    void set_data_value(const std::string input_data) {
        _data = input_data;
    }

    bool data_parser(const std::string& str) override;

private:
    std::string _data;
};

class IntArrayParser : public ParserInterface {
public:
    IntArrayParser() = default;

    ~IntArrayParser() = default;

    Datatype data_type() override {
        return Datatype::INT_ARRAY;
    }

    void print_data() override;

    bool data_parser(const std::string& str) override;

private:
    std::vector<int> _data;
};

class FloatArrayParser : public ParserInterface {
public:
    FloatArrayParser() = default;

    ~FloatArrayParser() = default;

    Datatype data_type() override {
        return Datatype::FLOAT_ARRAY;
    }

    void print_data() override;

    bool data_parser(const std::string& str) override;

private:
    std::vector<float> _data;
};

class StrArrayParser : public ParserInterface {
public:
    StrArrayParser() = default;

    ~StrArrayParser() = default;

    Datatype data_type() override {
        return Datatype::STRING_ARRAY;
    }

    void print_data() override;

    bool data_parser(const std::string& str) override;

private:
    std::vector<std::string> _data;
};


const int MAX_LINE_SIZE = 8192;

struct LabelInfo {
    std::string name;
    std::string info;
};

using LabelVector = std::vector<LabelInfo>;
using StringVector = std::vector<std::string>;

class LoaderInterface {
public:
    LoaderInterface() = default;
    virtual ~LoaderInterface() = default;
    virtual bool load(const std::string& file_name) = 0;
    virtual bool get_meta_list(LabelVector& list) = 0;
    virtual bool get_value_list(size_t index, StringVector& list) = 0;
    virtual void clear() = 0;
};

class LoaderFStream : public LoaderInterface {
public:
    LoaderFStream() = default;
    ~LoaderFStream() override = default;

    bool load(const std::string& file_name) override;
    bool get_meta_list(LabelVector& list) override {
        list = _label;
        return true;
    }
    bool get_value_list(size_t index, StringVector& list) override {
        if (index < 0 || index >= _content.size()) {
            return false;
        }
        list = _content.at(index);
        return true;
    }
    void clear() override {
        _label.clear();
        for (auto& v : _content) {
            v.clear();
        }
        _content.clear();
    }

private:
    std::string format_string(const std::string& str);

    LabelVector _label;
    std::vector<StringVector> _content;
    std::unordered_map<std::string, ParserInterface*> _type_parser;
};

class Table {
public:
    using ColumnMap = std::unordered_map<std::string, int32_t>;
    using ColumnName = std::map<int32_t, std::string>;
    //using RowList = std::list<Row*>;
    void add_column(const std::string& col_name, int32_t col_index, std::string& type_name);
    std::string get_column_name(int32_t col_index) const;
    int32_t get_column_index(const std::string& col_name) const;
    std::string get_column_type() const;

};

//colume Type
enum eDBType
{
    DB_COLUMN_Unkonw = 0,
    DB_COLUMN_INT = 1,
    DB_COLUMN_INT64,
    DB_COLUMN_FLOAT,
    DB_COLUMN_DOUBLE,
    DB_COLUMN_BLOB,
    DB_COLUMN_NULL,
    DB_COLUMN_TEXT,
    DB_COLUMN_SMALLINT,
    DB_COLUMN_TINYINT,
    DB_COLUMN_BINARY,
    DB_COLUMN_UINT,
    DB_COLUMN_UINT64
};

class FileInterface : public LoaderFStream//, public Singleton<FileInterface>
{
public:
    FileInterface();
    virtual ~FileInterface();

    virtual bool ExecuteSql(const char* sSql, Table* pTable);

    void Clear();
    void FillValues(Table* pTable, StringVector& vals); //出于对效率的考虑，最好能定义一下循环次数，上边的木有限制数量在接口中有实现，就先按最大行数进行查询取结果吧。
};

//#define MAX_CFG_LINE_SIZE 8192
//#include <string>
//#include <vector>
//class LabelInfo
//{
//public:
//    LabelInfo(void) {}
//    virtual ~LabelInfo(void) {}
//    std::string m_Name;
//    std::string m_Info;
//};
//
//typedef std::vector<LabelInfo> LabelVector;
//typedef std::vector<std::string> StringVector;
//
//
//class LoaderInterface
//{
//public:
//    LoaderInterface() {}
//    virtual ~LoaderInterface() {}
//
//    virtual bool Load(const char* sFile) = 0;
//    virtual bool GetLabelList(LabelVector& list) = 0;
//    virtual bool GetValueList(int32_t index, StringVector& list) = 0;
//    virtual void Clear() = 0;
//};
//
//class LoaderFStream : public LoaderInterface
//{
//public:
//    LoaderFStream() {}
//    virtual ~LoaderFStream() {}
//
//    bool Load(const char* sFile);
//    bool GetLabelList(LabelVector& list);
//    bool GetValueList(int32_t index, StringVector& list);
//
//    void Clear();
//private:
//    std::string FormatString(std::string& str);
//    LabelVector m_Label;
//    std::vector<StringVector> m_Val;
//};

#endif
