#include <string>

#include "test/blob_generator.hpp"
#include "test/format_test.hpp"
#include "test/parse_test.hpp"
#include "test/serialize_test1.hpp"


using namespace std;


int main() {

    //blob_generator(60000);
    //auto yml = get_yml_string();
    //auto parsed = YmlRaw(yml, parser::lazyParserMT).parse();;;;;;;;;;
    parse_test();
    //serialize_test();;
    //format_test();

    return 0;
}
