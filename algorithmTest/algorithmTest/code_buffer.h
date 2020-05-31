#ifndef TEST_H
#define TEST_H
#include <string>
#include <vector>

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
