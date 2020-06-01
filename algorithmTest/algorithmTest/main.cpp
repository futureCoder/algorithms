#include "inc/leetcode.h"
#include "inc/algorithmsBasic.hpp"
#include "inc/ThreadPool.h"
#include "LRUCache.h"

#include "myshared_ptr.h"

#include <mutex>
#include <memory>

#include "code_buffer.h"

int main() {
    //LoaderFStream ls;
    //ls.load("card_define.txt");
    //LabelVector lv;
    //ls.get_meta_list(lv);
    DictParser dp;
    dp.read_file_by_line("parser_sample.txt");
}